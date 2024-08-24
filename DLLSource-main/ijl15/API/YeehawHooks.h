#include "../Global.h"
#include "MapleStory/Type/ZXString.h"
#include "MapleStory/Static.h"
#include "MapleStory/UI/CWnd.h"
#include "MapleStory/Classes/CUserLocal.h"
#include "MapleStory/WZ/Bstr_T.h"
#include "MapleStory/Classes/CSkillInfo.h"
#include "MapleStory/Type/CInPacket.h"


#pragma once
bool _CInPacket_Decode1(bool enable) {
	typedef char(__fastcall* CInPacket__Decode1_t)(CInPacket* iPacket, void* edx);

	static auto CInPacket__Decode1 = reinterpret_cast<CInPacket__Decode1_t>(0x004097D0);

	CInPacket__Decode1_t Hook = [](CInPacket* iPacket, void* edx) -> char {
		if (iPacket->m_uLength - iPacket->m_uOffset < 1) {
			void* stack[10];
			unsigned short frame = CaptureStackBackTrace(0, 10, stack, NULL);
			for (int i = 0; i < 10; i++)
				Log(std::to_string((int)(stack[i])).c_str());
		}

		return CInPacket__Decode1(iPacket, edx);
	};

	return SetHook(enable, reinterpret_cast<void**>(&CInPacket__Decode1), Hook);
}

bool _CInPacket_Decode2(bool enable) {
	typedef __int16(__fastcall* CInPacket__Decode2_t)(CInPacket* iPacket, void* edx);

	static auto CInPacket__Decode2 = reinterpret_cast<CInPacket__Decode2_t>(0x0042A2A0);

	CInPacket__Decode2_t Hook = [](CInPacket* iPacket, void* edx) -> __int16 {
		if (iPacket->m_uLength - iPacket->m_uOffset < 2) {
			void* stack[10];
			unsigned short frame = CaptureStackBackTrace(0, 10, stack, NULL);
			for (int i = 0; i < 10; i++)
				Log(std::to_string((int)(stack[i])).c_str());
		}

		return CInPacket__Decode2(iPacket, edx);
	};

	return SetHook(enable, reinterpret_cast<void**>(&CInPacket__Decode2), Hook);
}

bool _CInPacket_Decode4(bool enable) {
	typedef int(__fastcall* CInPacket__Decode4_t)(CInPacket* iPacket, void* edx);

	static auto CInPacket__Decode4 = reinterpret_cast<CInPacket__Decode4_t>(0x00409870);

	CInPacket__Decode4_t Hook = [](CInPacket* iPacket, void* edx) -> int {
		if (iPacket->m_uLength - iPacket->m_uOffset < 4) {
			void* stack[10];
			unsigned short frame = CaptureStackBackTrace(0, 10, stack, NULL);
			for (int i = 0; i < 10; i++)
				Log(std::to_string((int)(stack[i])).c_str());
		}

		return CInPacket__Decode4(iPacket, edx);
	};

	return SetHook(enable, reinterpret_cast<void**>(&CInPacket__Decode4), Hook);
}

bool _CInPacket_DecodeBuffer(bool enable) {
	typedef void* (__fastcall* CInPacket__DecodeBuffer_t)(CInPacket* iPacket, void* edx, void* dst, size_t size);

	static auto CInPacket__DecodeBuffer = reinterpret_cast<CInPacket__DecodeBuffer_t>(0x004336A0);

	CInPacket__DecodeBuffer_t Hook = [](CInPacket* iPacket, void* edx, void* dst, size_t size) -> void* {
		if (iPacket->m_uLength - iPacket->m_uOffset < size) {
			void* stack[10];
			unsigned short frame = CaptureStackBackTrace(0, 10, stack, NULL);
			for (int i = 0; i < 10; i++)
				Log(std::to_string((int)(stack[i])).c_str());
		}

		return CInPacket__DecodeBuffer(iPacket, edx, dst, size);
	};

	return SetHook(enable, reinterpret_cast<void**>(&CInPacket__DecodeBuffer), Hook);
}

ZXString<char>* LackOfBetterFunctionNameSoImJustNamingItThis(ZXString<char>* string, const char* sFormat, ...)
{
	char buf[2048] = { 0 };
	va_list args;
	va_start(args, sFormat);
	vsprintf_s(buf, sFormat, args);

	std::string str(buf);
	std::string name = str.substr(0, str.find(" "));
	int a = name.length();
	int b = 28;
	int c = b - a;
	std::stringstream last;
	last << "%-" << c << "s   %-11s%6d";

	vsprintf_s(buf, last.str().c_str(), args);
	va_end(args);

	string->SetText(buf);

	return string;
}


bool Hook_StringPool__GetString(bool enable)
{
	typedef ZXString<char>* (__fastcall* StringPool__GetString_t)(void* ecx, void* edx, ZXString<char>* result, int nIdx);
	static auto StringPool__GetString = reinterpret_cast<StringPool__GetString_t>(0x00406455);
	StringPool__GetString_t Hook = [](void* ecx, void* edx, ZXString<char>* result, int nIdx) -> ZXString<char>*{
		auto ret = StringPool__GetString(ecx, edx, result, nIdx);
		if (stringPool.find(nIdx) != stringPool.end()) {
			result->SetText(stringPool[nIdx]);
		}
		return ret;
	};
	return SetHook(enable, reinterpret_cast<void**>(&StringPool__GetString), Hook);
}


const char* test = "SOFTWARE\\MAO\\MAO";
DWORD ret = 0x009BF82D;

__declspec(naked) void Replace()
{
	__asm
	{
		push offset[test]
		jmp dword ptr[ret]
	}
}

void ReplaceStringPool(int id, std::string string)
{
	stringPool[id] = string;
}
//
void StringPoolStuff()
{
	Hook_StringPool__GetString(true);

	ReplaceStringPool(2585, "SOFTWARE\\MAO\\MAOSTORY");

	//PatchJmp(0x009BF828, Replace);
}

void PatchDlgEx() {
	// color
	WriteByte(0x00985BBA, 0x22);
	WriteByte(0x00985BBB, 0x22);
	WriteByte(0x00985BBC, 0x22);
	WriteByte(0x00985CD2, 0x22);
	WriteByte(0x00985CD3, 0x22);
	WriteValue(0x00985FE9 + 1, 0xFF028A0F); // green
	WriteValue(0x0098610F + 1, 0xFF028A0F); // green

	// size
	WriteByte(0x00985BBF, 0xC);
	WriteByte(0x00985CD7, 0xC);
	WriteByte(0x00985DD3, 0xC);
	WriteByte(0x00985EF5, 0xC);
	WriteByte(0x00985FEF, 0xC);
	WriteByte(0x00986115, 0xC);
	WriteByte(0x0098620F, 0xC);
	WriteByte(0x00986335, 0xC);
	WriteByte(0x0098642C, 0xC);
	WriteByte(0x00986552, 0xC);
	WriteByte(0x0098664C, 0xC);
	WriteByte(0x00986552, 0xC);
	WriteByte(0x0098664C, 0xC);
	WriteByte(0x00986775, 0xC);
}


//
//void PatchSecurity() {
//	// All necessary to skip client security stuff
	PatchJmp(0x0044E88E, Hook_MyGetProcAddress);

	PatchJmpShort(0x009F5CA3, 0x009F5FDF);
	PatchJmpShort(0x009F526F, 0x009F55D8);
	PatchJmpShort(0x009F5616, 0x009F5623);
	PatchJmpShort(0x009F55FB, 0x009F5608);
	PatchNop(0x009F1C04, 5);
	PatchRetZero(0x0044EC9C);
	PatchRetZero(0x0044EC9C); // hidedll
	PatchRetZero(0x0044ED47); // reset lsp
	//PatchRetZero(0x009BF370);
	//PatchRetZero(0x0066A050);
	PatchRetZero(0x004AB380);
	PatchRetZero(0x004AB8B0);
	PatchRetZero(0x004AB900);
	PatchRetZero(0x004AD020);
	PatchRetZero(0x00571740);
//
//	PatchNop(0x00496670, 12);
//	//WriteValue(0x009C6DEA, 0xEB);
//
//	//PatchRetZero(0x009DBEC0);
//}