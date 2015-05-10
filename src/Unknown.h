#ifndef __H_UNKNOWN
#define __H_UNKNOWN

#include "Util.h"

typedef struct IUNKVtbl IUNKVtbl;

typedef struct IUNK
{
    IUNKVtbl* lpVtbl;
    IUnknown* real;
} IUNK;

//functions actually used in the game
HRESULT STDMETHODCALLTYPE IUNKQueryInterface(IUNK* dd, const IID* const riid, void** ppvObject);
ULONG STDMETHODCALLTYPE IUNKRelease(IUNK* dd);
ULONG STDMETHODCALLTYPE IUNKAddRef(IUNK* dd);

STDDDTYPEDEF(IUNK, QueryInterface, IUNK* dd, REFIID riid, void** ppvObject);
DDTYPEDEF(ULONG, IUNK, AddRef, IUNK* dd);
DDTYPEDEF(ULONG, IUNK, Release, IUNK* dd);

//Define Vtable and objects compatible with what we give to mw3
typedef struct IUNKVtbl
{
    IUNKQueryInterfacePtr QueryInterface;
    IUNKAddRefPtr AddRef;
    IUNKReleasePtr Release;
};

#endif
