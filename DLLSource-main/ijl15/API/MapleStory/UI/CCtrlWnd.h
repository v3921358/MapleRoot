#pragma once
#include "../Type/Assert.h"
#include "Msg/IGObj.h"
#include "Msg/IUIMsgHandler.h"
#include "../WZ/Com_Vector2D.h"
#include "CWnd.h"

struct CCtrlWnd : IGObj, IUIMsgHandler, ZRefCounted
{
	unsigned int m_nCtrlId;
	Com_Vector2D m_pLTCtrl;
	int m_width;
	int m_height;
	CWnd* m_pParent;
	int m_bAcceptFocus;
	int m_bEnabled;
	int m_bShown;
};

static_assert_size(sizeof(CCtrlWnd), 0x34);