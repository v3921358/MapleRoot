#pragma once
#include "Type/CharacterData.h"
#include "Type/SecondaryStat.h"
#include "Type/SE_TYPE.h"

class Static {
public:
	static int get_weapon_type()
	{
		//unsigned int pointer
		//varia
		int localplayer = *reinterpret_cast<uintptr_t*>(0x00BEBF98);

		if (localplayer == 0)
		{
			return 0;
		}

		int weapon = *reinterpret_cast<uintptr_t*>(localplayer + 0x4EC);

		return (weapon / 10000) % 100;
	}

	static int get_weapon_mastery(CharacterData* cd, SecondaryStat* ss, int nWeaponItemID, int nAttackType, int nSkillID, int* pnACCInc, int* pnPADInc) {
		return reinterpret_cast<int(__cdecl*)
			(CharacterData*, SecondaryStat*, int, int, int, int*, int*)>(0x00709950)
			(cd, ss, nWeaponItemID, nAttackType, nSkillID, pnACCInc, pnPADInc);
	}

	static int get_critical_skill_level(CharacterData* cd, int nWeaponItemID, int nAttackType, int* pnProp, int* pnParam) {
		return reinterpret_cast<int(__cdecl*)
			(CharacterData*, int, int, int*, int*)>(0x0070A240)
			(cd, nWeaponItemID, nAttackType, pnProp, pnParam);
	}

	static long double get_rand(unsigned int nRand, long double f0, long double f1)
	{
		if (f0 > f1)
		{
			return f0 + (nRand % 10000000) * (f1 - f0) / 9999999.0;
		}
		if (f1 != f0)
			return f0 + (nRand % 10000000) * (f1 - f0) / 9999999.0;
		return f0;
	}

	static BOOL is_pronestab_action(int nAction)
	{
		return nAction == 41 || nAction == 57;
	}

	static unsigned int play_skill_sound(int nSkillId, SE_TYPE seType, int nSLV)
	{
		return reinterpret_cast<unsigned int(__cdecl*)
			(int, SE_TYPE, int)>(0x00966B60)
			(nSkillId, seType, nSLV);
	}
private:
};