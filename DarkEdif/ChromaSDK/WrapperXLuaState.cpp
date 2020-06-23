#include "WrapperXLuaState.h"
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <hash_map>
#include "XLuaState.h"

void WrapperXLuaState::LoadStringW(void* obj, const char* str, const char* sname)
{
	if (obj)
	{
		XLuaState* xState = (XLuaState*)obj;
		if (xState)
		{
			xState->LoadStringA(str, sname);
		}
	}
}

void WrapperXLuaState::LoadFile(void* obj, const char* str)
{
	if (obj)
	{
		XLuaState* xState = (XLuaState*)obj;
		if (xState)
		{
			xState->LoadFile(str);
		}
	}
}
