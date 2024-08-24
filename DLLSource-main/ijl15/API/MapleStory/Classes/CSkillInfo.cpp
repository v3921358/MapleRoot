#include "CSkillInfo.h"

int CSkillInfo::GetSkillLevel(CharacterData* cd, int nSkillID, SKILLENTRY** ppSkillEntry)
{
	return reinterpret_cast<int(__thiscall*)
		(CSkillInfo*, CharacterData*, int, SKILLENTRY**)>(0x006F1D10)
		(this, cd, nSkillID, ppSkillEntry);
}

SKILLENTRY* CSkillInfo::GetSkill(int nSkillID)
{
	return reinterpret_cast<SKILLENTRY*(__thiscall*)
		(CSkillInfo*, int)>(0x006F1BB0)
		(this, nSkillID);
}
