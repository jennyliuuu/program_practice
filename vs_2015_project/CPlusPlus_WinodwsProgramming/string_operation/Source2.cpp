#include <iostream>
#include <string>
#include <tchar.h>
#include "windows.h"
using namespace std;

void str_assign(char *);
void str_memcpy(char *);
void str_strcpy(char *);

int main()
{
    char *a = new char[20];
    a = "aaaaabbbbb";
    //str_assign(a);     //illegal
    str_memcpy(a);
    str_strcpy(a);


    char a1[20] = "aaaaabbbbb";
    str_assign(a1);
    str_memcpy(a1);
    str_strcpy(a1);

    system("pause");

    return 0;
}

void str_assign(char *b)
{
    b[1] = 'c';
    cout << "b: " << b << endl;
}

void str_memcpy(char *b)
{
    char c[20] = "";
    cout << "strlen(b): " << strlen(b) << endl;
    cout << "str_memcpy c: " << c << endl;
    memcpy(c, b, (strlen(b) + 1) * sizeof(char));
    c[2] = 'w';
    cout << "str_memcpy c: " << c << endl;

}

void str_strcpy(char *b)
{
    char c[20] = "";
    cout << "strlen(b): " << strlen(b) << endl;
    cout << "str_strcpy c: " << c << endl;
    strncpy_s(c, b, (strlen(b) + 1) * sizeof(char));
    cout << "str_strcpy c: " << c << endl;
}
