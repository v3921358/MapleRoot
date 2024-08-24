#pragma once
#include "Assert.h"

class ZRefCountedVtbl
{
public:
	void* (__thiscall* __vecDelDtor)(ZRefCounted*, unsigned int);
private:
};

class ZRefCounted : ZRefCountedVtbl
{
public:
	int _m_nRef;
	ZRefCounted* _m_pNext;
private:
};

static_assert_size(sizeof(ZRefCountedVtbl), 0x4);
static_assert_size(sizeof(ZRefCounted), 0xC);