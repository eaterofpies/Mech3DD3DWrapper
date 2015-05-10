#ifndef __H_DIRECTDRAWSURFACE4
#define __H_DIRECTDRAWSURFACE4

#include "Util.h"

typedef struct DDS4
{
    IDirectDrawSurface4Vtbl* lpVtbl;
    IDirectDrawSurface4* real;
} DDS4;

void IDDS4Init(IDirectDrawSurface4**);

#endif
