#pragma once
#include "../Type/Assert.h"
#include "Msg/IGObj.h"
#include "Msg/IUIMsgHandler.h"
#include "../Type/ZRef.h"
#include "../Type/SECPOINT.h"
#include "../WZ/Com_IWzCanvas.h"

class CWnd : IGObj, IUIMsgHandler, ZRefCounted
{
	enum UIOrigin
	{
		Origin_LT = 0x0,
		Origin_CT = 0x1,
		Origin_RT = 0x2,
		Origin_LC = 0x3,
		Origin_CC = 0x4,
		Origin_RC = 0x5,
		Origin_LB = 0x6,
		Origin_CB = 0x7,
		Origin_RB = 0x8,
		Origin_NUM = 0x9,
	};
public:
	unsigned int m_dwWndKey;
	Com_Gr2DLayer m_pLayer;
	Com_Gr2DLayer m_pAnimationLayer;
	Com_Gr2DLayer m_pOverlabLayer;
	int m_width;
	int m_height;
	tagRECT m_rcInvalidated;
	int m_bScreenCoord;
	int m_nBackgrndX;
	int m_nBackgrndY;
	SECPOINT m_ptCursorRel;
	ZList<ZRef<CCtrlWnd> > m_lpChildren;
	CCtrlWnd* m_pFocusChild;
	Com_IWzCanvas m_pBackgrnd;
	CWnd::UIOrigin m_origin;
private:
};

static_assert_size(sizeof(CWnd), 0x80);