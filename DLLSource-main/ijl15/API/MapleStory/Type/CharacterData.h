#pragma once
#include "Assert.h"
#include "GW_CharacterStat.h"
#include "Additional.h"

class CharacterData
{
public:
	GW_CharacterStat characterStat;
	padding(0x695);
	Additional::CRITICAL critical;
};

static_assert_size(sizeof(CharacterData), 0x778);