#pragma once
#include "Assert.h"
#include "../Type/ZtlSecure.h"

class BasicStat
{
public:
	int GetLevel() {
		try {
			return this->nLevel.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetJob() {
		try {
			return this->nJob.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetSTR() {
		try {
			return this->nSTR.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetDEX() {
		try {
			return this->nDEX.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetINT() {
		try {
			return this->nINT.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetLUK() {
		try {
			return this->nLUK.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetPOP() {
		try {
			return this->nPOP.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetMHP() {
		try {
			return this->nMHP.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

	int GetMMP() {
		try {
			return this->nMMP.Fuse();
		}
		catch (std::exception& e) {
			UNREFERENCED_PARAMETER(e);
		}

		return 0;
	}

private:
	ZtlSecure<int> nGender;
	ZtlSecure<int> nLevel;
	ZtlSecure<int> nJob;
	ZtlSecure<int> nSTR;
	ZtlSecure<int> nDEX;
	ZtlSecure<int> nINT;
	ZtlSecure<int> nLUK;
	ZtlSecure<int> nPOP;
	ZtlSecure<int> nMHP;
	ZtlSecure<int> nMMP;
};

//static_assert_size(sizeof(BasicStat), 0x78);