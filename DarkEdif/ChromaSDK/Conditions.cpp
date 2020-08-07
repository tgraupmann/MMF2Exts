#include "Common.h"
#include "Public/ChromaAnimationAPI.h"

using namespace ChromaSDK;

bool Extension::CondIsInitialized()
{
	/*
	OutputDebugStringA("CondIsInitialized: Result=");
	OutputDebugStringA(_sInitResult == RZRESULT_SUCCESS ? "SUCCESS" : "FAILED");
	OutputDebugStringA("\r\n");
	*/
	return _sInitResult == RZRESULT_SUCCESS;
}

bool Extension::CondInit()
{
	if (CondIsInitialized())
	{
		return true;
	}
	if (ChromaAnimationAPI::IsInitializedAPI())
	{
		APPINFOTYPE appInfo = {};

		_tcscpy_s(appInfo.Title, 256, _sAppInfoTitle.c_str());
		_tcscpy_s(appInfo.Description, 1024, _sAppInfoDescription.c_str());
		_tcscpy_s(appInfo.Author.Name, 256, _sAppInfoAuthorName.c_str());
		_tcscpy_s(appInfo.Author.Contact, 256, _sAppInfoAuthorContact.c_str());

		//appInfo.SupportedDevice = 
		//    0x01 | // Keyboards
		//    0x02 | // Mice
		//    0x04 | // Headset
		//    0x08 | // Mousepads
		//    0x10 | // Keypads
		//    0x20   // ChromaLink devices
		appInfo.SupportedDevice = (0x01 | 0x02 | 0x04 | 0x08 | 0x10 | 0x20);
		appInfo.Category = 1;

		_sInitResult = ChromaAnimationAPI::InitSDK(&appInfo);
	}
	return CondIsInitialized();
}
