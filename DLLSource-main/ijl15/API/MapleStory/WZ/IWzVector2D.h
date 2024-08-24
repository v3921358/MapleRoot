#pragma once
#include "../Type/Assert.h"
#include "IWzShape2D.h"

class IWzVector2D : IWzShape2D
{
public:
private:
};

static_assert_size(sizeof(IWzVector2D), 0x4);