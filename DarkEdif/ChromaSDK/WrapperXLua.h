#pragma once

#include <string>

class WrapperXLua
{
public:
	static bool lua_isbooleanW(void* state, int idx);
	static bool lua_isstringW(void* state, int idx);

	static bool lua_tobooleanW(void* state, int idx);
	static std::string lua_tostringW(void* state, int idx);
};
