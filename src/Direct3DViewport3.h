#ifndef __H_DIRECT3DV3
#define __H_DIRECT3DV3

#include "Util.h"

void ID3DV3Init(IDirect3DViewport3**);

typedef struct D3DV3
{
    IDirect3DViewport3Vtbl* lpVtbl;
    IDirect3DViewport3* real;
} D3DV3;

#endif

