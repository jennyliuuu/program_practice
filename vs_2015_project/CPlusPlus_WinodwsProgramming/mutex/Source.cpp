/* http://www.cnblogs.com/TenosDoIt/p/3601387.html */

#include<string>
#include<iostream>
#include<process.h>
#include<windows.h>
using namespace std;

//声明互斥量句柄
HANDLE hmu;

//线程绑定的函数返回值和参数是确定的，而且一定要__stdcall
unsigned __stdcall threadFun(void *param)
{
    WaitForSingleObject(hmu, INFINITE);//等待互斥量
    cout << *(string *)(param) << endl;
    ReleaseMutex(hmu);//释放互斥量
    return 1;
}


int main()
{
    //创建互斥量
    hmu = CreateMutex(NULL, FALSE, NULL);

    HANDLE hth1, hth2, hth3;
    string s1 = "first", s2 = "second", s3 = "third";

    //创建线程
    hth1 = (HANDLE)_beginthreadex(NULL, 0, threadFun, &s1, 0, NULL);
    hth2 = (HANDLE)_beginthreadex(NULL, 0, threadFun, &s2, 0, NULL);
    hth3 = (HANDLE)_beginthreadex(NULL, 0, threadFun, &s3, 0, NULL);

    //等待子线程结束
    WaitForSingleObject(hth1, INFINITE);
    WaitForSingleObject(hth2, INFINITE);
    WaitForSingleObject(hth3, INFINITE);

    //一定要记得关闭线程句柄
    CloseHandle(hth1);
    CloseHandle(hth2);
    CloseHandle(hth3);

    //千万别忘了删除互斥量
    CloseHandle(hmu);
    system("pause");
    return 0;
}