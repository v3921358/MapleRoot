#pragma once
#include <Windows.h>

struct COutPacket {
	int Loopback;
	union {
		PUCHAR Data;
		PVOID Unk;
		PUSHORT Header;
	};
	ULONG Size;
	UINT Offset;
	int EncryptedByShanda;
};

struct SendPacketData {
	DWORD ReturnAddress;
	COutPacket* packet;
};

struct CInPacket {
	bool fLoopback;
	int iState;
	union {
		BYTE* lpvData;
		struct {
			ULONG dw;
			USHORT wHeader;
		} *pHeader;
		struct {
			ULONG dw;
			PUCHAR Data;
		} *pData;
	};
	ULONG Size;
	USHORT usRawSeq;
	USHORT usDataLen;
	USHORT usUnknown;
	UINT uOffset;
	PVOID lpv;
	template<typename T>
	T Decode()
	{
		// TODO write real decode template instead of relying on decodebuffer

		typedef INT(__fastcall* _DecodeBuffer_t)(CInPacket* pThis, PVOID edx, PVOID p, size_t nLen);
		static _DecodeBuffer_t _DecodeBuffer = reinterpret_cast<_DecodeBuffer_t>(0x00432257);

		T retval;

		_DecodeBuffer(this, NULL, &retval, sizeof(T));

		return retval;
	}
};

struct SpawnControlData {
	UINT mapID;
	INT spawnX;
	INT spawnY;

	SpawnControlData(UINT mapID, INT spawnX, INT spawnY) {
		this->mapID = mapID;
		this->spawnX = spawnX;
		this->spawnY = spawnY;
	}
};