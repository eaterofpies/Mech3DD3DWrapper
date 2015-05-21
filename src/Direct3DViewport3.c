#include "Direct3DViewport3.h"

STDDDTYPEDEF(D3DV3, QueryInterface, D3DV3 *This, REFIID riid, void** ppvObject);
DDTYPEDEF(ULONG, D3DV3, AddRef, D3DV3 *This);
DDTYPEDEF(ULONG, D3DV3, Release, D3DV3 *This);

STDDDTYPEDEF(D3DV3, Initialize, D3DV3 *This, IDirect3D *d3d) ;
STDDDTYPEDEF(D3DV3, GetViewport, D3DV3 *This, D3DVIEWPORT *data) ;
STDDDTYPEDEF(D3DV3, SetViewport, D3DV3 *This, D3DVIEWPORT *data) ;
STDDDTYPEDEF(D3DV3, TransformVertices, D3DV3 *This, DWORD vertex_count, D3DTRANSFORMDATA *data, DWORD flags, DWORD *offscreen) ;
STDDDTYPEDEF(D3DV3, LightElements, D3DV3 *This, DWORD element_count, D3DLIGHTDATA *data) ;
STDDDTYPEDEF(D3DV3, SetBackground, D3DV3 *This, D3DMATERIALHANDLE hMat) ;
STDDDTYPEDEF(D3DV3, GetBackground, D3DV3 *This, D3DMATERIALHANDLE *material, BOOL *valid) ;
STDDDTYPEDEF(D3DV3, SetBackgroundDepth, D3DV3 *This, IDirectDrawSurface *surface) ;
STDDDTYPEDEF(D3DV3, GetBackgroundDepth, D3DV3 *This, IDirectDrawSurface **surface, BOOL *valid) ;
STDDDTYPEDEF(D3DV3, Clear, D3DV3 *This, DWORD count, D3DRECT *rects, DWORD flags) ;
STDDDTYPEDEF(D3DV3, AddLight, D3DV3 *This, IDirect3DLight *light) ;
STDDDTYPEDEF(D3DV3, DeleteLight, D3DV3 *This, IDirect3DLight *light) ;
STDDDTYPEDEF(D3DV3, NextLight, D3DV3 *This, IDirect3DLight *ref, IDirect3DLight **light, DWORD flags) ;
STDDDTYPEDEF(D3DV3, GetViewport2, D3DV3 *This, D3DVIEWPORT2 *data) ;
STDDDTYPEDEF(D3DV3, SetViewport2, D3DV3 *This, D3DVIEWPORT2 *data) ;
STDDDTYPEDEF(D3DV3, SetBackgroundDepth2, D3DV3 *This, IDirectDrawSurface4 *surface) ;
STDDDTYPEDEF(D3DV3, GetBackgroundDepth2, D3DV3 *This, IDirectDrawSurface4 **surface, BOOL *valid) ;
STDDDTYPEDEF(D3DV3, Clear2, D3DV3 *This, DWORD count, D3DRECT *rects, DWORD flags, DWORD color, D3DVALUE z, DWORD stencil) ;


STDDDSTUB(D3DV3, QueryInterface, D3DV3* This, REFIID riid, void** ppvObject);
DDSTUB(ULONG, D3DV3, AddRef, D3DV3* This);
//DDSTUB(ULONG, D3DV3, Release, D3DV3* This);
STDDDSTUB(D3DV3, Initialize, D3DV3 *This, IDirect3D *d3d) ;
STDDDSTUB(D3DV3, GetViewport, D3DV3 *This, D3DVIEWPORT *data) ;
STDDDSTUB(D3DV3, SetViewport, D3DV3 *This, D3DVIEWPORT *data) ;
STDDDSTUB(D3DV3, TransformVertices, D3DV3 *This, DWORD vertex_count, D3DTRANSFORMDATA *data, DWORD flags, DWORD *offscreen) ;
STDDDSTUB(D3DV3, LightElements, D3DV3 *This, DWORD element_count, D3DLIGHTDATA *data) ;
//STDDDSTUB(D3DV3, SetBackground, D3DV3 *This, D3DMATERIALHANDLE hMat) ;
STDDDSTUB(D3DV3, GetBackground, D3DV3 *This, D3DMATERIALHANDLE *material, BOOL *valid) ;
STDDDSTUB(D3DV3, SetBackgroundDepth, D3DV3 *This, IDirectDrawSurface *surface) ;
STDDDSTUB(D3DV3, GetBackgroundDepth, D3DV3 *This, IDirectDrawSurface **surface, BOOL *valid) ;
STDDDSTUB(D3DV3, Clear, D3DV3 *This, DWORD count, D3DRECT *rects, DWORD flags) ;
STDDDSTUB(D3DV3, AddLight, D3DV3 *This, IDirect3DLight *light) ;
STDDDSTUB(D3DV3, DeleteLight, D3DV3 *This, IDirect3DLight *light) ;
STDDDSTUB(D3DV3, NextLight, D3DV3 *This, IDirect3DLight *ref, IDirect3DLight **light, DWORD flags) ;
STDDDSTUB(D3DV3, GetViewport2, D3DV3 *This, D3DVIEWPORT2 *data) ;
//STDDDSTUB(D3DV3, SetViewport2, D3DV3 *This, D3DVIEWPORT2 *data) ;
STDDDSTUB(D3DV3, SetBackgroundDepth2, D3DV3 *This, IDirectDrawSurface4 *surface) ;
STDDDSTUB(D3DV3, GetBackgroundDepth2, D3DV3 *This, IDirectDrawSurface4 **surface, BOOL *valid) ;
STDDDSTUB(D3DV3, Clear2, D3DV3 *This, DWORD count, D3DRECT *rects, DWORD flags, DWORD color, D3DVALUE z, DWORD stencil) ;

ULONG STDMETHODCALLTYPE D3DV3Release(D3DV3 *This)
{
	DPRINTF("trace");
	return IUNKRelease(This);
}

HRESULT STDMETHODCALLTYPE D3DV3SetBackground(D3DV3 *This, D3DMATERIALHANDLE hMat)
{
	DPRINTF("trace");
	return This->real->lpVtbl->SetBackground(This->real, hMat);
}

HRESULT STDMETHODCALLTYPE D3DV3SetViewport2(D3DV3 *This, D3DVIEWPORT2 *data)
{
	DPRINTF("minZ %f\nmaxZ %f", data->dvMinZ, data->dvMaxZ);
	return This->real->lpVtbl->SetViewport2(This->real, data);
}



IDirect3DViewport3Vtbl d3dv3Vtbl =
{
	D3DV3QueryInterface,
	D3DV3AddRef,
	D3DV3Release,
	D3DV3Initialize,
	D3DV3GetViewport,
	D3DV3SetViewport,
	D3DV3TransformVertices,
	D3DV3LightElements,
	D3DV3SetBackground,
	D3DV3GetBackground,
	D3DV3SetBackgroundDepth,
	D3DV3GetBackgroundDepth,
	D3DV3Clear,
	D3DV3AddLight,
	D3DV3DeleteLight,
	D3DV3NextLight,
	D3DV3GetViewport2,
	D3DV3SetViewport2,
	D3DV3SetBackgroundDepth2,
	D3DV3GetBackgroundDepth2,
	D3DV3Clear2
};

//Initialise ddraw structure
void ID3DV3Init(IDirect3DViewport3** dd)
{
	DPRINTF("trace");

	//TODO currently not freed
    D3DV3* fake = malloc(sizeof(D3DV3));
	fake->lpVtbl = &d3dv3Vtbl;
    fake->real = *dd;
    *dd = fake;
}




