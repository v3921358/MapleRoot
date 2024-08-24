#pragma once
#include <Windows.h>
#include <cstdint>
#include "lazy_import.h"

template<typename T>
__forceinline void write_to_mem(uintptr_t address, T value)
{
	unsigned long oldprot;
	LI_FN(VirtualProtect)(reinterpret_cast<void*>(address), sizeof(value), PAGE_EXECUTE_READWRITE, &oldprot);
	*reinterpret_cast<T*>(address) = value;
	LI_FN(VirtualProtect)(reinterpret_cast<void*>(address), sizeof(value), oldprot, nullptr);
}

void change_res(int width, int height);