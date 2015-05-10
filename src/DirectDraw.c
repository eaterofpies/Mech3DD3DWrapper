
#include <stdint.h>

#include "Unknown.h"
#include "DirectDraw.h"


//Need to provide a IDirectDraw objects vtable


typedef struct DD1
{
    IDirectDrawVtbl* lpVtbl;
    IDirectDraw* real;
} DD1;

//dd function pointer types
STDDDTYPEDEF(IDD, QueryInterface, IDirectDraw* dd, REFIID riid, void** ppvObject);
DDTYPEDEF(ULONG, IDD, AddRef, IDirectDraw* dd);
DDTYPEDEF(ULONG, IDD, Release, IDirectDraw* dd);
STDDDTYPEDEF(IDD, Compact, IDirectDraw* dd);
STDDDTYPEDEF(IDD, CreateClipper, IDirectDraw* dd, DWORD flags, IDirectDrawClipper **clipper, IUnknown *outer);
STDDDTYPEDEF(IDD, CreatePalette, IDirectDraw* dd, DWORD flags, PALETTEENTRY *color_table,
        IDirectDrawPalette **palette, IUnknown *outer);
STDDDTYPEDEF(IDD, CreateSurface, IDirectDraw* dd, DDSURFACEDESC *surface_desc,
        struct IDirectDrawSurface **surface, IUnknown *outer);
STDDDTYPEDEF(IDD, DuplicateSurface, IDirectDraw* dd, struct IDirectDrawSurface *src_surface,
        struct IDirectDrawSurface **dst_surface);
STDDDTYPEDEF(IDD, EnumDisplayModes, IDirectDraw* dd, DWORD flags, DDSURFACEDESC *surface_desc,
        void *ctx, LPDDENUMMODESCALLBACK cb);
STDDDTYPEDEF(IDD, EnumSurfaces, IDirectDraw* dd, DWORD flags, DDSURFACEDESC *surface_desc,
        void *ctx, LPDDENUMSURFACESCALLBACK cb);
STDDDTYPEDEF(IDD, FlipToGDISurface, IDirectDraw* dd);
STDDDTYPEDEF(IDD, GetCaps, IDirectDraw* dd, DDCAPS *driver_caps, DDCAPS *hel_caps);
STDDDTYPEDEF(IDD, GetDisplayMode, IDirectDraw* dd, DDSURFACEDESC *surface_desc);
STDDDTYPEDEF(IDD, GetFourCCCodes, IDirectDraw* dd, LPDWORD lpNumCodes, LPDWORD lpCodes);
STDDDTYPEDEF(IDD, GetGDISurface, IDirectDraw* dd, struct IDirectDrawSurface **surface);
STDDDTYPEDEF(IDD, GetMonitorFrequency, IDirectDraw* dd, LPDWORD lpdwFrequency);
STDDDTYPEDEF(IDD, GetScanLine, IDirectDraw* dd, LPDWORD lpdwScanLine);
STDDDTYPEDEF(IDD, GetVerticalBlankStatus, IDirectDraw* dd, BOOL *lpbIsInVB);
STDDDTYPEDEF(IDD, Initialize, IDirectDraw* dd, GUID *lpGUID);
STDDDTYPEDEF(IDD, RestoreDisplayMode, IDirectDraw* dd);
STDDDTYPEDEF(IDD, SetCooperativeLevel, IDirectDraw* dd, HWND hWnd, DWORD dwFlags);
STDDDTYPEDEF(IDD, SetDisplayMode, IDirectDraw* dd, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP);
STDDDTYPEDEF(IDD, WaitForVerticalBlank, IDirectDraw* dd, DWORD dwFlags, HANDLE hEvent);

//dd function pointer types
//STDDDSTUB(IDD, QueryInterface, IDirectDraw* dd, REFIID riid, void** ppvObject);
DDSTUB(ULONG, DD1, AddRef, IDirectDraw* dd);
//DDSTUB(ULONG, DD1, Release, IDirectDraw* dd);
STDDDSTUB(DD1, Compact, IDirectDraw* dd);
STDDDSTUB(DD1, CreateClipper, IDirectDraw* dd, DWORD flags, IDirectDrawClipper **clipper, IUnknown *outer);
STDDDSTUB(DD1, CreatePalette, IDirectDraw* dd, DWORD flags, PALETTEENTRY *color_table,
        IDirectDrawPalette **palette, IUnknown *outer);
//STDDDSTUB(DD1, CreateSurface, IDirectDraw* dd, DDSURFACEDESC *surface_desc,
//        struct IDirectDrawSurface **surface, IUnknown *outer);
STDDDSTUB(DD1, DuplicateSurface, IDirectDraw* dd, struct IDirectDrawSurface *src_surface,
        struct IDirectDrawSurface **dst_surface);
STDDDSTUB(DD1, EnumDisplayModes, IDirectDraw* dd, DWORD flags, DDSURFACEDESC *surface_desc,
        void *ctx, LPDDENUMMODESCALLBACK cb);
STDDDSTUB(DD1, EnumSurfaces, IDirectDraw* dd, DWORD flags, DDSURFACEDESC *surface_desc,
        void *ctx, LPDDENUMSURFACESCALLBACK cb);
STDDDSTUB(DD1, FlipToGDISurface, IDirectDraw* dd);
STDDDSTUB(DD1, GetCaps, IDirectDraw* dd, DDCAPS *driver_caps, DDCAPS *hel_caps);
STDDDSTUB(DD1, GetDisplayMode, IDirectDraw* dd, DDSURFACEDESC *surface_desc);
STDDDSTUB(DD1, GetFourCCCodes, IDirectDraw* dd, LPDWORD lpNumCodes, LPDWORD lpCodes);
STDDDSTUB(DD1, GetGDISurface, IDirectDraw* dd, struct IDirectDrawSurface **surface);
STDDDSTUB(DD1, GetMonitorFrequency, IDirectDraw* dd, LPDWORD lpdwFrequency);
STDDDSTUB(DD1, GetScanLine, IDirectDraw* dd, LPDWORD lpdwScanLine);
STDDDSTUB(DD1, GetVerticalBlankStatus, IDirectDraw* dd, BOOL *lpbIsInVB);
STDDDSTUB(DD1, Initialize, IDirectDraw* dd, GUID *lpGUID);
STDDDSTUB(DD1, RestoreDisplayMode, IDirectDraw* dd);
//STDDDSTUB(DD1, SetCooperativeLevel, IDirectDraw* dd, HWND hWnd, DWORD dwFlags);
STDDDSTUB(DD1, SetDisplayMode, IDirectDraw* dd, DWORD dwWidth, DWORD dwHeight, DWORD dwBPP);
STDDDSTUB(DD1, WaitForVerticalBlank, IDirectDraw* dd, DWORD dwFlags, HANDLE hEvent);

//functions actually used in the game
HRESULT STDMETHODCALLTYPE DD1QueryInterface(DD1* dd, const IID* const riid, void** ppvObject)
{
    DPRINTF("trace");
    return IUNKQueryInterface(dd, riid, ppvObject);
}

ULONG STDMETHODCALLTYPE DD1Release(DD1* dd)
{
    DPRINTF("trace");
    return IUNKRelease(dd);
}


HRESULT STDMETHODCALLTYPE DD1SetCooperativeLevel(DD1* dd, HWND hWnd, DWORD dwFlags)
{
    DPRINTF("flags %x",dwFlags );
    return dd->real->lpVtbl->SetCooperativeLevel(dd->real, hWnd, DDSCL_NORMAL );
}

HRESULT STDMETHODCALLTYPE DD1CreateSurface(DD1* dd, DDSURFACEDESC *surface_desc, struct IDirectDrawSurface **surface, IUnknown *outer)
{
    DPRINTF("trace");
    return dd->real->lpVtbl->CreateSurface(dd->real, surface_desc, surface, outer);
}

// create vtables for the interfaces
IDirectDrawVtbl dd1Vtbl =
{
	DD1QueryInterface,
	DD1AddRef,
	DD1Release,
	DD1Compact,
	DD1CreateClipper,
	DD1CreatePalette,
	DD1CreateSurface,
	DD1DuplicateSurface,
	DD1EnumDisplayModes,
	DD1EnumSurfaces,
	DD1FlipToGDISurface,
	DD1GetCaps,
	DD1GetDisplayMode,
	DD1GetFourCCCodes,
	DD1GetGDISurface,
	DD1GetMonitorFrequency,
	DD1GetScanLine,
	DD1GetVerticalBlankStatus,
	DD1Initialize,
	DD1RestoreDisplayMode,
	DD1SetCooperativeLevel,
	DD1SetDisplayMode,
	DD1WaitForVerticalBlank
};

IDirectDraw* IDDCreate(IDirectDraw* real)
{
	DPRINTF("trace");

    DD1* fake = malloc(sizeof(DD1));
	fake->lpVtbl = &dd1Vtbl;
    fake->real = real;
    return fake;
}

