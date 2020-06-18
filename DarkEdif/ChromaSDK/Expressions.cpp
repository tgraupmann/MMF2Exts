#include "Common.h"
#include "Public/ChromaAnimationAPI.h"
#include <string>

using namespace ChromaSDK;
using namespace std;


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

int Extension::ExpGetFrameCountName(const TCHAR* path)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();

		return ChromaAnimationAPI::GetFrameCountName(cPath);
	}
	else
	{
		return 0;
	}
}
