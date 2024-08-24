
typedef void(__fastcall* _CWndCreateWnd_t)(void* pThis, void* edx, int nLeft, int nTop, int nWidth, int nHeight, int z, int bScreenCoord, void* esi, int bSetFocus);
static auto _CWndCreateWnd = reinterpret_cast<_CWndCreateWnd_t>(0x009DE4D2); //thanks you teto for helping me on this learning journey
static _CWndCreateWnd_t _CWndCreateWnd_Hook = [](void* pThis, void* edx, int nLeft, int nTop, int nWidth, int nHeight, int z, int bScreenCoord, void* esi, int bSetFocus)
-> void {_CWndCreateWnd(pThis, edx, nLeft, nTop, nWidth, nHeight, z, bScreenCoord, esi, bSetFocus); //changing the values here will modify the result of the function
						//usually put changes here //this only runs after the original execution
};

typedef void(__fastcall* _CLoginSendSelectCharPacket_t)(void* pThis, void* edx);
static auto _CLoginSendSelectCharPacket = reinterpret_cast<_CLoginSendSelectCharPacket_t>(0x005F726D);
static _CLoginSendSelectCharPacket_t _CLoginSendSelectCharPacket_Hook = [](void* pThis, void* edx)
-> void {_CLoginSendSelectCharPacket(pThis, edx); //changing the values here will modify the result of the function
//Client::loggedIn = 1;						//usually put changes here
//Client::UpdateResolution();	//tried to get client to change to different res than login while in main game. failed. this is what's left
};

enum RESMAN_PARAM {
	RC_AUTO_SERIALIZE = 0x1,
	RC_AUTO_SERIALIZE_NO_CACHE = 0x2,
	RC_NO_AUTO_SERIALIZE = 0x4,
	RC_DEFAULT_AUTO_SERIALIZE = 0x0,
	RC_AUTO_SERIALIZE_MASK = 0x7,
	RC_AUTO_REPARSE = 0x10,
	RC_NO_AUTO_REPARSE = 0x20,
	RC_DEFAULT_AUTO_REPARSE = 0x0,
	RC_AUTO_REPARSE_MASK = 0x30,
};

// DWORD Address
auto g_rm = (void**)0x00BF14E8; //static?
auto g_root = (void**)0x00BF14E0;
auto pNameSpace = 0x00BF0CD0;

// Generic
void* pUnkOuter = 0;
void* nPriority = 0;

typedef void(__fastcall* _CWvsApp__InitializeResMan_t)(void* pThis, void* edx);	//ty to all the contributors of the ragezone release: Client load .img instead of .wz v62~v92 //ty y785	//char* ecx, char* edx
static auto _CWvsApp__InitializeResMan = reinterpret_cast<_CWvsApp__InitializeResMan_t>(0x009F7159);

typedef void(__cdecl* _PcCreateObject_IWzResMan_t)(const wchar_t* sUOL, void* pObj, void* pUnkOuter);
static auto _PcCreateObject_IWzResMan = reinterpret_cast<_PcCreateObject_IWzResMan_t>(0x009FAF55);
static _PcCreateObject_IWzResMan_t _PcCreateObject_IWzResMan_Hook = [](const wchar_t* sUOL, void* pObj, void* pUnkOuters) {
	//-> void {_PcCreateObject_IWzResMan(sUOL, pObj, pUnkOuter); //remove -> part and redefine to replace parts of execution code proper
	_PcCreateObject_IWzResMan(sUOL, pObj, pUnkOuter);
};

typedef void(__cdecl* _PcCreateObject_IWzNameSpace_t)(const wchar_t* sUOL, void* pObj, void* pUnkOuter);
static auto _PcCreateObject_IWzNameSpace = reinterpret_cast<_PcCreateObject_IWzNameSpace_t>(0x009FAFBA);
static _PcCreateObject_IWzNameSpace_t _PcCreateObject_IWzNameSpace_Hook = [](const wchar_t* sUOL, void* pObj, void* pUnkOuters) {
	//-> void {_PcCreateObject_IWzNameSpace(sUOL, pObj, pUnkOuter);
	_PcCreateObject_IWzNameSpace(sUOL, pObj, pUnkOuter);
};

typedef void(__cdecl* _PcCreateObject_IWzFileSystem_t)(const wchar_t* sUOL, void* pObj, void* pUnkOuter);
static auto _PcCreateObject_IWzFileSystem = reinterpret_cast<_PcCreateObject_IWzFileSystem_t>(0x009FB01F);
static _PcCreateObject_IWzFileSystem_t _PcCreateObject_IWzFileSystem_Hook = [](const wchar_t* sUOL, void* pObj, void* pUnkOuters) {
	//-> void {_PcCreateObject_IWzFileSystem(sUOL, pObj, pUnkOuter);
	_PcCreateObject_IWzFileSystem(sUOL, pObj, pUnkOuter);
};

typedef void(__cdecl* _CWvsApp__Dir_BackSlashToSlash_t)(char* sDir);
static auto _CWvsApp__Dir_BackSlashToSlash = reinterpret_cast<_CWvsApp__Dir_BackSlashToSlash_t>(0x009F95FE);
static _CWvsApp__Dir_BackSlashToSlash_t _CWvsApp__Dir_BackSlashToSlash_Hook = [](char* sDir) {
	//-> void {_CWvsApp__Dir_BackSlashToSlash(sDir); 
	int myLength = strlen(sDir);
	for (int i = 0; i < myLength; ++i) { if (sDir[i] == '\\') { sDir[i] = '/'; } }
};

typedef void(__cdecl* _CWvsApp__Dir_upDir_t)(char* sDir);
static auto _CWvsApp__Dir_upDir = reinterpret_cast<_CWvsApp__Dir_upDir_t>(0x009F9644);
static _CWvsApp__Dir_upDir_t _CWvsApp__Dir_upDir_Hook = [](char* sDir) {
	//-> void {_CWvsApp__Dir_upDir(sDir); 
	_CWvsApp__Dir_upDir(sDir);
};

typedef char* (__fastcall* _bstr_ctor_t)(void* pThis, void* edx, const char* str);
static auto _bstr_ctor = reinterpret_cast<_bstr_ctor_t>(0x00406301);
static _bstr_ctor_t _bstr_ctor_Hook = [](void* pThis, void* edx, const char* str) {
	return _bstr_ctor(pThis, edx, str); };

typedef HRESULT(__fastcall* _IWzFileSystem__Init_t)(void* pThis, void* edx, void* sPath);	//HRESULT
static auto _IWzFileSystem__Init = reinterpret_cast<_IWzFileSystem__Init_t>(0x009F7964);
static _IWzFileSystem__Init_t _IWzFileSystem__Init_Hook = [](void* pThis, void* edx, void* sPath) {
	//-> HRESULT {_IWzFileSystem__Init(pThis, edx, sPath);	//HRESULT
	//std::cout << "_IWzFileSystem__Init " << " pThis: " << pThis << " edx: " << edx << " sPath: " << sPath << std::endl;
	return _IWzFileSystem__Init(pThis, edx, sPath);
};

typedef HRESULT(__fastcall* _IWzNameSpace__Mount_t)(void* pThis, void* edx, void* sPath, void* pDown, int nPriority); //HRESULT
static auto _IWzNameSpace__Mount = reinterpret_cast<_IWzNameSpace__Mount_t>(0x009F790A);
static _IWzNameSpace__Mount_t _IWzNameSpace__Mount_Hook = [](void* pThis, void* edx, void* sPath, void* pDown, int nPriority) {
	//-> HRESULT {_IWzNameSpace__Mount(pThis, edx, sPath, pDown, nPriority); //HRESULT //return _IWzNameSpace__Mount(pThis, edx, sPath, pDown, nPriority);
	return _IWzNameSpace__Mount(pThis, edx, sPath, pDown, nPriority);
};
