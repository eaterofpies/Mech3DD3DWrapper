
#include "DirectDraw.h"
#include "DirectDraw2.h"
#include "DirectDraw4.h"
#include "DirectDrawSurface3.h"
#include "Direct3D3.h"
#include "Unknown.h"


//functions actually used in the game
HRESULT STDMETHODCALLTYPE IUNKQueryInterface(IUNK* unk, const IID* const riid, void** ppvObject)
{
    DPRINTF("trace\nthis %x\nriid = %x", unk, *riid);

    if(IsEqualIID(riid, &IID_IDirectDraw2))
    {
        DPRINTF("Requested IDirectDraw2",DD_OK);
        (*ppvObject) = IDD2Query(unk);
        return DD_OK;
    }

    if(IsEqualIID(riid, &IID_IDirectDraw4))
    {
        DPRINTF("Requested IDirectDraw4");
        (*ppvObject) = IDD4Query(unk);
        return DD_OK;
	}

	if(IsEqualIID(riid, &IID_IDirect3D3))
	{
        DPRINTF("Requested IDirect3D3",DD_OK);
        (*ppvObject) = ID3D3Query(unk);
        return DD_OK;
	}

	if(IsEqualIID(riid, &IID_IDirectDrawSurface4))
	{
        DPRINTF("Requested IDirectDrawSurface4",DD_OK);
        (*ppvObject) = IDDS4Query(unk);
        return DD_OK;
	}

	//DDraw surfaces can be converted into textures
	if(IsEqualIID(riid, &IID_IDirectDrawSurface3))
	{
        DPRINTF("Requested IDirectDrawSurface3",DD_OK);
		//Just give it the real interface for now
		return IDDS3Query(unk);
	}

	//DDraw surfaces can be converted into textures
	if(IsEqualIID(riid, &IID_IDirect3DTexture2))
	{
        DPRINTF("Requested IDirect3DTexture2",DD_OK);
		//Just give it the real interface for now
		return unk->real->lpVtbl->QueryInterface(unk->real, riid, ppvObject);
	}


	DPRINTF("refiid: %x unsupported API not hooked\n", *riid);
    ABORT();
}


ULONG STDMETHODCALLTYPE IUNKRelease(IUNK* dd)
{
    DPRINTF("trace\nthis %x", dd);
    ULONG count = dd->real->lpVtbl->Release(dd->real);

	if (count == 0)
	{
		free(dd);
	}

    return count;
}

ULONG STDMETHODCALLTYPE IUNKAddRef(IUNK* dd)
{
    DPRINTF("trace");
    return dd->real->lpVtbl->AddRef(dd->real);
}
