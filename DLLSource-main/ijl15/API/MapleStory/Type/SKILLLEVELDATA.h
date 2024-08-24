#pragma once
#include "Assert.h"
#include "ZtlSecure.h"
#include "SECRECT.h"

class SKILLLEVELDATA {
public:
	int GetProp() {
		try {
			return this->nProp.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetCDMin() {
		try {
			return this->nCDMin.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetDamage() {
		try {
			return this->nDamage.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetX() {
		try {
			return this->nX.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}
private:
	// it's wrong apparently
	padding(0x4);
	ZtlSecure<int> nHP;
	ZtlSecure<int> nMP;
	ZtlSecure<int> nPAD;
	ZtlSecure<int> nPDD;
	ZtlSecure<int> nMAD;
	ZtlSecure<int> nMDD;
	ZtlSecure<int> nACC;
	ZtlSecure<int> nEVA;
	ZtlSecure<int> nCraft;
	ZtlSecure<int> nSpeed;
	ZtlSecure<int> nJump;
	ZtlSecure<int> nMorph;
	ZtlSecure<int> nHPCon;
	ZtlSecure<int> nMPCon;
	ZtlSecure<int> nMoneyCon;
	ZtlSecure<int> nItemCon;
	ZtlSecure<int> nItemConNo;
	ZtlSecure<int> nDamage;
	ZtlSecure<int> nFixDamage;
	ZtlSecure<int> nSelfDestruction;
	ZtlSecure<int> tTime;
	ZtlSecure<int> tSubTime;
	ZtlSecure<int> nProp;
	ZtlSecure<int> nSubProp;
	ZtlSecure<int> nAttackCount;
	ZtlSecure<int> nBulletCount;
	ZtlSecure<int> nBulletConsume;
	ZtlSecure<int> nMastery;
	ZtlSecure<int> nMobCount;
	ZtlSecure<int> nX;
	ZtlSecure<int> nY;
	ZtlSecure<int> nZ;
	ZtlSecure<int> nAction;
	ZtlSecure<int> nEMHP;
	ZtlSecure<int> nEMMP;
	ZtlSecure<int> nEPAD;
	ZtlSecure<int> nEPDD;
	ZtlSecure<int> nEMDD;
	SECRECT rcAffectedArea;
	ZtlSecure<int> nRange;
	padding(0xC);
	ZtlSecure<int> nCooltime;
	ZtlSecure<int> nMHPr;
	ZtlSecure<int> nMMPr;
	ZtlSecure<int> nCr;
	ZtlSecure<int> nCDMin;
	ZtlSecure<int> nCDMax;
	ZtlSecure<int> nACCr;
	ZtlSecure<int> nEVAr;
	ZtlSecure<int> nAr;
	ZtlSecure<int> nEr;
	ZtlSecure<int> nPDDr;
	ZtlSecure<int> nMDDr;
	ZtlSecure<int> nPDr;
	ZtlSecure<int> nMDr;
	ZtlSecure<int> nDIPr;
	ZtlSecure<int> nPDamr;
	ZtlSecure<int> nMDamr;
	ZtlSecure<int> nPADr;
	ZtlSecure<int> nMADr;
	ZtlSecure<int> nEXPr;
	ZtlSecure<int> nDot;
	ZtlSecure<unsigned int> unDotInterval;
	ZtlSecure<unsigned int> unDotTime;
	ZtlSecure<int> nIMPr;
	ZtlSecure<int> nASRr;
	ZtlSecure<int> nTERr;
	ZtlSecure<int> nMESOr;
	ZtlSecure<int> nPADx;
	ZtlSecure<int> nMADx;
	ZtlSecure<int> nIMDr;
	ZtlSecure<int> nPsdJump;
	ZtlSecure<int> nPsdSpeed;
	ZtlSecure<int> nOCr;
	ZtlSecure<int> nDCr;
	ZtlSecure<int> nReqGL;
	ZtlSecure<int> nPrice;
	ZtlSecure<unsigned int> nCRC;
	ZtlSecure<int> nS;
	ZtlSecure<int> nU;
	ZtlSecure<int> nV;
	ZtlSecure<int> nW;
	float _ZtlSecureTear_fT;
	_FILETIME dateExpire;
	int bLoaded;
	int bCalcCRC;
};

static_assert_size(sizeof(SKILLLEVELDATA), 0x414);