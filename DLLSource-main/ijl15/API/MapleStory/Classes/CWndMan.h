#pragma once
#include "../Type/TSingleton.h"
#include "../Type/Assert.h"

class CWndMan : public TSingleton<CWndMan, 0x00C63EA8>
{
	~CWndMan() = delete;
public:
	static void StartHooks();
private:
};