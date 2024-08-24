#define WIN32_LEAN_AND_MEAN
#include "../Global.h"
#include "chair_rel_move.h"

#pragma comment(lib, "comsuppw.lib")

// these make the code harder to reverse engineer
#define JM_XORSTR_DISABLE_AVX_INTRINSICS
#include "xorstr.h"
#include "lazy_import.h"
#include "res.h"
#include "otherstuffsmile.h"


#define FMT_HEADER_ONLY
#include "../fmt/format.h"
#include <unordered_map>
#include <string>

#include "../DiscordRichPresence.h"
#include "../rulaxStuff.h"

#define HOSTNAME "localhost"

struct chair_data_t
{
	chair_data_t() {}
	chair_data_t(int nBodyRelMoveX, int nBodyRelMoveY) : m_nBodyRelMoveX(nBodyRelMoveX), m_nBodyRelMoveY(nBodyRelMoveY) {}

	int m_nBodyRelMoveX = 0;
	int m_nBodyRelMoveY = 0;
	bool m_bFirstCall = true;
};

std::unordered_map<unsigned int, chair_data_t> g_pChairData;

uintptr_t g_pCItemInfo = 0x00BE78D8;
typedef IWzProperty* (__thiscall* CItemInfo__GetItemInfo_t)(uintptr_t ecx, IWzProperty** result, const int nItemID);
auto _CItemInfo__GetItemInfo = reinterpret_cast<CItemInfo__GetItemInfo_t>(0x005DA83C);

//typedef void(__thiscall* CClientSocket__ProcessPacket_t)(uintptr_t ecx, CInPacket* iPacket);
//auto _CClientSocket__ProcessPacket = reinterpret_cast<CClientSocket__ProcessPacket_t>(0x004965F1);

typedef void(__thiscall* CUserLocal__Update_t)(uintptr_t ecx);
auto _CUserLocal__Update = reinterpret_cast<CUserLocal__Update_t>(0x0094A144);

typedef void(__thiscall* CUser__SetActivePortableChair_t)(CUser* ecx, int nItemID);
auto _CUser__SetActivePortableChair = reinterpret_cast<CUser__SetActivePortableChair_t>(0x0093C7C3);

typedef void(__thiscall* CUser__Update_t)(CUser* ecx);
auto _CUser__Update = reinterpret_cast<CUser__Update_t>(0x00930B27);

typedef void(__thiscall* CAvatar__PrepareActionLayer_t)(CAvatar* ecx, int nActionSpeed, int nWalkSpeed, int bKeyDown);
auto _CAvatar__PrepareActionLayer = reinterpret_cast<CAvatar__PrepareActionLayer_t>(0x00453AD1);



uintptr_t get_lib(std::wstring_view lib)
{
	uintptr_t addr = reinterpret_cast<uintptr_t>(LI_FN(GetModuleHandleW)(lib.data()));

	if (addr == 0)
	{
		addr = reinterpret_cast<uintptr_t>(LI_FN(LoadLibraryW)(lib.data()));
	}

	return addr;
}

uintptr_t get_func(uintptr_t mod, std::string_view fun)
{
	return reinterpret_cast<uintptr_t>(LI_FN(GetProcAddress)(reinterpret_cast<HMODULE>(mod), fun.data()));
}

IWzProperty* get_item_info(const int nItemID)
{
	IWzProperty* pResult;
	_CItemInfo__GetItemInfo(g_pCItemInfo, &pResult, nItemID);

	return pResult;
}



void update_user_body_origin(const chair_data_t& pChairData, wil::com_ptr_t<IWzVector2D> pBodyOrigin)
{
	if (pBodyOrigin != nullptr)
	{
		pBodyOrigin->raw_RelMove(pChairData.m_nBodyRelMoveX, pChairData.m_nBodyRelMoveY, 0, 0);
	}
}



void __fastcall hook_CUser__Update(CUser* ecx, uintptr_t)
{
	_CUser__Update(ecx);

	static DWORD lastUpdate = 0;
	auto t = GetTickCount();
	//if(t - lastUpdate > 5000) {
	//	DiscordRichPresence::getInstance().updatePresence(GetJobCode(), GetCharacterLevel(), GetCharacterName());
	//	lastUpdate = t;
	//}

	if (g_pChairData.find(ecx->m_dwCharacterId()) != g_pChairData.end())
	{
		auto& pChairData = g_pChairData[ecx->m_dwCharacterId()];

		// prevents the chair from going above
		if (!pChairData.m_bFirstCall)
		{
			update_user_body_origin(pChairData, ecx->GetAvatar()->m_pBodyOrigin());
		}

		pChairData.m_bFirstCall = false;
	}
}

void __fastcall hook_CAvatar__PrepareActionLayer(CAvatar* ecx, uintptr_t, int nActionSpeed, int nWalkSpeed, int bKeyDown)
{
	_CAvatar__PrepareActionLayer(ecx, nActionSpeed, nWalkSpeed, bKeyDown);

	if (g_pChairData.find(ecx->GetCharacterID()) != g_pChairData.end())
	{
		auto& pChairData = g_pChairData[ecx->GetCharacterID()];

		if (!pChairData.m_bFirstCall)
		{
			update_user_body_origin(g_pChairData[ecx->GetCharacterID()], ecx->m_pBodyOrigin());
		}

		pChairData.m_bFirstCall = false;
	}
}

void __fastcall hook_CUser__SetActivePortableChair(CUser* ecx, uintptr_t, int nItemID)
{
	_CUser__SetActivePortableChair(ecx, nItemID);

	if (nItemID != 0)
	{
		int nBodyRelMoveX = 0;
		int nBodyRelMoveY = 0;
		auto pItemInfo = get_item_info(nItemID);

		if (pItemInfo != nullptr)
		{
			auto pBodyRelMove = pItemInfo->get_item<IWzVector2D*>(L"bodyRelMove");
		
			if (pBodyRelMove != nullptr)
			{
				nBodyRelMoveX = pBodyRelMove->get_x();
				nBodyRelMoveY = pBodyRelMove->get_y();
			}
			else
			{
				auto off = get_chair_rel_move(nItemID);
				nBodyRelMoveX = std::get<0>(off);
				nBodyRelMoveY = std::get<1>(off);
			}
		}


		// looking to the right - adjust view
		if (!ecx->IsLeft())
		{
			nBodyRelMoveX *= -1;
		}

		g_pChairData[ecx->m_dwCharacterId()] = chair_data_t(nBodyRelMoveX, nBodyRelMoveY);
		update_user_body_origin(g_pChairData[ecx->m_dwCharacterId()], ecx->GetAvatar()->m_pBodyOrigin());
	}

	else
	{
		g_pChairData.erase(ecx->m_dwCharacterId());
	}
}

void Hook_SetActivePortableChair(bool bEnable)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)_CUser__SetActivePortableChair, &hook_CUser__SetActivePortableChair);
	DetourTransactionCommit();
}

void Hook_PrepareActionLayer(bool bEnable)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)_CAvatar__PrepareActionLayer, &hook_CAvatar__PrepareActionLayer);
	DetourTransactionCommit();
}

void Hook_CUserLocalUpdate(bool bEnable)
{
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	(bEnable ? DetourAttach : DetourDetach)(&(PVOID&)_CUser__Update, &hook_CUser__Update);
	DetourTransactionCommit();
}


void init()
{
	change_res(1366, 768);
	Hook_CUserLocalUpdate(true);
	Hook_PrepareActionLayer(true);
	Hook_SetActivePortableChair(true);
}