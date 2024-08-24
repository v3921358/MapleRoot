#pragma once

struct __cppobj CDialog : CWnd
{
	int m_nRet;
	int m_bTerminate;
	ZRef<CDialog> m_pChildModal;
};