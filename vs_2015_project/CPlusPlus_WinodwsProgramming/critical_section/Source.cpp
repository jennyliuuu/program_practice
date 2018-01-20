#include "Everything.h" 

DWORD g_cnt1; 
DWORD g_cnt2; 
BOOL g_bContinue = TRUE; 
CRITICAL_SECTION cs; 
 
unsigned int _stdcall ThreadProc(void* pVoid) 
{ 
  int a = (*(int *)pVoid);
  //int a = (int) pVoid;

  printf("thread: %d \n", a);
  ::EnterCriticalSection(&cs); 
  //while(g_bContinue) 
  //{ 
    g_cnt1++; 
    g_cnt2++; 
 // } 
  ::LeaveCriticalSection(&cs); 
  return 0; 
} 
 
int _tmain(int argc, _TCHAR* argv[]) 
{ 
  HANDLE hThread[2]; 
  g_cnt1 = 10, g_cnt2 = 20;
  int a = 1, b = 2;
  ::InitializeCriticalSection(&cs); 
 
//  hThread[0] = (HANDLE)_beginthreadex (NULL, 0, ThreadProc, (void*) a, 0, NULL); 
//  hThread[1] = (HANDLE)_beginthreadex (NULL, 0, ThreadProc, (void*) b, 0, NULL);

  hThread[0] = (HANDLE)_beginthreadex (NULL, 0, ThreadProc, (void*) &a, 0, NULL); //  hThread[0] = (HANDLE)_beginthreadex(NULL, 0, ThreadProc, &a, 0, NULL);
  hThread[1] = (HANDLE)_beginthreadex (NULL, 0, ThreadProc, (void*) &b, 0, NULL); //  hThread[1] = (HANDLE)_beginthreadex(NULL, 0, ThreadProc, &b, 0, NULL);

  Sleep(1000); 
  //g_bContinue = FALSE; 
  ::WaitForMultipleObjects(2, hThread, TRUE, INFINITE); 
  printf("g_cnt1=%d\n",g_cnt1); 
  printf("g_cnt2=%d\n",g_cnt2); 
 
  ::DeleteCriticalSection(&cs); 
 
  ::CloseHandle(hThread[0]); 
  ::CloseHandle(hThread[1]); 

  return 0; 
}
