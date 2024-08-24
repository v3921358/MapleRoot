#pragma once
#include "Assert.h"

class CRTTI
{
public:
	CRTTI* m_pPrev;
private:
};

static_assert_size(sizeof(CRTTI), 0x4);