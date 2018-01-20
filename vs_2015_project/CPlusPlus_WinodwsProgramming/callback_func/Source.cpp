//http://cc.byexamples.com/2007/10/11/simple-callback-function/comment-page-1/
// call back func with no parameter

//#include <stdio.h>
//#include <iostream>
//#define SIZE 3
//typedef void(*callback)(void);
//
//typedef struct table
//{
//    int id;
//    callback func;
//}table1;
//
//void cbfunc1() { printf("cbfunc1 called\n");}
//void cbfunc2() { printf("cbfunc2 called\n"); }
//void cbfunc3() { printf("cbfunc3 called\n"); }
//
//int main()
//{
//    table1 tb[SIZE] = {  { 1,cbfunc1 },
//                         { 2,cbfunc2 },
//                         { 3,cbfunc3 } };
//    callback cb;
//    int index = 1, i;
//    for (i = 0; i < SIZE; i++)
//    {
//        if (index == tb[i].id)
//        {
//            cb = tb[i].func;
//            cb();//呼叫callback function
//        }
//        index++;
//    }
//    system("pause");
//    return 0;
//}