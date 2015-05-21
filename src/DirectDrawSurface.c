
#include "Unknown.h"
#include "Direct3DViewport3.h"
#include "Direct3DDevice3.h"
#include "DirectDrawSurface.h"


//function typedefs
//unknown
STDDDTYPEDEF(DDS1, QueryInterface, DDS1* This, REFIID riid, void** ppvObject);
DDTYPEDEF(ULONG, DDS1, AddRef, DDS1* This);
DDTYPEDEF(ULONG, DDS1, Release, DDS1* This);
//dds4
STDDDTYPEDEF(DDS1, AddAttachedSurface, DDS1 *This, IDirectDrawSurface *attachment) ;
STDDDTYPEDEF(DDS1, AddOverlayDirtyRect, DDS1 *This, LPRECT lpRect) ;
STDDDTYPEDEF(DDS1, Blt, DDS1 *This, RECT *dst_rect, IDirectDrawSurface *src_surface, RECT *src_rect,
            DWORD flags, DDBLTFX *fx) ;
STDDDTYPEDEF(DDS1, BltBatch, DDS1 *This, DDBLTBATCH *batch, DWORD count, DWORD flags) ;
STDDDTYPEDEF(DDS1, BltFast, DDS1 *This, DWORD x, DWORD y, IDirectDrawSurface *src_surface,
            RECT *src_rect, DWORD flags) ;
STDDDTYPEDEF(DDS1, DeleteAttachedSurface, DDS1 *This, DWORD flags, IDirectDrawSurface *attachment) ;
STDDDTYPEDEF(DDS1, EnumAttachedSurfaces, DDS1 *This, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback) ;
STDDDTYPEDEF(DDS1, EnumOverlayZOrders, DDS1 *This, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback) ;
STDDDTYPEDEF(DDS1, Flip, DDS1 *This, IDirectDrawSurface *dst_surface, DWORD flags) ;
STDDDTYPEDEF(DDS1, GetAttachedSurface, DDS1 *This, DDSCAPS *caps, IDirectDrawSurface **attachment) ;
STDDDTYPEDEF(DDS1, GetBltStatus, DDS1 *This, DWORD dwFlags) ;
STDDDTYPEDEF(DDS1, GetCaps, DDS1 *This, DDSCAPS *caps) ;
STDDDTYPEDEF(DDS1, GetClipper, DDS1 *This, IDirectDrawClipper **clipper) ;
STDDDTYPEDEF(DDS1, GetColorKey, DDS1 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDTYPEDEF(DDS1, GetDC, DDS1 *This, HDC *lphDC) ;
STDDDTYPEDEF(DDS1, GetFlipStatus, DDS1 *This, DWORD dwFlags) ;
STDDDTYPEDEF(DDS1, GetOverlayPosition, DDS1 *This, LPLONG lplX, LPLONG lplY) ;
STDDDTYPEDEF(DDS1, GetPalette, DDS1 *This, IDirectDrawPalette **palette) ;
STDDDTYPEDEF(DDS1, GetPixelFormat, DDS1 *This, DDPIXELFORMAT *format) ;
STDDDTYPEDEF(DDS1, GetSurfaceDesc, DDS1 *This, DDSURFACEDESC *surface_desc) ;
STDDDTYPEDEF(DDS1, Initialize, DDS1 *This, IDirectDraw *ddraw, DDSURFACEDESC *surface_desc) ;
STDDDTYPEDEF(DDS1, IsLost, DDS1 *This) ;
STDDDTYPEDEF(DDS1, Lock, DDS1 *This, RECT *rect, DDSURFACEDESC *surface_desc, DWORD flags, HANDLE event) ;
STDDDTYPEDEF(DDS1, ReleaseDC, DDS1 *This, HDC hDC) ;
STDDDTYPEDEF(DDS1, Restore, DDS1 *This) ;
STDDDTYPEDEF(DDS1, SetClipper, DDS1 *This, IDirectDrawClipper *clipper) ;
STDDDTYPEDEF(DDS1, SetColorKey, DDS1 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDTYPEDEF(DDS1, SetOverlayPosition, DDS1 *This, LONG lX, LONG lY) ;
STDDDTYPEDEF(DDS1, SetPalette, DDS1 *This, IDirectDrawPalette *palette) ;
STDDDTYPEDEF(DDS1, Unlock, DDS1 *This, LPVOID lpSurfaceData) ;
STDDDTYPEDEF(DDS1, UpdateOverlay, DDS1 *This, RECT *src_rect, IDirectDrawSurface *dst_surface, RECT *dst_rect,
            DWORD flags, DDOVERLAYFX *fx) ;
STDDDTYPEDEF(DDS1, UpdateOverlayDisplay, DDS1 *This, DWORD dwFlags) ;
STDDDTYPEDEF(DDS1, UpdateOverlayZOrder, DDS1 *This, DWORD flags, IDirectDrawSurface *reference_surface) ;

//stub functions
//unknown
//STDDDSTUB(DDS1, QueryInterface, DDS1* dd, REFIID riid, void** ppvObject);
DDSTUB(ULONG, DDS1, AddRef, DDS1* dd);
//DDSTUB(ULONG, DDS1, Release, DDS1* dd);
//dds4
STDDDSTUB(DDS1, AddAttachedSurface, DDS1 *This, DDS1 *attachment) ;
STDDDSTUB(DDS1, AddOverlayDirtyRect, DDS1 *This, LPRECT lpRect) ;
STDDDSTUB(DDS1, Blt, DDS1 *This, RECT *dst_rect, DDS1 *src_surface, RECT *src_rect,
            DWORD flags, DDBLTFX *fx) ;
STDDDSTUB(DDS1, BltBatch, DDS1 *This, DDBLTBATCH *batch, DWORD count, DWORD flags) ;
STDDDSTUB(DDS1, BltFast, DDS1 *This, DWORD x, DWORD y, DDS1 *src_surface,
            RECT *src_rect, DWORD flags) ;
STDDDSTUB(DDS1, DeleteAttachedSurface, DDS1 *This, DWORD flags, DDS1 *attachment) ;
STDDDSTUB(DDS1, EnumAttachedSurfaces, DDS1 *This, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback) ;
STDDDSTUB(DDS1, EnumOverlayZOrders, DDS1 *This, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback) ;
STDDDSTUB(DDS1, Flip, DDS1 *This, DDS1 *dst_surface, DWORD flags) ;
STDDDSTUB(DDS1, GetAttachedSurface, DDS1 *This, DDSCAPS *caps, DDS1 **attachment) ;
STDDDSTUB(DDS1, GetBltStatus, DDS1 *This, DWORD dwFlags) ;
STDDDSTUB(DDS1, GetCaps, DDS1 *This, DDSCAPS *caps) ;
STDDDSTUB(DDS1, GetClipper, DDS1 *This, IDirectDrawClipper **clipper) ;
STDDDSTUB(DDS1, GetColorKey, DDS1 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDSTUB(DDS1, GetDC, DDS1 *This, HDC *lphDC) ;
STDDDSTUB(DDS1, GetFlipStatus, DDS1 *This, DWORD dwFlags) ;
STDDDSTUB(DDS1, GetOverlayPosition, DDS1 *This, LPLONG lplX, LPLONG lplY) ;
STDDDSTUB(DDS1, GetPalette, DDS1 *This, IDirectDrawPalette **palette) ;
STDDDSTUB(DDS1, GetPixelFormat, DDS1 *This, DDPIXELFORMAT *format) ;
STDDDSTUB(DDS1, GetSurfaceDesc, DDS1 *This, DDSURFACEDESC *surface_desc) ;
STDDDSTUB(DDS1, Initialize, DDS1 *This, IDirectDraw *ddraw, DDSURFACEDESC2 *surface_desc) ;
STDDDSTUB(DDS1, IsLost, DDS1 *This) ;
STDDDSTUB(DDS1, Lock, DDS1 *This, RECT *rect, DDSURFACEDESC *surface_desc, DWORD flags, HANDLE event) ;
STDDDSTUB(DDS1, ReleaseDC, DDS1 *This, HDC hDC) ;
STDDDSTUB(DDS1, Restore, DDS1 *This) ;
STDDDSTUB(DDS1, SetClipper, DDS1 *This, IDirectDrawClipper *clipper) ;
STDDDSTUB(DDS1, SetColorKey, DDS1 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDSTUB(DDS1, SetOverlayPosition, DDS1 *This, LONG lX, LONG lY) ;
STDDDSTUB(DDS1, SetPalette, DDS1 *This, IDirectDrawPalette *palette) ;
STDDDSTUB(DDS1, Unlock, DDS1 *This, LPRECT lpSurfaceData) ;
STDDDSTUB(DDS1, UpdateOverlay, DDS1 *This, RECT *src_rect, DDS1 *dst_surface, RECT *dst_rect,
            DWORD flags, DDOVERLAYFX *fx) ;
STDDDSTUB(DDS1, UpdateOverlayDisplay, DDS1 *This, DWORD dwFlags) ;
STDDDSTUB(DDS1, UpdateOverlayZOrder, DDS1 *This, DWORD flags, DDS1 *reference_surface) ;


HRESULT STDMETHODCALLTYPE DDS1QueryInterface(DDS1* This, REFIID riid, void** ppvObject)
{
	DPRINTF("trace %x", This);
    return IUNKQueryInterface(This, riid, ppvObject);
}

ULONG STDMETHODCALLTYPE DDS1Release(DDS1* This)
{
	DPRINTF("trace %x", This);
    return IUNKRelease(This);
}

IDirectDrawSurfaceVtbl ddsVtbl =
{
	//unk
	DDS1QueryInterface,
	DDS1AddRef,
	DDS1Release,
	//dds4
	DDS1AddAttachedSurface,
	DDS1AddOverlayDirtyRect,
	DDS1Blt,
	DDS1BltBatch,
	DDS1BltFast,
	DDS1DeleteAttachedSurface,
	DDS1EnumAttachedSurfaces,
	DDS1EnumOverlayZOrders,
	DDS1Flip,
	DDS1GetAttachedSurface,
	DDS1GetBltStatus,
	DDS1GetCaps,
	DDS1GetClipper,
	DDS1GetColorKey,
	DDS1GetDC,
	DDS1GetFlipStatus,
	DDS1GetOverlayPosition,
	DDS1GetPalette,
	DDS1GetPixelFormat,
	DDS1GetSurfaceDesc,
	DDS1Initialize,
	DDS1IsLost,
	DDS1Lock,
	DDS1ReleaseDC,
	DDS1Restore,
	DDS1SetClipper,
	DDS1SetColorKey,
	DDS1SetOverlayPosition,
	DDS1SetPalette,
	DDS1Unlock,
	DDS1UpdateOverlay,
	DDS1UpdateOverlayDisplay,
	DDS1UpdateOverlayZOrder
};


IDirectDrawSurface* IDDS1Create(IDirectDrawSurface* real)
{
    DDS1* fake = malloc(sizeof(DDS1));
	fake->lpVtbl = &ddsVtbl;
    fake->real = real;
	DPRINTF("trace %x", fake);
    return fake;
}


