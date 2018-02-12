//http://cc.byexamples.com/2007/10/11/simple-callback-function/comment-page-1/
// call back func with parameters

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define SIZE 3
typedef void(*callback)(int, string);

typedef struct table
{
    int id;
    callback func;
}table1;

void cbfunc1(int a, string b) { printf("cbfunc1 called, a = %d, b = %s\n", a, b.c_str()); }
void cbfunc2(int a, string b) { printf("cbfunc2 called, a = %d, b = %s\n", a, b.c_str()); }
void cbfunc3(int a, string b) { printf("cbfunc3 called, a = %d, b = %s\n", a, b.c_str()); }

int main()
{
    table1 tb[SIZE] = { { 1,cbfunc1 },
                        { 2,cbfunc2 },
                        { 3,cbfunc3 } };
    callback cb;
    int index = 1, i;
    int a = 1;
    string b = "jenny";
    for (i = 0; i < SIZE; i++)
    {
        if (index == tb[i].id)
        {
            cb = tb[i].func;
            cb(a, b);//呼叫callback function
        }
        index++;
    }
    system("pause");
    return 0;
}