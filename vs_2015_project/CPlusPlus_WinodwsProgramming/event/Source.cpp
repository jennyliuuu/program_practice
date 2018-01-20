﻿#include "iostream"
#include "windows.h"
using namespace std;

DWORD WINAPI ThreadProc1(LPVOID lpParam);
DWORD WINAPI ThreadProc2(LPVOID lpParam);
HANDLE hEvent = NULL;
HANDLE hThread1 = NULL;
HANDLE hThread2 = NULL;
int main(int argc, char *args[])
{
    hEvent = CreateEvent(NULL, FALSE, TRUE, NULL); //使用手动重置为无信号状态，初始化时有信号状态
    hThread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc1, NULL, 0, NULL);
    Sleep(200);
    hThread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThreadProc2, NULL, 0, NULL);
    Sleep(200);
    if (NULL == hThread1)
    {
        cout << "create thread fail!";
    }
    system("pause");
    return 0;
}
DWORD WINAPI ThreadProc1(LPVOID lpParam)
{
    cout << "in thread1@!" << endl;
    DWORD dReturn = WaitForSingleObject(hEvent, INFINITE);
    if (WAIT_OBJECT_0 == dReturn)
    {
        cout << " thread1 signaled ! " << endl;
    }
    cout << "in thread1 --signal" << endl;
    //ResetEvent(hEvent);
    return 0;
}
DWORD WINAPI ThreadProc2(LPVOID lpParam)
{
    cout << "in thread2@!" << endl;
    DWORD dReturn = WaitForSingleObject(hEvent, INFINITE);
    if (WAIT_OBJECT_0 == dReturn)
    {
        cout << "thread2 signaled ! " << endl;
    }
    cout << "in thread2--signal" << endl;
    return 0;
}