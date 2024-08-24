#pragma once
#include "../Type/Assert.h"
#include "IWzSerialize.h"

class IWzCanvas : IWzSerialize
{
public:
private:
};

static_assert_size(sizeof(IWzCanvas), 0x4);
