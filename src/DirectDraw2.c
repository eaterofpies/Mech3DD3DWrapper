
#include "Unknown.h"
#include "DirectDraw2.h"


typedef struct DD2
{
    IDirectDraw2Vtbl* lpVtbl;
    IDirectDraw2* real;
} DD2;

//dd2 stub functions that deliberately crash if used
STDDDSTUB(DD2, QueryInterface, IDirectDraw2* dd, REFIID riid, void** ppvObject);
DDSTUB(ULONG, DD2, AddRef, IDirectDraw2* dd);
//DDSTUB(ULONG, DD2, Release, IDirectDraw2* dd);
STDDDSTUB(DD2, Compact, IDirectDraw2* dd);
STDDDSTUB(DD2, CreateClipper, IDirectDraw2* dd, DWORD flags, IDirectDrawClipper **clipper, IUnknown *outer);
STDDDSTUB(DD2, CreatePalette, IDirectDraw2* dd, DWORD flags, PALETTEENTRY *color_table,
        IDirectDrawPalette **palette, IUnknown *outer);
STDDDSTUB(DD2, CreateSurface, IDirectDraw2* dd, DDSURFACEDESC *surface_desc,
        struct IDirectDrawSurface **surface, IUnknown *outer);
STDDDSTUB(DD2, DuplicateSurface, IDirectDraw2* dd, struct IDirectDrawSurface *src_surface,
        struct IDirectDrawSurface **dst_surface);
STDDDSTUB(DD2, EnumDisplayModes, IDirectDraw2* dd, DWORD flags, DDSURFACEDESC *surface_desc,
        void *ctx, LPDDENUMMODESCALLBACK cb);
STDDDSTUB(DD2, EnumSurfaces, IDirectDraw2* dd, DWORD flags, DDSURFACEDESC *surface_desc,
        void *ctx, LPDDENUMSURFACESCALLBACK cb);
STDDDSTUB(DD2, FlipToGDISurface, IDirectDraw2* dd);
STDDDSTUB(DD2, GetCaps, IDirectDraw2* dd, DDCAPS *driver_caps, DDCAPS *hel_caps);
STDDDSTUB(DD2, GetDisplayMode, IDirectDraw2* dd, DDSURFACEDESC *surface_desc);
STDDDSTUB(DD2, GetFourCCCodes, IDirectDraw2* dd, LPDWORD lpNumCodes, LPDWORD lpCodes);
STDDDSTUB(DD2, GetGDISurface, IDirectDraw2* dd, struct IDirectDrawSurface **surface);
STDDDSTUB(DD2, GetMonitorFrequency, IDirectDraw2* dd, LPDWORD lpdwFrequency);
STDDDSTUB(DD2, GetScanLine, IDirectDraw2* dd, LPDWORD lpdwScanLine);
STDDDSTUB(DD2, GetVerticalBlankStatus, IDirectDraw2* dd, BOOL *lpbIsInVB);
STDDDSTUB(DD2, Initialize, IDirectDraw2* dd, GUID *lpGUID);
STDDDSTUB(DD2, RestoreDisplayMode, IDirectDraw2* dd);
STDDDSTUB(DD2, SetCooperativeLevel, IDirectDraw2* dd, HWND hWnd, DWORD dwFlags);
STDDDSTUB(DD2, SetDisplayMode, IDirectDraw2* dd, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP, DWORD dwRefreshRate, DWORD dwFlags);
STDDDSTUB(DD2, WaitForVerticalBlank, IDirectDraw2* dd, DWORD dwFlags, HANDLE hEvent);
STDDDSTUB(DD2, GetAvailableVidMem, IDirectDraw2* dd, DDSCAPS *caps, DWORD *total, DWORD *free);

//extern void* fakeDD;

ULONG STDMETHODCALLTYPE DD2Release(DD2* dd)
{
    DPRINTF("trace");
    return IUNKRelease(dd);
}

IDirectDraw2Vtbl dd2Vtbl =
{
	DD2QueryInterface,
	DD2AddRef,
	DD2Release,
	DD2Compact,
	DD2CreateClipper,
	DD2CreatePalette,
	DD2CreateSurface,
	DD2DuplicateSurface,
	DD2EnumDisplayModes,
	DD2EnumSurfaces,
	DD2FlipToGDISurface,
	DD2GetCaps,
	DD2GetDisplayMode,
	DD2GetFourCCCodes,
	DD2GetGDISurface,
	DD2GetMonitorFrequency,
	DD2GetScanLine,
	DD2GetVerticalBlankStatus,
	DD2Initialize,
	DD2RestoreDisplayMode,
	DD2SetCooperativeLevel,
	DD2SetDisplayMode,
	DD2WaitForVerticalBlank,
	DD2GetAvailableVidMem
};

//Initialise ddraw structure
void IDD2Init(IDirectDraw2** dd)
{
	DPRINTF("trace");

	//TODO currently not freed
    DD2* fakeDD2 = malloc(sizeof(DD2));
	fakeDD2->lpVtbl = &dd2Vtbl;
    fakeDD2->real = *dd;

    *dd = fakeDD2;
}
