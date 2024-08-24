#pragma once
#include "Assert.h"
#include "ZArray.h"
#include "ZXString.h"

class ALLIANCEDATA
{
public:
	int nAllianceID;
	ZXString<char> sAllianceName;
	ZArray<ZXString<char> > asGradeName;
	ZArray<unsigned long> adwGuildID;
	int nMaxMemberNum;
	ZXString<char> sNotice;
private:
};

static_assert_size(sizeof(ALLIANCEDATA), 0x18);