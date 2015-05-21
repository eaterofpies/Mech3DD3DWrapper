#ifndef __H_DIRECTDRAWSURFACE
#define __H_DIRECTDRAWSURFACE

#include "Util.h"
#include "Unknown.h"

typedef struct DDS1
{
    IDirectDrawSurfaceVtbl* lpVtbl;
    IDirectDrawSurface* real;
} DDS1;

IDirectDrawSurface* IDDS1Create(IDirectDrawSurface* real);

#endif
