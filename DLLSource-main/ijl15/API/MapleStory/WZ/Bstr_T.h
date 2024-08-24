//#include <OAIdl.h>
//#include <memory>
//#include <string>
//#include <map>
//#include <algorithm>
//
//typedef int(__stdcall* IWzGr2D__GetLayer_t)(DWORD*, VARIANTARG, DWORD**);
//typedef int(__stdcall* IWzVector2D__RelMove_t)(DWORD*, int, int, VARIANTARG, VARIANTARG);
//typedef int(__stdcall* IWzCanvas_PutCXY_t)(DWORD*, int);
//typedef void(__thiscall* _CCtrlButton__SetEnable)(DWORD*, void*, int);
//
//#define IWzGr2DLayer__Getcanvas(x, r) (*(IWzGr2D__GetLayer_t*)(*(DWORD*)(x) + 256))((DWORD *)x, pvarg, r)
//#define IWzVector2D__RelMove(x, l, t) (*(IWzVector2D__RelMove_t*)(*(DWORD*)(x) + 144))((DWORD *)x, l, t, errorVar, errorVar)
//#define GET_IWzVector2D(x) (sp[x][6])
//#define CCtrlButton__SetEnable(x, nEnable) (*(_CCtrlButton__SetEnable*)(*(*(*((DWORD***)(x)) + 4) + 28)))(*((DWORD**)(x)) + 4, nullptr, nEnable);
//
//typedef int* (__fastcall* _CWnd__CreateWnd)(DWORD* This, void* notuse, int nLeft, int nTop,
//    int nWidth, int nHeight, int z, int bScreenCoord, DWORD* pData, int bSetFocus);
//
//typedef int(__fastcall* _bstr_constructor)(void* ecx, void* edx, const char* str);
//typedef int(__fastcall* _bstr_constructor_wchar)(void* ecx, void* edx, const wchar_t* str);
//typedef int(__fastcall* _bstr_release)(void* ecx, void* edx);
//typedef DWORD* (__fastcall* _ZXString_char_constructor)(void* ecx, void* edx, const char*, size_t);
//
//typedef int(__fastcall* _IWzProperty_QueryInterface)(IUnknown** This, void* notuse, IUnknown* a2);
//typedef DWORD(__fastcall* _Ztl_variant_t__GetUnknown)(VARIANTARG* This, void* notuse, bool a2, bool a3);
//typedef DWORD(__fastcall* _IWzCanvas__GetProperty)(DWORD* This, void* notuse, IUnknown** a2);
//typedef VARIANTARG* (__fastcall* _IWzProperty__GetItem)(IUnknown* This, void* notuse, VARIANTARG* pvargDest, int* sPath);
//typedef int(__fastcall* _IWzUOL__GetfilePath)(DWORD* This, void* notuse, int a2);
//typedef IUnknown* (__fastcall* _IWzUOL_QueryInterface)(DWORD* This, void* notuse, IUnknown* a2);
//typedef VARIANTARG* (__fastcall* _IWzResMan__GetObjectA)(DWORD* This, void* notuse, VARIANTARG* pvargDest, int* sUOL, int vParam, int vAux);
//typedef DWORD* (__cdecl* _get_unknown)(DWORD*, VARIANT*);
//typedef int(__fastcall* _IWzCanvas_operator_equal)(DWORD* This, void* notuse, DWORD* a2);
//typedef int(__fastcall* _CWndMan__EnableIME)(DWORD* This, void* notuse, int bEnable);
//typedef void(__fastcall* _CCtrlEdit__SetText)(DWORD* This, void* notuse, char* a2);
//typedef void(__fastcall* _CWvsApp__CreateMainWindow)(DWORD* This, void* notuse);
//typedef int(__fastcall* _IWzCanvas__Getwidth)(DWORD* This, void* notuse);
//typedef int(__fastcall* _IWzCanvas__Getheight)(DWORD* This, void* notuse);
//typedef DWORD* (__fastcall* _IWzCanvas__DrawTextA)(DWORD* This, void* notuse, int nLeft, int nTop, int* sText, int pFont, DWORD* vAlpha, DWORD* vTabOrg);
//
//VARIANTARG errorVar = { VT_ERROR, 0, 0, 0x80020004 };
//VARIANTARG pvarg = { VT_I4, 0, 0, 0 };
//VARIANTARG pvargSrc = { 0 };
//
//_CWnd__CreateWnd CWnd__CreateWnd = (_CWnd__CreateWnd)0x9DE4D2;
//
//_bstr_constructor bstr_constructor = (_bstr_constructor)0x406301;
//_bstr_constructor_wchar bstr_constructor_wchar = (_bstr_constructor_wchar)0x402BE8;
//_bstr_release bstr_release = (_bstr_release)0x402EA5;
//_ZXString_char_constructor ZXString_char_constructor = (_ZXString_char_constructor)0x428DB3;
//
//_IWzProperty_QueryInterface IWzProperty_QueryInterface = (_IWzProperty_QueryInterface)0x4052AD;
//_Ztl_variant_t__GetUnknown Ztl_variant_t__GetUnknown = (_Ztl_variant_t__GetUnknown)0x4032B2;
//_IWzCanvas__GetProperty IWzCanvas__GetProperty = (_IWzCanvas__GetProperty)0x404AD7;
//_IWzProperty__GetItem IWzProperty__GetItem = (_IWzProperty__GetItem)0x403935;
//_IWzUOL__GetfilePath IWzUOL__GetfilePath = (_IWzUOL__GetfilePath)0x414C70;
//_IWzUOL_QueryInterface IWzUOL_QueryInterface = (_IWzUOL_QueryInterface)0x416838;
//_IWzResMan__GetObjectA IWzResMan__GetObjectA = (_IWzResMan__GetObjectA)0x403A93;
//
//_get_unknown get_unknown = (_get_unknown)0x414ADA;
//_IWzCanvas_operator_equal IWzCanvas_operator_equal = (_IWzCanvas_operator_equal)0x41E42B;
//
//_CWndMan__EnableIME CWndMan__EnableIME = (_CWndMan__EnableIME)0x9E85F3;
//_CCtrlEdit__SetText CCtrlEdit__SetText = (_CCtrlEdit__SetText)0x4CC512;
//
//_CWvsApp__CreateMainWindow CWvsApp__CreateMainWindow = (_CWvsApp__CreateMainWindow)0x9F6D97;
//
//_IWzCanvas__Getwidth IWzCanvas__Getwidth = (_IWzCanvas__Getwidth)0x40B920;
//_IWzCanvas__Getheight IWzCanvas__Getheight = (_IWzCanvas__Getheight)0x40B947;
//_IWzCanvas__DrawTextA IWzCanvas__DrawTextA = (_IWzCanvas__DrawTextA)0x4277AD;
//
//void** g_gr = (void**)0xBF14EC;
//void** g_rm = (void**)0xBF14E8;
//void** g_wvsapp = (void**)0xBE7B38;
//void** g_wndman = (void**)0xBEC20C;
//void** g_uistatusbar = (void**)0xBEC208;
//void** g_actionman = (void**)0xBE78D4;
//
//
//DWORD* GetCWvsAppInstance()
//{
//    return (DWORD*)*g_wvsapp;
//}
//
//HWND GetMapleMainWindow()
//{
//    return (HWND) * (GetCWvsAppInstance() + 1);
//}
//
//DWORD* GetGr2DInstance()
//{
//    return (DWORD*)*g_gr;
//}
//
//DWORD* GetCWndManInstance()
//{
//    return (DWORD*)*g_wndman;
//}
//
//DWORD* GetUIStatusBarInstance()
//{
//    return (DWORD*)*g_uistatusbar;
//}
//
//DWORD* GetResManInstance()
//{
//    return (DWORD*)*g_rm;
//}
//
//
//DWORD* GetActionManInstance()
//{
//    return (DWORD*)*g_actionman;
//}
//
//std::map<IUnknown*, std::shared_ptr<std::wstring>> gMapImgPath;
//void* GetUOLProperty(VARIANT* prop, void** result)
//{
//    if (prop == NULL || result == NULL)
//        return NULL;
//    IUnknown* pUnk = (IUnknown*)Ztl_variant_t__GetUnknown(prop, nullptr, 0, 0);
//    if (pUnk)
//    {
//        pUnk->AddRef();
//        IUnknown* pWzUOL = NULL;
//
//        IWzUOL_QueryInterface((DWORD*)&pWzUOL, nullptr, (IUnknown*)&pUnk);
//
//        if (pWzUOL)
//        {
//            IWzUOL__GetfilePath((DWORD*)pWzUOL, nullptr, (int)result);
//            if (*result)
//                return *result;
//        }
//    }
//    return NULL;
//}
//
//std::wstring GetImgFullPath(std::wstring strT)
//{
//    std::wstring lstr = strT;
//    std::transform(lstr.begin(), lstr.end(), lstr.begin(), towlower);
//
//    int pos = lstr.rfind(L".img");
//    if (pos != std::string::npos)
//    {
//        pos += 4; // 4
//        strT = strT.substr(0, pos);
//        strT += L"/";
//    }
//    return strT;
//}
//
//DWORD GetCanvasPropertyByPath(std::wstring path, DWORD* result)
//{
//    VARIANT varDest = { 0 };
//    VARIANT var1 = { 0 };
//    VARIANT var2 = { 0 };
//    DWORD varUnk = 0;
//    void* sUol = NULL;
//    bstr_constructor_wchar(&sUol, nullptr, path.c_str());
//    auto v9 = IWzResMan__GetObjectA((DWORD*)*g_rm, nullptr, &varDest, (int*)sUol, (int)&var1, (int)&var2);
//    auto v10 = get_unknown(&varUnk, v9);
//    return IWzCanvas_operator_equal(result, nullptr, v10);
//}
//
//int __fastcall IWzCanvas_operator_equal_Hook(DWORD* This, void* notuse, DWORD* a2)
//{
//    auto ret = IWzCanvas_operator_equal(This, nullptr, a2);
//    IUnknown* prop = NULL;
//    void* pStrInlink = NULL;
//    void* pStrOutlink = NULL;
//    VARIANT dst = { 0 };
//    int w = 0, h = 0;
//    if (!*This)
//        goto RET;
//
//    w = IWzCanvas__Getwidth((DWORD*)*This, nullptr);
//    h = IWzCanvas__Getheight((DWORD*)*This, nullptr);
//
//    if (w > 1 || h > 1)
//        goto RET;
//
//    IWzCanvas__GetProperty((DWORD*)*This, nullptr, &prop);
//
//    if (!prop)
//        goto RET;
//
//    bstr_constructor(&pStrInlink, nullptr, "_inlink");
//
//    if (!pStrInlink)
//        goto OUTLINK;
//
//    IWzProperty__GetItem(prop, nullptr, &dst, (int*)pStrInlink);
//
//    if (!dst.vt)
//        goto OUTLINK;
//
//    if (dst.vt == VT_BSTR)
//    {
//        void* link = NULL;
//        if (dst.bstrVal)
//        {
//            IUnknown* pUnk = (IUnknown*)*a2;
//
//            if (gMapImgPath.find(pUnk) != gMapImgPath.end())
//            {
//                //LOGI("_inlink: %S, FullPath: %S", dst.bstrVal, gMapImgPath[pUnk]->c_str());
//                DWORD ptr = 0;
//                ret = GetCanvasPropertyByPath(GetImgFullPath(gMapImgPath[pUnk]->c_str()) + dst.bstrVal, (DWORD*)&ptr);
//                if (ptr)
//                    *This = ptr;
//            }
//        }
//    }
//
//OUTLINK:
//    bstr_constructor(&pStrOutlink, nullptr, "_outlink");
//    IWzProperty__GetItem(prop, nullptr, &dst, (int*)pStrOutlink);
//
//    if (!dst.vt)
//        goto RET;
//
//    if (dst.vt == VT_BSTR)
//    {
//        void* link = NULL;
//        if (dst.bstrVal)
//        {
//            DWORD ptr = 0;
//            ret = GetCanvasPropertyByPath(dst.bstrVal, (DWORD*)&ptr);
//            if (ptr)
//                *This = ptr;
//        }
//    }
//
//
//RET:
//    if (prop)
//        ((IUnknown*)prop)->Release();
//    return ret;
//};
//
//VARIANTARG* __fastcall IWzResMan__GetObjectA_Hook(DWORD* This, void* notuse, VARIANTARG* pvargDest, int* sUOL, int vParam, int vAux)
//{
//    std::wstring strT = (wchar_t*)*sUOL;
//    auto ret = IWzResMan__GetObjectA(This, nullptr, pvargDest, sUOL, vParam, vAux);
//    if (ret && ret->vt == VT_UNKNOWN)
//    {
//        gMapImgPath[ret->punkVal] = std::make_shared<std::wstring>(strT);
//    }
//    return ret;
//};
//
//VARIANTARG* __fastcall IWzProperty__GetItem_Hook(IUnknown* This, void* notuse, VARIANTARG* pvargDest, int* sPath)
//{
//    std::wstring strT = (wchar_t*)*sPath;
//    auto ret = IWzProperty__GetItem(This, nullptr, pvargDest, sPath);
//    if (pvargDest->vt == VT_UNKNOWN)
//    {
//        if (gMapImgPath.find(This) != gMapImgPath.end())
//        {
//            gMapImgPath[pvargDest->punkVal] = gMapImgPath[This];
//        }
//    }
//    void* sUOL = NULL;
//    GetUOLProperty(pvargDest, &sUOL);
//    if (sUOL)
//    {
//        VARIANTARG pvarg1 = errorVar;
//        VARIANTARG pvarg2 = errorVar;
//        ret = IWzResMan__GetObjectA(GetResManInstance(), nullptr, pvargDest, (int*)sUOL, (int)&pvarg1, (int)&pvarg2);
//    }
//    return ret;
//};
//
//void InitInlinkOutlink()
//{
//    SetHook(true, reinterpret_cast<void**>(&IWzProperty__GetItem), IWzProperty__GetItem_Hook);
//    SetHook(true, reinterpret_cast<void**>(&IWzResMan__GetObjectA), IWzResMan__GetObjectA_Hook);
//    SetHook(true, reinterpret_cast<void**>(&IWzCanvas_operator_equal), IWzCanvas_operator_equal_Hook);
//}