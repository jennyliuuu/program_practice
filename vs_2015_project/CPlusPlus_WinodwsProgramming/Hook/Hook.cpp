#include <windows.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv)
{
    int i;
    HMODULE hdll = LoadLibrary("Hook_dll.dll");
    if (hdll != NULL)
    {
        HOOKPROC hproc = (HOOKPROC)GetProcAddress(hdll, "SetHookTest");
        if (!hproc)
        {
            cout << "Load SetHookTest() fail" << endl;
        }
        else
        {
            HHOOK hook = SetWindowsHookEx(WH_KEYBOARD, hproc, hdll, 0);
            for (i = 0; i < 30; i++) {
                Sleep(2000);
            }
            UnhookWindowsHookEx(hook);
        }
        FreeLibrary(hdll);
    }
    else
    {
        cout << "Load Hook_dll.dll fail" << endl;
    }
    return 0;
}