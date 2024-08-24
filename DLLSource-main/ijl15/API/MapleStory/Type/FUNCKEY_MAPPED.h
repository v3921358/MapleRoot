#pragma once
#include "../Type/Assert.h"

class FUNCKEY_MAPPED
{
public:
	char nType;
	int nID;
private:
};

static_assert_size(sizeof(FUNCKEY_MAPPED), 0x8);