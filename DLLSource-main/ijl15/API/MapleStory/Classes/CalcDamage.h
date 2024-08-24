#pragma once
#include "../Type/Assert.h"
#include "../Type/CRand32.h"
#include "../Type/CharacterData.h"
#include "../Type/BasicStat.h"
#include "../Type/SecondaryStat.h"
#include "../Type/MobStat.h"
#include "../Type/CMobTemplate.h"
#include "../Type/ZRef.h"
#include "../Type/PassiveSkillData.h"
#include "../Type/SKILLENTRY.h"

class CalcDamage
{
public:
	static void StartHooks();

	CRand32& getRandForCharacter() 
	{
		return this->m_RndGenForCharacter;
	}

	static BOOL CalcPImmune(MobStat* ms, SecondaryStat* ss, int nRand)
	{
		return reinterpret_cast<BOOL(__stdcall*)
			(MobStat*, SecondaryStat*, int)>(0x00723020)
			(ms, ss, nRand);
	}
private:
	CRand32 m_RndGenForCharacter;
	CRand32 m_RndForCheckDamageMiss;
	CRand32 m_RndForMortalBlow;
	CRand32 m_RndForSummoned;
	CRand32 m_RndForMob;
	CRand32 m_RndGenForMob;
};

static_assert_size(sizeof(CalcDamage), 0x90);