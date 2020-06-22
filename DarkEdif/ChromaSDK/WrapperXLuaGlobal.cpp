#include "WrapperXLuaGlobal.h"

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <hash_map>
#include "lua.hpp"
#include "XLuaGlobal.h"

void* WrapperXLuaGlobal::GetState(int sid)
{
	XLuaGlobal& luaGlobal = XLuaGlobal::Get();
	return luaGlobal.GetState(sid);
}

bool WrapperXLuaGlobal::CreateState(int sid)
{
	XLuaGlobal& luaGlobal = XLuaGlobal::Get();
	return luaGlobal.CreateState(sid);
}
