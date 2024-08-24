//#include "CWndMan.h"
//#include "../../../Funcs.h"
//#include "../../../CAdminMan.h"
//#include <WinUser.h>
//
//typedef int(__fastcall* CWndMan__TranslateMessage_t)(CWndMan* pThis, void* ecx, unsigned int* message, unsigned int* wParam, int* lParam, int* plResult);
//static auto CWndMan__TranslateMessage = reinterpret_cast<CWndMan__TranslateMessage_t>(0x009B5360);
//
//int __fastcall _TranslateMessage(CWndMan* pThis, void* ecx, unsigned int* message, unsigned int* wParam, int* lParam, int* plResult)
//{
//	if (*message != 0x0100 && *message != 0x0104)
//		return CWndMan__TranslateMessage(pThis, ecx, message, wParam, lParam, plResult);
//
//	if (!CAdminMan::get().KeyHandler(*wParam, *lParam))
//		return CWndMan__TranslateMessage(pThis, ecx, message, wParam, lParam, plResult);
//
//	return CWndMan__TranslateMessage(pThis, ecx, message, wParam, lParam, plResult);
//}
//
//void CWndMan::StartHooks()
//{
//	SetHook(true, reinterpret_cast<void**>(&CWndMan__TranslateMessage), _TranslateMessage);
//}
