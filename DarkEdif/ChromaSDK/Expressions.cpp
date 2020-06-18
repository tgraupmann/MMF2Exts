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
