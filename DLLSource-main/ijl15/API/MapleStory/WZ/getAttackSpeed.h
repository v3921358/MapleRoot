#include "../../../Global.h"
#pragma once


int get_weapon_type()
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

auto pGetAttackSpeedDegree = (void(__thiscall*)(char, signed int, int))0x00765066;
int(__cdecl GetAttackSpeedDegree)(int nDegree, const int nSkillID, const int nWeaponBooster, const int nPartyBooster)
{
	//Log("%7d, %7d, %7d, %7d", nDegree, nSkillID, nWeaponBooster, nPartyBooster);


	int nWeaponDegree;

	switch (get_weapon_type())
	{
	case 30: nWeaponDegree = 4; /*Log("hit 30");*/ break;
	case 40: nWeaponDegree = 6; /*Log("hit 40");*/ break;
	case 43: nWeaponDegree = 6; /*Log("hit 43");*/ break;
	default: nWeaponDegree = 2; break;
	}
	if (nPartyBooster == -1)
	{
		return 2;
		//Log("4");
	}
	else if (nWeaponBooster != 0 && nPartyBooster == -2)
	{
		return 8;
		//Log("8");
	}
	else if (nWeaponBooster != 0 && nPartyBooster == 0)
	{
		return 10;
		//Log("10");
	}
	else if (nWeaponBooster == 0 && nPartyBooster == -2)
	{
		return (nWeaponDegree - 2);
		//Log("2");
	}
	else
	{
		return nWeaponDegree;
	}
}