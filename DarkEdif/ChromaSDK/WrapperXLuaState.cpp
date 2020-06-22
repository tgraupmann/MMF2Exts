#include "WrapperXLuaState.h"
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <hash_map>
#include "XLuaState.h"

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
