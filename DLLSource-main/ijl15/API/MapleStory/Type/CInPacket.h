#pragma once
#include "Assert.h"
#include "ZArray.h"
#include "ZXString.h"

class CInPacket {
public:
    CInPacket(int bLoopback);
    CInPacket* CopyFrom(CInPacket* iPacket);
    ~CInPacket();

    short GetType();
    int GetBytesLeft();

    char Decode1();
    short Decode2();
    int Decode4();
    ZXString<char>* DecodeStr();
    void DecodeBuffer(void* p, int size);

    void Dump();

    int m_bLoopback;						// 0x00
    int m_nState;							// 0x04

    ZArray<unsigned char> m_aRecvBuff;      // 0x08

    __int16 m_uLength;                      // 0x0C
    __int16 m_uRawSeq;					    // 0x0E
    __int16 m_uDataLen;				        // 0x10

    padding(0x2);                           // 0x12 - it be like that

    int m_uOffset;					        // 0x14?
};