#pragma once
#include "../../Type/Assert.h"
#include "../../Type/ZArray.h"
#include "../../Type/ZList.h"
#include "../../Type/ZXString.h"
#include "../../Type/CRTTI.h"
#include "IDraggable.h"

class IUIMsgHandler
{
public:
	IUIMsgHandlerVtbl* vfptr;
private:
};

class IUIMsgHandlerVtbl
{
public:
	void(__thiscall* OnKey)(IUIMsgHandler*, unsigned int, unsigned int);
	BYTE gap4[8];
	int(__thiscall* OnMouseMove)(IUIMsgHandler*, int, int);
	int(__thiscall* OnMouseWheel)(IUIMsgHandler*, int, int, int);
	void(__thiscall* OnMouseEnter)(IUIMsgHandler*, int);
	void(__thiscall* OnDraggableMove)(IUIMsgHandler*, int, IDraggable*, int, int);
	void(__thiscall* SetEnable)(IUIMsgHandler*, int);
	int(__thiscall* IsEnabled)(IUIMsgHandler*);
	void(__thiscall* SetShow)(IUIMsgHandler*, int);
	int(__thiscall* IsShown)(IUIMsgHandler*);
	int(__thiscall* GetAbsLeft)(IUIMsgHandler*);
	int(__thiscall* GetAbsTop)(IUIMsgHandler*);
	void(__thiscall* ClearToolTip)(IUIMsgHandler*);
	void(__thiscall* OnIMEModeChange)(IUIMsgHandler*, char);
	void(__thiscall* OnIMEResult)(IUIMsgHandler*, const char*);
	void(__thiscall* OnIMEComp)(IUIMsgHandler*, const char*, ZArray<unsigned long>*, unsigned int, int, ZList<ZXString<char> >*, int, int, int);
	CRTTI* (__thiscall* GetRTTI)(IUIMsgHandler*);
	int(__thiscall* IsKindOf)(IUIMsgHandler*, CRTTI*);
};

static_assert_size(sizeof(IUIMsgHandlerVtbl), 0x4C);
static_assert_size(sizeof(IUIMsgHandler), 0x4);