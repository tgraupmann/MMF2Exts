#include "Common.h"
#include "Public/ChromaAnimationAPI.h"
#include <string>

using namespace ChromaSDK;
using namespace std;

void Extension::ActInit()
{
	CondInit();
}

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

void Extension::StopAnimationName(const TCHAR* path)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();

		ChromaAnimationAPI::StopAnimationName(cPath);
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

void Extension::CloseAnimationName(const TCHAR* path)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::CloseAnimationName(cPath);
	}
}

void Extension::GetAnimation(const TCHAR* path)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::GetAnimation(cPath);
	}
}

void Extension::DuplicateFirstFrameName(const TCHAR* path, int frameCount)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::DuplicateFirstFrameName(cPath, frameCount);
	}
}

void Extension::DuplicateFramesName(const TCHAR* path)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::DuplicateFramesName(cPath);
	}
}

void Extension::MakeBlankFramesName(const TCHAR* path, int frameCount, float duration, int color)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::MakeBlankFramesName(cPath, frameCount, duration, color);
	}
}

void Extension::ReduceFramesName(const TCHAR* path, int n)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::ReduceFramesName(cPath, n);
	}
}

void Extension::InsertDelayName(const TCHAR* path, int frameId, int delay)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::InsertDelayName(cPath, frameId, delay);
	}
}

void Extension::TrimStartFramesName(const TCHAR* path, int numberOfFrames)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::TrimStartFramesName(cPath, numberOfFrames);
	}
}

void Extension::TrimEndFramesName(const TCHAR* path, int lastFrameId)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::TrimEndFramesName(cPath, lastFrameId);
	}
}

void Extension::MultiplyTargetColorLerpAllFramesName(const TCHAR* path, int color1, int color2)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::MultiplyTargetColorLerpAllFramesName(cPath, color1, color2);
	}
}

void Extension::MultiplyNonZeroTargetColorLerpAllFramesName(const TCHAR* path, int color1, int color2)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::MultiplyNonZeroTargetColorLerpAllFramesName(cPath, color1, color2);
	}
}


void Extension::FillZeroColorAllFramesName(const TCHAR* path, int color)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::FillZeroColorAllFramesName(cPath, color);
	}
}

void Extension::OffsetColorsAllFramesName(const TCHAR* path, int red, int green, int blue)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsPath(path);
		string sPath(bsPath.begin(), bsPath.end());
		const char* cPath = sPath.c_str();
		ChromaAnimationAPI::OffsetColorsAllFramesName(cPath, red, green, blue);
	}
}

void Extension::CopyNonZeroTargetAllKeysAllFramesName(const TCHAR* sourceAnimation, const TCHAR* targetAnimation)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsSource(sourceAnimation);
		string sSource(bsSource.begin(), bsSource.end());
		const char* cSource = sSource.c_str();

		basic_string<TCHAR> bsTarget(targetAnimation);
		string sTarget(bsTarget.begin(), bsTarget.end());
		const char* cTarget = sTarget.c_str();

		ChromaAnimationAPI::CopyNonZeroTargetAllKeysAllFramesName(cSource, cTarget);
	}
}

void Extension::CopyNonZeroAllKeysAllFramesName(const TCHAR* sourceAnimation, const TCHAR* targetAnimation)
{
	if (CondIsInitialized())
	{
		basic_string<TCHAR> bsSource(sourceAnimation);
		string sSource(bsSource.begin(), bsSource.end());
		const char* cSource = sSource.c_str();

		basic_string<TCHAR> bsTarget(targetAnimation);
		string sTarget(bsTarget.begin(), bsTarget.end());
		const char* cTarget = sTarget.c_str();

		ChromaAnimationAPI::CopyNonZeroAllKeysAllFramesName(cSource, cTarget);
	}
}

void Extension::ConnectXLua(ParamExtension* xLua)
{
	if (xLua)
	{

	}
}
