#ifndef __H_UTIL
#define __H_UTIL

#include <ddraw.h>
#include <d3d.h>
#include <stdio.h>
extern FILE* logfd;

//Debug macros
#define DPRINTF(args...) \
do \
{ \
	fprintf(logfd, "------------\n%s:%s:%d\n",__func__,__FILE__,__LINE__); \
	fprintf(logfd, args); \
	fprintf(logfd, "\n------------\n"); \
} while(0)

//Macros for generating typedefs for directdraw apis
#define DDTYPEDEF(rtype, iface, name,args...)\
typedef rtype (STDMETHODCALLTYPE *iface##name##Ptr)(args);

#define STDDDTYPEDEF(iface, name, args...)\
DDTYPEDEF(HRESULT, iface, name, args)

#define DDSTUB(rtype, iface, name, args...) \
rtype STDMETHODCALLTYPE iface##name(args) \
{ \
    DPRINTF("call to unimplemented function. Aborting."); \
    ABORT(); \
    return 0; \
}

#define ABORT() \
do {DPRINTF("---------------aborting"); int* i = 0; memset(i,1,1000); abort(); } while(0)

#define STDDDSTUB(iface, name, args...) \
DDSTUB(HRESULT, iface, name, args);

#endif
