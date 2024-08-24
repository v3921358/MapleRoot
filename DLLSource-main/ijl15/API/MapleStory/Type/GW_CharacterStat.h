#pragma once
#include "Assert.h"
#include "ZtlSecure.h"
#include "../Custom/MapleGender.h"
#include <string>

class GW_CharacterStat
{
public:
	char getLevel() {
		try {
			return this->nLevel.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

private:
	unsigned int dwCharacterID;
	char sCharacterName[13];
	char nGender;
	char nSkin;
	int nFace;
	int nHair;
	_LARGE_INTEGER aliPetLockerSN[3];
	ZtlSecure<char> nLevel;
	__int16 _ZtlSecureTear_nJob[2];
	unsigned int _ZtlSecureTear_nJob_CS;
	__int16 _ZtlSecureTear_nSTR[2];
	unsigned int _ZtlSecureTear_nSTR_CS;
	__int16 _ZtlSecureTear_nDEX[2];
	unsigned int _ZtlSecureTear_nDEX_CS;
	__int16 _ZtlSecureTear_nINT[2];
	unsigned int _ZtlSecureTear_nINT_CS;
	__int16 _ZtlSecureTear_nLUK[2];
	unsigned int _ZtlSecureTear_nLUK_CS;
	int _ZtlSecureTear_nHP[2];
	unsigned int _ZtlSecureTear_nHP_CS;
	int _ZtlSecureTear_nMHP[2];
	unsigned int _ZtlSecureTear_nMHP_CS;
	int _ZtlSecureTear_nMP[2];
	unsigned int _ZtlSecureTear_nMP_CS;
	int _ZtlSecureTear_nMMP[2];
	unsigned int _ZtlSecureTear_nMMP_CS;
	__int16 _ZtlSecureTear_nAP[2];
	unsigned int _ZtlSecureTear_nAP_CS;
	__int16 _ZtlSecureTear_nSP[2];
	unsigned int _ZtlSecureTear_nSP_CS;
	int _ZtlSecureTear_nEXP[2];
	unsigned int _ZtlSecureTear_nEXP_CS;
	__int16 _ZtlSecureTear_nPOP[2];
	unsigned int _ZtlSecureTear_nPOP_CS;
	int _ZtlSecureTear_nMoney[2];
	unsigned int _ZtlSecureTear_nMoney_CS;
	int _ZtlSecureTear_nTempEXP[2];
	unsigned int _ZtlSecureTear_nTempEXP_CS;
	/*ExtendSP extendSP;
	unsigned int _ZtlSecureTear_dwPosMap[2];
	unsigned int _ZtlSecureTear_dwPosMap_CS;
	char nPortal;
	int nCheckSum;
	char nItemCountCheckSum;
	int nPlaytime;
	__int16 nSubJob;*/
};

static_assert_size(sizeof(GW_CharacterStat), 0xD8);