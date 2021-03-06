#include "Common.h"
#include <assert.h>

///
/// EXTENSION CONSTRUCTOR/DESTRUCTOR
///

#define Ext (*globals->_ext)
#define Saved globals->_saved

HANDLE AppWasClosed = NULL;
Extension::Extension(RUNDATA * _rdPtr, EDITDATA * edPtr, CreateObjectInfo * cobPtr) :
	rdPtr(_rdPtr), rhPtr(_rdPtr->rHo.AdRunHeader), Runtime(_rdPtr), FusionDebugger(this)
{
	// Nullify the thread-specific data
	ClearThreadData();
	mainThreadID = std::this_thread::get_id();

	/*
		Link all your action/condition/expression functions to their IDs to match the
		IDs in the JSON here
	*/
	{
		LinkAction(0, RelayServer_Host);
		LinkAction(1, RelayServer_StopHosting);
		LinkAction(2, SetWelcomeMessage);
		LinkAction(3, RemovedActionNoParams);
		LinkAction(4, RemovedActionNoParams);
		LinkAction(5, RemovedActionNoParams);
		LinkAction(6, RemovedActionNoParams);
		LinkAction(7, RemovedActionNoParams);
		LinkAction(8, RemovedActionNoParams);
		LinkAction(9, RemovedActionNoParams /* EnableCondition_OnMessageToChannel */);
		LinkAction(10, RemovedActionNoParams);
		LinkAction(11, RemovedActionNoParams /*EnableCondition_OnMessageToPeer */);
		LinkAction(12, RemovedActionNoParams);
		LinkAction(13, RemovedActionNoParams);
		LinkAction(14, RemovedActionNoParams);
		LinkAction(15, RemovedActionNoParams);
		LinkAction(16, RemovedActionNoParams);
		LinkAction(17, RemovedActionNoParams);
		LinkAction(18, RemovedActionNoParams);
		LinkAction(19, RemovedActionNoParams /* old deny action without reason */);
		LinkAction(20, OnInteractive_ChangeClientName);
		LinkAction(21, OnInteractive_ChangeChannelName);
		LinkAction(22, OnInteractive_ReplaceMessageWithText);
		LinkAction(23, OnInteractive_ReplaceMessageWithNumber);
		LinkAction(24, OnInteractive_ReplaceMessageWithSendBinary);
		LinkAction(25, Channel_Close);
		LinkAction(26, Channel_SelectMaster);
		LinkAction(27, Channel_SelectByName);
		LinkAction(28, LoopAllChannels);
		LinkAction(29, Client_Disconnect);
		LinkAction(30, Client_LoopJoinedChannels);
		LinkAction(31, Client_SelectByName);
		LinkAction(32, Client_SelectByID);
		LinkAction(33, LoopAllClients);
		LinkAction(34, SendTextToClient);
		LinkAction(35, SendTextToChannel);
		LinkAction(36, SendNumberToClient);
		LinkAction(37, SendNumberToChannel);
		LinkAction(38, SendBinaryToClient);
		LinkAction(39, SendBinaryToChannel);
		LinkAction(40, BlastTextToClient);
		LinkAction(41, BlastTextToChannel);
		LinkAction(42, BlastNumberToClient);
		LinkAction(43, BlastNumberToChannel);
		LinkAction(44, BlastBinaryToClient);
		LinkAction(45, BlastBinaryToChannel);
		LinkAction(46, AddByteText);
		LinkAction(47, AddByteInt);
		LinkAction(48, AddShort);
		LinkAction(49, AddInt);
		LinkAction(50, AddFloat);
		LinkAction(51, AddStringWithoutNull);
		LinkAction(52, AddString);
		LinkAction(53, AddBinary);
		LinkAction(54, AddFileToBinary);
		LinkAction(55, CompressSendBinary);
		LinkAction(56, ClearBinaryToSend);
		LinkAction(57, SaveReceivedBinaryToFile);
		LinkAction(58, AppendReceivedBinaryToFile);
		LinkAction(59, DecompressReceivedBinary);
		LinkAction(60, Channel_LoopClients);
		LinkAction(61, OnInteractive_DropMessage);
		LinkAction(62, Client_SelectSender);
		LinkAction(63, Client_SelectReceiver);
		LinkAction(64, LoopAllChannelsWithName);
		LinkAction(65, LoopAllClientsWithName);
		LinkAction(66, Client_LoopJoinedChannelsWithName);
		LinkAction(67, Channel_LoopClientsWithName);
		LinkAction(68, FlashServer_Host);
		LinkAction(69, FlashServer_StopHosting);
		LinkAction(70, Client_SetLocalData);
		LinkAction(71, MoveReceivedBinaryCursor);
		LinkAction(72, Channel_SetLocalData);
		LinkAction(73, ResizeBinaryToSend);
		// Added actions:
		LinkAction(74, EnableCondition_OnConnectRequest);
		LinkAction(75, EnableCondition_OnJoinChannelRequest);
		LinkAction(76, EnableCondition_OnLeaveChannelRequest);
		LinkAction(77, EnableCondition_OnMessageToChannel);
		LinkAction(78, EnableCondition_OnMessageToPeer);
		LinkAction(79, EnableCondition_OnMessageToServer);
		LinkAction(80, OnInteractive_Deny);
		LinkAction(81, EnableCondition_OnNameSetRequest);
		//LinkAction(82, HTML5Server_EnableHosting);
		//LinkAction(83, HTML5Server_DisableHosting);
	}
	{
		LinkCondition(0, AlwaysTrue /* OnError */);
		LinkCondition(1, AlwaysTrue /* OnClientConnectRequest */);
		LinkCondition(2, AlwaysTrue /* OnDisconnect */);
		LinkCondition(3, AlwaysTrue /* OnChannel_JoinRequest */);
		LinkCondition(4, AlwaysTrue /* OnChannel_LeaveRequest */);
		LinkCondition(5, AlwaysTrue /* AllChannelsLoop */);
		LinkCondition(6, AlwaysTrue /* OnClient_JoinedChannelsLoop */);
		LinkCondition(7, AlwaysTrue /* AllClientsLoop */);
		LinkCondition(8, AlwaysTrue /* OnChannel_ClientLoop */);
		LinkCondition(9, Client_IsChannelMaster);
		LinkCondition(10, AlwaysTrue /* OnClient_NameSetRequest */);
		LinkCondition(11, AlwaysFalse /* NOT USED: OnClient_NameChangeRequest */);
		LinkCondition(12, SubchannelMatches /* OnSentTextMessageToServer */);
		LinkCondition(13, SubchannelMatches /* OnSentNumberMessageToServer */);
		LinkCondition(14, SubchannelMatches /* OnSentBinaryMessageToServer */);
		LinkCondition(15, SubchannelMatches /* OnAnySentMessageToServer */);
		LinkCondition(16, SubchannelMatches /* OnSentTextMessageToChannel */);
		LinkCondition(17, SubchannelMatches /* OnSentNumberMessageToChannel */);
		LinkCondition(18, SubchannelMatches /* OnSentBinaryMessageToChannel */);
		LinkCondition(19, SubchannelMatches /* OnAnySentMessageToChannel */);
		LinkCondition(20, SubchannelMatches /* OnSentTextMessageToPeer */);
		LinkCondition(21, SubchannelMatches /* OnSentNumberMessageToPeer */);
		LinkCondition(22, SubchannelMatches /* OnSentBinaryMessageToPeer */);
		LinkCondition(23, SubchannelMatches /* OnAnySentMessageToPeer */);
		LinkCondition(24, SubchannelMatches /* OnBlastedTextMessageToPeer */);
		LinkCondition(25, SubchannelMatches /* OnBlastedNumberMessageToServer */);
		LinkCondition(26, SubchannelMatches /* OnBlastedBinaryMessageToServer */);
		LinkCondition(27, SubchannelMatches /* OnAnyBlastedMessageToServer */);
		LinkCondition(28, SubchannelMatches /* OnBlastedTextMessageToChannel */);
		LinkCondition(29, SubchannelMatches /* OnBlastedNumberMessageToChannel */);
		LinkCondition(30, SubchannelMatches /* OnBlastedBinaryMessageToChannel */);
		LinkCondition(31, SubchannelMatches /* OnAnyBlastedMessageToChannel */);
		LinkCondition(32, SubchannelMatches /* OnBlastedTextMessageToPeer */);
		LinkCondition(33, SubchannelMatches /* OnBlastedNumberMessageToPeer */);
		LinkCondition(34, SubchannelMatches /* OnBlastedBinaryMessageToPeer */);
		LinkCondition(35, SubchannelMatches /* OnAnyBlastedMessageToPeer */);
		LinkCondition(36, OnAllChannelsLoopWithName);
		LinkCondition(37, OnClientsJoinedChannelLoopWithName);
		LinkCondition(38, OnAllClientsLoopWithName);
		LinkCondition(39, OnChannelClientsLoopWithName);
		LinkCondition(40, OnChannelClientsLoopWithNameFinished);
		LinkCondition(41, OnAllChannelsLoopWithNameFinished);
		LinkCondition(42, OnAllClientsLoopWithNameFinished);
		LinkCondition(43, OnClientsJoinedChannelLoopWithNameFinished);
		LinkCondition(44, AlwaysTrue /* OnChannelsClientLoopFinished */);
		LinkCondition(45, AlwaysTrue /* OnAllChannelsLoopFinished */);
		LinkCondition(46, AlwaysTrue /* OnAllClientsLoopFinished */);
		LinkCondition(47, AlwaysTrue /* OnClientJoinedChannelLoopFinished */);
		LinkCondition(48, IsLacewingServerHosting);
		LinkCondition(49, IsFlashPolicyServerHosting);
		LinkCondition(50, ChannelIsHiddenFromChannelList);
		LinkCondition(51, ChannelIsSetToCloseAutomatically);
		LinkCondition(52, AlwaysFalseWithTextParam /* DUPLICATE IN ORIG, NOT USED IN BLUE: OnAllClientsLoopWithNameFinished */);
		// Added conditions:
		LinkCondition(53, IsClientOnChannel_ID);
		LinkCondition(54, IsClientOnChannel_Name);
		LinkCondition(55, DoesChannelNameExist);
		LinkCondition(56, DoesChannelIDExist);
		LinkCondition(57, DoesClientNameExist);
		LinkCondition(58, DoesClientIDExist);
		LinkCondition(59, AlwaysTrue /* UponChannelClose */);
	//	LinkCondition(X, IsHTML5Hosting);
	}
	{
		LinkExpression(0, Error);
		LinkExpression(1, Lacewing_Version);
		LinkExpression(2, BinaryToSend_Size);
		LinkExpression(3, RequestedClientName);
		LinkExpression(4, RequestedChannelName);
		LinkExpression(5, Channel_Name);
		LinkExpression(6, Channel_ClientCount);
		LinkExpression(7, Client_Name);
		LinkExpression(8, Client_ID);
		LinkExpression(9, Client_IP);
		LinkExpression(10, Client_ConnectionTime);
		LinkExpression(11, Client_ChannelCount);
		LinkExpression(12, ReceivedStr);
		LinkExpression(13, ReceivedInt);
		LinkExpression(14, ReceivedBinarySize);
		LinkExpression(15, ReceivedBinaryAddress);
		LinkExpression(16, StrByte);
		LinkExpression(17, UnsignedByte);
		LinkExpression(18, SignedByte);
		LinkExpression(19, UnsignedShort);
		LinkExpression(20, SignedShort);
		LinkExpression(21, UnsignedInteger);
		LinkExpression(22, SignedInteger);
		LinkExpression(23, Float);
		LinkExpression(24, StringWithSize);
		LinkExpression(25, String);
		LinkExpression(26, Subchannel);
		LinkExpression(27, Channel_Count);
		LinkExpression(28, Client_GetLocalData);
		LinkExpression(29, CursorStrByte);
		LinkExpression(30, CursorUnsignedByte);
		LinkExpression(31, CursorSignedByte);
		LinkExpression(32, CursorUnsignedShort);
		LinkExpression(33, CursorSignedShort);
		LinkExpression(34, CursorUnsignedInteger);
		LinkExpression(35, CursorSignedInteger);
		LinkExpression(36, CursorFloat);
		LinkExpression(37, CursorStringWithSize);
		LinkExpression(38, CursorString);
		LinkExpression(39, Client_ProtocolImplementation);
		LinkExpression(40, Channel_GetLocalData);
		LinkExpression(41, Port);
		LinkExpression(42, BinaryToSend_Address);
		// Added expressions:
		LinkExpression(43, DumpMessage);
		LinkExpression(44, AllClientCount);
		LinkExpression(45, GetDenyReason);
	}
	
#if EditorBuild
	if (edPtr->eHeader.extSize < sizeof(EDITDATA))
	{
		MessageBoxA(NULL, "Properties are the wrong size. Please re-create the Lacewing Blue Server object in frame, "
			"and use \"Replace by another object\" in Event Editor.", "Lacewing Blue Server error", MB_OK | MB_ICONERROR);
	}
#endif


	// This is signalled by EndApp in General.cpp. It's used to unhost the server
	// when the application closes, from the timeout thread - assuming events
	// haven't done that already.
	if (!AppWasClosed)
	{
		AppWasClosed = CreateEvent(NULL, TRUE, FALSE, NULL);
		if (!AppWasClosed)
			throw std::runtime_error("Couldn't create an AppWasClosed event.");
	}

	isGlobal = edPtr->isGlobal;
	char msgBuff[500];
	sprintf_s(msgBuff, "Extension create: IsGlobal=%i.\n", isGlobal ? 1 : 0);
	OutputDebugStringA(msgBuff);
	if (isGlobal)
	{
		std::string GlobalIDCopy = "LacewingRelayServer";
		GlobalIDCopy += edPtr->edGlobalID;
		void * v = Runtime.ReadGlobal(GlobalIDCopy.c_str());
		if (!v)
		{
			globals = new GlobalInfo(this, edPtr);
			Runtime.WriteGlobal(GlobalIDCopy.c_str(), globals);
			OutputDebugStringA("Created new globals.\n");
		}
		else
		{
			// Add this Extension to Refs
			globals = (GlobalInfo *)v;

			EnterCriticalSectionDebug(&globals->lock);

			// If switching frames, the old ext will store selection here.
			// We'll keep it across frames for simplicity.
			if (!globals->lastDestroyedExtSelectedChannel.expired())
			{
				selChannel = globals->lastDestroyedExtSelectedChannel.lock();
				globals->lastDestroyedExtSelectedChannel.reset();
			}
			if (!globals->lastDestroyedExtSelectedClient.expired())
			{
				selClient = globals->lastDestroyedExtSelectedClient.lock();
				globals->lastDestroyedExtSelectedClient.reset();
			}

			globals->Refs.push_back(this);
			if (!globals->_ext)
				globals->_ext = this;
			OutputDebugStringA("Globals exists: added to Refs.\n");

			if (globals->timeoutThread)
			{
				OutputDebugStringA("Timeout thread is active: waiting for it to close.\n");
				SetEvent(AppWasClosed);
				WaitForSingleObject(globals->timeoutThread, 200);
				CloseHandle(globals->timeoutThread);
				globals->timeoutThread = NULL;
				ResetEvent(AppWasClosed);
				OutputDebugStringA("Timeout thread has closed.\n");
			}

			LeaveCriticalSectionDebug(&globals->lock);
		}
	}
	else
	{
		OutputDebugStringA("Non-Global object; creating globals, not submitting to WriteGlobal.\n");
		globals = new GlobalInfo(this, edPtr);

		globals->_objEventPump->tick();
	}

	// Try to boot the Lacewing thread if multithreading and not already running
	if (edPtr->multiThreading && !globals->_thread && !(globals->_thread = CreateThread(NULL, NULL, LacewingLoopThread, this, NULL, NULL)))
	{
		CreateError("failed to boot thread. Falling back to single-threaded interface.");
		Runtime.Rehandle();
	}
	else if (!edPtr->multiThreading)
		Runtime.Rehandle();


	// Set up Fusion debugger (it uses globals, so we have to do it after)
	// The server could be hosting already if this Extension() is being run after a Fusion frame switch.
	const auto hostingDebugItemReader = [](Extension *ext, std::tstring &writeTo) {
		if (ext->Srv.hosting())
			writeTo = _T("Hosting: Port ") + std::to_tstring(ext->Srv.port());
		else
			writeTo = _T("Hosting: Not hosting.");
	};
	FusionDebugger.AddItemToDebugger(hostingDebugItemReader, NULL, 500, NULL);

	const auto clientCountDebugItemReader = [](Extension *ext, std::tstring &writeTo) {
		if (ext->Srv.hosting())
			writeTo = _T("All client count: ") + std::to_tstring(ext->Srv.clientcount());
		else
			writeTo = _T("All client count: N/A");
	};
	FusionDebugger.AddItemToDebugger(clientCountDebugItemReader, NULL, 500, NULL);

	const auto channelCountDebugItemReader = [](Extension *ext, std::tstring &writeTo) {
		if (ext->Srv.hosting())
			writeTo = _T("All channel count: ") + std::to_tstring(ext->Srv.channelcount());
		else
			writeTo = _T("All channel count: N/A");
		
	};
	FusionDebugger.AddItemToDebugger(channelCountDebugItemReader, NULL, 500, NULL);

	const auto selChannelDebugItemReader = [](Extension *ext, std::tstring &writeTo) {
		if (ext->selChannel)
			writeTo = _T("Selected channel: ") + ext->selChannel->name();
		else
			writeTo = _T("Selected channel: (none)");
	};
	FusionDebugger.AddItemToDebugger(selChannelDebugItemReader, NULL, 100, NULL);

	const auto selChannelNumClientsDebugItemReader = [](Extension *ext, std::tstring &writeTo) {
		if (ext->selChannel)
			writeTo = _T("> Client count: ") + std::to_tstring(ext->selChannel->clientcount());
		else
			writeTo = _T("> Client count: (no selected channel)");
	};
	FusionDebugger.AddItemToDebugger(selChannelNumClientsDebugItemReader, NULL, 100, NULL);


	const auto selClientDebugItemReader = [](Extension *ext, std::tstring &writeTo) {
		if (ext->selClient)
			writeTo = _T("Selected client: ") + ext->selChannel->name();
		else
			writeTo = _T("Selected client: (none)");
	};
	FusionDebugger.AddItemToDebugger(selClientDebugItemReader, NULL, 100, NULL);

	const auto selClientNumChannelsDebugItemReader = [](Extension *ext, std::tstring &writeTo) {
		if (ext->selClient)
			writeTo = _T("> Channel count: ") + std::to_tstring(ext->selClient->channelcount());
		else
			writeTo = _T("> Channel count: (no selected client)");
	};
	FusionDebugger.AddItemToDebugger(selClientNumChannelsDebugItemReader, NULL, 100, NULL);
}



DWORD WINAPI LacewingLoopThread(void * ThisExt)
{
	// If the loop thread is terminated, very few bytes of memory will be leaked.
	// However, it is better to use PostEventLoopExit().

	GlobalInfo * g = ((Extension *)ThisExt)->globals;
	try {
		lacewing::error error = g->_objEventPump->start_eventloop();

		// Can't error report if there's no extension to error-report to.
		// Worst case scenario CreateError calls Runtime.Rehandle which breaks because ext is gone.
		if (!error)
			OutputDebugStringA("LacewingLoopThread closing gracefully.");
		else if (g->_ext)
		{
			std::string Text = "Error returned by StartEventLoop(): ";
			Text += error->tostring();
			g->CreateError(Text.c_str());
		}

	}
	catch (...)
	{
		OutputDebugStringA("LacewingLoopThread got an exception.");
		if (g->_ext)
		{
			std::string Text = "StartEventLoop() killed by exception. Switching to single-threaded.";
			g->CreateError(Text.c_str());
		}
	}

	CloseHandle(g->_thread);
	g->_thread = NULL;
	OutputDebugStringA("LacewingLoopThread has exited.");
	return 0;
}

GlobalInfo::GlobalInfo(Extension * e, EDITDATA * edPtr)
	: _objEventPump(lacewing::eventpump_new(), eventpumpdeleter),
	_server(_objEventPump.get())
{
	_ext = e;
	Refs.push_back(e);
	if (edPtr->isGlobal)
		_globalID = _strdup(edPtr->edGlobalID);
	timeoutWarningEnabled = edPtr->timeoutWarningEnabled;
	fullDeleteEnabled = edPtr->fullDeleteEnabled;

	_server.onerror(::OnError);
	_server.onconnect(::OnClientConnectRequest);
	_server.onnameset(::OnNameSetRequest);
	_server.onchannel_join(::OnJoinChannelRequest);
	_server.onchannel_leave(::OnLeaveChannelRequest);
	_server.onmessage_server(::OnServerMessage);
	_server.ondisconnect(::OnClientDisconnect);

	// Approve quiet needs no handler
	//_server.onmessage_channel(::OnChannelMessage);
	//_server.onmessage_peer(::OnPeerMessage);
	
	// RelayServer combines flash policy errors with regular errors.
	// So this is handled by srv.onerror
	//flashSrv->on_error(::OnFlashError);

	InitializeCriticalSection(&lock);

	// Useful so Lacewing callbacks can access Extension
	_server.tag = this;
}
GlobalInfo::~GlobalInfo() noexcept(false)
{
	if (!Refs.empty())
		throw std::exception("GlobalInfo dtor called prematurely.");
	free(_globalID);
	DeleteCriticalSection(&lock);

	// We're no longer responding to these events
	_server.onerror(nullptr);
	_server.ondisconnect(nullptr);
	_server.onconnect(nullptr);
	_server.onnameset(nullptr);
	_server.onchannel_join(nullptr);
	_server.onchannel_leave(nullptr);
	_server.onmessage_server(nullptr);
	_server.onmessage_channel(nullptr);
	_server.onmessage_peer(nullptr);

	// Cleanup all usages of GlobalInfo
	if (!_thread)
		_objEventPump->tick();

	_server.tag = nullptr; // was == this, now this is not usable

	if (_server.hosting())
	{
		_server.unhost();

		if (!_thread)
			_objEventPump->tick();
		Sleep(0U);
	}
	_objEventPump->post_eventloop_exit();

	if (_thread)
	{
		Sleep(0U);
		if (_thread)
			Sleep(50U);
		if (_thread) {
			TerminateThread(_thread, 0U);
			CloseHandle(_thread);
			_thread = NULL;
		}
	}
	else
	{
		_objEventPump->tick();
		Sleep(0U);
	}
}
void eventpumpdeleter(lacewing::eventpump pump)
{
	OutputDebugStringA("Pump deleting...\n");
	lacewing::pump_delete(pump);
	OutputDebugStringA("Pump deleted.\n");
	_CrtCheckMemory();
}


#ifdef MULTI_THREADING

void GlobalInfo::AddEvent1(int event1ID,
	std::shared_ptr<lacewing::relayserver::channel> channel /* = nullptr */,
	std::shared_ptr<lacewing::relayserver::client> senderClient /* = nullptr */,
	std::string_view messageOrErrorText /* = std::string_view() */,
	lw_ui8 subchannel /* = 255 */,
	std::shared_ptr<lacewing::relayserver::client> receivingClient /* = nullptr */,
	InteractiveType interactiveType  /* = None */,
	lw_ui8 variant /* = 255 */,
	bool blasted /* = false */,
	bool channelCreate_Hidden /* = false */,
	bool channelCreate_AutoClose /* = false */
	)
{
	return AddEventF(false, event1ID, 35353,
		channel, senderClient, messageOrErrorText, subchannel,
		receivingClient, interactiveType, variant, blasted, channelCreate_Hidden, channelCreate_AutoClose);
}
void GlobalInfo::AddEvent2(int event1ID, int event2ID,
	std::shared_ptr<lacewing::relayserver::channel> channel /* = nullptr */,
	std::shared_ptr<lacewing::relayserver::client> senderClient /* = nullptr */,
	std::string_view messageOrErrorText /* = std::string_view() */,
	lw_ui8 subchannel /* = 255 */,
	std::shared_ptr<lacewing::relayserver::client> receivingClient /* = nullptr */,
	InteractiveType interactiveType  /* = None */,
	lw_ui8 variant /* = 255 */,
	bool blasted /* = false */,
	bool channelCreate_Hidden /* = false */,
	bool channelCreate_AutoClose /* = false */)
{
	return AddEventF(true, event1ID, event2ID,
		channel, senderClient, messageOrErrorText, subchannel,
		receivingClient, interactiveType, variant, blasted, channelCreate_Hidden, channelCreate_AutoClose);
}
void GlobalInfo::AddEventF(bool twoEvents, int event1ID, int event2ID,
	std::shared_ptr<lacewing::relayserver::channel> channel /* = nullptr */,
	std::shared_ptr<lacewing::relayserver::client> senderClient /* = nullptr */,
	std::string_view messageOrErrorText /* = std::string_view() */,
	lw_ui8 subchannel /* = 255 */,
	std::shared_ptr<lacewing::relayserver::client> receivingClient /* = nullptr */,
	InteractiveType interactiveType  /* = None */,
	unsigned char variant /* = 255 */,
	bool blasted /* = false */,
	bool channelCreate_Hidden /* = false */,
	bool channelCreate_AutoClose /* = false */)
{
	/*
		Saves all variables returned by expressions in order to ensure two conditions, triggering simultaneously,
		do not cause reading of only the last condition's output. Only used in multi-threading.

		For example, if an error event changes an output variable, and immediately afterward a
		success event changes the same variable, only the success event's output can be read since it overwrote
		the last event. However, using MMF2 in single-threaded mode, overwriting is impossible to do
		provided you use GenerateEvent(). Since PushEvent() is not immediate, you can reproduce this
		multi-threaded bug in single-thread mode. But PushEvent() isn't recommended for use anyway;
		it's designed so extensions who don't have focus of MMF2 (gained by MMF2 calling, say, Rehandle)
		can still create events.
		With GenerateEvent() + multithreading, this would cause crashes as Fusion is forced into the extension
		at the wrong time.
		With PushEvent() + multithreading, this would cause overwriting of old events and possibly access
		violations as variables are simultaneously written to by the ext and read from by Fusion at the same time.
		
		But in DarkEdif, you'll note all the GenerateEvents() are handled on a queue, and the queue is
		iterated through in Handle(), thus it is quite safe. But we still need to protect potentially several
		AddEvent() functions running at once and corrupting the memory at some point; so we need the
		CRITICAL_SECTION variable mentioned in Extension.h to ensure this will not happen.
	*/

	auto newEvent = std::make_shared<SaveExtInfo>();
	SaveExtInfo &newEvent2 = *newEvent;

	// Initialise
	newEvent2.numEvents = twoEvents ? 2 : 1;
	newEvent2.CondTrig[0] = (unsigned short)event1ID;
	newEvent2.CondTrig[1] = (unsigned short)event2ID;
	newEvent2.channel = channel;
	newEvent2.senderClient = senderClient;
	newEvent2.receivingClient = receivingClient;
	// Message Content, Error Text, and Loop Name overlap
	newEvent2.receivedMsg.content = messageOrErrorText;
	newEvent2.receivedMsg.subchannel = subchannel;
	newEvent2.receivedMsg.variant = variant;
	newEvent2.receivedMsg.blasted = blasted;
	newEvent2.InteractiveType = interactiveType;
	newEvent2.channelCreate_Hidden = channelCreate_Hidden;
	newEvent2.channelCreate_AutoClose = channelCreate_AutoClose;

	EnterCriticalSectionDebug(&lock); // Needed before we access Extension

	_saved.push_back(newEvent);

	LeaveCriticalSectionDebug(&lock); // We're done accessing Extension

	// Cause Handle() to be triggered, allowing Saved to be parsed
	if (_ext != nullptr)
		_ext->Runtime.Rehandle();
}

#endif // MULTI_THREADING


void Extension::ClearThreadData()
{
	threadData = std::make_shared<SaveExtInfo>();
}

void Extension::CreateError(_Printf_format_string_ const char * error, ...)
{
	va_list v;
	va_start(v, error);
	globals->CreateError(error, v);
	va_end(v);
}

void GlobalInfo::CreateError(_Printf_format_string_ const char * error, va_list v)
{
	std::stringstream errorDetailed;
	if (std::this_thread::get_id() != Refs[0]->mainThreadID)
		errorDetailed << "[handler] ";
	else
		errorDetailed << "[Fusion event #" << Refs[0]->rhPtr->EventGroup->evgInhibit << "] ";

	char output[2048];
	try {
		if (vsprintf_s(output, error, v) <= 0)
		{
			errorDetailed.str("vsprintf_s failed with errno ");
			errorDetailed << errno << ", format [" << error << "].";
		}
		else
			errorDetailed << output;
	}
	catch (...)
	{
		errorDetailed.str("vsprintf_s failed with crash, format [");
		errorDetailed << error << "].";
	}

	const std::string errText = errorDetailed.str();
	OutputDebugStringA(errText.c_str());
	OutputDebugStringA("\n");
	AddEvent1(0, nullptr, nullptr, errText);
}

void GlobalInfo::CreateError(_Printf_format_string_ const char * error, ...)
{
	va_list v;
	va_start(v, error);
	CreateError(error, v);
	va_end(v);
}

void Extension::AddToSend(void * data, size_t size)
{
	if (!data)
	{
		CreateError("Error adding to send binary: pointer supplied is invalid. "
			"The message has not been modified.");
		return;
	}
	if (!size)
		return;
	char * newptr = (char *)realloc(SendMsg, SendMsgSize + size);

	// Failed to reallocate memory
	if (!newptr)
	{
		CreateError("Received error number %u with reallocating memory to append to binary message. "
			"The message has not been modified.", errno);
		return;
	}

	// memcpy_s does not allow copying from what's already inside sendMsg; memmove_s does.
	// If we failed to copy memory.
	if (memmove_s(newptr + SendMsgSize, size, data, size))
		CreateError("Received error number %u with copying memory to append to binary message.", errno);

	SendMsg = newptr;
	SendMsgSize += size;
}

static const std::string empty;
const std::string& GlobalInfo::GetLocalData(std::shared_ptr<lacewing::relayserver::client> client, std::string key)
{
	auto local = std::find_if(clientLocal.cbegin(), clientLocal.cend(),
		[&](const auto &c) { return c.ptr == client && !_stricmp(c.key.c_str(), key.c_str()); });
	if (local == clientLocal.cend())
		return empty;
	return local->val;
}
const std::string& GlobalInfo::GetLocalData(std::shared_ptr<lacewing::relayserver::channel> channel, std::string key)
{
	auto local = std::find_if(channelLocal.cbegin(), channelLocal.cend(),
		[&](const auto &c) { return c.ptr == channel && !_stricmp(c.key.c_str(), key.c_str()); });
	if (local == channelLocal.cend())
		return empty;
	return local->val;
}
void GlobalInfo::SetLocalData(std::shared_ptr<lacewing::relayserver::client> client, std::string key, std::string value)
{
	auto local = std::find_if(clientLocal.begin(), clientLocal.end(),
		[&](const auto &c) { return c.ptr == client && !_stricmp(c.key.c_str(), key.c_str()); });
	if (local == clientLocal.end())
		clientLocal.push_back(LocalData(client, key, value));
	else
		local->val = value;
}
void GlobalInfo::SetLocalData(std::shared_ptr<lacewing::relayserver::channel> channel, std::string key, std::string value)
{
	auto local = std::find_if(channelLocal.begin(), channelLocal.end(),
		[&](const auto &c) { return c.ptr == channel && !_stricmp(c.key.c_str(), key.c_str()); });
	if (local == channelLocal.end())
		channelLocal.push_back(LocalData(channel, key, value));
	else
		local->val = value;
}
void GlobalInfo::ClearLocalData(std::shared_ptr<lacewing::relayserver::client> client)
{
	clientLocal.erase(std::remove_if(clientLocal.begin(), clientLocal.end(),
		[&](const auto &c) { return c.ptr == client; }), clientLocal.end());
}
void GlobalInfo::ClearLocalData(std::shared_ptr<lacewing::relayserver::channel> channel)
{
	channelLocal.erase(std::remove_if(channelLocal.begin(), channelLocal.end(),
		[&](const auto &c) { return c.ptr == channel; }), channelLocal.end());
}

REFLAG Extension::Handle()
{
	// If thread is not working, use Tick functionality. This may add events, so do it before the event-loop check.
	if (!globals->_thread)
	{
		lacewing::error e = ObjEventPump->tick();
		if (e != nullptr)
		{
			CreateError(e->tostring());
			return REFLAG::NONE; // Run next loop
		}
	}

	// AddEvent() was called and not yet handled
	// (note all code that accesses Saved must have ownership of lock)

	// If Thread is not available, we have to tick() on Handle(), so
	// we have to run next loop even if there's no events in Saved() to deal with.
	bool RunNextLoop = !globals->_thread;

	for (size_t maxTrig = 0; maxTrig < 10; maxTrig++)
	{
		// Attempt to Enter, break if we can't get it instantly
		if (!TryEnterCriticalSection(&globals->lock))
		{
			RunNextLoop = true;
			break; // lock already occupied; leave it and run next event loop
		}
		// At this point we have effectively run EnterCriticalSection
#ifdef _DEBUG
		::CriticalSection << "Thread " << GetCurrentThreadId() << " : Entered on "
			<< __FILE__ << ", line " << __LINE__ << ".\r\n";
#endif

		if (Saved.empty())
		{
			LeaveCriticalSectionDebug(&globals->lock);
			break;
		}
		std::shared_ptr<SaveExtInfo> s = Saved.front();
		Saved.erase(Saved.begin());

		InteractivePending = s->InteractiveType;
		if (s->InteractiveType == InteractiveType::ConnectRequest)
			DenyReason = globals->autoResponse_Connect_DenyReason;
		else if (s->InteractiveType == InteractiveType::ChannelLeave)
			DenyReason = globals->autoResponse_ChannelLeave_DenyReason;
		else if (s->InteractiveType == InteractiveType::ClientNameSet)
		{
			NewClientName = s->requested.name;
			DenyReason = globals->autoResponse_NameSet_DenyReason;
		}
		else if (s->InteractiveType == InteractiveType::ChannelJoin)
		{
			NewChannelName = s->requested.name;
			DenyReason = globals->autoResponse_ChannelJoin_DenyReason;
		}
		else if (s->InteractiveType == InteractiveType::ChannelMessageIntercept)
		{
			DropMessage = globals->autoResponse_MessageChannel == AutoResponse::Deny_Quiet ||
				globals->autoResponse_MessageChannel == AutoResponse::Deny_TellFusion;
		}
		else if (s->InteractiveType == InteractiveType::ClientMessageIntercept)
		{
			DropMessage = globals->autoResponse_MessageClient == AutoResponse::Deny_Quiet ||
				globals->autoResponse_MessageClient == AutoResponse::Deny_TellFusion;
		}

		LeaveCriticalSectionDebug(&globals->lock);

		// Trigger all stored events (more than one may be stored by calling AddEvent(***, true) )
		for (unsigned char u = 0; u < s->numEvents; ++u)
		{
			if (s->CondTrig[u] != 0xFFFF)
			{
				for (auto i : globals->Refs)
				{
					auto origSelCli = i->selClient;
					auto origSelCh = i->selChannel;

					i->selClient = s->senderClient;
					i->selChannel = s->channel;
					i->threadData = s;
					i->Runtime.GenerateEvent((int)s->CondTrig[u]);

					i->ClearThreadData();
					i->selClient = origSelCli;
					i->selChannel = origSelCh;
				}

				// We need to access these locks in multithreaded in case the user prevents
				// us from handling the interactive event properly by their actions,
				// e.g. don't want to allow the user to close midway through a send.
				// In single threaded the tick runs before this triggers, so it's not a problem.
				

				// If multiple events are triggering, only do this on the last one
				if (u == s->numEvents - 1)
				{
					// If interactive event, check for responses.
					if (s->InteractiveType != InteractiveType::None)
						HandleInteractiveEvent(s);

					if (s->InteractiveType == InteractiveType::ChannelLeave &&
						s->channel->readonly())
					{
						s->InteractiveType = InteractiveType::None;
						for (auto i : globals->Refs)
						{
							auto origSelCli = i->selClient;
							auto origSelCh = i->selChannel;

							i->selChannel = s->channel;
							i->threadData = s;
							// Special case: upon channel closed
							i->Runtime.GenerateEvent(59);

							i->ClearThreadData();
							i->selClient = origSelCli;
							i->selChannel = origSelCh;
						}
						s->InteractiveType = InteractiveType::None;
					}

					// Free memory for received message
					ClearThreadData();
				}
				
			}
			// Deselect after 0xFFFF
			else
				DeselectIfDestroyed(s);
		}
	}

	// Will not be called next loop if RunNextLoop is false
	return RunNextLoop ? REFLAG::NONE : REFLAG::ONE_SHOT;
}

// Only called by Handle().
void Extension::HandleInteractiveEvent(std::shared_ptr<SaveExtInfo> s)
{
#define EnterSectionIfMultiThread(x) if (GThread) { EnterCriticalSectionDebug(x); Sleep(0); }
#define LeaveSectionIfMultiThread(x) if (GThread) LeaveCriticalSectionDebug(x)
	if (s->InteractiveType == InteractiveType::ConnectRequest)
	{
		if (globals->autoResponse_Connect == AutoResponse::WaitForFusion
			&& !s->senderClient->readonly())
		{
			EnterSectionIfMultiThread(&globals->lock);
			Srv.connect_response(s->senderClient, DenyReason.c_str());

			// Disconnected by Fusion: reflect in copy
			if (!DenyReason.empty())
			{
				// Mark as disconnected
				s->senderClient->disconnect();

				// Trick this for loop into running a second event to cleanup immediately
				assert(s->numEvents == 1); // connect req must be one event for this to work
				s->CondTrig[1] = 0xFFFF;
				s->numEvents = 2;
			}
			LeaveSectionIfMultiThread(&globals->lock);
		}
	}
	else if (s->InteractiveType == InteractiveType::ClientNameSet)
	{
		if (globals->autoResponse_NameSet == AutoResponse::WaitForFusion
			&& !s->senderClient->readonly())
		{
			EnterSectionIfMultiThread(&globals->lock);
			Srv.nameset_response(s->senderClient, NewClientName, DenyReason.c_str());

			if (!DenyReason.empty())
				s->senderClient->name(NewClientName);
			LeaveSectionIfMultiThread(&globals->lock);
		}
	}
	else if (s->InteractiveType == InteractiveType::ChannelJoin)
	{
		if (globals->autoResponse_ChannelJoin == AutoResponse::WaitForFusion
			&& !s->channel->readonly() && !s->senderClient->readonly())
		{
			std::string denyReason = DenyReason;
			bool channelmasterset = false;
			auto channelToJoinTo = s->channel;

			if (denyReason.empty())
			{
				// channel name was changed in join request
				if (!NewChannelName.empty())
				{
					// New channel name is in use by another channel
					auto channelWriteLock = s->channel->lock.createWriteLock();
					auto serverReadLock = Srv.lock.createReadLock();
					auto channels = Srv.getchannels();
					auto srvChIt = std::find_if(channels.cbegin(), channels.cend(),
						[&](auto & otherCh) { return otherCh != s->channel && lw_sv_icmp(NewChannelName, otherCh->name()); });

					if (srvChIt != channels.cend())
					{
						channelToJoinTo = *srvChIt;
						// A join channel request was renamed to an existing channel. Isn't necessarily an error.
						//	char text[1024];
						//	sprintf_s(text, "New channel name %s (ID %hu) is in use by existing channel %s (ID %hu).",
						//		NewChannelName.c_str(), s->channel->id(), (*srvChIt)->name().data(), (*srvChIt)->id());
						//	CreateError(text);
					}
					else // Rename channel
						s->channel->name(NewChannelName);
				}
			}

			// Deny, create or join channel
			Srv.joinchannel_response(s->channel, s->senderClient, denyReason);
		} // is any closed
	}
	else if (s->InteractiveType == InteractiveType::ChannelLeave)
	{
		if (globals->autoResponse_ChannelLeave == AutoResponse::WaitForFusion
			&& !s->channel->readonly() && !s->senderClient->readonly())
		{
			Srv.leavechannel_response(s->channel, s->senderClient, DenyReason.c_str());
		}
	}
	else if (s->InteractiveType == InteractiveType::ChannelMessageIntercept)
	{
		if (globals->autoResponse_MessageChannel == AutoResponse::WaitForFusion)
		{
			if (!DropMessage && (s->channel->readonly() || s->senderClient->readonly()))
				DropMessage = true;

			// s->senderClient may not be accurate, since user selection will alter Client,
			// and it overlaps with Client. Refer to original event "s".
			Srv.channelmessage_permit(s->senderClient, s->channel,
				s->receivedMsg.blasted, s->receivedMsg.subchannel,
				s->receivedMsg.content,
				s->receivedMsg.variant, !DropMessage);
		}

		// Replace messages not programmed.
		// Look like Lacewing Relay was going to use Send Binary, though, but if they replace with
		// text/number the send binary should stay intact.
		// We may have to use a 3rd message struct as we don't want to use the sendMsg data.
		//srv.channelmessage_permit(*s->channel, *s->senderClient,
		//	s->receivedMsg.content, s->MsgToSend.size, s->receivedMsg.subchannel);
	}
	else if (s->InteractiveType == InteractiveType::ClientMessageIntercept)
	{
		if (globals->autoResponse_MessageClient == AutoResponse::WaitForFusion)
		{
			if (!DropMessage && (s->channel->readonly() ||
				s->senderClient->readonly() || s->receivingClient->readonly()))
			{
				DropMessage = true;
			}

			Srv.clientmessage_permit(s->senderClient, s->channel,
				s->receivingClient,
				s->receivedMsg.blasted, s->receivedMsg.subchannel,
				s->receivedMsg.content,
				s->receivedMsg.variant, !DropMessage);
		}
	}
	else
		globals->CreateError("Interactive type not recognised!");

#undef EnterSectionIfMultiThread
#undef LeaveSectionIfMultiThread
}


// Only called by Handle().
void Extension::DeselectIfDestroyed(std::shared_ptr<SaveExtInfo> s)
{
	// If channel, it's a channel leave or peer leaving channel
	if (s->channel)
	{
		// channel, no client: channel closing.
		// Worth noting this is not called for non-autoclose channels.
		if (!s->senderClient)
		{
			if (s->channel->readonly() == false)
				MessageBoxA(NULL, "s->channel->readonly() == false", "!", MB_OK);
			/*
			for (auto u = Channels.begin(); u != Channels.end(); ++u)
			{
				if (*u == s->channel)
				{
					Channels.erase(u);
					delete s->channel;
					break;
				}
			}
			*/
			globals->ClearLocalData(s->channel);

			for (auto dropExt : globals->Refs)
				if (dropExt->selChannel == s->channel)
					dropExt->selChannel = nullptr;
		}
		// channel, client: peer leaving channel.
		else
		{
			// We just make sure user doesn't have them selected.
			// At least, not within the channel they just left.
			for (auto dropExt : globals->Refs)
				if (dropExt->selChannel == s->channel && dropExt->selClient == s->senderClient)
					dropExt->selClient = nullptr;
		}
	}
	// No channel, client: client is disconnecting.
	else if (s->senderClient)
	{
		assert(s->senderClient->readonly());
		/*
		// Drop client
		for (auto u = Clients.begin(); u != Clients.end(); ++u)
		{
			if (*u == s->client)
			{
				Clients.erase(u);
				break;
			}
		}
		*/
		globals->ClearLocalData(s->senderClient);

		// Make sure user doesn't have them selected.
		for (auto dropExt : globals->Refs)
		{
			if (dropExt->selClient == s->senderClient)
				dropExt->selClient = nullptr;
		}
	}
	// No channel, no peer: server has unhosted, clear everything
	else
	{
		/*
		for (auto i : Channels)
		{
			assert(i->readonly());
			i->close();
			delete i;
		}
		for (auto i : Clients)
		{
			assert(i->readonly());
			delete i;
		}*/
		globals->clientLocal.clear();
		globals->channelLocal.clear();
		for (auto dropExt : globals->Refs)
		{
			dropExt->selChannel = nullptr;
			dropExt->selClient = nullptr;
		}

		//	Channels.clear();
		//	Clients.clear();
	}
}


DWORD WINAPI ObjectDestroyTimeoutFunc(void * ThisGlobalsInfo)
{
	GlobalInfo& G = *(GlobalInfo *)ThisGlobalsInfo;

	// If the user has created a new object which is receiving events from Bluewing
	// it's cool, just close silently
	if (!G.Refs.empty())
		return 0U;

	// If not hosting, no clients to worry about dropping
	if (!G._server.hosting())
		return 0U;

	// App closed within next 3 seconds: unhost by default
	if (WaitForSingleObject(AppWasClosed, 3000U) == WAIT_OBJECT_0)
		return 0U;

	// 3 seconds have passed: if we now have an ext, or server was unhosted, we're good
	if (!G.Refs.empty())
		return 0U;

	if (!G._server.hosting())
		return 0U;

	if (G.timeoutWarningEnabled)
	{
		// Otherwise, fuss at them.
		MessageBoxA(NULL, "Bluewing Server Warning!\r\n"
			"All Bluewing Server objects have been destroyed and some time has passed; but "
			"the server is still hosting in the background, unused, but still available.\r\n"
			"If this is intended behaviour, disable the Timeout warning in the object properties.\r\n"
			"If you want to unhost if no instances remain open, use the FullCleanup action on the Bluewing object.",
			"Bluewing Server Warning",
			MB_OK | MB_DEFBUTTON1 | MB_ICONEXCLAMATION | MB_TOPMOST);
	}
	delete &G; // Cleanup!
	return 0U;
}

Extension::~Extension()
{
	char msgBuff[500];
	sprintf_s(msgBuff, "~Extension called; Refs count is %u.\n", globals->Refs.size());
	OutputDebugStringA(msgBuff);

	EnterCriticalSectionDebug(&globals->lock);

	// Remove this Extension from liblacewing usage.
	auto i = std::find(globals->Refs.cbegin(), globals->Refs.cend(), this);
	bool wasBegin = i == globals->Refs.cbegin();
	globals->Refs.erase(i);

	ClearThreadData();

	// Shift secondary event management to other Extension, if any
	if (!globals->Refs.empty())
	{
		OutputDebugStringA("Note: Switched Lacewing instances.\n");

		// Switch Handle ticking over to next Extension visible.
		if (wasBegin)
		{
			globals->_ext = globals->Refs.front();
			LeaveCriticalSectionDebug(&globals->lock);

			globals->_ext->Runtime.Rehandle();
		}
		else // This extension wasn't even the main event handler (for Handle()/globals).
		{
			LeaveCriticalSectionDebug(&globals->lock);
		}
	}
	// Last instance of this object; if global and not full-delete-enabled, do not cleanup.
	// In single-threaded server instances, this will cause a dirty timeout from the client side;
	// the lower-level protocols, e.g. TCP, will close the connection after a certain amount of
	// not-responding.
	// In multi-threaded instances, messages and events will continue to be handled, and no visible
	// difference is made to the clients, other than the events explicitly handled by Fusion events.
	else
	{
		if (!globals->_server.hosting())
			OutputDebugStringA("Note: Not hosting, nothing important to retain, closing globals info.\n");
		else if (!isGlobal)
			OutputDebugStringA("Note: Not global, closing globals info.\n");
		else if (globals->fullDeleteEnabled)
			OutputDebugStringA("Note: Full delete enabled, closing globals info.\n");
		// Wait for 0ms returns immediately as per spec
		else if (WaitForSingleObject(AppWasClosed, 0U) == WAIT_OBJECT_0)
			OutputDebugStringA("Note: App was closed, closing globals info.\n");
		else // !globals->fullDeleteEnabled
		{
			OutputDebugStringA("Note: Last instance dropped, and currently hosting - "
				"globals will be retained until a Unhost is called.\n");
			globals->_ext = nullptr;
			globals->lastDestroyedExtSelectedChannel = selChannel;
			globals->lastDestroyedExtSelectedClient = selClient;
			LeaveCriticalSectionDebug(&globals->lock);

			sprintf_s(msgBuff, "Timeout thread started. If no instance has reclaimed ownership in 3 seconds, %s.\n",
				globals->timeoutWarningEnabled
				? "a warning message will be shown"
				: "the hosting will terminate and all pending messages will be discarded");
			OutputDebugStringA(msgBuff);

			globals->timeoutThread = CreateThread(NULL, 0, ObjectDestroyTimeoutFunc, globals, NULL, NULL);
			ClearThreadData();
			selChannel = nullptr;
			selClient = nullptr;
			return;
		}

		std::string id = "LacewingRelayServer";
		id += (globals->_globalID ? globals->_globalID : "");
		Runtime.WriteGlobal(id.c_str(), nullptr);
		LeaveCriticalSectionDebug(&globals->lock);
		delete globals; // Unhosts and closes event pump, deletes lock
		globals = nullptr;
	}

	selChannel = nullptr;
	selClient = nullptr;
}

REFLAG Extension::Display()
{
	/*
		If you return REFLAG::DISPLAY in Handle() this routine will run.
	*/

	// Ok
	return REFLAG::NONE;
}

short Extension::Pause()
{

	// Ok
	return 0;
}

short Extension::Continue()
{

	// Ok
	return 0;
}

bool Extension::Save(HANDLE File)
{
	bool OK = false;

	#ifndef VITALIZE

		// Save the object's data here

		OK = true;

	#endif

	return OK;
}

bool Extension::Load(HANDLE File)
{
	bool OK = false;

	#ifndef VITALIZE

		// Load the object's data here

		OK = true;

	#endif

	return OK;
}


// These are called if there's no function linked to an ID

void Extension::Action(int ID, RUNDATA * rdPtr, long param1, long param2)
{

}

long Extension::Condition(int ID, RUNDATA * rdPtr, long param1, long param2)
{
	return false;
}

long Extension::Expression(int ID, RUNDATA * rdPtr, long param)
{
	return 0;
}
