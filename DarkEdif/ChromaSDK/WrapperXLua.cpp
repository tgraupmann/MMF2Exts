#include "WrapperXLua.h"
#define LUA_CORE
#include <Windows.h>
#include "Lua.h"
#include "lstate.h"
#include "lobject.h"
#include "lstring.h"
#include "lgc.h"
#include "ltable.h"
#include "lfunc.h"
#include "ldo.h"
#include "lmem.h"
#include "lcoco.h"
#include "ljit.h"
#include "ldebug.h"
#include "lvm.h"
#include "luaconf.h"
#include "lopcodes.h"
#include "lzio.h"

using namespace std;

#pragma region ldebug_c

/* only ANSI way to check whether a pointer points to an array */
static int isinstack(CallInfo* ci, const TValue* o) {
	StkId p;
	for (p = ci->base; p < ci->top; p++)
		if (o == p) return 1;
	return 0;
}

static int currentpc(lua_State* L, CallInfo* ci) {
	if (isLua(ci))  /* must be a Lua function to get current PC */
		return luaJIT_findpc(ci_func(ci)->l.p,
			ci == L->ci ? L->savedpc : ci->savedpc);
	else
		return -1;
}

#define check(x)		if (!(x)) return 0;
#define checkreg(pt,reg)	check((reg) < (pt)->maxstacksize)

static int precheck(const Proto* pt) {
	check(pt->maxstacksize <= MAXSTACK);
	check(pt->numparams + (pt->is_vararg & VARARG_HASARG) <= pt->maxstacksize);
	check(!(pt->is_vararg & VARARG_NEEDSARG) ||
		(pt->is_vararg & VARARG_HASARG));
	check(pt->sizeupvalues <= pt->nups);
	check(pt->sizelineinfo == pt->sizecode || pt->sizelineinfo == 0);
	check(pt->sizecode > 0 && GET_OPCODE(pt->code[pt->sizecode - 1]) == OP_RETURN);
	return 1;
}

static int checkArgMode(const Proto* pt, int r, enum OpArgMask mode) {
	switch (mode) {
	case OpArgN: check(r == 0); break;
	case OpArgU: break;
	case OpArgR: checkreg(pt, r); break;
	case OpArgK:
		check(ISK(r) ? INDEXK(r) < pt->sizek : r < pt->maxstacksize);
		break;
	}
	return 1;
}

#define checkopenop(pt,pc)	luaG_checkopenop((pt)->code[(pc)+1])

int luaG_checkopenop(Instruction i) {
	switch (GET_OPCODE(i)) {
	case OP_CALL:
	case OP_TAILCALL:
	case OP_RETURN:
	case OP_SETLIST: {
		check(GETARG_B(i) == 0);
		return 1;
	}
	default: return 0;  /* invalid instruction after an open call */
	}
}

static Instruction symbexec(const Proto* pt, int lastpc, int reg) {
	int pc;
	int last;  /* stores position of last instruction that changed `reg' */
	last = pt->sizecode - 1;  /* points to final return (a `neutral' instruction) */
	check(precheck(pt));
	for (pc = 0; pc < lastpc; pc++) {
		Instruction i = pt->code[pc];
		OpCode op = GET_OPCODE(i);
		int a = GETARG_A(i);
		int b = 0;
		int c = 0;
		check(op < NUM_OPCODES);
		checkreg(pt, a);
		switch (getOpMode(op)) {
		case iABC: {
			b = GETARG_B(i);
			c = GETARG_C(i);
			check(checkArgMode(pt, b, getBMode(op)));
			check(checkArgMode(pt, c, getCMode(op)));
			break;
		}
		case iABx: {
			b = GETARG_Bx(i);
			if (getBMode(op) == OpArgK) check(b < pt->sizek);
			break;
		}
		case iAsBx: {
			b = GETARG_sBx(i);
			if (getBMode(op) == OpArgR) {
				int dest = pc + 1 + b;
				check(0 <= dest && dest < pt->sizecode);
				if (dest > 0) {
					int j;
					/* check that it does not jump to a setlist count; this
					   is tricky, because the count from a previous setlist may
					   have the same value of an invalid setlist; so, we must
					   go all the way back to the first of them (if any) */
					for (j = 0; j < dest; j++) {
						Instruction d = pt->code[dest - 1 - j];
						if (!(GET_OPCODE(d) == OP_SETLIST && GETARG_C(d) == 0)) break;
					}
					/* if 'j' is even, previous value is not a setlist (even if
					   it looks like one) */
					check((j & 1) == 0);
				}
			}
			break;
		}
		}
		if (testAMode(op)) {
			if (a == reg) last = pc;  /* change register `a' */
		}
		if (testTMode(op)) {
			check(pc + 2 < pt->sizecode);  /* check skip */
			check(GET_OPCODE(pt->code[pc + 1]) == OP_JMP);
		}
		switch (op) {
		case OP_LOADBOOL: {
			if (c == 1) {  /* does it jump? */
				check(pc + 2 < pt->sizecode);  /* check its jump */
				check(GET_OPCODE(pt->code[pc + 1]) != OP_SETLIST ||
					GETARG_C(pt->code[pc + 1]) != 0);
			}
			break;
		}
		case OP_LOADNIL: {
			if (a <= reg && reg <= b)
				last = pc;  /* set registers from `a' to `b' */
			break;
		}
		case OP_GETUPVAL:
		case OP_SETUPVAL: {
			check(b < pt->nups);
			break;
		}
		case OP_GETGLOBAL:
		case OP_SETGLOBAL: {
			check(ttisstring(&pt->k[b]));
			break;
		}
		case OP_SELF: {
			checkreg(pt, a + 1);
			if (reg == a + 1) last = pc;
			break;
		}
		case OP_CONCAT: {
			check(b < c);  /* at least two operands */
			break;
		}
		case OP_TFORLOOP: {
			check(c >= 1);  /* at least one result (control variable) */
			checkreg(pt, a + 2 + c);  /* space for results */
			if (reg >= a + 2) last = pc;  /* affect all regs above its base */
			break;
		}
		case OP_FORLOOP:
		case OP_FORPREP:
			checkreg(pt, a + 3);
			/* go through */
		case OP_JMP: {
			int dest = pc + 1 + b;
			/* not full check and jump is forward and do not skip `lastpc'? */
			if (reg != NO_REG && pc < dest && dest <= lastpc)
				pc += b;  /* do the jump */
			break;
		}
		case OP_CALL:
		case OP_TAILCALL: {
			if (b != 0) {
				checkreg(pt, a + b - 1);
			}
			c--;  /* c = num. returns */
			if (c == LUA_MULTRET) {
				check(checkopenop(pt, pc));
			}
			else if (c != 0)
				checkreg(pt, a + c - 1);
			if (reg >= a) last = pc;  /* affect all registers above base */
			break;
		}
		case OP_RETURN: {
			b--;  /* b = num. returns */
			if (b > 0) checkreg(pt, a + b - 1);
			break;
		}
		case OP_SETLIST: {
			if (b > 0) checkreg(pt, a + b);
			if (c == 0) {
				pc++;
				check(pc < pt->sizecode - 1);
			}
			break;
		}
		case OP_CLOSURE: {
			int nup, j;
			check(b < pt->sizep);
			nup = pt->p[b]->nups;
			check(pc + nup < pt->sizecode);
			for (j = 1; j <= nup; j++) {
				OpCode op1 = GET_OPCODE(pt->code[pc + j]);
				check(op1 == OP_GETUPVAL || op1 == OP_MOVE);
			}
			if (reg != NO_REG)  /* tracing? */
				pc += nup;  /* do not 'execute' these pseudo-instructions */
			break;
		}
		case OP_VARARG: {
			check((pt->is_vararg & VARARG_ISVARARG) &&
				!(pt->is_vararg & VARARG_NEEDSARG));
			b--;
			if (b == LUA_MULTRET) check(checkopenop(pt, pc));
			checkreg(pt, a + b - 1);
			break;
		}
		default: break;
		}
	}
	return pt->code[last];
}

static const char* kname(Proto* p, int c) {
	if (ISK(c) && ttisstring(&p->k[INDEXK(c)]))
		return svalue(&p->k[INDEXK(c)]);
	else
		return "?";
}

static const char* getobjname(lua_State* L, CallInfo* ci, int stackpos,
	const char** name) {
	if (isLua(ci)) {  /* a Lua function? */
		Proto* p = ci_func(ci)->l.p;
		int pc = currentpc(L, ci);
		Instruction i;
		*name = luaF_getlocalname(p, stackpos + 1, pc);
		if (*name)  /* is a local? */
			return "local";
		i = symbexec(p, pc, stackpos);  /* try symbolic execution */
		lua_assert(pc != -1);
		switch (GET_OPCODE(i)) {
		case OP_GETGLOBAL: {
			int g = GETARG_Bx(i);  /* global index */
			lua_assert(ttisstring(&p->k[g]));
			*name = svalue(&p->k[g]);
			return "global";
		}
		case OP_MOVE: {
			int a = GETARG_A(i);
			int b = GETARG_B(i);  /* move from `b' to `a' */
			if (b < a)
				return getobjname(L, ci, b, name);  /* get name for `b' */
			break;
		}
		case OP_GETTABLE: {
			int k = GETARG_C(i);  /* key index */
			*name = kname(p, k);
			return "field";
		}
		case OP_GETUPVAL: {
			int u = GETARG_B(i);  /* upvalue index */
			*name = p->upvalues ? getstr(p->upvalues[u]) : "?";
			return "upvalue";
		}
		case OP_SELF: {
			int k = GETARG_C(i);  /* key index */
			*name = kname(p, k);
			return "method";
		}
		default: break;
		}
	}
	return NULL;  /* no useful name found */
}

void luaG_typeerror(lua_State* L, const TValue* o, const char* op) {
	const char* name = NULL;
	const char* t = luaT_typenames[ttype(o)];
	const char* kind = (isinstack(L->ci, o)) ?
		getobjname(L, L->ci, cast_int(o - L->base), &name) :
		NULL;
	if (kind)
		luaG_runerror(L, "attempt to %s %s " LUA_QS " (a %s value)",
			op, kind, name, t);
	else
		luaG_runerror(L, "attempt to %s a %s value", op, t);
}

static int currentline(lua_State* L, CallInfo* ci) {
	int pc = currentpc(L, ci);
	if (pc < 0)
		return -1;  /* only active lua functions have current-line information */
	else
		return getline(ci_func(ci)->l.p, pc);
}

static Proto* getluaproto(CallInfo* ci) {
	return (isLua(ci) ? ci_func(ci)->l.p : NULL);
}

static void addinfo(lua_State* L, const char* msg) {
	CallInfo* ci = L->ci;
	if (isLua(ci)) {  /* is Lua code? */
		char buff[LUA_IDSIZE];  /* add file:line information */
		int line = currentline(L, ci);
		luaO_chunkid(buff, getstr(getluaproto(ci)->source), LUA_IDSIZE);
		luaO_pushfstring(L, "%s:%d: %s", buff, line, msg);
	}
}

void luaG_runerror(lua_State* L, const char* fmt, ...) {
	va_list argp;
	va_start(argp, fmt);
	addinfo(L, luaO_pushvfstring(L, fmt, argp));
	va_end(argp);
	luaG_errormsg(L);
}

void luaG_errormsg(lua_State* L) {
	if (L->errfunc != 0) {  /* is there an error handling function? */
		StkId errfunc = restorestack(L, L->errfunc);
		if (!ttisfunction(errfunc)) luaD_throw(L, LUA_ERRERR);
		setobjs2s(L, L->top, L->top - 1);  /* move argument */
		setobjs2s(L, L->top - 1, errfunc);  /* push function */
		incr_top(L);
		luaD_call(L, L->top - 2, 1);  /* call it */
	}
	luaD_throw(L, LUA_ERRRUN);
}

int luaG_ordererror(lua_State* L, const TValue* p1, const TValue* p2) {
	const char* t1 = luaT_typenames[ttype(p1)];
	const char* t2 = luaT_typenames[ttype(p2)];
	if (t1[2] == t2[2])
		luaG_runerror(L, "attempt to compare two %s values", t1);
	else
		luaG_runerror(L, "attempt to compare %s with %s", t1, t2);
	return 0;
}

void luaG_aritherror(lua_State* L, const TValue* p1, const TValue* p2) {
	TValue temp;
	if (luaV_tonumber(p1, &temp) == NULL)
		p2 = p1;  /* first operand is wrong */
	luaG_typeerror(L, p2, "perform arithmetic on");
}

void luaG_concaterror(lua_State* L, StkId p1, StkId p2) {
	if (ttisstring(p1) || ttisnumber(p1)) p1 = p2;
	lua_assert(!ttisstring(p1) && !ttisnumber(p1));
	luaG_typeerror(L, p1, "concatenate");
}

#pragma endregion

#pragma region ljit_core_c

/* Create the state table and copy the arguments. */
static Table* jit_createstate(lua_State* L, StkId arg, int nargs)
{
	Table* st;
	int i;
	luaC_checkGC(L);
	st = luaH_new(L, nargs, COMSTATE_PREALLOC);
	for (i = 0; i < nargs; i++)
		setobj2t(L, luaH_setnum(L, st, i + 1), arg + i);
	return st;
}

/* Compile a prototype. */
/* Note: func pointer may be invalidated because of stack reallocation. */
static int jit_compile(lua_State* L, StkId func, Table* st, int force)
{
	jit_State* J = G(L)->jit_state;
	Closure* cl = clvalue(func);
	Proto* pt = cl->l.p;
	int status;

	/* Check if JIT engine is enabled and prevent recursive invocation. */
	if ((J->flags & JIT_F_INIT_FAILED) ||
		(!force && !(J->flags & JIT_F_ON)) ||
		!J->frontwrap) {
		status = JIT_S_ENGINE_OFF;
	}
	else if (J->flags & JIT_F_COMPILING) {
		status = JIT_S_DELAYED;
	}
	else if (pt->jit_szmcode != 0 && force < 2) {  /* Prevent recompile. */
   /* TODO: Allow recompiles? Use case? Extra flag for jit.compile()? */
		status = JIT_S_OK;
	}
	else {
		setclvalue(L, luaH_setstr(L, st, luaS_newliteral(L, "func")), cl);
		/* Call frontend wrapper. */
		J->flags |= JIT_F_COMPILING;
		lua_unlock(L);
		status = J->frontwrap(L, st);
		lua_lock(L);
		J->flags &= ~JIT_F_COMPILING;
	}

	/* Better sanity check what the frontend returns. */
	if ((status == JIT_S_OK && pt->jit_szmcode == 0) || status == JIT_S_NONE)
		status = JIT_S_COMPILER_ERROR;

	/* Update closure callgate and prototype status. */
	cl->l.jit_gate = (status == JIT_S_OK) ? (lua_CFunction)pt->jit_mcode :
		G(L)->jit_gateJL;
	pt->jit_status = status;
	return status;
}

/* Compile and run a function. To be used by luaD_precall() only. */
int luaJIT_run(lua_State* L, StkId func, int nresults)
{
	ptrdiff_t funcr = savestack(L, func);
	Table* st = jit_createstate(L, func + 1, L->top - (func + 1));
	int status = jit_compile(L, func, st, 0);  /* Compile function. */
	func = restorestack(L, funcr);

	/* Run the compiled function on success. Fallback to bytecode on failure. */
	if (status == JIT_S_OK)
		return G(L)->jit_gateLJ(L, func, nresults);
	else
		return luaD_precall(L, func, nresults);
	/* Note: We are called from luaD_precall and we call it again. */
	/* So jit_compile makes sure pt->jit_status != JIT_S_NONE. */
}

int luaJIT_findpc(Proto* pt, const Instruction* savedpc)
{
	ptrdiff_t pcdiff = savedpc - pt->code;
	if (pcdiff >= 0 && pcdiff <= pt->sizecode) { /* Bytecode pointer? */
		return (int)pcdiff - 1;
	}
	else {  /* Else translate JIT mcode address to PC. */
		char* addr = (char*)savedpc;
		jit_MCTrailer tr;
		tr.mcode = (char*)pt->jit_mcode;
		tr.sz = pt->jit_szmcode;
		/* Follow trailer chain until addr is part of an mcode block. */
		while (!((size_t)(addr - tr.mcode) < tr.sz)) {
			memcpy((void*)&tr, JIT_MCTRAILER(tr.mcode, tr.sz),
				sizeof(jit_MCTrailer));
			if (tr.mcode == NULL) return -1;  /* Not in chain. */
		}
		{
			jit_Mfm* mfm = JIT_MCMFM(tr.mcode, tr.sz);
			int ofs = (int)(addr - tr.mcode);
			int isdeopt = !jit_mfm_ismain(mfm);
			int pc = 0;  /* Prologue fragment is at start of main mfm. */
			while (pc <= pt->sizecode) {
				int m = *mfm--;
				switch (m) {
				default:
					if (m & JIT_MFM_MARK) {
						m ^= JIT_MFM_MARK;
						if (isdeopt) { pc = m; continue; }  /* Seek. */
					}
					ofs -= m;
					if (ofs <= 0) return pc - 1;  /* Found! */
				case JIT_MFM_COMBINE:
				case JIT_MFM_DEAD:
					pc++;
					break;
				case JIT_MFM_STOP:
					jit_assert(0);  /* Premature STOP found. */
					return -1;
				}
			}
			jit_assert(0);  /* Address is in .tail. */
			return -1;
		}
	}
}

#pragma endregion

#pragma region ljit_mem_c

/*
** Define this if you want to run LuaJIT with valgrind. You will get random
** errors if you don't. And these errors are usually not caught by valgrind!
**
** This macro evaluates to a no-op if not run with valgrind. I.e. you can
** use the same binary for regular runs, too (without a performance loss).
*/
#ifdef USE_VALGRIND
#include <valgrind/valgrind.h>
#define MCH_INVALIDATE(ptr, addr) VALGRIND_DISCARD_TRANSLATIONS(ptr, addr)
#else
#define MCH_INVALIDATE(ptr, addr) ((void)0)
#endif

#define mcode_free(L, J, p, sz)	HeapFree(J->mcodeheap, 0, (p))

/* Free JIT structures in function prototype. */
void luaJIT_freeproto(lua_State* L, Proto* pt)
{
	char* mcode = (char*)pt->jit_mcode;
	size_t sz = pt->jit_szmcode;
	pt->jit_mcode = NULL;
	pt->jit_szmcode = 0;
	while (sz != 0) {  /* Free whole chain of mcode blocks for this proto. */
		jit_MCTrailer next;
		memcpy((void*)&next, JIT_MCTRAILER(mcode, sz), sizeof(jit_MCTrailer));
		MCH_INVALIDATE(mcode, sz);
		mcode_free(L, G(L)->jit_state, mcode, sz);
		mcode = next.mcode;
		sz = next.sz;
	}
}

#pragma endregion

#pragma region ldo_c

/*
** Call a function (C or Lua). The function to be called is at *func.
** The arguments are on the stack, right after the function.
** When returns, all the results are on the stack, starting at the original
** function position.
*/
void luaD_call(lua_State* L, StkId func, int nResults) {
	if (++L->nCcalls >= LUAI_MAXCCALLS) {
		if (L->nCcalls == LUAI_MAXCCALLS)
			luaG_runerror(L, "C stack overflow");
		else if (L->nCcalls >= (LUAI_MAXCCALLS + (LUAI_MAXCCALLS >> 3)))
			luaD_throw(L, LUA_ERRERR);  /* error while handing stack error */
	}
	if (luaD_precall(L, func, nResults) == PCRLUA)  /* is a Lua function? */
		luaV_execute(L, 1);  /* call it */
	L->nCcalls--;
	luaC_checkGC(L);
}

static StkId adjust_varargs(lua_State* L, Proto* p, int actual) {
	int i;
	int nfixargs = p->numparams;
	Table* htab = NULL;
	StkId base, fixed;
	for (; actual < nfixargs; ++actual)
		setnilvalue(L->top++);
#if defined(LUA_COMPAT_VARARG)
	if (p->is_vararg & VARARG_NEEDSARG) { /* compat. with old-style vararg? */
		int nvar = actual - nfixargs;  /* number of extra arguments */
		lua_assert(p->is_vararg & VARARG_HASARG);
		luaC_checkGC(L);
		htab = luaH_new(L, nvar, 1);  /* create `arg' table */
		for (i = 0; i < nvar; i++)  /* put extra arguments into `arg' table */
			setobj2n(L, luaH_setnum(L, htab, i + 1), L->top - nvar + i);
		/* store counter in field `n' */
		setnvalue(luaH_setstr(L, htab, luaS_newliteral(L, "n")), cast_num(nvar));
	}
#endif
	/* move fixed parameters to final position */
	fixed = L->top - actual;  /* first fixed argument */
	base = L->top;  /* final position of first argument */
	for (i = 0; i < nfixargs; i++) {
		setobjs2s(L, L->top++, fixed + i);
		setnilvalue(fixed + i);
	}
	/* add `arg' parameter */
	if (htab) {
		sethvalue(L, L->top++, htab);
		lua_assert(iswhite(obj2gco(htab)));
	}
	return base;
}

#define inc_ci(L) \
  ((L->ci == L->end_ci) ? luaD_growCI(L) : \
   (condhardstacktests(luaD_reallocCI(L, L->size_ci)), ++L->ci))

int luaD_precall(lua_State* L, StkId func, int nresults) {
	LClosure* cl;
	ptrdiff_t funcr;
	if (!ttisfunction(func)) /* `func' is not a function? */
		func = luaD_tryfuncTM(L, func);  /* check the `function' tag method */
	funcr = savestack(L, func);
	cl = &clvalue(func)->l;
	L->ci->savedpc = L->savedpc;
	if (!cl->isC) {  /* Lua function? prepare its call */
		CallInfo* ci;
		StkId st, base;
		Proto* p = cl->p;
		if (p->jit_status <= JIT_S_NONE) { /* JIT compiler enabled? */
			if (p->jit_status == JIT_S_OK)
				return G(L)->jit_gateLJ(L, func, nresults);  /* Run compiled code. */
			else
				return luaJIT_run(L, func, nresults);  /* Compile and run code. */
		}
		luaD_checkstack(L, p->maxstacksize);
		func = restorestack(L, funcr);
		if (!p->is_vararg) {  /* no varargs? */
			base = func + 1;
			if (L->top > base + p->numparams)
				L->top = base + p->numparams;
		}
		else {  /* vararg function */
			int nargs = cast_int(L->top - func) - 1;
			base = adjust_varargs(L, p, nargs);
			func = restorestack(L, funcr);  /* previous call may change the stack */
		}
		ci = inc_ci(L);  /* now `enter' new function */
		ci->func = func;
		L->base = ci->base = base;
		ci->top = L->base + p->maxstacksize;
		lua_assert(ci->top <= L->stack_last);
		L->savedpc = p->code;  /* starting point */
		ci->tailcalls = 0;
		ci->nresults = nresults;
		for (st = L->top; st < ci->top; st++)
			setnilvalue(st);
		L->top = ci->top;
		if (L->hookmask & LUA_MASKCALL) {
			L->savedpc++;  /* hooks assume 'pc' is already incremented */
			luaD_callhook(L, LUA_HOOKCALL, -1);
			L->savedpc--;  /* correct 'pc' */
		}
		return PCRLUA;
	}
	else {  /* if is a C function, call it */
		CallInfo* ci;
		int n;
		luaD_checkstack(L, LUA_MINSTACK);  /* ensure minimum stack size */
		ci = inc_ci(L);  /* now `enter' new function */
		ci->func = restorestack(L, funcr);
		L->base = ci->base = ci->func + 1;
		ci->top = L->top + LUA_MINSTACK;
		lua_assert(ci->top <= L->stack_last);
		ci->nresults = nresults;
		if (L->hookmask & LUA_MASKCALL)
			luaD_callhook(L, LUA_HOOKCALL, -1);
		lua_unlock(L);
		n = (*curr_func(L)->c.f)(L);  /* do the actual call */
		lua_lock(L);
		if (n < 0)  /* yielding? */
			return PCRYIELD;
		else {
			luaD_poscall(L, L->top - n);
			return PCRC;
		}
	}
}

void luaD_callhook(lua_State* L, int event, int line) {
	lua_Hook hook = L->hook;
	if (hook && L->allowhook) {
		ptrdiff_t top = savestack(L, L->top);
		ptrdiff_t ci_top = savestack(L, L->ci->top);
		lua_Debug ar;
		ar.event = event;
		ar.currentline = line;
		if (event == LUA_HOOKTAILRET)
			ar.i_ci = 0;  /* tail call; no debug information about it */
		else
			ar.i_ci = cast_int(L->ci - L->base_ci);
		luaD_checkstack(L, LUA_MINSTACK);  /* ensure minimum stack size */
		L->ci->top = L->top + LUA_MINSTACK;
		lua_assert(L->ci->top <= L->stack_last);
		L->allowhook = 0;  /* cannot call hooks inside a hook */
		lua_unlock(L);
		(*hook)(L, &ar);
		lua_lock(L);
		lua_assert(!L->allowhook);
		L->allowhook = 1;
		L->ci->top = restorestack(L, ci_top);
		L->top = restorestack(L, top);
	}
}

StkId luaD_tryfuncTM(lua_State* L, StkId func) {
	const TValue* tm = luaT_gettmbyobj(L, func, TM_CALL);
	StkId p;
	ptrdiff_t funcr = savestack(L, func);
	if (!ttisfunction(tm))
		luaG_typeerror(L, func, "call");
	/* Open a hole inside the stack at `func' */
	for (p = L->top; p > func; p--) setobjs2s(L, p, p - 1);
	incr_top(L);
	func = restorestack(L, funcr);  /* previous call may change stack */
	setobj2s(L, func, tm);  /* tag method is the new function to be called */
	return func;
}

static StkId callrethooks(lua_State* L, StkId firstResult) {
	ptrdiff_t fr = savestack(L, firstResult);  /* next call may change stack */
	luaD_callhook(L, LUA_HOOKRET, -1);
	if (f_isLua(L->ci)) {  /* Lua function? */
		while ((L->hookmask & LUA_MASKRET) && L->ci->tailcalls--) /* tail calls */
			luaD_callhook(L, LUA_HOOKTAILRET, -1);
	}
	return restorestack(L, fr);
}

int luaD_poscall(lua_State* L, StkId firstResult) {
	StkId res;
	int wanted, i;
	CallInfo* ci;
	if (L->hookmask & LUA_MASKRET)
		firstResult = callrethooks(L, firstResult);
	ci = L->ci--;
	res = ci->func;  /* res == final position of 1st result */
	wanted = ci->nresults;
	L->base = (ci - 1)->base;  /* restore base */
	L->savedpc = (ci - 1)->savedpc;  /* restore savedpc */
	/* move results to correct place */
	for (i = wanted; i != 0 && firstResult < L->top; i--)
		setobjs2s(L, res++, firstResult++);
	while (i-- > 0)
		setnilvalue(res++);
	L->top = res;
	return (wanted - LUA_MULTRET);  /* 0 iff wanted == LUA_MULTRET */
}

void luaD_reallocCI(lua_State* L, int newsize) {
	CallInfo* oldci = L->base_ci;
	luaM_reallocvector(L, L->base_ci, L->size_ci, newsize, CallInfo);
	L->size_ci = newsize;
	L->ci = (L->ci - oldci) + L->base_ci;
	L->end_ci = L->base_ci + L->size_ci - 1;
}

CallInfo* luaD_growCI(lua_State* L) {
	if (L->size_ci > LUAI_MAXCALLS)  /* overflow while handling overflow? */
		luaD_throw(L, LUA_ERRERR);
	else {
		luaD_reallocCI(L, 2 * L->size_ci);
		if (L->size_ci > LUAI_MAXCALLS)
			luaG_runerror(L, "stack overflow");
	}
	return ++L->ci;
}

static void correctstack(lua_State* L, TValue* oldstack) {
	CallInfo* ci;
	GCObject* up;
	L->top = (L->top - oldstack) + L->stack;
	for (up = L->openupval; up != NULL; up = up->gch.next)
		gco2uv(up)->v = (gco2uv(up)->v - oldstack) + L->stack;
	for (ci = L->base_ci; ci <= L->ci; ci++) {
		ci->top = (ci->top - oldstack) + L->stack;
		ci->base = (ci->base - oldstack) + L->stack;
		ci->func = (ci->func - oldstack) + L->stack;
	}
	L->base = (L->base - oldstack) + L->stack;
}

void luaD_reallocstack(lua_State* L, int newsize) {
	TValue* oldstack = L->stack;
	int realsize = newsize + 1 + EXTRA_STACK;
	lua_assert(L->stack_last - L->stack == L->stacksize - EXTRA_STACK - 1);
	luaM_reallocvector(L, L->stack, L->stacksize, realsize, TValue);
	L->stacksize = realsize;
	L->stack_last = L->stack + newsize;
	correctstack(L, oldstack);
}

void luaD_growstack(lua_State* L, int n) {
	if (n <= L->stacksize)  /* double size is enough? */
		luaD_reallocstack(L, 2 * L->stacksize);
	else
		luaD_reallocstack(L, L->stacksize + n);
}

static void restore_stack_limit(lua_State* L) {
	lua_assert(L->stack_last - L->stack == L->stacksize - EXTRA_STACK - 1);
	if (L->size_ci > LUAI_MAXCALLS) {  /* there was an overflow? */
		int inuse = cast_int(L->ci - L->base_ci);
		if (inuse + 1 < LUAI_MAXCALLS)  /* can `undo' overflow? */
			luaD_reallocCI(L, LUAI_MAXCALLS);
	}
}

static void resetstack(lua_State* L, int status) {
	L->ci = L->base_ci;
	L->base = L->ci->base;
	luaF_close(L, L->base);  /* close eventual pending closures */
	luaD_seterrorobj(L, status, L->base);
	L->nCcalls = 0;
	L->allowhook = 1;
	restore_stack_limit(L);
	L->errfunc = 0;
	L->errorJmp = NULL;
}

/* chain list of long jump buffers */
struct lua_longjmp {
	struct lua_longjmp* previous;
	luai_jmpbuf b;
	volatile int status;  /* error code */
};

void luaD_throw(lua_State* L, int errcode) {
	if (L->errorJmp) {
		L->errorJmp->status = errcode;
		LUAI_THROW(L, L->errorJmp);
	}
	else {
		L->status = cast_byte(errcode);
		if (G(L)->panic) {
			resetstack(L, errcode);
			lua_unlock(L);
			G(L)->panic(L);
		}
		exit(EXIT_FAILURE);
	}
}

void luaD_seterrorobj(lua_State* L, int errcode, StkId oldtop) {
	switch (errcode) {
	case LUA_ERRMEM: {
		setsvalue2s(L, oldtop, luaS_newliteral(L, MEMERRMSG));
		break;
	}
	case LUA_ERRERR: {
		setsvalue2s(L, oldtop, luaS_newliteral(L, "error in error handling"));
		break;
	}
	case LUA_ERRSYNTAX:
	case LUA_ERRRUN: {
		setobjs2s(L, oldtop, L->top - 1);  /* error message on current top */
		break;
	}
	}
	L->top = oldtop + 1;
}

#pragma endregion

#pragma region lfunc_c

static void unlinkupval(UpVal* uv) {
	lua_assert(uv->u.l.next->u.l.prev == uv && uv->u.l.prev->u.l.next == uv);
	uv->u.l.next->u.l.prev = uv->u.l.prev;  /* remove from `uvhead' list */
	uv->u.l.prev->u.l.next = uv->u.l.next;
}

void luaF_close(lua_State* L, StkId level) {
	UpVal* uv;
	global_State* g = G(L);
	while (L->openupval != NULL && (uv = ngcotouv(L->openupval))->v >= level) {
		GCObject* o = obj2gco(uv);
		lua_assert(!isblack(o) && uv->v != &uv->u.value);
		L->openupval = uv->next;  /* remove from `open' list */
		if (isdead(g, o))
			luaF_freeupval(L, uv);  /* free upvalue */
		else {
			unlinkupval(uv);
			setobj(L, &uv->u.value, uv->v);
			uv->v = &uv->u.value;  /* now current value lives here */
			luaC_linkupval(L, uv);  /* link upvalue into `gcroot' list */
		}
	}
}

void luaF_freeproto(lua_State* L, Proto* f) {
	luaJIT_freeproto(L, f);
	luaM_freearray(L, f->code, f->sizecode, Instruction);
	luaM_freearray(L, f->p, f->sizep, Proto*);
	luaM_freearray(L, f->k, f->sizek, TValue);
	luaM_freearray(L, f->lineinfo, f->sizelineinfo, int);
	luaM_freearray(L, f->locvars, f->sizelocvars, struct LocVar);
	luaM_freearray(L, f->upvalues, f->sizeupvalues, TString*);
	luaM_free(L, f);
}

void luaF_freeclosure(lua_State* L, Closure* c) {
	int size = (c->c.isC) ? sizeCclosure(c->c.nupvalues) :
		sizeLclosure(c->l.nupvalues);
	luaM_freemem(L, c, size);
}

void luaF_freeupval(lua_State* L, UpVal* uv) {
	if (uv->v != &uv->u.value)  /* is it open? */
		unlinkupval(uv);  /* remove from open list */
	luaM_free(L, uv);  /* free upvalue */
}

/*
** Look for n-th local variable at line `line' in function `func'.
** Returns NULL if not found.
*/
const char* luaF_getlocalname(const Proto* f, int local_number, int pc) {
	int i;
	for (i = 0; i < f->sizelocvars && f->locvars[i].startpc <= pc; i++) {
		if (pc < f->locvars[i].endpc) {  /* is variable active? */
			local_number--;
			if (local_number == 0)
				return getstr(f->locvars[i].varname);
		}
	}
	return NULL;  /* not found */
}

Closure* luaF_newLclosure(lua_State* L, int nelems, Table* e) {
	Closure* c = cast(Closure*, luaM_malloc(L, sizeLclosure(nelems)));
	luaC_link(L, obj2gco(c), LUA_TFUNCTION);
	c->l.isC = 0;
	c->l.env = e;
	c->l.jit_gate = G(L)->jit_gateJL;
	c->l.nupvalues = cast_byte(nelems);
	while (nelems--) c->l.upvals[nelems] = NULL;
	return c;
}

UpVal* luaF_findupval(lua_State* L, StkId level) {
	global_State* g = G(L);
	GCObject** pp = &L->openupval;
	UpVal* p;
	UpVal* uv;
	while (*pp != NULL && (p = ngcotouv(*pp))->v >= level) {
		lua_assert(p->v != &p->u.value);
		if (p->v == level) {  /* found a corresponding upvalue? */
			if (isdead(g, obj2gco(p)))  /* is it dead? */
				changewhite(obj2gco(p));  /* ressurect it */
			return p;
		}
		pp = &p->next;
	}
	uv = luaM_new(L, UpVal);  /* not found: create a new one */
	uv->tt = LUA_TUPVAL;
	uv->marked = luaC_white(g);
	uv->v = level;  /* current value lives in the stack */
	uv->next = *pp;  /* chain it in the proper position */
	*pp = obj2gco(uv);
	uv->u.l.prev = &g->uvhead;  /* double link it in `uvhead' list */
	uv->u.l.next = g->uvhead.u.l.next;
	uv->u.l.next->u.l.prev = uv;
	g->uvhead.u.l.next = uv;
	lua_assert(uv->u.l.next->u.l.prev == uv && uv->u.l.prev->u.l.next == uv);
	return uv;
}

#pragma endregion

#pragma region ltable_c

#define hashpow2(t,n)      (gnode(t, lmod((n), sizenode(t))))
#define hashstr(t,str)  hashpow2(t, (str)->tsv.hash)

#define dummynode		(&dummynode_)

static const Node dummynode_ = {
  {{NULL}, LUA_TNIL},  /* value */
  {{{NULL}, LUA_TNIL, NULL}}  /* key */
};

/*
** search function for strings
*/
const TValue* luaH_getstr(Table* t, TString* key) {
	Node* n = hashstr(t, key);
	do {  /* check whether `key' is somewhere in the chain */
		if (ttisstring(gkey(n)) && rawtsvalue(gkey(n)) == key)
			return gval(n);  /* that's it */
		else n = gnext(n);
	} while (n);
	return luaO_nilobject;
}

void luaH_free(lua_State* L, Table* t) {
	if (t->node != dummynode)
		luaM_freearray(L, t->node, sizenode(t), Node);
	luaM_freearray(L, t->array, t->sizearray, TValue);
	luaM_free(L, t);
}

TValue* luaH_setnum(lua_State* L, Table* t, int key) {
	const TValue* p = luaH_getnum(t, key);
	if (p != luaO_nilobject)
		return cast(TValue*, p);
	else {
		TValue k;
		setnvalue(&k, cast_num(key));
		return luaH_newkey(L, t, &k);
	}
}

/*
** number of ints inside a lua_Number
*/
#define numints		cast_int(sizeof(lua_Number)/sizeof(int))

/*
** for some types, it is better to avoid modulus by power of 2, as
** they tend to have many 2 factors.
*/
#define hashmod(t,n)	(gnode(t, ((n) % ((sizenode(t)-1)|1))))

/*
** hash for lua_Numbers
*/
static Node* hashnum(const Table* t, lua_Number n) {
	unsigned int a[numints];
	int i;
	if (luai_numeq(n, 0))  /* avoid problems with -0 */
		return gnode(t, 0);
	memcpy(a, &n, sizeof(a));
	for (i = 1; i < numints; i++) a[0] += a[i];
	return hashmod(t, a[0]);
}

/*
** search function for integers
*/
const TValue* luaH_getnum(Table* t, int key) {
	/* (1 <= key && key <= t->sizearray) */
	if (cast(unsigned int, key - 1) < cast(unsigned int, t->sizearray))
		return &t->array[key - 1];
	else {
		lua_Number nk = cast_num(key);
		Node* n = hashnum(t, nk);
		do {  /* check whether `key' is somewhere in the chain */
			if (ttisnumber(gkey(n)) && luai_numeq(nvalue(gkey(n)), nk))
				return gval(n);  /* that's it */
			else n = gnext(n);
		} while (n);
		return luaO_nilobject;
	}
}

TValue* luaH_setstr(lua_State* L, Table* t, TString* key) {
	const TValue* p = luaH_getstr(t, key);
	if (p != luaO_nilobject)
		return cast(TValue*, p);
	else {
		TValue k;
		setsvalue(L, &k, key);
		return luaH_newkey(L, t, &k);
	}
}

static void setarrayvector(lua_State* L, Table* t, int size) {
	int i;
	luaM_reallocvector(L, t->array, t->sizearray, size, TValue);
	for (i = t->sizearray; i < size; i++)
		setnilvalue(&t->array[i]);
	t->sizearray = size;
}

/*
** max size of array part is 2^MAXBITS
*/
#if LUAI_BITSINT > 26
#define MAXBITS		26
#else
#define MAXBITS		(LUAI_BITSINT-2)
#endif

#define MAXASIZE	(1 << MAXBITS)

static void setnodevector(lua_State* L, Table* t, int size) {
	int lsize;
	if (size == 0) {  /* no elements to hash part? */
		t->node = cast(Node*, dummynode);  /* use common `dummynode' */
		lsize = 0;
	}
	else {
		int i;
		lsize = ceillog2(size);
		if (lsize > MAXBITS)
			luaG_runerror(L, "table overflow");
		size = twoto(lsize);
		t->node = luaM_newvector(L, size, Node);
		for (i = 0; i < size; i++) {
			Node* n = gnode(t, i);
			gnext(n) = NULL;
			setnilvalue(gkey(n));
			setnilvalue(gval(n));
		}
	}
	t->lsizenode = cast_byte(lsize);
	t->lastfree = gnode(t, size);  /* all positions are free */
}

Table* luaH_new(lua_State* L, int narray, int nhash) {
	Table* t = luaM_new(L, Table);
	luaC_link(L, obj2gco(t), LUA_TTABLE);
	t->metatable = NULL;
	t->flags = cast_byte(~0);
	/* temporary values (kept only if some malloc fails) */
	t->array = NULL;
	t->sizearray = 0;
	t->lsizenode = 0;
	t->node = cast(Node*, dummynode);
	setarrayvector(L, t, narray);
	setnodevector(L, t, nhash);
	return t;
}

#define hashboolean(t,p)        hashpow2(t, p)

#define hashpointer(t,p)	hashmod(t, IntPoint(p))

/*
** returns the `main' position of an element in a table (that is, the index
** of its hash value)
*/
static Node* mainposition(const Table* t, const TValue* key) {
	switch (ttype(key)) {
	case LUA_TNUMBER:
		return hashnum(t, nvalue(key));
	case LUA_TSTRING:
		return hashstr(t, rawtsvalue(key));
	case LUA_TBOOLEAN:
		return hashboolean(t, bvalue(key));
	case LUA_TLIGHTUSERDATA:
		return hashpointer(t, pvalue(key));
	default:
		return hashpointer(t, gcvalue(key));
	}
}

static Node* getfreepos(Table* t) {
	while (t->lastfree-- > t->node) {
		if (ttisnil(gkey(t->lastfree)))
			return t->lastfree;
	}
	return NULL;  /* could not find a free place */
}

static int numusearray(const Table* t, int* nums) {
	int lg;
	int ttlg;  /* 2^lg */
	int ause = 0;  /* summation of `nums' */
	int i = 1;  /* count to traverse all array keys */
	for (lg = 0, ttlg = 1; lg <= MAXBITS; lg++, ttlg *= 2) {  /* for each slice */
		int lc = 0;  /* counter */
		int lim = ttlg;
		if (lim > t->sizearray) {
			lim = t->sizearray;  /* adjust upper limit */
			if (i > lim)
				break;  /* no more elements to count */
		}
		/* count elements in range (2^(lg-1), 2^lg] */
		for (; i <= lim; i++) {
			if (!ttisnil(&t->array[i - 1]))
				lc++;
		}
		nums[lg] += lc;
		ause += lc;
	}
	return ause;
}

/*
** returns the index for `key' if `key' is an appropriate key to live in
** the array part of the table, -1 otherwise.
*/
static int arrayindex(const TValue* key) {
	if (ttisnumber(key)) {
		lua_Number n = nvalue(key);
		int k;
		lua_number2int(k, n);
		if (luai_numeq(cast_num(k), n))
			return k;
	}
	return -1;  /* `key' did not match some condition */
}

static int countint(const TValue* key, int* nums) {
	int k = arrayindex(key);
	if (0 < k && k <= MAXASIZE) {  /* is `key' an appropriate array index? */
		nums[ceillog2(k)]++;  /* count as such */
		return 1;
	}
	else
		return 0;
}

static int numusehash(const Table* t, int* nums, int* pnasize) {
	int totaluse = 0;  /* total number of elements */
	int ause = 0;  /* summation of `nums' */
	int i = sizenode(t);
	while (i--) {
		Node* n = &t->node[i];
		if (!ttisnil(gval(n))) {
			ause += countint(key2tval(n), nums);
			totaluse++;
		}
	}
	*pnasize += ause;
	return totaluse;
}

static int computesizes(int nums[], int* narray) {
	int i;
	int twotoi;  /* 2^i */
	int a = 0;  /* number of elements smaller than 2^i */
	int na = 0;  /* number of elements to go to array part */
	int n = 0;  /* optimal size for array part */
	for (i = 0, twotoi = 1; twotoi / 2 < *narray; i++, twotoi *= 2) {
		if (nums[i] > 0) {
			a += nums[i];
			if (a > twotoi / 2) {  /* more than half elements present? */
				n = twotoi;  /* optimal size (till now) */
				na = a;  /* all elements smaller than n will go to array part */
			}
		}
		if (a == *narray) break;  /* all elements already counted */
	}
	*narray = n;
	lua_assert(*narray / 2 <= na && na <= *narray);
	return na;
}

static void resize(lua_State* L, Table* t, int nasize, int nhsize) {
	int i;
	int oldasize = t->sizearray;
	int oldhsize = t->lsizenode;
	Node* nold = t->node;  /* save old hash ... */
	if (nasize > oldasize)  /* array part must grow? */
		setarrayvector(L, t, nasize);
	/* create new hash part with appropriate size */
	setnodevector(L, t, nhsize);
	if (nasize < oldasize) {  /* array part must shrink? */
		t->sizearray = nasize;
		/* re-insert elements from vanishing slice */
		for (i = nasize; i < oldasize; i++) {
			if (!ttisnil(&t->array[i]))
				setobjt2t(L, luaH_setnum(L, t, i + 1), &t->array[i]);
		}
		/* shrink array */
		luaM_reallocvector(L, t->array, oldasize, nasize, TValue);
	}
	/* re-insert elements from hash part */
	for (i = twoto(oldhsize) - 1; i >= 0; i--) {
		Node* old = nold + i;
		if (!ttisnil(gval(old)))
			setobjt2t(L, luaH_set(L, t, key2tval(old)), gval(old));
	}
	if (nold != dummynode)
		luaM_freearray(L, nold, twoto(oldhsize), Node);  /* free old array */
}

static void rehash(lua_State* L, Table* t, const TValue* ek) {
	int nasize, na;
	int nums[MAXBITS + 1];  /* nums[i] = number of keys between 2^(i-1) and 2^i */
	int i;
	int totaluse;
	for (i = 0; i <= MAXBITS; i++) nums[i] = 0;  /* reset counts */
	nasize = numusearray(t, nums);  /* count keys in array part */
	totaluse = nasize;  /* all those keys are integer keys */
	totaluse += numusehash(t, nums, &nasize);  /* count keys in hash part */
	/* count extra key */
	nasize += countint(ek, nums);
	totaluse++;
	/* compute new size for array part */
	na = computesizes(nums, &nasize);
	/* resize the table to new computed sizes */
	resize(L, t, nasize, totaluse - na);
}

TValue* luaH_newkey(lua_State* L, Table* t, const TValue* key) {
	Node* mp = mainposition(t, key);
	if (!ttisnil(gval(mp)) || mp == dummynode) {
		Node* othern;
		Node* n = getfreepos(t);  /* get a free place */
		if (n == NULL) {  /* cannot find a free place? */
			rehash(L, t, key);  /* grow table */
			return luaH_set(L, t, key);  /* re-insert key into grown table */
		}
		lua_assert(n != dummynode);
		othern = mainposition(t, key2tval(mp));
		if (othern != mp) {  /* is colliding node out of its main position? */
		  /* yes; move colliding node into free position */
			while (gnext(othern) != mp) othern = gnext(othern);  /* find previous */
			gnext(othern) = n;  /* redo the chain with `n' in place of `mp' */
			*n = *mp;  /* copy colliding node into free pos. (mp->next also goes) */
			gnext(mp) = NULL;  /* now `mp' is free */
			setnilvalue(gval(mp));
		}
		else {  /* colliding node is in its own main position */
		  /* new node will go into free position */
			gnext(n) = gnext(mp);  /* chain new position */
			gnext(mp) = n;
			mp = n;
		}
	}
	gkey(mp)->value = key->value; gkey(mp)->tt = key->tt;
	luaC_barriert(L, t, key);
	lua_assert(ttisnil(gval(mp)));
	return gval(mp);
}

TValue* luaH_set(lua_State* L, Table* t, const TValue* key) {
	const TValue* p = luaH_get(t, key);
	t->flags = 0;
	if (p != luaO_nilobject)
		return cast(TValue*, p);
	else {
		if (ttisnil(key)) luaG_runerror(L, "table index is nil");
		else if (ttisnumber(key) && luai_numisnan(nvalue(key)))
			luaG_runerror(L, "table index is NaN");
		return luaH_newkey(L, t, key);
	}
}

/*
** main search function
*/
const TValue* luaH_get(Table* t, const TValue* key) {
	switch (ttype(key)) {
	case LUA_TNIL: return luaO_nilobject;
	case LUA_TSTRING: return luaH_getstr(t, rawtsvalue(key));
	case LUA_TNUMBER: {
		int k;
		lua_Number n = nvalue(key);
		lua_number2int(k, n);
		if (luai_numeq(cast_num(k), nvalue(key))) /* index is int? */
			return luaH_getnum(t, k);  /* use specialized version */
		  /* else go through */
	}
	default: {
		Node* n = mainposition(t, key);
		do {  /* check whether `key' is somewhere in the chain */
			if (luaO_rawequalObj(key2tval(n), key))
				return gval(n);  /* that's it */
			else n = gnext(n);
		} while (n);
		return luaO_nilobject;
	}
	}
}

void luaH_resizearray(lua_State* L, Table* t, int nasize) {
	int nsize = (t->node == dummynode) ? 0 : sizenode(t);
	resize(L, t, nasize, nsize);
}

static int unbound_search(Table* t, unsigned int j) {
	unsigned int i = j;  /* i is zero or a present index */
	j++;
	/* find `i' and `j' such that i is present and j is not */
	while (!ttisnil(luaH_getnum(t, j))) {
		i = j;
		j *= 2;
		if (j > cast(unsigned int, MAX_INT)) {  /* overflow? */
		  /* table was built with bad purposes: resort to linear search */
			i = 1;
			while (!ttisnil(luaH_getnum(t, i))) i++;
			return i - 1;
		}
	}
	/* now do a binary search between them */
	while (j - i > 1) {
		unsigned int m = (i + j) / 2;
		if (ttisnil(luaH_getnum(t, m))) j = m;
		else i = m;
	}
	return i;
}

/*
** Try to find a boundary in table `t'. A `boundary' is an integer index
** such that t[i] is non-nil and t[i+1] is nil (and 0 if t[1] is nil).
*/
int luaH_getn(Table* t) {
	unsigned int j = t->sizearray;
	if (j > 0 && ttisnil(&t->array[j - 1])) {
		/* there is a boundary in the array part: (binary) search for it */
		unsigned int i = 0;
		while (j - i > 1) {
			unsigned int m = (i + j) / 2;
			if (ttisnil(&t->array[m - 1])) j = m;
			else i = m;
		}
		return i;
	}
	/* else must find a boundary in hash part */
	else if (t->node == dummynode)  /* hash part is empty? */
		return j;  /* that is easy... */
	else return unbound_search(t, j);
}

#pragma endregion

#pragma region lcoco_c

#define COCO_FREE(L) \
  DeleteFiber(L2COCO(L)->fib); \
  L2COCO(L)->fib = NULL;

/* Free the C stack of a coroutine. Called from lstate.c. */
void luaCOCO_free(lua_State* L)
{
	COCO_FREE(L)
}

#pragma endregion

#pragma region lstate_c

#define state_size(x)	(sizeof(x) + LUAI_EXTRASPACE)
#define fromstate(l)	(cast(lu_byte *, (l)) - LUAI_EXTRASPACE)

#pragma endregion

#pragma region lobject_c

static void freestack(lua_State* L, lua_State* L1) {
	luaM_freearray(L, L1->base_ci, L1->size_ci, CallInfo);
	luaM_freearray(L, L1->stack, L1->stacksize, TValue);
}

void luaE_freethread(lua_State* L, lua_State* L1) {
	luaF_close(L1, L1->stack);  /* close all upvalues for this thread */
	lua_assert(L1->openupval == NULL);
	luai_userstatefree(L1);
	freestack(L, L1);
	luaM_freemem(L, fromstate(L1), state_size(lua_State));
}

/* converts back */
int luaO_fb2int(int x) {
	int e = (x >> 3) & 31;
	if (e == 0) return x;
	else return ((x & 7) + 8) << (e - 1);
}

int luaO_log2(unsigned int x) {
	static const lu_byte log_2[256] = {
	  0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
	  6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
	  7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	  7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
	  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,
	  8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8
	};
	int l = -1;
	while (x >= 256) { l += 8; x >>= 8; }
	return l + log_2[x];

}

int luaO_rawequalObj(const TValue* t1, const TValue* t2) {
	if (ttype(t1) != ttype(t2)) return 0;
	else switch (ttype(t1)) {
	case LUA_TNIL:
		return 1;
	case LUA_TNUMBER:
		return luai_numeq(nvalue(t1), nvalue(t2));
	case LUA_TBOOLEAN:
		return bvalue(t1) == bvalue(t2);  /* boolean true must be 1 !! */
	case LUA_TLIGHTUSERDATA:
		return pvalue(t1) == pvalue(t2);
	default:
		lua_assert(iscollectable(t1));
		return gcvalue(t1) == gcvalue(t2);
	}
}

static void pushstr(lua_State* L, const char* str) {
	setsvalue2s(L, L->top, luaS_new(L, str));
	incr_top(L);
}

/* this function handles only `%d', `%c', %f, %p, and `%s' formats */
const char* luaO_pushvfstring(lua_State* L, const char* fmt, va_list argp) {
	int n = 1;
	pushstr(L, "");
	for (;;) {
		const char* e = strchr(fmt, '%');
		if (e == NULL) break;
		setsvalue2s(L, L->top, luaS_newlstr(L, fmt, e - fmt));
		incr_top(L);
		switch (*(e + 1)) {
		case 's': {
			const char* s = va_arg(argp, char*);
			if (s == NULL) s = "(null)";
			pushstr(L, s);
			break;
		}
		case 'c': {
			char buff[2];
			buff[0] = cast(char, va_arg(argp, int));
			buff[1] = '\0';
			pushstr(L, buff);
			break;
		}
		case 'd': {
			setnvalue(L->top, cast_num(va_arg(argp, int)));
			incr_top(L);
			break;
		}
		case 'f': {
			setnvalue(L->top, cast_num(va_arg(argp, l_uacNumber)));
			incr_top(L);
			break;
		}
		case 'p': {
			char buff[4 * sizeof(void*) + 8]; /* should be enough space for a `%p' */
			sprintf(buff, "%p", va_arg(argp, void*));
			pushstr(L, buff);
			break;
		}
		case '%': {
			pushstr(L, "%");
			break;
		}
		default: {
			char buff[3];
			buff[0] = '%';
			buff[1] = *(e + 1);
			buff[2] = '\0';
			pushstr(L, buff);
			break;
		}
		}
		n += 2;
		fmt = e + 2;
	}
	pushstr(L, fmt);
	luaV_concat(L, n + 1, cast_int(L->top - L->base) - 1);
	L->top -= n;
	return svalue(L->top - 1);
}

const char* luaO_pushfstring(lua_State* L, const char* fmt, ...) {
	const char* msg;
	va_list argp;
	va_start(argp, fmt);
	msg = luaO_pushvfstring(L, fmt, argp);
	va_end(argp);
	return msg;
}

void luaO_chunkid(char* out, const char* source, size_t bufflen) {
	if (*source == '=') {
		strncpy(out, source + 1, bufflen);  /* remove first char */
		out[bufflen - 1] = '\0';  /* ensures null termination */
	}
	else {  /* out = "source", or "...source" */
		if (*source == '@') {
			size_t l;
			source++;  /* skip the `@' */
			bufflen -= sizeof(" '...' ");
			l = strlen(source);
			strcpy(out, "");
			if (l > bufflen) {
				source += (l - bufflen);  /* get last part of file name */
				strcat(out, "...");
			}
			strcat(out, source);
		}
		else {  /* out = [string "string"] */
			size_t len = strcspn(source, "\n\r");  /* stop at first newline */
			bufflen -= sizeof(" [string \"...\"] ");
			if (len > bufflen) len = bufflen;
			strcpy(out, "[string \"");
			if (source[len] != '\0') {  /* must truncate? */
				strncat(out, source, len);
				strcat(out, "...");
			}
			else
				strcat(out, source);
			strcat(out, "\"]");
		}
	}
}

const TValue luaO_nilobject_ = { {NULL}, LUA_TNIL };

#pragma endregion

#pragma region ltm_c

/*
** function to be used with macro "fasttm": optimized for absence of
** tag methods
*/
const TValue* luaT_gettm(Table* events, TMS event, TString* ename) {
	const TValue* tm = luaH_getstr(events, ename);
	lua_assert(event <= TM_EQ);
	if (ttisnil(tm)) {  /* no tag method? */
		events->flags |= cast_byte(1u << event);  /* cache this fact */
		return NULL;
	}
	else return tm;
}

const TValue* luaT_gettmbyobj(lua_State* L, const TValue* o, TMS event) {
	Table* mt;
	switch (ttype(o)) {
	case LUA_TTABLE:
		mt = hvalue(o)->metatable;
		break;
	case LUA_TUSERDATA:
		mt = uvalue(o)->metatable;
		break;
	default:
		mt = G(L)->mt[ttype(o)];
	}
	return (mt ? luaH_getstr(mt, G(L)->tmname[event]) : luaO_nilobject);
}

const char* const luaT_typenames[] = {
  "nil", "boolean", "userdata", "number",
  "string", "table", "function", "userdata", "thread",
  "proto", "upval"
};

#pragma endregion

#pragma region lgc_c

#define GCSTEPSIZE	1024u
#define GCSWEEPMAX	40
#define GCSWEEPCOST	10
#define GCFINALIZECOST	100

#define sweepwholelist(L,p)	sweeplist(L,p,MAX_LUMEM)

#define maskmarks	cast_byte(~(bitmask(BLACKBIT)|WHITEBITS))

#define makewhite(g,x)	\
   ((x)->gch.marked = cast_byte(((x)->gch.marked & maskmarks) | luaC_white(g)))

#define white2gray(x)	reset2bits((x)->gch.marked, WHITE0BIT, WHITE1BIT)
#define black2gray(x)	resetbit((x)->gch.marked, BLACKBIT)

#define stringmark(s)	reset2bits((s)->tsv.marked, WHITE0BIT, WHITE1BIT)


#define isfinalized(u)		testbit((u)->marked, FINALIZEDBIT)
#define markfinalized(u)	l_setbit((u)->marked, FINALIZEDBIT)


#define KEYWEAK         bitmask(KEYWEAKBIT)
#define VALUEWEAK       bitmask(VALUEWEAKBIT)



#define markvalue(g,o) { checkconsistency(o); \
  if (iscollectable(o) && iswhite(gcvalue(o))) reallymarkobject(g,gcvalue(o)); }

#define markobject(g,t) { if (iswhite(obj2gco(t))) \
		reallymarkobject(g, obj2gco(t)); }


#define setthreshold(g)  (g->GCthreshold = (g->estimate/100) * g->gcpause)

static void reallymarkobject(global_State* g, GCObject* o) {
	lua_assert(iswhite(o) && !isdead(g, o));
	white2gray(o);
	switch (o->gch.tt) {
	case LUA_TSTRING: {
		return;
	}
	case LUA_TUSERDATA: {
		Table* mt = gco2u(o)->metatable;
		gray2black(o);  /* udata are never gray */
		if (mt) markobject(g, mt);
		markobject(g, gco2u(o)->env);
		return;
	}
	case LUA_TUPVAL: {
		UpVal* uv = gco2uv(o);
		markvalue(g, uv->v);
		if (uv->v == &uv->u.value)  /* closed? */
			gray2black(o);  /* open upvalues are never black */
		return;
	}
	case LUA_TFUNCTION: {
		gco2cl(o)->c.gclist = g->gray;
		g->gray = o;
		break;
	}
	case LUA_TTABLE: {
		gco2h(o)->gclist = g->gray;
		g->gray = o;
		break;
	}
	case LUA_TTHREAD: {
		gco2th(o)->gclist = g->gray;
		g->gray = o;
		break;
	}
	case LUA_TPROTO: {
		gco2p(o)->gclist = g->gray;
		g->gray = o;
		break;
	}
	default: lua_assert(0);
	}
}

static void markmt(global_State* g) {
	int i;
	for (i = 0; i < NUM_TAGS; i++)
		if (g->mt[i]) markobject(g, g->mt[i]);
}

/* mark root set */
static void markroot(lua_State* L) {
	global_State* g = G(L);
	g->gray = NULL;
	g->grayagain = NULL;
	g->weak = NULL;
	markobject(g, g->mainthread);
	/* make global table be traversed before main stack */
	markvalue(g, gt(g->mainthread));
	markvalue(g, registry(L));
	markmt(g);
	g->gcstate = GCSpropagate;
}

static void removeentry(Node* n) {
	lua_assert(ttisnil(gval(n)));
	if (iscollectable(gkey(n)))
		setttype(gkey(n), LUA_TDEADKEY);  /* dead key; remove it */
}

static int traversetable(global_State* g, Table* h) {
	int i;
	int weakkey = 0;
	int weakvalue = 0;
	const TValue* mode;
	if (h->metatable)
		markobject(g, h->metatable);
	mode = gfasttm(g, h->metatable, TM_MODE);
	if (mode && ttisstring(mode)) {  /* is there a weak mode? */
		weakkey = (strchr(svalue(mode), 'k') != NULL);
		weakvalue = (strchr(svalue(mode), 'v') != NULL);
		if (weakkey || weakvalue) {  /* is really weak? */
			h->marked &= ~(KEYWEAK | VALUEWEAK);  /* clear bits */
			h->marked |= cast_byte((weakkey << KEYWEAKBIT) |
				(weakvalue << VALUEWEAKBIT));
			h->gclist = g->weak;  /* must be cleared after GC, ... */
			g->weak = obj2gco(h);  /* ... so put in the appropriate list */
		}
	}
	if (weakkey && weakvalue) return 1;
	if (!weakvalue) {
		i = h->sizearray;
		while (i--)
			markvalue(g, &h->array[i]);
	}
	i = sizenode(h);
	while (i--) {
		Node* n = gnode(h, i);
		lua_assert(ttype(gkey(n)) != LUA_TDEADKEY || ttisnil(gval(n)));
		if (ttisnil(gval(n)))
			removeentry(n);  /* remove empty entries */
		else {
			lua_assert(!ttisnil(gkey(n)));
			if (!weakkey) markvalue(g, gkey(n));
			if (!weakvalue) markvalue(g, gval(n));
		}
	}
	return weakkey || weakvalue;
}

static void traverseclosure(global_State* g, Closure* cl) {
	markobject(g, cl->c.env);
	if (cl->c.isC) {
		int i;
		for (i = 0; i < cl->c.nupvalues; i++)  /* mark its upvalues */
			markvalue(g, &cl->c.upvalue[i]);
	}
	else {
		int i;
		lua_assert(cl->l.nupvalues == cl->l.p->nups);
		markobject(g, cl->l.p);
		for (i = 0; i < cl->l.nupvalues; i++)  /* mark its upvalues */
			markobject(g, cl->l.upvals[i]);
	}
}

static void checkstacksizes(lua_State* L, StkId max) {
	int ci_used = cast_int(L->ci - L->base_ci);  /* number of `ci' in use */
	int s_used = cast_int(max - L->stack);  /* part of stack in use */
	if (L->size_ci > LUAI_MAXCALLS)  /* handling overflow? */
		return;  /* do not touch the stacks */
	if (4 * ci_used < L->size_ci && 2 * BASIC_CI_SIZE < L->size_ci)
		luaD_reallocCI(L, L->size_ci / 2);  /* still big enough... */
	condhardstacktests(luaD_reallocCI(L, ci_used + 1));
	if (4 * s_used < L->stacksize &&
		2 * (BASIC_STACK_SIZE + EXTRA_STACK) < L->stacksize)
		luaD_reallocstack(L, L->stacksize / 2);  /* still big enough... */
	condhardstacktests(luaD_reallocstack(L, s_used));
}

static void traversestack(global_State* g, lua_State* l) {
	StkId o, lim;
	CallInfo* ci;
	markvalue(g, gt(l));
	lim = l->top;
	for (ci = l->base_ci; ci <= l->ci; ci++) {
		lua_assert(ci->top <= l->stack_last);
		if (lim < ci->top) lim = ci->top;
	}
	for (o = l->stack; o < l->top; o++)
		markvalue(g, o);
	for (; o <= lim; o++)
		setnilvalue(o);
	checkstacksizes(l, lim);
}

/*
** All marks are conditional because a GC may happen while the
** prototype is still being created
*/
static void traverseproto(global_State* g, Proto* f) {
	int i;
	if (f->source) stringmark(f->source);
	for (i = 0; i < f->sizek; i++)  /* mark literals */
		markvalue(g, &f->k[i]);
	for (i = 0; i < f->sizeupvalues; i++) {  /* mark upvalue names */
		if (f->upvalues[i])
			stringmark(f->upvalues[i]);
	}
	for (i = 0; i < f->sizep; i++) {  /* mark nested protos */
		if (f->p[i])
			markobject(g, f->p[i]);
	}
	for (i = 0; i < f->sizelocvars; i++) {  /* mark local-variable names */
		if (f->locvars[i].varname)
			stringmark(f->locvars[i].varname);
	}
}

/*
** traverse one gray object, turning it to black.
** Returns `quantity' traversed.
*/
static l_mem propagatemark(global_State* g) {
	GCObject* o = g->gray;
	lua_assert(isgray(o));
	gray2black(o);
	switch (o->gch.tt) {
	case LUA_TTABLE: {
		Table* h = gco2h(o);
		g->gray = h->gclist;
		if (traversetable(g, h))  /* table is weak? */
			black2gray(o);  /* keep it gray */
		return sizeof(Table) + sizeof(TValue) * h->sizearray +
			sizeof(Node) * sizenode(h);
	}
	case LUA_TFUNCTION: {
		Closure* cl = gco2cl(o);
		g->gray = cl->c.gclist;
		traverseclosure(g, cl);
		return (cl->c.isC) ? sizeCclosure(cl->c.nupvalues) :
			sizeLclosure(cl->l.nupvalues);
	}
	case LUA_TTHREAD: {
		lua_State* th = gco2th(o);
		g->gray = th->gclist;
		th->gclist = g->grayagain;
		g->grayagain = o;
		black2gray(o);
		traversestack(g, th);
		return sizeof(lua_State) + sizeof(TValue) * th->stacksize +
			sizeof(CallInfo) * th->size_ci;
	}
	case LUA_TPROTO: {
		Proto* p = gco2p(o);
		g->gray = p->gclist;
		traverseproto(g, p);
		return sizeof(Proto) + sizeof(Instruction) * p->sizecode +
			sizeof(Proto*) * p->sizep +
			sizeof(TValue) * p->sizek +
			sizeof(int) * p->sizelineinfo +
			sizeof(LocVar) * p->sizelocvars +
			sizeof(TString*) * p->sizeupvalues;
	}
	default: lua_assert(0); return 0;
	}
}

static void remarkupvals(global_State* g) {
	UpVal* uv;
	for (uv = g->uvhead.u.l.next; uv != &g->uvhead; uv = uv->u.l.next) {
		lua_assert(uv->u.l.next->u.l.prev == uv && uv->u.l.prev->u.l.next == uv);
		if (isgray(obj2gco(uv)))
			markvalue(g, uv->v);
	}
}

static size_t propagateall(global_State* g) {
	size_t m = 0;
	while (g->gray) m += propagatemark(g);
	return m;
}

static void marktmu(global_State* g) {
	GCObject* u = g->tmudata;
	if (u) {
		do {
			u = u->gch.next;
			makewhite(g, u);  /* may be marked, if left from previous GC */
			reallymarkobject(g, u);
		} while (u != g->tmudata);
	}
}

/*
** The next function tells whether a key or value can be cleared from
** a weak table. Non-collectable objects are never removed from weak
** tables. Strings behave as `values', so are never removed too. for
** other objects: if really collected, cannot keep them; for userdata
** being finalized, keep them in keys, but not in values
*/
static int iscleared(const TValue* o, int iskey) {
	if (!iscollectable(o)) return 0;
	if (ttisstring(o)) {
		stringmark(rawtsvalue(o));  /* strings are `values', so are never weak */
		return 0;
	}
	return iswhite(gcvalue(o)) ||
		(ttisuserdata(o) && (!iskey && isfinalized(uvalue(o))));
}

/*
** clear collected entries from weaktables
*/
static void cleartable(GCObject* l) {
	while (l) {
		Table* h = gco2h(l);
		int i = h->sizearray;
		lua_assert(testbit(h->marked, VALUEWEAKBIT) ||
			testbit(h->marked, KEYWEAKBIT));
		if (testbit(h->marked, VALUEWEAKBIT)) {
			while (i--) {
				TValue* o = &h->array[i];
				if (iscleared(o, 0))  /* value was collected? */
					setnilvalue(o);  /* remove value */
			}
		}
		i = sizenode(h);
		while (i--) {
			Node* n = gnode(h, i);
			if (!ttisnil(gval(n)) &&  /* non-empty entry? */
				(iscleared(key2tval(n), 1) || iscleared(gval(n), 0))) {
				setnilvalue(gval(n));  /* remove value ... */
				removeentry(n);  /* remove entry from table */
			}
		}
		l = h->gclist;
	}
}

static void atomic(lua_State* L) {
	global_State* g = G(L);
	size_t udsize;  /* total size of userdata to be finalized */
	/* remark occasional upvalues of (maybe) dead threads */
	remarkupvals(g);
	/* traverse objects cautch by write barrier and by 'remarkupvals' */
	propagateall(g);
	/* remark weak tables */
	g->gray = g->weak;
	g->weak = NULL;
	lua_assert(!iswhite(obj2gco(g->mainthread)));
	markobject(g, L);  /* mark running thread */
	markmt(g);  /* mark basic metatables (again) */
	propagateall(g);
	/* remark gray again */
	g->gray = g->grayagain;
	g->grayagain = NULL;
	propagateall(g);
	udsize = luaC_separateudata(L, 0);  /* separate userdata to be finalized */
	marktmu(g);  /* mark `preserved' userdata */
	udsize += propagateall(g);  /* remark, to propagate `preserveness' */
	cleartable(g->weak);  /* remove collected objects from weak tables */
	/* flip current white */
	g->currentwhite = cast_byte(otherwhite(g));
	g->sweepstrgc = 0;
	g->sweepgc = &g->rootgc;
	g->gcstate = GCSsweepstring;
	g->estimate = g->totalbytes - udsize;  /* first estimate */
}

static void freeobj(lua_State* L, GCObject* o) {
	switch (o->gch.tt) {
	case LUA_TPROTO: luaF_freeproto(L, gco2p(o)); break;
	case LUA_TFUNCTION: luaF_freeclosure(L, gco2cl(o)); break;
	case LUA_TUPVAL: luaF_freeupval(L, gco2uv(o)); break;
	case LUA_TTABLE: luaH_free(L, gco2h(o)); break;
	case LUA_TTHREAD: {
		lua_assert(gco2th(o) != L && gco2th(o) != G(L)->mainthread);
		luaE_freethread(L, gco2th(o));
		break;
	}
	case LUA_TSTRING: {
		G(L)->strt.nuse--;
		luaM_freemem(L, o, sizestring(gco2ts(o)));
		break;
	}
	case LUA_TUSERDATA: {
		luaM_freemem(L, o, sizeudata(gco2u(o)));
		break;
	}
	default: lua_assert(0);
	}
}

static GCObject** sweeplist(lua_State* L, GCObject** p, lu_mem count) {
	GCObject* curr;
	global_State* g = G(L);
	int deadmask = otherwhite(g);
	while ((curr = *p) != NULL && count-- > 0) {
		if (curr->gch.tt == LUA_TTHREAD)  /* sweep open upvalues of each thread */
			sweepwholelist(L, &gco2th(curr)->openupval);
		if ((curr->gch.marked ^ WHITEBITS) & deadmask) {  /* not dead? */
			lua_assert(!isdead(g, curr) || testbit(curr->gch.marked, FIXEDBIT));
			makewhite(g, curr);  /* make it white (for next cycle) */
			p = &curr->gch.next;
		}
		else {  /* must erase `curr' */
			lua_assert(isdead(g, curr) || deadmask == bitmask(SFIXEDBIT));
			*p = curr->gch.next;
			if (curr == g->rootgc)  /* is the first element of the list? */
				g->rootgc = curr->gch.next;  /* adjust first */
			freeobj(L, curr);
		}
	}
	return p;
}

static void checkSizes(lua_State* L) {
	global_State* g = G(L);
	/* check size of string hash */
	if (g->strt.nuse < cast(lu_int32, g->strt.size / 4) &&
		g->strt.size > MINSTRTABSIZE * 2)
		luaS_resize(L, g->strt.size / 2);  /* table is too big */
	  /* check size of buffer */
	if (luaZ_sizebuffer(&g->buff) > LUA_MINBUFFER * 2) {  /* buffer too big? */
		size_t newsize = luaZ_sizebuffer(&g->buff) / 2;
		luaZ_resizebuffer(L, &g->buff, newsize);
	}
}

static void GCTM(lua_State* L) {
	global_State* g = G(L);
	GCObject* o = g->tmudata->gch.next;  /* get first element */
	Udata* udata = rawgco2u(o);
	const TValue* tm;
	/* remove udata from `tmudata' */
	if (o == g->tmudata)  /* last element? */
		g->tmudata = NULL;
	else
		g->tmudata->gch.next = udata->uv.next;
	udata->uv.next = g->mainthread->next;  /* return it to `root' list */
	g->mainthread->next = o;
	makewhite(g, o);
	tm = fasttm(L, udata->uv.metatable, TM_GC);
	if (tm != NULL) {
		lu_byte oldah = L->allowhook;
		lu_mem oldt = g->GCthreshold;
		L->allowhook = 0;  /* stop debug hooks during GC tag method */
		g->GCthreshold = 2 * g->totalbytes;  /* avoid GC steps */
		setobj2s(L, L->top, tm);
		setuvalue(L, L->top + 1, udata);
		L->top += 2;
		luaD_call(L, L->top - 2, 0);
		L->allowhook = oldah;  /* restore hooks */
		g->GCthreshold = oldt;  /* restore threshold */
	}
}

static l_mem singlestep(lua_State* L) {
	global_State* g = G(L);
	/*lua_checkmemory(L);*/
	switch (g->gcstate) {
	case GCSpause: {
		markroot(L);  /* start a new collection */
		return 0;
	}
	case GCSpropagate: {
		if (g->gray)
			return propagatemark(g);
		else {  /* no more `gray' objects */
			atomic(L);  /* finish mark phase */
			return 0;
		}
	}
	case GCSsweepstring: {
		lu_mem old = g->totalbytes;
		sweepwholelist(L, &g->strt.hash[g->sweepstrgc++]);
		if (g->sweepstrgc >= g->strt.size)  /* nothing more to sweep? */
			g->gcstate = GCSsweep;  /* end sweep-string phase */
		lua_assert(old >= g->totalbytes);
		g->estimate -= old - g->totalbytes;
		return GCSWEEPCOST;
	}
	case GCSsweep: {
		lu_mem old = g->totalbytes;
		g->sweepgc = sweeplist(L, g->sweepgc, GCSWEEPMAX);
		if (*g->sweepgc == NULL) {  /* nothing more to sweep? */
			checkSizes(L);
			g->gcstate = GCSfinalize;  /* end sweep phase */
		}
		lua_assert(old >= g->totalbytes);
		g->estimate -= old - g->totalbytes;
		return GCSWEEPMAX * GCSWEEPCOST;
	}
	case GCSfinalize: {
		if (g->tmudata) {
			GCTM(L);
			if (g->estimate > GCFINALIZECOST)
				g->estimate -= GCFINALIZECOST;
			return GCFINALIZECOST;
		}
		else {
			g->gcstate = GCSpause;  /* end collection */
			g->gcdept = 0;
			return 0;
		}
	}
	default: lua_assert(0); return 0;
	}
}

void luaC_step(lua_State* L) {
	global_State* g = G(L);
	l_mem lim = (GCSTEPSIZE / 100) * g->gcstepmul;
	if (lim == 0)
		lim = (MAX_LUMEM - 1) / 2;  /* no limit */
	g->gcdept += g->totalbytes - g->GCthreshold;
	do {
		lim -= singlestep(L);
		if (g->gcstate == GCSpause)
			break;
	} while (lim > 0);
	if (g->gcstate != GCSpause) {
		if (g->gcdept < GCSTEPSIZE)
			g->GCthreshold = g->totalbytes + GCSTEPSIZE;  /* - lim/g->gcstepmul;*/
		else {
			g->gcdept -= GCSTEPSIZE;
			g->GCthreshold = g->totalbytes;
		}
	}
	else {
		lua_assert(g->totalbytes >= g->estimate);
		setthreshold(g);
	}
}

size_t luaC_separateudata(lua_State* L, int all) {
	global_State* g = G(L);
	size_t deadmem = 0;
	GCObject** p = &g->mainthread->next;
	GCObject* curr;
	while ((curr = *p) != NULL) {
		if (!(iswhite(curr) || all) || isfinalized(gco2u(curr)))
			p = &curr->gch.next;  /* don't bother with them */
		else if (fasttm(L, gco2u(curr)->metatable, TM_GC) == NULL) {
			markfinalized(gco2u(curr));  /* don't need finalization */
			p = &curr->gch.next;
		}
		else {  /* must call its gc method */
			deadmem += sizeudata(gco2u(curr));
			markfinalized(gco2u(curr));
			*p = curr->gch.next;
			/* link `curr' at the end of `tmudata' list */
			if (g->tmudata == NULL)  /* list is empty? */
				g->tmudata = curr->gch.next = curr;  /* creates a circular list */
			else {
				curr->gch.next = g->tmudata->gch.next;
				g->tmudata->gch.next = curr;
				g->tmudata = curr;
			}
		}
	}
	return deadmem;
}

void luaC_linkupval(lua_State* L, UpVal* uv) {
	global_State* g = G(L);
	GCObject* o = obj2gco(uv);
	o->gch.next = g->rootgc;  /* link upvalue into `rootgc' list */
	g->rootgc = o;
	if (isgray(o)) {
		if (g->gcstate == GCSpropagate) {
			gray2black(o);  /* closed upvalues need barrier */
			luaC_barrier(L, uv, uv->v);
		}
		else {  /* sweep phase: sweep it (turning it into white) */
			makewhite(g, o);
			lua_assert(g->gcstate != GCSfinalize && g->gcstate != GCSpause);
		}
	}
}

void luaC_barrierf(lua_State* L, GCObject* o, GCObject* v) {
	global_State* g = G(L);
	lua_assert(isblack(o) && iswhite(v) && !isdead(g, v) && !isdead(g, o));
	lua_assert(g->gcstate != GCSfinalize && g->gcstate != GCSpause);
	lua_assert(ttype(&o->gch) != LUA_TTABLE);
	/* must keep invariant? */
	if (g->gcstate == GCSpropagate)
		reallymarkobject(g, v);  /* restore invariant */
	else  /* don't mind */
		makewhite(g, o);  /* mark as white just to avoid other barriers */
}

void luaC_link(lua_State* L, GCObject* o, lu_byte tt) {
	global_State* g = G(L);
	o->gch.next = g->rootgc;
	g->rootgc = o;
	o->gch.marked = luaC_white(g);
	o->gch.tt = tt;
}

void luaC_barrierback(lua_State* L, Table* t) {
	global_State* g = G(L);
	GCObject* o = obj2gco(t);
	lua_assert(isblack(o) && !isdead(g, o));
	lua_assert(g->gcstate != GCSfinalize && g->gcstate != GCSpause);
	black2gray(o);  /* make table gray (again) */
	t->gclist = g->grayagain;
	g->grayagain = o;
}

#pragma endregion

#pragma region lmem_c

void* luaM_toobig(lua_State* L) {
	//luaG_runerror(L, "memory allocation error: block too big");
	exit(EXIT_FAILURE);
	return NULL;  /* to avoid warnings */
}

/*
** generic allocation routine.
*/
void* luaM_realloc_(lua_State* L, void* block, size_t osize, size_t nsize) {
	global_State* g = G(L);
	lua_assert((osize == 0) == (block == NULL));
	block = (*g->frealloc)(g->ud, block, osize, nsize);
	if (block == NULL && nsize > 0)
		//luaD_throw(L, LUA_ERRMEM);
		exit(EXIT_FAILURE);
	lua_assert((nsize == 0) == (block == NULL));
	g->totalbytes = (g->totalbytes - osize) + nsize;
	return block;
}

#pragma endregion

#pragma region lstring_c

static TString* newlstr(lua_State* L, const char* str, size_t l,
	unsigned int h) {
	TString* ts;
	stringtable* tb;
	if (l + 1 > (MAX_SIZET - sizeof(TString)) / sizeof(char))
		luaM_toobig(L);
	ts = cast(TString*, luaM_malloc(L, (l + 1) * sizeof(char) + sizeof(TString)));
	ts->tsv.len = l;
	ts->tsv.hash = h;
	ts->tsv.marked = luaC_white(G(L));
	ts->tsv.tt = LUA_TSTRING;
	ts->tsv.reserved = 0;
	memcpy(ts + 1, str, l * sizeof(char));
	((char*)(ts + 1))[l] = '\0';  /* ending 0 */
	tb = &G(L)->strt;
	h = lmod(h, tb->size);
	ts->tsv.next = tb->hash[h];  /* chain new entry */
	tb->hash[h] = obj2gco(ts);
	tb->nuse++;
	if (tb->nuse > cast(lu_int32, tb->size) && tb->size <= MAX_INT / 2)
		luaS_resize(L, tb->size * 2);  /* too crowded */
	return ts;
}

TString* luaS_newlstr(lua_State* L, const char* str, size_t l) {
	GCObject* o;
	unsigned int h = cast(unsigned int, l);  /* seed */
	size_t step = (l >> 5) + 1;  /* if string is too long, don't hash all its chars */
	size_t l1;
	for (l1 = l; l1 >= step; l1 -= step)  /* compute hash */
		h = h ^ ((h << 5) + (h >> 2) + cast(unsigned char, str[l1 - 1]));
	for (o = G(L)->strt.hash[lmod(h, G(L)->strt.size)];
		o != NULL;
		o = o->gch.next) {
		TString* ts = rawgco2ts(o);
		if (ts->tsv.len == l && (memcmp(str, getstr(ts), l) == 0)) {
			/* string may be dead */
			if (isdead(G(L), o)) changewhite(o);
			return ts;
		}
	}
	return newlstr(L, str, l, h);  /* not found */
}

void luaS_resize(lua_State* L, int newsize) {
	GCObject** newhash;
	stringtable* tb;
	int i;
	if (G(L)->gcstate == GCSsweepstring)
		return;  /* cannot resize during GC traverse */
	newhash = luaM_newvector(L, newsize, GCObject*);
	tb = &G(L)->strt;
	for (i = 0; i < newsize; i++) newhash[i] = NULL;
	/* rehash */
	for (i = 0; i < tb->size; i++) {
		GCObject* p = tb->hash[i];
		while (p) {  /* for each node in the list */
			GCObject* next = p->gch.next;  /* save next */
			unsigned int h = gco2ts(p)->hash;
			int h1 = lmod(h, newsize);  /* new position */
			lua_assert(cast_int(h % newsize) == lmod(h, newsize));
			p->gch.next = newhash[h1];  /* chain it */
			newhash[h1] = p;
			p = next;
		}
	}
	luaM_freearray(L, tb->hash, tb->size, TString*);
	tb->size = newsize;
	tb->hash = newhash;
}

#pragma endregion

#pragma region lapi_c

/*
** access functions (stack -> C)
*/

static TValue* index2adr(lua_State* L, int idx) {
	if (idx > 0) {
		TValue* o = L->base + (idx - 1);
		api_check(L, idx <= L->ci->top - L->base);
		if (o >= L->top) return cast(TValue*, luaO_nilobject);
		else return o;
	}
	else if (idx > LUA_REGISTRYINDEX) {
		api_check(L, idx != 0 && -idx <= L->top - L->base);
		return L->top + idx;
	}
	else switch (idx) {  /* pseudo-indices */
	case LUA_REGISTRYINDEX: return registry(L);
	case LUA_ENVIRONINDEX: {
		Closure* func = curr_func(L);
		sethvalue(L, &L->env, func->c.env);
		return &L->env;
	}
	case LUA_GLOBALSINDEX: return gt(L);
	default: {
		Closure* func = curr_func(L);
		idx = LUA_GLOBALSINDEX - idx;
		return (idx <= func->c.nupvalues)
			? &func->c.upvalue[idx - 1]
			: cast(TValue*, luaO_nilobject);
	}
	}
}

LUA_API int lua_type(lua_State* L, int idx) {
	StkId o = index2adr(L, idx);
	return (o == luaO_nilobject) ? LUA_TNONE : ttype(o);
}

LUA_API int lua_toboolean(lua_State* L, int idx) {
	const TValue* o = index2adr(L, idx);
	return !l_isfalse(o);
}

LUA_API int lua_isstring(lua_State* L, int idx) {
	int t = lua_type(L, idx);
	return (t == LUA_TSTRING || t == LUA_TNUMBER);
}

int luaV_tostring(lua_State* L, StkId obj) {
	if (!ttisnumber(obj))
		return 0;
	else {
		char s[LUAI_MAXNUMBER2STR];
		lua_Number n = nvalue(obj);
		lua_number2str(s, n);
		setsvalue2s(L, obj, luaS_new(L, s));
		return 1;
	}
}

LUA_API const char* lua_tolstring(lua_State* L, int idx, size_t* len) {
	StkId o = index2adr(L, idx);
	if (!ttisstring(o)) {
		lua_lock(L);  /* `luaV_tostring' may create a new string */
		if (!luaV_tostring(L, o)) {  /* conversion failed? */
			if (len != NULL) *len = 0;
			lua_unlock(L);
			return NULL;
		}
		luaC_checkGC(L);
		o = index2adr(L, idx);  /* previous call may reallocate the stack */
		lua_unlock(L);
	}
	if (len != NULL) *len = tsvalue(o)->len;
	return svalue(o);
}

#pragma endregion

#pragma region lvm_c

static void traceexec(lua_State* L, const Instruction* pc) {
	lu_byte mask = L->hookmask;
	const Instruction* oldpc = L->savedpc;
	L->savedpc = pc;
	if ((mask & LUA_MASKCOUNT) && L->hookcount == 0) {
		resethookcount(L);
		luaD_callhook(L, LUA_HOOKCOUNT, -1);
	}
	if (mask & LUA_MASKLINE) {
		Proto* p = ci_func(L->ci)->l.p;
		int npc = pcRel(pc, p);
		int newline = getline(p, npc);
		/* call linehook when enter a new function, when jump back (loop),
		   or when enter a new line */
		if (npc == 0 || pc <= oldpc || newline != getline(p, pcRel(oldpc, p)))
			luaD_callhook(L, LUA_HOOKLINE, newline);
	}
}

#define runtime_check(L, c)	{ if (!(c)) break; }

#define RA(i)	(base+GETARG_A(i))
/* to be used after possible stack reallocation */
#define RB(i)	check_exp(getBMode(GET_OPCODE(i)) == OpArgR, base+GETARG_B(i))
#define RC(i)	check_exp(getCMode(GET_OPCODE(i)) == OpArgR, base+GETARG_C(i))
#define RKB(i)	check_exp(getBMode(GET_OPCODE(i)) == OpArgK, \
	ISK(GETARG_B(i)) ? k+INDEXK(GETARG_B(i)) : base+GETARG_B(i))
#define RKC(i)	check_exp(getCMode(GET_OPCODE(i)) == OpArgK, \
	ISK(GETARG_C(i)) ? k+INDEXK(GETARG_C(i)) : base+GETARG_C(i))
#define KBx(i)	check_exp(getBMode(GET_OPCODE(i)) == OpArgK, k+GETARG_Bx(i))

#define dojump(L,pc,i)	{(pc) += (i); luai_threadyield(L);}


#define Protect(x)	{ L->savedpc = pc; {x;}; base = L->base; }


#define arith_op(op,tm) { \
        TValue *rb = RKB(i); \
        TValue *rc = RKC(i); \
        if (ttisnumber(rb) && ttisnumber(rc)) { \
          lua_Number nb = nvalue(rb), nc = nvalue(rc); \
          setnvalue(ra, op(nb, nc)); \
        } \
        else \
          Protect(luaV_arith(L, ra, rb, rc, tm)); \
      }

static void callTMres(lua_State* L, StkId res, const TValue* f,
	const TValue* p1, const TValue* p2) {
	ptrdiff_t result = savestack(L, res);
	setobj2s(L, L->top, f);  /* push function */
	setobj2s(L, L->top + 1, p1);  /* 1st argument */
	setobj2s(L, L->top + 2, p2);  /* 2nd argument */
	luaD_checkstack(L, 3);
	L->top += 3;
	luaD_call(L, L->top - 3, 1);
	res = restorestack(L, result);
	L->top--;
	setobjs2s(L, res, L->top);
}

static int call_binTM(lua_State* L, const TValue* p1, const TValue* p2,
	StkId res, TMS event) {
	const TValue* tm = luaT_gettmbyobj(L, p1, event);  /* try first operand */
	if (ttisnil(tm))
		tm = luaT_gettmbyobj(L, p2, event);  /* try second operand */
	if (ttisnil(tm)) return 0;
	callTMres(L, res, tm, p1, p2);
	return 1;
}

void luaV_execute(lua_State* L, int nexeccalls) {
	LClosure* cl;
	StkId base;
	TValue* k;
	const Instruction* pc;
reentry:  /* entry point */
	lua_assert(isLua(L->ci));
	pc = L->savedpc;
	cl = &clvalue(L->ci->func)->l;
	base = L->base;
	k = cl->p->k;
	/* main loop of interpreter */
	for (;;) {
		const Instruction i = *pc++;
		StkId ra;
		if ((L->hookmask & (LUA_MASKLINE | LUA_MASKCOUNT)) &&
			(--L->hookcount == 0 || L->hookmask & LUA_MASKLINE)) {
			traceexec(L, pc);
			if (L->status == LUA_YIELD) {  /* did hook yield? */
				L->savedpc = pc - 1;
				return;
			}
			base = L->base;
		}
		/* warning!! several calls may realloc the stack and invalidate `ra' */
		ra = RA(i);
		lua_assert(base == L->base && L->base == L->ci->base);
		lua_assert(base <= L->top && L->top <= L->stack + L->stacksize);
		lua_assert(L->top == L->ci->top || luaG_checkopenop(i));
		switch (GET_OPCODE(i)) {
		case OP_MOVE: {
			setobjs2s(L, ra, RB(i));
			continue;
		}
		case OP_LOADK: {
			setobj2s(L, ra, KBx(i));
			continue;
		}
		case OP_LOADBOOL: {
			setbvalue(ra, GETARG_B(i));
			if (GETARG_C(i)) pc++;  /* skip next instruction (if C) */
			continue;
		}
		case OP_LOADNIL: {
			TValue* rb = RB(i);
			do {
				setnilvalue(rb--);
			} while (rb >= ra);
			continue;
		}
		case OP_GETUPVAL: {
			int b = GETARG_B(i);
			setobj2s(L, ra, cl->upvals[b]->v);
			continue;
		}
		case OP_GETGLOBAL: {
			TValue g;
			TValue* rb = KBx(i);
			sethvalue(L, &g, cl->env);
			lua_assert(ttisstring(rb));
			Protect(luaV_gettable(L, &g, rb, ra));
			continue;
		}
		case OP_GETTABLE: {
			Protect(luaV_gettable(L, RB(i), RKC(i), ra));
			continue;
		}
		case OP_SETGLOBAL: {
			TValue g;
			sethvalue(L, &g, cl->env);
			lua_assert(ttisstring(KBx(i)));
			Protect(luaV_settable(L, &g, KBx(i), ra));
			continue;
		}
		case OP_SETUPVAL: {
			UpVal* uv = cl->upvals[GETARG_B(i)];
			setobj(L, uv->v, ra);
			luaC_barrier(L, uv, ra);
			continue;
		}
		case OP_SETTABLE: {
			Protect(luaV_settable(L, ra, RKB(i), RKC(i)));
			continue;
		}
		case OP_NEWTABLE: {
			int b = GETARG_B(i);
			int c = GETARG_C(i);
			sethvalue(L, ra, luaH_new(L, luaO_fb2int(b), luaO_fb2int(c)));
			Protect(luaC_checkGC(L));
			continue;
		}
		case OP_SELF: {
			StkId rb = RB(i);
			setobjs2s(L, ra + 1, rb);
			Protect(luaV_gettable(L, rb, RKC(i), ra));
			continue;
		}
		case OP_ADD: {
			arith_op(luai_numadd, TM_ADD);
			continue;
		}
		case OP_SUB: {
			arith_op(luai_numsub, TM_SUB);
			continue;
		}
		case OP_MUL: {
			arith_op(luai_nummul, TM_MUL);
			continue;
		}
		case OP_DIV: {
			arith_op(luai_numdiv, TM_DIV);
			continue;
		}
		case OP_MOD: {
			arith_op(luai_nummod, TM_MOD);
			continue;
		}
		case OP_POW: {
			arith_op(luai_numpow, TM_POW);
			continue;
		}
		case OP_UNM: {
			TValue* rb = RB(i);
			if (ttisnumber(rb)) {
				lua_Number nb = nvalue(rb);
				setnvalue(ra, luai_numunm(nb));
			}
			else {
				Protect(luaV_arith(L, ra, rb, rb, TM_UNM));
			}
			continue;
		}
		case OP_NOT: {
			int res = l_isfalse(RB(i));  /* next assignment may change this value */
			setbvalue(ra, res);
			continue;
		}
		case OP_LEN: {
			const TValue* rb = RB(i);
			switch (ttype(rb)) {
			case LUA_TTABLE: {
				setnvalue(ra, cast_num(luaH_getn(hvalue(rb))));
				break;
			}
			case LUA_TSTRING: {
				setnvalue(ra, cast_num(tsvalue(rb)->len));
				break;
			}
			default: {  /* try metamethod */
				Protect(
					if (!call_binTM(L, rb, luaO_nilobject, ra, TM_LEN))
						luaG_typeerror(L, rb, "get length of");
				)
			}
			}
			continue;
		}
		case OP_CONCAT: {
			int b = GETARG_B(i);
			int c = GETARG_C(i);
			Protect(luaV_concat(L, c - b + 1, c); luaC_checkGC(L));
			setobjs2s(L, RA(i), base + b);
			continue;
		}
		case OP_JMP: {
			dojump(L, pc, GETARG_sBx(i));
			continue;
		}
		case OP_EQ: {
			TValue* rb = RKB(i);
			TValue* rc = RKC(i);
			Protect(
				if (equalobj(L, rb, rc) == GETARG_A(i))
					dojump(L, pc, GETARG_sBx(*pc));
			)
				pc++;
			continue;
		}
		case OP_LT: {
			Protect(
				if (luaV_lessthan(L, RKB(i), RKC(i)) == GETARG_A(i))
					dojump(L, pc, GETARG_sBx(*pc));
			)
				pc++;
			continue;
		}
		case OP_LE: {
			Protect(
				if (luaV_lessequal(L, RKB(i), RKC(i)) == GETARG_A(i))
					dojump(L, pc, GETARG_sBx(*pc));
			)
				pc++;
			continue;
		}
		case OP_TEST: {
			if (l_isfalse(ra) != GETARG_C(i))
				dojump(L, pc, GETARG_sBx(*pc));
			pc++;
			continue;
		}
		case OP_TESTSET: {
			TValue* rb = RB(i);
			if (l_isfalse(rb) != GETARG_C(i)) {
				setobjs2s(L, ra, rb);
				dojump(L, pc, GETARG_sBx(*pc));
			}
			pc++;
			continue;
		}
		case OP_CALL: {
			int b = GETARG_B(i);
			int nresults = GETARG_C(i) - 1;
			if (b != 0) L->top = ra + b;  /* else previous instruction set top */
			L->savedpc = pc;
			switch (luaD_precall(L, ra, nresults)) {
			case PCRLUA: {
				nexeccalls++;
				goto reentry;  /* restart luaV_execute over new Lua function */
			}
			case PCRC: {
				/* it was a C function (`precall' called it); adjust results */
				if (nresults >= 0) L->top = L->ci->top;
				base = L->base;
				continue;
			}
			default: {
				return;  /* yield */
			}
			}
		}
		case OP_TAILCALL: {
			int b = GETARG_B(i);
			if (b != 0) L->top = ra + b;  /* else previous instruction set top */
			L->savedpc = pc;
			lua_assert(GETARG_C(i) - 1 == LUA_MULTRET);
			switch (luaD_precall(L, ra, LUA_MULTRET)) {
			case PCRLUA: {
				/* tail call: put new frame in place of previous one */
				CallInfo* ci = L->ci - 1;  /* previous frame */
				int aux;
				StkId func = ci->func;
				StkId pfunc = (ci + 1)->func;  /* previous function index */
				if (L->openupval) luaF_close(L, ci->base);
				L->base = ci->base = ci->func + ((ci + 1)->base - pfunc);
				for (aux = 0; pfunc + aux < L->top; aux++)  /* move frame down */
					setobjs2s(L, func + aux, pfunc + aux);
				ci->top = L->top = func + aux;  /* correct top */
				lua_assert(L->top == L->base + clvalue(func)->l.p->maxstacksize);
				ci->savedpc = L->savedpc;
				ci->tailcalls++;  /* one more call lost */
				L->ci--;  /* remove new frame */
				goto reentry;
			}
			case PCRC: {  /* it was a C function (`precall' called it) */
				base = L->base;
				continue;
			}
			default: {
				return;  /* yield */
			}
			}
		}
		case OP_RETURN: {
			int b = GETARG_B(i);
			if (b != 0) L->top = ra + b - 1;
			if (L->openupval) luaF_close(L, base);
			L->savedpc = pc;
			b = luaD_poscall(L, ra);
			if (--nexeccalls == 0)  /* was previous function running `here'? */
				return;  /* no: return */
			else {  /* yes: continue its execution */
				if (b) L->top = L->ci->top;
				lua_assert(isLua(L->ci));
				lua_assert(GET_OPCODE(*((L->ci)->savedpc - 1)) == OP_CALL);
				goto reentry;
			}
		}
		case OP_FORLOOP: {
			lua_Number step = nvalue(ra + 2);
			lua_Number idx = luai_numadd(nvalue(ra), step); /* increment index */
			lua_Number limit = nvalue(ra + 1);
			if (luai_numlt(0, step) ? luai_numle(idx, limit)
				: luai_numle(limit, idx)) {
				dojump(L, pc, GETARG_sBx(i));  /* jump back */
				setnvalue(ra, idx);  /* update internal index... */
				setnvalue(ra + 3, idx);  /* ...and external index */
			}
			continue;
		}
		case OP_FORPREP: {
			const TValue* init = ra;
			const TValue* plimit = ra + 1;
			const TValue* pstep = ra + 2;
			L->savedpc = pc;  /* next steps may throw errors */
			if (!tonumber(init, ra))
				luaG_runerror(L, LUA_QL("for") " initial value must be a number");
			else if (!tonumber(plimit, ra + 1))
				luaG_runerror(L, LUA_QL("for") " limit must be a number");
			else if (!tonumber(pstep, ra + 2))
				luaG_runerror(L, LUA_QL("for") " step must be a number");
			setnvalue(ra, luai_numsub(nvalue(ra), nvalue(pstep)));
			dojump(L, pc, GETARG_sBx(i));
			continue;
		}
		case OP_TFORLOOP: {
			StkId cb = ra + 3;  /* call base */
			setobjs2s(L, cb + 2, ra + 2);
			setobjs2s(L, cb + 1, ra + 1);
			setobjs2s(L, cb, ra);
			L->top = cb + 3;  /* func. + 2 args (state and index) */
			Protect(luaD_call(L, cb, GETARG_C(i)));
			L->top = L->ci->top;
			cb = RA(i) + 3;  /* previous call may change the stack */
			if (!ttisnil(cb)) {  /* continue loop? */
				setobjs2s(L, cb - 1, cb);  /* save control variable */
				dojump(L, pc, GETARG_sBx(*pc));  /* jump back */
			}
			pc++;
			continue;
		}
		case OP_SETLIST: {
			int n = GETARG_B(i);
			int c = GETARG_C(i);
			int last;
			Table* h;
			if (n == 0) {
				n = cast_int(L->top - ra) - 1;
				L->top = L->ci->top;
			}
			if (c == 0) c = cast_int(*pc++);
			runtime_check(L, ttistable(ra));
			h = hvalue(ra);
			last = ((c - 1) * LFIELDS_PER_FLUSH) + n;
			if (last > h->sizearray)  /* needs more space? */
				luaH_resizearray(L, h, last);  /* pre-alloc it at once */
			for (; n > 0; n--) {
				TValue* val = ra + n;
				setobj2t(L, luaH_setnum(L, h, last--), val);
				luaC_barriert(L, h, val);
			}
			continue;
		}
		case OP_CLOSE: {
			luaF_close(L, ra);
			continue;
		}
		case OP_CLOSURE: {
			Proto* p;
			Closure* ncl;
			int nup, j;
			p = cl->p->p[GETARG_Bx(i)];
			nup = p->nups;
			ncl = luaF_newLclosure(L, nup, cl->env);
			ncl->l.p = p;
			for (j = 0; j < nup; j++, pc++) {
				if (GET_OPCODE(*pc) == OP_GETUPVAL)
					ncl->l.upvals[j] = cl->upvals[GETARG_B(*pc)];
				else {
					lua_assert(GET_OPCODE(*pc) == OP_MOVE);
					ncl->l.upvals[j] = luaF_findupval(L, base + GETARG_B(*pc));
				}
			}
			setclvalue(L, ra, ncl);
			Protect(luaC_checkGC(L));
			continue;
		}
		case OP_VARARG: {
			int b = GETARG_B(i) - 1;
			int j;
			CallInfo* ci = L->ci;
			int n = cast_int(ci->base - ci->func) - cl->p->numparams - 1;
			if (b == LUA_MULTRET) {
				Protect(luaD_checkstack(L, n));
				ra = RA(i);  /* previous call may change the stack */
				b = n;
				L->top = ra + n;
			}
			for (j = 0; j < b; j++) {
				if (j < n) {
					setobjs2s(L, ra + j, ci->base - n + j);
				}
				else {
					setnilvalue(ra + j);
				}
			}
			continue;
		}
		}
	}
}

static int l_strcmp(const TString* ls, const TString* rs) {
	const char* l = getstr(ls);
	size_t ll = ls->tsv.len;
	const char* r = getstr(rs);
	size_t lr = rs->tsv.len;
	for (;;) {
		int temp = strcoll(l, r);
		if (temp != 0) return temp;
		else {  /* strings are equal up to a `\0' */
			size_t len = strlen(l);  /* index of first `\0' in both strings */
			if (len == lr)  /* r is finished? */
				return (len == ll) ? 0 : 1;
			else if (len == ll)  /* l is finished? */
				return -1;  /* l is smaller than r (because r is not finished) */
			  /* both strings longer than `len'; go on comparing (after the `\0') */
			len++;
			l += len; ll -= len; r += len; lr -= len;
		}
	}
}

static int call_orderTM(lua_State* L, const TValue* p1, const TValue* p2,
	TMS event) {
	const TValue* tm1 = luaT_gettmbyobj(L, p1, event);
	const TValue* tm2;
	if (ttisnil(tm1)) return -1;  /* no metamethod? */
	tm2 = luaT_gettmbyobj(L, p2, event);
	if (!luaO_rawequalObj(tm1, tm2))  /* different metamethods? */
		return -1;
	callTMres(L, L->top, tm1, p1, p2);
	return !l_isfalse(L->top);
}

int luaV_lessthan(lua_State* L, const TValue* l, const TValue* r) {
	int res;
	if (ttype(l) != ttype(r))
		return luaG_ordererror(L, l, r);
	else if (ttisnumber(l))
		return luai_numlt(nvalue(l), nvalue(r));
	else if (ttisstring(l))
		return l_strcmp(rawtsvalue(l), rawtsvalue(r)) < 0;
	else if ((res = call_orderTM(L, l, r, TM_LT)) != -1)
		return res;
	return luaG_ordererror(L, l, r);
}

int luaV_lessequal(lua_State* L, const TValue* l, const TValue* r) {
	int res;
	if (ttype(l) != ttype(r))
		return luaG_ordererror(L, l, r);
	else if (ttisnumber(l))
		return luai_numle(nvalue(l), nvalue(r));
	else if (ttisstring(l))
		return l_strcmp(rawtsvalue(l), rawtsvalue(r)) <= 0;
	else if ((res = call_orderTM(L, l, r, TM_LE)) != -1)  /* first try `le' */
		return res;
	else if ((res = call_orderTM(L, r, l, TM_LT)) != -1)  /* else try `lt' */
		return !res;
	return luaG_ordererror(L, l, r);
}

static const TValue* get_compTM(lua_State* L, Table* mt1, Table* mt2,
	TMS event) {
	const TValue* tm1 = fasttm(L, mt1, event);
	const TValue* tm2;
	if (tm1 == NULL) return NULL;  /* no metamethod */
	if (mt1 == mt2) return tm1;  /* same metatables => same metamethods */
	tm2 = fasttm(L, mt2, event);
	if (tm2 == NULL) return NULL;  /* no metamethod */
	if (luaO_rawequalObj(tm1, tm2))  /* same metamethods? */
		return tm1;
	return NULL;
}

int luaV_equalval(lua_State* L, const TValue* t1, const TValue* t2) {
	const TValue* tm;
	lua_assert(ttype(t1) == ttype(t2));
	switch (ttype(t1)) {
	case LUA_TNIL: return 1;
	case LUA_TNUMBER: return luai_numeq(nvalue(t1), nvalue(t2));
	case LUA_TBOOLEAN: return bvalue(t1) == bvalue(t2);  /* true must be 1 !! */
	case LUA_TLIGHTUSERDATA: return pvalue(t1) == pvalue(t2);
	case LUA_TUSERDATA: {
		if (uvalue(t1) == uvalue(t2)) return 1;
		tm = get_compTM(L, uvalue(t1)->metatable, uvalue(t2)->metatable,
			TM_EQ);
		break;  /* will try TM */
	}
	case LUA_TTABLE: {
		if (hvalue(t1) == hvalue(t2)) return 1;
		tm = get_compTM(L, hvalue(t1)->metatable, hvalue(t2)->metatable, TM_EQ);
		break;  /* will try TM */
	}
	default: return gcvalue(t1) == gcvalue(t2);
	}
	if (tm == NULL) return 0;  /* no TM? */
	callTMres(L, L->top, tm, t1, t2);  /* call TM */
	return !l_isfalse(L->top);
}

const TValue* luaV_tonumber(const TValue* obj, TValue* n) {
	lua_Number num;
	if (ttisnumber(obj)) return obj;
	if (ttisstring(obj) && luaO_str2d(svalue(obj), &num)) {
		setnvalue(n, num);
		return n;
	}
	else
		return NULL;
}

int luaO_str2d(const char* s, lua_Number* result) {
	char* endptr;
	*result = lua_str2number(s, &endptr);
	if (endptr == s) return 0;  /* conversion failed */
	if (*endptr == 'x' || *endptr == 'X')  /* maybe an hexadecimal constant? */
		*result = cast_num(strtoul(s, &endptr, 16));
	if (*endptr == '\0') return 1;  /* most common case */
	while (isspace(cast(unsigned char, *endptr))) endptr++;
	if (*endptr != '\0') return 0;  /* invalid trailing characters? */
	return 1;
}

/* limit for table tag-method chains (to avoid loops) */
#define MAXTAGLOOP	100

void luaV_gettable(lua_State* L, const TValue* t, TValue* key, StkId val) {
	int loop;
	for (loop = 0; loop < MAXTAGLOOP; loop++) {
		const TValue* tm;
		if (ttistable(t)) {  /* `t' is a table? */
			Table* h = hvalue(t);
			const TValue* res = luaH_get(h, key); /* do a primitive get */
			if (!ttisnil(res) ||  /* result is no nil? */
				(tm = fasttm(L, h->metatable, TM_INDEX)) == NULL) { /* or no TM? */
				setobj2s(L, val, res);
				return;
			}
			/* else will try the tag method */
		}
		else if (ttisnil(tm = luaT_gettmbyobj(L, t, TM_INDEX)))
			luaG_typeerror(L, t, "index");
		if (ttisfunction(tm)) {
			callTMres(L, val, tm, t, key);
			return;
		}
		t = tm;  /* else repeat with `tm' */
	}
	luaG_runerror(L, "loop in gettable");
}

static void callTM(lua_State* L, const TValue* f, const TValue* p1,
	const TValue* p2, const TValue* p3) {
	setobj2s(L, L->top, f);  /* push function */
	setobj2s(L, L->top + 1, p1);  /* 1st argument */
	setobj2s(L, L->top + 2, p2);  /* 2nd argument */
	setobj2s(L, L->top + 3, p3);  /* 3th argument */
	luaD_checkstack(L, 4);
	L->top += 4;
	luaD_call(L, L->top - 4, 0);
}

void luaV_settable(lua_State* L, const TValue* t, TValue* key, StkId val) {
	int loop;
	for (loop = 0; loop < MAXTAGLOOP; loop++) {
		const TValue* tm;
		if (ttistable(t)) {  /* `t' is a table? */
			Table* h = hvalue(t);
			TValue* oldval = luaH_set(L, h, key); /* do a primitive set */
			if (!ttisnil(oldval) ||  /* result is no nil? */
				(tm = fasttm(L, h->metatable, TM_NEWINDEX)) == NULL) { /* or no TM? */
				setobj2t(L, oldval, val);
				luaC_barriert(L, h, val);
				return;
			}
			/* else will try the tag method */
		}
		else if (ttisnil(tm = luaT_gettmbyobj(L, t, TM_NEWINDEX)))
			luaG_typeerror(L, t, "index");
		if (ttisfunction(tm)) {
			callTM(L, tm, t, key, val);
			return;
		}
		t = tm;  /* else repeat with `tm' */
	}
	luaG_runerror(L, "loop in settable");
}

void luaV_arith(lua_State* L, StkId ra, const TValue* rb,
	const TValue* rc, TMS op) {
	TValue tempb, tempc;
	const TValue* b, * c;
	if ((b = luaV_tonumber(rb, &tempb)) != NULL &&
		(c = luaV_tonumber(rc, &tempc)) != NULL) {
		lua_Number nb = nvalue(b), nc = nvalue(c);
		switch (op) {
		case TM_ADD: setnvalue(ra, luai_numadd(nb, nc)); break;
		case TM_SUB: setnvalue(ra, luai_numsub(nb, nc)); break;
		case TM_MUL: setnvalue(ra, luai_nummul(nb, nc)); break;
		case TM_DIV: setnvalue(ra, luai_numdiv(nb, nc)); break;
		case TM_MOD: setnvalue(ra, luai_nummod(nb, nc)); break;
		case TM_POW: setnvalue(ra, luai_numpow(nb, nc)); break;
		case TM_UNM: setnvalue(ra, luai_numunm(nb)); break;
		default: lua_assert(0); break;
		}
	}
	else if (!call_binTM(L, rb, rc, ra, op))
		luaG_aritherror(L, rb, rc);
}

void luaV_concat(lua_State* L, int total, int last) {
	do {
		StkId top = L->base + last + 1;
		int n = 2;  /* number of elements handled in this pass (at least 2) */
		if (!(ttisstring(top - 2) || ttisnumber(top - 2)) || !tostring(L, top - 1)) {
			if (!call_binTM(L, top - 2, top - 1, top - 2, TM_CONCAT))
				luaG_concaterror(L, top - 2, top - 1);
		}
		else if (tsvalue(top - 1)->len == 0)  /* second op is empty? */
			(void)tostring(L, top - 2);  /* result is first op (as string) */
		else {
			/* at least two string values; get as many as possible */
			size_t tl = tsvalue(top - 1)->len;
			char* buffer;
			int i;
			/* collect total length */
			for (n = 1; n < total && tostring(L, top - n - 1); n++) {
				size_t l = tsvalue(top - n - 1)->len;
				if (l >= MAX_SIZET - tl) luaG_runerror(L, "string length overflow");
				tl += l;
			}
			buffer = luaZ_openspace(L, &G(L)->buff, tl);
			tl = 0;
			for (i = n; i > 0; i--) {  /* concat all strings */
				size_t l = tsvalue(top - i)->len;
				memcpy(buffer + tl, svalue(top - i), l);
				tl += l;
			}
			setsvalue2s(L, top - n, luaS_newlstr(L, buffer, tl));
		}
		total -= n - 1;  /* got `n' strings to create 1 new */
		last -= n - 1;
	} while (total > 1);  /* repeat until only 1 result left */
}

#pragma endregion

#pragma region lzio_c

char* luaZ_openspace(lua_State* L, Mbuffer* buff, size_t n) {
	if (n > buff->buffsize) {
		if (n < LUA_MINBUFFER) n = LUA_MINBUFFER;
		luaZ_resizebuffer(L, buff, n);
	}
	return buff->buffer;
}

#pragma endregion

#pragma region opmodes_c

#define opmode(t,a,b,c,m) (((t)<<7) | ((a)<<6) | ((b)<<4) | ((c)<<2) | (m))

const lu_byte luaP_opmodes[NUM_OPCODES] = {
	/*       T  A    B       C     mode		   opcode	*/
	  opmode(0, 1, OpArgR, OpArgN, iABC) 		/* OP_MOVE */
	 ,opmode(0, 1, OpArgK, OpArgN, iABx)		/* OP_LOADK */
	 ,opmode(0, 1, OpArgU, OpArgU, iABC)		/* OP_LOADBOOL */
	 ,opmode(0, 1, OpArgR, OpArgN, iABC)		/* OP_LOADNIL */
	 ,opmode(0, 1, OpArgU, OpArgN, iABC)		/* OP_GETUPVAL */
	 ,opmode(0, 1, OpArgK, OpArgN, iABx)		/* OP_GETGLOBAL */
	 ,opmode(0, 1, OpArgR, OpArgK, iABC)		/* OP_GETTABLE */
	 ,opmode(0, 0, OpArgK, OpArgN, iABx)		/* OP_SETGLOBAL */
	 ,opmode(0, 0, OpArgU, OpArgN, iABC)		/* OP_SETUPVAL */
	 ,opmode(0, 0, OpArgK, OpArgK, iABC)		/* OP_SETTABLE */
	 ,opmode(0, 1, OpArgU, OpArgU, iABC)		/* OP_NEWTABLE */
	 ,opmode(0, 1, OpArgR, OpArgK, iABC)		/* OP_SELF */
	 ,opmode(0, 1, OpArgK, OpArgK, iABC)		/* OP_ADD */
	 ,opmode(0, 1, OpArgK, OpArgK, iABC)		/* OP_SUB */
	 ,opmode(0, 1, OpArgK, OpArgK, iABC)		/* OP_MUL */
	 ,opmode(0, 1, OpArgK, OpArgK, iABC)		/* OP_DIV */
	 ,opmode(0, 1, OpArgK, OpArgK, iABC)		/* OP_MOD */
	 ,opmode(0, 1, OpArgK, OpArgK, iABC)		/* OP_POW */
	 ,opmode(0, 1, OpArgR, OpArgN, iABC)		/* OP_UNM */
	 ,opmode(0, 1, OpArgR, OpArgN, iABC)		/* OP_NOT */
	 ,opmode(0, 1, OpArgR, OpArgN, iABC)		/* OP_LEN */
	 ,opmode(0, 1, OpArgR, OpArgR, iABC)		/* OP_CONCAT */
	 ,opmode(0, 0, OpArgR, OpArgN, iAsBx)		/* OP_JMP */
	 ,opmode(1, 0, OpArgK, OpArgK, iABC)		/* OP_EQ */
	 ,opmode(1, 0, OpArgK, OpArgK, iABC)		/* OP_LT */
	 ,opmode(1, 0, OpArgK, OpArgK, iABC)		/* OP_LE */
	 ,opmode(1, 1, OpArgR, OpArgU, iABC)		/* OP_TEST */
	 ,opmode(1, 1, OpArgR, OpArgU, iABC)		/* OP_TESTSET */
	 ,opmode(0, 1, OpArgU, OpArgU, iABC)		/* OP_CALL */
	 ,opmode(0, 1, OpArgU, OpArgU, iABC)		/* OP_TAILCALL */
	 ,opmode(0, 0, OpArgU, OpArgN, iABC)		/* OP_RETURN */
	 ,opmode(0, 1, OpArgR, OpArgN, iAsBx)		/* OP_FORLOOP */
	 ,opmode(0, 1, OpArgR, OpArgN, iAsBx)		/* OP_FORPREP */
	 ,opmode(1, 0, OpArgN, OpArgU, iABC)		/* OP_TFORLOOP */
	 ,opmode(0, 0, OpArgU, OpArgU, iABC)		/* OP_SETLIST */
	 ,opmode(0, 0, OpArgN, OpArgN, iABC)		/* OP_CLOSE */
	 ,opmode(0, 1, OpArgU, OpArgN, iABx)		/* OP_CLOSURE */
	 ,opmode(0, 1, OpArgU, OpArgN, iABC)		/* OP_VARARG */
};

#pragma endregion

bool WrapperXLua::lua_isbooleanW(void* state, int idx)
{
	return lua_isboolean((lua_State*)state, idx);
}

bool WrapperXLua::lua_isstringW(void* state, int idx)
{
	return lua_isstring((lua_State*)state, idx);
}

bool WrapperXLua::lua_tobooleanW(void* state, int idx)
{
	return lua_toboolean((lua_State*)state, idx) == 1;
}

std::string WrapperXLua::lua_tostringW(void* state, int idx)
{
	return lua_tostring((lua_State*)state, idx);
}
