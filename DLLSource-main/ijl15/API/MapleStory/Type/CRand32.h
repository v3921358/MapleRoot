#pragma once
#include "Assert.h"

class CRand32 {
public:
	static int Random(CRand32* rnd) {
		return reinterpret_cast<int(__fastcall*)(CRand32*, void*)>(0x00409A90)(rnd, nullptr);
	}
private:
	unsigned int m_s1;
	unsigned int m_s2;
	unsigned int m_s3;
	unsigned int m_past_s1;
	unsigned int m_past_s2;
	unsigned int m_past_s3;
	//ZFatalSection m_lock;
};

static_assert_size(sizeof(CRand32), 0x18);