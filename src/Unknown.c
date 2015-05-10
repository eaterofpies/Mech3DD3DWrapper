
#include "DirectDraw.h"
#include "DirectDraw2.h"
#include "DirectDraw4.h"
#include "Direct3D3.h"
#include "Unknown.h"


//functions actually used in the game
HRESULT STDMETHODCALLTYPE IUNKQueryInterface(IUNK* dd, const IID* const riid, void** ppvObject)
{
    DPRINTF("trace\nriid = %x", *riid);

	//get the real pointer
	if(dd->real->lpVtbl->QueryInterface(dd->real, riid, ppvObject) != DD_OK)
	{
		DPRINTF("query interface failed with %d",DD_OK);
		ABORT();
	}

    if(IsEqualIID(riid, &IID_IDirectDraw2))
    {
        DPRINTF("Requested IDirectDraw2",DD_OK);
        IDD2Init((IDirectDraw2**)ppvObject);
        return DD_OK;
    }

    if(IsEqualIID(riid, &IID_IDirectDraw4))
    {
        DPRINTF("Requested IDirectDraw4",DD_OK);
        IDD4Init((IDirectDraw4**)ppvObject);
        return DD_OK;
	}

	if(IsEqualIID(riid, &IID_IDirect3D3))
	{
        DPRINTF("Requested IDirect3D3",DD_OK);
	    ID3D3Init((IDirect3D3**)ppvObject);
        return DD_OK;
	}

	if(IsEqualIID(riid, &IID_IDirectDrawSurface4))
	{
        DPRINTF("Requested IDirectDrawSurface4",DD_OK);
	    IDDS4Init((IDirectDrawSurface4**)ppvObject);
        return DD_OK;
	}

	//DDraw surfaces can be converted into textures
	if(IsEqualIID(riid, &IID_IDirect3DTexture2))
	{
        DPRINTF("Requested IDirect3DTexture2",DD_OK);
	    //Just give it the real interface for now
	    return DD_OK;
	}


	DPRINTF("refiid: %x unsupported API not hooked\n", *riid);
    ABORT();
    return dd->real->lpVtbl->QueryInterface(dd->real, riid, ppvObject);
}


ULONG STDMETHODCALLTYPE IUNKRelease(IUNK* dd)
{
    DPRINTF("trace");
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
    //TODO delete allocated space on release
    return dd->real->lpVtbl->AddRef(dd->real);
}
