
#include "Common.h"

const TCHAR * Extension::GetError()
{
	return Runtime.CopyString(error.str().c_str());
}

const TCHAR * Extension::GetActionMenu2()
{
	return Runtime.CopyString(menuStr[0].c_str());
}

const TCHAR * Extension::GetConditionMenu2()
{
	return Runtime.CopyString(menuStr[1].c_str());
}

const TCHAR * Extension::GetExpressionMenu2()
{
	return Runtime.CopyString(menuStr[2].c_str());
}

typedef void (FusionAPI * GetXXXStringFunc)(mv *mV, short actionID, TCHAR * strBuf, short maxLen);
typedef void * (FusionAPI * GetXXXInfosFunc)(mv * mV, short actionID);// Actually ACEInfo *, ID param
typedef void (FusionAPI * GetXXXTitleFunc)(mv *mV, short actionID, short paramID, TCHAR * strBuf, short maxLen);
typedef void (FusionAPI * GetExpressionParamFunc)(mv *mV, short actionID, short paramID, TCHAR * strBuf, short maxLen);
typedef short (FusionAPI * GetRunObjectInfosFunc)(mv * mV, kpxRunInfos * infoPtr);

#include <unordered_map>
static std::unordered_map<Params, std::tstring> actionAndConditionParamTypes
{
	// Taken from "Params" struct
	{ /*  1 */ Params::Object, _T("object") },
	{ /*  5 */ Params::Integer, _T("int") },
	{ /* 22 */ Params::Expression, _T("int") }, // Expression
	{ /* 28 */ Params::Text_Number, _T("text number") },
	{ /* 40 */ Params::Filename, _T("filename") },
	{ /* 41 */ Params::String, _T("string") },
	{ /* 45 */ Params::String_Expression, _T("string") },
	{ /* 55 */ Params::Extension, _T("extension") },
	{ /* 63 */ Params::Filename_2, _T("filename") }
};

static std::unordered_map<ExpParams, std::tstring> expressionParamTypes
{
	{ /*  1 */ ExpParams::Integer, _T("int") },
	{ /*  3 */ ExpParams::String, _T("string") },
};

const TCHAR * Extension::GetAllActionInfos()
{
	error.clear();
	error.str(std::tstring());
	if (filename.empty())
	{
		error << _T("MFX filename was empty.");
		return Runtime.CopyString(_T(""));
	}

	HINSTANCE hGetProcIDDLL = LoadLibrary(filename.c_str());
	if (!hGetProcIDDLL) {
		error << _T("Could not load the dynamic library a.k.a. MFX, error ") << GetLastError();
		return Runtime.CopyString(_T(""));
	}

	GetXXXStringFunc getActionStringFunc = (GetXXXStringFunc)GetProcAddress(hGetProcIDDLL, "GetActionString");
	GetXXXInfosFunc getActionInfosFunc = (GetXXXInfosFunc)GetProcAddress(hGetProcIDDLL, "GetActionInfos");
	GetXXXTitleFunc getActionTitleFunc = (GetXXXTitleFunc)GetProcAddress(hGetProcIDDLL, "GetActionTitle");
	GetRunObjectInfosFunc getRunObjectInfosFunc = (GetRunObjectInfosFunc)GetProcAddress(hGetProcIDDLL, "GetRunObjectInfos");
	auto runInfos = std::make_unique<kpxRunInfos>();

	if (!getActionStringFunc) {
		error << _T("Could not locate function GetActionString, error ") << GetLastError();
		FreeLibrary(hGetProcIDDLL);
		return Runtime.CopyString(_T(""));
	}
	if (!getActionInfosFunc) {
		error << _T("Could not locate function GetActionInfos, error ") << GetLastError();
		FreeLibrary(hGetProcIDDLL);
		return Runtime.CopyString(_T(""));
	}
	if (!getActionTitleFunc) {
		error << _T("Could not locate function GetActionTitle, error ") << GetLastError();
		FreeLibrary(hGetProcIDDLL);
		return Runtime.CopyString(_T(""));
	}
	if (!getRunObjectInfosFunc) {
		error << _T("Could not locate function GetActionTitle, error ") << GetLastError();
		FreeLibrary(hGetProcIDDLL);
		return Runtime.CopyString(_T(""));
	}

	std::tstringstream output;

	short ret = getRunObjectInfosFunc(SDK->mV, runInfos.get());
	output << "Size of EDITDATA: " << runInfos->EDITDATASize << ".";

	const short bufferSize = 512;
	std::unique_ptr<TCHAR[]> buffer = std::make_unique<TCHAR[]>(bufferSize);
	if (!buffer) {
		error << _T("Could not allocate memory");
		return Runtime.CopyString(_T(""));
	}

	//	short FusionAPI GetRunObjectInfos(mv * mV, kpxRunInfos * infoPtr)
	//	returns in infoPtr the number of actions
	for (short i = 0; ; i++)
	{
		try {
			getActionStringFunc(SDK->mV, i, buffer.get(), bufferSize);
			if (buffer[0] == _T('\0'))
				break;

			if (i < 10)
				output << _T("0");
			output << i << _T(": ") << buffer.get() << _T(" (");
			// Lazy man's pointer decrementation, see ACEInfo->MMFPtr()
			// fun->FloatFlags is not valid and should not be read
			ACEInfo * fun = (ACEInfo *)(((char *)getActionInfosFunc(SDK->mV, i)) - 2); // don't free
			for (short j = 0; j < fun->NumOfParams; j++)
			{
				if (actionAndConditionParamTypes.find(fun->Parameter[j].p) == actionAndConditionParamTypes.cend())
					output << _T("<UNKNOWN TYPE Params val ") << (short)fun->Parameter[j].p << _T("> ");
				else
					output << actionAndConditionParamTypes[fun->Parameter[j].p] << _T(" ");
				getActionTitleFunc(SDK->mV, i, j, buffer.get(), bufferSize);
				output << _T("\"") << buffer.get() << ((j == fun->NumOfParams - 1) ? _T("\" ") : _T("\", "));
			}
			output << _T(")\r\n");
			buffer[0] = _T('\0'); // null for next loop
		}
		catch (...)
		{
			error << _T("Some exception happened.");
			break;
		}
	}
	FreeLibrary(hGetProcIDDLL);
	return Runtime.CopyString(output.str().c_str());
}

const TCHAR * Extension::GetAllConditionInfos()
{
	error.clear();
	error.str(std::tstring());
	if (filename.empty())
	{
		error << _T("MFX filename was empty.");
		return Runtime.CopyString(_T(""));
	}

	HINSTANCE hGetProcIDDLL = LoadLibrary(filename.c_str());

	if (!hGetProcIDDLL) {
		error << _T("Could not load the dynamic library a.k.a. MFX, error ") << GetLastError();
		return Runtime.CopyString(_T(""));
	}

	GetXXXStringFunc getConditionStringFunc = (GetXXXStringFunc)GetProcAddress(hGetProcIDDLL, "GetConditionString");
	GetXXXInfosFunc getConditionInfosFunc = (GetXXXInfosFunc)GetProcAddress(hGetProcIDDLL, "GetConditionInfos");
	GetXXXTitleFunc getConditionTitleFunc = (GetXXXTitleFunc)GetProcAddress(hGetProcIDDLL, "GetConditionTitle");

	if (!getConditionStringFunc) {
		error << _T("Could not locate function GetConditionString, error ") << GetLastError();
		return Runtime.CopyString(_T(""));
	}
	if (!getConditionInfosFunc) {
		error << _T("Could not locate function GetConditionInfos, error ") << GetLastError();
		return Runtime.CopyString(_T(""));
	}
	if (!getConditionTitleFunc) {
		error << _T("Could not locate function GetConditionTitle, error ") << GetLastError();
		return Runtime.CopyString(_T(""));
	}

	std::tstringstream output;
	const short bufferSize = 512;
	std::unique_ptr<TCHAR[]> buffer = std::make_unique<TCHAR[]>(bufferSize);
	if (!buffer) {
		error << _T("Could not allocate memory");
		return Runtime.CopyString(_T(""));
	}

	//	short FusionAPI GetRunObjectInfos(mv * mV, kpxRunInfos * infoPtr)
	//	returns in infoPtr the number of conditions
	for (short i = 0; ; i++)
	{
		try {
			getConditionStringFunc(SDK->mV, i, buffer.get(), bufferSize);
			if (buffer[0] == _T('\0'))
				break;

			if (i < 10)
				output << _T("0");
			output << i << _T(": ") << buffer << _T(" (");
			// Lazy man's pointer decrementation, see ACEInfo->MMFPtr()
			// fun->FloatFlags is not valid and should not be read
			const ACEInfo * const fun = (ACEInfo *)(((char *)getConditionInfosFunc(SDK->mV, i)) - 2); // don't free
			for (short j = 0; j < fun->NumOfParams; j++)
			{
				if (actionAndConditionParamTypes.find(fun->Parameter[j].p) == actionAndConditionParamTypes.cend())
					output << _T("<UNKNOWN TYPE Params val ") << (short)fun->Parameter[j].p << _T("> ");
				else
					output << actionAndConditionParamTypes[fun->Parameter[j].p] << _T(" ");
				getConditionTitleFunc(SDK->mV, i, j, buffer.get(), bufferSize);
				output << _T("\"") << buffer.get() << ((j == fun->NumOfParams - 1) ? _T("\" ") : _T("\", "));
			}
			output << _T(")\r\n");
			buffer[0] = _T('\0');
		}
		catch (...)
		{
			error << _T("Some exception happened.");
			break;
		}
	}
	return Runtime.CopyString(output.str().c_str());
}

const TCHAR * Extension::GetAllExpressionInfos()
{
	error.clear();
	error.str(std::tstring());
	if (filename.empty())
	{
		error << _T("MFX filename was empty.");
		return Runtime.CopyString(_T(""));
	}

	HINSTANCE hGetProcIDDLL = LoadLibrary(filename.c_str());

	if (!hGetProcIDDLL) {
		error << _T("Could not load the dynamic library a.k.a. MFX, error ") << GetLastError();
		return Runtime.CopyString(_T(""));
	}

	GetXXXStringFunc getExpressionStringFunc = (GetXXXStringFunc)GetProcAddress(hGetProcIDDLL, "GetExpressionString");
	GetXXXInfosFunc getExpressionInfosFunc = (GetXXXInfosFunc)GetProcAddress(hGetProcIDDLL, "GetExpressionInfos");
	GetXXXTitleFunc getExpressionTitleFunc = (GetXXXTitleFunc)GetProcAddress(hGetProcIDDLL, "GetExpressionTitle");
	GetExpressionParamFunc getExpressionParamFunc = (GetExpressionParamFunc)GetProcAddress(hGetProcIDDLL, "GetExpressionParam");

	if (!getExpressionStringFunc) {
		error << _T("Could not locate function GetExpressionString, error ") << GetLastError();
		return Runtime.CopyString(_T(""));
	}
	if (!getExpressionInfosFunc) {
		error << _T("Could not locate function GetExpressionInfos, error ") << GetLastError();
		return Runtime.CopyString(_T(""));
	}
	if (!getExpressionTitleFunc) {
		error << _T("Could not locate function GetExpressionTitle, error ") << GetLastError();
		return Runtime.CopyString(_T(""));
	}

	std::tstringstream output;
	const short bufferSize = 512U;
	std::unique_ptr<TCHAR[]> buffer = std::make_unique<TCHAR[]>(bufferSize);
	if (!buffer) {
		error << _T("Could not allocate memory");
		return Runtime.CopyString(_T(""));
	}

	//	short DLLExport GetRunObjectInfos(mv * mV, kpxRunInfos * infoPtr)
	//	returns in infoPtr the number of expressions
	for (short i = 0; ; i++)
	{
		try {
			getExpressionStringFunc(SDK->mV, i, buffer.get(), bufferSize);
			if (buffer[0] == _T('\0'))
				break;

			if (i < 10)
				output << _T("0");
			output << i << _T(": ") << buffer.get(); // ( at end of buffer
			// Lazy man's pointer decrementation, see ACEInfo->MMFPtr()
			// fun->FloatFlags is not valid and should not be read
			ACEInfo * fun = (ACEInfo *)(((char *)getExpressionInfosFunc(SDK->mV, i)) - 2); // don't free

			for (short j = 0; j < fun->NumOfParams; j++)
			{
				if (expressionParamTypes.find(fun->Parameter[j].ep) == expressionParamTypes.cend())
					output << _T("<UNKNOWN TYPE ExpParams val ") << (short)fun->Parameter[j].ep;
				else
					output << _T("<") << expressionParamTypes[fun->Parameter[j].ep];
				getExpressionParamFunc(SDK->mV, i, j, buffer.get(), bufferSize);
				output << _T(" ") << buffer << ((j == fun->NumOfParams - 1) ? _T(">") : _T(">, "));
			}
			output << _T(")\r\n");
			buffer[0] = _T('\0'); // empty for next loop
		}
		catch (...)
		{
			break;
		}
	}

	return Runtime.CopyString(output.str().c_str());
}
