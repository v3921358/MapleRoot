#pragma once
#include "../Type/Assert.h"
#include "IWzGr2DLayer.h"

class Com_Gr2DLayer
{
public:
	IWzGr2DLayer* m_pInterface;
private:
};

static_assert_size(sizeof(Com_Gr2DLayer), 0x4);