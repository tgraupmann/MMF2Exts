#include "Common.h"
#include "Public/ChromaAnimationAPI.h"

using namespace ChromaSDK;


int Extension::ExpIsInitialized()
{
	return CondIsInitialized();
}

int Extension::ExpInit()
{
	return CondInit();
}

int Extension::ExpGetRGB(int red, int green, int blue)
{
	if (CondIsInitialized())
	{
		ChromaAnimationAPI::GetRGB(red, green, blue);
	}
	else
	{
		return 0;
	}
}
