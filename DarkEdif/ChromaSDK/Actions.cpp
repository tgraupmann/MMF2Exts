#include "Common.h"
#include "Public/ChromaAnimationAPI.h"
#include <string>

using namespace ChromaSDK;
using namespace std;

void Extension::PlayAnimationName(const TCHAR* path, int loop)
{
	/*
	OutputDebugStringA("PlayAnimationName: Path=");
	OutputDebugStringA(path);
	OutputDebugStringA(" Loop=");
	OutputDebugStringA(loop == 0 ? "false" : "true");
	OutputDebugStringA("\r\n");
	*/

	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();

		ChromaAnimationAPI::PlayAnimationName(cPath, loop == 1);
	}
}

void Extension::PlayComposite(const TCHAR* name, int loop)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsName(name);
		string sName(bsName.begin(), bsName.end());
		const char* cName = sName.c_str();

		ChromaAnimationAPI::PlayComposite(cName, loop == 1);
	}
}

void Extension::StaticColor(int deviceType, int device, int color)
{
	if (CondIsInitialized())
	{
		ChromaAnimationAPI::StaticColor(deviceType, device, color);
	}
}

void Extension::StaticColorAllDevices(int color)
{
	StaticColor(ExpGetIntDeviceType(_T("ChromaLink")), ExpGetIntDevice(_T("ChromaLink")), color);
	StaticColor(ExpGetIntDeviceType(_T("Headset")), ExpGetIntDevice(_T("Headset")), color);
	StaticColor(ExpGetIntDeviceType(_T("Keyboard")), ExpGetIntDevice(_T("Keyboard")), color);
	StaticColor(ExpGetIntDeviceType(_T("Keypad")), ExpGetIntDevice(_T("Keypad")), color);
	StaticColor(ExpGetIntDeviceType(_T("Mouse")), ExpGetIntDevice(_T("Mouse")), color);
	StaticColor(ExpGetIntDeviceType(_T("Mousepad")), ExpGetIntDevice(_T("Mousepad")), color);
}

void Extension::ConnectXLua(ParamExtension* xLua)
{
	if (xLua)
	{

	}
}
