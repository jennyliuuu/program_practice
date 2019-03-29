// Hook_dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Hook_dll.h"

bool SetHookTest()
{
    MessageBox(NULL, TEXT("SetWindowsHookEx Success!"), TEXT("Tips"), MB_OK);
    return 0;
}
