#pragma once
#include "intrin.h"
#include "../Global.h"


int int_ = 0;
int magic = 0;
int dex = 0;
int str = 0;
int luk = 0;
int pad = 0;
int pleasejmpout = 0x00791C6C;
double int_multiplier = 3.4;
double div100 = 0.01;
int damageout = 0;
int mastery = 0;

template<typename T>
T __cdecl zmax(T a, T b)
{
	return b >= a ? b : a;
}

template<typename T>
T __cdecl zmin(T a, T b)
{
	return a < b ? a : b;
}

int getRandomNumber(int x, int y) {
	return rand() % (y - x + 1) + x;
}

int magicFormula() {

}

auto ztlSecureFuse_check = (unsigned int(__cdecl*)(int, int))0x00416563;
unsigned int __cdecl ztlfuse(int a1, int a2) {
	if ((int)_ReturnAddress() == 0x00791BC9)
	{
		int_ = ztlSecureFuse_check(a1, a2);
	}
	if ((int)_ReturnAddress() == 0x00791650)
	{
		magic = ztlSecureFuse_check(a1, a2);
	}

	return ztlSecureFuse_check(a1, a2);
}


static int __cdecl calc_max_skill_dmg(int mainStat, int secondaryStat, double weaponModifier, int weaponAttack)
{
	return ((mainStat * weaponModifier) / 100) * weaponAttack;
}

int get_weapon_type()
{
	int localplayer = *reinterpret_cast<uintptr_t*>(0x00BEBF98);

	if (localplayer == 0)
	{
		return 0;
	}

	int weapon = *reinterpret_cast<uintptr_t*>(localplayer + 0x4EC);

	return (weapon / 10000) % 100;
}

auto getPAD_hook = (int(__thiscall*)(void*, int, int))0x0077DF48;
int(__cdecl getPAD)(void* ss, void* edx, int getIncPAD, int bulletItem)
{
	pad = getPAD_hook(ss, getIncPAD, bulletItem);
	return getPAD_hook(ss, getIncPAD, bulletItem);
}

int PDamage()
{
	int weaponType = get_weapon_type();
	int primarystat;
	int secondarystat;
	double masterycalc = 0.1;
	if (mastery > 0)
	{
		double masterycalc = mastery / 20 + .10;
	}
	switch (weaponType) {
	case 30:
	case 31:
	case 32:
	case 39:
	case 40:
	case 41:
	case 42:
	case 43:
	case 44:
	case 48:
		primarystat = str;
		break;
	case 33:
	case 47:
		primarystat = luk;
		break;
	case 45:
	case 46:
	case 49:
		primarystat = dex;
	}
	int maxDmg = calc_max_skill_dmg(primarystat, secondarystat, 4.0, pad);
	int minDmg = maxDmg * masterycalc;
	int dmg = getRandomNumber(minDmg, maxDmg);
	if (dmg <= 0)
	{
		dmg = 1;
	}
	return dmg;
}

auto mastery_hook = (void(__cdecl*)(int, int, int, void*, unsigned int* a5, unsigned int* a6))0x00765066;
unsigned int __cdecl masterystuff(int a1, int a2, int a3, void* a4, unsigned int* a5, unsigned int* a6) {

}



auto pGetAttackSpeedDegree = (void(__thiscall*)(int, int, int, int))0x00765066;
int(__cdecl GetAttackSpeedDegree)(int nDegree, int nSkillID, int nWeaponBooster, int nPartyBooster)
{

	int nWeaponDegree = 6;
	nWeaponDegree += nWeaponBooster;
	nWeaponDegree += nPartyBooster;
	if (nWeaponDegree < 0)
	{
		nWeaponDegree = 0;
	}
	return nWeaponDegree;
}


