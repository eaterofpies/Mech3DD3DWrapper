#ifndef __H_DIRECT3DD3
#define __H_DIRECT3DD3

#include "Util.h"

void ID3DD3Init(IDirect3DDevice3**);


typedef struct D3DD3
{
    IDirect3DDevice3Vtbl* lpVtbl;
    IDirect3DDevice3* real;
} D3DD3;

#endif

