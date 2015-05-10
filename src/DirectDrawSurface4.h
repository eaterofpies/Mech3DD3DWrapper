#ifndef __H_DIRECTDRAWSURFACE4
#define __H_DIRECTDRAWSURFACE4

#include "Util.h"
#include "Unknown.h"

typedef struct DDS4
{
    IDirectDrawSurface4Vtbl* lpVtbl;
    IDirectDrawSurface4* real;
} DDS4;

IDirectDrawSurface4* IDDS4Create(IDirectDrawSurface4* real);
IDirectDrawSurface4* IDDS4Query(IUNK* unk);

#endif
