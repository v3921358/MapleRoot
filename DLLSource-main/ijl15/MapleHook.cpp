#pragma once
#include "Global.h"
#include "SkillEdits/ActiveSkill.h"
#include "shavitstuff/aquila.h"
#include "shavitstuff/IWzResMan.h"
#include "rulaxStuff.h"
#include "SkillEdits/CharacterDataEx.h"

// do active hooks

void Hook_DoActiveSkill(bool bEnable)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)pDoActiveSkill, &CUserLocal__DoActiveSkill_t);
	DetourTransactionCommit();
}

void Hook_Jump(bool bEnable)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)pDoJump, &CUserLocal_Jump);
	DetourTransactionCommit();
}

bool HookPcCreateObject_IWzResMan(bool bEnable)
{
	return SetHook(bEnable, reinterpret_cast<void**>(&_PcCreateObject_IWzResMan), _PcCreateObject_IWzResMan_Hook);
}
bool HookPcCreateObject_IWzNameSpace(bool bEnable)
{
	return SetHook(bEnable, reinterpret_cast<void**>(&_PcCreateObject_IWzNameSpace), _PcCreateObject_IWzNameSpace_Hook);
}
bool HookPcCreateObject_IWzFileSystem(bool bEnable)
{
	return SetHook(bEnable, reinterpret_cast<void**>(&_PcCreateObject_IWzFileSystem), _PcCreateObject_IWzFileSystem_Hook);
}
bool HookCWvsApp__Dir_BackSlashToSlash(bool bEnable)
{
	return SetHook(bEnable, reinterpret_cast<void**>(&_CWvsApp__Dir_BackSlashToSlash), _CWvsApp__Dir_BackSlashToSlash_Hook);
}
bool HookCWvsApp__Dir_upDir(bool bEnable)
{
	return SetHook(bEnable, reinterpret_cast<void**>(&_CWvsApp__Dir_upDir), _CWvsApp__Dir_upDir_Hook);
}
bool Hookbstr_ctor(bool bEnable)
{
	return SetHook(bEnable, reinterpret_cast<void**>(&_bstr_ctor), _bstr_ctor_Hook);
}
bool HookIWzFileSystem__Init(bool bEnable)
{
	return SetHook(bEnable, reinterpret_cast<void**>(&_IWzFileSystem__Init), _IWzFileSystem__Init_Hook);
}
bool HookIWzNameSpace__Mount(bool bEnable)
{
	return SetHook(bEnable, reinterpret_cast<void**>(&_IWzNameSpace__Mount), _IWzNameSpace__Mount_Hook);
}
//void Hook_Strings(bool bEnable)
//{
//	DetourTransactionBegin();
//	DetourUpdateThread(GetCurrentThread());
//	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)GetString, &tGetString);
//	DetourTransactionCommit();
//}



//void Hook_SMP(bool bEnable)
//{
//	DetourTransactionBegin();
//	DetourUpdateThread(GetCurrentThread());
//	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)SetMovePathAttribute, &tSetMovePathAttribute);
//	DetourTransactionCommit();
//}

void Hook_GetSkillLevel(bool bEnable)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)pGetSkillLevel, &GetSkillLevel);
	DetourTransactionCommit();

}

void Hook_Combo(bool bEnable)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)comboCalc_hook, &comboCalc);
	DetourTransactionCommit();

}

void Hook_Layers(bool bEnable)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)animation_hook, &LoadLayer);
	DetourTransactionCommit();

}

void Hook_Layers2(bool bEnable)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)animation_hook2, &LoadLayer2);
	DetourTransactionCommit();

}

//old stuff
//void asmStuff()
//{
//	ui_hacks();
//	misc_hacks();
//	skillhacks();
//	clientHacks();
//}

//void Hook_Crit(bool bEnable)
//{
//	DetourTransactionBegin();
//	DetourUpdateThread(GetCurrentThread());
//	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)getcrit, &get_critical_skill_level);
//	DetourTransactionCommit();
//}



bool Hook_CUserLocal__CanUseBareHand(bool enable) {
	typedef bool(__fastcall* CUserLocal__CanUseBareHand_t)(LPVOID lpvClassPtr, LPVOID lpvEdx);
	static auto CUserLocal__CanUseBareHand = reinterpret_cast<CUserLocal__CanUseBareHand_t>(0x0095F8CF);

	CUserLocal__CanUseBareHand_t Hook = [](void* ecx, void* edx) -> bool
	{
		/*Log("barehandaddy %p", _ReturnAddress());*/
		return true;
	};

	return SetHook(enable, reinterpret_cast<void**>(&CUserLocal__CanUseBareHand), Hook);
}

bool Hook_get_novice_skill_point(bool enable) {
	typedef int(__fastcall* get_novice_skill_point_t)(LPVOID lpvClassPtr, LPVOID lpvEdx);
	static auto get_novice_skill_point = reinterpret_cast<get_novice_skill_point_t>(0x765E9E);

	get_novice_skill_point_t Hook = [](void* ecx, void* edx) -> int
	{
		return 0;

	};

	return SetHook(enable, reinterpret_cast<void**>(&get_novice_skill_point), Hook);
}

bool Hook_monster_book_open(bool enable) {
	typedef int(__fastcall* monster_book_open_t)(LPVOID lpvClassPtr, LPVOID lpvEdx, unsigned int a1);
	static auto monster_book_open = reinterpret_cast<monster_book_open_t>(0x861B12);

	monster_book_open_t Hook = [](void* ecx, void* edx, unsigned int a1) -> int
	{
		return 0;
	};

	return SetHook(enable, reinterpret_cast<void**>(&monster_book_open), Hook);
}

bool Hook_monster_book_open_mob(bool enable) {
	typedef int(__fastcall* Hook_monster_book_open_mob_t)(LPVOID lpvClassPtr, LPVOID lpvEdx, char a2, signed int* a3);
	static auto Hook_monster_book_open_mob = reinterpret_cast<Hook_monster_book_open_mob_t>(0x86793F);

	Hook_monster_book_open_mob_t Hook = [](void* ecx, void* edx, char a2, signed int* a3) -> int
	{
		return 0;
	};

	return SetHook(enable, reinterpret_cast<void**>(&Hook_monster_book_open_mob), Hook);
}

bool HookCWvsApp__InitializeResMan(bool bEnable)	//resman hook that does nothing, kept for analysis and referrence //not skilled enough to rewrite to load custom wz files
{
	static _CWvsApp__InitializeResMan_t _CWvsApp__InitializeResMan_Hook = [](void* pThis, void* edx) {
		////-> void {_CWvsApp__InitializeResMan(pThis, edx);
		//_CWvsApp__InitializeResMan(pThis, edx);	//comment this out and uncomment below if testing, supposed to load from .img files in folders but i never got to test it
		void* pData = nullptr;
		void* pFileSystem = nullptr;
		void* pUnkOuter = 0;
		void* nPriority = 0;
		void* sPath;

		// Resman
		_PcCreateObject_IWzResMan(L"ResMan", g_rm, pUnkOuter);	//?(void*) //?&g

		void* pIWzResMan_Instance = *g_rm;	//?&g
		auto IWzResMan__SetResManParam = *(void(__fastcall**)(void*, void*, void*, int, int, int))((*(int*)pIWzResMan_Instance) + 20); // Hard Coded
		IWzResMan__SetResManParam(nullptr, nullptr, pIWzResMan_Instance, RC_AUTO_REPARSE | RC_AUTO_SERIALIZE, 60000, -1);

		// NameSpace
		_PcCreateObject_IWzNameSpace(L"NameSpace", g_root, pUnkOuter);

		void* pIWzNameSpace_Instance = g_root;
		auto PcSetRootNameSpace = *(void(__cdecl*)(void*, int)) * (int*)pNameSpace; // Hard Coded
		PcSetRootNameSpace(pIWzNameSpace_Instance, 1);

		// Game FileSystem
		_PcCreateObject_IWzFileSystem(L"NameSpace#FileSystem", &pFileSystem, pUnkOuter);

		char sStartPath[MAX_PATH];
		GetModuleFileNameA(NULL, sStartPath, MAX_PATH);
		_CWvsApp__Dir_BackSlashToSlash(sStartPath);
		_CWvsApp__Dir_upDir(sStartPath);

		_bstr_ctor(&sPath, pData, sStartPath);

		auto iGameFS = _IWzFileSystem__Init(pFileSystem, pData, sPath);

		_bstr_ctor(&sPath, pData, "/");

		auto mGameFS = _IWzNameSpace__Mount(*g_root, pData, sPath, pFileSystem, (int)nPriority);

		// Data FileSystem
		_PcCreateObject_IWzFileSystem(L"NameSpace#FileSystem", &pFileSystem, pUnkOuter);

		_bstr_ctor(&sPath, pData, "./Data");

		auto iDataFS = _IWzFileSystem__Init(pFileSystem, pData, sPath);

		_bstr_ctor(&sPath, pData, "/");

		auto mDataFS = _IWzNameSpace__Mount(*g_root, pData, sPath, pFileSystem, (int)nPriority);
	};
	return SetHook(bEnable, reinterpret_cast<void**>(&_CWvsApp__InitializeResMan), _CWvsApp__InitializeResMan_Hook);
}

//void flushcache() {
//	constexpr const uint32_t SWEEPCACHE_DELAY_1 = 0x00411BE2;
//	write_to_mem<int>(SWEEPCACHE_DELAY_1 + 2, 10000);
//
//	constexpr const uint32_t SWEEPCACHE_DELAY_2[] = { 0x00411D70, 0x00411E13, 0x00411EC5, 0x00411F68, 0x0041625F, 0x0041201A, 0x004120BD, 0x00412282, 0x00412303, 0x00412388 };
//
//	for (auto n : SWEEPCACHE_DELAY_2)
//	{
//		write_to_mem<int>(n + 2, 10000);
//	}
//
//	// flush in CField::Init
//	constexpr const uint32_t CFIELD_FLUSH = 0x00529320;
//	write_to_mem<int>(CFIELD_FLUSH + 1, 0);
//}


BOOL HaxMaple() {
	doini();
	UpdateResolution();
	WriteValue(0x0078F60A + 2, 0xAFE858); // 1h axe/bw = 0xAFE858
	WriteValue(0x0078f6B0 + 2, 0xAFE858);
	WriteValue(0x0078F1A4 + 2, 0xAFE858); // 2H axe/bw = 4.6 
	WriteValue(0x0078F24A + 2, 0xAFE858);
	WriteValue(0x0078F3FB + 2, 0xAFE858); // Polearm/Spear = 5.0
	WriteValue(0x0078F4A8 + 2, 0xAFE858);
	WriteValue(0x0078FE3E + 2, 0xAFE858);
	WriteValue(0x0078FABD + 2, 0xAFE858);
	WriteValue(0x0078F555 + 2, 0xAFE858); //2h sword
	WriteValue(0x0078FD81 + 2, 0xAFE858);
	WriteValue(0x0078F4A8 + 2, 0xAFE858);
	WriteValue(0x0078FCD4 + 2, 0xAFE858);
	WriteValue(0x0078FB6B + 2, 0xAFE858);
	WriteValue(0x0078F1A4 + 2, 0xAFE858);
	WriteValue(0x0078F24A + 2, 0xAFE858);
	WriteValue(0x0078FC2E + 2, 0xAFE858);
	WriteValue(0x0078F042 + 2, 0xAFE858);
	WriteValue(0x0078F0EF + 2, 0xAFE858);
	WriteValue(0X0078EB28 + 2, 0xAFE858);
	WriteValue(0x0078EBD5 + 2, 0xAFE858);
	WriteValue(0x0078F1A4 + 2, 0xAFE858);

	//DRAW UI
	WriteValue(0x008C2CE3 + 2, 0xAFE858);
	WriteValue(0x008C2DFD + 2, 0xAFE858);
	WriteValue(0x008C2E46 + 2, 0xAFE858);
	WriteValue(0x008C2C56 + 2, 0xAFE858);
	WriteValue(0x008C2C9F + 2, 0xAFE858);
	WriteValue(0x008C2D2C + 2, 0xAFE858);
	WriteValue(0x008C2AEC + 2, 0xAFE858);
	WriteValue(0x008C2B35 + 2, 0xAFE858);
	WriteValue(0x008C320C + 2, 0xAFE858);
	WriteValue(0x008C3255 + 2, 0xAFE858);
	WriteValue(0x008C3299 + 2, 0xAFE858);
	WriteValue(0x008C2BC9 + 2, 0xAFE858);
	WriteValue(0x008C2EE0 + 2, 0xAFE858);
	WriteValue(0x008C2C12 + 2, 0xAFE858);
	WriteValue(0x008C309D + 2, 0xAFE858);
	WriteValue(0x008C32E2 + 2, 0xAFE858);
	WriteValue(0x008C2D70 + 2, 0xAFE858);
	WriteValue(0x008C2DB9 + 2, 0xAFE858);
	WriteValue(0x008C31C8 + 2, 0xAFE858);
	WriteValue(0x008C317F + 2, 0xAFE858);

	WriteValue(0x00792509 + 2, 0xAFE860); // SUMMON DEX * 5
	
	PatchNop(0x00668DDF, 27); //show mob for snipe/hh/etc
	//damage calcs for tempesthh etc
	WriteValue(0x0078E4D6 + 1, 3222222); //snipe calc skip
	WriteValue(0x0078E5CE + 1, 3222222); // Tempest		
	WriteValue(0x0078E699 + 2, 202200202); //HH
	WriteByte(0x0078E4B0, 0xEB);
	WriteByte(0x0078E4DB, 0xEB);
	WriteByte(0x0078E55C, 0xEB);
	WriteByte(0x0078E5D3, 0xEB);
	WriteByte(0x0078E934, 0xEB);
	WriteByte(0x007669B7 + 1, 0xA); // COMBO SMASH 10
	WriteByte(0x007669B3 + 1, 0x1E);
	WriteByte(0x004F2D9B + 2, 0x07);//Super Beginner Wears anything

	WriteValue(0x0075BF65 + 3, 0x00B3D108); //chain lightning to 1.25 bonus per mob

	HookPcCreateObject_IWzResMan(true);
	HookPcCreateObject_IWzNameSpace(true);
	HookPcCreateObject_IWzFileSystem(true);
	HookCWvsApp__Dir_BackSlashToSlash(true);
	Hook_Combo(true);
	Hook_Layers(true);
	Hook_Layers2(true);
	HookCWvsApp__Dir_upDir(true);
	Hookbstr_ctor(true);
	HookIWzFileSystem__Init(true);
	HookIWzNameSpace__Mount(true);
	Hook_GetSkillLevel(true);
	HookCWvsApp__InitializeResMan(true); //experimental //ty to all the contributors of the ragezone release: Client load .img instead of .wz v62~v92
	SetHook(TRUE, reinterpret_cast<PVOID*>(&_is_attack_area_set_by_data), is_attack_area_set_by_data);
	SetHook(true, reinterpret_cast<void**>(&g_real_CUser__IsDarkSight), Horizons_CUser__IsDarkSight);
	SetHook(true, reinterpret_cast<void**>(&ltrbshoothook), ltrb);
	SetHook(true, reinterpret_cast<void**>(&pDoActiveSkill), CUserLocal__DoActiveSkill_t);
	SetHook(true, reinterpret_cast<void**>(&skillDelayHook), summondelay);
	SetHook(true, reinterpret_cast<void**>(&octHook), octopus);
	SetHook(true, reinterpret_cast<void**>(&pGetAttackSpeedDegree), GetAttackSpeedDegree);
	SetHook(true, reinterpret_cast<void**>(&get_cool_time), get_cool_time_t);
	SetHook(true, reinterpret_cast<void**>(&remove_bullet_skill_hook), remove_bullets);
	SetHook(true, reinterpret_cast<void**>(&ztlSecureFuse_check), ztlfuse);
	//SetHook(true, reinterpret_cast<void**>(&ztlSecureFuse_UI), ztlfuse_UI);
	//SetHook(true, reinterpret_cast<void**>(&getFindHitMobInRect), FindHitMobInRect);
	SetHook(true, reinterpret_cast<void**>(&hook_bstr_t), bstrt);
	SetHook(true, reinterpret_cast<void**>(&getPAD_hook), getPAD);
	SetHook(true, reinterpret_cast<void**>(&hook_message), messageStuff);
	SetHook(true, reinterpret_cast<void**>(&CUserRemote__OnAttack), CUserOnAttackPacket);
	SetHook(true, reinterpret_cast<void**>(&CUserRemote__OnPrepare), CUserPreparePacket);
	SetHook(true, reinterpret_cast<void**>(&CUserRemote__OnPrepareCancel), CUserPrepareCancelPacket);
	SetHook(true, reinterpret_cast<void**>(&mastery_Calcs_Hook), mCalc);
	SetHook(true, reinterpret_cast<void**>(&chainLightning_Hook), drop_off_damage_skills);
	SetHook(true, reinterpret_cast<void**>(&calcpdamage_hook), CalcDamage__PDamage);
	//SetHook(true, reinterpret_cast<void**>(&setObjVisible_Hook), setObjVisible);
	//hacky magnus ballshit
	//PatchNop(0x00678539, 2);
	//WriteByte(0x00678552, 0xEB);
	//WriteByte(0x00678552 + 1, 0x48);
	//PatchNop(0x00678552 + 2, 4);
	// ui stuff
	WriteByte(0x008C35C9 + 1, 0x2C); // weapon def
	WriteByte(0x008C374A + 1, 0x1A); // weapon def
	WriteByte(0x008C39E9 + 1, 0x62); // weapon def
	WriteByte(0x008C3B9C + 1, 0x50); // weapon def
	WriteByte(0x008C3D4F + 1, 0x3E); // weapon def
	WriteByte(0x008C3F8E + 1, 0x74); // weapon def
	PatchNop(0x00668C04, 5);
	//CodeCave(DamCalc, madcalcjmpout, 1);
	WriteByte(0x00620F2B + 1, 0x1F); // bypass checks for spam to login
	InitExpOverride();
	CodeCave(please, 0x00791C41, 4);
	CodeCave((void*)critAllClasses, 0x0076514E, 0);
	CodeCave((void*)NW_Multi, nwthrow, 0);
	WriteByte(0x0078EDB1 + 1, 0x84);
	CodeCave((void*)Claw_5, 0x0078EDB1, 1);
	CodeCave((void*)dCrits, 0x007650AF, 5);
	PatchNop(0x007650F9, 6);
	WriteByte(0x0076511E, 0xEB);
	RulaxEdits();
	WriteByte(0x008ECB02, 0xEB);//draw weapons speed
	GooseExpansion();
	DarnellEdits();
	Hook_DoActiveSkill(true);
	Hook_Jump(true);
	//DiscordRichPresence::hook();
	SetHook(TRUE, reinterpret_cast<PVOID*>(&_is_attack_area_set_by_data), is_attack_area_set_by_data);

	//Avenger + other ranged skills patch to evaluate inside TryDoingShootAttack
	CodeCave(LtRb_Eval, 0x00953E2C, 6);
	//Hook_CAvatar__PrepareActionLayer(true);
	//Hook_CUser__SetActivePortableChair(true);
	//Hook_CUser__Update(true);
	init();
	return TRUE;
}