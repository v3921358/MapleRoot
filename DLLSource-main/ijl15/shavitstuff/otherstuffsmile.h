#include "../Global.h"
#include <com.h>

#define member_at(T, offset, name) auto& name() { return *reinterpret_cast<T*>(reinterpret_cast<uintptr_t>(this) + offset); }

DECLARE_INTERFACE_IID_(IWzVector2D, IUnknown, "F28BD1ED-3DEB-4F92-9EEC-10EF5A1C3FB4")
{
	BEGIN_INTERFACE;

	STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;
	STDMETHOD(get_persistentUOL)(THIS_ wchar_t**) PURE;
	STDMETHOD(raw_Serialize)(THIS_ uintptr_t*) PURE;
	STDMETHOD(get_item)(THIS_ tagVARIANT, tagVARIANT*) PURE;
	STDMETHOD(get__NewEnum)(THIS_ IUnknown**) PURE;
	STDMETHOD(get_count)(THIS_ unsigned int*) PURE;
	STDMETHOD(get_x)(THIS_ int*) PURE;
	STDMETHOD(put_x)(THIS_ int) PURE;
	STDMETHOD(get_y)(THIS_ int*) PURE;
	STDMETHOD(put_y)(THIS_ int) PURE;
	STDMETHOD(get_x2)(THIS_ int*) PURE;
	STDMETHOD(put_x2)(THIS_ int) PURE;
	STDMETHOD(get_y2)(THIS_ int*) PURE;
	STDMETHOD(put_y2)(THIS_ int) PURE;
	STDMETHOD(raw_Move)(THIS_ int, int) PURE;
	STDMETHOD(raw_Offset)(THIS_ int, int) PURE;
	STDMETHOD(raw_Scale)(THIS_ int, int, int, int, int, int) PURE;
	STDMETHOD(raw_Insert)(THIS_ tagVARIANT, tagVARIANT) PURE;
	STDMETHOD(raw_Remove)(THIS_ tagVARIANT, tagVARIANT*) PURE;
	STDMETHOD(raw_Init)(THIS_ int, int) PURE;
	STDMETHOD(get_currentTime)(THIS_ int*) PURE;
	STDMETHOD(put_currentTime)(THIS_ int) PURE;
	STDMETHOD(get_origin)(THIS_ tagVARIANT*) PURE;
	STDMETHOD(put_origin)(THIS_ tagVARIANT) PURE;
	STDMETHOD(get_rx)(THIS_ int*) PURE;
	STDMETHOD(put_rx)(THIS_ int) PURE;
	STDMETHOD(get_ry)(THIS_ int*) PURE;
	STDMETHOD(put_ry)(THIS_ int) PURE;
	STDMETHOD(get_a)(THIS_ long double*) PURE;
	STDMETHOD(get_ra)(THIS_ long double*) PURE;
	STDMETHOD(put_ra)(THIS_ long double) PURE;
	STDMETHOD(get_flipX)(THIS_ int*) PURE;
	STDMETHOD(put_flipX)(THIS_ int) PURE;
	STDMETHOD(raw__GetSnapshot)(THIS_ int*, int*, int*, int*, int*, int*, long double*, long double*, tagVARIANT) PURE;
	STDMETHOD(raw_RelMove)(THIS_ int nX, int nY, _variant_t nTime, _variant_t nType) PURE;
	STDMETHOD(raw_RelOffset)(THIS_ int, int, tagVARIANT, tagVARIANT) PURE;
	STDMETHOD(raw_Ratio)(THIS_ IWzVector2D*, int, int, int, int) PURE;
	STDMETHOD(raw_WrapClip)(THIS_ tagVARIANT, int, int, unsigned int, unsigned int, tagVARIANT) PURE;
	STDMETHOD(raw_Rotate)(THIS_ long double, tagVARIANT) PURE;
	STDMETHOD(get_looseLevel)(THIS_ unsigned int*) PURE;
	STDMETHOD(put_looseLevel)(THIS_ unsigned int) PURE;
	STDMETHOD(raw_Fly)(THIS_ tagVARIANT*, int) PURE;

	int get_x()//
	{
		int x;
		this->get_x(&x);

		return x;
	}

	int get_y()
	{
		int y;
		this->get_y(&y);

		return y;
	}

	END_INTERFACE;
};

DECLARE_INTERFACE_IID_(IWzProperty, IUnknown, "986515D9-0A0B-4929-8B4F-718682177B92")
{
	BEGIN_INTERFACE;

	/*** IUnknown methods ***/
	STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppv) PURE;
	STDMETHOD_(ULONG, AddRef)(THIS) PURE;
	STDMETHOD_(ULONG, Release)(THIS) PURE;

	/*** IWzSerialize methods ***/
	STDMETHOD(get_persistentUOL)(THIS_ wchar_t**) PURE;
	STDMETHOD(raw_Serialize)(THIS_ uintptr_t*) PURE;

	/*** IWzProperty methods ***/
	STDMETHOD(get_item)(THIS_ const wchar_t* wsPath, _variant_t * result);
	STDMETHOD(put_item)(THIS_ const wchar_t* wsPath, _variant_t pItem);
	STDMETHOD(get__NewEnum)(THIS_ IUnknown**);
	STDMETHOD(get_count)(THIS_ unsigned int*);
	STDMETHOD(raw_Add)(THIS_ wchar_t*, tagVARIANT, tagVARIANT);
	STDMETHOD(raw_Remove)(THIS_ wchar_t*);
	STDMETHOD(raw_Import)(THIS_ wchar_t*);
	STDMETHOD(raw__GetHeadPosition)(THIS_ unsigned int**);
	STDMETHOD(raw__GetAt)(THIS_ unsigned int*, tagVARIANT*);
	STDMETHOD(raw__GetName)(THIS_ unsigned int*, wchar_t**);
	STDMETHOD(raw__GetNext)(THIS_ unsigned int**);

	template <typename T>
	T get_item(const wchar_t* wsPath)
	{
		_variant_t pItem(0);
		this->get_item(wsPath, &pItem);

		return reinterpret_cast<T>(pItem.ppunkVal);
	}

	END_INTERFACE;
};

class CAvatar;

class CUser
{
public:
	member_at(int, 0x570, m_nMoveAction);
	member_at(unsigned int, 0x11A8, m_dwCharacterId);

	CAvatar* GetAvatar();
	bool IsLeft();
};

class CUser;

class CAvatar
{
public:
	member_at(wil::com_ptr_t<IWzVector2D>, 0x10B8, m_pBodyOrigin);

	CUser* GetUser();
	unsigned int GetCharacterID();
};


CUser* CAvatar::GetUser()
{
	return reinterpret_cast<CUser*>(reinterpret_cast<uintptr_t>(this) - 0x88);
}

unsigned int CAvatar::GetCharacterID()
{
	return this->GetUser()->m_dwCharacterId();
}


CAvatar* CUser::GetAvatar()
{
	return reinterpret_cast<CAvatar*>(reinterpret_cast<uintptr_t>(this) + 0x88);
}

bool CUser::IsLeft()
{
	return (this->m_nMoveAction() & 1) > 0;
}
