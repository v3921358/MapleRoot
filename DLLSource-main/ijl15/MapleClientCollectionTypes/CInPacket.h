#pragma once
#include "ZArray.h"
#include <Windows.h>

struct CInPacket
{
	INT m_bLoopback;
	INT m_nState;
	ZArray<UCHAR> m_aRecvBuff;
	USHORT m_uLength;
	USHORT m_uRawSeq;
	USHORT m_uDataLen;
	UINT m_uOffset;


};