#pragma once
#include "Assert.h"

namespace Additional 
{
	class CRITICAL
	{
	public:
		int nProb;
		int nDamage;
	private:
	};
}

static_assert_size(sizeof(Additional::CRITICAL), 0x8);