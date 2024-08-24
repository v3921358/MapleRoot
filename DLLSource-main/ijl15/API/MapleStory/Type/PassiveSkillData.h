#pragma once
#include "Assert.h"
#include "ZMap.h"
#include "AdditionPsd.h"

class PassiveSkillData
{
public:
	int nMHPr;
	int nMMPr;
	int nCr;
	int nCDMin;
	int nACCr;
	int nEVAr;
	int nAr;
	int nEr;
	int nPDDr;
	int nMDDr;
	int nPDr;
	int nMDr;
	int nDIPr;
	int nPDamr;
	int nMDamr;
	int nPADr;
	int nMADr;
	int nEXPr;
	int nIMPr;
	int nASRr;
	int nTERr;
	int nMESOr;
	int nPADx;
	int nMADx;
	int nIMDr;
	int nPsdJump;
	int nPsdSpeed;
	int nOCr;
	int nDCr;
	ZMap<long, ZRef<AdditionPsd>, long> mAdditionPsd;
};

static_assert_size(sizeof(PassiveSkillData), 0x8C);