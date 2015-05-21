#ifndef __H_DIRECTDRAWSURFACE3
#define __H_DIRECTDRAWSURFACE3

#include "Util.h"
#include "Unknown.h"

typedef struct DDS3
{
    IDirectDrawSurface3Vtbl* lpVtbl;
    IDirectDrawSurface3* real;
} DDS3;
IDirectDrawSurface3* IDDS3Query(IUNK* unk);

#endif
