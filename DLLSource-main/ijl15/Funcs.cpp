#include "Global.h"
#include <iostream>

void Log(const char* format, ...) {
	char buf[2048] = { 0 };

	va_list args;
	va_start(args, format);
	vsprintf_s(buf, format, args);

	OutputDebugStringA(buf);
	std::cout << buf << std::endl;

	va_end(args);
}

bool UseVirtuProtect = true;

BOOL SetHook(BOOL bInstall, PVOID* ppvTarget, PVOID pvDetour) {
	if (DetourTransactionBegin() != NO_ERROR) {
		return FALSE;
	}

	auto tid = GetCurrentThread();

	if (DetourUpdateThread(tid) == NO_ERROR) {
		auto func = bInstall ? DetourAttach : DetourDetach;

		if (func(ppvTarget, pvDetour) == NO_ERROR) {
			if (DetourTransactionCommit() == NO_ERROR) {
				return TRUE;
			}
		}
	}

	DetourTransactionAbort();
	return FALSE;
}

void FillBytes(const DWORD dwOriginAddress, const unsigned char ucValue, const int nCount) {
	DWORD dwOldProtect;
	VirtualProtect((LPVOID)dwOriginAddress, nCount, PAGE_EXECUTE_READWRITE, &dwOldProtect); //thanks colaMint, joo, and stelmo for informing me of using virtualprotect
	memset((void*)dwOriginAddress, ucValue, nCount);
	VirtualProtect((LPVOID)dwOriginAddress, nCount, dwOldProtect, &dwOldProtect);
}

void WriteString(const DWORD dwOriginAddress, const char* sContent) {
	const size_t nSize = strlen(sContent);
	if (UseVirtuProtect) {
		DWORD dwOldProtect;
		VirtualProtect((LPVOID)dwOriginAddress, nSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);
		memcpy((void*)dwOriginAddress, sContent, nSize);
		VirtualProtect((LPVOID)dwOriginAddress, nSize, dwOldProtect, &dwOldProtect);
	}
	else { memcpy((void*)dwOriginAddress, sContent, nSize); }
}


DWORD GetFuncAddress(LPCSTR lpModule, LPCSTR lpFunc) {
	auto mod = LoadLibraryA(lpModule);
	auto address = (DWORD)GetProcAddress(mod, lpFunc);

#ifdef _DEBUG
	Log(__FUNCTION__ " [%s] %s @ %8X", lpModule, lpFunc, address);
#endif

	return (DWORD)GetProcAddress(mod, lpFunc);
}

DWORD MakePageWritable(void* address, size_t cb, DWORD flprotect) {
	MEMORY_BASIC_INFORMATION mbi = { 0 };
	VirtualQuery(address, &mbi, cb);

	if (mbi.Protect != flprotect) {
		DWORD oldprotect;
		VirtualProtect(address, cb, flprotect, &oldprotect);
		return oldprotect;
	}

	return flprotect;
}

void WriteByte(const DWORD dwOriginAddress, const unsigned char ucValue) {
	if (UseVirtuProtect) {
		DWORD dwOldProtect;
		VirtualProtect((LPVOID)dwOriginAddress, sizeof(unsigned char), PAGE_EXECUTE_READWRITE, &dwOldProtect);
		*(unsigned char*)dwOriginAddress = ucValue;
		VirtualProtect((LPVOID)dwOriginAddress, sizeof(unsigned char), dwOldProtect, &dwOldProtect);
	}
	else { *(unsigned char*)dwOriginAddress = ucValue; }
}

void WriteValue(const DWORD dwOriginAddress, const unsigned int dwValue) {
	if (UseVirtuProtect) {
		DWORD dwOldProtect;
		VirtualProtect((LPVOID)dwOriginAddress, sizeof(unsigned int), PAGE_EXECUTE_READWRITE, &dwOldProtect);
		*(unsigned int*)dwOriginAddress = dwValue;
		VirtualProtect((LPVOID)dwOriginAddress, sizeof(unsigned int), dwOldProtect, &dwOldProtect);
	}
	else { *(unsigned int*)dwOriginAddress = dwValue; }
}

void PatchRetZero(DWORD address) {
	MakePageWritable((void*)address, 3, PAGE_EXECUTE_READWRITE);
	*(BYTE*)(address + 0) = 0x33;
	*(BYTE*)(address + 1) = 0xC0;
	*(BYTE*)(address + 2) = 0xC3;
}
void PatchCall(DWORD address, void* dst) {
	MakePageWritable((void*)address, 3, PAGE_EXECUTE_READWRITE);
	*(BYTE*)address = 0xE8;
	*(DWORD*)(address + 1) = relative_address(address, dst);
}
void PatchJmp(DWORD address) {
	MakePageWritable((void*)address, 3, PAGE_EXECUTE_READWRITE);
	*(BYTE*)address = 0xE9;
}

void PatchJmpShort(DWORD address) {
	MakePageWritable((void*)address, 3, PAGE_EXECUTE_READWRITE);
	*(BYTE*)address = 0xEB;
}

void PatchJmp(DWORD address, void* dst, int nops) {
	MakePageWritable((void*)address, 5 + nops, PAGE_EXECUTE_READWRITE);
	*(BYTE*)address = 0xE9;
	*(DWORD*)(address + 1) = relative_address(address, dst);
	if (nops > 0)
		PatchNop(address + 5, nops);
}

void WriteDouble(const DWORD dwOriginAddress, const double dwValue) {
	if (UseVirtuProtect) {
		DWORD dwOldProtect;
		VirtualProtect((LPVOID)dwOriginAddress, sizeof(double), PAGE_EXECUTE_READWRITE, &dwOldProtect);
		*(double*)dwOriginAddress = dwValue;
		VirtualProtect((LPVOID)dwOriginAddress, sizeof(double), dwOldProtect, &dwOldProtect);
	}
	else { *(double*)dwOriginAddress = dwValue; }
}

void PatchNop(DWORD dwAddress, UINT nCount)
{
	if (nCount == 0)
		return;

	MEMORY_BASIC_INFORMATION mbi;
	DWORD dwOldProtect;

	// Get the current memory protection
	VirtualQuery((LPVOID)dwAddress, &mbi, sizeof(MEMORY_BASIC_INFORMATION));
	VirtualProtect(mbi.BaseAddress, mbi.RegionSize, PAGE_EXECUTE_READWRITE, &dwOldProtect);

	// Fill the memory with NOPs
	memset((void*)dwAddress, 0x90, nCount);

	// Restore the original memory protection
	VirtualProtect(mbi.BaseAddress, mbi.RegionSize, dwOldProtect, &dwOldProtect);
}


//void PatchNegEax(DWORD address)
//{
//	MakePageWritable((void*)address, 2, PAGE_EXECUTE_READWRITE);
//	*(BYTE*)(address + 0) = 0xF7;
//	*(BYTE*)(address + 1) = 0xD8;
//}

#define PE_START	0x401000 /* The standard PE start address */
#define MAX_BUFFER	1024 /* Maximum buffer size used for various arrays */

void WriteAoB(DWORD dwAddress, const char* sBytes) {
	// Calculate the length of the AoB
	const unsigned int uLen = strlen(sBytes);
	// Initialize the new, real length of memory to copy
	unsigned int uBufLen = 1;
	// Construct a new buffer for the fixed AoB
	BYTE pBuff[MAX_BUFFER] = { 0x00 };

	// Not enough bytes, invalid AoB
	if (uLen < 2 || uLen > MAX_BUFFER || dwAddress < PE_START) return;

	int i = 0;
	BYTE bInstruction;
	// Continue looping to further replace all AoB ASCII with appropriate HEX
	while ((bInstruction = (BYTE)*sBytes++), bInstruction) {
		BYTE bFlag = (i % 2 == 0) ? 4 : 0;//HIGH/LOW

		if (bInstruction >= '0' && bInstruction <= '9')
			pBuff[i++ / 2] += (bInstruction - '0') << bFlag;
		else if (bInstruction >= 'A' && bInstruction <= 'F')
			pBuff[i++ / 2] += (bInstruction - 'A' + 0xA) << bFlag;
		else if (bInstruction >= 'a' && bInstruction <= 'f')
			pBuff[i++ / 2] += (bInstruction - 'a' + 0xA) << bFlag;

		if (bInstruction == ' ')
			++uBufLen;
	}

	// Copy the new buffer to the address given, writing uBufLen bytes
	memcpy(reinterpret_cast<void*>(dwAddress), pBuff, uBufLen);
}

unsigned int ReadAoB(const char* sAoB, unsigned char* pBuff, bool* pMask) {
	unsigned char bOp;
	int i = 0, j = 0;

	while ((bOp = (BYTE)sAoB[j]), bOp) {
		unsigned char bFlag = (i % 2 == 0) ? 4 : 0;

		if (bOp >= '0' && bOp <= '9')
			pBuff[i++ / 2] += (bOp - '0') << bFlag;
		else if (bOp >= 'A' && bOp <= 'F')
			pBuff[i++ / 2] += (bOp - 'A' + 0xA) << bFlag;
		else if (bOp >= 'a' && bOp <= 'f')
			pBuff[i++ / 2] += (bOp - 'a' + 0xA) << bFlag;
		else if (bOp == '?') {
			pBuff[i / 2] = 0xFF;
			pMask[i / 2] = true;
			i++;
		}
		j++;
	}

	return (i % 2 == 0) ? (i / 2) : -1;
}

unsigned int FindAoB(const char* sAoB, DWORD dwStartAddress, DWORD dwEndAddress, int nSkip) {
	unsigned char pBuff[MAX_BUFFER] = { 0x00 };
	bool aMask[MAX_BUFFER] = { 0x00 };
	unsigned int uSize = ReadAoB(sAoB, pBuff, aMask);
	unsigned int i, j;
	int nSkipped = 0;

	if (uSize > 0) {
		dwStartAddress = dwStartAddress ? dwStartAddress : PE_START;
		dwEndAddress = dwEndAddress ? dwEndAddress : 0x07FFFFFF;

		__try {
			for (i = dwStartAddress; i < (dwEndAddress - uSize); i++) {
				for (j = 0; j < uSize; j++) {
					if (aMask[j]) {
						continue;
					}
					if (pBuff[j] != *(unsigned char*)(i + j)) {
						break;
					}
				}
				if (j == uSize) {
					if (nSkipped++ >= nSkip) {
						return i;
					}
				}
			}
		}
		__except (EXCEPTION_EXECUTE_HANDLER) {
		}
	}

	return 0;
}

void WriteBytes(DWORD dwAddress, LPCVOID pData, UINT nCount)
{
	DWORD dwOldValue, dwTemp;
	VirtualProtect((LPVOID)dwAddress, nCount, PAGE_EXECUTE_READWRITE, &dwOldValue);
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)dwAddress, pData, nCount, nullptr);
	VirtualProtect((LPVOID)dwAddress, nCount, dwOldValue, &dwTemp);
}

void CodeCave(void* ptrCodeCave, const DWORD dwOriginAddress, const int nNOPCount) { //tested and working
	__try {
		if (nNOPCount) FillBytes(dwOriginAddress, 0x90, nNOPCount); // create space for the jmp
		WriteByte(dwOriginAddress, 0xe9); // jmp instruction
		WriteValue(dwOriginAddress + 1, (int)(((int)ptrCodeCave - (int)dwOriginAddress) - 5)); // [jmp(1 byte)][address(4 bytes)] //this means you need to clear a space of at least 5 bytes (nNOPCount bytes)
	}
	__except (EXCEPTION_EXECUTE_HANDLER) {}
}

void WriteByteArray(const DWORD dwOriginAddress, unsigned char* ucValue, const int ucValueSize) {
	if (UseVirtuProtect) {
		for (int i = 0; i < ucValueSize; i++) {
			const DWORD newAddr = dwOriginAddress + i;
			DWORD dwOldProtect;
			VirtualProtect((LPVOID)newAddr, sizeof(unsigned char), PAGE_EXECUTE_READWRITE, &dwOldProtect);
			*(unsigned char*)newAddr = ucValue[i];
			VirtualProtect((LPVOID)newAddr, sizeof(unsigned char), dwOldProtect, &dwOldProtect);
		}
	}
	else {
		for (int i = 0; i < ucValueSize; i++) { const DWORD newAddr = dwOriginAddress + i; *(unsigned char*)newAddr = ucValue[i]; }
	}
}