#pragma once

class WrapperXLuaGlobal
{
public:
	static void* GetState(int sid);
	static bool CreateState(int sid);
};
