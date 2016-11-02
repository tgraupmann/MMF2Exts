class Extension
{
public:
	#ifdef MULTI_THREADING
		SaveExtInfo ThreadData; // Must be first variable in Extension class
		std::vector<SaveExtInfo *> Saved;
		SaveExtInfo & AddEvent(int Event, bool UseLastData = false);
		void NewEvent(SaveExtInfo *);
		// TODO: Threadsafe with a CRITICAL_SECTION
	#endif

    RUNDATA * rdPtr;
    RunHeader *    rhPtr;

    Edif::Runtime Runtime;

    static const int MinimumBuild = 254;
    static const int Version = 4;

    static const int OEFLAGS = 0; // See OEFLAG structure
    static const int OEPREFS = 0;
    
    static const int WindowProcPriority = 100;

    Extension(RUNDATA * rdPtr, EDITDATA * edPtr, CreateObjectInfo * cobPtr);
    ~Extension();


    /*  Add any data you want to store in your extension to this class
        (eg. what you'd normally store in rdPtr).
		
		For those using multi-threading, any variables that are modified
		by the threads should be set in ExtVariables.
		See MultiThreading.h.

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
		void UTF16StrToUTF8Mem(const wchar_t * utf16Str, int addr, int excludeNull);

    /// Conditions

    /// Expressions
        
        int UTF16CharToUTF16Int(const wchar_t * utf16Char);
		const wchar_t * UTF16IntToUTF16Char(unsigned int utf16ints);
		const wchar_t * UTF16StrFromUTF16Mem(long addr, int numChars);
		const wchar_t * UTF16StrFromUTF8Mem(long addr, int numChars);



    /* These are called if there's no function linked to an ID */

    void Action(int ID, RUNDATA * rdPtr, long param1, long param2);
    long Condition(int ID, RUNDATA * rdPtr, long param1, long param2);
    long Expression(int ID, RUNDATA * rdPtr, long param);




    /*  These replace the functions like HandleRunObject that used to be
        implemented in Runtime.cpp. They work exactly the same, but they're
        inside the extension class.
    */

    short Handle();
    short Display();

    short Pause();
    short Continue();

    bool Save(HANDLE File);
    bool Load(HANDLE File);

};