
#include "Unknown.h"
#include "Direct3DViewport3.h"
#include "Direct3DDevice3.h"
#include "DirectDrawSurface4.h"

//function typedefs
//unknown
STDDDTYPEDEF(DDS4, QueryInterface, DDS4* This, REFIID riid, void** ppvObject);
DDTYPEDEF(ULONG, DDS4, AddRef, DDS4* This);
DDTYPEDEF(ULONG, DDS4, Release, DDS4* This);
//dds4
STDDDTYPEDEF(DDS4, AddAttachedSurface, DDS4 *This, IDirectDrawSurface4 *attachment) ;
STDDDTYPEDEF(DDS4, AddOverlayDirtyRect, DDS4 *This, LPRECT lpRect) ;
STDDDTYPEDEF(DDS4, Blt, DDS4 *This, RECT *dst_rect, IDirectDrawSurface4 *src_surface, RECT *src_rect,
            DWORD flags, DDBLTFX *fx) ;
STDDDTYPEDEF(DDS4, BltBatch, DDS4 *This, DDBLTBATCH *batch, DWORD count, DWORD flags) ;
STDDDTYPEDEF(DDS4, BltFast, DDS4 *This, DWORD x, DWORD y, IDirectDrawSurface4 *src_surface,
            RECT *src_rect, DWORD flags) ;
STDDDTYPEDEF(DDS4, DeleteAttachedSurface, DDS4 *This, DWORD flags, IDirectDrawSurface4 *attachment) ;
STDDDTYPEDEF(DDS4, EnumAttachedSurfaces, DDS4 *This, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpEnumSurfacesCallback) ;
STDDDTYPEDEF(DDS4, EnumOverlayZOrders, DDS4 *This, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpfnCallback) ;
STDDDTYPEDEF(DDS4, Flip, DDS4 *This, IDirectDrawSurface4 *dst_surface, DWORD flags) ;
STDDDTYPEDEF(DDS4, GetAttachedSurface, DDS4 *This, DDSCAPS2 *caps, IDirectDrawSurface4 **attachment) ;
STDDDTYPEDEF(DDS4, GetBltStatus, DDS4 *This, DWORD dwFlags) ;
STDDDTYPEDEF(DDS4, GetCaps, DDS4 *This, DDSCAPS2 *caps) ;
STDDDTYPEDEF(DDS4, GetClipper, DDS4 *This, IDirectDrawClipper **clipper) ;
STDDDTYPEDEF(DDS4, GetColorKey, DDS4 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDTYPEDEF(DDS4, GetDC, DDS4 *This, HDC *lphDC) ;
STDDDTYPEDEF(DDS4, GetFlipStatus, DDS4 *This, DWORD dwFlags) ;
STDDDTYPEDEF(DDS4, GetOverlayPosition, DDS4 *This, LPLONG lplX, LPLONG lplY) ;
STDDDTYPEDEF(DDS4, GetPalette, DDS4 *This, IDirectDrawPalette **palette) ;
STDDDTYPEDEF(DDS4, GetPixelFormat, DDS4 *This, DDPIXELFORMAT *format) ;
STDDDTYPEDEF(DDS4, GetSurfaceDesc, DDS4 *This, DDSURFACEDESC2 *surface_desc) ;
STDDDTYPEDEF(DDS4, Initialize, DDS4 *This, IDirectDraw *ddraw, DDSURFACEDESC2 *surface_desc) ;
STDDDTYPEDEF(DDS4, IsLost, DDS4 *This) ;
STDDDTYPEDEF(DDS4, Lock, DDS4 *This, RECT *rect, DDSURFACEDESC2 *surface_desc, DWORD flags, HANDLE event) ;
STDDDTYPEDEF(DDS4, ReleaseDC, DDS4 *This, HDC hDC) ;
STDDDTYPEDEF(DDS4, Restore, DDS4 *This) ;
STDDDTYPEDEF(DDS4, SetClipper, DDS4 *This, IDirectDrawClipper *clipper) ;
STDDDTYPEDEF(DDS4, SetColorKey, DDS4 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDTYPEDEF(DDS4, SetOverlayPosition, DDS4 *This, LONG lX, LONG lY) ;
STDDDTYPEDEF(DDS4, SetPalette, DDS4 *This, IDirectDrawPalette *palette) ;
STDDDTYPEDEF(DDS4, Unlock, DDS4 *This, LPRECT lpSurfaceData) ;
STDDDTYPEDEF(DDS4, UpdateOverlay, DDS4 *This, RECT *src_rect, IDirectDrawSurface4 *dst_surface, RECT *dst_rect,
            DWORD flags, DDOVERLAYFX *fx) ;
STDDDTYPEDEF(DDS4, UpdateOverlayDisplay, DDS4 *This, DWORD dwFlags) ;
STDDDTYPEDEF(DDS4, UpdateOverlayZOrder, DDS4 *This, DWORD flags, IDirectDrawSurface4 *reference_surface) ;
STDDDTYPEDEF(DDS4, GetDDInterface, DDS4 *This, LPVOID *lplpDD) ;
STDDDTYPEDEF(DDS4, PageLock, DDS4 *This, DWORD dwFlags) ;
STDDDTYPEDEF(DDS4, PageUnlock, DDS4 *This, DWORD dwFlags) ;
STDDDTYPEDEF(DDS4, SetSurfaceDesc, DDS4 *This, DDSURFACEDESC2 *surface_desc, DWORD flags) ;
STDDDTYPEDEF(DDS4, SetPrivateData, DDS4 *This, const GUID* const tag, LPVOID pData, DWORD cbSize, DWORD dwFlags) ;
STDDDTYPEDEF(DDS4, GetPrivateData, DDS4 *This, const GUID* const tag, LPVOID pBuffer, LPDWORD pcbBufferSize) ;
STDDDTYPEDEF(DDS4, FreePrivateData, DDS4 *This, const GUID* const tag) ;
STDDDTYPEDEF(DDS4, GetUniquenessValue, DDS4 *This, LPDWORD pValue) ;
STDDDTYPEDEF(DDS4, ChangeUniquenessValue, DDS4 *This) ;


//stub functions
//unknown
//STDDDSTUB(DDS4, QueryInterface, DDS4* dd, REFIID riid, void** ppvObject);
DDSTUB(ULONG, DDS4, AddRef, DDS4* dd);
//DDSTUB(ULONG, DDS4, Release, DDS4* dd);
//dds4
//STDDDSTUB(DDS4, AddAttachedSurface, DDS4 *This, DDS4 *attachment) ;
STDDDSTUB(DDS4, AddOverlayDirtyRect, DDS4 *This, LPRECT lpRect) ;
//STDDDSTUB(DDS4, Blt, DDS4 *This, RECT *dst_rect, DDS4 *src_surface, RECT *src_rect,
//            DWORD flags, DDBLTFX *fx) ;
STDDDSTUB(DDS4, BltBatch, DDS4 *This, DDBLTBATCH *batch, DWORD count, DWORD flags) ;
STDDDSTUB(DDS4, BltFast, DDS4 *This, DWORD x, DWORD y, DDS4 *src_surface,
            RECT *src_rect, DWORD flags) ;
STDDDSTUB(DDS4, DeleteAttachedSurface, DDS4 *This, DWORD flags, DDS4 *attachment) ;
STDDDSTUB(DDS4, EnumAttachedSurfaces, DDS4 *This, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpEnumSurfacesCallback) ;
STDDDSTUB(DDS4, EnumOverlayZOrders, DDS4 *This, DWORD dwFlags, LPVOID lpContext, LPDDENUMSURFACESCALLBACK2 lpfnCallback) ;
//STDDDSTUB(DDS4, Flip, DDS4 *This, DDS4 *dst_surface, DWORD flags) ;
//STDDDSTUB(DDS4, GetAttachedSurface, DDS4 *This, DDSCAPS2 *caps, DDS4 **attachment) ;
STDDDSTUB(DDS4, GetBltStatus, DDS4 *This, DWORD dwFlags) ;
STDDDSTUB(DDS4, GetCaps, DDS4 *This, DDSCAPS2 *caps) ;
STDDDSTUB(DDS4, GetClipper, DDS4 *This, IDirectDrawClipper **clipper) ;
STDDDSTUB(DDS4, GetColorKey, DDS4 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDSTUB(DDS4, GetDC, DDS4 *This, HDC *lphDC) ;
STDDDSTUB(DDS4, GetFlipStatus, DDS4 *This, DWORD dwFlags) ;
STDDDSTUB(DDS4, GetOverlayPosition, DDS4 *This, LPLONG lplX, LPLONG lplY) ;
STDDDSTUB(DDS4, GetPalette, DDS4 *This, IDirectDrawPalette **palette) ;
//STDDDSTUB(DDS4, GetPixelFormat, DDS4 *This, DDPIXELFORMAT *format) ;
STDDDSTUB(DDS4, GetSurfaceDesc, DDS4 *This, DDSURFACEDESC2 *surface_desc) ;
STDDDSTUB(DDS4, Initialize, DDS4 *This, IDirectDraw *ddraw, DDSURFACEDESC2 *surface_desc) ;
STDDDSTUB(DDS4, IsLost, DDS4 *This) ;
//STDDDSTUB(DDS4, Lock, DDS4 *This, RECT *rect, DDSURFACEDESC2 *surface_desc, DWORD flags, HANDLE event) ;
STDDDSTUB(DDS4, ReleaseDC, DDS4 *This, HDC hDC) ;
//STDDDSTUB(DDS4, Restore, DDS4 *This) ;
//STDDDSTUB(DDS4, SetClipper, DDS4 *This, IDirectDrawClipper *clipper) ;
STDDDSTUB(DDS4, SetColorKey, DDS4 *This, DWORD flags, DDCOLORKEY *color_key) ;
STDDDSTUB(DDS4, SetOverlayPosition, DDS4 *This, LONG lX, LONG lY) ;
STDDDSTUB(DDS4, SetPalette, DDS4 *This, IDirectDrawPalette *palette) ;
//STDDDSTUB(DDS4, Unlock, DDS4 *This, LPRECT lpSurfaceData) ;
STDDDSTUB(DDS4, UpdateOverlay, DDS4 *This, RECT *src_rect, DDS4 *dst_surface, RECT *dst_rect,
            DWORD flags, DDOVERLAYFX *fx) ;
STDDDSTUB(DDS4, UpdateOverlayDisplay, DDS4 *This, DWORD dwFlags) ;
STDDDSTUB(DDS4, UpdateOverlayZOrder, DDS4 *This, DWORD flags, DDS4 *reference_surface) ;
STDDDSTUB(DDS4, GetDDInterface, DDS4 *This, LPVOID *lplpDD) ;
STDDDSTUB(DDS4, PageLock, DDS4 *This, DWORD dwFlags) ;
STDDDSTUB(DDS4, PageUnlock, DDS4 *This, DWORD dwFlags) ;
STDDDSTUB(DDS4, SetSurfaceDesc, DDS4 *This, DDSURFACEDESC2 *surface_desc, DWORD flags) ;
STDDDSTUB(DDS4, SetPrivateData, DDS4 *This, const GUID* const tag, LPVOID pData, DWORD cbSize, DWORD dwFlags) ;
STDDDSTUB(DDS4, GetPrivateData, DDS4 *This, const GUID* const tag, LPVOID pBuffer, LPDWORD pcbBufferSize) ;
STDDDSTUB(DDS4, FreePrivateData, DDS4 *This, const GUID* const tag) ;
STDDDSTUB(DDS4, GetUniquenessValue, DDS4 *This, LPDWORD pValue) ;
STDDDSTUB(DDS4, ChangeUniquenessValue, DDS4 *This) ;


HRESULT STDMETHODCALLTYPE DDS4QueryInterface(DDS4* This, REFIID riid, void** ppvObject)
{
    DPRINTF("trace %x", This);
    return IUNKQueryInterface(This, riid, ppvObject);
}

ULONG STDMETHODCALLTYPE DDS4Release(DDS4* This)
{
    DPRINTF("trace %x", This);
    return IUNKRelease(This);
}

//Used to attach zbuffer?!?
HRESULT STDMETHODCALLTYPE DDS4AddAttachedSurface(DDS4 *This, DDS4 *attachment)
{
    DPRINTF("trace %x", This);
    return This->real->lpVtbl->AddAttachedSurface(This->real, attachment->real);
}

HRESULT STDMETHODCALLTYPE DDS4Blt(DDS4 *This, RECT *dst_rect, DDS4 *src_surface, RECT *src_rect,
            DWORD flags, DDBLTFX *fx)
{
    /*
    #define DDBLT_ZBUFFERDESTCONSTOVERRIDE        0x00100000
    #define DDBLT_ZBUFFERDESTOVERRIDE        0x00200000
    #define DDBLT_ZBUFFERSRCCONSTOVERRIDE        0x00400000
    #define DDBLT_ZBUFFERSRCOVERRIDE        0x00800000
    #define DDBLT_WAIT                0x01000000
    #define DDBLT_DEPTHFILL                0x02000000
    */

    IDirectDrawSurface4* src = NULL;
    if(src_surface != NULL)
    {
        src = src_surface->real;
    }

    if(flags & DDBLT_DEPTHFILL)
    {
        DPRINTF("trace %x\ndrect %x\nssurf %x\nsrect %x\nflags %x",
            This, dst_rect, src_surface, src_rect, flags);

        if(dst_rect != NULL)
        {
            PrintRect(dst_rect);
        }

        if(fx != NULL)
        {
            DPRINTF("zDepth = %x", fx->dwFillDepth);
        }
    }


    return This->real->lpVtbl->Blt(This->real, dst_rect, src, src_rect, flags, fx);
}

HRESULT STDMETHODCALLTYPE DDS4Flip(DDS4 *This, DDS4 *dst_surface, DWORD flags)
{
    DPRINTF("trace %x", This);

    IDirectDrawSurface4* dst = NULL;
    if(dst_surface != NULL)
    {
        dst = dst_surface->real;
    }

    return This->real->lpVtbl->Flip(This->real, dst, flags);
}

HRESULT STDMETHODCALLTYPE DDS4GetAttachedSurface(DDS4 *This, DDSCAPS2 *caps, DDS4 **attachment)
{
    DPRINTF("trace %x", This);
    DPRINTF("caps = %x, caps2 = %x", caps->dwCaps, caps->dwCaps2);
    HRESULT rc = This->real->lpVtbl->GetAttachedSurface(This->real, caps, attachment);
    (*attachment) = IDDS4Create(*attachment);
    return rc;
}

HRESULT STDMETHODCALLTYPE DDS4GetPixelFormat(DDS4 *This, DDPIXELFORMAT *format)
{
    HRESULT rc = This->real->lpVtbl->GetPixelFormat(This->real, format);
    DPRINTF("flags = %x", format->dwFlags);
    return rc;
}

HRESULT STDMETHODCALLTYPE DDS4Lock(DDS4 *This, RECT *rect, DDSURFACEDESC2 *surface_desc, DWORD flags, HANDLE event)
{
    DPRINTF("trace %x", This);
    return This->real->lpVtbl->Lock(This->real, rect, surface_desc, flags, event);
}

HRESULT STDMETHODCALLTYPE DDS4Restore(DDS4 *This)
{
    DPRINTF("trace %x", This);
    return This->real->lpVtbl->Restore(This->real);
}

HRESULT STDMETHODCALLTYPE DDS4SetClipper(DDS4 *This, IDirectDrawClipper *clipper)
{
    DPRINTF("trace %x", This);
    return This->real->lpVtbl->SetClipper(This->real, clipper);
}

HRESULT STDMETHODCALLTYPE DDS4Unlock(DDS4 *This, LPRECT lpSurfaceData)
{
    DPRINTF("trace %x", This);
    return This->real->lpVtbl->Unlock(This->real, lpSurfaceData);
}

IDirectDrawSurface4Vtbl dds4Vtbl =
{
    //unk
    DDS4QueryInterface,
    DDS4AddRef,
    DDS4Release,
    //dds4
    DDS4AddAttachedSurface,
    DDS4AddOverlayDirtyRect,
    DDS4Blt,
    DDS4BltBatch,
    DDS4BltFast,
    DDS4DeleteAttachedSurface,
    DDS4EnumAttachedSurfaces,
    DDS4EnumOverlayZOrders,
    DDS4Flip,
    DDS4GetAttachedSurface,
    DDS4GetBltStatus,
    DDS4GetCaps,
    DDS4GetClipper,
    DDS4GetColorKey,
    DDS4GetDC,
    DDS4GetFlipStatus,
    DDS4GetOverlayPosition,
    DDS4GetPalette,
    DDS4GetPixelFormat,
    DDS4GetSurfaceDesc,
    DDS4Initialize,
    DDS4IsLost,
    DDS4Lock,
    DDS4ReleaseDC,
    DDS4Restore,
    DDS4SetClipper,
    DDS4SetColorKey,
    DDS4SetOverlayPosition,
    DDS4SetPalette,
    DDS4Unlock,
    DDS4UpdateOverlay,
    DDS4UpdateOverlayDisplay,
    DDS4UpdateOverlayZOrder,
    DDS4GetDDInterface,
    DDS4PageLock,
    DDS4PageUnlock,
    DDS4SetSurfaceDesc,
    DDS4SetPrivateData,
    DDS4GetPrivateData,
    DDS4FreePrivateData,
    DDS4GetUniquenessValue,
    DDS4ChangeUniquenessValue,
};

IDirectDrawSurface4* IDDS4Create(IDirectDrawSurface4* real)
{
    DDS4* fake = malloc(sizeof(DDS4));
    fake->lpVtbl = &dds4Vtbl;
    fake->real = real;
    DPRINTF("fake %x", fake);
    return fake;
}

IDirectDrawSurface4* IDDS4Query(IUNK* unk)
{
    IDirectDrawSurface4* real;
    //get the real pointer
    if(unk->real->lpVtbl->QueryInterface(unk->real, &IID_IDirectDrawSurface4, &real) != DD_OK)
    {
        DPRINTF("query interface failed with %d",DD_OK);
        ABORT();
    }


    DDS4* fake = malloc(sizeof(DDS4));
    fake->lpVtbl = &dds4Vtbl;
    fake->real = real;
    DPRINTF("trace %x", fake);
    return fake;
}

