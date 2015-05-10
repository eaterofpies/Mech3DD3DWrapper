#ifndef __H_UNKNOWN
#define __H_UNKNOWN

#include "Util.h"

typedef struct IUNK
{
    IUnknownVtbl* lpVtbl;
    IUnknown* real;
} IUNK;

STDDDTYPEDEF(IUNK, QueryInterface, IUNK* dd, REFIID riid, void** ppvObject);
DDTYPEDEF(ULONG, IUNK, AddRef, IUNK* dd);
DDTYPEDEF(ULONG, IUNK, Release, IUNK* dd);

#endif
