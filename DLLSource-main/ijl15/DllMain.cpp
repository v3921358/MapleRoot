
#include "Global.h"
#include "shavitstuff/xorstr.h"
#include "shavitstuff/lazy_import.h"

HMODULE _this;



std::string GetCrashLogName() {
	time_t now = time(0);
	struct tm timeStruct {};
	char buf[80];
	localtime_s(&timeStruct, &now);
	strftime(buf, sizeof(buf), "Exception %Y-%m-%d %X.log", &timeStruct);
	return buf;
}

static DWORD GetModuleBase(HMODULE hModule)
{
	PIMAGE_DOS_HEADER dos = PIMAGE_DOS_HEADER(hModule);
	PIMAGE_NT_HEADERS nt = PIMAGE_NT_HEADERS(long(hModule) + dos->e_lfanew);
	PIMAGE_OPTIONAL_HEADER header = &nt->OptionalHeader;

	return header->ImageBase;
}

static DWORD GetModuleImageSize(HMODULE hModule)
{
	PIMAGE_DOS_HEADER dos = PIMAGE_DOS_HEADER(hModule);
	PIMAGE_NT_HEADERS nt = PIMAGE_NT_HEADERS(long(hModule) + dos->e_lfanew);
	PIMAGE_OPTIONAL_HEADER header = &nt->OptionalHeader;

	return header->SizeOfImage;
}

void* TrackExceptions() {
	PVECTORED_EXCEPTION_HANDLER exception_handler = [](EXCEPTION_POINTERS* pExceptionInfo) -> long {
		if (pExceptionInfo->ExceptionRecord->ExceptionCode == 0xE06D7363) {
			// We ignore CMSExceptions because it just fills up quickly, especially if you multiclient lol
		}
		else if (pExceptionInfo->ExceptionRecord->ExceptionCode != STATUS_PRIVILEGED_INSTRUCTION &&
			pExceptionInfo->ExceptionRecord->ExceptionCode != DBG_PRINTEXCEPTION_C) {
			if (pExceptionInfo->ExceptionRecord->ExceptionCode == STATUS_HEAP_CORRUPTION ||
				pExceptionInfo->ExceptionRecord->ExceptionCode == STATUS_ACCESS_VIOLATION) {
				if (pExceptionInfo->ExceptionRecord->ExceptionAddress != 0) {
					FILE* ff;
					std::regex regexp("[:]");
					errno_t err = fopen_s(&ff, std::regex_replace(GetCrashLogName(), regexp, "-").c_str(), "a+");
					if (err == 0 && ff) {
						DWORD minusVal = (DWORD)_this - 0x10001000;
						DWORD curEsp = 0x0;

						for (int i = 0; i < 0x400; i += 4) {
							curEsp = *(DWORD*)(pExceptionInfo->ContextRecord->Esp + i);
							if (curEsp >= 0x00401000 && curEsp <= 0x00D96FFF) { // Executable
								fprintf_s(ff, "Esp+%02X (ME) = %08X\n", i, curEsp);
							}
							//else if (curEsp >= (DWORD)_this && curEsp <= ((DWORD)_this + 0x10080000)) { // DLL
							//	fprintf_s(ff, "Esp+%02X (MD) = %08X\n", i, curEsp - minusVal);
							//}
							//else { // Everything else
							//	fprintf_s(ff, "Esp+%02X = %08X\n", i, curEsp);
							//}
						}
						fclose(ff);
					}
				}
			}
			else {
				// Reg exceptions are dumb
			}
		}
		return EXCEPTION_CONTINUE_SEARCH;
	};
	return AddVectoredExceptionHandler(1, exception_handler);
}


void write_buffer(uintptr_t address, const char* aBuffer, size_t dwSize)
{
	unsigned long oldprot;
	LI_FN(VirtualProtect)(reinterpret_cast<void*>(address), dwSize, PAGE_EXECUTE_READWRITE, &oldprot);
	std::copy(aBuffer, aBuffer + dwSize, reinterpret_cast<uint8_t*>(address));
	LI_FN(VirtualProtect)(reinterpret_cast<void*>(address), dwSize, oldprot, nullptr);
}

std::string get_ip(std::string_view hostname)
{
	WSADATA data;
	LI_FN(WSAStartup)(MAKEWORD(1, 1), &data);
	auto host = LI_FN(gethostbyname)(hostname.data());
	auto ip = LI_FN(inet_ntoa)(*reinterpret_cast<in_addr*>(host->h_addr_list[0]));
	LI_FN(WSACleanup)();

	return ip;
}

void doitNow()
{
	auto ip = get_ip(xorstr_("localhost"));
	auto ip = get_ip(xorstr_("localhost"));
	auto ip = get_ip(xorstr_("localhost"));
	for (const auto& address : { 0x00AFE084, 0x00AFE094, 0x00AFE0A4 })
	{
		write_buffer(address, ip.data(), ip.length() + 1);
	}
}

//
//bool HookGetModuleFileName(bool bEnable) {
//	static decltype(&GetModuleFileNameW) _GetModuleFileNameW = &GetModuleFileNameW;
//
//	const decltype(&GetModuleFileNameW) GetModuleFileNameW_Hook = [](HMODULE hModule, LPWSTR lpFileName, DWORD dwSize) -> DWORD {
//		auto len = _GetModuleFileNameW(hModule, lpFileName, dwSize);
//		// Check to see if the length is invalid (zero)
//		if (!len) {
//			// Try again without the provided module for a fixed result
//			len = _GetModuleFileNameW(nullptr, lpFileName, dwSize);
//		}
//		return len;
//	};
//
//	return SetHook(bEnable, reinterpret_cast<void**>(&_GetModuleFileNameW), GetModuleFileNameW_Hook);
//}
//
///// <summary>
///// Creates a detour for the User32.dll CreateWindowExA function applying the following changes:
///// 1. Enable the window minimize box
///// </summary>
//inline void HookCreateWindowExA(bool bEnable) {
//	static auto create_window_ex_a = decltype(&CreateWindowExA)(GetProcAddress(LoadLibraryA("USER32"), "CreateWindowExA"));
//	static const decltype(&CreateWindowExA) hook = [](DWORD dwExStyle, LPCSTR lpClassName, LPCSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam) -> HWND {
//		dwStyle |= WS_MINIMIZEBOX; // enable minimize button
//		return create_window_ex_a(dwExStyle, lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
//	};
//	SetHook(bEnable, reinterpret_cast<void**>(&create_window_ex_a), hook);
//}


BOOL WINAPI Injected() {
	//TrackExceptions();
	//AllocConsole();
    freopen("CONIN$", "r", stdin);
    freopen("CONOUT$", "w", stdout);
    freopen("CONOUT$", "w", stderr);
	BOOL bResult = TRUE;
	bResult &= HaxMaple();
	return TRUE;
}

BOOL APIENTRY DllMain(HMODULE hModule, unsigned long ulReason, void* lpvReserved) {
    _this = hModule;
	if (ulReason == DLL_PROCESS_ATTACH) {
		BOOL bResult = TRUE;
		bResult &= HaxWinApi();
		doitNow();
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(&Injected), NULL, 0, NULL);
	}
	return TRUE;
}