#include "../../../Funcs.h"
#include "../../../Global.h"
#include <intrin.h>

#pragma intrinsic(_ReturnAddress)

int Sus;
int SLevel;
int OLevel;
int TLevel;
int Spear;
int OSword;
int TSword;
int Crit;
int Defenses;

auto pGetSkillLevel = (int(__thiscall*)(int, const struct CharacterData*, signed int, int**))0x007616F6;
int(__fastcall GetSkillLevel)(int _this, void* blah, CharacterData* charData, signed int skillID, int** skillEntry)
{
	auto i = pGetSkillLevel(_this, charData, skillID, skillEntry);
	Defenses = pGetSkillLevel(_this, charData, 61, skillEntry);
	Crit = pGetSkillLevel(_this, charData, 62, skillEntry);
	TSword = pGetSkillLevel(_this, charData, 40, skillEntry);
	OSword = pGetSkillLevel(_this, charData, 41, skillEntry);
	Spear = pGetSkillLevel(_this, charData, 42, skillEntry);
	Sus = pGetSkillLevel(_this, charData, 60, skillEntry);
	TLevel = pGetSkillLevel(_this, charData, 1050, skillEntry);
	OLevel = pGetSkillLevel(_this, charData, 1051, skillEntry);
	SLevel = pGetSkillLevel(_this, charData, 1052, skillEntry);
	//Log("%d", i);
	return pGetSkillLevel(_this, charData, skillID, skillEntry);
}
