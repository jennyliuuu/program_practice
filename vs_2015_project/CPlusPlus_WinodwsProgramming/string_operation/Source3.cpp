#include <iostream>
#include <string>
#include <tchar.h>
#include "windows.h"
using namespace std;

int main()
{
    char szDefaultFileVer[64] = "aaaa";
    if (strnlen_s(szDefaultFileVer, 64) == 0) 
    {
        cout << "hihi" << endl;
    }
    else
    {
        cout << "nono" << endl;
    }
    system("pause");
}