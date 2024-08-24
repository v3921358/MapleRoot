//#include "CalcDamage.h"
//#include "../../../Funcs.h"
//#include "../Static.h"
//#include "../Classes/CSkillInfo.h"
//#include "../Type/WeaponType.h"
//
//#define ACT_ASSASSINATIONS 0x4F
//
//template<typename T>
//T __cdecl zmax(T a, T b)
//{
//	return b >= a ? b : a;
//}
//
//template<typename T>
//T __cdecl zmin(T a, T b)
//{
//	return a < b ? a : b;
//}
//
//static int __cdecl calculate_accuracy(int playerAccuracy, int mobEvasion, int playerLevel, int mobLevel)
//{
//	int result = 100;
//	if (mobLevel > playerLevel)
//		result -= (5 * playerLevel - mobLevel);
//	return zmin<int>(zmax<int>(result + sqrt(playerAccuracy) - sqrt(mobEvasion), 1), 100);
//}
//
//static int __cdecl calc_base_damage(int p1, int p2, int p3, int ad, long double k)
//{
//	return ((p3 + p2 + 4 * p1) / 100.0 * (ad * k) + 0.5);
//}
//
//static int __cdecl calc_max_damage(int mulitplier, int primaryStat, int secondaryStat, int attack)
//{
//	return mulitplier * ((4 * primaryStat) + secondaryStat) * (attack / 100);
//}
//
//static int __cdecl calc_max_skill_dmg(int mainStat, int secondaryStat, double weaponModifier, int weaponAttack)
//{
//	return ((mainStat * weaponModifier + secondaryStat) / 100) * weaponAttack;
//}
//
//static int __cdecl calc_min_skill_dmg(int mainStat, int secondaryStat, double weaponModifier, int weaponAttack, double skillMastery)
//{
//	return ((mainStat * 0.4 * weaponModifier * skillMastery + secondaryStat) / 100) * weaponAttack;
//}
//
//static int __cdecl adjust_random_damage(long double damage, int nRand, long double k, int nMastery)
//{
//	int mastery = nMastery / 100.0 + k;
//	if (mastery >= 0.95)
//		mastery = 0.95;
//	return Static::get_rand(nRand, damage, (mastery * damage + 0.5));
//}
//
//double __cdecl get_weapon_multipler(int nWT)
//{
//	switch (static_cast<WeaponType>(nWT))
//	{
//	case OH_SWORD:
//	case OH_AXE:
//	case OH_BLUNT:
//		return 1.2;
//	case TH_SWORD:
//	case TH_AXE:
//	case TH_BLUNT:
//		return 1.32;
//	case SPEAR:
//	case POLEARM:
//		return 1.49;
//	case DAGGER:
//	case SUBDAGGER:
//		return 1.30;
//	case BAREHAND:
//		return 1.43;
//	default:
//		return 0.0;
//	}
//}
//
//double __cdecl get_weapon_modifier(int nWT)
//{
//	switch (static_cast<WeaponType>(nWT))
//	{
//	default:
//	case OH_SWORD:
//	case DAGGER:
//	case SUBDAGGER:
//		return 4.0;
//	case OH_AXE:
//	case OH_BLUNT:
//		return 4.4;
//	case TH_SWORD:
//		return 4.6;
//	case TH_AXE:
//	case TH_BLUNT:
//		return 4.8;
//	case SPEAR:
//	case POLEARM:
//		return 5.0;
//	}
//}
//
//double __cdecl GetMasteryConstByWT(int nWT)
//{
//	switch (static_cast<WeaponType>(nWT))
//	{
//	case OH_SWORD:
//	case OH_AXE:
//	case OH_BLUNT:
//	case TH_SWORD:
//	case TH_AXE:
//	case TH_BLUNT:
//	case SPEAR:
//	case POLEARM:
//	case DAGGER:
//	case SUBDAGGER:
//	default:
//		return 0.2;
//	}
//}
//
//typedef double(__cdecl* CalcDamage__CalcDamageByWT_t)(int nWT, BasicStat* bs, int nPAD, int nMAD);
//static auto CalcDamage__CalcDamageByWT = reinterpret_cast<CalcDamage__CalcDamageByWT_t>(0x00724DB0);
//
//double __cdecl CalcDamageByWT(int nWT, BasicStat* bs, int nPAD, int nMAD)
//{
//	int primaryStat = 0, secondaryStat = 0, thirdStat = 0;
//	double multiplier = get_weapon_multipler(nWT);
//
//	switch (static_cast<WeaponType>(nWT))
//	{
//	case OH_SWORD:
//	case OH_AXE:
//	case OH_BLUNT:
//	case TH_SWORD:
//	case TH_AXE:
//	case TH_BLUNT:
//	case SPEAR:
//	case POLEARM:
//		primaryStat = bs->GetSTR();
//		secondaryStat = bs->GetDEX();
//		return calc_base_damage(primaryStat, secondaryStat, thirdStat, nPAD, multiplier);
//	case BAREHAND:
//		primaryStat = bs->GetSTR();
//		secondaryStat = bs->GetDEX();
//		return calc_base_damage(primaryStat, secondaryStat, thirdStat, 1, multiplier);
//	case DAGGER:
//	case SUBDAGGER:
//		primaryStat = bs->GetSTR();
//		secondaryStat = bs->GetDEX();
//		thirdStat = bs->GetSTR() / 2;
//		return calc_base_damage(primaryStat, secondaryStat, thirdStat, nPAD, multiplier);
//	default:
//		return 1.0;
//	}
//}
//
//typedef void(__fastcall* CalcDamage__PDamage_t)(CalcDamage* pThis, void* ecx, CharacterData* cd, BasicStat* bs, SecondaryStat* ss, const unsigned int dwMobID, MobStat* ms, CMobTemplate* pTemplate, ZRef<PassiveSkillData> pPsd, int* bNextAttackCritical, int nAttackCount, int nDamagePerMob, int nWeaponItemID, int nBulletItemID, int nAttackType, int nAction, int bShadowPartner, SKILLENTRY* pSkill, int nSLV, int* aDamage, int* abCritical, int nCriticalProb, int nCriticalDamage, int nTotalDAMr, int nBossDAMr, int nIgnoreTargetDEF, int nDragonFury, int nAR01Pad, int tKeyDown, int nDarkForce, int nAdvancedChargeDamage, int bInvincible);
//static auto CalcDamage__PDamage = reinterpret_cast<CalcDamage__PDamage_t>(0x00730130);
//
//void __fastcall PDamage(CalcDamage* pThis, void* ecx, CharacterData* cd, BasicStat* bs, SecondaryStat* ss, const unsigned int dwMobID, MobStat* ms, CMobTemplate* pTemplate, ZRef<PassiveSkillData> pPsd, int* bNextAttackCritical, int nAttackCount, int nDamagePerMob, int nWeaponItemID, int nBulletItemID, int nAttackType, int nAction, int bShadowPartner, SKILLENTRY* pSkill, int nSLV, int* aDamage, int* abCritical, int nCriticalProb, int nCriticalDamage, int nTotalDAMr, int nBossDAMr, int nIgnoreTargetDEF, int nDragonFury, int nAR01Pad, int tKeyDown, int nDarkForce, int nAdvancedChargeDamage, int bInvincible)
//{
//	CRand32* rndForChar = &pThis->getRandForCharacter();
//	unsigned int aRandom[7];
//
//	for (int j = 0; j < 7; ++j)
//		aRandom[j] = CRand32::Random(rndForChar);
//
//	SKILLLEVELDATA* skillLevelData = nullptr;
//	if (pSkill)
//		skillLevelData = SKILLENTRY::GetLevelData(pSkill, nSLV);
//
//	for (int i = 0; i < nDamagePerMob; i++)
//	{
//		if (ms->bInvincible)
//			continue;
//
//		if (CalcDamage::CalcPImmune(ms, ss, aRandom[i % 7] % 100))
//		{
//			aDamage[i] = 1;
//			continue;
//		}
//
//		int weaponType = Static::get_weapon_type(nWeaponItemID);
//		double weaponModifier = get_weapon_modifier(weaponType);
//		int weaponAttack = ss->nItemPAD.Fuse();
//
//		float mobDefenseSubtractor = (float)1.0 - (float)((float)((float)ms->nPDR + (float)ms->nPDR_) / (float)10000.0);
//
//		int minDmg = calc_min_skill_dmg(bs->GetSTR(), bs->GetDEX(), weaponModifier, weaponAttack, 0.6);
//		int maxDmg = calc_max_skill_dmg(bs->GetSTR(), bs->GetDEX(), weaponModifier, weaponAttack);
//		int dmg = Static::get_rand(aRandom[i % 7], minDmg, maxDmg) * mobDefenseSubtractor;
//
//		int accuracy = ss->GetACC(bs);
//		int calcdAcc = calculate_accuracy(accuracy, ms->nEVA + ms->nEVA_, bs->GetLevel(), ms->nLevel);
//
//		if (calcdAcc < Static::get_rand(aRandom[i % 7], 0.0, 100.0))
//			continue;
//
//		if (pSkill)
//			dmg = dmg * skillLevelData->GetDamage() / 100;
//
//		int critChance = 5;
//		int rand = Static::get_rand(aRandom[i % 7], 0.0, 100.0);
//
//		if (rand <= critChance)
//		{
//			abCritical[i] = 1;
//			dmg = dmg * 2;
//		}
//
//		aDamage[i] = dmg;
//	}
//}
//
//void CalcDamage::StartHooks()
//{
//	SetHook(true, reinterpret_cast<void**>(&CalcDamage__PDamage), PDamage);
//	SetHook(true, reinterpret_cast<void**>(&CalcDamage__CalcDamageByWT), CalcDamageByWT);
//}