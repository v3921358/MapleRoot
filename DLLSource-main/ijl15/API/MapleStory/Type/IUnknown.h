#pragma once
#include "Assert.h"
#include <Windows.h>
#include <comutil.h>
#include <string>

class IUnknownVtbl
{
public:
	HRESULT(__stdcall* QueryInterface)(IUnknown*, _GUID*, void**);
	unsigned int(__stdcall* AddRef)(IUnknown*);
	unsigned int(__stdcall* Release)(IUnknown*);
private:
};

class _IUnknown
{
public:
	IUnknownVtbl* vfptr;
private:
};

static_assert_size(sizeof(IUnknownVtbl), 0xC);
static_assert_size(sizeof(_IUnknown), 0x4);