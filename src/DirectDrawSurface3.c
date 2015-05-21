
#include "Unknown.h"
#include "Direct3DViewport3.h"
#include "Direct3DDevice3.h"
#include "DirectDrawSurface3.h"


//function typedefs
//unknown
STDDDTYPEDEF(DDS3, QueryInterface, DDS3* This, REFIID riid, void** ppvObject);
DDTYPEDEF(ULONG, DDS3, AddRef, DDS3* This);
DDTYPEDEF(ULONG, DDS3, Release, DDS3* This);
//dds4
STDDDTYPEDEF(DDS3, AddAttachedSurface, DDS3 *This, IDirectDrawSurface3 *attachment) ;
STDDDTYPEDEF(DDS3, AddOverlayDirtyRect, DDS3 *This, LPRECT lpRect) ;
STDDDTYPEDEF(DDS3, Blt, DDS3 *This, RECT *dst_rect, IDirectDrawSurface3 *src_surface, RECT *src_rect,
            DWORD flags, DDBLTFX *fx) ;
STDDDTYPEDEF(DDS3, BltBatch, DDS3 *This, DDBLTBATCH *batch, DWORD count, DWORD flags) ;
STDDDTYPEDEF(DDS3, BltFast, DDS3 *This, DWORD x, DWORD y, IDirectDrawSurface3 *src_surface,
            RECT *src_rect, DWORD flags) ;
STDDDTYPEDEF(DDS3, DeleteAttachedSurface, DDS3 *This, DWORD flags, IDirectDrawSurface3 *attachment) ;
STDDDTYPEDEF(DDS3, EnumAttachedSurfaces, DDS3 *This, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback) ;
STDDDTYPEDEF(DDS3, EnumOverlayZOrders, DDS3 *This, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback) ;
STDDDTYPEDEF(DDS3, Flip, DDS3 *This, IDirectDrawSurface3 *dst_surface, DWORD flags) ;
STDDDTYPEDEF(DDS3, GetAttachedSurface, DDS3 *This, DDSCAPS *caps, IDirectDrawSurface3 **attachment) ;
STDDDTYPEDEF(DDS3, GetBltStatus, DDS3 *This, DWORD dwFlags) ;
STDDDTYPEDEF(DDS3, GetCaps, DDS3 *This, DDSCAPS *caps) ;
STDDDTYPEDEF(DDS3, GetClipper, DDS3 *This, IDirectDrawClipper **clipper) ;
STDDDTYPEDEF(DDS3, GetColorKey, DDS3 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDTYPEDEF(DDS3, GetDC, DDS3 *This, HDC *lphDC) ;
STDDDTYPEDEF(DDS3, GetFlipStatus, DDS3 *This, DWORD dwFlags) ;
STDDDTYPEDEF(DDS3, GetOverlayPosition, DDS3 *This, LPLONG lplX, LPLONG lplY) ;
STDDDTYPEDEF(DDS3, GetPalette, DDS3 *This, IDirectDrawPalette **palette) ;
STDDDTYPEDEF(DDS3, GetPixelFormat, DDS3 *This, DDPIXELFORMAT *format) ;
STDDDTYPEDEF(DDS3, GetSurfaceDesc, DDS3 *This, DDSURFACEDESC *surface_desc) ;
STDDDTYPEDEF(DDS3, Initialize, DDS3 *This, IDirectDraw *ddraw, DDSURFACEDESC *surface_desc) ;
STDDDTYPEDEF(DDS3, IsLost, DDS3 *This) ;
STDDDTYPEDEF(DDS3, Lock, DDS3 *This, RECT *rect, DDSURFACEDESC *surface_desc, DWORD flags, HANDLE event) ;
STDDDTYPEDEF(DDS3, ReleaseDC, DDS3 *This, HDC hDC) ;
STDDDTYPEDEF(DDS3, Restore, DDS3 *This) ;
STDDDTYPEDEF(DDS3, SetClipper, DDS3 *This, IDirectDrawClipper *clipper) ;
STDDDTYPEDEF(DDS3, SetColorKey, DDS3 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDTYPEDEF(DDS3, SetOverlayPosition, DDS3 *This, LONG lX, LONG lY) ;
STDDDTYPEDEF(DDS3, SetPalette, DDS3 *This, IDirectDrawPalette *palette) ;
STDDDTYPEDEF(DDS3, Unlock, DDS3 *This, LPVOID lpSurfaceData) ;
STDDDTYPEDEF(DDS3, UpdateOverlay, DDS3 *This, RECT *src_rect, IDirectDrawSurface3 *dst_surface, RECT *dst_rect,
            DWORD flags, DDOVERLAYFX *fx) ;
STDDDTYPEDEF(DDS3, UpdateOverlayDisplay, DDS3 *This, DWORD dwFlags) ;
STDDDTYPEDEF(DDS3, UpdateOverlayZOrder, DDS3 *This, DWORD flags, IDirectDrawSurface3 *reference_surface) ;
STDDDTYPEDEF(DDS3, GetDDInterface, DDS3 *This,  LPVOID *lplpDD) ;
STDDDTYPEDEF(DDS3, PageLock, DDS3 *This, DWORD dwFlags);
STDDDTYPEDEF(DDS3, PageUnlock, DDS3 *This, DWORD dwFlags);
STDDDTYPEDEF(DDS3, SetSurfaceDesc, DDS3 *This, DDSURFACEDESC *surface_desc, DWORD flags);

//stub functions
//unknown
STDDDSTUB(DDS3, QueryInterface, DDS3* dd, REFIID riid, void** ppvObject);
DDSTUB(ULONG, DDS3, AddRef, DDS3* dd);
DDSTUB(ULONG, DDS3, Release, DDS3* dd);
//dds4
STDDDSTUB(DDS3, AddAttachedSurface, DDS3 *This, DDS3 *attachment) ;
STDDDSTUB(DDS3, AddOverlayDirtyRect, DDS3 *This, LPRECT lpRect) ;
STDDDSTUB(DDS3, Blt, DDS3 *This, RECT *dst_rect, DDS3 *src_surface, RECT *src_rect,
            DWORD flags, DDBLTFX *fx) ;
STDDDSTUB(DDS3, BltBatch, DDS3 *This, DDBLTBATCH *batch, DWORD count, DWORD flags) ;
STDDDSTUB(DDS3, BltFast, DDS3 *This, DWORD x, DWORD y, DDS3 *src_surface,
            RECT *src_rect, DWORD flags) ;
STDDDSTUB(DDS3, DeleteAttachedSurface, DDS3 *This, DWORD flags, DDS3 *attachment) ;
STDDDSTUB(DDS3, EnumAttachedSurfaces, DDS3 *This, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpEnumSurfacesCallback) ;
STDDDSTUB(DDS3, EnumOverlayZOrders, DDS3 *This, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK lpfnCallback) ;
STDDDSTUB(DDS3, Flip, DDS3 *This, DDS3 *dst_surface, DWORD flags) ;
STDDDSTUB(DDS3, GetAttachedSurface, DDS3 *This, DDSCAPS *caps, DDS3 **attachment) ;
STDDDSTUB(DDS3, GetBltStatus, DDS3 *This, DWORD dwFlags) ;
STDDDSTUB(DDS3, GetCaps, DDS3 *This, DDSCAPS *caps) ;
STDDDSTUB(DDS3, GetClipper, DDS3 *This, IDirectDrawClipper **clipper) ;
STDDDSTUB(DDS3, GetColorKey, DDS3 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDSTUB(DDS3, GetDC, DDS3 *This, HDC *lphDC) ;
STDDDSTUB(DDS3, GetFlipStatus, DDS3 *This, DWORD dwFlags) ;
STDDDSTUB(DDS3, GetOverlayPosition, DDS3 *This, LPLONG lplX, LPLONG lplY) ;
STDDDSTUB(DDS3, GetPalette, DDS3 *This, IDirectDrawPalette **palette) ;
STDDDSTUB(DDS3, GetPixelFormat, DDS3 *This, DDPIXELFORMAT *format) ;
STDDDSTUB(DDS3, GetSurfaceDesc, DDS3 *This, DDSURFACEDESC *surface_desc) ;
STDDDSTUB(DDS3, Initialize, DDS3 *This, IDirectDraw *ddraw, DDSURFACEDESC2 *surface_desc) ;
STDDDSTUB(DDS3, IsLost, DDS3 *This) ;
STDDDSTUB(DDS3, Lock, DDS3 *This, RECT *rect, DDSURFACEDESC *surface_desc, DWORD flags, HANDLE event) ;
STDDDSTUB(DDS3, ReleaseDC, DDS3 *This, HDC hDC) ;
STDDDSTUB(DDS3, Restore, DDS3 *This) ;
STDDDSTUB(DDS3, SetClipper, DDS3 *This, IDirectDrawClipper *clipper) ;
STDDDSTUB(DDS3, SetColorKey, DDS3 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDSTUB(DDS3, SetOverlayPosition, DDS3 *This, LONG lX, LONG lY) ;
STDDDSTUB(DDS3, SetPalette, DDS3 *This, IDirectDrawPalette *palette) ;
STDDDSTUB(DDS3, Unlock, DDS3 *This, LPRECT lpSurfaceData) ;
STDDDSTUB(DDS3, UpdateOverlay, DDS3 *This, RECT *src_rect, DDS3 *dst_surface, RECT *dst_rect,
            DWORD flags, DDOVERLAYFX *fx) ;
STDDDSTUB(DDS3, UpdateOverlayDisplay, DDS3 *This, DWORD dwFlags) ;
STDDDSTUB(DDS3, UpdateOverlayZOrder, DDS3 *This, DWORD flags, DDS3 *reference_surface) ;
STDDDSTUB(DDS3, GetDDInterface, DDS3 *This,  LPVOID *lplpDD) PURE;
STDDDSTUB(DDS3, PageLock, DDS3 *This, DWORD dwFlags) PURE;
STDDDSTUB(DDS3, PageUnlock, DDS3 *This, DWORD dwFlags) PURE;
STDDDSTUB(DDS3, SetSurfaceDesc, DDS3 *This, DDSURFACEDESC *surface_desc, DWORD flags) PURE;

IDirectDrawSurface3Vtbl dds3Vtbl =
{
	//unk
	DDS3QueryInterface,
	DDS3AddRef,
	DDS3Release,
	//dds4
	DDS3AddAttachedSurface,
	DDS3AddOverlayDirtyRect,
	DDS3Blt,
	DDS3BltBatch,
	DDS3BltFast,
	DDS3DeleteAttachedSurface,
	DDS3EnumAttachedSurfaces,
	DDS3EnumOverlayZOrders,
	DDS3Flip,
	DDS3GetAttachedSurface,
	DDS3GetBltStatus,
	DDS3GetCaps,
	DDS3GetClipper,
	DDS3GetColorKey,
	DDS3GetDC,
	DDS3GetFlipStatus,
	DDS3GetOverlayPosition,
	DDS3GetPalette,
	DDS3GetPixelFormat,
	DDS3GetSurfaceDesc,
	DDS3Initialize,
	DDS3IsLost,
	DDS3Lock,
	DDS3ReleaseDC,
	DDS3Restore,
	DDS3SetClipper,
	DDS3SetColorKey,
	DDS3SetOverlayPosition,
	DDS3SetPalette,
	DDS3Unlock,
	DDS3UpdateOverlay,
	DDS3UpdateOverlayDisplay,
	DDS3UpdateOverlayZOrder
};


IDirectDrawSurface3* IDDS3Create(IDirectDrawSurface3* real)
{
    DDS3* fake = malloc(sizeof(DDS3));
	fake->lpVtbl = &dds3Vtbl;
    fake->real = real;
	DPRINTF("trace %x", fake);
    return fake;
}

IDirectDrawSurface3* IDDS3Query(IUNK* unk)
{
	IDirectDrawSurface3* real;
	//get the real pointer
	if(unk->real->lpVtbl->QueryInterface(unk->real, &IID_IDirectDrawSurface3, &real) != DD_OK)
	{
		DPRINTF("query interface failed with %d",DD_OK);
		ABORT();
	}

    DDS3* fake = malloc(sizeof(DDS3));
	fake->lpVtbl = &dds3Vtbl;
    fake->real = real;
	DPRINTF("trace %x", fake);
    return fake;
}

