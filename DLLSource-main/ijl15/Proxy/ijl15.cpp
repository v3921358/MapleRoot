#include <Windows.h>
#include "ijl15.h"

#define LIB_NAME	"2ijl15.dll"
#define LIB_EXPORT	extern "C" __declspec(dllexport)

DWORD ijlErrorStr_Proc;
DWORD ijlFree_Proc;
DWORD ijlGetLibVersion_Proc;
DWORD ijlInit_Proc;
DWORD ijlRead_Proc;
DWORD ijlWrite_Proc;

BOOL InitializeIjl15() {
	HMODULE SeData_Base = LoadLibraryA(LIB_NAME);

	if (SeData_Base) {
		ijlErrorStr_Proc = (DWORD)GetProcAddress(SeData_Base, "ijlErrorStr");
		ijlFree_Proc = (DWORD)GetProcAddress(SeData_Base, "ijlFree");
		ijlGetLibVersion_Proc = (DWORD)GetProcAddress(SeData_Base, "ijlGetLibVersion");
		ijlInit_Proc = (DWORD)GetProcAddress(SeData_Base, "ijlInit");
		ijlRead_Proc = (DWORD)GetProcAddress(SeData_Base, "ijlRead");
		ijlWrite_Proc = (DWORD)GetProcAddress(SeData_Base, "ijlWrite");

		return TRUE;
	}

	return FALSE;
}

BOOL g_InitIjl15 = InitializeIjl15();

LIB_EXPORT void ijlGetLibVersion() {
	__asm 	 jmp dword ptr[ijlGetLibVersion_Proc]
}

LIB_EXPORT void ijlInit() {
	__asm  jmp dword ptr[ijlInit_Proc]
}

LIB_EXPORT void ijlFree() {
	__asm 	 jmp dword ptr[ijlFree_Proc]
}

LIB_EXPORT void ijlRead() {
	__asm jmp dword ptr[ijlRead_Proc]
}

LIB_EXPORT void ijlWrite() {
	__asm  jmp dword ptr[ijlWrite_Proc]
}

LIB_EXPORT void ijlErrorStr() {
	__asm  jmp dword ptr[ijlErrorStr_Proc]
}
