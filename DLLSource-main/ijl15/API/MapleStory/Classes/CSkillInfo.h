#pragma once
#include "../Type/TSingleton.h"
#include "../Type/Assert.h"
#include "../Type/CharacterData.h"
#include "../Type/SKILLENTRY.h"

class CSkillInfo : public TSingleton<CSkillInfo, 0x00C63EA8>
{
	~CSkillInfo() = delete;
public:
	int GetSkillLevel(CharacterData* cd, int nSkillID, SKILLENTRY** ppSkillEntry);
	SKILLENTRY* GetSkill(int nSkillID);
private:
};

static_assert_size(sizeof(CSkillInfo), 0x1);