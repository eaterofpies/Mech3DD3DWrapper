
#include "Unknown.h"
#include "DirectDrawSurface4.h"
#include "DirectDraw4.h"

//dd4 function pointer types
STDDDTYPEDEF(DD4, QueryInterface, IDirectDraw4* dd, REFIID riid, void** ppvObject);
DDTYPEDEF(ULONG, DD4, AddRef, IDirectDraw4* dd);
DDTYPEDEF(ULONG, DD4, Release, IDirectDraw4* dd);
STDDDTYPEDEF(DD4, Compact, IDirectDraw4* dd);
STDDDTYPEDEF(DD4, CreateClipper, IDirectDraw4* dd, DWORD flags, IDirectDrawClipper **clipper, IUnknown *outer);
STDDDTYPEDEF(DD4, CreatePalette, IDirectDraw4* dd, DWORD flags, PALETTEENTRY *color_table,
        IDirectDrawPalette **palette, IUnknown *outer);
STDDDTYPEDEF(DD4, CreateSurface, IDirectDraw4* dd, DDSURFACEDESC2 *surface_desc,
        struct IDirectDrawSurface4 **surface, IUnknown *outer);
STDDDTYPEDEF(DD4, DuplicateSurface, IDirectDraw4* dd, struct IDirectDrawSurface4 *src_surface,
        struct IDirectDrawSurface4 **dst_surface);
STDDDTYPEDEF(DD4, EnumDisplayModes, IDirectDraw4* dd, DWORD flags, DDSURFACEDESC2 *surface_desc,
        void *ctx, LPDDENUMMODESCALLBACK2 cb);
STDDDTYPEDEF(DD4, EnumSurfaces, IDirectDraw4* dd, DWORD flags, DDSURFACEDESC2 *surface_desc,
        void *ctx, LPDDENUMSURFACESCALLBACK2 cb);
STDDDTYPEDEF(DD4, FlipToGDISurface, IDirectDraw4* dd);
STDDDTYPEDEF(DD4, GetCaps, IDirectDraw4* dd, DDCAPS *driver_caps, DDCAPS *hel_caps);
STDDDTYPEDEF(DD4, GetDisplayMode, IDirectDraw4* dd, DDSURFACEDESC2 *surface_desc);
STDDDTYPEDEF(DD4, GetFourCCCodes, IDirectDraw4* dd, LPDWORD lpNumCodes, LPDWORD lpCodes);
STDDDTYPEDEF(DD4, GetGDISurface, IDirectDraw4* dd, struct IDirectDrawSurface4 **surface);
STDDDTYPEDEF(DD4, GetMonitorFrequency, IDirectDraw4* dd, LPDWORD lpdwFrequency);
STDDDTYPEDEF(DD4, GetScanLine, IDirectDraw4* dd, LPDWORD lpdwScanLine);
STDDDTYPEDEF(DD4, GetVerticalBlankStatus, IDirectDraw4* dd, BOOL *lpbIsInVB);
STDDDTYPEDEF(DD4, Initialize, IDirectDraw4* dd, GUID *lpGUID);
STDDDTYPEDEF(DD4, RestoreDisplayMode, IDirectDraw4* dd);
STDDDTYPEDEF(DD4, SetCooperativeLevel, IDirectDraw4* dd, HWND hWnd, DWORD dwFlags);
STDDDTYPEDEF(DD4, SetDisplayMode, IDirectDraw4* dd, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP, DWORD dwRefreshRate, DWORD dwFlags);
STDDDTYPEDEF(DD4, WaitForVerticalBlank, IDirectDraw4* dd, DWORD dwFlags, HANDLE hEvent);
STDDDTYPEDEF(DD4, GetAvailableVidMem, IDirectDraw4* dd, DDSCAPS2 *caps, DWORD *total, DWORD *free);
STDDDTYPEDEF(DD4, GetSurfaceFromDC, IDirectDraw4* dd, HDC dc, struct IDirectDrawSurface4 **surface);
STDDDTYPEDEF(DD4, RestoreAllSurfaces, IDirectDraw4* dd);
STDDDTYPEDEF(DD4, TestCooperativeLevel, IDirectDraw4* dd);
STDDDTYPEDEF(DD4, GetDeviceIdentifier, IDirectDraw4* dd, DDDEVICEIDENTIFIER *identifier, DWORD flags);

typedef struct DD4
{
    IDirectDraw4Vtbl* lpVtbl;
    IDirectDraw4* real;
} DD4;

//STDDDSTUB(DD4, QueryInterface, IDirectDraw4* dd, REFIID riid, void** ppvObject);
DDSTUB(ULONG, DD4, AddRef, IDirectDraw4* dd);
//DDSTUB(ULONG, DD4, Release, IDirectDraw4* dd);
STDDDSTUB(DD4, Compact, IDirectDraw4* dd);
//STDDDSTUB(DD4, CreateClipper, IDirectDraw4* dd, DWORD flags, IDirectDrawClipper **clipper, IUnknown *outer);
STDDDSTUB(DD4, CreatePalette, IDirectDraw4* dd, DWORD flags, PALETTEENTRY *color_table,
        IDirectDrawPalette **palette, IUnknown *outer);
//STDDDSTUB(DD4, CreateSurface, IDirectDraw4* dd, DDSURFACEDESC2 *surface_desc,
//      struct IDirectDrawSurface4 **surface, IUnknown *outer);
STDDDSTUB(DD4, DuplicateSurface, IDirectDraw4* dd, struct IDirectDrawSurface4 *src_surface,
        struct IDirectDrawSurface4 **dst_surface);
//STDDDSTUB(DD4, EnumDisplayModes, IDirectDraw4* dd, DWORD flags, DDSURFACEDESC2 *surface_desc,
//        void *ctx, LPDDENUMMODESCALLBACK2 cb);
STDDDSTUB(DD4, EnumSurfaces, IDirectDraw4* dd, DWORD flags, DDSURFACEDESC2 *surface_desc,
        void *ctx, LPDDENUMSURFACESCALLBACK2 cb);
STDDDSTUB(DD4, FlipToGDISurface, IDirectDraw4* dd);
//STDDDSTUB(DD4, GetCaps, IDirectDraw4* dd, DDCAPS *driver_caps, DDCAPS *hel_caps);
STDDDSTUB(DD4, GetDisplayMode, IDirectDraw4* dd, DDSURFACEDESC2 *surface_desc);
STDDDSTUB(DD4, GetFourCCCodes, IDirectDraw4* dd, LPDWORD lpNumCodes, LPDWORD lpCodes);
STDDDSTUB(DD4, GetGDISurface, IDirectDraw4* dd, struct IDirectDrawSurface4 **surface);
STDDDSTUB(DD4, GetMonitorFrequency, IDirectDraw4* dd, LPDWORD lpdwFrequency);
STDDDSTUB(DD4, GetScanLine, IDirectDraw4* dd, LPDWORD lpdwScanLine);
STDDDSTUB(DD4, GetVerticalBlankStatus, IDirectDraw4* dd, BOOL *lpbIsInVB);
STDDDSTUB(DD4, Initialize, IDirectDraw4* dd, GUID *lpGUID);
//STDDDSTUB(DD4, RestoreDisplayMode, IDirectDraw4* dd);
//STDDDSTUB(DD4, SetCooperativeLevel, IDirectDraw4* dd, HWND hWnd, DWORD dwFlags);
//STDDDSTUB(DD4, SetDisplayMode, IDirectDraw4* dd, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP, DWORD dwRefreshRate, DWORD dwFlags);
STDDDSTUB(DD4, WaitForVerticalBlank, IDirectDraw4* dd, DWORD dwFlags, HANDLE hEvent);
//STDDDSTUB(DD4, GetAvailableVidMem, IDirectDraw4* dd, DDSCAPS2 *caps, DWORD *total, DWORD *free);
STDDDSTUB(DD4, GetSurfaceFromDC, IDirectDraw4* dd, HDC dc, struct IDirectDrawSurface4 **surface);
STDDDSTUB(DD4, RestoreAllSurfaces, IDirectDraw4* dd);
STDDDSTUB(DD4, TestCooperativeLevel, IDirectDraw4* dd);
STDDDSTUB(DD4, GetDeviceIdentifier, IDirectDraw4* dd, DDDEVICEIDENTIFIER *identifier, DWORD flags);

HRESULT STDMETHODCALLTYPE DD4QueryInterface(DD4* dd, REFIID riid, void** ppvObject)
{
    DPRINTF("trace");
    return IUNKQueryInterface(dd, riid, ppvObject);
}

ULONG STDMETHODCALLTYPE DD4Release(DD4* dd)
{
    DPRINTF("trace");
    return IUNKRelease(dd);
}

HRESULT STDMETHODCALLTYPE DD4CreateClipper(DD4* dd, DWORD flags, IDirectDrawClipper **clipper, IUnknown *outer)
{
    DPRINTF("trace");
    return dd->real->lpVtbl->CreateClipper(dd->real, flags, clipper, outer);
}

HRESULT STDMETHODCALLTYPE DD4CreateSurface(DD4* dd, DDSURFACEDESC2 *surface_desc,
        struct IDirectDrawSurface4 **surface, IUnknown *outer)
{
    DPRINTF("pixel format flags %x", surface_desc->ddpfPixelFormat.dwFlags);
    HRESULT rc =  dd->real->lpVtbl->CreateSurface(dd->real, surface_desc, surface, outer);

	if(rc != DD_OK)
	{
		ABORT();
	}

    (*surface) = IDDS4Create(*surface);
    return rc;
}

typedef struct EnumDisplayModesCTX
{
        LPDDENUMMODESCALLBACK2 originalCB;
        void* realCTX;
} EnumDisplayModesCTX;

HRESULT EnumDisplayModesCallback(DDSURFACEDESC2* desc, void* ctxIn)
{
    DPRINTF("trace\nwidth: %d\nheight: %d\nflags: %x",desc->dwWidth, desc->dwHeight, desc->dwFlags);
    EnumDisplayModesCTX* ctx = ctxIn;
    return ctx->originalCB(desc, ctx->realCTX);
}

HRESULT STDMETHODCALLTYPE DD4EnumDisplayModes(DD4* dd, DWORD flags, DDSURFACEDESC2 *surface_desc,
        void *realCTX, LPDDENUMMODESCALLBACK2 cb)
{
    EnumDisplayModesCTX ctx;
    ctx.realCTX = realCTX;
    ctx.originalCB = cb;
    DPRINTF("trace");
    return dd->real->lpVtbl->EnumDisplayModes(dd->real, flags, surface_desc, &ctx, &EnumDisplayModesCallback);
}
HRESULT STDMETHODCALLTYPE DD4GetCaps(DD4* dd, DDCAPS *driver_caps, DDCAPS *hel_caps)
{
    DPRINTF("trace");
    return dd->real->lpVtbl->GetCaps(dd->real, driver_caps, hel_caps);
}

HRESULT STDMETHODCALLTYPE DD4RestoreDisplayMode(DD4* dd)
{
    DPRINTF("trace");
    return dd->real->lpVtbl->RestoreDisplayMode(dd->real);
}

HRESULT STDMETHODCALLTYPE DD4SetCooperativeLevel(DD4* dd, HWND hWnd, DWORD dwFlags)
{
    //MUST NOT MODIFY FLAGS
    //if the flags arent correct the game thinks the video device doesn't exist
    DPRINTF("flags %x", DDSCL_NORMAL/*dwFlags*/ );
    return dd->real->lpVtbl->SetCooperativeLevel(dd->real, hWnd, dwFlags );
}


HRESULT STDMETHODCALLTYPE DD4SetDisplayMode(DD4* dd, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP, DWORD dwRefreshRate, DWORD dwFlags)
{
    DPRINTF(" width: %d\n height: %d\n BPP: %d\n refresh rate: %d\nflags:%x\n",
        dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags);
    return dd->real->lpVtbl->SetDisplayMode(dd->real, dwWidth, dwHeight, dwBPP, dwRefreshRate, dwFlags);
}


HRESULT STDMETHODCALLTYPE DD4GetAvailableVidMem(DD4* dd, DDSCAPS2 *caps, DWORD *total, DWORD *free)
{
    DPRINTF("trace");
    return dd->real->lpVtbl->GetAvailableVidMem(dd->real, caps, total, free);
}


IDirectDraw4Vtbl dd4Vtbl =
{
	DD4QueryInterface,
	DD4AddRef,
	DD4Release,
	DD4Compact,
	DD4CreateClipper,
	DD4CreatePalette,
	DD4CreateSurface,
	DD4DuplicateSurface,
	DD4EnumDisplayModes,
	DD4EnumSurfaces,
	DD4FlipToGDISurface,
	DD4GetCaps,
	DD4GetDisplayMode,
	DD4GetFourCCCodes,
	DD4GetGDISurface,
	DD4GetMonitorFrequency,
	DD4GetScanLine,
	DD4GetVerticalBlankStatus,
	DD4Initialize,
	DD4RestoreDisplayMode,
	DD4SetCooperativeLevel,
	DD4SetDisplayMode,
	DD4WaitForVerticalBlank,
	DD4GetAvailableVidMem,
	DD4GetSurfaceFromDC,
	DD4RestoreAllSurfaces,
	DD4TestCooperativeLevel,
	DD4GetDeviceIdentifier
};

IDirectDraw4* IDD4Query(IUNK* unk)
{
	IDirectDraw4* real;
	//get the real pointer
	if(unk->real->lpVtbl->QueryInterface(unk->real, &IID_IDirectDraw4, &real) != DD_OK)
	{
		DPRINTF("query interface failed with %d",DD_OK);
		ABORT();
	}

	DPRINTF("trace");

    DD4* fakeDD4 = malloc(sizeof(DD4));
	fakeDD4->lpVtbl = &dd4Vtbl;
    fakeDD4->real = real;
    return fakeDD4;
}
