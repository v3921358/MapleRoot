#pragma once
#include "../Type/TSingleton.h"
#include "CalcDamage.h"
#include "../Type/ZRef.h"
#include "../Type/ALLIANCEDATA.h"

class CWvsContext : public TSingleton<CWvsContext, 0x00C64068>
{
	~CWvsContext() = delete;
public:
	ZRef<CharacterData> GetCharacterData()
	{
		return m_pCharacterData;
	}

	padding(0x20C8);
	ZRef<CharacterData> m_pCharacterData;
	padding(0x1764);
	ALLIANCEDATA m_alliance;
	padding(0x42C);
	CalcDamage m_CalcDamage;
private:
};

static_assert_size(sizeof(CWvsContext), 0x3D08);