#pragma once

class WrapperXLuaState
{
public:
	static void LoadStringW(void* obj, const char* str, const char* sname = 0);
	static void LoadFile(void* obj, const char* str);
};
#pragma once
