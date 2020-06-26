#include "Common.h"
#include "Public/ChromaAnimationAPI.h"
#include "WrapperXLua.h"
#include "WrapperXLuaGlobal.h"
#include "WrapperXLuaState.h"
#include <string>

#if _UNICODE
#pragma message("Building the UNICODE vesion of the ChromaSDK extension")
#else
#pragma message("Building the NON_UNICODE vesion of the ChromaSDK extension")
#endif

#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS
#include <hash_map>
namespace lua
{
	#include "XLuaState.h"
}

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

lua::XLuaState* Extension::GetLuaState()
{
	int sid = 0;
	lua::XLuaState* xState = (lua::XLuaState*)WrapperXLuaGlobal::GetState(sid);
	
	// Use the wrapper to call the global namespace :: include of XLuaGlobal
	if (xState == nullptr)
	{
		// The global namespace :: is able to create XLuaState states without link errors
		if (WrapperXLuaGlobal::CreateState(sid))
		{
			//OutputDebugStringA("Created Lua state!");
			// We aren't able to import the XLuaState from the global namespace because API changes
			// So we import XLuaState to the lua namespace to avoid API collisions
			// Here we cast the global namespaced XLuaState to the lua namespaced XLuaState
			xState = (lua::XLuaState*)WrapperXLuaGlobal::GetState(sid);
		}
		else
		{
			OutputDebugStringA("Failed to created Lua state!");
		}
	}
	return xState;
}

void Extension::ActLuaLoadString(const TCHAR* source)
{
	lua::XLuaState* xState = GetLuaState();
	if (xState != NULL)
	{
		basic_string<TCHAR> bsSource(source);
		string sSource(bsSource.begin(), bsSource.end());
		const char* cSource = sSource.c_str();

		WrapperXLuaState::LoadString(xState, cSource);
	}
}

void Extension::ActLuaLoadFile(const TCHAR* source)
{
	lua::XLuaState* xState = GetLuaState();
	if (xState != NULL)
	{
		basic_string<TCHAR> bsSource(source);
		string sSource(bsSource.begin(), bsSource.end());
		const char* cSource = sSource.c_str();

		WrapperXLuaState::LoadFile(xState, cSource);
	}
}

void Extension::RegisterLuaFunctions()
{
	lua::XLuaState* xState = GetLuaState();
	if (xState != NULL)
	{
		// The lua_State is used in all the binding functions
		lua::lua_State* lState = xState->state;
		if (lState)
		{
			// Load builtin libraries
			WrapperXLua::LoadBitLibrary(lState);
			WrapperXLua::LoadMathLibrary(lState);

			// Expose enums to lua
			WrapperXLuaState::LoadString(xState, "EChromaSDKDeviceEnum = {}");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDeviceEnum.DE_ChromaLink = 0");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDeviceEnum.DE_Headset = 1");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDeviceEnum.DE_Keyboard = 2");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDeviceEnum.DE_Keypad = 3");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDeviceEnum.DE_Mouse = 4");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDeviceEnum.DE_Mousepad = 5");

			WrapperXLuaState::LoadString(xState, "EChromaSDKDevice1DEnum = {}");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDevice1DEnum.DE_ChromaLink = 0");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDevice1DEnum.DE_Headset = 1");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDevice1DEnum.DE_Mousepad = 2");

			WrapperXLuaState::LoadString(xState, "EChromaSDKDevice2DEnum = {}");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDevice2DEnum.DE_Keyboard = 0");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDevice2DEnum.DE_Keypad = 1");
			WrapperXLuaState::LoadString(xState, "EChromaSDKDevice2DEnum.DE_Mouse = 2");

			WrapperXLuaState::LoadString(xState, "Keyboard = {}");
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY = {}");
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_ESC = tonumber(\"000001\", 16)"); /*!< Esc (VK_ESCAPE) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F1 = tonumber(\"000003\", 16)"); /*!< F1 (VK_F1) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F2 = tonumber(\"000004\", 16)"); /*!< F2 (VK_F2) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F3 = tonumber(\"000005\", 16)"); /*!< F3 (VK_F3) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F4 = tonumber(\"000006\", 16)"); /*!< F4 (VK_F4) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F5 = tonumber(\"000007\", 16)"); /*!< F5 (VK_F5) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F6 = tonumber(\"000008\", 16)"); /*!< F6 (VK_F6) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F7 = tonumber(\"000009\", 16)"); /*!< F7 (VK_F7) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F8 = tonumber(\"00000A\", 16)"); /*!< F8 (VK_F8) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F9 = tonumber(\"00000B\", 16)"); /*!< F9 (VK_F9) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F10 = tonumber(\"00000C\", 16)"); /*!< F10 (VK_F10) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F11 = tonumber(\"00000D\", 16)"); /*!< F11 (VK_F11) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F12 = tonumber(\"00000E\", 16)"); /*!< F12 (VK_F12) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_1 = tonumber(\"000102\", 16)"); /*!< 1 (VK_1) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_2 = tonumber(\"000103\", 16)"); /*!< 2 (VK_2) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_3 = tonumber(\"000104\", 16)"); /*!< 3 (VK_3) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_4 = tonumber(\"000105\", 16)"); /*!< 4 (VK_4) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_5 = tonumber(\"000106\", 16)"); /*!< 5 (VK_5) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_6 = tonumber(\"000107\", 16)"); /*!< 6 (VK_6) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_7 = tonumber(\"000108\", 16)"); /*!< 7 (VK_7) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_8 = tonumber(\"000109\", 16)"); /*!< 8 (VK_8) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_9 = tonumber(\"00010A\", 16)"); /*!< 9 (VK_9) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_0 = tonumber(\"00010B\", 16)"); /*!< 0 (VK_0) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_A = tonumber(\"000302\", 16)"); /*!< A (VK_A) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_B = tonumber(\"000407\", 16)"); /*!< B (VK_B) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_C = tonumber(\"000405\", 16)"); /*!< C (VK_C) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_D = tonumber(\"000304\", 16)"); /*!< D (VK_D) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_E = tonumber(\"000204\", 16)"); /*!< E (VK_E) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_F = tonumber(\"000305\", 16)"); /*!< F (VK_F) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_G = tonumber(\"000306\", 16)"); /*!< G (VK_G) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_H = tonumber(\"000307\", 16)"); /*!< H (VK_H) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_I = tonumber(\"000209\", 16)"); /*!< I (VK_I) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_J = tonumber(\"000308\", 16)"); /*!< J (VK_J) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_K = tonumber(\"000309\", 16)"); /*!< K (VK_K) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_L = tonumber(\"00030A\", 16)"); /*!< L (VK_L) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_M = tonumber(\"000409\", 16)"); /*!< M (VK_M) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_N = tonumber(\"000408\", 16)"); /*!< N (VK_N) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_O = tonumber(\"00020A\", 16)"); /*!< O (VK_O) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_P = tonumber(\"00020B\", 16)"); /*!< P (VK_P) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_Q = tonumber(\"000202\", 16)"); /*!< Q (VK_Q) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_R = tonumber(\"000205\", 16)"); /*!< R (VK_R) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_S = tonumber(\"000303\", 16)"); /*!< S (VK_S) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_T = tonumber(\"000206\", 16)"); /*!< T (VK_T) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_U = tonumber(\"000208\", 16)"); /*!< U (VK_U) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_V = tonumber(\"000406\", 16)"); /*!< V (VK_V) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_W = tonumber(\"000203\", 16)"); /*!< W (VK_W) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_X = tonumber(\"000404\", 16)"); /*!< X (VK_X) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_Y = tonumber(\"000207\", 16)"); /*!< Y (VK_Y) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_Z = tonumber(\"000403\", 16)"); /*!< Z (VK_Z) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMLOCK = tonumber(\"000112\", 16)"); /*!< Numlock (VK_NUMLOCK) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD0 = tonumber(\"000513\", 16)"); /*!< Numpad 0 (VK_NUMPAD0) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD1 = tonumber(\"000412\", 16)"); /*!< Numpad 1 (VK_NUMPAD1) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD2 = tonumber(\"000413\", 16)"); /*!< Numpad 2 (VK_NUMPAD2) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD3 = tonumber(\"000414\", 16)"); /*!< Numpad 3 (VK_NUMPAD3) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD4 = tonumber(\"000312\", 16)"); /*!< Numpad 4 (VK_NUMPAD4) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD5 = tonumber(\"000313\", 16)"); /*!< Numpad 5 (VK_NUMPAD5) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD6 = tonumber(\"000314\", 16)"); /*!< Numpad 6 (VK_NUMPAD6) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD7 = tonumber(\"000212\", 16)"); /*!< Numpad 7 (VK_NUMPAD7) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD8 = tonumber(\"000213\", 16)"); /*!< Numpad 8 (VK_NUMPAD8) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD9 = tonumber(\"000214\", 16)"); /*!< Numpad 9 (VK_ NUMPAD9*/
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD_DIVIDE = tonumber(\"000113\", 16)"); /*!< Divide (VK_DIVIDE) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD_MULTIPLY = tonumber(\"000114\", 16)"); /*!< Multiply (VK_MULTIPLY) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD_SUBTRACT = tonumber(\"000115\", 16)"); /*!< Subtract (VK_SUBTRACT) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD_ADD = tonumber(\"000215\", 16)"); /*!< Add (VK_ADD) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD_ENTER = tonumber(\"000415\", 16)"); /*!< Enter (VK_RETURN - Extended) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_NUMPAD_DECIMAL = tonumber(\"000514\", 16)"); /*!< Decimal (VK_DECIMAL) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_PRINTSCREEN = tonumber(\"00000F\", 16)"); /*!< Print Screen (VK_PRINT) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_SCROLL = tonumber(\"000010\", 16)"); /*!< Scroll Lock (VK_SCROLL) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_PAUSE = tonumber(\"000011\", 16)"); /*!< Pause (VK_PAUSE) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_INSERT = tonumber(\"00010F\", 16)"); /*!< Insert (VK_INSERT) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_HOME = tonumber(\"000110\", 16)"); /*!< Home (VK_HOME) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_PAGEUP = tonumber(\"000111\", 16)"); /*!< Page Up (VK_PRIOR) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_DELETE = tonumber(\"00020f\", 16)"); /*!< Delete (VK_DELETE) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_END = tonumber(\"000210\", 16)"); /*!< End (VK_END) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_PAGEDOWN = tonumber(\"000211\", 16)"); /*!< Page Down (VK_NEXT) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_UP = tonumber(\"000410\", 16)"); /*!< Up (VK_UP) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_LEFT = tonumber(\"00050F\", 16)"); /*!< Left (VK_LEFT) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_DOWN = tonumber(\"000510\", 16)"); /*!< Down (VK_DOWN) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_RIGHT = tonumber(\"000511\", 16)"); /*!< Right (VK_RIGHT) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_TAB = tonumber(\"000201\", 16)"); /*!< Tab (VK_TAB) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_CAPSLOCK = tonumber(\"000301\", 16)"); /*!< Caps Lock(VK_CAPITAL) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_BACKSPACE = tonumber(\"00010E\", 16)"); /*!< Backspace (VK_BACK) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_ENTER = tonumber(\"00030E\", 16)"); /*!< Enter (VK_RETURN) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_LCTRL = tonumber(\"000501\", 16)"); /*!< Left Control(VK_LCONTROL) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_LWIN = tonumber(\"000502\", 16)"); /*!< Left Window (VK_LWIN) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_LALT = tonumber(\"000503\", 16)"); /*!< Left Alt (VK_LMENU) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_SPACE = tonumber(\"000507\", 16)"); /*!< Spacebar (VK_SPACE) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_RALT = tonumber(\"00050B\", 16)"); /*!< Right Alt (VK_RMENU) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_FN = tonumber(\"00050C\", 16)"); /*!< Function key. */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_RMENU = tonumber(\"00050D\", 16)"); /*!< Right Menu (VK_APPS) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_RCTRL = tonumber(\"00050E\", 16)"); /*!< Right Control (VK_RCONTROL) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_LSHIFT = tonumber(\"000401\", 16)"); /*!< Left Shift (VK_LSHIFT) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_RSHIFT = tonumber(\"00040E\", 16)"); /*!< Right Shift (VK_RSHIFT) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_MACRO1 = tonumber(\"000100\", 16)"); /*!< Macro Key 1 */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_MACRO2 = tonumber(\"000200\", 16)"); /*!< Macro Key 2 */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_MACRO3 = tonumber(\"000300\", 16)"); /*!< Macro Key 3 */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_MACRO4 = tonumber(\"000400\", 16)"); /*!< Macro Key 4 */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_MACRO5 = tonumber(\"000500\", 16)"); /*!< Macro Key 5 */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_OEM_1 = tonumber(\"000101\", 16)"); /*!< ~ (tilde/半角/全角) (VK_OEM_3) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_OEM_2 = tonumber(\"00010C\", 16)"); /*!< -- (minus) (VK_OEM_MINUS) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_OEM_3 = tonumber(\"00010D\", 16)"); /*!< = tonumber(\"(equal) (VK_OEM_PLUS) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_OEM_4 = tonumber(\"00020C\", 16)"); /*!< [ (left sqaure bracket) (VK_OEM_4) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_OEM_5 = tonumber(\"00020D\", 16)"); /*!< ] (right square bracket) (VK_OEM_6) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_OEM_6 = tonumber(\"00020E\", 16)"); /*!< \ (backslash) (VK_OEM_5) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_OEM_7 = tonumber(\"00030B\", 16)"); /*!< ; (semi-colon) (VK_OEM_1) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_OEM_8 = tonumber(\"00030C\", 16)"); /*!< ' (apostrophe) (VK_OEM_7) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_OEM_9 = tonumber(\"00040A\", 16)"); /*!< \", 16)"); //(comma) (VK_OEM_COMMA) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_OEM_10 = tonumber(\"00040B\", 16)"); /*!< . (period) (VK_OEM_PERIOD) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_OEM_11 = tonumber(\"00040C\", 16)"); /*!< / (forward slash) (VK_OEM_2) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_EUR_1 = tonumber(\"00030D\", 16)"); /*!< "#" (VK_OEM_5) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_EUR_2 = tonumber(\"000402\", 16)"); /*!< \ (VK_OEM_102) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_JPN_1 = tonumber(\"000015\", 16)"); /*!< ¥ (00FF) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_JPN_2 = tonumber(\"00040D\", 16)"); /*!< \ (00C1) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_JPN_3 = tonumber(\"000504\", 16)"); /*!< 無変換 (VK_OEM_PA1) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_JPN_4 = tonumber(\"000509\", 16)"); /*!< 変換 (00FF) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_JPN_5 = tonumber(\"00050A\", 16)"); /*!< ひらがな/カタカナ (00FF) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_KOR_1 = tonumber(\"000015\", 16)"); /*!< | (00FF) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_KOR_2 = tonumber(\"00030D\", 16)"); /*!< (VK_OEM_5) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_KOR_3 = tonumber(\"000402\", 16)"); /*!< (VK_OEM_102) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_KOR_4 = tonumber(\"00040D\", 16)"); /*!< (00C1) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_KOR_5 = tonumber(\"000504\", 16)"); /*!< (VK_OEM_PA1) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_KOR_6 = tonumber(\"000509\", 16)"); /*!< 한/영 (00FF) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_KOR_7 = tonumber(\"00050A\", 16)"); /*!< (00FF) */
			WrapperXLuaState::LoadString(xState, "Keyboard.RZKEY.RZKEY_INVALID = tonumber(\"00FFFF\", 16)"); /*!< Invalid keys. */

			// Create an object to bind the global functions
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI = {}");

			lua::lua_pushcfunction(lState, Extension::LuaDebugPrint);
			lua::lua_setglobal(lState, "DebugPrint");

			//lua::lua_pushcfunction(lState, Extension::LuaLoadLibs);
			//lua::lua_setglobal(lState, "LoadLibs");

#pragma region Autogenerated bindings

			// AddFrame
			lua::lua_pushcfunction(lState, Extension::LuaAddFrame);
			lua::lua_setglobal(lState, "AddFrame");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddFrame = AddFrame");

			// AddNonZeroAllKeysAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroAllKeysAllFrames);
			lua::lua_setglobal(lState, "AddNonZeroAllKeysAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroAllKeysAllFrames = AddNonZeroAllKeysAllFrames");

			// AddNonZeroAllKeysAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroAllKeysAllFramesName);
			lua::lua_setglobal(lState, "AddNonZeroAllKeysAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroAllKeysAllFramesName = AddNonZeroAllKeysAllFramesName");

			// AddNonZeroAllKeysAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroAllKeysAllFramesNameD);
			lua::lua_setglobal(lState, "AddNonZeroAllKeysAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroAllKeysAllFramesNameD = AddNonZeroAllKeysAllFramesNameD");

			// AddNonZeroAllKeysAllFramesOffset
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroAllKeysAllFramesOffset);
			lua::lua_setglobal(lState, "AddNonZeroAllKeysAllFramesOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroAllKeysAllFramesOffset = AddNonZeroAllKeysAllFramesOffset");

			// AddNonZeroAllKeysAllFramesOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroAllKeysAllFramesOffsetName);
			lua::lua_setglobal(lState, "AddNonZeroAllKeysAllFramesOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroAllKeysAllFramesOffsetName = AddNonZeroAllKeysAllFramesOffsetName");

			// AddNonZeroAllKeysAllFramesOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroAllKeysAllFramesOffsetNameD);
			lua::lua_setglobal(lState, "AddNonZeroAllKeysAllFramesOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroAllKeysAllFramesOffsetNameD = AddNonZeroAllKeysAllFramesOffsetNameD");

			// AddNonZeroAllKeysOffset
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroAllKeysOffset);
			lua::lua_setglobal(lState, "AddNonZeroAllKeysOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroAllKeysOffset = AddNonZeroAllKeysOffset");

			// AddNonZeroAllKeysOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroAllKeysOffsetName);
			lua::lua_setglobal(lState, "AddNonZeroAllKeysOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroAllKeysOffsetName = AddNonZeroAllKeysOffsetName");

			// AddNonZeroAllKeysOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroAllKeysOffsetNameD);
			lua::lua_setglobal(lState, "AddNonZeroAllKeysOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroAllKeysOffsetNameD = AddNonZeroAllKeysOffsetNameD");

			// AddNonZeroTargetAllKeysAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroTargetAllKeysAllFrames);
			lua::lua_setglobal(lState, "AddNonZeroTargetAllKeysAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroTargetAllKeysAllFrames = AddNonZeroTargetAllKeysAllFrames");

			// AddNonZeroTargetAllKeysAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroTargetAllKeysAllFramesName);
			lua::lua_setglobal(lState, "AddNonZeroTargetAllKeysAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroTargetAllKeysAllFramesName = AddNonZeroTargetAllKeysAllFramesName");

			// AddNonZeroTargetAllKeysAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroTargetAllKeysAllFramesNameD);
			lua::lua_setglobal(lState, "AddNonZeroTargetAllKeysAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroTargetAllKeysAllFramesNameD = AddNonZeroTargetAllKeysAllFramesNameD");

			// AddNonZeroTargetAllKeysAllFramesOffset
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroTargetAllKeysAllFramesOffset);
			lua::lua_setglobal(lState, "AddNonZeroTargetAllKeysAllFramesOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroTargetAllKeysAllFramesOffset = AddNonZeroTargetAllKeysAllFramesOffset");

			// AddNonZeroTargetAllKeysAllFramesOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroTargetAllKeysAllFramesOffsetName);
			lua::lua_setglobal(lState, "AddNonZeroTargetAllKeysAllFramesOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroTargetAllKeysAllFramesOffsetName = AddNonZeroTargetAllKeysAllFramesOffsetName");

			// AddNonZeroTargetAllKeysAllFramesOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroTargetAllKeysAllFramesOffsetNameD);
			lua::lua_setglobal(lState, "AddNonZeroTargetAllKeysAllFramesOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroTargetAllKeysAllFramesOffsetNameD = AddNonZeroTargetAllKeysAllFramesOffsetNameD");

			// AddNonZeroTargetAllKeysOffset
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroTargetAllKeysOffset);
			lua::lua_setglobal(lState, "AddNonZeroTargetAllKeysOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroTargetAllKeysOffset = AddNonZeroTargetAllKeysOffset");

			// AddNonZeroTargetAllKeysOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroTargetAllKeysOffsetName);
			lua::lua_setglobal(lState, "AddNonZeroTargetAllKeysOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroTargetAllKeysOffsetName = AddNonZeroTargetAllKeysOffsetName");

			// AddNonZeroTargetAllKeysOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaAddNonZeroTargetAllKeysOffsetNameD);
			lua::lua_setglobal(lState, "AddNonZeroTargetAllKeysOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AddNonZeroTargetAllKeysOffsetNameD = AddNonZeroTargetAllKeysOffsetNameD");

			// AppendAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaAppendAllFrames);
			lua::lua_setglobal(lState, "AppendAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AppendAllFrames = AppendAllFrames");

			// AppendAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaAppendAllFramesName);
			lua::lua_setglobal(lState, "AppendAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AppendAllFramesName = AppendAllFramesName");

			// AppendAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaAppendAllFramesNameD);
			lua::lua_setglobal(lState, "AppendAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.AppendAllFramesNameD = AppendAllFramesNameD");

			// ClearAll
			lua::lua_pushcfunction(lState, Extension::LuaClearAll);
			lua::lua_setglobal(lState, "ClearAll");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ClearAll = ClearAll");

			// ClearAnimationType
			lua::lua_pushcfunction(lState, Extension::LuaClearAnimationType);
			lua::lua_setglobal(lState, "ClearAnimationType");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ClearAnimationType = ClearAnimationType");

			// CloseAll
			lua::lua_pushcfunction(lState, Extension::LuaCloseAll);
			lua::lua_setglobal(lState, "CloseAll");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CloseAll = CloseAll");

			// CloseAnimation
			lua::lua_pushcfunction(lState, Extension::LuaCloseAnimation);
			lua::lua_setglobal(lState, "CloseAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CloseAnimation = CloseAnimation");

			// CloseAnimationD
			lua::lua_pushcfunction(lState, Extension::LuaCloseAnimationD);
			lua::lua_setglobal(lState, "CloseAnimationD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CloseAnimationD = CloseAnimationD");

			// CloseAnimationName
			lua::lua_pushcfunction(lState, Extension::LuaCloseAnimationName);
			lua::lua_setglobal(lState, "CloseAnimationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CloseAnimationName = CloseAnimationName");

			// CloseAnimationNameD
			lua::lua_pushcfunction(lState, Extension::LuaCloseAnimationNameD);
			lua::lua_setglobal(lState, "CloseAnimationNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CloseAnimationNameD = CloseAnimationNameD");

			// CloseComposite
			lua::lua_pushcfunction(lState, Extension::LuaCloseComposite);
			lua::lua_setglobal(lState, "CloseComposite");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CloseComposite = CloseComposite");

			// CloseCompositeD
			lua::lua_pushcfunction(lState, Extension::LuaCloseCompositeD);
			lua::lua_setglobal(lState, "CloseCompositeD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CloseCompositeD = CloseCompositeD");

			// CopyAnimation
			lua::lua_pushcfunction(lState, Extension::LuaCopyAnimation);
			lua::lua_setglobal(lState, "CopyAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyAnimation = CopyAnimation");

			// CopyAnimationName
			lua::lua_pushcfunction(lState, Extension::LuaCopyAnimationName);
			lua::lua_setglobal(lState, "CopyAnimationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyAnimationName = CopyAnimationName");

			// CopyAnimationNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyAnimationNameD);
			lua::lua_setglobal(lState, "CopyAnimationNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyAnimationNameD = CopyAnimationNameD");

			// CopyBlueChannelAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaCopyBlueChannelAllFrames);
			lua::lua_setglobal(lState, "CopyBlueChannelAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyBlueChannelAllFrames = CopyBlueChannelAllFrames");

			// CopyBlueChannelAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaCopyBlueChannelAllFramesName);
			lua::lua_setglobal(lState, "CopyBlueChannelAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyBlueChannelAllFramesName = CopyBlueChannelAllFramesName");

			// CopyBlueChannelAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyBlueChannelAllFramesNameD);
			lua::lua_setglobal(lState, "CopyBlueChannelAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyBlueChannelAllFramesNameD = CopyBlueChannelAllFramesNameD");

			// CopyGreenChannelAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaCopyGreenChannelAllFrames);
			lua::lua_setglobal(lState, "CopyGreenChannelAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyGreenChannelAllFrames = CopyGreenChannelAllFrames");

			// CopyGreenChannelAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaCopyGreenChannelAllFramesName);
			lua::lua_setglobal(lState, "CopyGreenChannelAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyGreenChannelAllFramesName = CopyGreenChannelAllFramesName");

			// CopyGreenChannelAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyGreenChannelAllFramesNameD);
			lua::lua_setglobal(lState, "CopyGreenChannelAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyGreenChannelAllFramesNameD = CopyGreenChannelAllFramesNameD");

			// CopyKeyColor
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeyColor);
			lua::lua_setglobal(lState, "CopyKeyColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeyColor = CopyKeyColor");

			// CopyKeyColorAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeyColorAllFrames);
			lua::lua_setglobal(lState, "CopyKeyColorAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeyColorAllFrames = CopyKeyColorAllFrames");

			// CopyKeyColorAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeyColorAllFramesName);
			lua::lua_setglobal(lState, "CopyKeyColorAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeyColorAllFramesName = CopyKeyColorAllFramesName");

			// CopyKeyColorAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeyColorAllFramesNameD);
			lua::lua_setglobal(lState, "CopyKeyColorAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeyColorAllFramesNameD = CopyKeyColorAllFramesNameD");

			// CopyKeyColorAllFramesOffset
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeyColorAllFramesOffset);
			lua::lua_setglobal(lState, "CopyKeyColorAllFramesOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeyColorAllFramesOffset = CopyKeyColorAllFramesOffset");

			// CopyKeyColorAllFramesOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeyColorAllFramesOffsetName);
			lua::lua_setglobal(lState, "CopyKeyColorAllFramesOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeyColorAllFramesOffsetName = CopyKeyColorAllFramesOffsetName");

			// CopyKeyColorAllFramesOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeyColorAllFramesOffsetNameD);
			lua::lua_setglobal(lState, "CopyKeyColorAllFramesOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeyColorAllFramesOffsetNameD = CopyKeyColorAllFramesOffsetNameD");

			// CopyKeyColorName
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeyColorName);
			lua::lua_setglobal(lState, "CopyKeyColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeyColorName = CopyKeyColorName");

			// CopyKeyColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeyColorNameD);
			lua::lua_setglobal(lState, "CopyKeyColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeyColorNameD = CopyKeyColorNameD");

			// CopyKeysColor
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeysColor);
			lua::lua_setglobal(lState, "CopyKeysColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeysColor = CopyKeysColor");

			// CopyKeysColorAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeysColorAllFrames);
			lua::lua_setglobal(lState, "CopyKeysColorAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeysColorAllFrames = CopyKeysColorAllFrames");

			// CopyKeysColorAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeysColorAllFramesName);
			lua::lua_setglobal(lState, "CopyKeysColorAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeysColorAllFramesName = CopyKeysColorAllFramesName");

			// CopyKeysColorName
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeysColorName);
			lua::lua_setglobal(lState, "CopyKeysColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeysColorName = CopyKeysColorName");

			// CopyKeysColorOffset
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeysColorOffset);
			lua::lua_setglobal(lState, "CopyKeysColorOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeysColorOffset = CopyKeysColorOffset");

			// CopyKeysColorOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaCopyKeysColorOffsetName);
			lua::lua_setglobal(lState, "CopyKeysColorOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyKeysColorOffsetName = CopyKeysColorOffsetName");

			// CopyNonZeroAllKeys
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeys);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeys");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeys = CopyNonZeroAllKeys");

			// CopyNonZeroAllKeysAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeysAllFrames);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeysAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeysAllFrames = CopyNonZeroAllKeysAllFrames");

			// CopyNonZeroAllKeysAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeysAllFramesName);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeysAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeysAllFramesName = CopyNonZeroAllKeysAllFramesName");

			// CopyNonZeroAllKeysAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeysAllFramesNameD);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeysAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeysAllFramesNameD = CopyNonZeroAllKeysAllFramesNameD");

			// CopyNonZeroAllKeysAllFramesOffset
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeysAllFramesOffset);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeysAllFramesOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeysAllFramesOffset = CopyNonZeroAllKeysAllFramesOffset");

			// CopyNonZeroAllKeysAllFramesOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeysAllFramesOffsetName);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeysAllFramesOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeysAllFramesOffsetName = CopyNonZeroAllKeysAllFramesOffsetName");

			// CopyNonZeroAllKeysAllFramesOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeysAllFramesOffsetNameD);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeysAllFramesOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeysAllFramesOffsetNameD = CopyNonZeroAllKeysAllFramesOffsetNameD");

			// CopyNonZeroAllKeysName
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeysName);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeysName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeysName = CopyNonZeroAllKeysName");

			// CopyNonZeroAllKeysNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeysNameD);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeysNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeysNameD = CopyNonZeroAllKeysNameD");

			// CopyNonZeroAllKeysOffset
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeysOffset);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeysOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeysOffset = CopyNonZeroAllKeysOffset");

			// CopyNonZeroAllKeysOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeysOffsetName);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeysOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeysOffsetName = CopyNonZeroAllKeysOffsetName");

			// CopyNonZeroAllKeysOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroAllKeysOffsetNameD);
			lua::lua_setglobal(lState, "CopyNonZeroAllKeysOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroAllKeysOffsetNameD = CopyNonZeroAllKeysOffsetNameD");

			// CopyNonZeroKeyColor
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroKeyColor);
			lua::lua_setglobal(lState, "CopyNonZeroKeyColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroKeyColor = CopyNonZeroKeyColor");

			// CopyNonZeroKeyColorName
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroKeyColorName);
			lua::lua_setglobal(lState, "CopyNonZeroKeyColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroKeyColorName = CopyNonZeroKeyColorName");

			// CopyNonZeroKeyColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroKeyColorNameD);
			lua::lua_setglobal(lState, "CopyNonZeroKeyColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroKeyColorNameD = CopyNonZeroKeyColorNameD");

			// CopyNonZeroTargetAllKeys
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeys);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeys");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeys = CopyNonZeroTargetAllKeys");

			// CopyNonZeroTargetAllKeysAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeysAllFrames);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeysAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeysAllFrames = CopyNonZeroTargetAllKeysAllFrames");

			// CopyNonZeroTargetAllKeysAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeysAllFramesName);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeysAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeysAllFramesName = CopyNonZeroTargetAllKeysAllFramesName");

			// CopyNonZeroTargetAllKeysAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeysAllFramesNameD);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeysAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeysAllFramesNameD = CopyNonZeroTargetAllKeysAllFramesNameD");

			// CopyNonZeroTargetAllKeysAllFramesOffset
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeysAllFramesOffset);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeysAllFramesOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeysAllFramesOffset = CopyNonZeroTargetAllKeysAllFramesOffset");

			// CopyNonZeroTargetAllKeysAllFramesOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeysAllFramesOffsetName);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeysAllFramesOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeysAllFramesOffsetName = CopyNonZeroTargetAllKeysAllFramesOffsetName");

			// CopyNonZeroTargetAllKeysAllFramesOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeysAllFramesOffsetNameD);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeysAllFramesOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeysAllFramesOffsetNameD = CopyNonZeroTargetAllKeysAllFramesOffsetNameD");

			// CopyNonZeroTargetAllKeysName
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeysName);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeysName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeysName = CopyNonZeroTargetAllKeysName");

			// CopyNonZeroTargetAllKeysNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeysNameD);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeysNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeysNameD = CopyNonZeroTargetAllKeysNameD");

			// CopyNonZeroTargetAllKeysOffset
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeysOffset);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeysOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeysOffset = CopyNonZeroTargetAllKeysOffset");

			// CopyNonZeroTargetAllKeysOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeysOffsetName);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeysOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeysOffsetName = CopyNonZeroTargetAllKeysOffsetName");

			// CopyNonZeroTargetAllKeysOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetAllKeysOffsetNameD);
			lua::lua_setglobal(lState, "CopyNonZeroTargetAllKeysOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetAllKeysOffsetNameD = CopyNonZeroTargetAllKeysOffsetNameD");

			// CopyNonZeroTargetZeroAllKeysAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetZeroAllKeysAllFrames);
			lua::lua_setglobal(lState, "CopyNonZeroTargetZeroAllKeysAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetZeroAllKeysAllFrames = CopyNonZeroTargetZeroAllKeysAllFrames");

			// CopyNonZeroTargetZeroAllKeysAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetZeroAllKeysAllFramesName);
			lua::lua_setglobal(lState, "CopyNonZeroTargetZeroAllKeysAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetZeroAllKeysAllFramesName = CopyNonZeroTargetZeroAllKeysAllFramesName");

			// CopyNonZeroTargetZeroAllKeysAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyNonZeroTargetZeroAllKeysAllFramesNameD);
			lua::lua_setglobal(lState, "CopyNonZeroTargetZeroAllKeysAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyNonZeroTargetZeroAllKeysAllFramesNameD = CopyNonZeroTargetZeroAllKeysAllFramesNameD");

			// CopyRedChannelAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaCopyRedChannelAllFrames);
			lua::lua_setglobal(lState, "CopyRedChannelAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyRedChannelAllFrames = CopyRedChannelAllFrames");

			// CopyRedChannelAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaCopyRedChannelAllFramesName);
			lua::lua_setglobal(lState, "CopyRedChannelAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyRedChannelAllFramesName = CopyRedChannelAllFramesName");

			// CopyRedChannelAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyRedChannelAllFramesNameD);
			lua::lua_setglobal(lState, "CopyRedChannelAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyRedChannelAllFramesNameD = CopyRedChannelAllFramesNameD");

			// CopyZeroAllKeysAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroAllKeysAllFrames);
			lua::lua_setglobal(lState, "CopyZeroAllKeysAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroAllKeysAllFrames = CopyZeroAllKeysAllFrames");

			// CopyZeroAllKeysAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroAllKeysAllFramesName);
			lua::lua_setglobal(lState, "CopyZeroAllKeysAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroAllKeysAllFramesName = CopyZeroAllKeysAllFramesName");

			// CopyZeroAllKeysAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroAllKeysAllFramesNameD);
			lua::lua_setglobal(lState, "CopyZeroAllKeysAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroAllKeysAllFramesNameD = CopyZeroAllKeysAllFramesNameD");

			// CopyZeroAllKeysAllFramesOffset
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroAllKeysAllFramesOffset);
			lua::lua_setglobal(lState, "CopyZeroAllKeysAllFramesOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroAllKeysAllFramesOffset = CopyZeroAllKeysAllFramesOffset");

			// CopyZeroAllKeysAllFramesOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroAllKeysAllFramesOffsetName);
			lua::lua_setglobal(lState, "CopyZeroAllKeysAllFramesOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroAllKeysAllFramesOffsetName = CopyZeroAllKeysAllFramesOffsetName");

			// CopyZeroAllKeysAllFramesOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroAllKeysAllFramesOffsetNameD);
			lua::lua_setglobal(lState, "CopyZeroAllKeysAllFramesOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroAllKeysAllFramesOffsetNameD = CopyZeroAllKeysAllFramesOffsetNameD");

			// CopyZeroKeyColor
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroKeyColor);
			lua::lua_setglobal(lState, "CopyZeroKeyColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroKeyColor = CopyZeroKeyColor");

			// CopyZeroKeyColorName
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroKeyColorName);
			lua::lua_setglobal(lState, "CopyZeroKeyColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroKeyColorName = CopyZeroKeyColorName");

			// CopyZeroKeyColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroKeyColorNameD);
			lua::lua_setglobal(lState, "CopyZeroKeyColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroKeyColorNameD = CopyZeroKeyColorNameD");

			// CopyZeroTargetAllKeysAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroTargetAllKeysAllFrames);
			lua::lua_setglobal(lState, "CopyZeroTargetAllKeysAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroTargetAllKeysAllFrames = CopyZeroTargetAllKeysAllFrames");

			// CopyZeroTargetAllKeysAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroTargetAllKeysAllFramesName);
			lua::lua_setglobal(lState, "CopyZeroTargetAllKeysAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroTargetAllKeysAllFramesName = CopyZeroTargetAllKeysAllFramesName");

			// CopyZeroTargetAllKeysAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaCopyZeroTargetAllKeysAllFramesNameD);
			lua::lua_setglobal(lState, "CopyZeroTargetAllKeysAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CopyZeroTargetAllKeysAllFramesNameD = CopyZeroTargetAllKeysAllFramesNameD");

			// CoreCreateChromaLinkEffect
			lua::lua_pushcfunction(lState, Extension::LuaCoreCreateChromaLinkEffect);
			lua::lua_setglobal(lState, "CoreCreateChromaLinkEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreCreateChromaLinkEffect = CoreCreateChromaLinkEffect");

			// CoreCreateEffect
			lua::lua_pushcfunction(lState, Extension::LuaCoreCreateEffect);
			lua::lua_setglobal(lState, "CoreCreateEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreCreateEffect = CoreCreateEffect");

			// CoreCreateHeadsetEffect
			lua::lua_pushcfunction(lState, Extension::LuaCoreCreateHeadsetEffect);
			lua::lua_setglobal(lState, "CoreCreateHeadsetEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreCreateHeadsetEffect = CoreCreateHeadsetEffect");

			// CoreCreateKeyboardEffect
			lua::lua_pushcfunction(lState, Extension::LuaCoreCreateKeyboardEffect);
			lua::lua_setglobal(lState, "CoreCreateKeyboardEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreCreateKeyboardEffect = CoreCreateKeyboardEffect");

			// CoreCreateKeypadEffect
			lua::lua_pushcfunction(lState, Extension::LuaCoreCreateKeypadEffect);
			lua::lua_setglobal(lState, "CoreCreateKeypadEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreCreateKeypadEffect = CoreCreateKeypadEffect");

			// CoreCreateMouseEffect
			lua::lua_pushcfunction(lState, Extension::LuaCoreCreateMouseEffect);
			lua::lua_setglobal(lState, "CoreCreateMouseEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreCreateMouseEffect = CoreCreateMouseEffect");

			// CoreCreateMousepadEffect
			lua::lua_pushcfunction(lState, Extension::LuaCoreCreateMousepadEffect);
			lua::lua_setglobal(lState, "CoreCreateMousepadEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreCreateMousepadEffect = CoreCreateMousepadEffect");

			// CoreDeleteEffect
			lua::lua_pushcfunction(lState, Extension::LuaCoreDeleteEffect);
			lua::lua_setglobal(lState, "CoreDeleteEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreDeleteEffect = CoreDeleteEffect");

			// CoreInit
			lua::lua_pushcfunction(lState, Extension::LuaCoreInit);
			lua::lua_setglobal(lState, "CoreInit");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreInit = CoreInit");

			// CoreInitSDK
			lua::lua_pushcfunction(lState, Extension::LuaCoreInitSDK);
			lua::lua_setglobal(lState, "CoreInitSDK");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreInitSDK = CoreInitSDK");

			// CoreQueryDevice
			lua::lua_pushcfunction(lState, Extension::LuaCoreQueryDevice);
			lua::lua_setglobal(lState, "CoreQueryDevice");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreQueryDevice = CoreQueryDevice");

			// CoreSetEffect
			lua::lua_pushcfunction(lState, Extension::LuaCoreSetEffect);
			lua::lua_setglobal(lState, "CoreSetEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreSetEffect = CoreSetEffect");

			// CoreUnInit
			lua::lua_pushcfunction(lState, Extension::LuaCoreUnInit);
			lua::lua_setglobal(lState, "CoreUnInit");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CoreUnInit = CoreUnInit");

			// CreateAnimation
			lua::lua_pushcfunction(lState, Extension::LuaCreateAnimation);
			lua::lua_setglobal(lState, "CreateAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CreateAnimation = CreateAnimation");

			// CreateAnimationInMemory
			lua::lua_pushcfunction(lState, Extension::LuaCreateAnimationInMemory);
			lua::lua_setglobal(lState, "CreateAnimationInMemory");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CreateAnimationInMemory = CreateAnimationInMemory");

			// CreateEffect
			lua::lua_pushcfunction(lState, Extension::LuaCreateEffect);
			lua::lua_setglobal(lState, "CreateEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.CreateEffect = CreateEffect");

			// DeleteEffect
			lua::lua_pushcfunction(lState, Extension::LuaDeleteEffect);
			lua::lua_setglobal(lState, "DeleteEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.DeleteEffect = DeleteEffect");

			// DuplicateFirstFrame
			lua::lua_pushcfunction(lState, Extension::LuaDuplicateFirstFrame);
			lua::lua_setglobal(lState, "DuplicateFirstFrame");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.DuplicateFirstFrame = DuplicateFirstFrame");

			// DuplicateFirstFrameName
			lua::lua_pushcfunction(lState, Extension::LuaDuplicateFirstFrameName);
			lua::lua_setglobal(lState, "DuplicateFirstFrameName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.DuplicateFirstFrameName = DuplicateFirstFrameName");

			// DuplicateFirstFrameNameD
			lua::lua_pushcfunction(lState, Extension::LuaDuplicateFirstFrameNameD);
			lua::lua_setglobal(lState, "DuplicateFirstFrameNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.DuplicateFirstFrameNameD = DuplicateFirstFrameNameD");

			// DuplicateFrames
			lua::lua_pushcfunction(lState, Extension::LuaDuplicateFrames);
			lua::lua_setglobal(lState, "DuplicateFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.DuplicateFrames = DuplicateFrames");

			// DuplicateFramesName
			lua::lua_pushcfunction(lState, Extension::LuaDuplicateFramesName);
			lua::lua_setglobal(lState, "DuplicateFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.DuplicateFramesName = DuplicateFramesName");

			// DuplicateFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaDuplicateFramesNameD);
			lua::lua_setglobal(lState, "DuplicateFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.DuplicateFramesNameD = DuplicateFramesNameD");

			// DuplicateMirrorFrames
			lua::lua_pushcfunction(lState, Extension::LuaDuplicateMirrorFrames);
			lua::lua_setglobal(lState, "DuplicateMirrorFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.DuplicateMirrorFrames = DuplicateMirrorFrames");

			// DuplicateMirrorFramesName
			lua::lua_pushcfunction(lState, Extension::LuaDuplicateMirrorFramesName);
			lua::lua_setglobal(lState, "DuplicateMirrorFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.DuplicateMirrorFramesName = DuplicateMirrorFramesName");

			// DuplicateMirrorFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaDuplicateMirrorFramesNameD);
			lua::lua_setglobal(lState, "DuplicateMirrorFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.DuplicateMirrorFramesNameD = DuplicateMirrorFramesNameD");

			// FadeEndFrames
			lua::lua_pushcfunction(lState, Extension::LuaFadeEndFrames);
			lua::lua_setglobal(lState, "FadeEndFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FadeEndFrames = FadeEndFrames");

			// FadeEndFramesName
			lua::lua_pushcfunction(lState, Extension::LuaFadeEndFramesName);
			lua::lua_setglobal(lState, "FadeEndFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FadeEndFramesName = FadeEndFramesName");

			// FadeEndFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaFadeEndFramesNameD);
			lua::lua_setglobal(lState, "FadeEndFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FadeEndFramesNameD = FadeEndFramesNameD");

			// FadeStartFrames
			lua::lua_pushcfunction(lState, Extension::LuaFadeStartFrames);
			lua::lua_setglobal(lState, "FadeStartFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FadeStartFrames = FadeStartFrames");

			// FadeStartFramesName
			lua::lua_pushcfunction(lState, Extension::LuaFadeStartFramesName);
			lua::lua_setglobal(lState, "FadeStartFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FadeStartFramesName = FadeStartFramesName");

			// FadeStartFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaFadeStartFramesNameD);
			lua::lua_setglobal(lState, "FadeStartFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FadeStartFramesNameD = FadeStartFramesNameD");

			// FillColor
			lua::lua_pushcfunction(lState, Extension::LuaFillColor);
			lua::lua_setglobal(lState, "FillColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColor = FillColor");

			// FillColorAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaFillColorAllFrames);
			lua::lua_setglobal(lState, "FillColorAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColorAllFrames = FillColorAllFrames");

			// FillColorAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaFillColorAllFramesName);
			lua::lua_setglobal(lState, "FillColorAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColorAllFramesName = FillColorAllFramesName");

			// FillColorAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillColorAllFramesNameD);
			lua::lua_setglobal(lState, "FillColorAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColorAllFramesNameD = FillColorAllFramesNameD");

			// FillColorAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillColorAllFramesRGB);
			lua::lua_setglobal(lState, "FillColorAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColorAllFramesRGB = FillColorAllFramesRGB");

			// FillColorAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillColorAllFramesRGBName);
			lua::lua_setglobal(lState, "FillColorAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColorAllFramesRGBName = FillColorAllFramesRGBName");

			// FillColorAllFramesRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillColorAllFramesRGBNameD);
			lua::lua_setglobal(lState, "FillColorAllFramesRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColorAllFramesRGBNameD = FillColorAllFramesRGBNameD");

			// FillColorName
			lua::lua_pushcfunction(lState, Extension::LuaFillColorName);
			lua::lua_setglobal(lState, "FillColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColorName = FillColorName");

			// FillColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillColorNameD);
			lua::lua_setglobal(lState, "FillColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColorNameD = FillColorNameD");

			// FillColorRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillColorRGB);
			lua::lua_setglobal(lState, "FillColorRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColorRGB = FillColorRGB");

			// FillColorRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillColorRGBName);
			lua::lua_setglobal(lState, "FillColorRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColorRGBName = FillColorRGBName");

			// FillColorRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillColorRGBNameD);
			lua::lua_setglobal(lState, "FillColorRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillColorRGBNameD = FillColorRGBNameD");

			// FillNonZeroColor
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColor);
			lua::lua_setglobal(lState, "FillNonZeroColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColor = FillNonZeroColor");

			// FillNonZeroColorAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColorAllFrames);
			lua::lua_setglobal(lState, "FillNonZeroColorAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColorAllFrames = FillNonZeroColorAllFrames");

			// FillNonZeroColorAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColorAllFramesName);
			lua::lua_setglobal(lState, "FillNonZeroColorAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColorAllFramesName = FillNonZeroColorAllFramesName");

			// FillNonZeroColorAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColorAllFramesNameD);
			lua::lua_setglobal(lState, "FillNonZeroColorAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColorAllFramesNameD = FillNonZeroColorAllFramesNameD");

			// FillNonZeroColorAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColorAllFramesRGB);
			lua::lua_setglobal(lState, "FillNonZeroColorAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColorAllFramesRGB = FillNonZeroColorAllFramesRGB");

			// FillNonZeroColorAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColorAllFramesRGBName);
			lua::lua_setglobal(lState, "FillNonZeroColorAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColorAllFramesRGBName = FillNonZeroColorAllFramesRGBName");

			// FillNonZeroColorAllFramesRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColorAllFramesRGBNameD);
			lua::lua_setglobal(lState, "FillNonZeroColorAllFramesRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColorAllFramesRGBNameD = FillNonZeroColorAllFramesRGBNameD");

			// FillNonZeroColorName
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColorName);
			lua::lua_setglobal(lState, "FillNonZeroColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColorName = FillNonZeroColorName");

			// FillNonZeroColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColorNameD);
			lua::lua_setglobal(lState, "FillNonZeroColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColorNameD = FillNonZeroColorNameD");

			// FillNonZeroColorRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColorRGB);
			lua::lua_setglobal(lState, "FillNonZeroColorRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColorRGB = FillNonZeroColorRGB");

			// FillNonZeroColorRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColorRGBName);
			lua::lua_setglobal(lState, "FillNonZeroColorRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColorRGBName = FillNonZeroColorRGBName");

			// FillNonZeroColorRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillNonZeroColorRGBNameD);
			lua::lua_setglobal(lState, "FillNonZeroColorRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillNonZeroColorRGBNameD = FillNonZeroColorRGBNameD");

			// FillRandomColors
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColors);
			lua::lua_setglobal(lState, "FillRandomColors");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColors = FillRandomColors");

			// FillRandomColorsAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColorsAllFrames);
			lua::lua_setglobal(lState, "FillRandomColorsAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColorsAllFrames = FillRandomColorsAllFrames");

			// FillRandomColorsAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColorsAllFramesName);
			lua::lua_setglobal(lState, "FillRandomColorsAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColorsAllFramesName = FillRandomColorsAllFramesName");

			// FillRandomColorsAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColorsAllFramesNameD);
			lua::lua_setglobal(lState, "FillRandomColorsAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColorsAllFramesNameD = FillRandomColorsAllFramesNameD");

			// FillRandomColorsBlackAndWhite
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColorsBlackAndWhite);
			lua::lua_setglobal(lState, "FillRandomColorsBlackAndWhite");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColorsBlackAndWhite = FillRandomColorsBlackAndWhite");

			// FillRandomColorsBlackAndWhiteAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColorsBlackAndWhiteAllFrames);
			lua::lua_setglobal(lState, "FillRandomColorsBlackAndWhiteAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColorsBlackAndWhiteAllFrames = FillRandomColorsBlackAndWhiteAllFrames");

			// FillRandomColorsBlackAndWhiteAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColorsBlackAndWhiteAllFramesName);
			lua::lua_setglobal(lState, "FillRandomColorsBlackAndWhiteAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColorsBlackAndWhiteAllFramesName = FillRandomColorsBlackAndWhiteAllFramesName");

			// FillRandomColorsBlackAndWhiteAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColorsBlackAndWhiteAllFramesNameD);
			lua::lua_setglobal(lState, "FillRandomColorsBlackAndWhiteAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColorsBlackAndWhiteAllFramesNameD = FillRandomColorsBlackAndWhiteAllFramesNameD");

			// FillRandomColorsBlackAndWhiteName
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColorsBlackAndWhiteName);
			lua::lua_setglobal(lState, "FillRandomColorsBlackAndWhiteName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColorsBlackAndWhiteName = FillRandomColorsBlackAndWhiteName");

			// FillRandomColorsBlackAndWhiteNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColorsBlackAndWhiteNameD);
			lua::lua_setglobal(lState, "FillRandomColorsBlackAndWhiteNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColorsBlackAndWhiteNameD = FillRandomColorsBlackAndWhiteNameD");

			// FillRandomColorsName
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColorsName);
			lua::lua_setglobal(lState, "FillRandomColorsName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColorsName = FillRandomColorsName");

			// FillRandomColorsNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillRandomColorsNameD);
			lua::lua_setglobal(lState, "FillRandomColorsNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillRandomColorsNameD = FillRandomColorsNameD");

			// FillThresholdColors
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColors);
			lua::lua_setglobal(lState, "FillThresholdColors");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColors = FillThresholdColors");

			// FillThresholdColorsAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsAllFrames);
			lua::lua_setglobal(lState, "FillThresholdColorsAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsAllFrames = FillThresholdColorsAllFrames");

			// FillThresholdColorsAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsAllFramesName);
			lua::lua_setglobal(lState, "FillThresholdColorsAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsAllFramesName = FillThresholdColorsAllFramesName");

			// FillThresholdColorsAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsAllFramesNameD);
			lua::lua_setglobal(lState, "FillThresholdColorsAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsAllFramesNameD = FillThresholdColorsAllFramesNameD");

			// FillThresholdColorsAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsAllFramesRGB);
			lua::lua_setglobal(lState, "FillThresholdColorsAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsAllFramesRGB = FillThresholdColorsAllFramesRGB");

			// FillThresholdColorsAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsAllFramesRGBName);
			lua::lua_setglobal(lState, "FillThresholdColorsAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsAllFramesRGBName = FillThresholdColorsAllFramesRGBName");

			// FillThresholdColorsAllFramesRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsAllFramesRGBNameD);
			lua::lua_setglobal(lState, "FillThresholdColorsAllFramesRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsAllFramesRGBNameD = FillThresholdColorsAllFramesRGBNameD");

			// FillThresholdColorsMinMaxAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsMinMaxAllFramesRGB);
			lua::lua_setglobal(lState, "FillThresholdColorsMinMaxAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsMinMaxAllFramesRGB = FillThresholdColorsMinMaxAllFramesRGB");

			// FillThresholdColorsMinMaxAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsMinMaxAllFramesRGBName);
			lua::lua_setglobal(lState, "FillThresholdColorsMinMaxAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsMinMaxAllFramesRGBName = FillThresholdColorsMinMaxAllFramesRGBName");

			// FillThresholdColorsMinMaxAllFramesRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsMinMaxAllFramesRGBNameD);
			lua::lua_setglobal(lState, "FillThresholdColorsMinMaxAllFramesRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsMinMaxAllFramesRGBNameD = FillThresholdColorsMinMaxAllFramesRGBNameD");

			// FillThresholdColorsMinMaxRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsMinMaxRGB);
			lua::lua_setglobal(lState, "FillThresholdColorsMinMaxRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsMinMaxRGB = FillThresholdColorsMinMaxRGB");

			// FillThresholdColorsMinMaxRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsMinMaxRGBName);
			lua::lua_setglobal(lState, "FillThresholdColorsMinMaxRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsMinMaxRGBName = FillThresholdColorsMinMaxRGBName");

			// FillThresholdColorsMinMaxRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsMinMaxRGBNameD);
			lua::lua_setglobal(lState, "FillThresholdColorsMinMaxRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsMinMaxRGBNameD = FillThresholdColorsMinMaxRGBNameD");

			// FillThresholdColorsName
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsName);
			lua::lua_setglobal(lState, "FillThresholdColorsName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsName = FillThresholdColorsName");

			// FillThresholdColorsNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsNameD);
			lua::lua_setglobal(lState, "FillThresholdColorsNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsNameD = FillThresholdColorsNameD");

			// FillThresholdColorsRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsRGB);
			lua::lua_setglobal(lState, "FillThresholdColorsRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsRGB = FillThresholdColorsRGB");

			// FillThresholdColorsRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsRGBName);
			lua::lua_setglobal(lState, "FillThresholdColorsRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsRGBName = FillThresholdColorsRGBName");

			// FillThresholdColorsRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdColorsRGBNameD);
			lua::lua_setglobal(lState, "FillThresholdColorsRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdColorsRGBNameD = FillThresholdColorsRGBNameD");

			// FillThresholdRGBColorsAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdRGBColorsAllFramesRGB);
			lua::lua_setglobal(lState, "FillThresholdRGBColorsAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdRGBColorsAllFramesRGB = FillThresholdRGBColorsAllFramesRGB");

			// FillThresholdRGBColorsAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdRGBColorsAllFramesRGBName);
			lua::lua_setglobal(lState, "FillThresholdRGBColorsAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdRGBColorsAllFramesRGBName = FillThresholdRGBColorsAllFramesRGBName");

			// FillThresholdRGBColorsAllFramesRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdRGBColorsAllFramesRGBNameD);
			lua::lua_setglobal(lState, "FillThresholdRGBColorsAllFramesRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdRGBColorsAllFramesRGBNameD = FillThresholdRGBColorsAllFramesRGBNameD");

			// FillThresholdRGBColorsRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdRGBColorsRGB);
			lua::lua_setglobal(lState, "FillThresholdRGBColorsRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdRGBColorsRGB = FillThresholdRGBColorsRGB");

			// FillThresholdRGBColorsRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdRGBColorsRGBName);
			lua::lua_setglobal(lState, "FillThresholdRGBColorsRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdRGBColorsRGBName = FillThresholdRGBColorsRGBName");

			// FillThresholdRGBColorsRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillThresholdRGBColorsRGBNameD);
			lua::lua_setglobal(lState, "FillThresholdRGBColorsRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillThresholdRGBColorsRGBNameD = FillThresholdRGBColorsRGBNameD");

			// FillZeroColor
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColor);
			lua::lua_setglobal(lState, "FillZeroColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColor = FillZeroColor");

			// FillZeroColorAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColorAllFrames);
			lua::lua_setglobal(lState, "FillZeroColorAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColorAllFrames = FillZeroColorAllFrames");

			// FillZeroColorAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColorAllFramesName);
			lua::lua_setglobal(lState, "FillZeroColorAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColorAllFramesName = FillZeroColorAllFramesName");

			// FillZeroColorAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColorAllFramesNameD);
			lua::lua_setglobal(lState, "FillZeroColorAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColorAllFramesNameD = FillZeroColorAllFramesNameD");

			// FillZeroColorAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColorAllFramesRGB);
			lua::lua_setglobal(lState, "FillZeroColorAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColorAllFramesRGB = FillZeroColorAllFramesRGB");

			// FillZeroColorAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColorAllFramesRGBName);
			lua::lua_setglobal(lState, "FillZeroColorAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColorAllFramesRGBName = FillZeroColorAllFramesRGBName");

			// FillZeroColorAllFramesRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColorAllFramesRGBNameD);
			lua::lua_setglobal(lState, "FillZeroColorAllFramesRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColorAllFramesRGBNameD = FillZeroColorAllFramesRGBNameD");

			// FillZeroColorName
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColorName);
			lua::lua_setglobal(lState, "FillZeroColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColorName = FillZeroColorName");

			// FillZeroColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColorNameD);
			lua::lua_setglobal(lState, "FillZeroColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColorNameD = FillZeroColorNameD");

			// FillZeroColorRGB
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColorRGB);
			lua::lua_setglobal(lState, "FillZeroColorRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColorRGB = FillZeroColorRGB");

			// FillZeroColorRGBName
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColorRGBName);
			lua::lua_setglobal(lState, "FillZeroColorRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColorRGBName = FillZeroColorRGBName");

			// FillZeroColorRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaFillZeroColorRGBNameD);
			lua::lua_setglobal(lState, "FillZeroColorRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.FillZeroColorRGBNameD = FillZeroColorRGBNameD");

			// Get1DColor
			lua::lua_pushcfunction(lState, Extension::LuaGet1DColor);
			lua::lua_setglobal(lState, "Get1DColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Get1DColor = Get1DColor");

			// Get1DColorName
			lua::lua_pushcfunction(lState, Extension::LuaGet1DColorName);
			lua::lua_setglobal(lState, "Get1DColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Get1DColorName = Get1DColorName");

			// Get1DColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaGet1DColorNameD);
			lua::lua_setglobal(lState, "Get1DColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Get1DColorNameD = Get1DColorNameD");

			// Get2DColor
			lua::lua_pushcfunction(lState, Extension::LuaGet2DColor);
			lua::lua_setglobal(lState, "Get2DColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Get2DColor = Get2DColor");

			// Get2DColorName
			lua::lua_pushcfunction(lState, Extension::LuaGet2DColorName);
			lua::lua_setglobal(lState, "Get2DColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Get2DColorName = Get2DColorName");

			// Get2DColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaGet2DColorNameD);
			lua::lua_setglobal(lState, "Get2DColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Get2DColorNameD = Get2DColorNameD");

			// GetAnimation
			lua::lua_pushcfunction(lState, Extension::LuaGetAnimation);
			lua::lua_setglobal(lState, "GetAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetAnimation = GetAnimation");

			// GetAnimationCount
			lua::lua_pushcfunction(lState, Extension::LuaGetAnimationCount);
			lua::lua_setglobal(lState, "GetAnimationCount");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetAnimationCount = GetAnimationCount");

			// GetAnimationD
			lua::lua_pushcfunction(lState, Extension::LuaGetAnimationD);
			lua::lua_setglobal(lState, "GetAnimationD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetAnimationD = GetAnimationD");

			// GetAnimationId
			lua::lua_pushcfunction(lState, Extension::LuaGetAnimationId);
			lua::lua_setglobal(lState, "GetAnimationId");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetAnimationId = GetAnimationId");

			// GetAnimationName
			lua::lua_pushcfunction(lState, Extension::LuaGetAnimationName);
			lua::lua_setglobal(lState, "GetAnimationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetAnimationName = GetAnimationName");

			// GetCurrentFrame
			lua::lua_pushcfunction(lState, Extension::LuaGetCurrentFrame);
			lua::lua_setglobal(lState, "GetCurrentFrame");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetCurrentFrame = GetCurrentFrame");

			// GetCurrentFrameName
			lua::lua_pushcfunction(lState, Extension::LuaGetCurrentFrameName);
			lua::lua_setglobal(lState, "GetCurrentFrameName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetCurrentFrameName = GetCurrentFrameName");

			// GetCurrentFrameNameD
			lua::lua_pushcfunction(lState, Extension::LuaGetCurrentFrameNameD);
			lua::lua_setglobal(lState, "GetCurrentFrameNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetCurrentFrameNameD = GetCurrentFrameNameD");

			// GetDevice
			lua::lua_pushcfunction(lState, Extension::LuaGetDevice);
			lua::lua_setglobal(lState, "GetDevice");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetDevice = GetDevice");

			// GetDeviceName
			lua::lua_pushcfunction(lState, Extension::LuaGetDeviceName);
			lua::lua_setglobal(lState, "GetDeviceName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetDeviceName = GetDeviceName");

			// GetDeviceNameD
			lua::lua_pushcfunction(lState, Extension::LuaGetDeviceNameD);
			lua::lua_setglobal(lState, "GetDeviceNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetDeviceNameD = GetDeviceNameD");

			// GetDeviceType
			lua::lua_pushcfunction(lState, Extension::LuaGetDeviceType);
			lua::lua_setglobal(lState, "GetDeviceType");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetDeviceType = GetDeviceType");

			// GetDeviceTypeName
			lua::lua_pushcfunction(lState, Extension::LuaGetDeviceTypeName);
			lua::lua_setglobal(lState, "GetDeviceTypeName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetDeviceTypeName = GetDeviceTypeName");

			// GetDeviceTypeNameD
			lua::lua_pushcfunction(lState, Extension::LuaGetDeviceTypeNameD);
			lua::lua_setglobal(lState, "GetDeviceTypeNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetDeviceTypeNameD = GetDeviceTypeNameD");

			// GetFrame
			lua::lua_pushcfunction(lState, Extension::LuaGetFrame);
			lua::lua_setglobal(lState, "GetFrame");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetFrame = GetFrame");

			// GetFrameCount
			lua::lua_pushcfunction(lState, Extension::LuaGetFrameCount);
			lua::lua_setglobal(lState, "GetFrameCount");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetFrameCount = GetFrameCount");

			// GetFrameCountName
			lua::lua_pushcfunction(lState, Extension::LuaGetFrameCountName);
			lua::lua_setglobal(lState, "GetFrameCountName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetFrameCountName = GetFrameCountName");

			// GetFrameCountNameD
			lua::lua_pushcfunction(lState, Extension::LuaGetFrameCountNameD);
			lua::lua_setglobal(lState, "GetFrameCountNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetFrameCountNameD = GetFrameCountNameD");

			// GetKeyColor
			lua::lua_pushcfunction(lState, Extension::LuaGetKeyColor);
			lua::lua_setglobal(lState, "GetKeyColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetKeyColor = GetKeyColor");

			// GetKeyColorD
			lua::lua_pushcfunction(lState, Extension::LuaGetKeyColorD);
			lua::lua_setglobal(lState, "GetKeyColorD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetKeyColorD = GetKeyColorD");

			// GetKeyColorName
			lua::lua_pushcfunction(lState, Extension::LuaGetKeyColorName);
			lua::lua_setglobal(lState, "GetKeyColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetKeyColorName = GetKeyColorName");

			// GetLibraryLoadedState
			lua::lua_pushcfunction(lState, Extension::LuaGetLibraryLoadedState);
			lua::lua_setglobal(lState, "GetLibraryLoadedState");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetLibraryLoadedState = GetLibraryLoadedState");

			// GetLibraryLoadedStateD
			lua::lua_pushcfunction(lState, Extension::LuaGetLibraryLoadedStateD);
			lua::lua_setglobal(lState, "GetLibraryLoadedStateD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetLibraryLoadedStateD = GetLibraryLoadedStateD");

			// GetMaxColumn
			lua::lua_pushcfunction(lState, Extension::LuaGetMaxColumn);
			lua::lua_setglobal(lState, "GetMaxColumn");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetMaxColumn = GetMaxColumn");

			// GetMaxColumnD
			lua::lua_pushcfunction(lState, Extension::LuaGetMaxColumnD);
			lua::lua_setglobal(lState, "GetMaxColumnD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetMaxColumnD = GetMaxColumnD");

			// GetMaxLeds
			lua::lua_pushcfunction(lState, Extension::LuaGetMaxLeds);
			lua::lua_setglobal(lState, "GetMaxLeds");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetMaxLeds = GetMaxLeds");

			// GetMaxLedsD
			lua::lua_pushcfunction(lState, Extension::LuaGetMaxLedsD);
			lua::lua_setglobal(lState, "GetMaxLedsD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetMaxLedsD = GetMaxLedsD");

			// GetMaxRow
			lua::lua_pushcfunction(lState, Extension::LuaGetMaxRow);
			lua::lua_setglobal(lState, "GetMaxRow");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetMaxRow = GetMaxRow");

			// GetMaxRowD
			lua::lua_pushcfunction(lState, Extension::LuaGetMaxRowD);
			lua::lua_setglobal(lState, "GetMaxRowD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetMaxRowD = GetMaxRowD");

			// GetPlayingAnimationCount
			lua::lua_pushcfunction(lState, Extension::LuaGetPlayingAnimationCount);
			lua::lua_setglobal(lState, "GetPlayingAnimationCount");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetPlayingAnimationCount = GetPlayingAnimationCount");

			// GetPlayingAnimationId
			lua::lua_pushcfunction(lState, Extension::LuaGetPlayingAnimationId);
			lua::lua_setglobal(lState, "GetPlayingAnimationId");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetPlayingAnimationId = GetPlayingAnimationId");

			// GetRGB
			lua::lua_pushcfunction(lState, Extension::LuaGetRGB);
			lua::lua_setglobal(lState, "GetRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetRGB = GetRGB");

			// GetRGBD
			lua::lua_pushcfunction(lState, Extension::LuaGetRGBD);
			lua::lua_setglobal(lState, "GetRGBD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.GetRGBD = GetRGBD");

			// HasAnimationLoop
			lua::lua_pushcfunction(lState, Extension::LuaHasAnimationLoop);
			lua::lua_setglobal(lState, "HasAnimationLoop");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.HasAnimationLoop = HasAnimationLoop");

			// HasAnimationLoopName
			lua::lua_pushcfunction(lState, Extension::LuaHasAnimationLoopName);
			lua::lua_setglobal(lState, "HasAnimationLoopName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.HasAnimationLoopName = HasAnimationLoopName");

			// HasAnimationLoopNameD
			lua::lua_pushcfunction(lState, Extension::LuaHasAnimationLoopNameD);
			lua::lua_setglobal(lState, "HasAnimationLoopNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.HasAnimationLoopNameD = HasAnimationLoopNameD");

			// Init
			lua::lua_pushcfunction(lState, Extension::LuaInit);
			lua::lua_setglobal(lState, "Init");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Init = Init");

			// InitD
			lua::lua_pushcfunction(lState, Extension::LuaInitD);
			lua::lua_setglobal(lState, "InitD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InitD = InitD");

			// InitSDK
			lua::lua_pushcfunction(lState, Extension::LuaInitSDK);
			lua::lua_setglobal(lState, "InitSDK");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InitSDK = InitSDK");

			// InsertDelay
			lua::lua_pushcfunction(lState, Extension::LuaInsertDelay);
			lua::lua_setglobal(lState, "InsertDelay");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InsertDelay = InsertDelay");

			// InsertDelayName
			lua::lua_pushcfunction(lState, Extension::LuaInsertDelayName);
			lua::lua_setglobal(lState, "InsertDelayName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InsertDelayName = InsertDelayName");

			// InsertDelayNameD
			lua::lua_pushcfunction(lState, Extension::LuaInsertDelayNameD);
			lua::lua_setglobal(lState, "InsertDelayNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InsertDelayNameD = InsertDelayNameD");

			// InsertFrame
			lua::lua_pushcfunction(lState, Extension::LuaInsertFrame);
			lua::lua_setglobal(lState, "InsertFrame");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InsertFrame = InsertFrame");

			// InsertFrameName
			lua::lua_pushcfunction(lState, Extension::LuaInsertFrameName);
			lua::lua_setglobal(lState, "InsertFrameName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InsertFrameName = InsertFrameName");

			// InsertFrameNameD
			lua::lua_pushcfunction(lState, Extension::LuaInsertFrameNameD);
			lua::lua_setglobal(lState, "InsertFrameNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InsertFrameNameD = InsertFrameNameD");

			// InvertColors
			lua::lua_pushcfunction(lState, Extension::LuaInvertColors);
			lua::lua_setglobal(lState, "InvertColors");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InvertColors = InvertColors");

			// InvertColorsAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaInvertColorsAllFrames);
			lua::lua_setglobal(lState, "InvertColorsAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InvertColorsAllFrames = InvertColorsAllFrames");

			// InvertColorsAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaInvertColorsAllFramesName);
			lua::lua_setglobal(lState, "InvertColorsAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InvertColorsAllFramesName = InvertColorsAllFramesName");

			// InvertColorsAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaInvertColorsAllFramesNameD);
			lua::lua_setglobal(lState, "InvertColorsAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InvertColorsAllFramesNameD = InvertColorsAllFramesNameD");

			// InvertColorsName
			lua::lua_pushcfunction(lState, Extension::LuaInvertColorsName);
			lua::lua_setglobal(lState, "InvertColorsName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InvertColorsName = InvertColorsName");

			// InvertColorsNameD
			lua::lua_pushcfunction(lState, Extension::LuaInvertColorsNameD);
			lua::lua_setglobal(lState, "InvertColorsNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.InvertColorsNameD = InvertColorsNameD");

			// IsAnimationPaused
			lua::lua_pushcfunction(lState, Extension::LuaIsAnimationPaused);
			lua::lua_setglobal(lState, "IsAnimationPaused");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsAnimationPaused = IsAnimationPaused");

			// IsAnimationPausedName
			lua::lua_pushcfunction(lState, Extension::LuaIsAnimationPausedName);
			lua::lua_setglobal(lState, "IsAnimationPausedName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsAnimationPausedName = IsAnimationPausedName");

			// IsAnimationPausedNameD
			lua::lua_pushcfunction(lState, Extension::LuaIsAnimationPausedNameD);
			lua::lua_setglobal(lState, "IsAnimationPausedNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsAnimationPausedNameD = IsAnimationPausedNameD");

			// IsDialogOpen
			lua::lua_pushcfunction(lState, Extension::LuaIsDialogOpen);
			lua::lua_setglobal(lState, "IsDialogOpen");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsDialogOpen = IsDialogOpen");

			// IsDialogOpenD
			lua::lua_pushcfunction(lState, Extension::LuaIsDialogOpenD);
			lua::lua_setglobal(lState, "IsDialogOpenD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsDialogOpenD = IsDialogOpenD");

			// IsInitialized
			lua::lua_pushcfunction(lState, Extension::LuaIsInitialized);
			lua::lua_setglobal(lState, "IsInitialized");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsInitialized = IsInitialized");

			// IsInitializedD
			lua::lua_pushcfunction(lState, Extension::LuaIsInitializedD);
			lua::lua_setglobal(lState, "IsInitializedD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsInitializedD = IsInitializedD");

			// IsPlatformSupported
			lua::lua_pushcfunction(lState, Extension::LuaIsPlatformSupported);
			lua::lua_setglobal(lState, "IsPlatformSupported");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsPlatformSupported = IsPlatformSupported");

			// IsPlatformSupportedD
			lua::lua_pushcfunction(lState, Extension::LuaIsPlatformSupportedD);
			lua::lua_setglobal(lState, "IsPlatformSupportedD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsPlatformSupportedD = IsPlatformSupportedD");

			// IsPlaying
			lua::lua_pushcfunction(lState, Extension::LuaIsPlaying);
			lua::lua_setglobal(lState, "IsPlaying");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsPlaying = IsPlaying");

			// IsPlayingD
			lua::lua_pushcfunction(lState, Extension::LuaIsPlayingD);
			lua::lua_setglobal(lState, "IsPlayingD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsPlayingD = IsPlayingD");

			// IsPlayingName
			lua::lua_pushcfunction(lState, Extension::LuaIsPlayingName);
			lua::lua_setglobal(lState, "IsPlayingName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsPlayingName = IsPlayingName");

			// IsPlayingNameD
			lua::lua_pushcfunction(lState, Extension::LuaIsPlayingNameD);
			lua::lua_setglobal(lState, "IsPlayingNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsPlayingNameD = IsPlayingNameD");

			// IsPlayingType
			lua::lua_pushcfunction(lState, Extension::LuaIsPlayingType);
			lua::lua_setglobal(lState, "IsPlayingType");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsPlayingType = IsPlayingType");

			// IsPlayingTypeD
			lua::lua_pushcfunction(lState, Extension::LuaIsPlayingTypeD);
			lua::lua_setglobal(lState, "IsPlayingTypeD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.IsPlayingTypeD = IsPlayingTypeD");

			// Lerp
			lua::lua_pushcfunction(lState, Extension::LuaLerp);
			lua::lua_setglobal(lState, "Lerp");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Lerp = Lerp");

			// LerpColor
			lua::lua_pushcfunction(lState, Extension::LuaLerpColor);
			lua::lua_setglobal(lState, "LerpColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.LerpColor = LerpColor");

			// LoadAnimation
			lua::lua_pushcfunction(lState, Extension::LuaLoadAnimation);
			lua::lua_setglobal(lState, "LoadAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.LoadAnimation = LoadAnimation");

			// LoadAnimationD
			lua::lua_pushcfunction(lState, Extension::LuaLoadAnimationD);
			lua::lua_setglobal(lState, "LoadAnimationD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.LoadAnimationD = LoadAnimationD");

			// LoadAnimationName
			lua::lua_pushcfunction(lState, Extension::LuaLoadAnimationName);
			lua::lua_setglobal(lState, "LoadAnimationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.LoadAnimationName = LoadAnimationName");

			// LoadComposite
			lua::lua_pushcfunction(lState, Extension::LuaLoadComposite);
			lua::lua_setglobal(lState, "LoadComposite");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.LoadComposite = LoadComposite");

			// MakeBlankFrames
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFrames);
			lua::lua_setglobal(lState, "MakeBlankFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFrames = MakeBlankFrames");

			// MakeBlankFramesName
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFramesName);
			lua::lua_setglobal(lState, "MakeBlankFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFramesName = MakeBlankFramesName");

			// MakeBlankFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFramesNameD);
			lua::lua_setglobal(lState, "MakeBlankFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFramesNameD = MakeBlankFramesNameD");

			// MakeBlankFramesRandom
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFramesRandom);
			lua::lua_setglobal(lState, "MakeBlankFramesRandom");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFramesRandom = MakeBlankFramesRandom");

			// MakeBlankFramesRandomBlackAndWhite
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFramesRandomBlackAndWhite);
			lua::lua_setglobal(lState, "MakeBlankFramesRandomBlackAndWhite");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFramesRandomBlackAndWhite = MakeBlankFramesRandomBlackAndWhite");

			// MakeBlankFramesRandomBlackAndWhiteName
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFramesRandomBlackAndWhiteName);
			lua::lua_setglobal(lState, "MakeBlankFramesRandomBlackAndWhiteName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFramesRandomBlackAndWhiteName = MakeBlankFramesRandomBlackAndWhiteName");

			// MakeBlankFramesRandomBlackAndWhiteNameD
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFramesRandomBlackAndWhiteNameD);
			lua::lua_setglobal(lState, "MakeBlankFramesRandomBlackAndWhiteNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFramesRandomBlackAndWhiteNameD = MakeBlankFramesRandomBlackAndWhiteNameD");

			// MakeBlankFramesRandomName
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFramesRandomName);
			lua::lua_setglobal(lState, "MakeBlankFramesRandomName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFramesRandomName = MakeBlankFramesRandomName");

			// MakeBlankFramesRandomNameD
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFramesRandomNameD);
			lua::lua_setglobal(lState, "MakeBlankFramesRandomNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFramesRandomNameD = MakeBlankFramesRandomNameD");

			// MakeBlankFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFramesRGB);
			lua::lua_setglobal(lState, "MakeBlankFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFramesRGB = MakeBlankFramesRGB");

			// MakeBlankFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFramesRGBName);
			lua::lua_setglobal(lState, "MakeBlankFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFramesRGBName = MakeBlankFramesRGBName");

			// MakeBlankFramesRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaMakeBlankFramesRGBNameD);
			lua::lua_setglobal(lState, "MakeBlankFramesRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MakeBlankFramesRGBNameD = MakeBlankFramesRGBNameD");

			// MirrorHorizontally
			lua::lua_pushcfunction(lState, Extension::LuaMirrorHorizontally);
			lua::lua_setglobal(lState, "MirrorHorizontally");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MirrorHorizontally = MirrorHorizontally");

			// MirrorVertically
			lua::lua_pushcfunction(lState, Extension::LuaMirrorVertically);
			lua::lua_setglobal(lState, "MirrorVertically");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MirrorVertically = MirrorVertically");

			// MultiplyColorLerpAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyColorLerpAllFrames);
			lua::lua_setglobal(lState, "MultiplyColorLerpAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyColorLerpAllFrames = MultiplyColorLerpAllFrames");

			// MultiplyColorLerpAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyColorLerpAllFramesName);
			lua::lua_setglobal(lState, "MultiplyColorLerpAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyColorLerpAllFramesName = MultiplyColorLerpAllFramesName");

			// MultiplyColorLerpAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyColorLerpAllFramesNameD);
			lua::lua_setglobal(lState, "MultiplyColorLerpAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyColorLerpAllFramesNameD = MultiplyColorLerpAllFramesNameD");

			// MultiplyIntensity
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensity);
			lua::lua_setglobal(lState, "MultiplyIntensity");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensity = MultiplyIntensity");

			// MultiplyIntensityAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityAllFrames);
			lua::lua_setglobal(lState, "MultiplyIntensityAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityAllFrames = MultiplyIntensityAllFrames");

			// MultiplyIntensityAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityAllFramesName);
			lua::lua_setglobal(lState, "MultiplyIntensityAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityAllFramesName = MultiplyIntensityAllFramesName");

			// MultiplyIntensityAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityAllFramesNameD);
			lua::lua_setglobal(lState, "MultiplyIntensityAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityAllFramesNameD = MultiplyIntensityAllFramesNameD");

			// MultiplyIntensityAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityAllFramesRGB);
			lua::lua_setglobal(lState, "MultiplyIntensityAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityAllFramesRGB = MultiplyIntensityAllFramesRGB");

			// MultiplyIntensityAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityAllFramesRGBName);
			lua::lua_setglobal(lState, "MultiplyIntensityAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityAllFramesRGBName = MultiplyIntensityAllFramesRGBName");

			// MultiplyIntensityAllFramesRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityAllFramesRGBNameD);
			lua::lua_setglobal(lState, "MultiplyIntensityAllFramesRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityAllFramesRGBNameD = MultiplyIntensityAllFramesRGBNameD");

			// MultiplyIntensityColor
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityColor);
			lua::lua_setglobal(lState, "MultiplyIntensityColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityColor = MultiplyIntensityColor");

			// MultiplyIntensityColorAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityColorAllFrames);
			lua::lua_setglobal(lState, "MultiplyIntensityColorAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityColorAllFrames = MultiplyIntensityColorAllFrames");

			// MultiplyIntensityColorAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityColorAllFramesName);
			lua::lua_setglobal(lState, "MultiplyIntensityColorAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityColorAllFramesName = MultiplyIntensityColorAllFramesName");

			// MultiplyIntensityColorAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityColorAllFramesNameD);
			lua::lua_setglobal(lState, "MultiplyIntensityColorAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityColorAllFramesNameD = MultiplyIntensityColorAllFramesNameD");

			// MultiplyIntensityColorName
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityColorName);
			lua::lua_setglobal(lState, "MultiplyIntensityColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityColorName = MultiplyIntensityColorName");

			// MultiplyIntensityColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityColorNameD);
			lua::lua_setglobal(lState, "MultiplyIntensityColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityColorNameD = MultiplyIntensityColorNameD");

			// MultiplyIntensityName
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityName);
			lua::lua_setglobal(lState, "MultiplyIntensityName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityName = MultiplyIntensityName");

			// MultiplyIntensityNameD
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityNameD);
			lua::lua_setglobal(lState, "MultiplyIntensityNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityNameD = MultiplyIntensityNameD");

			// MultiplyIntensityRGB
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityRGB);
			lua::lua_setglobal(lState, "MultiplyIntensityRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityRGB = MultiplyIntensityRGB");

			// MultiplyIntensityRGBName
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityRGBName);
			lua::lua_setglobal(lState, "MultiplyIntensityRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityRGBName = MultiplyIntensityRGBName");

			// MultiplyIntensityRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyIntensityRGBNameD);
			lua::lua_setglobal(lState, "MultiplyIntensityRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyIntensityRGBNameD = MultiplyIntensityRGBNameD");

			// MultiplyNonZeroTargetColorLerp
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyNonZeroTargetColorLerp);
			lua::lua_setglobal(lState, "MultiplyNonZeroTargetColorLerp");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyNonZeroTargetColorLerp = MultiplyNonZeroTargetColorLerp");

			// MultiplyNonZeroTargetColorLerpAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyNonZeroTargetColorLerpAllFrames);
			lua::lua_setglobal(lState, "MultiplyNonZeroTargetColorLerpAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyNonZeroTargetColorLerpAllFrames = MultiplyNonZeroTargetColorLerpAllFrames");

			// MultiplyNonZeroTargetColorLerpAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyNonZeroTargetColorLerpAllFramesName);
			lua::lua_setglobal(lState, "MultiplyNonZeroTargetColorLerpAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyNonZeroTargetColorLerpAllFramesName = MultiplyNonZeroTargetColorLerpAllFramesName");

			// MultiplyNonZeroTargetColorLerpAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyNonZeroTargetColorLerpAllFramesNameD);
			lua::lua_setglobal(lState, "MultiplyNonZeroTargetColorLerpAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyNonZeroTargetColorLerpAllFramesNameD = MultiplyNonZeroTargetColorLerpAllFramesNameD");

			// MultiplyNonZeroTargetColorLerpAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyNonZeroTargetColorLerpAllFramesRGB);
			lua::lua_setglobal(lState, "MultiplyNonZeroTargetColorLerpAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyNonZeroTargetColorLerpAllFramesRGB = MultiplyNonZeroTargetColorLerpAllFramesRGB");

			// MultiplyNonZeroTargetColorLerpAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyNonZeroTargetColorLerpAllFramesRGBName);
			lua::lua_setglobal(lState, "MultiplyNonZeroTargetColorLerpAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyNonZeroTargetColorLerpAllFramesRGBName = MultiplyNonZeroTargetColorLerpAllFramesRGBName");

			// MultiplyNonZeroTargetColorLerpAllFramesRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyNonZeroTargetColorLerpAllFramesRGBNameD);
			lua::lua_setglobal(lState, "MultiplyNonZeroTargetColorLerpAllFramesRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyNonZeroTargetColorLerpAllFramesRGBNameD = MultiplyNonZeroTargetColorLerpAllFramesRGBNameD");

			// MultiplyTargetColorLerp
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyTargetColorLerp);
			lua::lua_setglobal(lState, "MultiplyTargetColorLerp");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyTargetColorLerp = MultiplyTargetColorLerp");

			// MultiplyTargetColorLerpAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyTargetColorLerpAllFrames);
			lua::lua_setglobal(lState, "MultiplyTargetColorLerpAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyTargetColorLerpAllFrames = MultiplyTargetColorLerpAllFrames");

			// MultiplyTargetColorLerpAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyTargetColorLerpAllFramesName);
			lua::lua_setglobal(lState, "MultiplyTargetColorLerpAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyTargetColorLerpAllFramesName = MultiplyTargetColorLerpAllFramesName");

			// MultiplyTargetColorLerpAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyTargetColorLerpAllFramesNameD);
			lua::lua_setglobal(lState, "MultiplyTargetColorLerpAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyTargetColorLerpAllFramesNameD = MultiplyTargetColorLerpAllFramesNameD");

			// MultiplyTargetColorLerpAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyTargetColorLerpAllFramesRGB);
			lua::lua_setglobal(lState, "MultiplyTargetColorLerpAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyTargetColorLerpAllFramesRGB = MultiplyTargetColorLerpAllFramesRGB");

			// MultiplyTargetColorLerpAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyTargetColorLerpAllFramesRGBName);
			lua::lua_setglobal(lState, "MultiplyTargetColorLerpAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyTargetColorLerpAllFramesRGBName = MultiplyTargetColorLerpAllFramesRGBName");

			// MultiplyTargetColorLerpAllFramesRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaMultiplyTargetColorLerpAllFramesRGBNameD);
			lua::lua_setglobal(lState, "MultiplyTargetColorLerpAllFramesRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.MultiplyTargetColorLerpAllFramesRGBNameD = MultiplyTargetColorLerpAllFramesRGBNameD");

			// OffsetColors
			lua::lua_pushcfunction(lState, Extension::LuaOffsetColors);
			lua::lua_setglobal(lState, "OffsetColors");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetColors = OffsetColors");

			// OffsetColorsAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaOffsetColorsAllFrames);
			lua::lua_setglobal(lState, "OffsetColorsAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetColorsAllFrames = OffsetColorsAllFrames");

			// OffsetColorsAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaOffsetColorsAllFramesName);
			lua::lua_setglobal(lState, "OffsetColorsAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetColorsAllFramesName = OffsetColorsAllFramesName");

			// OffsetColorsAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaOffsetColorsAllFramesNameD);
			lua::lua_setglobal(lState, "OffsetColorsAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetColorsAllFramesNameD = OffsetColorsAllFramesNameD");

			// OffsetColorsName
			lua::lua_pushcfunction(lState, Extension::LuaOffsetColorsName);
			lua::lua_setglobal(lState, "OffsetColorsName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetColorsName = OffsetColorsName");

			// OffsetColorsNameD
			lua::lua_pushcfunction(lState, Extension::LuaOffsetColorsNameD);
			lua::lua_setglobal(lState, "OffsetColorsNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetColorsNameD = OffsetColorsNameD");

			// OffsetNonZeroColors
			lua::lua_pushcfunction(lState, Extension::LuaOffsetNonZeroColors);
			lua::lua_setglobal(lState, "OffsetNonZeroColors");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetNonZeroColors = OffsetNonZeroColors");

			// OffsetNonZeroColorsAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaOffsetNonZeroColorsAllFrames);
			lua::lua_setglobal(lState, "OffsetNonZeroColorsAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetNonZeroColorsAllFrames = OffsetNonZeroColorsAllFrames");

			// OffsetNonZeroColorsAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaOffsetNonZeroColorsAllFramesName);
			lua::lua_setglobal(lState, "OffsetNonZeroColorsAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetNonZeroColorsAllFramesName = OffsetNonZeroColorsAllFramesName");

			// OffsetNonZeroColorsAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaOffsetNonZeroColorsAllFramesNameD);
			lua::lua_setglobal(lState, "OffsetNonZeroColorsAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetNonZeroColorsAllFramesNameD = OffsetNonZeroColorsAllFramesNameD");

			// OffsetNonZeroColorsName
			lua::lua_pushcfunction(lState, Extension::LuaOffsetNonZeroColorsName);
			lua::lua_setglobal(lState, "OffsetNonZeroColorsName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetNonZeroColorsName = OffsetNonZeroColorsName");

			// OffsetNonZeroColorsNameD
			lua::lua_pushcfunction(lState, Extension::LuaOffsetNonZeroColorsNameD);
			lua::lua_setglobal(lState, "OffsetNonZeroColorsNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OffsetNonZeroColorsNameD = OffsetNonZeroColorsNameD");

			// OpenAnimation
			lua::lua_pushcfunction(lState, Extension::LuaOpenAnimation);
			lua::lua_setglobal(lState, "OpenAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OpenAnimation = OpenAnimation");

			// OpenAnimationD
			lua::lua_pushcfunction(lState, Extension::LuaOpenAnimationD);
			lua::lua_setglobal(lState, "OpenAnimationD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OpenAnimationD = OpenAnimationD");

			// OpenAnimationFromMemory
			lua::lua_pushcfunction(lState, Extension::LuaOpenAnimationFromMemory);
			lua::lua_setglobal(lState, "OpenAnimationFromMemory");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OpenAnimationFromMemory = OpenAnimationFromMemory");

			// OpenEditorDialog
			lua::lua_pushcfunction(lState, Extension::LuaOpenEditorDialog);
			lua::lua_setglobal(lState, "OpenEditorDialog");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OpenEditorDialog = OpenEditorDialog");

			// OpenEditorDialogAndPlay
			lua::lua_pushcfunction(lState, Extension::LuaOpenEditorDialogAndPlay);
			lua::lua_setglobal(lState, "OpenEditorDialogAndPlay");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OpenEditorDialogAndPlay = OpenEditorDialogAndPlay");

			// OpenEditorDialogAndPlayD
			lua::lua_pushcfunction(lState, Extension::LuaOpenEditorDialogAndPlayD);
			lua::lua_setglobal(lState, "OpenEditorDialogAndPlayD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OpenEditorDialogAndPlayD = OpenEditorDialogAndPlayD");

			// OpenEditorDialogD
			lua::lua_pushcfunction(lState, Extension::LuaOpenEditorDialogD);
			lua::lua_setglobal(lState, "OpenEditorDialogD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OpenEditorDialogD = OpenEditorDialogD");

			// OverrideFrameDuration
			lua::lua_pushcfunction(lState, Extension::LuaOverrideFrameDuration);
			lua::lua_setglobal(lState, "OverrideFrameDuration");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OverrideFrameDuration = OverrideFrameDuration");

			// OverrideFrameDurationD
			lua::lua_pushcfunction(lState, Extension::LuaOverrideFrameDurationD);
			lua::lua_setglobal(lState, "OverrideFrameDurationD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OverrideFrameDurationD = OverrideFrameDurationD");

			// OverrideFrameDurationName
			lua::lua_pushcfunction(lState, Extension::LuaOverrideFrameDurationName);
			lua::lua_setglobal(lState, "OverrideFrameDurationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.OverrideFrameDurationName = OverrideFrameDurationName");

			// PauseAnimation
			lua::lua_pushcfunction(lState, Extension::LuaPauseAnimation);
			lua::lua_setglobal(lState, "PauseAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PauseAnimation = PauseAnimation");

			// PauseAnimationName
			lua::lua_pushcfunction(lState, Extension::LuaPauseAnimationName);
			lua::lua_setglobal(lState, "PauseAnimationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PauseAnimationName = PauseAnimationName");

			// PauseAnimationNameD
			lua::lua_pushcfunction(lState, Extension::LuaPauseAnimationNameD);
			lua::lua_setglobal(lState, "PauseAnimationNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PauseAnimationNameD = PauseAnimationNameD");

			// PlayAnimation
			lua::lua_pushcfunction(lState, Extension::LuaPlayAnimation);
			lua::lua_setglobal(lState, "PlayAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PlayAnimation = PlayAnimation");

			// PlayAnimationD
			lua::lua_pushcfunction(lState, Extension::LuaPlayAnimationD);
			lua::lua_setglobal(lState, "PlayAnimationD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PlayAnimationD = PlayAnimationD");

			// PlayAnimationFrame
			lua::lua_pushcfunction(lState, Extension::LuaPlayAnimationFrame);
			lua::lua_setglobal(lState, "PlayAnimationFrame");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PlayAnimationFrame = PlayAnimationFrame");

			// PlayAnimationFrameName
			lua::lua_pushcfunction(lState, Extension::LuaPlayAnimationFrameName);
			lua::lua_setglobal(lState, "PlayAnimationFrameName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PlayAnimationFrameName = PlayAnimationFrameName");

			// PlayAnimationFrameNameD
			lua::lua_pushcfunction(lState, Extension::LuaPlayAnimationFrameNameD);
			lua::lua_setglobal(lState, "PlayAnimationFrameNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PlayAnimationFrameNameD = PlayAnimationFrameNameD");

			// PlayAnimationLoop
			lua::lua_pushcfunction(lState, Extension::LuaPlayAnimationLoop);
			lua::lua_setglobal(lState, "PlayAnimationLoop");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PlayAnimationLoop = PlayAnimationLoop");

			// PlayAnimationName
			lua::lua_pushcfunction(lState, Extension::LuaPlayAnimationName);
			lua::lua_setglobal(lState, "PlayAnimationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PlayAnimationName = PlayAnimationName");

			// PlayAnimationNameD
			lua::lua_pushcfunction(lState, Extension::LuaPlayAnimationNameD);
			lua::lua_setglobal(lState, "PlayAnimationNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PlayAnimationNameD = PlayAnimationNameD");

			// PlayComposite
			lua::lua_pushcfunction(lState, Extension::LuaPlayComposite);
			lua::lua_setglobal(lState, "PlayComposite");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PlayComposite = PlayComposite");

			// PlayCompositeD
			lua::lua_pushcfunction(lState, Extension::LuaPlayCompositeD);
			lua::lua_setglobal(lState, "PlayCompositeD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PlayCompositeD = PlayCompositeD");

			// PreviewFrame
			lua::lua_pushcfunction(lState, Extension::LuaPreviewFrame);
			lua::lua_setglobal(lState, "PreviewFrame");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PreviewFrame = PreviewFrame");

			// PreviewFrameD
			lua::lua_pushcfunction(lState, Extension::LuaPreviewFrameD);
			lua::lua_setglobal(lState, "PreviewFrameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PreviewFrameD = PreviewFrameD");

			// PreviewFrameName
			lua::lua_pushcfunction(lState, Extension::LuaPreviewFrameName);
			lua::lua_setglobal(lState, "PreviewFrameName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.PreviewFrameName = PreviewFrameName");

			// ReduceFrames
			lua::lua_pushcfunction(lState, Extension::LuaReduceFrames);
			lua::lua_setglobal(lState, "ReduceFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ReduceFrames = ReduceFrames");

			// ReduceFramesName
			lua::lua_pushcfunction(lState, Extension::LuaReduceFramesName);
			lua::lua_setglobal(lState, "ReduceFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ReduceFramesName = ReduceFramesName");

			// ReduceFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaReduceFramesNameD);
			lua::lua_setglobal(lState, "ReduceFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ReduceFramesNameD = ReduceFramesNameD");

			// ResetAnimation
			lua::lua_pushcfunction(lState, Extension::LuaResetAnimation);
			lua::lua_setglobal(lState, "ResetAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ResetAnimation = ResetAnimation");

			// ResumeAnimation
			lua::lua_pushcfunction(lState, Extension::LuaResumeAnimation);
			lua::lua_setglobal(lState, "ResumeAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ResumeAnimation = ResumeAnimation");

			// ResumeAnimationName
			lua::lua_pushcfunction(lState, Extension::LuaResumeAnimationName);
			lua::lua_setglobal(lState, "ResumeAnimationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ResumeAnimationName = ResumeAnimationName");

			// ResumeAnimationNameD
			lua::lua_pushcfunction(lState, Extension::LuaResumeAnimationNameD);
			lua::lua_setglobal(lState, "ResumeAnimationNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ResumeAnimationNameD = ResumeAnimationNameD");

			// Reverse
			lua::lua_pushcfunction(lState, Extension::LuaReverse);
			lua::lua_setglobal(lState, "Reverse");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Reverse = Reverse");

			// ReverseAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaReverseAllFrames);
			lua::lua_setglobal(lState, "ReverseAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ReverseAllFrames = ReverseAllFrames");

			// ReverseAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaReverseAllFramesName);
			lua::lua_setglobal(lState, "ReverseAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ReverseAllFramesName = ReverseAllFramesName");

			// ReverseAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaReverseAllFramesNameD);
			lua::lua_setglobal(lState, "ReverseAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.ReverseAllFramesNameD = ReverseAllFramesNameD");

			// SaveAnimation
			lua::lua_pushcfunction(lState, Extension::LuaSaveAnimation);
			lua::lua_setglobal(lState, "SaveAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SaveAnimation = SaveAnimation");

			// SaveAnimationName
			lua::lua_pushcfunction(lState, Extension::LuaSaveAnimationName);
			lua::lua_setglobal(lState, "SaveAnimationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SaveAnimationName = SaveAnimationName");

			// Set1DColor
			lua::lua_pushcfunction(lState, Extension::LuaSet1DColor);
			lua::lua_setglobal(lState, "Set1DColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Set1DColor = Set1DColor");

			// Set1DColorName
			lua::lua_pushcfunction(lState, Extension::LuaSet1DColorName);
			lua::lua_setglobal(lState, "Set1DColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Set1DColorName = Set1DColorName");

			// Set1DColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaSet1DColorNameD);
			lua::lua_setglobal(lState, "Set1DColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Set1DColorNameD = Set1DColorNameD");

			// Set2DColor
			lua::lua_pushcfunction(lState, Extension::LuaSet2DColor);
			lua::lua_setglobal(lState, "Set2DColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Set2DColor = Set2DColor");

			// Set2DColorName
			lua::lua_pushcfunction(lState, Extension::LuaSet2DColorName);
			lua::lua_setglobal(lState, "Set2DColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Set2DColorName = Set2DColorName");

			// Set2DColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaSet2DColorNameD);
			lua::lua_setglobal(lState, "Set2DColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Set2DColorNameD = Set2DColorNameD");

			// SetChromaCustomColorAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaSetChromaCustomColorAllFrames);
			lua::lua_setglobal(lState, "SetChromaCustomColorAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetChromaCustomColorAllFrames = SetChromaCustomColorAllFrames");

			// SetChromaCustomColorAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaSetChromaCustomColorAllFramesName);
			lua::lua_setglobal(lState, "SetChromaCustomColorAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetChromaCustomColorAllFramesName = SetChromaCustomColorAllFramesName");

			// SetChromaCustomColorAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaSetChromaCustomColorAllFramesNameD);
			lua::lua_setglobal(lState, "SetChromaCustomColorAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetChromaCustomColorAllFramesNameD = SetChromaCustomColorAllFramesNameD");

			// SetChromaCustomFlag
			lua::lua_pushcfunction(lState, Extension::LuaSetChromaCustomFlag);
			lua::lua_setglobal(lState, "SetChromaCustomFlag");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetChromaCustomFlag = SetChromaCustomFlag");

			// SetChromaCustomFlagName
			lua::lua_pushcfunction(lState, Extension::LuaSetChromaCustomFlagName);
			lua::lua_setglobal(lState, "SetChromaCustomFlagName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetChromaCustomFlagName = SetChromaCustomFlagName");

			// SetChromaCustomFlagNameD
			lua::lua_pushcfunction(lState, Extension::LuaSetChromaCustomFlagNameD);
			lua::lua_setglobal(lState, "SetChromaCustomFlagNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetChromaCustomFlagNameD = SetChromaCustomFlagNameD");

			// SetCurrentFrame
			lua::lua_pushcfunction(lState, Extension::LuaSetCurrentFrame);
			lua::lua_setglobal(lState, "SetCurrentFrame");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetCurrentFrame = SetCurrentFrame");

			// SetCurrentFrameName
			lua::lua_pushcfunction(lState, Extension::LuaSetCurrentFrameName);
			lua::lua_setglobal(lState, "SetCurrentFrameName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetCurrentFrameName = SetCurrentFrameName");

			// SetCurrentFrameNameD
			lua::lua_pushcfunction(lState, Extension::LuaSetCurrentFrameNameD);
			lua::lua_setglobal(lState, "SetCurrentFrameNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetCurrentFrameNameD = SetCurrentFrameNameD");

			// SetDevice
			lua::lua_pushcfunction(lState, Extension::LuaSetDevice);
			lua::lua_setglobal(lState, "SetDevice");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetDevice = SetDevice");

			// SetEffect
			lua::lua_pushcfunction(lState, Extension::LuaSetEffect);
			lua::lua_setglobal(lState, "SetEffect");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetEffect = SetEffect");

			// SetIdleAnimation
			lua::lua_pushcfunction(lState, Extension::LuaSetIdleAnimation);
			lua::lua_setglobal(lState, "SetIdleAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetIdleAnimation = SetIdleAnimation");

			// SetIdleAnimationName
			lua::lua_pushcfunction(lState, Extension::LuaSetIdleAnimationName);
			lua::lua_setglobal(lState, "SetIdleAnimationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetIdleAnimationName = SetIdleAnimationName");

			// SetKeyColor
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColor);
			lua::lua_setglobal(lState, "SetKeyColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColor = SetKeyColor");

			// SetKeyColorAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColorAllFrames);
			lua::lua_setglobal(lState, "SetKeyColorAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColorAllFrames = SetKeyColorAllFrames");

			// SetKeyColorAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColorAllFramesName);
			lua::lua_setglobal(lState, "SetKeyColorAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColorAllFramesName = SetKeyColorAllFramesName");

			// SetKeyColorAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColorAllFramesNameD);
			lua::lua_setglobal(lState, "SetKeyColorAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColorAllFramesNameD = SetKeyColorAllFramesNameD");

			// SetKeyColorAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColorAllFramesRGB);
			lua::lua_setglobal(lState, "SetKeyColorAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColorAllFramesRGB = SetKeyColorAllFramesRGB");

			// SetKeyColorAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColorAllFramesRGBName);
			lua::lua_setglobal(lState, "SetKeyColorAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColorAllFramesRGBName = SetKeyColorAllFramesRGBName");

			// SetKeyColorAllFramesRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColorAllFramesRGBNameD);
			lua::lua_setglobal(lState, "SetKeyColorAllFramesRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColorAllFramesRGBNameD = SetKeyColorAllFramesRGBNameD");

			// SetKeyColorName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColorName);
			lua::lua_setglobal(lState, "SetKeyColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColorName = SetKeyColorName");

			// SetKeyColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColorNameD);
			lua::lua_setglobal(lState, "SetKeyColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColorNameD = SetKeyColorNameD");

			// SetKeyColorRGB
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColorRGB);
			lua::lua_setglobal(lState, "SetKeyColorRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColorRGB = SetKeyColorRGB");

			// SetKeyColorRGBName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColorRGBName);
			lua::lua_setglobal(lState, "SetKeyColorRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColorRGBName = SetKeyColorRGBName");

			// SetKeyColorRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyColorRGBNameD);
			lua::lua_setglobal(lState, "SetKeyColorRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyColorRGBNameD = SetKeyColorRGBNameD");

			// SetKeyNonZeroColor
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyNonZeroColor);
			lua::lua_setglobal(lState, "SetKeyNonZeroColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyNonZeroColor = SetKeyNonZeroColor");

			// SetKeyNonZeroColorName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyNonZeroColorName);
			lua::lua_setglobal(lState, "SetKeyNonZeroColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyNonZeroColorName = SetKeyNonZeroColorName");

			// SetKeyNonZeroColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyNonZeroColorNameD);
			lua::lua_setglobal(lState, "SetKeyNonZeroColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyNonZeroColorNameD = SetKeyNonZeroColorNameD");

			// SetKeyNonZeroColorRGB
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyNonZeroColorRGB);
			lua::lua_setglobal(lState, "SetKeyNonZeroColorRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyNonZeroColorRGB = SetKeyNonZeroColorRGB");

			// SetKeyNonZeroColorRGBName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyNonZeroColorRGBName);
			lua::lua_setglobal(lState, "SetKeyNonZeroColorRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyNonZeroColorRGBName = SetKeyNonZeroColorRGBName");

			// SetKeyNonZeroColorRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyNonZeroColorRGBNameD);
			lua::lua_setglobal(lState, "SetKeyNonZeroColorRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyNonZeroColorRGBNameD = SetKeyNonZeroColorRGBNameD");

			// SetKeysColor
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysColor);
			lua::lua_setglobal(lState, "SetKeysColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysColor = SetKeysColor");

			// SetKeysColorAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysColorAllFrames);
			lua::lua_setglobal(lState, "SetKeysColorAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysColorAllFrames = SetKeysColorAllFrames");

			// SetKeysColorAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysColorAllFramesName);
			lua::lua_setglobal(lState, "SetKeysColorAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysColorAllFramesName = SetKeysColorAllFramesName");

			// SetKeysColorAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysColorAllFramesRGB);
			lua::lua_setglobal(lState, "SetKeysColorAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysColorAllFramesRGB = SetKeysColorAllFramesRGB");

			// SetKeysColorAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysColorAllFramesRGBName);
			lua::lua_setglobal(lState, "SetKeysColorAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysColorAllFramesRGBName = SetKeysColorAllFramesRGBName");

			// SetKeysColorName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysColorName);
			lua::lua_setglobal(lState, "SetKeysColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysColorName = SetKeysColorName");

			// SetKeysColorRGB
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysColorRGB);
			lua::lua_setglobal(lState, "SetKeysColorRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysColorRGB = SetKeysColorRGB");

			// SetKeysColorRGBName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysColorRGBName);
			lua::lua_setglobal(lState, "SetKeysColorRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysColorRGBName = SetKeysColorRGBName");

			// SetKeysNonZeroColor
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysNonZeroColor);
			lua::lua_setglobal(lState, "SetKeysNonZeroColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysNonZeroColor = SetKeysNonZeroColor");

			// SetKeysNonZeroColorAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysNonZeroColorAllFrames);
			lua::lua_setglobal(lState, "SetKeysNonZeroColorAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysNonZeroColorAllFrames = SetKeysNonZeroColorAllFrames");

			// SetKeysNonZeroColorAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysNonZeroColorAllFramesName);
			lua::lua_setglobal(lState, "SetKeysNonZeroColorAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysNonZeroColorAllFramesName = SetKeysNonZeroColorAllFramesName");

			// SetKeysNonZeroColorName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysNonZeroColorName);
			lua::lua_setglobal(lState, "SetKeysNonZeroColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysNonZeroColorName = SetKeysNonZeroColorName");

			// SetKeysNonZeroColorRGB
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysNonZeroColorRGB);
			lua::lua_setglobal(lState, "SetKeysNonZeroColorRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysNonZeroColorRGB = SetKeysNonZeroColorRGB");

			// SetKeysNonZeroColorRGBName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysNonZeroColorRGBName);
			lua::lua_setglobal(lState, "SetKeysNonZeroColorRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysNonZeroColorRGBName = SetKeysNonZeroColorRGBName");

			// SetKeysZeroColor
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysZeroColor);
			lua::lua_setglobal(lState, "SetKeysZeroColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysZeroColor = SetKeysZeroColor");

			// SetKeysZeroColorAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysZeroColorAllFrames);
			lua::lua_setglobal(lState, "SetKeysZeroColorAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysZeroColorAllFrames = SetKeysZeroColorAllFrames");

			// SetKeysZeroColorAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysZeroColorAllFramesName);
			lua::lua_setglobal(lState, "SetKeysZeroColorAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysZeroColorAllFramesName = SetKeysZeroColorAllFramesName");

			// SetKeysZeroColorAllFramesRGB
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysZeroColorAllFramesRGB);
			lua::lua_setglobal(lState, "SetKeysZeroColorAllFramesRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysZeroColorAllFramesRGB = SetKeysZeroColorAllFramesRGB");

			// SetKeysZeroColorAllFramesRGBName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysZeroColorAllFramesRGBName);
			lua::lua_setglobal(lState, "SetKeysZeroColorAllFramesRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysZeroColorAllFramesRGBName = SetKeysZeroColorAllFramesRGBName");

			// SetKeysZeroColorName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysZeroColorName);
			lua::lua_setglobal(lState, "SetKeysZeroColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysZeroColorName = SetKeysZeroColorName");

			// SetKeysZeroColorRGB
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysZeroColorRGB);
			lua::lua_setglobal(lState, "SetKeysZeroColorRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysZeroColorRGB = SetKeysZeroColorRGB");

			// SetKeysZeroColorRGBName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeysZeroColorRGBName);
			lua::lua_setglobal(lState, "SetKeysZeroColorRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeysZeroColorRGBName = SetKeysZeroColorRGBName");

			// SetKeyZeroColor
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyZeroColor);
			lua::lua_setglobal(lState, "SetKeyZeroColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyZeroColor = SetKeyZeroColor");

			// SetKeyZeroColorName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyZeroColorName);
			lua::lua_setglobal(lState, "SetKeyZeroColorName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyZeroColorName = SetKeyZeroColorName");

			// SetKeyZeroColorNameD
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyZeroColorNameD);
			lua::lua_setglobal(lState, "SetKeyZeroColorNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyZeroColorNameD = SetKeyZeroColorNameD");

			// SetKeyZeroColorRGB
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyZeroColorRGB);
			lua::lua_setglobal(lState, "SetKeyZeroColorRGB");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyZeroColorRGB = SetKeyZeroColorRGB");

			// SetKeyZeroColorRGBName
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyZeroColorRGBName);
			lua::lua_setglobal(lState, "SetKeyZeroColorRGBName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyZeroColorRGBName = SetKeyZeroColorRGBName");

			// SetKeyZeroColorRGBNameD
			lua::lua_pushcfunction(lState, Extension::LuaSetKeyZeroColorRGBNameD);
			lua::lua_setglobal(lState, "SetKeyZeroColorRGBNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetKeyZeroColorRGBNameD = SetKeyZeroColorRGBNameD");

			// SetLogDelegate
			lua::lua_pushcfunction(lState, Extension::LuaSetLogDelegate);
			lua::lua_setglobal(lState, "SetLogDelegate");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SetLogDelegate = SetLogDelegate");

			// StaticColor
			lua::lua_pushcfunction(lState, Extension::LuaStaticColor);
			lua::lua_setglobal(lState, "StaticColor");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.StaticColor = StaticColor");

			// StaticColorD
			lua::lua_pushcfunction(lState, Extension::LuaStaticColorD);
			lua::lua_setglobal(lState, "StaticColorD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.StaticColorD = StaticColorD");

			// StopAll
			lua::lua_pushcfunction(lState, Extension::LuaStopAll);
			lua::lua_setglobal(lState, "StopAll");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.StopAll = StopAll");

			// StopAnimation
			lua::lua_pushcfunction(lState, Extension::LuaStopAnimation);
			lua::lua_setglobal(lState, "StopAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.StopAnimation = StopAnimation");

			// StopAnimationD
			lua::lua_pushcfunction(lState, Extension::LuaStopAnimationD);
			lua::lua_setglobal(lState, "StopAnimationD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.StopAnimationD = StopAnimationD");

			// StopAnimationName
			lua::lua_pushcfunction(lState, Extension::LuaStopAnimationName);
			lua::lua_setglobal(lState, "StopAnimationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.StopAnimationName = StopAnimationName");

			// StopAnimationNameD
			lua::lua_pushcfunction(lState, Extension::LuaStopAnimationNameD);
			lua::lua_setglobal(lState, "StopAnimationNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.StopAnimationNameD = StopAnimationNameD");

			// StopAnimationType
			lua::lua_pushcfunction(lState, Extension::LuaStopAnimationType);
			lua::lua_setglobal(lState, "StopAnimationType");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.StopAnimationType = StopAnimationType");

			// StopAnimationTypeD
			lua::lua_pushcfunction(lState, Extension::LuaStopAnimationTypeD);
			lua::lua_setglobal(lState, "StopAnimationTypeD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.StopAnimationTypeD = StopAnimationTypeD");

			// StopComposite
			lua::lua_pushcfunction(lState, Extension::LuaStopComposite);
			lua::lua_setglobal(lState, "StopComposite");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.StopComposite = StopComposite");

			// StopCompositeD
			lua::lua_pushcfunction(lState, Extension::LuaStopCompositeD);
			lua::lua_setglobal(lState, "StopCompositeD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.StopCompositeD = StopCompositeD");

			// SubtractNonZeroAllKeysAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroAllKeysAllFrames);
			lua::lua_setglobal(lState, "SubtractNonZeroAllKeysAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroAllKeysAllFrames = SubtractNonZeroAllKeysAllFrames");

			// SubtractNonZeroAllKeysAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroAllKeysAllFramesName);
			lua::lua_setglobal(lState, "SubtractNonZeroAllKeysAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroAllKeysAllFramesName = SubtractNonZeroAllKeysAllFramesName");

			// SubtractNonZeroAllKeysAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroAllKeysAllFramesNameD);
			lua::lua_setglobal(lState, "SubtractNonZeroAllKeysAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroAllKeysAllFramesNameD = SubtractNonZeroAllKeysAllFramesNameD");

			// SubtractNonZeroAllKeysAllFramesOffset
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroAllKeysAllFramesOffset);
			lua::lua_setglobal(lState, "SubtractNonZeroAllKeysAllFramesOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroAllKeysAllFramesOffset = SubtractNonZeroAllKeysAllFramesOffset");

			// SubtractNonZeroAllKeysAllFramesOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroAllKeysAllFramesOffsetName);
			lua::lua_setglobal(lState, "SubtractNonZeroAllKeysAllFramesOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroAllKeysAllFramesOffsetName = SubtractNonZeroAllKeysAllFramesOffsetName");

			// SubtractNonZeroAllKeysAllFramesOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroAllKeysAllFramesOffsetNameD);
			lua::lua_setglobal(lState, "SubtractNonZeroAllKeysAllFramesOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroAllKeysAllFramesOffsetNameD = SubtractNonZeroAllKeysAllFramesOffsetNameD");

			// SubtractNonZeroAllKeysOffset
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroAllKeysOffset);
			lua::lua_setglobal(lState, "SubtractNonZeroAllKeysOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroAllKeysOffset = SubtractNonZeroAllKeysOffset");

			// SubtractNonZeroAllKeysOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroAllKeysOffsetName);
			lua::lua_setglobal(lState, "SubtractNonZeroAllKeysOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroAllKeysOffsetName = SubtractNonZeroAllKeysOffsetName");

			// SubtractNonZeroAllKeysOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroAllKeysOffsetNameD);
			lua::lua_setglobal(lState, "SubtractNonZeroAllKeysOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroAllKeysOffsetNameD = SubtractNonZeroAllKeysOffsetNameD");

			// SubtractNonZeroTargetAllKeysAllFrames
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroTargetAllKeysAllFrames);
			lua::lua_setglobal(lState, "SubtractNonZeroTargetAllKeysAllFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroTargetAllKeysAllFrames = SubtractNonZeroTargetAllKeysAllFrames");

			// SubtractNonZeroTargetAllKeysAllFramesName
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroTargetAllKeysAllFramesName);
			lua::lua_setglobal(lState, "SubtractNonZeroTargetAllKeysAllFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroTargetAllKeysAllFramesName = SubtractNonZeroTargetAllKeysAllFramesName");

			// SubtractNonZeroTargetAllKeysAllFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroTargetAllKeysAllFramesNameD);
			lua::lua_setglobal(lState, "SubtractNonZeroTargetAllKeysAllFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroTargetAllKeysAllFramesNameD = SubtractNonZeroTargetAllKeysAllFramesNameD");

			// SubtractNonZeroTargetAllKeysAllFramesOffset
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroTargetAllKeysAllFramesOffset);
			lua::lua_setglobal(lState, "SubtractNonZeroTargetAllKeysAllFramesOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroTargetAllKeysAllFramesOffset = SubtractNonZeroTargetAllKeysAllFramesOffset");

			// SubtractNonZeroTargetAllKeysAllFramesOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroTargetAllKeysAllFramesOffsetName);
			lua::lua_setglobal(lState, "SubtractNonZeroTargetAllKeysAllFramesOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroTargetAllKeysAllFramesOffsetName = SubtractNonZeroTargetAllKeysAllFramesOffsetName");

			// SubtractNonZeroTargetAllKeysAllFramesOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroTargetAllKeysAllFramesOffsetNameD);
			lua::lua_setglobal(lState, "SubtractNonZeroTargetAllKeysAllFramesOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroTargetAllKeysAllFramesOffsetNameD = SubtractNonZeroTargetAllKeysAllFramesOffsetNameD");

			// SubtractNonZeroTargetAllKeysOffset
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroTargetAllKeysOffset);
			lua::lua_setglobal(lState, "SubtractNonZeroTargetAllKeysOffset");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroTargetAllKeysOffset = SubtractNonZeroTargetAllKeysOffset");

			// SubtractNonZeroTargetAllKeysOffsetName
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroTargetAllKeysOffsetName);
			lua::lua_setglobal(lState, "SubtractNonZeroTargetAllKeysOffsetName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroTargetAllKeysOffsetName = SubtractNonZeroTargetAllKeysOffsetName");

			// SubtractNonZeroTargetAllKeysOffsetNameD
			lua::lua_pushcfunction(lState, Extension::LuaSubtractNonZeroTargetAllKeysOffsetNameD);
			lua::lua_setglobal(lState, "SubtractNonZeroTargetAllKeysOffsetNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.SubtractNonZeroTargetAllKeysOffsetNameD = SubtractNonZeroTargetAllKeysOffsetNameD");

			// TrimEndFrames
			lua::lua_pushcfunction(lState, Extension::LuaTrimEndFrames);
			lua::lua_setglobal(lState, "TrimEndFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.TrimEndFrames = TrimEndFrames");

			// TrimEndFramesName
			lua::lua_pushcfunction(lState, Extension::LuaTrimEndFramesName);
			lua::lua_setglobal(lState, "TrimEndFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.TrimEndFramesName = TrimEndFramesName");

			// TrimEndFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaTrimEndFramesNameD);
			lua::lua_setglobal(lState, "TrimEndFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.TrimEndFramesNameD = TrimEndFramesNameD");

			// TrimFrame
			lua::lua_pushcfunction(lState, Extension::LuaTrimFrame);
			lua::lua_setglobal(lState, "TrimFrame");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.TrimFrame = TrimFrame");

			// TrimFrameName
			lua::lua_pushcfunction(lState, Extension::LuaTrimFrameName);
			lua::lua_setglobal(lState, "TrimFrameName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.TrimFrameName = TrimFrameName");

			// TrimFrameNameD
			lua::lua_pushcfunction(lState, Extension::LuaTrimFrameNameD);
			lua::lua_setglobal(lState, "TrimFrameNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.TrimFrameNameD = TrimFrameNameD");

			// TrimStartFrames
			lua::lua_pushcfunction(lState, Extension::LuaTrimStartFrames);
			lua::lua_setglobal(lState, "TrimStartFrames");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.TrimStartFrames = TrimStartFrames");

			// TrimStartFramesName
			lua::lua_pushcfunction(lState, Extension::LuaTrimStartFramesName);
			lua::lua_setglobal(lState, "TrimStartFramesName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.TrimStartFramesName = TrimStartFramesName");

			// TrimStartFramesNameD
			lua::lua_pushcfunction(lState, Extension::LuaTrimStartFramesNameD);
			lua::lua_setglobal(lState, "TrimStartFramesNameD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.TrimStartFramesNameD = TrimStartFramesNameD");

			// Uninit
			lua::lua_pushcfunction(lState, Extension::LuaUninit);
			lua::lua_setglobal(lState, "Uninit");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.Uninit = Uninit");

			// UninitD
			lua::lua_pushcfunction(lState, Extension::LuaUninitD);
			lua::lua_setglobal(lState, "UninitD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.UninitD = UninitD");

			// UnloadAnimation
			lua::lua_pushcfunction(lState, Extension::LuaUnloadAnimation);
			lua::lua_setglobal(lState, "UnloadAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.UnloadAnimation = UnloadAnimation");

			// UnloadAnimationD
			lua::lua_pushcfunction(lState, Extension::LuaUnloadAnimationD);
			lua::lua_setglobal(lState, "UnloadAnimationD");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.UnloadAnimationD = UnloadAnimationD");

			// UnloadAnimationName
			lua::lua_pushcfunction(lState, Extension::LuaUnloadAnimationName);
			lua::lua_setglobal(lState, "UnloadAnimationName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.UnloadAnimationName = UnloadAnimationName");

			// UnloadComposite
			lua::lua_pushcfunction(lState, Extension::LuaUnloadComposite);
			lua::lua_setglobal(lState, "UnloadComposite");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.UnloadComposite = UnloadComposite");

			// UpdateFrame
			lua::lua_pushcfunction(lState, Extension::LuaUpdateFrame);
			lua::lua_setglobal(lState, "UpdateFrame");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.UpdateFrame = UpdateFrame");

			// UseIdleAnimation
			lua::lua_pushcfunction(lState, Extension::LuaUseIdleAnimation);
			lua::lua_setglobal(lState, "UseIdleAnimation");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.UseIdleAnimation = UseIdleAnimation");

			// UseIdleAnimations
			lua::lua_pushcfunction(lState, Extension::LuaUseIdleAnimations);
			lua::lua_setglobal(lState, "UseIdleAnimations");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.UseIdleAnimations = UseIdleAnimations");

			// UsePreloading
			lua::lua_pushcfunction(lState, Extension::LuaUsePreloading);
			lua::lua_setglobal(lState, "UsePreloading");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.UsePreloading = UsePreloading");

			// UsePreloadingName
			lua::lua_pushcfunction(lState, Extension::LuaUsePreloadingName);
			lua::lua_setglobal(lState, "UsePreloadingName");
			WrapperXLuaState::LoadString(xState, "ChromaAnimationAPI.UsePreloadingName = UsePreloadingName");

#pragma endregion
		}
	}
}

int Extension::LuaDebugPrint(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string message = WrapperXLua::lua_tostringW(state, 1);
		OutputDebugStringA(message.c_str());
		OutputDebugStringA("\r\n");
		return 0;
	}
	else
	{
		return -1;
	}
}

namespace lua
{
	static const luaL_Reg lualibs[] = {
		{"", luaopen_base},
		{LUA_LOADLIBNAME, luaopen_package},
		{LUA_TABLIBNAME, luaopen_table},
		{LUA_IOLIBNAME, luaopen_io},
		{LUA_OSLIBNAME, luaopen_os},
		{LUA_STRLIBNAME, luaopen_string},
		{LUA_MATHLIBNAME, luaopen_math},
		{LUA_DBLIBNAME, luaopen_debug},
		{LUA_JITLIBNAME, luaopen_jit},
		{LUA_BITLIBNAME, luaopen_bit},
		{NULL, NULL}
	};
}

int Extension::LuaLoadLibs(lua::lua_State* lState)
{
	if (lState)
	{
		// Register lua libs
		const lua::luaL_Reg* lib = lua::lualibs;
		for (; lib->func; lib++) {
			lua::lua_pushcfunction(lState, lib->func);
			lua::lua_pushstring(lState, lib->name);
			lua::lua_call(lState, 1, 0);
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

#pragma region Autogenerated lua C functions
/*
	Adds a frame to the `Chroma` animation and sets the `duration` (in seconds).
	The `color` is expected to be an array of the dimensions for the `deviceType/device`.
	The `length` parameter is the size of the `color` array. For `EChromaSDKDevice1DEnum`
	the array size should be `MAX LEDS`. For `EChromaSDKDevice2DEnum` the array
	size should be `MAX ROW` * `MAX COLUMN`. Returns the animation id upon
	success. Returns -1 upon failure.
*/
int Extension::LuaAddFrame(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: float
		// FieldName: duration
		// FieldType: int*
		// FieldName: colors
		// FieldType: int
		// FieldName: length
#pragma message("TODO - add support for AddFrame")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where color is not black for all frames, reference
	source and target by id.
*/
int Extension::LuaAddNonZeroAllKeysAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::AddNonZeroAllKeysAllFrames(sourceAnimationId, targetAnimationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where color is not black for all frames, reference
	source and target by name.
*/
int Extension::LuaAddNonZeroAllKeysAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		ChromaAnimationAPI::AddNonZeroAllKeysAllFramesName(sourceAnimation.c_str(), targetAnimation.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaAddNonZeroAllKeysAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		double result = ChromaAnimationAPI::AddNonZeroAllKeysAllFramesNameD(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where color is not black for all frames starting
	at offset for the length of the source, reference source and target by
	id.
*/
int Extension::LuaAddNonZeroAllKeysAllFramesOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::AddNonZeroAllKeysAllFramesOffset(sourceAnimationId, targetAnimationId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where color is not black for all frames starting
	at offset for the length of the source, reference source and target by
	name.
*/
int Extension::LuaAddNonZeroAllKeysAllFramesOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::AddNonZeroAllKeysAllFramesOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaAddNonZeroAllKeysAllFramesOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::AddNonZeroAllKeysAllFramesOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where color is not black for the source frame
	and target offset frame, reference source and target by id.
*/
int Extension::LuaAddNonZeroAllKeysOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::AddNonZeroAllKeysOffset(sourceAnimationId, targetAnimationId, frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where color is not black for the source frame
	and target offset frame, reference source and target by name.
*/
int Extension::LuaAddNonZeroAllKeysOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::AddNonZeroAllKeysOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaAddNonZeroAllKeysOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::AddNonZeroAllKeysOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where the target color is not black for all frames,
	reference source and target by id.
*/
int Extension::LuaAddNonZeroTargetAllKeysAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::AddNonZeroTargetAllKeysAllFrames(sourceAnimationId, targetAnimationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where the target color is not black for all frames,
	reference source and target by name.
*/
int Extension::LuaAddNonZeroTargetAllKeysAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		ChromaAnimationAPI::AddNonZeroTargetAllKeysAllFramesName(sourceAnimation.c_str(), targetAnimation.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaAddNonZeroTargetAllKeysAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		double result = ChromaAnimationAPI::AddNonZeroTargetAllKeysAllFramesNameD(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where the target color is not black for all frames
	starting at offset for the length of the source, reference source and target
	by id.
*/
int Extension::LuaAddNonZeroTargetAllKeysAllFramesOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::AddNonZeroTargetAllKeysAllFramesOffset(sourceAnimationId, targetAnimationId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where the target color is not black for all frames
	starting at offset for the length of the source, reference source and target
	by name.
*/
int Extension::LuaAddNonZeroTargetAllKeysAllFramesOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::AddNonZeroTargetAllKeysAllFramesOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaAddNonZeroTargetAllKeysAllFramesOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::AddNonZeroTargetAllKeysAllFramesOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where target color is not blank from the source
	frame to the target offset frame, reference source and target by id.
*/
int Extension::LuaAddNonZeroTargetAllKeysOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::AddNonZeroTargetAllKeysOffset(sourceAnimationId, targetAnimationId, frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Add source color to target where target color is not blank from the source
	frame to the target offset frame, reference source and target by name.
*/
int Extension::LuaAddNonZeroTargetAllKeysOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::AddNonZeroTargetAllKeysOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaAddNonZeroTargetAllKeysOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::AddNonZeroTargetAllKeysOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Append all source frames to the target animation, reference source and target
	by id.
*/
int Extension::LuaAppendAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::AppendAllFrames(sourceAnimationId, targetAnimationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Append all source frames to the target animation, reference source and target
	by name.
*/
int Extension::LuaAppendAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		ChromaAnimationAPI::AppendAllFramesName(sourceAnimation.c_str(), targetAnimation.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaAppendAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		double result = ChromaAnimationAPI::AppendAllFramesNameD(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginClearAll` will issue a `CLEAR` effect for all devices.
*/
int Extension::LuaClearAll(lua::lua_State* state)
{
	if (state)
	{
		ChromaAnimationAPI::ClearAll();
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginClearAnimationType` will issue a `CLEAR` effect for the given device.
*/
int Extension::LuaClearAnimationType(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int deviceType = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int device = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::ClearAnimationType(deviceType, device);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginCloseAll` closes all open animations so they can be reloaded from
	disk. The set of animations will be stopped if playing.
*/
int Extension::LuaCloseAll(lua::lua_State* state)
{
	if (state)
	{
		ChromaAnimationAPI::CloseAll();
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Closes the `Chroma` animation to free up resources referenced by id. Returns
	the animation id upon success. Returns -1 upon failure. This might be used
	while authoring effects if there was a change necessitating re-opening
	the animation. The animation id can no longer be used once closed.
*/
int Extension::LuaCloseAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::CloseAnimation(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCloseAnimationD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double animationId = WrapperXLua::lua_tonumberW(state, 1);
		double result = ChromaAnimationAPI::CloseAnimationD(animationId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Closes the `Chroma` animation referenced by name so that the animation can
	be reloaded from disk.
*/
int Extension::LuaCloseAnimationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::CloseAnimationName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCloseAnimationNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::CloseAnimationNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginCloseComposite` closes a set of animations so they can be reloaded
	from disk. The set of animations will be stopped if playing.
*/
int Extension::LuaCloseComposite(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string name = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::CloseComposite(name.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCloseCompositeD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string name = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::CloseCompositeD(name.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation to named target animation in memory. If target animation
	exists, close first. Source is referenced by id.
*/
int Extension::LuaCopyAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		int result = ChromaAnimationAPI::CopyAnimation(sourceAnimationId, targetAnimation.c_str());
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation to named target animation in memory. If target animation
	exists, close first. Source is referenced by name.
*/
int Extension::LuaCopyAnimationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		ChromaAnimationAPI::CopyAnimationName(sourceAnimation.c_str(), targetAnimation.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyAnimationNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		double result = ChromaAnimationAPI::CopyAnimationNameD(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy blue channel to other channels for all frames. Intensity range is 0.0
	to 1.0. Reference the animation by id.
*/
int Extension::LuaCopyBlueChannelAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		float redIntensity = (float)WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float greenIntensity = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::CopyBlueChannelAllFrames(animationId, redIntensity, greenIntensity);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy blue channel to other channels for all frames. Intensity range is 0.0
	to 1.0. Reference the animation by name.
*/
int Extension::LuaCopyBlueChannelAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		float redIntensity = (float)WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float greenIntensity = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::CopyBlueChannelAllFramesName(path.c_str(), redIntensity, greenIntensity);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyBlueChannelAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double redIntensity = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double greenIntensity = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::CopyBlueChannelAllFramesNameD(path.c_str(), redIntensity, greenIntensity);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy green channel to other channels for all frames. Intensity range is
	0.0 to 1.0. Reference the animation by id.
*/
int Extension::LuaCopyGreenChannelAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		float redIntensity = (float)WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float blueIntensity = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::CopyGreenChannelAllFrames(animationId, redIntensity, blueIntensity);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy green channel to other channels for all frames. Intensity range is
	0.0 to 1.0. Reference the animation by name.
*/
int Extension::LuaCopyGreenChannelAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		float redIntensity = (float)WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float blueIntensity = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::CopyGreenChannelAllFramesName(path.c_str(), redIntensity, blueIntensity);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyGreenChannelAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double redIntensity = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double blueIntensity = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::CopyGreenChannelAllFramesNameD(path.c_str(), redIntensity, blueIntensity);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation key color from the source animation to the target animation
	for the given frame. Reference the source and target by id.
*/
int Extension::LuaCopyKeyColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyKeyColor(sourceAnimationId, targetAnimationId, frameId, rzkey);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation key color from the source animation to the target animation
	for all frames. Reference the source and target by id.
*/
int Extension::LuaCopyKeyColorAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyKeyColorAllFrames(sourceAnimationId, targetAnimationId, rzkey);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation key color from the source animation to the target animation
	for all frames. Reference the source and target by name.
*/
int Extension::LuaCopyKeyColorAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyKeyColorAllFramesName(sourceAnimation.c_str(), targetAnimation.c_str(), rzkey);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyKeyColorAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::CopyKeyColorAllFramesNameD(sourceAnimation.c_str(), targetAnimation.c_str(), rzkey);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation key color from the source animation to the target animation
	for all frames, starting at the offset for the length of the source animation.
	Source and target are referenced by id.
*/
int Extension::LuaCopyKeyColorAllFramesOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyKeyColorAllFramesOffset(sourceAnimationId, targetAnimationId, rzkey, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation key color from the source animation to the target animation
	for all frames, starting at the offset for the length of the source animation.
	Source and target are referenced by name.
*/
int Extension::LuaCopyKeyColorAllFramesOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyKeyColorAllFramesOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), rzkey, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyKeyColorAllFramesOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::CopyKeyColorAllFramesOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), rzkey, offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation key color from the source animation to the target animation
	for the given frame.
*/
int Extension::LuaCopyKeyColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyKeyColorName(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, rzkey);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyKeyColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::CopyKeyColorNameD(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, rzkey);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation color for a set of keys from the source animation to the
	target animation for the given frame. Reference the source and target by
	id.
*/
int Extension::LuaCopyKeysColor(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: sourceAnimationId
		// FieldType: int
		// FieldName: targetAnimationId
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: keys
		// FieldType: int
		// FieldName: size
#pragma message("TODO - add support for CopyKeysColor")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation color for a set of keys from the source animation to the
	target animation for all frames. Reference the source and target by id.
*/
int Extension::LuaCopyKeysColorAllFrames(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: sourceAnimationId
		// FieldType: int
		// FieldName: targetAnimationId
		// FieldType: const int*
		// FieldName: keys
		// FieldType: int
		// FieldName: size
#pragma message("TODO - add support for CopyKeysColorAllFrames")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation color for a set of keys from the source animation to the
	target animation for all frames. Reference the source and target by name.
*/
int Extension::LuaCopyKeysColorAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: sourceAnimation
		// FieldType: const char*
		// FieldName: targetAnimation
		// FieldType: const int*
		// FieldName: keys
		// FieldType: int
		// FieldName: size
#pragma message("TODO - add support for CopyKeysColorAllFramesName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation color for a set of keys from the source animation to the
	target animation for the given frame. Reference the source and target by
	name.
*/
int Extension::LuaCopyKeysColorName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: sourceAnimation
		// FieldType: const char*
		// FieldName: targetAnimation
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: keys
		// FieldType: int
		// FieldName: size
#pragma message("TODO - add support for CopyKeysColorName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation color for a set of keys from the source animation to the
	target animation from the source frame to the target frame. Reference the
	source and target by id.
*/
int Extension::LuaCopyKeysColorOffset(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: sourceAnimationId
		// FieldType: int
		// FieldName: targetAnimationId
		// FieldType: int
		// FieldName: sourceFrameId
		// FieldType: int
		// FieldName: targetFrameId
		// FieldType: const int*
		// FieldName: keys
		// FieldType: int
		// FieldName: size
#pragma message("TODO - add support for CopyKeysColorOffset")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation color for a set of keys from the source animation to the
	target animation from the source frame to the target frame. Reference the
	source and target by name.
*/
int Extension::LuaCopyKeysColorOffsetName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: sourceAnimation
		// FieldType: const char*
		// FieldName: targetAnimation
		// FieldType: int
		// FieldName: sourceFrameId
		// FieldType: int
		// FieldName: targetFrameId
		// FieldType: const int*
		// FieldName: keys
		// FieldType: int
		// FieldName: size
#pragma message("TODO - add support for CopyKeysColorOffsetName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy source animation to target animation for the given frame. Source and
	target are referenced by id.
*/
int Extension::LuaCopyNonZeroAllKeys(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyNonZeroAllKeys(sourceAnimationId, targetAnimationId, frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from a source animation to a target animation for all
	frames. Reference source and target by id.
*/
int Extension::LuaCopyNonZeroAllKeysAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::CopyNonZeroAllKeysAllFrames(sourceAnimationId, targetAnimationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from a source animation to a target animation for all
	frames. Reference source and target by name.
*/
int Extension::LuaCopyNonZeroAllKeysAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		ChromaAnimationAPI::CopyNonZeroAllKeysAllFramesName(sourceAnimation.c_str(), targetAnimation.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyNonZeroAllKeysAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		double result = ChromaAnimationAPI::CopyNonZeroAllKeysAllFramesNameD(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from a source animation to a target animation for all
	frames starting at the offset for the length of the source animation. The
	source and target are referenced by id.
*/
int Extension::LuaCopyNonZeroAllKeysAllFramesOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyNonZeroAllKeysAllFramesOffset(sourceAnimationId, targetAnimationId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from a source animation to a target animation for all
	frames starting at the offset for the length of the source animation. The
	source and target are referenced by name.
*/
int Extension::LuaCopyNonZeroAllKeysAllFramesOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyNonZeroAllKeysAllFramesOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyNonZeroAllKeysAllFramesOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::CopyNonZeroAllKeysAllFramesOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from source animation to target animation for the specified
	frame. Source and target are referenced by id.
*/
int Extension::LuaCopyNonZeroAllKeysName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyNonZeroAllKeysName(sourceAnimation.c_str(), targetAnimation.c_str(), frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyNonZeroAllKeysNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::CopyNonZeroAllKeysNameD(sourceAnimation.c_str(), targetAnimation.c_str(), frameId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation from
	the source frame to the target offset frame. Source and target are referenced
	by id.
*/
int Extension::LuaCopyNonZeroAllKeysOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyNonZeroAllKeysOffset(sourceAnimationId, targetAnimationId, frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation from
	the source frame to the target offset frame. Source and target are referenced
	by name.
*/
int Extension::LuaCopyNonZeroAllKeysOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyNonZeroAllKeysOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyNonZeroAllKeysOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::CopyNonZeroAllKeysOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation key color from the source animation to the target animation
	for the given frame where color is not zero.
*/
int Extension::LuaCopyNonZeroKeyColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyNonZeroKeyColor(sourceAnimationId, targetAnimationId, frameId, rzkey);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy animation key color from the source animation to the target animation
	for the given frame where color is not zero.
*/
int Extension::LuaCopyNonZeroKeyColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyNonZeroKeyColorName(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, rzkey);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyNonZeroKeyColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::CopyNonZeroKeyColorNameD(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, rzkey);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for the specified frame. Source and target
	are referenced by id.
*/
int Extension::LuaCopyNonZeroTargetAllKeys(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyNonZeroTargetAllKeys(sourceAnimationId, targetAnimationId, frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for all frames. Source and target are referenced
	by id.
*/
int Extension::LuaCopyNonZeroTargetAllKeysAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::CopyNonZeroTargetAllKeysAllFrames(sourceAnimationId, targetAnimationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for all frames. Source and target are referenced
	by name.
*/
int Extension::LuaCopyNonZeroTargetAllKeysAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		ChromaAnimationAPI::CopyNonZeroTargetAllKeysAllFramesName(sourceAnimation.c_str(), targetAnimation.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyNonZeroTargetAllKeysAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		double result = ChromaAnimationAPI::CopyNonZeroTargetAllKeysAllFramesNameD(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for all frames. Source and target are referenced
	by name.
*/
int Extension::LuaCopyNonZeroTargetAllKeysAllFramesOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyNonZeroTargetAllKeysAllFramesOffset(sourceAnimationId, targetAnimationId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for all frames starting at the target offset
	for the length of the source animation. Source and target animations are
	referenced by name.
*/
int Extension::LuaCopyNonZeroTargetAllKeysAllFramesOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyNonZeroTargetAllKeysAllFramesOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyNonZeroTargetAllKeysAllFramesOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::CopyNonZeroTargetAllKeysAllFramesOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for the specified frame. The source and target
	are referenced by name.
*/
int Extension::LuaCopyNonZeroTargetAllKeysName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyNonZeroTargetAllKeysName(sourceAnimation.c_str(), targetAnimation.c_str(), frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyNonZeroTargetAllKeysNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::CopyNonZeroTargetAllKeysNameD(sourceAnimation.c_str(), targetAnimation.c_str(), frameId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for the specified source frame and target offset
	frame. The source and target are referenced by id.
*/
int Extension::LuaCopyNonZeroTargetAllKeysOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyNonZeroTargetAllKeysOffset(sourceAnimationId, targetAnimationId, frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is nonzero for the specified source frame and target offset
	frame. The source and target are referenced by name.
*/
int Extension::LuaCopyNonZeroTargetAllKeysOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyNonZeroTargetAllKeysOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyNonZeroTargetAllKeysOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::CopyNonZeroTargetAllKeysOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is zero for all frames. Source and target are referenced
	by id.
*/
int Extension::LuaCopyNonZeroTargetZeroAllKeysAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::CopyNonZeroTargetZeroAllKeysAllFrames(sourceAnimationId, targetAnimationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero colors from the source animation to the target animation where
	the target color is zero for all frames. Source and target are referenced
	by name.
*/
int Extension::LuaCopyNonZeroTargetZeroAllKeysAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		ChromaAnimationAPI::CopyNonZeroTargetZeroAllKeysAllFramesName(sourceAnimation.c_str(), targetAnimation.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyNonZeroTargetZeroAllKeysAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		double result = ChromaAnimationAPI::CopyNonZeroTargetZeroAllKeysAllFramesNameD(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy red channel to other channels for all frames. Intensity range is 0.0
	to 1.0. Reference the animation by id.
*/
int Extension::LuaCopyRedChannelAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		float greenIntensity = (float)WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float blueIntensity = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::CopyRedChannelAllFrames(animationId, greenIntensity, blueIntensity);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy green channel to other channels for all frames. Intensity range is
	0.0 to 1.0. Reference the animation by name.
*/
int Extension::LuaCopyRedChannelAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		float greenIntensity = (float)WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float blueIntensity = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::CopyRedChannelAllFramesName(path.c_str(), greenIntensity, blueIntensity);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyRedChannelAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double greenIntensity = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double blueIntensity = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::CopyRedChannelAllFramesNameD(path.c_str(), greenIntensity, blueIntensity);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy zero colors from source animation to target animation for all frames.
	Source and target are referenced by id.
*/
int Extension::LuaCopyZeroAllKeysAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::CopyZeroAllKeysAllFrames(sourceAnimationId, targetAnimationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy zero colors from source animation to target animation for all frames.
	Source and target are referenced by name.
*/
int Extension::LuaCopyZeroAllKeysAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		ChromaAnimationAPI::CopyZeroAllKeysAllFramesName(sourceAnimation.c_str(), targetAnimation.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyZeroAllKeysAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		double result = ChromaAnimationAPI::CopyZeroAllKeysAllFramesNameD(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy zero colors from source animation to target animation for all frames
	starting at the target offset for the length of the source animation. Source
	and target are referenced by id.
*/
int Extension::LuaCopyZeroAllKeysAllFramesOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyZeroAllKeysAllFramesOffset(sourceAnimationId, targetAnimationId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy zero colors from source animation to target animation for all frames
	starting at the target offset for the length of the source animation. Source
	and target are referenced by name.
*/
int Extension::LuaCopyZeroAllKeysAllFramesOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::CopyZeroAllKeysAllFramesOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyZeroAllKeysAllFramesOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::CopyZeroAllKeysAllFramesOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy zero key color from source animation to target animation for the specified
	frame. Source and target are referenced by id.
*/
int Extension::LuaCopyZeroKeyColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyZeroKeyColor(sourceAnimationId, targetAnimationId, frameId, rzkey);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy zero key color from source animation to target animation for the specified
	frame. Source and target are referenced by name.
*/
int Extension::LuaCopyZeroKeyColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::CopyZeroKeyColorName(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, rzkey);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyZeroKeyColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::CopyZeroKeyColorNameD(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, rzkey);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero color from source animation to target animation where target
	is zero for all frames. Source and target are referenced by id.
*/
int Extension::LuaCopyZeroTargetAllKeysAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::CopyZeroTargetAllKeysAllFrames(sourceAnimationId, targetAnimationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Copy nonzero color from source animation to target animation where target
	is zero for all frames. Source and target are referenced by name.
*/
int Extension::LuaCopyZeroTargetAllKeysAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		ChromaAnimationAPI::CopyZeroTargetAllKeysAllFramesName(sourceAnimation.c_str(), targetAnimation.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaCopyZeroTargetAllKeysAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		double result = ChromaAnimationAPI::CopyZeroTargetAllKeysAllFramesNameD(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreCreateChromaLinkEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: ChromaSDK::ChromaLink::EFFECT_TYPE
		// FieldName: Effect
		// FieldType: PRZPARAM
		// FieldName: pParam
		// FieldType: RZEFFECTID*
		// FieldName: pEffectId
#pragma message("TODO - add support for CoreCreateChromaLinkEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreCreateEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: RZDEVICEID
		// FieldName: DeviceId
		// FieldType: ChromaSDK::EFFECT_TYPE
		// FieldName: Effect
		// FieldType: PRZPARAM
		// FieldName: pParam
		// FieldType: RZEFFECTID*
		// FieldName: pEffectId
#pragma message("TODO - add support for CoreCreateEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreCreateHeadsetEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: ChromaSDK::Headset::EFFECT_TYPE
		// FieldName: Effect
		// FieldType: PRZPARAM
		// FieldName: pParam
		// FieldType: RZEFFECTID*
		// FieldName: pEffectId
#pragma message("TODO - add support for CoreCreateHeadsetEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreCreateKeyboardEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: ChromaSDK::Keyboard::EFFECT_TYPE
		// FieldName: Effect
		// FieldType: PRZPARAM
		// FieldName: pParam
		// FieldType: RZEFFECTID*
		// FieldName: pEffectId
#pragma message("TODO - add support for CoreCreateKeyboardEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreCreateKeypadEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: ChromaSDK::Keypad::EFFECT_TYPE
		// FieldName: Effect
		// FieldType: PRZPARAM
		// FieldName: pParam
		// FieldType: RZEFFECTID*
		// FieldName: pEffectId
#pragma message("TODO - add support for CoreCreateKeypadEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreCreateMouseEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: ChromaSDK::Mouse::EFFECT_TYPE
		// FieldName: Effect
		// FieldType: PRZPARAM
		// FieldName: pParam
		// FieldType: RZEFFECTID*
		// FieldName: pEffectId
#pragma message("TODO - add support for CoreCreateMouseEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreCreateMousepadEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: ChromaSDK::Mousepad::EFFECT_TYPE
		// FieldName: Effect
		// FieldType: PRZPARAM
		// FieldName: pParam
		// FieldType: RZEFFECTID*
		// FieldName: pEffectId
#pragma message("TODO - add support for CoreCreateMousepadEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreDeleteEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: RZEFFECTID
		// FieldName: EffectId
#pragma message("TODO - add support for CoreDeleteEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreInit(lua::lua_State* state)
{
	if (state)
	{
		ChromaAnimationAPI::CoreInit();
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreInitSDK(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: ChromaSDK::APPINFOTYPE*
		// FieldName: AppInfo
#pragma message("TODO - add support for CoreInitSDK")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreQueryDevice(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: RZDEVICEID
		// FieldName: DeviceId
		// FieldType: ChromaSDK::DEVICE_INFO_TYPE&
		// FieldName: DeviceInfo
#pragma message("TODO - add support for CoreQueryDevice")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreSetEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: RZEFFECTID
		// FieldName: EffectId
#pragma message("TODO - add support for CoreSetEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Direct access to low level API.
*/
int Extension::LuaCoreUnInit(lua::lua_State* state)
{
	if (state)
	{
		ChromaAnimationAPI::CoreUnInit();
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Creates a `Chroma` animation at the given path. The `deviceType` parameter
	uses `EChromaSDKDeviceTypeEnum` as an integer. The `device` parameter uses
	`EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` as an integer, respective
	to the `deviceType`. Returns the animation id upon success. Returns -1
	upon failure. Saves a `Chroma` animation file with the `.chroma` extension
	at the given path. Returns the animation id upon success. Returns -1 upon
	failure.
*/
int Extension::LuaCreateAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int deviceType = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int device = WrapperXLua::lua_tointegerW(state, 3);
		int result = ChromaAnimationAPI::CreateAnimation(path.c_str(), deviceType, device);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Creates a `Chroma` animation in memory without creating a file. The `deviceType`
	parameter uses `EChromaSDKDeviceTypeEnum` as an integer. The `device` parameter
	uses `EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` as an integer,
	respective to the `deviceType`. Returns the animation id upon success.
	Returns -1 upon failure. Returns the animation id upon success. Returns
	-1 upon failure.
*/
int Extension::LuaCreateAnimationInMemory(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int deviceType = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int device = WrapperXLua::lua_tointegerW(state, 2);
		int result = ChromaAnimationAPI::CreateAnimationInMemory(deviceType, device);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Create a device specific effect.
*/
int Extension::LuaCreateEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: RZDEVICEID
		// FieldName: deviceId
		// FieldType: ChromaSDK::EFFECT_TYPE
		// FieldName: effect
		// FieldType: int*
		// FieldName: colors
		// FieldType: int
		// FieldName: size
		// FieldType: ChromaSDK::FChromaSDKGuid*
		// FieldName: effectId
#pragma message("TODO - add support for CreateEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Delete an effect given the effect id.
*/
int Extension::LuaDeleteEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const ChromaSDK::FChromaSDKGuid&
		// FieldName: effectId
#pragma message("TODO - add support for DeleteEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Duplicate the first animation frame so that the animation length matches
	the frame count. Animation is referenced by id.
*/
int Extension::LuaDuplicateFirstFrame(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameCount = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::DuplicateFirstFrame(animationId, frameCount);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Duplicate the first animation frame so that the animation length matches
	the frame count. Animation is referenced by name.
*/
int Extension::LuaDuplicateFirstFrameName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameCount = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::DuplicateFirstFrameName(path.c_str(), frameCount);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaDuplicateFirstFrameNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameCount = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::DuplicateFirstFrameNameD(path.c_str(), frameCount);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Duplicate all the frames of the animation to double the animation length.
	Frame 1 becomes frame 1 and 2. Frame 2 becomes frame 3 and 4. And so on.
	The animation is referenced by id.
*/
int Extension::LuaDuplicateFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		ChromaAnimationAPI::DuplicateFrames(animationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Duplicate all the frames of the animation to double the animation length.
	Frame 1 becomes frame 1 and 2. Frame 2 becomes frame 3 and 4. And so on.
	The animation is referenced by name.
*/
int Extension::LuaDuplicateFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::DuplicateFramesName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaDuplicateFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::DuplicateFramesNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Duplicate all the animation frames in reverse so that the animation plays
	forwards and backwards. Animation is referenced by id.
*/
int Extension::LuaDuplicateMirrorFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		ChromaAnimationAPI::DuplicateMirrorFrames(animationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Duplicate all the animation frames in reverse so that the animation plays
	forwards and backwards. Animation is referenced by name.
*/
int Extension::LuaDuplicateMirrorFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::DuplicateMirrorFramesName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaDuplicateMirrorFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::DuplicateMirrorFramesNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fade the animation to black starting at the fade frame index to the end
	of the animation. Animation is referenced by id.
*/
int Extension::LuaFadeEndFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int fade = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FadeEndFrames(animationId, fade);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fade the animation to black starting at the fade frame index to the end
	of the animation. Animation is referenced by name.
*/
int Extension::LuaFadeEndFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int fade = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FadeEndFramesName(path.c_str(), fade);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFadeEndFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double fade = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::FadeEndFramesNameD(path.c_str(), fade);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fade the animation from black to full color starting at 0 to the fade frame
	index. Animation is referenced by id.
*/
int Extension::LuaFadeStartFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int fade = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FadeStartFrames(animationId, fade);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fade the animation from black to full color starting at 0 to the fade frame
	index. Animation is referenced by name.
*/
int Extension::LuaFadeStartFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int fade = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FadeStartFramesName(path.c_str(), fade);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFadeStartFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double fade = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::FadeStartFramesNameD(path.c_str(), fade);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set the RGB value for all colors in the specified frame. Animation is referenced
	by id.
*/
int Extension::LuaFillColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::FillColor(animationId, frameId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the RGB value for all colors for all frames. Animation is referenced
	by id.
*/
int Extension::LuaFillColorAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FillColorAllFrames(animationId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the RGB value for all colors for all frames. Animation is referenced
	by name.
*/
int Extension::LuaFillColorAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FillColorAllFramesName(path.c_str(), color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillColorAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::FillColorAllFramesNameD(path.c_str(), color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set the RGB value for all colors for all frames. Use the range of 0 to 255
	for red, green, and blue parameters. Animation is referenced by id.
*/
int Extension::LuaFillColorAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::FillColorAllFramesRGB(animationId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the RGB value for all colors for all frames. Use the range of 0 to 255
	for red, green, and blue parameters. Animation is referenced by name.
*/
int Extension::LuaFillColorAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::FillColorAllFramesRGBName(path.c_str(), red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillColorAllFramesRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::FillColorAllFramesRGBNameD(path.c_str(), red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set the RGB value for all colors in the specified frame. Animation is referenced
	by name.
*/
int Extension::LuaFillColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::FillColorName(path.c_str(), frameId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::FillColorNameD(path.c_str(), frameId, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set the RGB value for all colors in the specified frame. Animation is referenced
	by id.
*/
int Extension::LuaFillColorRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::FillColorRGB(animationId, frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the RGB value for all colors in the specified frame. Animation is referenced
	by name.
*/
int Extension::LuaFillColorRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::FillColorRGBName(path.c_str(), frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillColorRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 5);
		double result = ChromaAnimationAPI::FillColorRGBNameD(path.c_str(), frameId, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors in the specified
	frame. Animation is referenced by id.
*/
int Extension::LuaFillNonZeroColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::FillNonZeroColor(animationId, frameId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors for all frames.
	Animation is referenced by id.
*/
int Extension::LuaFillNonZeroColorAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FillNonZeroColorAllFrames(animationId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors for all frames.
	Animation is referenced by name.
*/
int Extension::LuaFillNonZeroColorAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FillNonZeroColorAllFramesName(path.c_str(), color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillNonZeroColorAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::FillNonZeroColorAllFramesNameD(path.c_str(), color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors for all frames.
	Use the range of 0 to 255 for red, green, and blue parameters. Animation
	is referenced by id.
*/
int Extension::LuaFillNonZeroColorAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::FillNonZeroColorAllFramesRGB(animationId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors for all frames.
	Use the range of 0 to 255 for red, green, and blue parameters. Animation
	is referenced by name.
*/
int Extension::LuaFillNonZeroColorAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::FillNonZeroColorAllFramesRGBName(path.c_str(), red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillNonZeroColorAllFramesRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::FillNonZeroColorAllFramesRGBNameD(path.c_str(), red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors in the specified
	frame. Animation is referenced by name.
*/
int Extension::LuaFillNonZeroColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::FillNonZeroColorName(path.c_str(), frameId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillNonZeroColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::FillNonZeroColorNameD(path.c_str(), frameId, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors in the specified
	frame. Use the range of 0 to 255 for red, green, and blue parameters. Animation
	is referenced by id.
*/
int Extension::LuaFillNonZeroColorRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::FillNonZeroColorRGB(animationId, frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Set the RGB value for a subset of colors in the specified
	frame. Use the range of 0 to 255 for red, green, and blue parameters. Animation
	is referenced by name.
*/
int Extension::LuaFillNonZeroColorRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::FillNonZeroColorRGBName(path.c_str(), frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillNonZeroColorRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 5);
		double result = ChromaAnimationAPI::FillNonZeroColorRGBNameD(path.c_str(), frameId, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the frame with random RGB values for the given frame. Animation is
	referenced by id.
*/
int Extension::LuaFillRandomColors(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FillRandomColors(animationId, frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the frame with random RGB values for all frames. Animation is referenced
	by id.
*/
int Extension::LuaFillRandomColorsAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		ChromaAnimationAPI::FillRandomColorsAllFrames(animationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the frame with random RGB values for all frames. Animation is referenced
	by name.
*/
int Extension::LuaFillRandomColorsAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::FillRandomColorsAllFramesName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillRandomColorsAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::FillRandomColorsAllFramesNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the frame with random black and white values for the specified frame.
	Animation is referenced by id.
*/
int Extension::LuaFillRandomColorsBlackAndWhite(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FillRandomColorsBlackAndWhite(animationId, frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the frame with random black and white values for all frames. Animation
	is referenced by id.
*/
int Extension::LuaFillRandomColorsBlackAndWhiteAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		ChromaAnimationAPI::FillRandomColorsBlackAndWhiteAllFrames(animationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the frame with random black and white values for all frames. Animation
	is referenced by name.
*/
int Extension::LuaFillRandomColorsBlackAndWhiteAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::FillRandomColorsBlackAndWhiteAllFramesName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillRandomColorsBlackAndWhiteAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::FillRandomColorsBlackAndWhiteAllFramesNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the frame with random black and white values for the specified frame.
	Animation is referenced by name.
*/
int Extension::LuaFillRandomColorsBlackAndWhiteName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FillRandomColorsBlackAndWhiteName(path.c_str(), frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillRandomColorsBlackAndWhiteNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::FillRandomColorsBlackAndWhiteNameD(path.c_str(), frameId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the frame with random RGB values for the given frame. Animation is
	referenced by name.
*/
int Extension::LuaFillRandomColorsName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FillRandomColorsName(path.c_str(), frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillRandomColorsNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::FillRandomColorsNameD(path.c_str(), frameId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with RGB color where the animation color is less
	than the RGB threshold. Animation is referenced by id.
*/
int Extension::LuaFillThresholdColors(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int threshold = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::FillThresholdColors(animationId, frameId, threshold, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with RGB color where the animation color is less than the
	RGB threshold. Animation is referenced by id.
*/
int Extension::LuaFillThresholdColorsAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int threshold = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::FillThresholdColorsAllFrames(animationId, threshold, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with RGB color where the animation color is less than the
	RGB threshold. Animation is referenced by name.
*/
int Extension::LuaFillThresholdColorsAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int threshold = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::FillThresholdColorsAllFramesName(path.c_str(), threshold, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillThresholdColorsAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double threshold = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::FillThresholdColorsAllFramesNameD(path.c_str(), threshold, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with RGB color where the animation color is less than the
	threshold. Animation is referenced by id.
*/
int Extension::LuaFillThresholdColorsAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int threshold = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::FillThresholdColorsAllFramesRGB(animationId, threshold, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with RGB color where the animation color is less than the
	threshold. Animation is referenced by name.
*/
int Extension::LuaFillThresholdColorsAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int threshold = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::FillThresholdColorsAllFramesRGBName(path.c_str(), threshold, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillThresholdColorsAllFramesRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double threshold = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 5);
		double result = ChromaAnimationAPI::FillThresholdColorsAllFramesRGBNameD(path.c_str(), threshold, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with the min RGB color where the animation color is less
	than the min threshold AND with the max RGB color where the animation is
	more than the max threshold. Animation is referenced by id.
*/
int Extension::LuaFillThresholdColorsMinMaxAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int minThreshold = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int minRed = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int minGreen = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int minBlue = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int maxThreshold = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int maxRed = WrapperXLua::lua_tointegerW(state, 7);
		if (!WrapperXLua::lua_isnumberW(state, 8))
		{
			return -1;
		}
		int maxGreen = WrapperXLua::lua_tointegerW(state, 8);
		if (!WrapperXLua::lua_isnumberW(state, 9))
		{
			return -1;
		}
		int maxBlue = WrapperXLua::lua_tointegerW(state, 9);
		ChromaAnimationAPI::FillThresholdColorsMinMaxAllFramesRGB(animationId, minThreshold, minRed, minGreen, minBlue, maxThreshold, maxRed, maxGreen, maxBlue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with the min RGB color where the animation color is less
	than the min threshold AND with the max RGB color where the animation is
	more than the max threshold. Animation is referenced by name.
*/
int Extension::LuaFillThresholdColorsMinMaxAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int minThreshold = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int minRed = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int minGreen = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int minBlue = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int maxThreshold = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int maxRed = WrapperXLua::lua_tointegerW(state, 7);
		if (!WrapperXLua::lua_isnumberW(state, 8))
		{
			return -1;
		}
		int maxGreen = WrapperXLua::lua_tointegerW(state, 8);
		if (!WrapperXLua::lua_isnumberW(state, 9))
		{
			return -1;
		}
		int maxBlue = WrapperXLua::lua_tointegerW(state, 9);
		ChromaAnimationAPI::FillThresholdColorsMinMaxAllFramesRGBName(path.c_str(), minThreshold, minRed, minGreen, minBlue, maxThreshold, maxRed, maxGreen, maxBlue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillThresholdColorsMinMaxAllFramesRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double minThreshold = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double minRed = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double minGreen = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double minBlue = WrapperXLua::lua_tonumberW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		double maxThreshold = WrapperXLua::lua_tonumberW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		double maxRed = WrapperXLua::lua_tonumberW(state, 7);
		if (!WrapperXLua::lua_isnumberW(state, 8))
		{
			return -1;
		}
		double maxGreen = WrapperXLua::lua_tonumberW(state, 8);
		if (!WrapperXLua::lua_isnumberW(state, 9))
		{
			return -1;
		}
		double maxBlue = WrapperXLua::lua_tonumberW(state, 9);
		double result = ChromaAnimationAPI::FillThresholdColorsMinMaxAllFramesRGBNameD(path.c_str(), minThreshold, minRed, minGreen, minBlue, maxThreshold, maxRed, maxGreen, maxBlue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with the min RGB color where the animation color
	is less than the min threshold AND with the max RGB color where the animation
	is more than the max threshold. Animation is referenced by id.
*/
int Extension::LuaFillThresholdColorsMinMaxRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int minThreshold = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int minRed = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int minGreen = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int minBlue = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int maxThreshold = WrapperXLua::lua_tointegerW(state, 7);
		if (!WrapperXLua::lua_isnumberW(state, 8))
		{
			return -1;
		}
		int maxRed = WrapperXLua::lua_tointegerW(state, 8);
		if (!WrapperXLua::lua_isnumberW(state, 9))
		{
			return -1;
		}
		int maxGreen = WrapperXLua::lua_tointegerW(state, 9);
		if (!WrapperXLua::lua_isnumberW(state, 10))
		{
			return -1;
		}
		int maxBlue = WrapperXLua::lua_tointegerW(state, 10);
		ChromaAnimationAPI::FillThresholdColorsMinMaxRGB(animationId, frameId, minThreshold, minRed, minGreen, minBlue, maxThreshold, maxRed, maxGreen, maxBlue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with the min RGB color where the animation color
	is less than the min threshold AND with the max RGB color where the animation
	is more than the max threshold. Animation is referenced by name.
*/
int Extension::LuaFillThresholdColorsMinMaxRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int minThreshold = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int minRed = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int minGreen = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int minBlue = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int maxThreshold = WrapperXLua::lua_tointegerW(state, 7);
		if (!WrapperXLua::lua_isnumberW(state, 8))
		{
			return -1;
		}
		int maxRed = WrapperXLua::lua_tointegerW(state, 8);
		if (!WrapperXLua::lua_isnumberW(state, 9))
		{
			return -1;
		}
		int maxGreen = WrapperXLua::lua_tointegerW(state, 9);
		if (!WrapperXLua::lua_isnumberW(state, 10))
		{
			return -1;
		}
		int maxBlue = WrapperXLua::lua_tointegerW(state, 10);
		ChromaAnimationAPI::FillThresholdColorsMinMaxRGBName(path.c_str(), frameId, minThreshold, minRed, minGreen, minBlue, maxThreshold, maxRed, maxGreen, maxBlue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillThresholdColorsMinMaxRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double minThreshold = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double minRed = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double minGreen = WrapperXLua::lua_tonumberW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		double minBlue = WrapperXLua::lua_tonumberW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		double maxThreshold = WrapperXLua::lua_tonumberW(state, 7);
		if (!WrapperXLua::lua_isnumberW(state, 8))
		{
			return -1;
		}
		double maxRed = WrapperXLua::lua_tonumberW(state, 8);
		if (!WrapperXLua::lua_isnumberW(state, 9))
		{
			return -1;
		}
		double maxGreen = WrapperXLua::lua_tonumberW(state, 9);
		if (!WrapperXLua::lua_isnumberW(state, 10))
		{
			return -1;
		}
		double maxBlue = WrapperXLua::lua_tonumberW(state, 10);
		double result = ChromaAnimationAPI::FillThresholdColorsMinMaxRGBNameD(path.c_str(), frameId, minThreshold, minRed, minGreen, minBlue, maxThreshold, maxRed, maxGreen, maxBlue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with RGB color where the animation color is less
	than the RGB threshold. Animation is referenced by name.
*/
int Extension::LuaFillThresholdColorsName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int threshold = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::FillThresholdColorsName(path.c_str(), frameId, threshold, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillThresholdColorsNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double threshold = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::FillThresholdColorsNameD(path.c_str(), frameId, threshold, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with RGB color where the animation color is less
	than the RGB threshold. Animation is referenced by id.
*/
int Extension::LuaFillThresholdColorsRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int threshold = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 6);
		ChromaAnimationAPI::FillThresholdColorsRGB(animationId, frameId, threshold, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with RGB color where the animation color is less
	than the RGB threshold. Animation is referenced by name.
*/
int Extension::LuaFillThresholdColorsRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int threshold = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 6);
		ChromaAnimationAPI::FillThresholdColorsRGBName(path.c_str(), frameId, threshold, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillThresholdColorsRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double threshold = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 6);
		double result = ChromaAnimationAPI::FillThresholdColorsRGBNameD(path.c_str(), frameId, threshold, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with RGB color where the animation color is less than the
	RGB threshold. Animation is referenced by id.
*/
int Extension::LuaFillThresholdRGBColorsAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int redThreshold = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int greenThreshold = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blueThreshold = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 7);
		ChromaAnimationAPI::FillThresholdRGBColorsAllFramesRGB(animationId, redThreshold, greenThreshold, blueThreshold, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with RGB color where the animation color is less than the
	RGB threshold. Animation is referenced by name.
*/
int Extension::LuaFillThresholdRGBColorsAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int redThreshold = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int greenThreshold = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blueThreshold = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 7);
		ChromaAnimationAPI::FillThresholdRGBColorsAllFramesRGBName(path.c_str(), redThreshold, greenThreshold, blueThreshold, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillThresholdRGBColorsAllFramesRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double redThreshold = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double greenThreshold = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double blueThreshold = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 7);
		double result = ChromaAnimationAPI::FillThresholdRGBColorsAllFramesRGBNameD(path.c_str(), redThreshold, greenThreshold, blueThreshold, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with RGB color where the animation color is less
	than the RGB threshold. Animation is referenced by id.
*/
int Extension::LuaFillThresholdRGBColorsRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int redThreshold = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int greenThreshold = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blueThreshold = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 7);
		if (!WrapperXLua::lua_isnumberW(state, 8))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 8);
		ChromaAnimationAPI::FillThresholdRGBColorsRGB(animationId, frameId, redThreshold, greenThreshold, blueThreshold, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with RGB color where the animation color is less
	than the RGB threshold. Animation is referenced by name.
*/
int Extension::LuaFillThresholdRGBColorsRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int redThreshold = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int greenThreshold = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blueThreshold = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 7);
		if (!WrapperXLua::lua_isnumberW(state, 8))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 8);
		ChromaAnimationAPI::FillThresholdRGBColorsRGBName(path.c_str(), frameId, redThreshold, greenThreshold, blueThreshold, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillThresholdRGBColorsRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double redThreshold = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double greenThreshold = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double blueThreshold = WrapperXLua::lua_tonumberW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 7);
		if (!WrapperXLua::lua_isnumberW(state, 8))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 8);
		double result = ChromaAnimationAPI::FillThresholdRGBColorsRGBNameD(path.c_str(), frameId, redThreshold, greenThreshold, blueThreshold, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with RGB color where the animation color is zero.
	Animation is referenced by id.
*/
int Extension::LuaFillZeroColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::FillZeroColor(animationId, frameId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with RGB color where the animation color is zero. Animation
	is referenced by id.
*/
int Extension::LuaFillZeroColorAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FillZeroColorAllFrames(animationId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with RGB color where the animation color is zero. Animation
	is referenced by name.
*/
int Extension::LuaFillZeroColorAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::FillZeroColorAllFramesName(path.c_str(), color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillZeroColorAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::FillZeroColorAllFramesNameD(path.c_str(), color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with RGB color where the animation color is zero. Animation
	is referenced by id.
*/
int Extension::LuaFillZeroColorAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::FillZeroColorAllFramesRGB(animationId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill all frames with RGB color where the animation color is zero. Animation
	is referenced by name.
*/
int Extension::LuaFillZeroColorAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::FillZeroColorAllFramesRGBName(path.c_str(), red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillZeroColorAllFramesRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::FillZeroColorAllFramesRGBNameD(path.c_str(), red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with RGB color where the animation color is zero.
	Animation is referenced by name.
*/
int Extension::LuaFillZeroColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::FillZeroColorName(path.c_str(), frameId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillZeroColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::FillZeroColorNameD(path.c_str(), frameId, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with RGB color where the animation color is zero.
	Animation is referenced by id.
*/
int Extension::LuaFillZeroColorRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::FillZeroColorRGB(animationId, frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Fill the specified frame with RGB color where the animation color is zero.
	Animation is referenced by name.
*/
int Extension::LuaFillZeroColorRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::FillZeroColorRGBName(path.c_str(), frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaFillZeroColorRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 5);
		double result = ChromaAnimationAPI::FillZeroColorRGBNameD(path.c_str(), frameId, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Get the animation color for a frame given the `1D` `led`. The `led` should
	be greater than or equal to 0 and less than the `MaxLeds`. Animation is
	referenced by id.
*/
int Extension::LuaGet1DColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int led = WrapperXLua::lua_tointegerW(state, 3);
		int result = ChromaAnimationAPI::Get1DColor(animationId, frameId, led);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Get the animation color for a frame given the `1D` `led`. The `led` should
	be greater than or equal to 0 and less than the `MaxLeds`. Animation is
	referenced by name.
*/
int Extension::LuaGet1DColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int led = WrapperXLua::lua_tointegerW(state, 3);
		int result = ChromaAnimationAPI::Get1DColorName(path.c_str(), frameId, led);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGet1DColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double led = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::Get1DColorNameD(path.c_str(), frameId, led);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Get the animation color for a frame given the `2D` `row` and `column`. The
	`row` should be greater than or equal to 0 and less than the `MaxRow`.
	The `column` should be greater than or equal to 0 and less than the `MaxColumn`.
	Animation is referenced by id.
*/
int Extension::LuaGet2DColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int row = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int column = WrapperXLua::lua_tointegerW(state, 4);
		int result = ChromaAnimationAPI::Get2DColor(animationId, frameId, row, column);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Get the animation color for a frame given the `2D` `row` and `column`. The
	`row` should be greater than or equal to 0 and less than the `MaxRow`.
	The `column` should be greater than or equal to 0 and less than the `MaxColumn`.
	Animation is referenced by name.
*/
int Extension::LuaGet2DColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int row = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int column = WrapperXLua::lua_tointegerW(state, 4);
		int result = ChromaAnimationAPI::Get2DColorName(path.c_str(), frameId, row, column);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGet2DColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double row = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double column = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::Get2DColorNameD(path.c_str(), frameId, row, column);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Get the animation id for the named animation.
*/
int Extension::LuaGetAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string name = WrapperXLua::lua_tostringW(state, 1);
		int result = ChromaAnimationAPI::GetAnimation(name.c_str());
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginGetAnimationCount` will return the number of loaded animations.
*/
int Extension::LuaGetAnimationCount(lua::lua_State* state)
{
	if (state)
	{
		int result = ChromaAnimationAPI::GetAnimationCount();
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGetAnimationD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string name = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::GetAnimationD(name.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginGetAnimationId` will return the `animationId` given the `index` of
	the loaded animation. The `index` is zero-based and less than the number
	returned by `PluginGetAnimationCount`. Use `PluginGetAnimationName` to
	get the name of the animation.
*/
int Extension::LuaGetAnimationId(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int index = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::GetAnimationId(index);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginGetAnimationName` takes an `animationId` and returns the name of
	the animation of the `.chroma` animation file. If a name is not available
	then an empty string will be returned.
*/
int Extension::LuaGetAnimationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		const char* result = ChromaAnimationAPI::GetAnimationName(animationId);
		lua::lua_pushlstring(state, result, strlen(result));
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Get the current frame of the animation referenced by id.
*/
int Extension::LuaGetCurrentFrame(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::GetCurrentFrame(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Get the current frame of the animation referenced by name.
*/
int Extension::LuaGetCurrentFrameName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		int result = ChromaAnimationAPI::GetCurrentFrameName(path.c_str());
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGetCurrentFrameNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::GetCurrentFrameNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Returns the `EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` of a `Chroma`
	animation respective to the `deviceType`, as an integer upon success. Returns
	-1 upon failure.
*/
int Extension::LuaGetDevice(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::GetDevice(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Returns the `EChromaSDKDevice1DEnum` or `EChromaSDKDevice2DEnum` of a `Chroma`
	animation respective to the `deviceType`, as an integer upon success. Returns
	-1 upon failure.
*/
int Extension::LuaGetDeviceName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		int result = ChromaAnimationAPI::GetDeviceName(path.c_str());
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGetDeviceNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::GetDeviceNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Returns the `EChromaSDKDeviceTypeEnum` of a `Chroma` animation as an integer
	upon success. Returns -1 upon failure.
*/
int Extension::LuaGetDeviceType(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::GetDeviceType(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Returns the `EChromaSDKDeviceTypeEnum` of a `Chroma` animation as an integer
	upon success. Returns -1 upon failure.
*/
int Extension::LuaGetDeviceTypeName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		int result = ChromaAnimationAPI::GetDeviceTypeName(path.c_str());
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGetDeviceTypeNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::GetDeviceTypeNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Gets the frame colors and duration (in seconds) for a `Chroma` animation.
	The `color` is expected to be an array of the expected dimensions for the
	`deviceType/device`. The `length` parameter is the size of the `color`
	array. For `EChromaSDKDevice1DEnum` the array size should be `MAX LEDS`.
	For `EChromaSDKDevice2DEnum` the array size should be `MAX ROW` * `MAX
	COLUMN`. Returns the animation id upon success. Returns -1 upon failure.
*/
int Extension::LuaGetFrame(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: int
		// FieldName: frameIndex
		// FieldType: float*
		// FieldName: duration
		// FieldType: int*
		// FieldName: colors
		// FieldType: int
		// FieldName: length
#pragma message("TODO - add support for GetFrame")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Returns the frame count of a `Chroma` animation upon success. Returns -1
	upon failure.
*/
int Extension::LuaGetFrameCount(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::GetFrameCount(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Returns the frame count of a `Chroma` animation upon success. Returns -1
	upon failure.
*/
int Extension::LuaGetFrameCountName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		int result = ChromaAnimationAPI::GetFrameCountName(path.c_str());
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGetFrameCountNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::GetFrameCountNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Get the color of an animation key for the given frame referenced by id.
*/
int Extension::LuaGetKeyColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		int result = ChromaAnimationAPI::GetKeyColor(animationId, frameId, rzkey);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGetKeyColorD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::GetKeyColorD(path.c_str(), frameId, rzkey);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Get the color of an animation key for the given frame referenced by name.
*/
int Extension::LuaGetKeyColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		int result = ChromaAnimationAPI::GetKeyColorName(path.c_str(), frameId, rzkey);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Returns `RZRESULT_SUCCESS` if the plugin has been initialized successfully.
	Returns `RZRESULT_DLL_NOT_FOUND` if core Chroma library is not found. Returns
	`RZRESULT_DLL_INVALID_SIGNATURE` if core Chroma library has an invalid
	signature.
*/
int Extension::LuaGetLibraryLoadedState(lua::lua_State* state)
{
	if (state)
	{
		ChromaAnimationAPI::GetLibraryLoadedState();
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGetLibraryLoadedStateD(lua::lua_State* state)
{
	if (state)
	{
		double result = ChromaAnimationAPI::GetLibraryLoadedStateD();
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Returns the `MAX COLUMN` given the `EChromaSDKDevice2DEnum` device as an
	integer upon success. Returns -1 upon failure.
*/
int Extension::LuaGetMaxColumn(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int device = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::GetMaxColumn(device);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGetMaxColumnD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double device = WrapperXLua::lua_tonumberW(state, 1);
		double result = ChromaAnimationAPI::GetMaxColumnD(device);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Returns the MAX LEDS given the `EChromaSDKDevice1DEnum` device as an integer
	upon success. Returns -1 upon failure.
*/
int Extension::LuaGetMaxLeds(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int device = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::GetMaxLeds(device);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGetMaxLedsD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double device = WrapperXLua::lua_tonumberW(state, 1);
		double result = ChromaAnimationAPI::GetMaxLedsD(device);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Returns the `MAX ROW` given the `EChromaSDKDevice2DEnum` device as an integer
	upon success. Returns -1 upon failure.
*/
int Extension::LuaGetMaxRow(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int device = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::GetMaxRow(device);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGetMaxRowD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double device = WrapperXLua::lua_tonumberW(state, 1);
		double result = ChromaAnimationAPI::GetMaxRowD(device);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginGetPlayingAnimationCount` will return the number of playing animations.
*/
int Extension::LuaGetPlayingAnimationCount(lua::lua_State* state)
{
	if (state)
	{
		int result = ChromaAnimationAPI::GetPlayingAnimationCount();
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginGetPlayingAnimationId` will return the `animationId` given the `index`
	of the playing animation. The `index` is zero-based and less than the number
	returned by `PluginGetPlayingAnimationCount`. Use `PluginGetAnimationName`
	to get the name of the animation.
*/
int Extension::LuaGetPlayingAnimationId(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int index = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::GetPlayingAnimationId(index);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Get the RGB color given red, green, and blue.
*/
int Extension::LuaGetRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 3);
		int result = ChromaAnimationAPI::GetRGB(red, green, blue);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaGetRGBD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::GetRGBD(red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Check if the animation has loop enabled referenced by id.
*/
int Extension::LuaHasAnimationLoop(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		bool result = ChromaAnimationAPI::HasAnimationLoop(animationId);
		lua::lua_pushboolean(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Check if the animation has loop enabled referenced by name.
*/
int Extension::LuaHasAnimationLoopName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		bool result = ChromaAnimationAPI::HasAnimationLoopName(path.c_str());
		lua::lua_pushboolean(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaHasAnimationLoopNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::HasAnimationLoopNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Initialize the ChromaSDK. Zero indicates  success, otherwise failure. Many
	API methods auto initialize the ChromaSDK if not already initialized.
*/
int Extension::LuaInit(lua::lua_State* state)
{
	if (state)
	{
		ChromaAnimationAPI::Init();
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaInitD(lua::lua_State* state)
{
	if (state)
	{
		double result = ChromaAnimationAPI::InitD();
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Initialize the ChromaSDK. AppInfo populates the details in Synapse. Zero
	indicates  success, otherwise failure. Many API methods auto initialize
	the ChromaSDK if not already initialized.
*/
int Extension::LuaInitSDK(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: ChromaSDK::APPINFOTYPE*
		// FieldName: AppInfo
#pragma message("TODO - add support for InitSDK")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Insert an animation delay by duplicating the frame by the delay number of
	times. Animation is referenced by id.
*/
int Extension::LuaInsertDelay(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int delay = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::InsertDelay(animationId, frameId, delay);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Insert an animation delay by duplicating the frame by the delay number of
	times. Animation is referenced by name.
*/
int Extension::LuaInsertDelayName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int delay = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::InsertDelayName(path.c_str(), frameId, delay);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaInsertDelayNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double delay = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::InsertDelayNameD(path.c_str(), frameId, delay);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Duplicate the source frame index at the target frame index. Animation is
	referenced by id.
*/
int Extension::LuaInsertFrame(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int sourceFrame = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int targetFrame = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::InsertFrame(animationId, sourceFrame, targetFrame);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Duplicate the source frame index at the target frame index. Animation is
	referenced by name.
*/
int Extension::LuaInsertFrameName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int sourceFrame = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int targetFrame = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::InsertFrameName(path.c_str(), sourceFrame, targetFrame);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaInsertFrameNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double sourceFrame = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double targetFrame = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::InsertFrameNameD(path.c_str(), sourceFrame, targetFrame);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Invert all the colors at the specified frame. Animation is referenced by
	id.
*/
int Extension::LuaInvertColors(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::InvertColors(animationId, frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Invert all the colors for all frames. Animation is referenced by id.
*/
int Extension::LuaInvertColorsAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		ChromaAnimationAPI::InvertColorsAllFrames(animationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Invert all the colors for all frames. Animation is referenced by name.
*/
int Extension::LuaInvertColorsAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::InvertColorsAllFramesName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaInvertColorsAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::InvertColorsAllFramesNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Invert all the colors at the specified frame. Animation is referenced by
	name.
*/
int Extension::LuaInvertColorsName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::InvertColorsName(path.c_str(), frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaInvertColorsNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::InvertColorsNameD(path.c_str(), frameId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Check if the animation is paused referenced by id.
*/
int Extension::LuaIsAnimationPaused(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		bool result = ChromaAnimationAPI::IsAnimationPaused(animationId);
		lua::lua_pushboolean(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Check if the animation is paused referenced by name.
*/
int Extension::LuaIsAnimationPausedName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		bool result = ChromaAnimationAPI::IsAnimationPausedName(path.c_str());
		lua::lua_pushboolean(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaIsAnimationPausedNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::IsAnimationPausedNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	The editor dialog is a non-blocking modal window, this method returns true
	if the modal window is open, otherwise false.
*/
int Extension::LuaIsDialogOpen(lua::lua_State* state)
{
	if (state)
	{
		bool result = ChromaAnimationAPI::IsDialogOpen();
		lua::lua_pushboolean(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaIsDialogOpenD(lua::lua_State* state)
{
	if (state)
	{
		double result = ChromaAnimationAPI::IsDialogOpenD();
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Returns true if the plugin has been initialized. Returns false if the plugin
	is uninitialized.
*/
int Extension::LuaIsInitialized(lua::lua_State* state)
{
	if (state)
	{
		bool result = ChromaAnimationAPI::IsInitialized();
		lua::lua_pushboolean(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaIsInitializedD(lua::lua_State* state)
{
	if (state)
	{
		double result = ChromaAnimationAPI::IsInitializedD();
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	If the method can be invoked the method returns true.
*/
int Extension::LuaIsPlatformSupported(lua::lua_State* state)
{
	if (state)
	{
		bool result = ChromaAnimationAPI::IsPlatformSupported();
		lua::lua_pushboolean(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaIsPlatformSupportedD(lua::lua_State* state)
{
	if (state)
	{
		double result = ChromaAnimationAPI::IsPlatformSupportedD();
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginIsPlayingName` automatically handles initializing the `ChromaSDK`.
	The named `.chroma` animation file will be automatically opened. The method
	will return whether the animation is playing or not. Animation is referenced
	by id.
*/
int Extension::LuaIsPlaying(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		bool result = ChromaAnimationAPI::IsPlaying(animationId);
		lua::lua_pushboolean(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaIsPlayingD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double animationId = WrapperXLua::lua_tonumberW(state, 1);
		double result = ChromaAnimationAPI::IsPlayingD(animationId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginIsPlayingName` automatically handles initializing the `ChromaSDK`.
	The named `.chroma` animation file will be automatically opened. The method
	will return whether the animation is playing or not. Animation is referenced
	by name.
*/
int Extension::LuaIsPlayingName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		bool result = ChromaAnimationAPI::IsPlayingName(path.c_str());
		lua::lua_pushboolean(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaIsPlayingNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::IsPlayingNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginIsPlayingType` automatically handles initializing the `ChromaSDK`.
	If any animation is playing for the `deviceType` and `device` combination,
	the method will return true, otherwise false.
*/
int Extension::LuaIsPlayingType(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int deviceType = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int device = WrapperXLua::lua_tointegerW(state, 2);
		bool result = ChromaAnimationAPI::IsPlayingType(deviceType, device);
		lua::lua_pushboolean(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaIsPlayingTypeD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double deviceType = WrapperXLua::lua_tonumberW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double device = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::IsPlayingTypeD(deviceType, device);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Do a lerp math operation on a float.
*/
int Extension::LuaLerp(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		float start = (float)WrapperXLua::lua_tonumberW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		float end = (float)WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float amt = (float)WrapperXLua::lua_tonumberW(state, 3);
		float result = ChromaAnimationAPI::Lerp(start, end, amt);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Lerp from one color to another given t in the range 0.0 to 1.0.
*/
int Extension::LuaLerpColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int from = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int to = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float t = (float)WrapperXLua::lua_tonumberW(state, 3);
		int result = ChromaAnimationAPI::LerpColor(from, to, t);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Loads `Chroma` effects so that the animation can be played immediately.
	Returns the animation id upon success. Returns -1 upon failure.
*/
int Extension::LuaLoadAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::LoadAnimation(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaLoadAnimationD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double animationId = WrapperXLua::lua_tonumberW(state, 1);
		double result = ChromaAnimationAPI::LoadAnimationD(animationId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Load the named animation.
*/
int Extension::LuaLoadAnimationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::LoadAnimationName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Load a composite set of animations.
*/
int Extension::LuaLoadComposite(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string name = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::LoadComposite(name.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color defaults to color. Animation
	is referenced by id.
*/
int Extension::LuaMakeBlankFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameCount = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float duration = (float)WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::MakeBlankFrames(animationId, frameCount, duration, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color defaults to color. Animation
	is referenced by name.
*/
int Extension::LuaMakeBlankFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameCount = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float duration = (float)WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::MakeBlankFramesName(path.c_str(), frameCount, duration, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMakeBlankFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameCount = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double duration = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::MakeBlankFramesNameD(path.c_str(), frameCount, duration, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color is random. Animation is referenced
	by id.
*/
int Extension::LuaMakeBlankFramesRandom(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameCount = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float duration = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::MakeBlankFramesRandom(animationId, frameCount, duration);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color is random black and white. Animation
	is referenced by id.
*/
int Extension::LuaMakeBlankFramesRandomBlackAndWhite(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameCount = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float duration = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::MakeBlankFramesRandomBlackAndWhite(animationId, frameCount, duration);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color is random black and white. Animation
	is referenced by name.
*/
int Extension::LuaMakeBlankFramesRandomBlackAndWhiteName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameCount = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float duration = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::MakeBlankFramesRandomBlackAndWhiteName(path.c_str(), frameCount, duration);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMakeBlankFramesRandomBlackAndWhiteNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameCount = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double duration = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::MakeBlankFramesRandomBlackAndWhiteNameD(path.c_str(), frameCount, duration);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color is random. Animation is referenced
	by name.
*/
int Extension::LuaMakeBlankFramesRandomName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameCount = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float duration = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::MakeBlankFramesRandomName(path.c_str(), frameCount, duration);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMakeBlankFramesRandomNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameCount = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double duration = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::MakeBlankFramesRandomNameD(path.c_str(), frameCount, duration);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color defaults to color. Animation
	is referenced by id.
*/
int Extension::LuaMakeBlankFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameCount = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float duration = (float)WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 6);
		ChromaAnimationAPI::MakeBlankFramesRGB(animationId, frameCount, duration, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Make a blank animation for the length of the frame count. Frame duration
	defaults to the duration. The frame color defaults to color. Animation
	is referenced by name.
*/
int Extension::LuaMakeBlankFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameCount = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float duration = (float)WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 6);
		ChromaAnimationAPI::MakeBlankFramesRGBName(path.c_str(), frameCount, duration, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMakeBlankFramesRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameCount = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double duration = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 6);
		double result = ChromaAnimationAPI::MakeBlankFramesRGBNameD(path.c_str(), frameCount, duration, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Flips the color grid horizontally for all `Chroma` animation frames. Returns
	the animation id upon success. Returns -1 upon failure.
*/
int Extension::LuaMirrorHorizontally(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::MirrorHorizontally(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Flips the color grid vertically for all `Chroma` animation frames. This
	method has no effect for `EChromaSDKDevice1DEnum` devices. Returns the
	animation id upon success. Returns -1 upon failure.
*/
int Extension::LuaMirrorVertically(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::MirrorVertically(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply the color intensity with the lerp result from color 1 to color
	2 using the frame index divided by the frame count for the `t` parameter.
	Animation is referenced in id.
*/
int Extension::LuaMultiplyColorLerpAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color1 = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color2 = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::MultiplyColorLerpAllFrames(animationId, color1, color2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply the color intensity with the lerp result from color 1 to color
	2 using the frame index divided by the frame count for the `t` parameter.
	Animation is referenced in name.
*/
int Extension::LuaMultiplyColorLerpAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color1 = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color2 = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::MultiplyColorLerpAllFramesName(path.c_str(), color1, color2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMultiplyColorLerpAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double color1 = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double color2 = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::MultiplyColorLerpAllFramesNameD(path.c_str(), color1, color2);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all the colors in the frame by the intensity value. The valid the
	intensity range is from 0.0 to 255.0. RGB components are multiplied equally.
	An intensity of 0.5 would half the color value. Black colors in the frame
	will not be affected by this method.
*/
int Extension::LuaMultiplyIntensity(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float intensity = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::MultiplyIntensity(animationId, frameId, intensity);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all the colors for all frames by the intensity value. The valid
	the intensity range is from 0.0 to 255.0. RGB components are multiplied
	equally. An intensity of 0.5 would half the color value. Black colors in
	the frame will not be affected by this method.
*/
int Extension::LuaMultiplyIntensityAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		float intensity = (float)WrapperXLua::lua_tonumberW(state, 2);
		ChromaAnimationAPI::MultiplyIntensityAllFrames(animationId, intensity);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all the colors for all frames by the intensity value. The valid
	the intensity range is from 0.0 to 255.0. RGB components are multiplied
	equally. An intensity of 0.5 would half the color value. Black colors in
	the frame will not be affected by this method.
*/
int Extension::LuaMultiplyIntensityAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		float intensity = (float)WrapperXLua::lua_tonumberW(state, 2);
		ChromaAnimationAPI::MultiplyIntensityAllFramesName(path.c_str(), intensity);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMultiplyIntensityAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double intensity = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::MultiplyIntensityAllFramesNameD(path.c_str(), intensity);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all frames by the RBG color intensity. Animation is referenced
	by id.
*/
int Extension::LuaMultiplyIntensityAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::MultiplyIntensityAllFramesRGB(animationId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all frames by the RBG color intensity. Animation is referenced
	by name.
*/
int Extension::LuaMultiplyIntensityAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::MultiplyIntensityAllFramesRGBName(path.c_str(), red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMultiplyIntensityAllFramesRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::MultiplyIntensityAllFramesRGBNameD(path.c_str(), red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply the specific frame by the RBG color intensity. Animation is referenced
	by id.
*/
int Extension::LuaMultiplyIntensityColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::MultiplyIntensityColor(animationId, frameId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all frames by the RBG color intensity. Animation is referenced
	by id.
*/
int Extension::LuaMultiplyIntensityColorAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::MultiplyIntensityColorAllFrames(animationId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all frames by the RBG color intensity. Animation is referenced
	by name.
*/
int Extension::LuaMultiplyIntensityColorAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::MultiplyIntensityColorAllFramesName(path.c_str(), color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMultiplyIntensityColorAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::MultiplyIntensityColorAllFramesNameD(path.c_str(), color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply the specific frame by the RBG color intensity. Animation is referenced
	by name.
*/
int Extension::LuaMultiplyIntensityColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::MultiplyIntensityColorName(path.c_str(), frameId, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMultiplyIntensityColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::MultiplyIntensityColorNameD(path.c_str(), frameId, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all the colors in the frame by the intensity value. The valid the
	intensity range is from 0.0 to 255.0. RGB components are multiplied equally.
	An intensity of 0.5 would half the color value. Black colors in the frame
	will not be affected by this method.
*/
int Extension::LuaMultiplyIntensityName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		float intensity = (float)WrapperXLua::lua_tonumberW(state, 3);
		ChromaAnimationAPI::MultiplyIntensityName(path.c_str(), frameId, intensity);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMultiplyIntensityNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double intensity = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::MultiplyIntensityNameD(path.c_str(), frameId, intensity);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply the specific frame by the RBG color intensity. Animation is referenced
	by id.
*/
int Extension::LuaMultiplyIntensityRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::MultiplyIntensityRGB(animationId, frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply the specific frame by the RBG color intensity. Animation is referenced
	by name.
*/
int Extension::LuaMultiplyIntensityRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::MultiplyIntensityRGBName(path.c_str(), frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMultiplyIntensityRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 5);
		double result = ChromaAnimationAPI::MultiplyIntensityRGBNameD(path.c_str(), frameId, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply the specific frame by the color lerp result between color 1 and
	2 using the frame color value as the `t` value. Animation is referenced
	by id.
*/
int Extension::LuaMultiplyNonZeroTargetColorLerp(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color1 = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color2 = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::MultiplyNonZeroTargetColorLerp(animationId, frameId, color1, color2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all frames by the color lerp result between color 1 and 2 using
	the frame color value as the `t` value. Animation is referenced by id.
*/
int Extension::LuaMultiplyNonZeroTargetColorLerpAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color1 = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color2 = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::MultiplyNonZeroTargetColorLerpAllFrames(animationId, color1, color2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all frames by the color lerp result between color 1 and 2 using
	the frame color value as the `t` value. Animation is referenced by name.
*/
int Extension::LuaMultiplyNonZeroTargetColorLerpAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color1 = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color2 = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::MultiplyNonZeroTargetColorLerpAllFramesName(path.c_str(), color1, color2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMultiplyNonZeroTargetColorLerpAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double color1 = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double color2 = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::MultiplyNonZeroTargetColorLerpAllFramesNameD(path.c_str(), color1, color2);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply the specific frame by the color lerp result between RGB 1 and 2
	using the frame color value as the `t` value. Animation is referenced by
	id.
*/
int Extension::LuaMultiplyNonZeroTargetColorLerpAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red1 = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green1 = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue1 = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int red2 = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int green2 = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int blue2 = WrapperXLua::lua_tointegerW(state, 7);
		ChromaAnimationAPI::MultiplyNonZeroTargetColorLerpAllFramesRGB(animationId, red1, green1, blue1, red2, green2, blue2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply the specific frame by the color lerp result between RGB 1 and 2
	using the frame color value as the `t` value. Animation is referenced by
	name.
*/
int Extension::LuaMultiplyNonZeroTargetColorLerpAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red1 = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green1 = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue1 = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int red2 = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int green2 = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int blue2 = WrapperXLua::lua_tointegerW(state, 7);
		ChromaAnimationAPI::MultiplyNonZeroTargetColorLerpAllFramesRGBName(path.c_str(), red1, green1, blue1, red2, green2, blue2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMultiplyNonZeroTargetColorLerpAllFramesRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double red1 = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double green1 = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double blue1 = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double red2 = WrapperXLua::lua_tonumberW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		double green2 = WrapperXLua::lua_tonumberW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		double blue2 = WrapperXLua::lua_tonumberW(state, 7);
		double result = ChromaAnimationAPI::MultiplyNonZeroTargetColorLerpAllFramesRGBNameD(path.c_str(), red1, green1, blue1, red2, green2, blue2);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply the specific frame by the color lerp result between color 1 and
	2 using the frame color value as the `t` value. Animation is referenced
	by id.
*/
int Extension::LuaMultiplyTargetColorLerp(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color1 = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color2 = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::MultiplyTargetColorLerp(animationId, frameId, color1, color2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all frames by the color lerp result between color 1 and 2 using
	the frame color value as the `t` value. Animation is referenced by id.
*/
int Extension::LuaMultiplyTargetColorLerpAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color1 = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color2 = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::MultiplyTargetColorLerpAllFrames(animationId, color1, color2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all frames by the color lerp result between color 1 and 2 using
	the frame color value as the `t` value. Animation is referenced by name.
*/
int Extension::LuaMultiplyTargetColorLerpAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int color1 = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color2 = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::MultiplyTargetColorLerpAllFramesName(path.c_str(), color1, color2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMultiplyTargetColorLerpAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double color1 = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double color2 = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::MultiplyTargetColorLerpAllFramesNameD(path.c_str(), color1, color2);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all frames by the color lerp result between RGB 1 and 2 using the
	frame color value as the `t` value. Animation is referenced by id.
*/
int Extension::LuaMultiplyTargetColorLerpAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red1 = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green1 = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue1 = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int red2 = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int green2 = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int blue2 = WrapperXLua::lua_tointegerW(state, 7);
		ChromaAnimationAPI::MultiplyTargetColorLerpAllFramesRGB(animationId, red1, green1, blue1, red2, green2, blue2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Multiply all frames by the color lerp result between RGB 1 and 2 using the
	frame color value as the `t` value. Animation is referenced by name.
*/
int Extension::LuaMultiplyTargetColorLerpAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red1 = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green1 = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue1 = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int red2 = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int green2 = WrapperXLua::lua_tointegerW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		int blue2 = WrapperXLua::lua_tointegerW(state, 7);
		ChromaAnimationAPI::MultiplyTargetColorLerpAllFramesRGBName(path.c_str(), red1, green1, blue1, red2, green2, blue2);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaMultiplyTargetColorLerpAllFramesRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double red1 = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double green1 = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double blue1 = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double red2 = WrapperXLua::lua_tonumberW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		double green2 = WrapperXLua::lua_tonumberW(state, 6);
		if (!WrapperXLua::lua_isnumberW(state, 7))
		{
			return -1;
		}
		double blue2 = WrapperXLua::lua_tonumberW(state, 7);
		double result = ChromaAnimationAPI::MultiplyTargetColorLerpAllFramesRGBNameD(path.c_str(), red1, green1, blue1, red2, green2, blue2);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Offset all colors in the frame using the RGB offset. Use the range of -255
	to 255 for red, green, and blue parameters. Negative values remove color.
	Positive values add color.
*/
int Extension::LuaOffsetColors(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::OffsetColors(animationId, frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Offset all colors for all frames using the RGB offset. Use the range of
	-255 to 255 for red, green, and blue parameters. Negative values remove
	color. Positive values add color.
*/
int Extension::LuaOffsetColorsAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::OffsetColorsAllFrames(animationId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Offset all colors for all frames using the RGB offset. Use the range of
	-255 to 255 for red, green, and blue parameters. Negative values remove
	color. Positive values add color.
*/
int Extension::LuaOffsetColorsAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::OffsetColorsAllFramesName(path.c_str(), red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaOffsetColorsAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::OffsetColorsAllFramesNameD(path.c_str(), red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Offset all colors in the frame using the RGB offset. Use the range of -255
	to 255 for red, green, and blue parameters. Negative values remove color.
	Positive values add color.
*/
int Extension::LuaOffsetColorsName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::OffsetColorsName(path.c_str(), frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaOffsetColorsNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 5);
		double result = ChromaAnimationAPI::OffsetColorsNameD(path.c_str(), frameId, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors in the frame using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
*/
int Extension::LuaOffsetNonZeroColors(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::OffsetNonZeroColors(animationId, frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors for all frames using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
*/
int Extension::LuaOffsetNonZeroColorsAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::OffsetNonZeroColorsAllFrames(animationId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors for all frames using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
*/
int Extension::LuaOffsetNonZeroColorsAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::OffsetNonZeroColorsAllFramesName(path.c_str(), red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaOffsetNonZeroColorsAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::OffsetNonZeroColorsAllFramesNameD(path.c_str(), red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	This method will only update colors in the animation that are not already
	set to black. Offset a subset of colors in the frame using the RGB offset.
	Use the range of -255 to 255 for red, green, and blue parameters. Negative
	values remove color. Positive values add color.
*/
int Extension::LuaOffsetNonZeroColorsName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::OffsetNonZeroColorsName(path.c_str(), frameId, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaOffsetNonZeroColorsNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 5);
		double result = ChromaAnimationAPI::OffsetNonZeroColorsNameD(path.c_str(), frameId, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Opens a `Chroma` animation file so that it can be played. Returns an animation
	id >= 0 upon success. Returns -1 if there was a failure. The animation
	id is used in most of the API methods.
*/
int Extension::LuaOpenAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		int result = ChromaAnimationAPI::OpenAnimation(path.c_str());
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaOpenAnimationD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::OpenAnimationD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Opens a `Chroma` animation data from memory so that it can be played. `Data`
	is a pointer to byte array of the loaded animation in memory. `Name` will
	be assigned to the animation when loaded. Returns an animation id >= 0
	upon success. Returns -1 if there was a failure. The animation id is used
	in most of the API methods.
*/
int Extension::LuaOpenAnimationFromMemory(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const byte*
		// FieldName: data
		// FieldType: const char*
		// FieldName: name
#pragma message("TODO - add support for OpenAnimationFromMemory")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Opens a `Chroma` animation file with the `.chroma` extension. Returns zero
	upon success. Returns -1 if there was a failure.
*/
int Extension::LuaOpenEditorDialog(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		int result = ChromaAnimationAPI::OpenEditorDialog(path.c_str());
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Open the named animation in the editor dialog and play the animation at
	start.
*/
int Extension::LuaOpenEditorDialogAndPlay(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		int result = ChromaAnimationAPI::OpenEditorDialogAndPlay(path.c_str());
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaOpenEditorDialogAndPlayD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::OpenEditorDialogAndPlayD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaOpenEditorDialogD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::OpenEditorDialogD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Sets the `duration` for all grames in the `Chroma` animation to the `duration`
	parameter. Returns the animation id upon success. Returns -1 upon failure.
*/
int Extension::LuaOverrideFrameDuration(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		float duration = (float)WrapperXLua::lua_tonumberW(state, 2);
		int result = ChromaAnimationAPI::OverrideFrameDuration(animationId, duration);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaOverrideFrameDurationD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double animationId = WrapperXLua::lua_tonumberW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double duration = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::OverrideFrameDurationD(animationId, duration);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Override the duration of all frames with the `duration` value. Animation
	is referenced by name.
*/
int Extension::LuaOverrideFrameDurationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		float duration = (float)WrapperXLua::lua_tonumberW(state, 2);
		ChromaAnimationAPI::OverrideFrameDurationName(path.c_str(), duration);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Pause the current animation referenced by id.
*/
int Extension::LuaPauseAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		ChromaAnimationAPI::PauseAnimation(animationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Pause the current animation referenced by name.
*/
int Extension::LuaPauseAnimationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::PauseAnimationName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaPauseAnimationNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::PauseAnimationNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Plays the `Chroma` animation. This will load the animation, if not loaded
	previously. Returns the animation id upon success. Returns -1 upon failure.
*/
int Extension::LuaPlayAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::PlayAnimation(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaPlayAnimationD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double animationId = WrapperXLua::lua_tonumberW(state, 1);
		double result = ChromaAnimationAPI::PlayAnimationD(animationId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginPlayAnimationFrame` automatically handles initializing the `ChromaSDK`.
	The method will play the animation given the `animationId` with looping
	`on` or `off` starting at the `frameId`.
*/
int Extension::LuaPlayAnimationFrame(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isbooleanW(state, 3))
		{
			return -1;
		}
		bool loop = WrapperXLua::lua_tobooleanW(state, 3) == 1;
		ChromaAnimationAPI::PlayAnimationFrame(animationId, frameId, loop);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginPlayAnimationFrameName` automatically handles initializing the `ChromaSDK`.
	The named `.chroma` animation file will be automatically opened. The animation
	will play with looping `on` or `off` starting at the `frameId`.
*/
int Extension::LuaPlayAnimationFrameName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isbooleanW(state, 3))
		{
			return -1;
		}
		bool loop = WrapperXLua::lua_tobooleanW(state, 3) == 1;
		ChromaAnimationAPI::PlayAnimationFrameName(path.c_str(), frameId, loop);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaPlayAnimationFrameNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double loop = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::PlayAnimationFrameNameD(path.c_str(), frameId, loop);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginPlayAnimationLoop` automatically handles initializing the `ChromaSDK`.
	The method will play the animation given the `animationId` with looping
	`on` or `off`.
*/
int Extension::LuaPlayAnimationLoop(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isbooleanW(state, 2))
		{
			return -1;
		}
		bool loop = WrapperXLua::lua_tobooleanW(state, 2) == 1;
		ChromaAnimationAPI::PlayAnimationLoop(animationId, loop);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginPlayAnimationName` automatically handles initializing the `ChromaSDK`.
	The named `.chroma` animation file will be automatically opened. The animation
	will play with looping `on` or `off`.
*/
int Extension::LuaPlayAnimationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isbooleanW(state, 2))
		{
			return -1;
		}
		bool loop = WrapperXLua::lua_tobooleanW(state, 2) == 1;
		ChromaAnimationAPI::PlayAnimationName(path.c_str(), loop);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaPlayAnimationNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double loop = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::PlayAnimationNameD(path.c_str(), loop);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginPlayComposite` automatically handles initializing the `ChromaSDK`.
	The named animation files for the `.chroma` set will be automatically opened.
	The set of animations will play with looping `on` or `off`.
*/
int Extension::LuaPlayComposite(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string name = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isbooleanW(state, 2))
		{
			return -1;
		}
		bool loop = WrapperXLua::lua_tobooleanW(state, 2) == 1;
		ChromaAnimationAPI::PlayComposite(name.c_str(), loop);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaPlayCompositeD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string name = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double loop = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::PlayCompositeD(name.c_str(), loop);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Displays the `Chroma` animation frame on `Chroma` hardware given the `frameIndex`.
	Returns the animation id upon success. Returns -1 upon failure.
*/
int Extension::LuaPreviewFrame(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameIndex = WrapperXLua::lua_tointegerW(state, 2);
		int result = ChromaAnimationAPI::PreviewFrame(animationId, frameIndex);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaPreviewFrameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double animationId = WrapperXLua::lua_tonumberW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameIndex = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::PreviewFrameD(animationId, frameIndex);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Displays the `Chroma` animation frame on `Chroma` hardware given the `frameIndex`.
	Animaton is referenced by name.
*/
int Extension::LuaPreviewFrameName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameIndex = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::PreviewFrameName(path.c_str(), frameIndex);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Reduce the frames of the animation by removing every nth element. Animation
	is referenced by id.
*/
int Extension::LuaReduceFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int n = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::ReduceFrames(animationId, n);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Reduce the frames of the animation by removing every nth element. Animation
	is referenced by name.
*/
int Extension::LuaReduceFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int n = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::ReduceFramesName(path.c_str(), n);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaReduceFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double n = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::ReduceFramesNameD(path.c_str(), n);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Resets the `Chroma` animation to 1 blank frame. Returns the animation id
	upon success. Returns -1 upon failure.
*/
int Extension::LuaResetAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::ResetAnimation(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Resume the animation with loop `ON` or `OFF` referenced by id.
*/
int Extension::LuaResumeAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isbooleanW(state, 2))
		{
			return -1;
		}
		bool loop = WrapperXLua::lua_tobooleanW(state, 2) == 1;
		ChromaAnimationAPI::ResumeAnimation(animationId, loop);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Resume the animation with loop `ON` or `OFF` referenced by name.
*/
int Extension::LuaResumeAnimationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isbooleanW(state, 2))
		{
			return -1;
		}
		bool loop = WrapperXLua::lua_tobooleanW(state, 2) == 1;
		ChromaAnimationAPI::ResumeAnimationName(path.c_str(), loop);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaResumeAnimationNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double loop = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::ResumeAnimationNameD(path.c_str(), loop);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Reverse the animation frame order of the `Chroma` animation. Returns the
	animation id upon success. Returns -1 upon failure. Animation is referenced
	by id.
*/
int Extension::LuaReverse(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::Reverse(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Reverse the animation frame order of the `Chroma` animation. Animation is
	referenced by id.
*/
int Extension::LuaReverseAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		ChromaAnimationAPI::ReverseAllFrames(animationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Reverse the animation frame order of the `Chroma` animation. Animation is
	referenced by name.
*/
int Extension::LuaReverseAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::ReverseAllFramesName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaReverseAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::ReverseAllFramesNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Save the animation referenced by id to the path specified.
*/
int Extension::LuaSaveAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 2);
		int result = ChromaAnimationAPI::SaveAnimation(animationId, path.c_str());
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Save the named animation to the target path specified.
*/
int Extension::LuaSaveAnimationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		int result = ChromaAnimationAPI::SaveAnimationName(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set the animation color for a frame given the `1D` `led`. The `led` should
	be greater than or equal to 0 and less than the `MaxLeds`. The animation
	is referenced by id.
*/
int Extension::LuaSet1DColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int led = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::Set1DColor(animationId, frameId, led, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the animation color for a frame given the `1D` `led`. The `led` should
	be greater than or equal to 0 and less than the `MaxLeds`. The animation
	is referenced by name.
*/
int Extension::LuaSet1DColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int led = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::Set1DColorName(path.c_str(), frameId, led, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSet1DColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double led = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::Set1DColorNameD(path.c_str(), frameId, led, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set the animation color for a frame given the `2D` `row` and `column`. The
	`row` should be greater than or equal to 0 and less than the `MaxRow`.
	The `column` should be greater than or equal to 0 and less than the `MaxColumn`.
	The animation is referenced by id.
*/
int Extension::LuaSet2DColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int row = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int column = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::Set2DColor(animationId, frameId, row, column, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the animation color for a frame given the `2D` `row` and `column`. The
	`row` should be greater than or equal to 0 and less than the `MaxRow`.
	The `column` should be greater than or equal to 0 and less than the `MaxColumn`.
	The animation is referenced by name.
*/
int Extension::LuaSet2DColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int row = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int column = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::Set2DColorName(path.c_str(), frameId, row, column, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSet2DColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double rowColumnIndex = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::Set2DColorNameD(path.c_str(), frameId, rowColumnIndex, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	When custom color is set, the custom key mode will be used. The animation
	is referenced by id.
*/
int Extension::LuaSetChromaCustomColorAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		ChromaAnimationAPI::SetChromaCustomColorAllFrames(animationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	When custom color is set, the custom key mode will be used. The animation
	is referenced by name.
*/
int Extension::LuaSetChromaCustomColorAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::SetChromaCustomColorAllFramesName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSetChromaCustomColorAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::SetChromaCustomColorAllFramesNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set the Chroma custom key color flag on all frames. `True` changes the layout
	from grid to key. `True` changes the layout from key to grid. Animation
	is referenced by id.
*/
int Extension::LuaSetChromaCustomFlag(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isbooleanW(state, 2))
		{
			return -1;
		}
		bool flag = WrapperXLua::lua_tobooleanW(state, 2) == 1;
		ChromaAnimationAPI::SetChromaCustomFlag(animationId, flag);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the Chroma custom key color flag on all frames. `True` changes the layout
	from grid to key. `True` changes the layout from key to grid. Animation
	is referenced by name.
*/
int Extension::LuaSetChromaCustomFlagName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isbooleanW(state, 2))
		{
			return -1;
		}
		bool flag = WrapperXLua::lua_tobooleanW(state, 2) == 1;
		ChromaAnimationAPI::SetChromaCustomFlagName(path.c_str(), flag);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSetChromaCustomFlagNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double flag = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::SetChromaCustomFlagNameD(path.c_str(), flag);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set the current frame of the animation referenced by id.
*/
int Extension::LuaSetCurrentFrame(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::SetCurrentFrame(animationId, frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the current frame of the animation referenced by name.
*/
int Extension::LuaSetCurrentFrameName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::SetCurrentFrameName(path.c_str(), frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSetCurrentFrameNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::SetCurrentFrameNameD(path.c_str(), frameId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Changes the `deviceType` and `device` of a `Chroma` animation. If the device
	is changed, the `Chroma` animation will be reset with 1 blank frame. Returns
	the animation id upon success. Returns -1 upon failure.
*/
int Extension::LuaSetDevice(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int deviceType = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int device = WrapperXLua::lua_tointegerW(state, 3);
		int result = ChromaAnimationAPI::SetDevice(animationId, deviceType, device);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	SetEffect will display the referenced effect id.
*/
int Extension::LuaSetEffect(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const ChromaSDK::FChromaSDKGuid&
		// FieldName: effectId
#pragma message("TODO - add support for SetEffect")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	When the idle animation is used, the named animation will play when no other
	animations are playing. Reference the animation by id.
*/
int Extension::LuaSetIdleAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		ChromaAnimationAPI::SetIdleAnimation(animationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	When the idle animation is used, the named animation will play when no other
	animations are playing. Reference the animation by name.
*/
int Extension::LuaSetIdleAnimationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::SetIdleAnimationName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set animation key to a static color for the given frame.
*/
int Extension::LuaSetKeyColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::SetKeyColor(animationId, frameId, rzkey, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the key to the specified key color for all frames. Animation is referenced
	by id.
*/
int Extension::LuaSetKeyColorAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::SetKeyColorAllFrames(animationId, rzkey, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the key to the specified key color for all frames. Animation is referenced
	by name.
*/
int Extension::LuaSetKeyColorAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::SetKeyColorAllFramesName(path.c_str(), rzkey, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSetKeyColorAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::SetKeyColorAllFramesNameD(path.c_str(), rzkey, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set the key to the specified key color for all frames. Animation is referenced
	by id.
*/
int Extension::LuaSetKeyColorAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::SetKeyColorAllFramesRGB(animationId, rzkey, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the key to the specified key color for all frames. Animation is referenced
	by name.
*/
int Extension::LuaSetKeyColorAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 5);
		ChromaAnimationAPI::SetKeyColorAllFramesRGBName(path.c_str(), rzkey, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSetKeyColorAllFramesRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 5);
		double result = ChromaAnimationAPI::SetKeyColorAllFramesRGBNameD(path.c_str(), rzkey, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set animation key to a static color for the given frame.
*/
int Extension::LuaSetKeyColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::SetKeyColorName(path.c_str(), frameId, rzkey, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSetKeyColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::SetKeyColorNameD(path.c_str(), frameId, rzkey, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set the key to the specified key color for the specified frame. Animation
	is referenced by id.
*/
int Extension::LuaSetKeyColorRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 6);
		ChromaAnimationAPI::SetKeyColorRGB(animationId, frameId, rzkey, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the key to the specified key color for the specified frame. Animation
	is referenced by name.
*/
int Extension::LuaSetKeyColorRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 6);
		ChromaAnimationAPI::SetKeyColorRGBName(path.c_str(), frameId, rzkey, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSetKeyColorRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 6);
		double result = ChromaAnimationAPI::SetKeyColorRGBNameD(path.c_str(), frameId, rzkey, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set animation key to a static color for the given frame if the existing
	color is not already black.
*/
int Extension::LuaSetKeyNonZeroColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::SetKeyNonZeroColor(animationId, frameId, rzkey, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set animation key to a static color for the given frame if the existing
	color is not already black.
*/
int Extension::LuaSetKeyNonZeroColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::SetKeyNonZeroColorName(path.c_str(), frameId, rzkey, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSetKeyNonZeroColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::SetKeyNonZeroColorNameD(path.c_str(), frameId, rzkey, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set the key to the specified key color for the specified frame where color
	is not black. Animation is referenced by id.
*/
int Extension::LuaSetKeyNonZeroColorRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 6);
		ChromaAnimationAPI::SetKeyNonZeroColorRGB(animationId, frameId, rzkey, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set the key to the specified key color for the specified frame where color
	is not black. Animation is referenced by name.
*/
int Extension::LuaSetKeyNonZeroColorRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 6);
		ChromaAnimationAPI::SetKeyNonZeroColorRGBName(path.c_str(), frameId, rzkey, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSetKeyNonZeroColorRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 6);
		double result = ChromaAnimationAPI::SetKeyNonZeroColorRGBNameD(path.c_str(), frameId, rzkey, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame. Animation
	is referenced by id.
*/
int Extension::LuaSetKeysColor(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: color
#pragma message("TODO - add support for SetKeysColor")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for all frames. Animation
	is referenced by id.
*/
int Extension::LuaSetKeysColorAllFrames(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: color
#pragma message("TODO - add support for SetKeysColorAllFrames")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for all frames. Animation
	is referenced by name.
*/
int Extension::LuaSetKeysColorAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		// is table
		if (!WrapperXLua::lua_istableW(state, 2))
		{
			return -1;
		}
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int keyCount = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		int* rzkeys = new int[keyCount];
		for (int i = 0; i < keyCount; ++i)
		{
			// copy integers from lua type
			WrapperXLua::lua_rawgetiW(state, 2, i);
			rzkeys[i] = WrapperXLua::lua_tointegerW(state, -1);
		}
		ChromaAnimationAPI::SetKeysColorAllFramesName(path.c_str(), rzkeys, keyCount, color);
		delete[] rzkeys;
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for all frames. Animation
	is referenced by id.
*/
int Extension::LuaSetKeysColorAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: red
		// FieldType: int
		// FieldName: green
		// FieldType: int
		// FieldName: blue
#pragma message("TODO - add support for SetKeysColorAllFramesRGB")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for all frames. Animation
	is referenced by name.
*/
int Extension::LuaSetKeysColorAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: path
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: red
		// FieldType: int
		// FieldName: green
		// FieldType: int
		// FieldName: blue
#pragma message("TODO - add support for SetKeysColorAllFramesRGBName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame.
*/
int Extension::LuaSetKeysColorName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: path
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: color
#pragma message("TODO - add support for SetKeysColorName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame. Animation
	is referenced by id.
*/
int Extension::LuaSetKeysColorRGB(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: red
		// FieldType: int
		// FieldName: green
		// FieldType: int
		// FieldName: blue
#pragma message("TODO - add support for SetKeysColorRGB")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame. Animation
	is referenced by name.
*/
int Extension::LuaSetKeysColorRGBName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: path
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: red
		// FieldType: int
		// FieldName: green
		// FieldType: int
		// FieldName: blue
#pragma message("TODO - add support for SetKeysColorRGBName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame if
	the existing color is not already black.
*/
int Extension::LuaSetKeysNonZeroColor(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: color
#pragma message("TODO - add support for SetKeysNonZeroColor")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame where
	the color is not black. Animation is referenced by id.
*/
int Extension::LuaSetKeysNonZeroColorAllFrames(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: color
#pragma message("TODO - add support for SetKeysNonZeroColorAllFrames")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for all frames if the existing
	color is not already black. Reference animation by name.
*/
int Extension::LuaSetKeysNonZeroColorAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: path
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: color
#pragma message("TODO - add support for SetKeysNonZeroColorAllFramesName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame if
	the existing color is not already black. Reference animation by name.
*/
int Extension::LuaSetKeysNonZeroColorName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: path
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: color
#pragma message("TODO - add support for SetKeysNonZeroColorName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame where
	the color is not black. Animation is referenced by id.
*/
int Extension::LuaSetKeysNonZeroColorRGB(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: red
		// FieldType: int
		// FieldName: green
		// FieldType: int
		// FieldName: blue
#pragma message("TODO - add support for SetKeysNonZeroColorRGB")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame where
	the color is not black. Animation is referenced by name.
*/
int Extension::LuaSetKeysNonZeroColorRGBName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: path
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: red
		// FieldType: int
		// FieldName: green
		// FieldType: int
		// FieldName: blue
#pragma message("TODO - add support for SetKeysNonZeroColorRGBName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame where
	the color is black. Animation is referenced by id.
*/
int Extension::LuaSetKeysZeroColor(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: color
#pragma message("TODO - add support for SetKeysZeroColor")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for all frames where the
	color is black. Animation is referenced by id.
*/
int Extension::LuaSetKeysZeroColorAllFrames(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: color
#pragma message("TODO - add support for SetKeysZeroColorAllFrames")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for all frames where the
	color is black. Animation is referenced by name.
*/
int Extension::LuaSetKeysZeroColorAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: path
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: color
#pragma message("TODO - add support for SetKeysZeroColorAllFramesName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for all frames where the
	color is black. Animation is referenced by id.
*/
int Extension::LuaSetKeysZeroColorAllFramesRGB(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: red
		// FieldType: int
		// FieldName: green
		// FieldType: int
		// FieldName: blue
#pragma message("TODO - add support for SetKeysZeroColorAllFramesRGB")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for all frames where the
	color is black. Animation is referenced by name.
*/
int Extension::LuaSetKeysZeroColorAllFramesRGBName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: path
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: red
		// FieldType: int
		// FieldName: green
		// FieldType: int
		// FieldName: blue
#pragma message("TODO - add support for SetKeysZeroColorAllFramesRGBName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame where
	the color is black. Animation is referenced by name.
*/
int Extension::LuaSetKeysZeroColorName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: path
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: color
#pragma message("TODO - add support for SetKeysZeroColorName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame where
	the color is black. Animation is referenced by id.
*/
int Extension::LuaSetKeysZeroColorRGB(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: red
		// FieldType: int
		// FieldName: green
		// FieldType: int
		// FieldName: blue
#pragma message("TODO - add support for SetKeysZeroColorRGB")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set an array of animation keys to a static color for the given frame where
	the color is black. Animation is referenced by name.
*/
int Extension::LuaSetKeysZeroColorRGBName(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: const char*
		// FieldName: path
		// FieldType: int
		// FieldName: frameId
		// FieldType: const int*
		// FieldName: rzkeys
		// FieldType: int
		// FieldName: keyCount
		// FieldType: int
		// FieldName: red
		// FieldType: int
		// FieldName: green
		// FieldType: int
		// FieldName: blue
#pragma message("TODO - add support for SetKeysZeroColorRGBName")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set animation key to a static color for the given frame where the color
	is black. Animation is referenced by id.
*/
int Extension::LuaSetKeyZeroColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::SetKeyZeroColor(animationId, frameId, rzkey, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set animation key to a static color for the given frame where the color
	is black. Animation is referenced by name.
*/
int Extension::LuaSetKeyZeroColorName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::SetKeyZeroColorName(path.c_str(), frameId, rzkey, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSetKeyZeroColorNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::SetKeyZeroColorNameD(path.c_str(), frameId, rzkey, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Set animation key to a static color for the given frame where the color
	is black. Animation is referenced by id.
*/
int Extension::LuaSetKeyZeroColorRGB(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 6);
		ChromaAnimationAPI::SetKeyZeroColorRGB(animationId, frameId, rzkey, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set animation key to a static color for the given frame where the color
	is black. Animation is referenced by name.
*/
int Extension::LuaSetKeyZeroColorRGBName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int rzkey = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int red = WrapperXLua::lua_tointegerW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		int green = WrapperXLua::lua_tointegerW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		int blue = WrapperXLua::lua_tointegerW(state, 6);
		ChromaAnimationAPI::SetKeyZeroColorRGBName(path.c_str(), frameId, rzkey, red, green, blue);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSetKeyZeroColorRGBNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double rzkey = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double red = WrapperXLua::lua_tonumberW(state, 4);
		if (!WrapperXLua::lua_isnumberW(state, 5))
		{
			return -1;
		}
		double green = WrapperXLua::lua_tonumberW(state, 5);
		if (!WrapperXLua::lua_isnumberW(state, 6))
		{
			return -1;
		}
		double blue = WrapperXLua::lua_tonumberW(state, 6);
		double result = ChromaAnimationAPI::SetKeyZeroColorRGBNameD(path.c_str(), frameId, rzkey, red, green, blue);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Invokes the setup for a debug logging callback so that `stdout` is redirected
	to the callback. This is used by `Unity` so that debug messages can appear
	in the console window.
*/
int Extension::LuaSetLogDelegate(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: DebugLogPtr
		// FieldName: fp
#pragma message("TODO - add support for SetLogDelegate")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginStaticColor` sets the target device to the static color.
*/
int Extension::LuaStaticColor(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int deviceType = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int device = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int color = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::StaticColor(deviceType, device, color);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaStaticColorD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double deviceType = WrapperXLua::lua_tonumberW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double device = WrapperXLua::lua_tonumberW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double color = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::StaticColorD(deviceType, device, color);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginStopAll` will automatically stop all animations that are playing.
*/
int Extension::LuaStopAll(lua::lua_State* state)
{
	if (state)
	{
		ChromaAnimationAPI::StopAll();
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Stops animation playback if in progress. Returns the animation id upon success.
	Returns -1 upon failure.
*/
int Extension::LuaStopAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::StopAnimation(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaStopAnimationD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double animationId = WrapperXLua::lua_tonumberW(state, 1);
		double result = ChromaAnimationAPI::StopAnimationD(animationId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginStopAnimationName` automatically handles initializing the `ChromaSDK`.
	The named `.chroma` animation file will be automatically opened. The animation
	will stop if playing.
*/
int Extension::LuaStopAnimationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::StopAnimationName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaStopAnimationNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::StopAnimationNameD(path.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginStopAnimationType` automatically handles initializing the `ChromaSDK`.
	If any animation is playing for the `deviceType` and `device` combination,
	it will be stopped.
*/
int Extension::LuaStopAnimationType(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int deviceType = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int device = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::StopAnimationType(deviceType, device);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaStopAnimationTypeD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double deviceType = WrapperXLua::lua_tonumberW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double device = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::StopAnimationTypeD(deviceType, device);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	`PluginStopComposite` automatically handles initializing the `ChromaSDK`.
	The named animation files for the `.chroma` set will be automatically opened.
	The set of animations will be stopped if playing.
*/
int Extension::LuaStopComposite(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string name = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::StopComposite(name.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaStopCompositeD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string name = WrapperXLua::lua_tostringW(state, 1);
		double result = ChromaAnimationAPI::StopCompositeD(name.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target color for all frames where the
	target color is not black. Source and target are referenced by id.
*/
int Extension::LuaSubtractNonZeroAllKeysAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::SubtractNonZeroAllKeysAllFrames(sourceAnimationId, targetAnimationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target color for all frames where the
	target color is not black. Source and target are referenced by name.
*/
int Extension::LuaSubtractNonZeroAllKeysAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		ChromaAnimationAPI::SubtractNonZeroAllKeysAllFramesName(sourceAnimation.c_str(), targetAnimation.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSubtractNonZeroAllKeysAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		double result = ChromaAnimationAPI::SubtractNonZeroAllKeysAllFramesNameD(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target color for all frames where the
	target color is not black starting at offset for the length of the source.
	Source and target are referenced by id.
*/
int Extension::LuaSubtractNonZeroAllKeysAllFramesOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::SubtractNonZeroAllKeysAllFramesOffset(sourceAnimationId, targetAnimationId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target color for all frames where the
	target color is not black starting at offset for the length of the source.
	Source and target are referenced by name.
*/
int Extension::LuaSubtractNonZeroAllKeysAllFramesOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::SubtractNonZeroAllKeysAllFramesOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSubtractNonZeroAllKeysAllFramesOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::SubtractNonZeroAllKeysAllFramesOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target where color is not black for the
	source frame and target offset frame, reference source and target by id.
*/
int Extension::LuaSubtractNonZeroAllKeysOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::SubtractNonZeroAllKeysOffset(sourceAnimationId, targetAnimationId, frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target where color is not black for the
	source frame and target offset frame, reference source and target by name.
*/
int Extension::LuaSubtractNonZeroAllKeysOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::SubtractNonZeroAllKeysOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSubtractNonZeroAllKeysOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::SubtractNonZeroAllKeysOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target color where the target color is
	not black for all frames. Reference source and target by id.
*/
int Extension::LuaSubtractNonZeroTargetAllKeysAllFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::SubtractNonZeroTargetAllKeysAllFrames(sourceAnimationId, targetAnimationId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target color where the target color is
	not black for all frames. Reference source and target by name.
*/
int Extension::LuaSubtractNonZeroTargetAllKeysAllFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		ChromaAnimationAPI::SubtractNonZeroTargetAllKeysAllFramesName(sourceAnimation.c_str(), targetAnimation.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSubtractNonZeroTargetAllKeysAllFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		double result = ChromaAnimationAPI::SubtractNonZeroTargetAllKeysAllFramesNameD(sourceAnimation.c_str(), targetAnimation.c_str());
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target color where the target color is
	not black for all frames starting at the target offset for the length of
	the source. Reference source and target by id.
*/
int Extension::LuaSubtractNonZeroTargetAllKeysAllFramesOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::SubtractNonZeroTargetAllKeysAllFramesOffset(sourceAnimationId, targetAnimationId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target color where the target color is
	not black for all frames starting at the target offset for the length of
	the source. Reference source and target by name.
*/
int Extension::LuaSubtractNonZeroTargetAllKeysAllFramesOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 3);
		ChromaAnimationAPI::SubtractNonZeroTargetAllKeysAllFramesOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSubtractNonZeroTargetAllKeysAllFramesOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 3);
		double result = ChromaAnimationAPI::SubtractNonZeroTargetAllKeysAllFramesOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target color where the target color is
	not black from the source frame to the target offset frame. Reference source
	and target by id.
*/
int Extension::LuaSubtractNonZeroTargetAllKeysOffset(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int sourceAnimationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int targetAnimationId = WrapperXLua::lua_tointegerW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::SubtractNonZeroTargetAllKeysOffset(sourceAnimationId, targetAnimationId, frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Subtract the source color from the target color where the target color is
	not black from the source frame to the target offset frame. Reference source
	and target by name.
*/
int Extension::LuaSubtractNonZeroTargetAllKeysOffsetName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		int offset = WrapperXLua::lua_tointegerW(state, 4);
		ChromaAnimationAPI::SubtractNonZeroTargetAllKeysOffsetName(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaSubtractNonZeroTargetAllKeysOffsetNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string sourceAnimation = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isstringW(state, 2))
		{
			return -1;
		}
		string targetAnimation = WrapperXLua::lua_tostringW(state, 2);
		if (!WrapperXLua::lua_isnumberW(state, 3))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 3);
		if (!WrapperXLua::lua_isnumberW(state, 4))
		{
			return -1;
		}
		double offset = WrapperXLua::lua_tonumberW(state, 4);
		double result = ChromaAnimationAPI::SubtractNonZeroTargetAllKeysOffsetNameD(sourceAnimation.c_str(), targetAnimation.c_str(), frameId, offset);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Trim the end of the animation. The length of the animation will be the lastFrameId
	+ 1. Reference the animation by id.
*/
int Extension::LuaTrimEndFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int lastFrameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::TrimEndFrames(animationId, lastFrameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Trim the end of the animation. The length of the animation will be the lastFrameId
	+ 1. Reference the animation by name.
*/
int Extension::LuaTrimEndFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int lastFrameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::TrimEndFramesName(path.c_str(), lastFrameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaTrimEndFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double lastFrameId = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::TrimEndFramesNameD(path.c_str(), lastFrameId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Remove the frame from the animation. Reference animation by id.
*/
int Extension::LuaTrimFrame(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::TrimFrame(animationId, frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Remove the frame from the animation. Reference animation by name.
*/
int Extension::LuaTrimFrameName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int frameId = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::TrimFrameName(path.c_str(), frameId);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaTrimFrameNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double frameId = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::TrimFrameNameD(path.c_str(), frameId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Trim the start of the animation starting at frame 0 for the number of frames.
	Reference the animation by id.
*/
int Extension::LuaTrimStartFrames(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int numberOfFrames = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::TrimStartFrames(animationId, numberOfFrames);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Trim the start of the animation starting at frame 0 for the number of frames.
	Reference the animation by name.
*/
int Extension::LuaTrimStartFramesName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		int numberOfFrames = WrapperXLua::lua_tointegerW(state, 2);
		ChromaAnimationAPI::TrimStartFramesName(path.c_str(), numberOfFrames);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaTrimStartFramesNameD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isnumberW(state, 2))
		{
			return -1;
		}
		double numberOfFrames = WrapperXLua::lua_tonumberW(state, 2);
		double result = ChromaAnimationAPI::TrimStartFramesNameD(path.c_str(), numberOfFrames);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Uninitializes the `ChromaSDK`. Returns 0 upon success. Returns -1 upon failure.
*/
int Extension::LuaUninit(lua::lua_State* state)
{
	if (state)
	{
		ChromaAnimationAPI::Uninit();
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaUninitD(lua::lua_State* state)
{
	if (state)
	{
		double result = ChromaAnimationAPI::UninitD();
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Unloads `Chroma` effects to free up resources. Returns the animation id
	upon success. Returns -1 upon failure. Reference the animation by id.
*/
int Extension::LuaUnloadAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		int result = ChromaAnimationAPI::UnloadAnimation(animationId);
		lua::lua_pushinteger(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	D suffix for limited data types.
*/
int Extension::LuaUnloadAnimationD(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		double animationId = WrapperXLua::lua_tonumberW(state, 1);
		double result = ChromaAnimationAPI::UnloadAnimationD(animationId);
		lua::lua_pushnumber(state, result);
		return 1;
	}
	else
	{
		return -1;
	}
}

/*
	Unload the animation effects. Reference the animation by name.
*/
int Extension::LuaUnloadAnimationName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::UnloadAnimationName(path.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Unload the the composite set of animation effects. Reference the animation
	by name.
*/
int Extension::LuaUnloadComposite(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string name = WrapperXLua::lua_tostringW(state, 1);
		ChromaAnimationAPI::UnloadComposite(name.c_str());
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Updates the `frameIndex` of the `Chroma` animation and sets the `duration`
	(in seconds). The `color` is expected to be an array of the dimensions
	for the `deviceType/device`. The `length` parameter is the size of the
	`color` array. For `EChromaSDKDevice1DEnum` the array size should be `MAX
	LEDS`. For `EChromaSDKDevice2DEnum` the array size should be `MAX ROW`
	* `MAX COLUMN`. Returns the animation id upon success. Returns -1 upon
	failure.
*/
int Extension::LuaUpdateFrame(lua::lua_State* state)
{
	if (state)
	{
		// FieldType: int
		// FieldName: animationId
		// FieldType: int
		// FieldName: frameIndex
		// FieldType: float
		// FieldName: duration
		// FieldType: int*
		// FieldName: colors
		// FieldType: int
		// FieldName: length
#pragma message("TODO - add support for UpdateFrame")
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	When the idle animation flag is true, when no other animations are playing,
	the idle animation will be used. The idle animation will not be affected
	by the API calls to PluginIsPlaying, PluginStopAnimationType, PluginGetPlayingAnimationId,
	and PluginGetPlayingAnimationCount. Then the idle animation flag is false,
	the idle animation is disabled. `Device` uses `EChromaSDKDeviceEnum` enums.
*/
int Extension::LuaUseIdleAnimation(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int device = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isbooleanW(state, 2))
		{
			return -1;
		}
		bool flag = WrapperXLua::lua_tobooleanW(state, 2) == 1;
		ChromaAnimationAPI::UseIdleAnimation(device, flag);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set idle animation flag for all devices.
*/
int Extension::LuaUseIdleAnimations(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isbooleanW(state, 1))
		{
			return -1;
		}
		bool flag = WrapperXLua::lua_tobooleanW(state, 1) == 1;
		ChromaAnimationAPI::UseIdleAnimations(flag);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set preloading animation flag, which is set to true by default. Reference
	animation by id.
*/
int Extension::LuaUsePreloading(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isnumberW(state, 1))
		{
			return -1;
		}
		int animationId = WrapperXLua::lua_tointegerW(state, 1);
		if (!WrapperXLua::lua_isbooleanW(state, 2))
		{
			return -1;
		}
		bool flag = WrapperXLua::lua_tobooleanW(state, 2) == 1;
		ChromaAnimationAPI::UsePreloading(animationId, flag);
		return 0;
	}
	else
	{
		return -1;
	}
}

/*
	Set preloading animation flag, which is set to true by default. Reference
	animation by name.
*/
int Extension::LuaUsePreloadingName(lua::lua_State* state)
{
	if (state)
	{
		if (!WrapperXLua::lua_isstringW(state, 1))
		{
			return -1;
		}
		string path = WrapperXLua::lua_tostringW(state, 1);
		if (!WrapperXLua::lua_isbooleanW(state, 2))
		{
			return -1;
		}
		bool flag = WrapperXLua::lua_tobooleanW(state, 2) == 1;
		ChromaAnimationAPI::UsePreloadingName(path.c_str(), flag);
		return 0;
	}
	else
	{
		return -1;
	}
}

#pragma endregion

#pragma comment(lib, "Imm32.lib") //causing Unicode error
