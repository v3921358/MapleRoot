#pragma once
#include <Windows.h>
void Log(const char* format, ...);

BOOL HaxSock();
BOOL HaxWinApi();
BOOL HaxMaple();

BOOL SetHook(BOOL bInstall, PVOID* ppvTarget, PVOID pvDetour);

DWORD GetFuncAddress(LPCSTR lpModule, LPCSTR lpFunc);
DWORD MakePageWritable(void* address, size_t cb, DWORD flprotect);

void WriteByte(DWORD address, BYTE value);
void WriteValue(DWORD dwBase, const unsigned int dwValue);
void PatchRetZero(DWORD address);
void PatchCall(DWORD address, void* dst);
void PatchJmp(DWORD address);
void PatchJmp(DWORD address, void* dst, int nops);
void WriteDouble(DWORD dwOriginAddress, double dwValue);
void PatchJmpShort(DWORD address);
void PatchNop(DWORD address, UINT count);
void PatchNegEax(DWORD address);
void WriteBytes(DWORD dwAddress, LPCVOID pData, UINT nCount);
void WriteString(DWORD dwAddress, const char* sContent);
void FillBytes(DWORD dwOriginAddress, unsigned char ucValue, int nCount);
void WriteByteArray(DWORD dwOriginAddress, unsigned char* ucValue, const int ucValueSize);


void WriteAoB(DWORD dwAddress, const char* sBytes);
unsigned int ReadAoB(const char* sAoB, unsigned char* pBuff, bool* pMask);
unsigned int FindAoB(const char* sAoB, DWORD dwStartAddress, DWORD dwEndAddress, int nSkip);

void CodeCave(void* codeCave, DWORD originalAddy, int nops);