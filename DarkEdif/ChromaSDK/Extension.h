#include <DarkEdif.h>
#include "Public/RzChromaSDKTypes.h"
#include "Public/RzErrors.h"


namespace lua
{
	class XLuaState;
	typedef struct lua_State lua_State;
}


class Extension
{
public:

	RUNDATA * rdPtr;
	RunHeader *	rhPtr;

	Edif::Runtime Runtime;

	static const int MinimumBuild = 254;
	static const int Version = 1;

	static const OEFLAGS OEFLAGS = OEFLAGS::NONE;
	static const OEPREFS OEPREFS = OEPREFS::NONE;
	
	static const int WindowProcPriority = 100;

	Extension(RUNDATA * rdPtr, EDITDATA * edPtr, CreateObjectInfo * cobPtr);
	~Extension();

	// To add items to the Fusion Debugger, just uncomment this line.
	DarkEdif::FusionDebugger FusionDebugger;
	// After enabling it, you run FusionDebugger.AddItemToDebugger() inside Extension's constructor
	// As an example:
	std::tstring exampleDebuggerTextItem;

	/*  Add any data you want to store in your extension to this class
		(eg. what you'd normally store in rdPtr in old SDKs).

		Unlike rdPtr, you can store real C++ objects with constructors
		and destructors, without having to call them manually or store
		a pointer.
	*/



	

	// int MyVariable;




	/*  Add your actions, conditions and expressions as real class member
		functions here. The arguments (and return type for expressions) must
		match EXACTLY what you defined in the JSON.

		Remember to link the actions, conditions and expressions to their
		numeric IDs in the class constructor (Extension.cpp)
	*/

	/// Actions

		void ActInit();

		void PlayAnimationName(const TCHAR* path, int loop);
		void StopAnimationName(const TCHAR* path);

		void PlayComposite(const TCHAR* name, int loop);

		void StaticColor(int deviceType, int device, int color);
		void StaticColorAllDevices(int color);

		void CloseAnimationName(const TCHAR* path);
		void GetAnimation(const TCHAR* path);

		void DuplicateFirstFrameName(const TCHAR* path, int frameCount);
		void DuplicateFramesName(const TCHAR* path);
		void MakeBlankFramesName(const TCHAR* path, int frameCount, float duration, int color);
		void ReduceFramesName(const TCHAR* path, int n);
		void InsertDelayName(const TCHAR* path, int frameId, int delay);
		void TrimStartFramesName(const TCHAR* path, int numberOfFrames);
		void TrimEndFramesName(const TCHAR* path, int lastFrameId);

		void MultiplyTargetColorLerpAllFramesName(const TCHAR* path, int color1, int color2);
		void MultiplyNonZeroTargetColorLerpAllFramesName(const TCHAR* path, int color1, int color2);

		void FillZeroColorAllFramesName(const TCHAR* path, int color);
		void OffsetColorsAllFramesName(const TCHAR* path, int red, int green, int blue);

		void CopyNonZeroTargetAllKeysAllFramesName(const TCHAR* sourceAnimation, const TCHAR* targetAnimation);
		void CopyNonZeroAllKeysAllFramesName(const TCHAR* sourceAnimation, const TCHAR* targetAnimation);

		lua::XLuaState* GetLuaState();

		void RegisterLuaFunctions();

		static int LuaPlayAnimationName(lua::lua_State* state);

		void ActLuaLoadString(const TCHAR* source);
		void ActLuaLoadFile(const TCHAR* source);

	/// Conditions

		bool CondIsInitialized();
		bool CondInit();

	/// Expressions
		
		int ExpIsInitialized();
		int ExpInit();

		int ExpGetRGB(int red, int green, int blue);

		int ExpGetIntDeviceType(const TCHAR* name);
		int ExpGetIntDevice(const TCHAR* name);

		int ExpGetFrameCountName(const TCHAR* path);



	/* These are called if there's no function linked to an ID */

	void Action(int ID, RUNDATA * rdPtr, long param1, long param2);
	long Condition(int ID, RUNDATA * rdPtr, long param1, long param2);
	long Expression(int ID, RUNDATA * rdPtr, long param);




	/*  These replace the functions like HandleRunObject that used to be
		implemented in Runtime.cpp. They work exactly the same, but they're
		inside the extension class.
	*/

	REFLAG Handle();
	REFLAG Display();

	short Pause();
	short Continue();
protected:
	RZRESULT _mInitResult;
};
