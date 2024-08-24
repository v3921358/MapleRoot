#pragma once
#include "../../Type/Assert.h"
#include "../../Type/ZRefCounted.h"
#include "../../WZ/Com_Gr2DLayer.h"
#include "../../Type/FUNCKEY_MAPPED.h"

class IDraggable : ZRefCounted
{
public:
	Com_Gr2DLayer m_pLayer;
	FUNCKEY_MAPPED m_OldIcon;
private:
};

static_assert_size(sizeof(IDraggable), 0x18);