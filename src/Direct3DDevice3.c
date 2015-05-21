
#include "Direct3DViewport3.h"
#include "Direct3DDevice3.h"

STDDDTYPEDEF(D3DD3, QueryInterface, D3DD3 *This, REFIID riid, void** ppvObject);
DDTYPEDEF(ULONG, D3DD3, AddRef, D3DD3 *This);
DDTYPEDEF(ULONG, D3DD3, Release, D3DD3 *This);
STDDDTYPEDEF(D3DD3, GetCaps, D3DD3 *This, D3DDEVICEDESC *hal_desc, D3DDEVICEDESC *hel_desc) ;
STDDDTYPEDEF(D3DD3, GetStats, D3DD3 *This, D3DSTATS *stats) ;
STDDDTYPEDEF(D3DD3, AddViewport, D3DD3 *This, D3DV3 *viewport) ;
STDDDTYPEDEF(D3DD3, DeleteViewport, D3DD3 *This, D3DV3 *viewport) ;
STDDDTYPEDEF(D3DD3, NextViewport, D3DD3 *This, D3DV3 *ref,
		D3DV3 **viewport, DWORD flags) ;
STDDDTYPEDEF(D3DD3, EnumTextureFormats, D3DD3 *This, LPD3DENUMPIXELFORMATSCALLBACK lpD3DEnumPixelProc, LPVOID lpArg) ;
STDDDTYPEDEF(D3DD3, BeginScene, D3DD3 *This) ;
STDDDTYPEDEF(D3DD3, EndScene, D3DD3 *This) ;
STDDDTYPEDEF(D3DD3, GetDirect3D, D3DD3 *This, IDirect3D3 **d3d) ;
STDDDTYPEDEF(D3DD3, SetCurrentViewport, D3DD3 *This, D3DV3 *viewport) ;
STDDDTYPEDEF(D3DD3, GetCurrentViewport, D3DD3 *This, D3DV3 **viewport) ;
STDDDTYPEDEF(D3DD3, SetRenderTarget, D3DD3 *This, IDirectDrawSurface4 *surface, DWORD flags) ;
STDDDTYPEDEF(D3DD3, GetRenderTarget, D3DD3 *This, IDirectDrawSurface4 **surface) ;
STDDDTYPEDEF(D3DD3, Begin, D3DD3 *This, D3DPRIMITIVETYPE d3dptPrimitiveType,DWORD dwVertexTypeDesc, DWORD dwFlags) ;
STDDDTYPEDEF(D3DD3, BeginIndexed, D3DD3 *This, D3DPRIMITIVETYPE d3dptPrimitiveType,DWORD d3dvtVertexType, LPVOID lpvVertices, DWORD dwNumVertices, DWORD dwFlags) ;
STDDDTYPEDEF(D3DD3, Vertex, D3DD3 *This, LPVOID lpVertexType) ;
STDDDTYPEDEF(D3DD3, Index, D3DD3 *This, WORD wVertexIndex) ;
STDDDTYPEDEF(D3DD3, End, D3DD3 *This, DWORD dwFlags) ;
STDDDTYPEDEF(D3DD3, GetRenderState, D3DD3 *This, D3DRENDERSTATETYPE dwRenderStateType, LPDWORD lpdwRenderState) ;
STDDDTYPEDEF(D3DD3, SetRenderState, D3DD3 *This, D3DRENDERSTATETYPE dwRenderStateType, DWORD dwRenderState) ;
STDDDTYPEDEF(D3DD3, GetLightState, D3DD3 *This, D3DLIGHTSTATETYPE dwLightStateType, LPDWORD lpdwLightState) ;
STDDDTYPEDEF(D3DD3, SetLightState, D3DD3 *This, D3DLIGHTSTATETYPE dwLightStateType, DWORD dwLightState) ;
STDDDTYPEDEF(D3DD3, SetTransform, D3DD3 *This, D3DTRANSFORMSTATETYPE state, D3DMATRIX *matrix) ;
STDDDTYPEDEF(D3DD3, GetTransform, D3DD3 *This, D3DTRANSFORMSTATETYPE state, D3DMATRIX *matrix) ;
STDDDTYPEDEF(D3DD3, MultiplyTransform, D3DD3 *This, D3DTRANSFORMSTATETYPE state, D3DMATRIX *matrix) ;
STDDDTYPEDEF(D3DD3, DrawPrimitive, D3DD3 *This, D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD d3dvtVertexType, LPVOID lpvVertices, DWORD dwVertexCount, DWORD dwFlags) ;
STDDDTYPEDEF(D3DD3, DrawIndexedPrimitive, D3DD3 *This, D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD d3dvtVertexType, LPVOID lpvVertices, DWORD dwVertexCount, LPWORD dwIndices, DWORD dwIndexCount, DWORD dwFlags) ;
STDDDTYPEDEF(D3DD3, SetClipStatus, D3DD3 *This, D3DCLIPSTATUS *clip_status) ;
STDDDTYPEDEF(D3DD3, GetClipStatus, D3DD3 *This, D3DCLIPSTATUS *clip_status) ;
STDDDTYPEDEF(D3DD3, DrawPrimitiveStrided, D3DD3 *This, D3DPRIMITIVETYPE primitive_type, DWORD fvf,
		D3DDRAWPRIMITIVESTRIDEDDATA *strided_data, DWORD vertex_count, DWORD flags) ;
STDDDTYPEDEF(D3DD3, DrawIndexedPrimitiveStrided, D3DD3 *This, D3DPRIMITIVETYPE primitive_type, DWORD fvf,
		D3DDRAWPRIMITIVESTRIDEDDATA *strided_data, DWORD vertex_count, WORD *indices, DWORD index_count,
		DWORD flags) ;
STDDDTYPEDEF(D3DD3, DrawPrimitiveVB, D3DD3 *This, D3DPRIMITIVETYPE primitive_type, struct IDirect3DVertexBuffer *vb,
		DWORD start_vertex, DWORD vertex_count, DWORD flags) ;
STDDDTYPEDEF(D3DD3, DrawIndexedPrimitiveVB, D3DD3 *This, D3DPRIMITIVETYPE primitive_type, struct IDirect3DVertexBuffer *vb,
		WORD *indices, DWORD index_count, DWORD flags) ;
STDDDTYPEDEF(D3DD3, ComputeSphereVisibility, D3DD3 *This, D3DVECTOR *centers, D3DVALUE *radii, DWORD sphere_count,
		DWORD flags, DWORD *ret) ;
STDDDTYPEDEF(D3DD3, GetTexture, D3DD3 *This, DWORD stage, IDirect3DTexture2 **texture) ;
STDDDTYPEDEF(D3DD3, SetTexture, D3DD3 *This, DWORD stage, IDirect3DTexture2 *texture) ;
STDDDTYPEDEF(D3DD3, GetTextureStageState, D3DD3 *This, DWORD dwStage,D3DTEXTURESTAGESTATETYPE d3dTexStageStateType,LPDWORD lpdwState) ;
STDDDTYPEDEF(D3DD3, SetTextureStageState, D3DD3 *This, DWORD dwStage,D3DTEXTURESTAGESTATETYPE d3dTexStageStateType,DWORD dwState) ;
STDDDTYPEDEF(D3DD3, ValidateDevice, D3DD3 *This, LPDWORD lpdwPasses) ;


STDDDSTUB(D3DD3, QueryInterface, D3DD3* This, REFIID riid, void** ppvObject);
DDSTUB(ULONG, D3DD3, AddRef, D3DD3* This);
//DDSTUB(ULONG, D3DD3, Release, D3DD3* This);
//STDDDSTUB(D3DD3, GetCaps, D3DD3 *This, D3DDEVICEDESC *hal_desc, D3DDEVICEDESC *hel_desc) ;
STDDDSTUB(D3DD3, GetStats, D3DD3 *This, D3DSTATS *stats) ;
//STDDDSTUB(D3DD3, AddViewport, D3DD3 *This, D3DV3 *viewport) ;
STDDDSTUB(D3DD3, DeleteViewport, D3DD3 *This, D3DV3 *viewport) ;
STDDDSTUB(D3DD3, NextViewport, D3DD3 *This, D3DV3 *ref,
		D3DV3 **viewport, DWORD flags) ;
//STDDDSTUB(D3DD3, EnumTextureFormats, D3DD3 *This, LPD3DENUMPIXELFORMATSCALLBACK lpD3DEnumPixelProc, LPVOID lpArg) ;
//STDDDSTUB(D3DD3, BeginScene, D3DD3 *This) ;
//STDDDSTUB(D3DD3, EndScene, D3DD3 *This) ;
STDDDSTUB(D3DD3, GetDirect3D, D3DD3 *This, IDirect3D3 **d3d) ;
//STDDDSTUB(D3DD3, SetCurrentViewport, D3DD3 *This, D3DV3 *viewport) ;
STDDDSTUB(D3DD3, GetCurrentViewport, D3DD3 *This, D3DV3 **viewport) ;
STDDDSTUB(D3DD3, SetRenderTarget, D3DD3 *This, IDirectDrawSurface4 *surface, DWORD flags) ;
STDDDSTUB(D3DD3, GetRenderTarget, D3DD3 *This, IDirectDrawSurface4 **surface) ;
STDDDSTUB(D3DD3, Begin, D3DD3 *This, D3DPRIMITIVETYPE d3dptPrimitiveType,DWORD dwVertexTypeDesc, DWORD dwFlags) ;
STDDDSTUB(D3DD3, BeginIndexed, D3DD3 *This, D3DPRIMITIVETYPE d3dptPrimitiveType,DWORD d3dvtVertexType, LPVOID lpvVertices, DWORD dwNumVertices, DWORD dwFlags) ;
STDDDSTUB(D3DD3, Vertex, D3DD3 *This, LPVOID lpVertexType) ;
STDDDSTUB(D3DD3, Index, D3DD3 *This, WORD wVertexIndex) ;
STDDDSTUB(D3DD3, End, D3DD3 *This, DWORD dwFlags) ;
STDDDSTUB(D3DD3, GetRenderState, D3DD3 *This, D3DRENDERSTATETYPE dwRenderStateType, LPDWORD lpdwRenderState) ;
//STDDDSTUB(D3DD3, SetRenderState, D3DD3 *This, D3DRENDERSTATETYPE dwRenderStateType, DWORD dwRenderState) ;
STDDDSTUB(D3DD3, GetLightState, D3DD3 *This, D3DLIGHTSTATETYPE dwLightStateType, LPDWORD lpdwLightState) ;
//STDDDSTUB(D3DD3, SetLightState, D3DD3 *This, D3DLIGHTSTATETYPE dwLightStateType, DWORD dwLightState) ;
STDDDSTUB(D3DD3, SetTransform, D3DD3 *This, D3DTRANSFORMSTATETYPE state, D3DMATRIX *matrix) ;
STDDDSTUB(D3DD3, GetTransform, D3DD3 *This, D3DTRANSFORMSTATETYPE state, D3DMATRIX *matrix) ;
STDDDSTUB(D3DD3, MultiplyTransform, D3DD3 *This, D3DTRANSFORMSTATETYPE state, D3DMATRIX *matrix) ;
//STDDDSTUB(D3DD3, DrawPrimitive, D3DD3 *This, D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD d3dvtVertexType, LPVOID lpvVertices, DWORD dwVertexCount, DWORD dwFlags) ;
STDDDSTUB(D3DD3, DrawIndexedPrimitive, D3DD3 *This, D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD d3dvtVertexType, LPVOID lpvVertices, DWORD dwVertexCount, LPWORD dwIndices, DWORD dwIndexCount, DWORD dwFlags) ;
STDDDSTUB(D3DD3, SetClipStatus, D3DD3 *This, D3DCLIPSTATUS *clip_status) ;
STDDDSTUB(D3DD3, GetClipStatus, D3DD3 *This, D3DCLIPSTATUS *clip_status) ;
STDDDSTUB(D3DD3, DrawPrimitiveStrided, D3DD3 *This, D3DPRIMITIVETYPE primitive_type, DWORD fvf,
		D3DDRAWPRIMITIVESTRIDEDDATA *strided_data, DWORD vertex_count, DWORD flags) ;
STDDDSTUB(D3DD3, DrawIndexedPrimitiveStrided, D3DD3 *This, D3DPRIMITIVETYPE primitive_type, DWORD fvf,
		D3DDRAWPRIMITIVESTRIDEDDATA *strided_data, DWORD vertex_count, WORD *indices, DWORD index_count,
		DWORD flags) ;
STDDDSTUB(D3DD3, DrawPrimitiveVB, D3DD3 *This, D3DPRIMITIVETYPE primitive_type, struct IDirect3DVertexBuffer *vb,
		DWORD start_vertex, DWORD vertex_count, DWORD flags) ;
STDDDSTUB(D3DD3, DrawIndexedPrimitiveVB, D3DD3 *This, D3DPRIMITIVETYPE primitive_type, struct IDirect3DVertexBuffer *vb,
		WORD *indices, DWORD index_count, DWORD flags) ;
STDDDSTUB(D3DD3, ComputeSphereVisibility, D3DD3 *This, D3DVECTOR *centers, D3DVALUE *radii, DWORD sphere_count,
		DWORD flags, DWORD *ret) ;
STDDDSTUB(D3DD3, GetTexture, D3DD3 *This, DWORD stage, IDirect3DTexture2 **texture) ;
//STDDDSTUB(D3DD3, SetTexture, D3DD3 *This, DWORD stage, IDirect3DTexture2 *texture) ;
STDDDSTUB(D3DD3, GetTextureStageState, D3DD3 *This, DWORD dwStage,D3DTEXTURESTAGESTATETYPE d3dTexStageStateType,LPDWORD lpdwState) ;
//STDDDSTUB(D3DD3, SetTextureStageState, D3DD3 *This, DWORD dwStage,D3DTEXTURESTAGESTATETYPE d3dTexStageStateType,DWORD dwState) ;
STDDDSTUB(D3DD3, ValidateDevice, D3DD3 *This, LPDWORD lpdwPasses) ;

ULONG STDMETHODCALLTYPE D3DD3Release(D3DD3* This)
{
    DPRINTF("trace");
    return IUNKRelease(This);
}

HRESULT STDMETHODCALLTYPE D3DD3GetCaps(D3DD3 *This, D3DDEVICEDESC *hal_desc, D3DDEVICEDESC *hel_desc)
{
	DPRINTF("trace");
	return This->real->lpVtbl->GetCaps(This->real, hal_desc, hel_desc);
}

HRESULT STDMETHODCALLTYPE D3DD3AddViewport(D3DD3 *This, D3DV3 *viewport)
{
	DPRINTF("trace");
	return This->real->lpVtbl->AddViewport(This->real, viewport->real);
}

HRESULT STDMETHODCALLTYPE D3DD3EnumTextureFormats(D3DD3 *This, LPD3DENUMPIXELFORMATSCALLBACK lpD3DEnumPixelProc, LPVOID lpArg)
{
	DPRINTF("trace");
	return This->real->lpVtbl->EnumTextureFormats(This->real, lpD3DEnumPixelProc, lpArg);
}

HRESULT STDMETHODCALLTYPE D3DD3BeginScene(D3DD3 *This)
{
	DPRINTF("trace");
	return This->real->lpVtbl->BeginScene(This->real);
}

HRESULT STDMETHODCALLTYPE D3DD3EndScene(D3DD3 *This)
{
	DPRINTF("trace");
	return This->real->lpVtbl->EndScene(This->real);
}

HRESULT STDMETHODCALLTYPE D3DD3SetCurrentViewport(D3DD3 *This, D3DV3 *viewport)
{
	DPRINTF("trace");
	return This->real->lpVtbl->SetCurrentViewport(This->real, viewport->real);
}

HRESULT STDMETHODCALLTYPE D3DD3SetRenderState(D3DD3 *This, D3DRENDERSTATETYPE dwRenderStateType, DWORD dwRenderState)
{
	PrintRenderstate(dwRenderStateType, dwRenderState);
#if 0
	if (dwRenderStateType == D3DRENDERSTATE_FOGENABLE)
	{
		dwRenderState = 0;
	}
#endif
	return This->real->lpVtbl->SetRenderState(This->real, dwRenderStateType, dwRenderState);
}

HRESULT STDMETHODCALLTYPE D3DD3SetLightState(D3DD3 *This, D3DLIGHTSTATETYPE dwLightStateType, DWORD dwLightState)
{
	DPRINTF("trace");
	return This->real->lpVtbl->SetLightState(This->real, dwLightStateType, dwLightState);
}

HRESULT STDMETHODCALLTYPE D3DD3DrawPrimitive(D3DD3 *This, D3DPRIMITIVETYPE d3dptPrimitiveType, DWORD d3dvtVertexType,
	LPVOID lpvVertices, DWORD dwVertexCount, DWORD dwFlags)
{
	// flags can be
	// D3DDP_WAIT               __MSABI_LONG(0x00000001)
	// D3DDP_DONOTCLIP          __MSABI_LONG(0x00000004)
	// D3DDP_DONOTUPDATEEXTENTS __MSABI_LONG(0x00000008)
	// D3DDP_DONOTLIGHT         __MSABI_LONG(0x00000010)

	// D3DFVF
	// all vertex types are 1c4, 2c4 / 3c4
	// 1, 2 or 3 textures
	// diffuse
	// specular
	// xyz rhw - something to do with GUIs??
/*	DPRINTF
	(
		"primitiveType %x\n"
		"vertexType %x\n"
		"vertices %d\n"
		"flags %x",
		d3dptPrimitiveType,
		d3dvtVertexType,
		dwVertexCount,
		dwFlags
	);*/
	return This->real->lpVtbl->DrawPrimitive
	(
		This->real,
		d3dptPrimitiveType,
		d3dvtVertexType,
		lpvVertices,
		dwVertexCount,
		dwFlags
	);
}

HRESULT STDMETHODCALLTYPE D3DD3SetTexture(D3DD3 *This, DWORD stage, IDirect3DTexture2 *texture)
{
	DPRINTF("trace");
	return This->real->lpVtbl->SetTexture(This->real, stage, texture);
}

HRESULT STDMETHODCALLTYPE D3DD3SetTextureStageState(D3DD3 *This, DWORD dwStage, D3DTEXTURESTAGESTATETYPE d3dTexStageStateType,DWORD dwState)
{
	DPRINTF("trace");
	return This->real->lpVtbl->SetTextureStageState(This->real, dwStage, d3dTexStageStateType, dwState);
}
IDirect3DDevice3Vtbl d3dd3Vtbl =
{
	D3DD3QueryInterface,
	D3DD3AddRef,
	D3DD3Release,
	D3DD3GetCaps,
	D3DD3GetStats,
	D3DD3AddViewport,
	D3DD3DeleteViewport,
	D3DD3NextViewport,
	D3DD3EnumTextureFormats,
	D3DD3BeginScene,
	D3DD3EndScene,
	D3DD3GetDirect3D,
	D3DD3SetCurrentViewport,
	D3DD3GetCurrentViewport,
	D3DD3SetRenderTarget,
	D3DD3GetRenderTarget,
	D3DD3Begin,
	D3DD3BeginIndexed,
	D3DD3Vertex,
	D3DD3Index,
	D3DD3End,
	D3DD3GetRenderState,
	D3DD3SetRenderState,
	D3DD3GetLightState,
	D3DD3SetLightState,
	D3DD3SetTransform,
	D3DD3GetTransform,
	D3DD3MultiplyTransform,
	D3DD3DrawPrimitive,
	D3DD3DrawIndexedPrimitive,
	D3DD3SetClipStatus,
	D3DD3GetClipStatus,
	D3DD3DrawPrimitiveStrided,
	D3DD3DrawIndexedPrimitiveStrided,
	D3DD3DrawPrimitiveVB,
	D3DD3DrawIndexedPrimitiveVB,
	D3DD3ComputeSphereVisibility,
	D3DD3GetTexture,
	D3DD3SetTexture,
	D3DD3GetTextureStageState,
	D3DD3SetTextureStageState,
	D3DD3ValidateDevice
};

//Initialise ddraw structure
void ID3DD3Init(IDirect3DDevice3** dd)
{
	DPRINTF("trace");

    D3DD3* fake = malloc(sizeof(D3DD3));
	fake->lpVtbl = &d3dd3Vtbl;
    fake->real = *dd;
    *dd = fake;
}

