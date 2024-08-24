#pragma once
#include "../Type/Assert.h"
#include "IWzSerialize.h"

class IWzShape2D : IWzSerialize
{
public:
private:
};

static_assert_size(sizeof(IWzShape2D), 0x4);