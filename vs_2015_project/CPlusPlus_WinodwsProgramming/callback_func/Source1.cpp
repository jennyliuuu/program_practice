//http://cc.byexamples.com/2007/10/11/simple-callback-function/comment-page-1/
// call back func with parameters

//#include <stdio.h>
//#include <iostream>
//#define SIZE 3
//typedef void(*callback)(int);
//
//typedef struct table
//{
//    int id;
//    callback func;
//}table1;
//
//void cbfunc1(int a) { printf("cbfunc1 called, a = %d\n",a); }
//void cbfunc2(int a) { printf("cbfunc2 called, a = %d\n",a); }
//void cbfunc3(int a) { printf("cbfunc3 called, a = %d\n",a); }
//
//int main()
//{
//    table1 tb[SIZE] = { { 1,cbfunc1 },
//                        { 2,cbfunc2 },
//                        { 3,cbfunc3 } };
//    callback cb;
//    int index = 1, i;
//    int a = 1;
//    for (i = 0; i < SIZE; i++)
//    {
//        if (index == tb[i].id)
//        {
//            cb = tb[i].func;
//            cb(a);//呼叫callback function
//        }
//        index++;
//    }
//    system("pause");
//    return 0;
//}