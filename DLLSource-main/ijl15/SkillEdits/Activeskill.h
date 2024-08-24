#include "../Global.h"
#include <random>

using namespace std;
using chrono::duration_cast;
using chrono::milliseconds;
using chrono::system_clock;
chrono::time_point<chrono::steady_clock> jumptimer;
// These are going to be all our Addresses that we jump to depending on what we want our skill to do.
int combatStep = 0x00969026; // requires further handling
int meleeAttack = 0x009690AE; // depending on what you want requires further handling should just handle lt/rb skills;
int summonAttack = 0x009689DF; //
int prepareAttack = 0x00969229; //requires further handling
int magicAttack = 0x0096928B; //probably requires further handling? MAO doesn't use magic
int statChange = 0x00969284; // you can use this for any buff and it will pass the skill being used to the server.
int dorecovery = 0x00969217;
int doBoundJump = 0x0096897A; // requires further handling
int shootAttack = 0x009690E9; // should work for basic rt/lb shooting skills.
bool jumped = false;
int normalCombo = 0;
int cygnusCombo = 0;
int normalACA = 0;
int cygnusACA = 0;
int bowman = 0;
int thief = 0;
int pirate = 0;
int nw = 0;
int wa = 0;
int tb = 0;
int skillid = 0;
int mastery = 0;

//NOT A SKILL
int doActiveJmpBack = 0x0096793B;// return to our existing code.

void _declspec(naked)doActiveSkills() {
	_asm {
		mov eax, 1050
		cmp esi, eax
		je[jumpmove]
		mov eax, 10001050
		cmp esi, eax
		je[jumpmove]
		mov eax, 20001050
		cmp esi, eax
		je[jumpmove]
		mov eax, 1121012
		cmp esi, eax
		je[melee]
		mov eax, 5121011
		cmp esi, eax
		je[melee]
		mov eax, 5121012
		cmp esi, eax
		je[melee]
		mov eax, 5111013
		cmp esi, eax
		je[melee]
		mov eax, 5121013
		cmp esi, eax
		je[melee]
		mov eax, 1321011
		cmp esi, eax
		je[melee]
		mov eax, 3221009
		cmp esi, eax
		je[shoot]
		mov eax, 4221009
		cmp esi, eax
		je[melee]
		mov eax, 7001002
		cmp esi, eax
		je[melee]
		mov eax, 7001003
		cmp esi, eax
		je[melee]
		mov eax, 7001001
		cmp esi, eax
		je[melee]
		mov eax, 7001000
		cmp esi, eax
		je[melee]
		mov eax, 7001004
		cmp esi, eax
		je[melee]
		mov eax, 7001006
		cmp esi, eax
		je[buff]
		mov eax, 1051
		cmp esi, eax
		je[melee]
		mov eax, 1052
		cmp esi, eax
		je[melee]
		mov eax, 2111004
		cmp esi, eax
		je[buff]
		mov eax, 2211004
		cmp esi, eax
		je[buff]
		mov eax, 2311005
		cmp esi, eax
		je[buff]
		mov eax, 11121004
		cmp esi, eax
		je[melee]
		mov eax, 11121014
		cmp esi, eax
		je[melee]
		mov eax, 11121101
		cmp esi, eax
		je[melee]
		mov eax, 11121102
		cmp esi, eax
		je[melee]
		mov eax, 11121203
		cmp esi, eax
		je[melee]
		mov eax, 12111002
		cmp esi, eax
		je[buff]
		mov eax, 12121012
		cmp esi, eax
		je[magic]
		mov eax, 12121002
		cmp esi, eax
		je[magic]
		mov eax, 12121054
		cmp esi, eax
		je[magic]
		mov eax, 12121055
		cmp esi, eax
		je[magic]
		mov eax, 13121001
		cmp esi, eax
		je[shoot]
		mov eax, 13121002
		cmp esi, eax
		je[shoot]
		mov eax, 13121052
		cmp esi, eax
		je[melee]
		mov eax, 13121008
		cmp esi, eax
		je[buff]
		mov eax, 13121054
		cmp esi, eax
		je[melee]
		mov eax, 14111002
		cmp esi, eax
		je[melee]
		mov eax, 14121007
		cmp esi, eax
		je[melee]
		mov eax, 14121006
		cmp esi,eax
		je[melee]
		mov eax, 4121010
		cmp esi, eax
		je[melee]
		mov eax, 14121001
		cmp esi, eax
		je[shoot]
		mov eax, 14121003
		cmp esi, eax
		je[melee]
		mov eax, 15121003
		cmp esi, eax
		je[melee]
		mov eax, 15121001
		cmp esi, eax
		je[melee]
		mov eax, 15121002
		cmp esi, eax
		je[melee]
		mov eax, 15121052
		cmp esi, eax
		je[melee]
		mov eax, 2121006
		cmp esi, eax
		je[magic]
		mov eax, 2221009
		cmp esi, eax
		je[magic]
		mov eax, 2121054
		cmp esi, eax
		je[magic]
		mov eax, 2121052
		cmp esi, eax
		je[magic]
		mov eax, 3221010
		cmp esi, eax
		je[melee]
		mov eax, 3121013
		cmp esi, eax
		je[summons]
		mov eax, 4221010
		cmp esi, eax
		je[melee]
		mov eax, 1221017
		cmp esi, eax
		je[melee]
		mov eax, 1321016
		cmp esi, eax
		je[melee]
		mov eax, 1321012
		cmp esi, eax
		je[melee]
		mov eax, 1221014
		cmp esi, eax
		je[melee]
		mov eax, 1321013
		cmp esi, eax
		je[melee]
		mov eax, 5221014
		cmp esi, eax
		je[buff]
		mov eax, 5221018
		cmp esi, eax
		je[buff]
		mov eax, 5221017
		cmp esi, eax
		je[shoot]
		mov eax, 5221016
		cmp esi, eax
		je[shoot]
		mov eax, 2221011
		cmp esi, eax
		je[magic]
		mov eax, 3121015
		cmp esi, eax
		je[shoot]
		mov eax, 1221014
		cmp esi, eax
		je[melee]


		mov eax, 2301005 // need this to go back to our original skills from where we codecave
		jmp[doActiveJmpBack]

		melee: jmp[meleeAttack] //
		summons : jmp[summonAttack]
		prepare : jmp[prepareAttack]
		magic : jmp[magicAttack]
		buff : jmp[statChange]
		combat : jmp[combatStep]
		recover : jmp[dorecovery]
		shoot : jmp[shootAttack]
		jumpmove : jmp[doBoundJump]

	}
}
//FLASH BOUNCE STUFF
const DWORD FlashJumpVar = 0x0096BF52;
const DWORD FlashJumpRet = 0x0096BF12;
void __declspec(naked)FlashJumpAll() {
	_asm {

		cmp     eax, 0xD72A0C
		je[fjvar]
		cmp     eax, 1050
		je[fjvar]
		cmp     eax, 10001050
		je[fjvar]
		cmp     eax, 20001050
		je[fjvar]

		jmp FlashJumpRet

		fjvar : jmp[FlashJumpVar]


	}
}

bool isSkillIDMatched(int nSkillID)
{
	const int skillIDs[] = {
		1050, 10001050, 20001050, 1121012, 5121011, 5121012, 5111013, 5121013, 1321011,
		3221010, 3221009, 4221009, 7001002, 7001003, 7001001, 7001000, 7001004, 7001006,
		1051, 1052, 11121004, 11121014, 11121101, 11121102, 11121203, 1221017, 12121012,
		12121002, 12121054, 12121055, 13121001, 13121002, 13121052, 13121008, 13121054,
		3121013, 14111002, 14121007, 14121006, 14121001, 14121003, 4221010, 15121003,
		2221009, 15121001, 15121002, 15121052, 2111004, 2211004, 2311005, 12111002,
		2121052, 2121054, 2121006, 5221017, 5221018, 5221014, 1321016, 2221011, 5221016,
		1321012, 1321013, 3121015, 4121010, 1221014
	};

	return std::find(std::begin(skillIDs), std::end(skillIDs), nSkillID) != std::end(skillIDs);
}

auto pDoActiveSkill = (int(__thiscall*)(int, int, int, int))0x00966F7A;
int(__fastcall CUserLocal__DoActiveSkill_t)(int _This, void* edx, int nSkillID, unsigned int nScanCode, int pnConsumeCheck)
{
	if (isSkillIDMatched(nSkillID))
	{
		CodeCave((void*)doActiveSkills, 0x0096792A, 0);
	}
	else
	{
		WriteByte(0x0096792A, 0x0F);
		WriteByte(0x0096792A + 1, 0x8F);
		WriteByte(0x0096792A + 2, 0x71);
		WriteByte(0x0096792A + 3, 0x09);
		WriteByte(0x0096792A + 4, 0x00);
	}
	return pDoActiveSkill(_This, nSkillID, nScanCode, pnConsumeCheck);
}


auto pGetSkillLevel = (int(__thiscall*)(int, void*, int, int))0x007616F6;
int(__fastcall GetSkillLevel)(int _this, void* blah, void* charData, int skillID, int skillEntry)
{
	int i = skillID;
	if (i) {
		pGetSkillLevel(_this, charData, i, skillEntry);
		normalACA = pGetSkillLevel(_this, charData, 1120003, skillEntry);
		normalCombo = pGetSkillLevel(_this, charData, 1111002, skillEntry);
		cygnusCombo = pGetSkillLevel(_this, charData, 11111001, skillEntry);
		cygnusACA = pGetSkillLevel(_this, charData, 11110004, skillEntry);
		bowman = pGetSkillLevel(_this, charData, 3000001, skillEntry);
		thief = pGetSkillLevel(_this, charData, 4100001, skillEntry);
		nw = pGetSkillLevel(_this, charData, 14100001, skillEntry);
		wa = pGetSkillLevel(_this, charData, 13000000, skillEntry);
		tb = pGetSkillLevel(_this, charData, 15110000, skillEntry);
		mastery = pGetSkillLevel(_this, charData, 2320012, skillEntry);
		if (tb > 0) {
			skillid = 15110000;
		}
		if (nw > 0) {
			skillid = 14100001;
		}
		if (thief > 0) {
			skillid = 4100001;
		}
		if (wa > 0) {
			skillid = 13000000;
		}
		if (bowman > 0) {
			skillid = 3000001;
		}
	}
	return pGetSkillLevel(_this, charData, skillID, skillEntry);
}

auto comboCalc_hook = (int(__cdecl*)(int, int, int))0x007653FA;
int(__cdecl comboCalc)(int _this, int edx, int a2) {
	int v10 = 100;
	if (cygnusACA > 0 && cygnusACA > normalACA)
	{
		return v10 + 50 + cygnusACA;
	}
	if (normalACA > 0 && cygnusACA < normalACA)
	{
		return v10 + 40 + normalACA;
	}
	if (normalCombo > 0)
	{
		return v10 + normalCombo + 5;
	}
	if (cygnusCombo > 0) {
		return v10 + cygnusCombo + 15;
	}
	return v10;
}

auto get_cool_time = (int(__cdecl*)(int))0x009535E3;
int(__cdecl get_cool_time_t)(int nSkillID)
{
	if (nSkillID == 4121008)
	{
		return 0;
	}
	return (get_cool_time(nSkillID));
}

auto remove_bullet_skill_hook = (int(__cdecl*)(int))0x007667EE;
int(__cdecl remove_bullets)(int nSkillID)
{
	if (nSkillID == 14111002 || nSkillID == 4111005 || nSkillID == 5221016 || nSkillID == 5221017 || nSkillID == 3121015 || nSkillID == 3221009)
	{
		return 1;
	}
	return (remove_bullet_skill_hook(nSkillID));
}

auto pDoJump = (int(__thiscall*)(int, int))0x0094C383;
int(__fastcall CUserLocal_Jump)(int _this, void* edx, int a2) {
	if (!jumped)
	{
		jumptimer = chrono::steady_clock::now();
		jumped = true;
		return pDoJump(_this, a2);
	}
	auto elapsed = chrono::steady_clock::now() - jumptimer;
	if (elapsed > chrono::milliseconds(100) && elapsed < chrono::milliseconds(450) && jumped) {
		CUserLocal__DoActiveSkill_t(_this, nullptr, 1050, 0, 0);
		jumped = false;
		return 0;
	}
	jumped = false;
	return pDoJump(_this, a2);
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

auto calcpdamage_hook = (void*(__thiscall*)(int, int, int, int, int,int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int))0x0078DF87;
void* (__fastcall CalcDamage__PDamage)(
	int _this,
	void* edx,
	int a2,
	int bs,
	int a4,
	int a5,
	int a6,
	int a7,
	int nDamagePerMob,
	int nItemID,
	int a10,
	int a11,
	int nAction,
	int shadow_partner,
	int a14,
	int a15,
	int a16,
	int a17,
	int a18,
	int a19,
	int a20,
	int a21) {
	switch (get_weapon_type()) {
	case 45:
	case 46:
	case 47:
	case 49:
		return calcpdamage_hook(_this, a2, bs, a4, a5, a6, a7, nDamagePerMob, nItemID, a10, 1,
			nAction, shadow_partner, a14, a15, a16, a17, a18, a19, a20, a21);
	default:
		return calcpdamage_hook(_this, a2, bs, a4, a5, a6, a7, nDamagePerMob, nItemID, a10, a11,
			nAction, shadow_partner, a14, a15, a16, a17, a18, a19, a20, a21);
	}
}


auto skillDelayHook = (int(__cdecl*)(int))0x00765047;
int(__cdecl summondelay)(int nSkillID)
{
	return 0;
}

auto SecondaryStat__SetFrom_Hook = (void(__thiscall*)(int, int, int, int, int, int, int))0x0077F4C9;
int(__fastcall SecondaryStat__SetFrom)(int ss, void* edx, int cd, int bs, int fs, int a3, int a4, int a5) {

}

auto pGetAttackSpeedDegree = (void(__thiscall*)(int, int, int, int))0x00765066;
int(__cdecl GetAttackSpeedDegree)(int nDegree, int nSkillID, int nWeaponBooster, int nPartyBooster)
{
	int nWeaponDegree = 4;
	switch (get_weapon_type())
	{
	case 30:
	case 31:
	case 32:
	case 37:
	case 38:
	case 44:
	case 47:
	case 49:
		nWeaponDegree = 3;
		break;
	case 33:
		nWeaponDegree = 2;
		break;
	default:
		nWeaponDegree = 4;
		break;
	}
	nWeaponDegree += nPartyBooster;
	if (nWeaponDegree < 0)
	{
		nWeaponDegree = 0;
	}
	return nWeaponDegree;
}


auto pAttackSpeedText = (int(__cdecl*)(int))0x005C9AFA;
int(__cdecl attackSpeedText)(int nDegree) {
	return 0;
}

auto octHook = (int(__cdecl*)(int))0x00766612;
int(__cdecl octopus)(int nSkillID)
{
	if (nSkillID == 3121013 || nSkillID == 8001002 || nSkillID == 8001003 || nSkillID == 8001004)
	{
		return 1;
	}
	return octHook(nSkillID);
}

auto ltrbshoothook = (int(__cdecl*)(int))0x00766722;
int(__cdecl ltrb)(int nSkillID)
{
	if (nSkillID == 13121001 || nSkillID == 13121002 || nSkillID == 13121052 || nSkillID == 13121054 || nSkillID == 14121007
		|| nSkillID == 3221010 || nSkillID == 3221009 || nSkillID == 3201005 || nSkillID == 3121015 || nSkillID == 5221017)
	{
		return 1;
	}
	return ltrbshoothook(nSkillID);
}
auto get_vertical_adjust_of_attack_range = (int(__cdecl*)(int))0x0076664D;
int(__cdecl vertical)(int nSkillID)
{
	return 500;
}

//0076511E to jmp
//0076514E jmp out
int critret = 0x00765153;
//007650AF jmpout
void _declspec(naked)critAllClasses() {
	_asm {
		push skillid
		jmp[critret]
	}
}

int critsjmp = 0x007650f5;
int nwthrow = 0x0078F881;
void _declspec(naked) dCrits()
{
	_asm {
		cmp eax, 50
		pop ecx
		jmp[critsjmp]
	}
}

int jnejmp = 0x0078EEC1;
int jeclawjmp = 0x0078FAD8;
void _declspec(naked) Claw_5()
{
	_asm {
		jne[lb1]
		je[lb2]
		lb1:
		jmp[jnejmp]
			lb2 :
			jmp[jeclawjmp]
	}
}

//0078F886
//0078FAD8
int jztos = 0x0078FAD8;
int jmpbacks = 0x0078F886;
void _declspec(naked) NW_Multi()
{
	_asm {
		cmp eax, 14121001
		je[lb1]
		cmp eax, 0xD7511D
		jmp[jmpbacks]
		lb1 :
		jmp[jztos]
	}
}

int madcalcjmpout = 0x00791BAE;
int madcalcjmpback = 0x00791BB4;
void _declspec(naked) DamCalc()
{
	_asm {
		push dword ptr[eax + 0xD8]
		add eax, 0xD0
		jmp[madcalcjmpback]
	}
}

double div100 = 0.01;


// Generate a random double
double random_number = 0.0;

void redoMagic()
{
	std::random_device rd;
	std::mt19937 gen(rd());

	// Define the range [0.60, 1.00]
	if (mastery > 0) {
		std::uniform_real_distribution<double> dist(0.80, 1.00);
		random_number = dist(gen);
	}
	else {
		std::uniform_real_distribution<double> dist(0.60, 1.00);
		random_number = dist(gen);
	}
}

int int_ = 0;
int magic = 0;
int bonusmagic = 0;
int pleasejmpout = 0x00791C6C;
double int_multiplier = 4.0;
double Hundred = 100;
int topMAD = 0;
int botMAD = 0;
int totmagic = 0;
int pad = 0;
double clMultiplier = 1.25;

void setMAD()
{
	topMAD = (((int_ * int_multiplier) * ((magic + bonusmagic) - int_)) / 100);
	botMAD = topMAD * 0.6;
	totmagic = ((magic + bonusmagic) - int_);
}


void summonPAD()
{
	topMAD = (((int_ * int_multiplier) * ((magic + bonusmagic) - int_)) / 100);
	botMAD = topMAD * 0.6;
	totmagic = ((magic + bonusmagic) - int_);
}

void _declspec(naked) please()
{
	setMAD();
	_asm {
		fild topMAD
		call[redoMagic]
		fmul random_number
		fimul[ebp + 0x30] // damage from skill
		fdiv Hundred
		jmp[pleasejmpout]
	}
}

auto chainLightning_Hook = (signed int(__thiscall*)(int*, int, int, int*, int))0x0075BF50;
int __fastcall drop_off_damage_skills(int* a1, void* edx, int a3, int a4, int* a5, int a6)
{
	int* v6;
	int i;
	for (i = 0; i < 15; i++)
	{
		double dMultiplier = 1.25;

		int j;

		for (j = 0; j < i; j++)
		{
			dMultiplier *= 1.25;
		}

		*(double*)(0x00BDB470 + i * sizeof(double)) = dMultiplier;
	}
	//Log("%7d", chainLightning_Hook(a1, a2, a3, a4 ,a5, a6));
	return chainLightning_Hook(a1, a3, a4, a5, a6);
}


auto ztlSecureFuse_check = (unsigned int(__cdecl*)(int, int))0x00416563;
unsigned int __cdecl ztlfuse(int a1, int a2) {
	if ((int)_ReturnAddress() == 0x00791BC9)
	{
		int_ = ztlSecureFuse_check(a1, a2);
	}
	if ((int)_ReturnAddress() == 0x008C677D)
	{
		int_ = ztlSecureFuse_check(a1, a2);
	}
	if ((int)_ReturnAddress() == 0x008C36A4)
	{
		magic = ztlSecureFuse_check(a1, a2);
	}
	if ((int)_ReturnAddress() == 0x00791650)
	{
		magic = ztlSecureFuse_check(a1, a2);
	}
	if ((int)_ReturnAddress() == 0x0079165E)
	{
		bonusmagic = ztlSecureFuse_check(a1, a2);
	}
	return ztlSecureFuse_check(a1, a2);
}

auto mastery_Calcs_Hook = (int(__cdecl*)(int, int, int, int, int, int))0x00764795;
int __cdecl mCalc(int a1, int a2, int a3, int a4, int a5, int a6) {
	if (get_weapon_type() > 44 && get_weapon_type() != 48) {
		return mastery_Calcs_Hook(a1, a2, 1, a4, a5, a6);
	}
	switch (get_weapon_type()) {
		case 31:
		case 32:
		case 41:
		case 42:
			return mastery_Calcs_Hook(a1, 1302000, 0, a4, a5, a6);
		default:
			break;
	}
		return mastery_Calcs_Hook(a1, a2, 0, a4, a5, a6);
}

auto ztlSecureFuse_short = (unsigned int(__cdecl*)(int, int))0x004746DD;
unsigned int __cdecl ztlfuse_short(int a1, int a2) {
	return ztlSecureFuse_short(a1, a2);
}

auto getPAD_hook = (int(__thiscall*)(void*, int, int))0x0077DF48;
int(__fastcall getPAD)(void* ss, void* edx, int getIncPAD, int bulletItem)
{
	pad = getPAD_hook(ss, getIncPAD, bulletItem);
	return getPAD_hook(ss, getIncPAD, bulletItem);
}

auto hook_bstr_t = (void(__thiscall*)(void*, const char*))0x00425ADD;
void(__fastcall bstrt)(void* Level, void* blah, const char* a2) {
	using namespace std;
	setMAD();
	int tMAD = topMAD;
	int bMAD = botMAD;
	int getMad = totmagic;
	int getPad = pad;
	string toMad = to_string(bMAD) + " ~ " + to_string(tMAD);
	string magicStr = to_string(getMad);
	string padStr = to_string(getPad);
	const char* magicchar = magicStr.c_str();
	const char* sussychar = toMad.c_str();
	const char* weaponchar = padStr.c_str();
	if ((int)_ReturnAddress() == 0x008C3B9C)
	{
		a2 = magicchar;
	}
	else if ((int)_ReturnAddress() == 0x008C3D4F)
	{
		a2 = sussychar;
	}
	else if ((int)_ReturnAddress() == 0x008C374A)
	{
		a2 = weaponchar;
	}
	return hook_bstr_t(Level, a2);
}
