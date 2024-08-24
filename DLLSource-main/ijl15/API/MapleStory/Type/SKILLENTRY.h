#pragma once
#include "Assert.h"
#include "SKILLLEVELDATA.h"
#include "ZXString.h"
#include "ZArray.h"

class SKILLENTRY
{
public:
	static unsigned int GetMaxLevel(SKILLENTRY* pThis) {
		return reinterpret_cast<unsigned int(__fastcall*)
			(SKILLENTRY*, void*)>(0x0050A020)
			(pThis, nullptr);
	}

	static SKILLLEVELDATA* GetLevelData(SKILLENTRY* pThis, int nLevel) {
		return reinterpret_cast<SKILLLEVELDATA * (__fastcall*)
			(SKILLENTRY*, void*, int)>(0x00708E10)
			(pThis, nullptr, nLevel);
	}

	bool IsCorrectWeaponType(int nWT, int nSubWT);

	int nSkillID;
	ZXString<char> sName;
	ZXString<char> sDescription;
	int nSkillType;
	int nPsdSkill;
	int nAttackElemAttr;
	int nWeapon;
	int nSubWeapon;
	ZArray<long> aAction;
	int nSpecialAction;
	int nPrepareAction;
	int tPrepare;
	int tBallDelay;
	int bInvisible;
	int bUpButtonDisabled;
	int nDefaultMasterLev;
	int bCombatOrders;
	unsigned int dwCRC;
	int bTimeLimited;
	unsigned int dwMobCode;
	int nDelayFrame;
	int nHoldFrame;
	ZArray<ZArray<long>> aFinalAttack;
};

static_assert_size(sizeof(SKILLENTRY), 0x5C);