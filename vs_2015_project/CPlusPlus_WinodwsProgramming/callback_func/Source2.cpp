//http://cc.byexamples.com/2007/10/11/simple-callback-function/comment-page-1/
// call back func with parameters

#include <stdio.h>
#include <iostream>
#define SIZE 3
typedef struct para
{
    int p1;
    char p2;
}mypara;

typedef void(*callback)(mypara*);

typedef struct table
{
    int id;
    callback func;
}table1;

void cbfunc1(mypara* m) { printf("cbfunc1 called, m->p1 = %d, m->p2 = %c\n", m->p1, m->p2); }
void cbfunc2(mypara* m) { printf("cbfunc2 called, m->p1 = %d, m->p2 = %c\n", m->p1, m->p2); }
void cbfunc3(mypara* m) { printf("cbfunc3 called, m->p1 = %d, m->p2 = %c\n", m->p1, m->p2); }

int main()
{
    table1 tb[SIZE] = { { 1,cbfunc1 },
                        { 2,cbfunc2 },
                        { 3,cbfunc3 } };
    callback cb;
    int index = 1, i;
    int a = 1;

    mypara m1;
    m1.p1 = 1;
    m1.p2 = 'w';

    for (i = 0; i < SIZE; i++)
    {
        if (index == tb[i].id)
        {
            cb = tb[i].func;
            cb(&m1);//呼叫callback function
        }
        index++;
    }
    system("pause");
    return 0;
}