#pragma once
#include "Assert.h"
#include "ZMap.h"
#include "ZRef.h"

class AdditionPsd {
public:
	static ZRef<AdditionPsd>* GetAt(ZMap<long, ZRef<AdditionPsd>, long>* pThis, const int* key, ZRef<AdditionPsd>* value)
	{
		return reinterpret_cast<ZRef<AdditionPsd>*(__fastcall*)
			(ZMap<long, ZRef<AdditionPsd>, long>*, void*, const int*, ZRef<AdditionPsd>*)>(0x0072C840)
			(pThis, nullptr, key, value);
	}
	int nCr;
	int nCDMin;
	int nAr;
	int nDIPr;
	int nPDamr;
	int nMDamr;
	int nIMPr;
private:
};

static_assert_size(sizeof(AdditionPsd), 0x1C);