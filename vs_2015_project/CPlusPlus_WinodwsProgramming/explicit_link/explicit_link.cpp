#include <iostream>
#include <windows.h>

typedef int(*pfn)(int, int);

int main()
{
    HINSTANCE dllHandle = LoadLibrary(L"dllfunc.dll");
    if (dllHandle != NULL)
    {
        // Get address of function
        pfn pSubFunc = (pfn)GetProcAddress(dllHandle, "Sub");
        if (!pSubFunc)
        {
            std::cout << "Load Sub() fail" << std::endl;  // handle the error
        }
        else
        {
            std::cout << pSubFunc(2, 3) << std::endl; // call the function
        }

        pfn pAddFunc = (pfn)GetProcAddress(dllHandle, "?Add@@YAHHH@Z");
        if (!pAddFunc)
        {
            std::cout << "Load Add() fail" << std::endl;
        }
        else
        {
            std::cout << pAddFunc(2, 3) << std::endl;
        }
        FreeLibrary(dllHandle);
    }
    else
    {
        std::cout << "Load FooLibrary.dll fail" << std::endl;
    }
    system("pause");
    return 0;
}
