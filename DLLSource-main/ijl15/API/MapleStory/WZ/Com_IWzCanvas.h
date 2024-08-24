#pragma once
#include "../Type/Assert.h"
#include "../WZ/IWzCanvas.h"

class Com_IWzCanvas
{
public:
	IWzCanvas* m_pInterface;
private:
};

static_assert_size(sizeof(Com_IWzCanvas), 0x4);