
#include <stdbool.h>

#include "Unknown.h"
#include "Direct3D3.h"
#include "Direct3DViewport3.h"
#include "DirectDrawSurface4.h"
#include "Direct3DDevice3.h"
#include "Direct3DMaterial3.h"

typedef struct D3D3
{
    IDirect3D3Vtbl* lpVtbl;
    IDirect3D3* real;
} D3D3;

STDDDTYPEDEF(D3D3, QueryInterface, D3D3* dd, REFIID riid, void** ppvObject);
DDTYPEDEF(ULONG, D3D3, AddRef, D3D3* dd);
DDTYPEDEF(ULONG, D3D3, Release, D3D3* dd);
STDDDTYPEDEF(D3D3, EnumDevices, D3D3* dd, LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpUserArg);
STDDDTYPEDEF(D3D3, CreateLight, D3D3* dd, struct IDirect3DLight **light, IUnknown *outer);
STDDDTYPEDEF(D3D3, CreateMaterial, D3D3* dd, struct IDirect3DMaterial3 **material, IUnknown *outer);
STDDDTYPEDEF(D3D3, CreateViewport, D3D3* dd, D3DV3 **viewport, IUnknown *outer);
STDDDTYPEDEF(D3D3, FindDevice, D3D3* dd, D3DFINDDEVICESEARCH *search, D3DFINDDEVICERESULT *result);
STDDDTYPEDEF(D3D3, CreateDevice, D3D3* dd, REFCLSID rclsid, DDS4 *surface,
        struct IDirect3DDevice3 **device, IUnknown *outer);
STDDDTYPEDEF(D3D3, CreateVertexBuffer, D3D3* dd, D3DVERTEXBUFFERDESC *desc, struct IDirect3DVertexBuffer **buffer,
        DWORD flags, IUnknown *outer);
STDDDTYPEDEF(D3D3, EnumZBufferFormats, D3D3* dd, REFCLSID riidDevice,LPD3DENUMPIXELFORMATSCALLBACK lpEnumCallback,LPVOID lpContext);
STDDDTYPEDEF(D3D3, EvictManagedTextures, D3D3* dd);


STDDDSTUB(D3D3, QueryInterface, D3D3* dd, REFIID riid, void** ppvObject);
DDSTUB(ULONG, D3D3, AddRef, D3D3* dd);
//DDSTUB(ULONG, D3D3, Release, D3D3* dd);
//STDDDSTUB(D3D3, EnumDevices, D3D3* dd, LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpUserArg);
STDDDSTUB(D3D3, CreateLight, D3D3* dd, struct IDirect3DLight **light, IUnknown *outer);
//STDDDSTUB(D3D3, CreateMaterial, D3D3* dd, struct IDirect3DMaterial3 **material, IUnknown *outer);
//STDDDSTUB(D3D3, CreateViewport, D3D3* dd, struct D3DV3 **viewport, IUnknown *outer);
STDDDSTUB(D3D3, FindDevice, D3D3* dd, D3DFINDDEVICESEARCH *search, D3DFINDDEVICERESULT *result);
//STDDDSTUB(D3D3, CreateDevice, D3D3* dd, REFCLSID rclsid, IDirectDrawSurface4 *surface,
//        struct IDirect3DDevice3 **device, IUnknown *outer);
STDDDSTUB(D3D3, CreateVertexBuffer, D3D3* dd, D3DVERTEXBUFFERDESC *desc, struct IDirect3DVertexBuffer **buffer,
        DWORD flags, IUnknown *outer);
//STDDDSTUB(D3D3, EnumZBufferFormats, D3D3* dd, REFCLSID riidDevice,LPD3DENUMPIXELFORMATSCALLBACK lpEnumCallback,LPVOID lpContext);
//STDDDSTUB(D3D3, EvictManagedTextures, D3D3* dd);



ULONG STDMETHODCALLTYPE D3D3Release(D3D3* dd)
{
    DPRINTF("trace");
    return IUNKRelease(dd);
}

HRESULT STDMETHODCALLTYPE D3D3EnumDevices(D3D3* dd, LPD3DENUMDEVICESCALLBACK lpEnumDevicesCallback, LPVOID lpUserArg)
{
    DPRINTF("trace");
    return dd->real->lpVtbl->EnumDevices(dd->real, lpEnumDevicesCallback, lpUserArg);
}

HRESULT STDMETHODCALLTYPE D3D3CreateMaterial(D3D3* dd, struct IDirect3DMaterial3 **material, IUnknown *outer)
{
    DPRINTF("trace");
    HRESULT rc = dd->real->lpVtbl->CreateMaterial(dd->real, material, outer);
    if(rc == D3D_OK)
    {
        //Swap the real material for a proxied one
        ID3DM3Init(material);
    }
    return rc;
}

HRESULT STDMETHODCALLTYPE  D3D3CreateViewport(D3D3* dd, struct D3DV3 **viewport, IUnknown *outer)
{
    DPRINTF("trace");
    HRESULT rc = dd->real->lpVtbl->CreateViewport(dd->real, viewport, outer);
    ID3DV3Init(viewport);
    return rc;
}

HRESULT STDMETHODCALLTYPE D3D3CreateDevice(D3D3* dd, REFCLSID rclsid, DDS4 *surface,
        struct IDirect3DDevice3 **device, IUnknown *outer)
{
    DPRINTF("trace");
    HRESULT rc = dd->real->lpVtbl->CreateDevice(dd->real, rclsid, surface->real, device, outer);

    if(rc == D3D_OK)
    {
        //Swap the real device for a proxied one
        ID3DD3Init(device);
    }

    return rc;
}



typedef struct LOCALPF {
    DWORD    dwSize;                 /* 0: size of structure */
    DWORD    dwFlags;                /* 4: pixel format flags */
    DWORD    dwFourCC;               /* 8: (FOURCC code) */
    DWORD    dwZBufferBitDepth;      /* C: how many bits for z buffers */
    union {
    DWORD    dwRBitMask;             /* 10: mask for red bit*/
    DWORD    dwYBitMask;             /* 10: mask for Y bits*/
    DWORD    dwStencilBitDepth;
    DWORD    dwLuminanceBitMask;
    DWORD    dwBumpDuBitMask;
    } DUMMYUNIONNAME2;
    union {
    DWORD    dwGBitMask;             /* 14: mask for green bits*/
    DWORD    dwUBitMask;             /* 14: mask for U bits*/
    DWORD    dwZBitMask;
    DWORD    dwBumpDvBitMask;
    } DUMMYUNIONNAME3;
    union {
    DWORD   dwBBitMask;             /* 18: mask for blue bits*/
    DWORD   dwVBitMask;             /* 18: mask for V bits*/
    DWORD    dwStencilBitMask;
    DWORD    dwBumpLuminanceBitMask;
    } DUMMYUNIONNAME4;
    union {
        DWORD    dwRGBAlphaBitMask;    /* 1C: mask for alpha channel */
        DWORD    dwYUVAlphaBitMask;    /* 1C: mask for alpha channel */
    DWORD    dwLuminanceAlphaBitMask;
    DWORD    dwRGBZBitMask;        /* 1C: mask for Z channel */
    DWORD    dwYUVZBitMask;        /* 1C: mask for Z channel */
    } DUMMYUNIONNAME5;
                        /* 20: next structure */
} LOCALPF,*LPLOCALPF;

typedef struct EnumZBufferFormatCTX
{
        LPD3DENUMPIXELFORMATSCALLBACK originalCB;
        void* realCTX;
        bool acceptedZBufferFormat;
        LOCALPF selectedZBufferFormat;
} EnumZBufferFormatCTX;

void SelectZBufferDepth(LPLOCALPF pixFmt, EnumZBufferFormatCTX* ctx)
{
    //if we dont have one that might work then select one
    if(ctx->acceptedZBufferFormat == false)
    {
        ctx->acceptedZBufferFormat = true;
        ctx->selectedZBufferFormat = *pixFmt;
        return;
    }

    //if we have a higher bit depth then select that one
    if(ctx->selectedZBufferFormat.dwZBufferBitDepth < pixFmt->dwZBufferBitDepth)
    {
        ctx->selectedZBufferFormat = *pixFmt;
        return;
    }
}

// Gets called by D3D3EnumZBufferFormats
// Always returns failure so we get a full list of zbuffer formats
HRESULT STDMETHODCALLTYPE CheckAllZBufFormatsCallback(LPLOCALPF pixFmt, LPVOID ctxIn)
{
    EnumZBufferFormatCTX* ctx = ctxIn;
    HRESULT rc = ctx->originalCB(pixFmt, ctx->realCTX);
    if(rc == D3DENUMRET_CANCEL)
    {
        //original code thought it was good so store it if its better
        SelectZBufferDepth(pixFmt, ctx);
    }

    DPRINTF("trace\nsize: %d\nflags: %x\nzbuffer depth: %d\n",
        pixFmt->dwSize, pixFmt->dwFlags, pixFmt->dwZBufferBitDepth);
    return D3DENUMRET_OK;
}

// Gets called by D3D3EnumZBufferFormats
// use the z buffer depth selected by the previous function
HRESULT STDMETHODCALLTYPE GetFinalZBufFormat(LPLOCALPF pixFmt, LPVOID ctxIn)
{
    EnumZBufferFormatCTX* ctx = ctxIn;
    HRESULT rc = ctx->originalCB(pixFmt, ctx->realCTX);
    DPRINTF("trace\nsize: %d\nflags: %x\nzbuffer depth: %d\n",
        pixFmt->dwSize, pixFmt->dwFlags, pixFmt->dwZBufferBitDepth);

    //TODO should do a complete check here
    if(rc == 0
        && ctx->selectedZBufferFormat.dwZBufferBitDepth == pixFmt->dwZBufferBitDepth
        && ctx->selectedZBufferFormat.dwFlags == pixFmt->dwFlags)
    {
        //Found the best match again

        return 0;
    }

    return D3DENUMRET_OK;
}


HRESULT STDMETHODCALLTYPE D3D3EnumZBufferFormats(D3D3* dd, REFCLSID riidDevice,LPD3DENUMPIXELFORMATSCALLBACK lpEnumCallback,LPVOID lpContext)
{
    DPRINTF("trace");
    EnumZBufferFormatCTX fakeCTX;
    fakeCTX.realCTX = lpContext;
    fakeCTX.originalCB = lpEnumCallback;
    fakeCTX.acceptedZBufferFormat = false;

    //call to make sure we iterate through all zbuffer formats
    (void)dd->real->lpVtbl->EnumZBufferFormats(dd->real, riidDevice, &CheckAllZBufFormatsCallback, &fakeCTX);

    //second call is to select a zbuffer format
    return dd->real->lpVtbl->EnumZBufferFormats(dd->real, riidDevice, &GetFinalZBufFormat, &fakeCTX);
}

HRESULT STDMETHODCALLTYPE D3D3EvictManagedTextures(D3D3* dd)
{
    DPRINTF("trace");
    return dd->real->lpVtbl->EvictManagedTextures(dd->real);
}



IDirect3D3Vtbl d3d3Vtbl =
{
    D3D3QueryInterface,
    D3D3AddRef,
    D3D3Release,
    D3D3EnumDevices,
    D3D3CreateLight,
    D3D3CreateMaterial,
    D3D3CreateViewport,
    D3D3FindDevice,
    D3D3CreateDevice,
    D3D3CreateVertexBuffer,
    D3D3EnumZBufferFormats,
    D3D3EvictManagedTextures
};


IDirect3D3* ID3D3Query(IUNK* unk)
{
    IDirect3D3* real;
    //get the real pointer
    if(unk->real->lpVtbl->QueryInterface(unk->real, &IID_IDirect3D3, &real) != DD_OK)
    {
        DPRINTF("query interface failed with %d",DD_OK);
        ABORT();
    }

    DPRINTF("trace");

    D3D3* fake = malloc(sizeof(D3D3));
    fake->lpVtbl = &d3d3Vtbl;
    fake->real = real;
    return fake;
}

