#pragma once
#include "Assert.h"
#include "ZtlSecure.h"

class SECPOINT
{
public:
	ZtlSecure<long> y;
	ZtlSecure<long> x;
private:
};

static_assert_size(sizeof(SECPOINT), 0x18);