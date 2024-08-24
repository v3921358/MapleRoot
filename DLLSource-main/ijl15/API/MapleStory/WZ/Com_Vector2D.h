#pragma once
#include "../Type/Assert.h"
#include "../WZ/IWzVector2D.h"

class Com_Vector2D
{
public:
	IWzVector2D* m_pInterface;
private:
};

static_assert_size(sizeof(Com_Vector2D), 0x4);