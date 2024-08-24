//typedef int(__fastcall* CUserLocal__DoActiveSkill_t)(CUserLocal* pThis, void* edx, int nSkillID, unsigned int nScanCode, int* pnConsumeCheck);
//static auto CUserLocal__DoActiveSkill_hook = reinterpret_cast<CUserLocal__DoActiveSkill_t>(0x00966F7A);
//
//int DoBuffSkill(CUserLocal* pThis, int nSkillID)
//{
//	Log("It's a buff!! pog");
//	return 0;
//}
//
//int DoMeleeSkill(CUserLocal* pThis, int nSkillID)
//{
//	Log("It's a melee attack!! pog");
//	auto cd = CWvsContext::GetInstance()->GetCharacterData();
//	SKILLENTRY* pSkill = nullptr;
//	auto nSLV = CSkillInfo::GetInstance()->GetSkillLevel(cd.p, nSkillID, &pSkill);
//
//	int ret = 0;
//
//	if (pSkill)
//	{
//		//if (!pSkill->IsCorrectWeaponType(nWT, nSubWT))
//		//	return 0;
//
//		ret = CUserLocal::GetInstance()->DoActiveSkill_MeleeAttack(pSkill, nSLV);
//
//		pThis->m_uSkillSoundCookie = Static::play_skill_sound(nSkillID, SE_TYPE::SE_SKILL_USE, nSLV);
//		pThis->m_bConsumePetMP = 1;
//	}
//
//	return ret;
//}
//
//int DoRangedSkill(CUserLocal* pThis, int nSkillID)
//{
//	Log("It's a ranged skill!! pog");
//	return 0;
//}
////
//int DoMovementSkill(CUserLocal* pThis, int nSkillID)
//{
//	Log("It's a movement skill!! WTF THIS IS NEW WHOA");
//
//	if (pThis->m_bFly || pThis->IsImmovable())
//		return 0;
//
//	int ret = 0;
//
//	if (nSkillID == 4214000)
//	{
//		auto cd = CWvsContext::GetInstance()->GetCharacterData();
//		SKILLENTRY* pSkill = nullptr;
//		auto nSLV = CSkillInfo::GetInstance()->GetSkillLevel(cd.p, nSkillID, &pSkill);
//
//		if (pSkill)
//		{
//			auto someCalc = nSLV / 4;
//			int coolTime = 0;
//			if ((pThis->m_nMoveAction & 1) != 0)
//				coolTime = -350 - 40 * someCalc;
//			else
//				coolTime = 40 * someCalc + 350;
//
//			int vy = (-250 - 20 * someCalc);
//			int vx = coolTime; // ??
//
//			//CVecCtrl::SetImpactNext()
//
//		}
//	}
//
//	return ret;
//}
//
//int __fastcall DoActiveSkill(CUserLocal* pThis, void* edx, int nSkillID, unsigned int nScanCode, int* pnConsumeCheck)
//{
//	Log("Trying to use skill id: %d", nSkillID);
//
//	int skillType = nSkillID % 10000;
//
//	if (nSkillID >= 1001000 && nSkillID <= 1110100)
//		return DoMeleeSkill(pThis, nSkillID);
//
//	if (nSkillID == 1101000) {
//		return DoActiveSkill(pThis, nSkillID);
//	}
//
//	//if (skillType >= 3000 && skillType < 4000)
//	//	return DoSkill(pThis, nSkillID);
//
//	//if (skillType >= 4000 && skillType < 5000)
//	//	return DoMovementSkill(pThis, nSkillID);
//
//	Log("Skill not found and not processed :(");
//	return 0;
//}
//
//void CUserLocal::StartHooks()
//{
//	// Assaulter
//	//WriteValue(0x0091EDCB + 6, 0x401E13);
//	//WriteValue(0x0091F0C0 + 6, 0x401E13);
//	//WriteValue(0x00920574 + 6, 0x401E13);
//	//WriteValue(0x00923CFC + 6, 0x401E13);
//	//WriteValue(0x00923F46 + 6, 0x401E13);
//	//WriteValue(0x00923FEA + 6, 0x401E13);
//	//PatchNop(0x00920574, 12); // Use without mobs :F3:
//	SetHook(true, reinterpret_cast<void**>(&CUserLocal__DoActiveSkill_hook), DoActiveSkill);
//}