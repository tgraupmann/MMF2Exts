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

int Extension::ExpGetIntDeviceType(const TCHAR* name)
{
	if (!_tcscmp(name, _T("ChromaLink")))
	{
		return 0;
	}
	if (!_tcscmp(name, _T("Headset")))
	{
		return 0;
	}
	if (!_tcscmp(name, _T("Keyboard")))
	{
		return 1;
	}
	if (!_tcscmp(name, _T("Keypad")))
	{
		return 1;
	}
	if (!_tcscmp(name, _T("Mouse")))
	{
		return 1;
	}
	if (!_tcscmp(name, _T("Mousepad")))
	{
		return 0;
	}
	return -1;
}

int Extension::ExpGetIntDevice(const TCHAR* name)
{
	if (!_tcscmp(name, _T("ChromaLink")))
	{
		return 0;
	}
	if (!_tcscmp(name, _T("Headset")))
	{
		return 1;
	}
	if (!_tcscmp(name, _T("Keyboard")))
	{
		return 0;
	}
	if (!_tcscmp(name, _T("Keypad")))
	{
		return 1;
	}
	if (!_tcscmp(name, _T("Mouse")))
	{
		return 2;
	}
	if (!_tcscmp(name, _T("Mousepad")))
	{
		return 2;
	}
	return -1;
}
