#define APP_NAME        "MW3Fixup"
#define APP_VERSION        "0.1"

#include <windows.h>
#include <initguid.h>
#include <ddraw.h>
#include <d3d.h>
#include <stdio.h>

#include "Util.h"

static HMODULE  realDLL;
static FARPROC    realAcquireDDThreadLock;
static FARPROC    realCheckFullscreen;
static FARPROC    realCompleteCreateSysmemSurface;
static FARPROC    realD3DParseUnknownCommand;
static FARPROC    realDDGetAttachedSurfaceLcl;
static FARPROC    realDDInternalLock;
static FARPROC    realDDInternalUnlock;
static FARPROC    realDSoundHelp;
static FARPROC    realDirectDrawCreate;
static FARPROC    realDirectDrawCreateClipper;
static FARPROC    realDirectDrawCreateEx;
static FARPROC    realDirectDrawEnumerateA;
static FARPROC    realDirectDrawEnumerateExA;
static FARPROC    realDirectDrawEnumerateExW;
static FARPROC    realDirectDrawEnumerateW;
static FARPROC    realDllCanUnloadNow;
static FARPROC    realDllGetClassObject;
static FARPROC    realGetDDSurfaceLocal;
static FARPROC    realGetOLEThunkData;
static FARPROC    realGetSurfaceFromDC;
static FARPROC    realRegisterSpecialCase;
static FARPROC    realReleaseDDThreadLock;

#ifndef WINAPI
#define WINAPI __declspec(dllexport);
#endif

void WINAPI AcquireDDThreadLock()
{
    abort();
}
void WINAPI CheckFullscreen()
{
    abort();
}

void WINAPI CompleteCreateSysmemSurface()
{
    abort();
}

void WINAPI D3DParseUnknownCommand()
{
    abort();
}

void WINAPI DDGetAttachedSurfaceLcl()
{
    abort();
}

void WINAPI DDInternalLock()
{
    abort();
}

void WINAPI DDInternalUnlock()
{
    abort();
}

void WINAPI DSoundHelp()
{
    abort();
}

HRESULT WINAPI DirectDrawCreate(GUID *driver_guid, IDirectDraw **ddraw, IUnknown *outer)
{
    printf("------------\n%s:%s:%d\n------------\n",__func__,__FILE__,__LINE__);
    HRESULT rc = realDirectDrawCreate(driver_guid, ddraw, outer);
    if(rc != DD_OK)
    {
        return rc;
    }
    LPDIRECTDRAW lpdd = *ddraw;

	if(logfd == 0)
	{
		logfd = fopen("hdraw.log","wb");
		setbuf(logfd, NULL);
	}

	//swap the real ddraw object for a proxy
    (*ddraw) = IDDCreate(lpdd);

    DPRINTF("%s", "Hooks installed\n");

    return DD_OK;
}

HRESULT WINAPI DirectDrawCreateEx(GUID* driver_guid,LPVOID *ddraw, REFIID refiid, IUnknown* outer)
{
    printf("------------\n%s:%s:%d\n------------\n",__func__,__FILE__,__LINE__);
    return realDirectDrawCreateEx(driver_guid, ddraw, refiid, outer);
}

HRESULT WINAPI DirectDrawCreateClipper(DWORD flags, IDirectDrawClipper **clipper, IUnknown *outer)
{
    printf("------------\n%s:%s:%d\n------------\n",__func__,__FILE__,__LINE__);
    return realDirectDrawCreateClipper(flags, clipper, outer);
}

HRESULT WINAPI DirectDrawEnumerateA(LPDDENUMCALLBACKA cb, LPVOID ptr)
{
    printf("------------\n%s:%s:%d\n------------\n",__func__,__FILE__,__LINE__);
    return realDirectDrawEnumerateA(cb, ptr);
}

HRESULT WINAPI DirectDrawEnumerateW(LPDDENUMCALLBACKW cb,LPVOID ptr)
{
    printf("------------\n%s:%s:%d\n------------\n",__func__,__FILE__,__LINE__);
    return realDirectDrawEnumerateW(cb, ptr);
}

HRESULT WINAPI DirectDrawEnumerateExA( LPDDENUMCALLBACKEXA lpCallback, LPVOID lpContext, DWORD dwFlags)
{
    printf("------------\n%s:%s:%d\n------------\n",__func__,__FILE__,__LINE__);
    return realDirectDrawEnumerateExA(lpCallback, lpContext, dwFlags);
}

HRESULT WINAPI DirectDrawEnumerateExW( LPDDENUMCALLBACKEXW lpCallback, LPVOID lpContext, DWORD dwFlags)
{
    printf("------------\n%s:%s:%d\n------------\n",__func__,__FILE__,__LINE__);
    return realDirectDrawEnumerateExW(lpCallback, lpContext, dwFlags);
}

HRESULT WINAPI DllCanUnloadNow(void) DECLSPEC_HIDDEN
{
    printf("------------\n%s:%s:%d\n------------\n",__func__,__FILE__,__LINE__);
    return realDllCanUnloadNow();
}

HRESULT WINAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID * ppv) DECLSPEC_HIDDEN
{
    printf("------------\n%s:%s:%d\n------------\n",__func__,__FILE__,__LINE__);
    return realDllGetClassObject(rclsid, riid, ppv);
}

void WINAPI GetDDSurfaceLocal()
{
    abort();
}

void WINAPI GetOLEThunkData()
{
    abort();
}

void WINAPI GetSurfaceFromDC()
{
    abort();
}

void WINAPI RegisterSpecialCase()
{
    abort();
}

void WINAPI ReleaseDDThreadLock()
{
    abort();
}


BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    char path[MAX_PATH];
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            realDLL = LoadLibrary("ddraw.dll");
            if (realDLL == 0)
            {
                MessageBox(0, "Cannot load original ddraw.dll library", APP_NAME, MB_ICONERROR);
                ExitProcess(0);
            }
            realAcquireDDThreadLock         = GetProcAddress(realDLL, "AcquireDDThreadLock");
            realCheckFullscreen             = GetProcAddress(realDLL, "CheckFullscreen");
            realCompleteCreateSysmemSurface = GetProcAddress(realDLL, "CompleteCreateSysmemSurface");
            realD3DParseUnknownCommand      = GetProcAddress(realDLL, "D3DParseUnknownCommand");
            realDDGetAttachedSurfaceLcl     = GetProcAddress(realDLL, "DDGetAttachedSurfaceLcl");
            realDDInternalLock              = GetProcAddress(realDLL, "DDInternalLock");
            realDDInternalUnlock            = GetProcAddress(realDLL, "DDInternalUnlock");
            realDSoundHelp                    = GetProcAddress(realDLL, "DSoundHelp");
            realDirectDrawCreate            = GetProcAddress(realDLL, "DirectDrawCreate");
            realDirectDrawCreateClipper     = GetProcAddress(realDLL, "DirectDrawCreateClipper");
            realDirectDrawCreateEx          = GetProcAddress(realDLL, "DirectDrawCreateEx");
            realDirectDrawEnumerateA        = GetProcAddress(realDLL, "DirectDrawEnumerateA");
            realDirectDrawEnumerateExA      = GetProcAddress(realDLL, "DirectDrawEnumerateExA");
            realDirectDrawEnumerateExW      = GetProcAddress(realDLL, "DirectDrawEnumerateExW");
            realDirectDrawEnumerateW        = GetProcAddress(realDLL, "DirectDrawEnumerateW");
            realDllCanUnloadNow             = GetProcAddress(realDLL, "DllCanUnloadNow");
            realDllGetClassObject           = GetProcAddress(realDLL, "DllGetClassObject");
            realGetDDSurfaceLocal           = GetProcAddress(realDLL, "GetDDSurfaceLocal");
            realGetOLEThunkData             = GetProcAddress(realDLL, "GetOLEThunkData");
            realGetSurfaceFromDC            = GetProcAddress(realDLL, "GetSurfaceFromDC");
            realRegisterSpecialCase         = GetProcAddress(realDLL, "RegisterSpecialCase");
            realReleaseDDThreadLock         = GetProcAddress(realDLL, "ReleaseDDThreadLock");
        break;

        case DLL_PROCESS_DETACH:
            FreeLibrary(realDLL);
        break;
    }
    return TRUE;
}

