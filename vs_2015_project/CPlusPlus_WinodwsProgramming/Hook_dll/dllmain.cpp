// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <stdio.h>
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
)
{
    printf("hello\n");
    MessageBox(NULL, TEXT("Process Load Dll Success !"), TEXT("Tips"), MB_OK);

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        MessageBox(NULL, TEXT("DLL_PROCESS_ATTACH !"), TEXT("Tips"), MB_OK);
        printf("DLL_PROCESS_ATTACH !\n");
        break;
    case DLL_THREAD_ATTACH:
        MessageBox(NULL, TEXT("DLL_THREAD_ATTACH !"), TEXT("Tips"), MB_OK);
        printf("DLL_THREAD_ATTACH !\n");
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

