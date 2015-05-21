

#include "Direct3DDevice3.h"
#include "Direct3DMaterial3.h"



typedef struct D3DM3
{
    IDirect3DMaterial3Vtbl* lpVtbl;
    IDirect3DMaterial3* real;
} D3DM3;

STDDDTYPEDEF(D3DM3, QueryInterface, D3DM3 *This, REFIID riid, void** ppvObject);
DDTYPEDEF(ULONG, D3DM3, AddRef, D3DM3 *This);
DDTYPEDEF(ULONG, D3DM3, Release, D3DM3 *This);
STDDDTYPEDEF(D3DM3, SetMaterial, D3DM3 *This, D3DMATERIAL *data);
STDDDTYPEDEF(D3DM3, GetMaterial, D3DM3 *This, D3DMATERIAL *data) ;
STDDDTYPEDEF(D3DM3, GetHandle, D3DM3 *This, struct D3DD3 *device, D3DMATERIALHANDLE *handle);

STDDDSTUB(D3DM3, QueryInterface, D3DM3* This, REFIID riid, void** ppvObject);
DDSTUB(ULONG, D3DM3, AddRef, D3DM3* This);
//DDSTUB(ULONG, D3DM3, Release, D3DM3* This);
//STDDDSTUB(D3DM3, SetMaterial, D3DM3 *This, D3DMATERIAL *data);
STDDDSTUB(D3DM3, GetMaterial, D3DM3 *This, D3DMATERIAL *data) ;
//STDDDSTUB(D3DM3, GetHandle, D3DM3 *This, struct D3DD3 *device, D3DMATERIALHANDLE *handle);

ULONG STDMETHODCALLTYPE D3DM3Release(D3DM3 *This)
{
    DPRINTF("trace");
    return IUNKRelease(This);
}

/*** IDirect3DMaterial3 methods ***/
HRESULT STDMETHODCALLTYPE D3DM3SetMaterial(D3DM3* This, D3DMATERIAL *data)
{
    DPRINTF("trace");
    return This->real->lpVtbl->SetMaterial(This->real, data);
}

HRESULT STDMETHODCALLTYPE D3DM3GetHandle(D3DM3* This, D3DD3 *device, D3DMATERIALHANDLE *handle)
{
    DPRINTF("trace");
    return This->real->lpVtbl->GetHandle(This->real, device->real, handle);
}

IDirect3D3Vtbl d3dm3Vtbl =
{
    D3DM3QueryInterface,
    D3DM3AddRef,
    D3DM3Release,
    D3DM3SetMaterial,
    D3DM3GetMaterial,
    D3DM3GetHandle
};

//Initialise ddraw structure
void ID3DM3Init(IDirect3DMaterial3** dd)
{
    DPRINTF("trace");

    //TODO currently not freed
    D3DM3* fake = malloc(sizeof(D3DM3));
    fake->lpVtbl = &d3dm3Vtbl;
    fake->real = *dd;

    *dd = fake;
}

