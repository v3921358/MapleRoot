#include "Global.h"
INIReader reader("config.ini");
bool Hook_CreateWindowExA(bool bEnable) {
	static auto _CreateWindowExA = decltype(&CreateWindowExA)(GetFuncAddress("USER32", "CreateWindowExA"));
	decltype(&CreateWindowExA) Hook = [](DWORD dwExStyle, LPCTSTR lpClassName, LPCTSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam) -> HWND {
		dwStyle |= WS_MINIMIZEBOX;
		if (!strcmp(lpClassName, "StartUpDlgClass")) {
			HaxMaple();
#ifdef SKIP_MAPLE_SPLASH
			return NULL;
#endif
		}
		else if (!strcmp(lpClassName, "MapleStoryClass")) {
			if (reader.ParseError() == 0)
			{
				if (reader.GetBoolean("general", "center", "true")) {
					RECT rectDesktop;
					GetWindowRect(GetDesktopWindow(), &rectDesktop);

					x = (rectDesktop.right / 2) - (1366 / 2);
					y = (rectDesktop.bottom / 2) - (768 / 2);
				}
			}
			return _CreateWindowExA(dwExStyle, lpClassName, WINDOW_NAME, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
		}
		else if (!strcmp(lpClassName, "NexonADBallon")) {
#ifdef SKIP_MAPLE_AD
			return NULL;
#endif		
		}
		return _CreateWindowExA(dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
	};
	return SetHook(bEnable, reinterpret_cast<void**>(&_CreateWindowExA), Hook);
}


bool Hook_OpenMutexA(bool bEnable) {
	static auto _OpenMutexA = decltype(&OpenMutexA)(GetFuncAddress("KERNEL32", "OpenMutexA"));
	decltype(&OpenMutexA) Hook = [](DWORD dwDesiredAccess, BOOL bInheritHandle, LPCSTR lpName) -> HANDLE {
		if (lpName && strstr(lpName, "meteora")) {
			return (HANDLE)0xDEADBEEF;
		}
		return _OpenMutexA(dwDesiredAccess, bInheritHandle, lpName);
	};
	return SetHook(bEnable, reinterpret_cast<void**>(&_OpenMutexA), Hook);
}

bool Hook_CreateMutexA(bool bEnable) {
	static auto _CreateMutexA = decltype(&CreateMutexA)(GetFuncAddress("KERNEL32", "CreateMutexA"));
	decltype(&CreateMutexA) Hook = [](LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName) -> HANDLE {
		if (lpName && strstr(lpName, "WvsClientMtx")) {
			return (HANDLE)0xBADF00D;
		}
		return _CreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
	};
	return SetHook(bEnable, reinterpret_cast<void**>(&_CreateMutexA), Hook);
}

bool Hook_GetModuleFileNameW(bool bEnable) {
	static auto _GetModuleFileNameW = decltype(&GetModuleFileNameW)(GetFuncAddress("KERNEL32", "GetModuleFileNameW"));
	decltype(&GetModuleFileNameW) Hook = [](HMODULE hModule, LPWSTR lpFilename, DWORD nSize) -> DWORD {
		auto ret = _GetModuleFileNameW(hModule, lpFilename, nSize);
		if (!ret) {
			ret = _GetModuleFileNameW(NULL, lpFilename, nSize);
		}
		return ret;
	};
	return SetHook(bEnable, reinterpret_cast<void**>(&_GetModuleFileNameW), Hook);
}

bool Hook_GetModuleHandleA(bool bEnable) {
	static auto _GetModuleHandleA = decltype(&GetModuleHandleA)(GetFuncAddress("KERNEL32", "GetModuleHandleA"));
	decltype(&GetModuleHandleA) Hook = [](LPCSTR lpModuleName) -> HMODULE {
		if (lpModuleName && !strcmp(lpModuleName, "ehsvc.dll")) {
			lpModuleName = NULL;
		}
		return _GetModuleHandleA(lpModuleName);
	};
	return SetHook(bEnable, reinterpret_cast<void**>(&_GetModuleHandleA), Hook);
}

bool Hook_FindFirstFileA(bool bEnable) {
	static decltype(&FindFirstFileA) _FindFirstFileA = &FindFirstFileA;

	decltype(&FindFirstFileA) FindFirstFileA_Hook = [](LPCSTR lpFileName, LPWIN32_FIND_DATAA lpFindFileData) -> HANDLE {
		if (lpFileName && !strcmp(lpFileName, "*")) {
			return INVALID_HANDLE_VALUE;
		}
		return _FindFirstFileA(lpFileName, lpFindFileData);
	};
	return SetHook(bEnable, reinterpret_cast<void**>(&_FindFirstFileA), FindFirstFileA_Hook);
}

bool Hook_CreateFileA(bool bEnable) {
	static auto _CreateFileA = decltype(&CreateFileA)(GetFuncAddress("KERNEL32", "CreateFileA"));
	decltype(&CreateFileA) Hook = [](LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile) {
		if (lpFileName && strstr(lpFileName, "ws2_32.dll")) {
			return INVALID_HANDLE_VALUE;
		}
		return _CreateFileA(lpFileName, dwDesiredAccess, dwShareMode, lpSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
	};
	return SetHook(bEnable, reinterpret_cast<void**>(&_CreateFileA), Hook);
}

bool Hook_LoadLibraryA(bool bEnable) {
	static auto _LoadLibraryA = decltype(&LoadLibraryA)(GetFuncAddress("KERNEL32", "LoadLibraryA"));
	decltype(&LoadLibraryA) Hook = [](LPCTSTR lpFileName) -> HMODULE {
		if (lpFileName) {
			if (strstr(lpFileName, "setupapi.dll") || strstr(lpFileName, "cfgmgr32.dll")) {
				return NULL;
			}
		}
		return _LoadLibraryA(lpFileName);
	};
	return SetHook(bEnable, reinterpret_cast<void**>(&_LoadLibraryA), Hook);
}

unsigned long g_getTickCount = GetTickCount();
unsigned long(__stdcall* g_real_GetTickCount)(void) = GetTickCount;

unsigned long g_timeGetTime = timeGetTime();
unsigned long(__stdcall* g_real_timeGetTime)(void) = timeGetTime;

DWORD startTick = 0;
DWORD WINAPI Hook_GetTickCount()
{
	DWORD currentTick = GetTickCount();
	currentTick = (currentTick < startTick) ? 0 : startTick;
	return (currentTick - startTick);
}

DWORD startTime = 0;
DWORD WINAPI Hook_TimeGetTime()
{
	DWORD currentTime = timeGetTime();
	startTime = (currentTime < startTime) ? 0 : startTime;
	return (currentTime - startTime);
}

BOOL HaxWinApi() {
	bool bResult = true;
	Hook_TimeGetTime();
	Hook_GetTickCount();
	bResult &= Hook_CreateWindowExA(true);
	bResult &= Hook_OpenMutexA(true);
	bResult &= Hook_CreateMutexA(true);
	bResult &= Hook_GetModuleFileNameW(true);
	bResult &= Hook_GetModuleHandleA(true);
	bResult &= Hook_FindFirstFileA(true);
	bResult &= Hook_CreateFileA(true);
	bResult &= Hook_LoadLibraryA(true);
	/*bResult &= SetHook(true, (PVOID*)&g_real_timeGetTime, (PVOID)corrected_timeGetTime);
	bResult &= SetHook(true, (PVOID*)&g_real_GetTickCount, (PVOID)corrected_GetTickCount);*/

	return bResult;
}