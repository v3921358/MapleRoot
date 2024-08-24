#pragma once
#include "../../Type/Assert.h"

class IGObjVtbl
{
public:
	void(__thiscall* Update)(IGObj*);
private:
};

class IGObj
{
public:
	IGObjVtbl* vfptr;
private:
};

static_assert_size(sizeof(IGObjVtbl), 0x4);
static_assert_size(sizeof(IGObj), 0x4);