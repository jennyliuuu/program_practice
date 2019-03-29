/*
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <iostream>

#define BUFSIZE 256

int main()
{
    DWORD targetPid;
    char dllName[BUFSIZE];
    char functionName[BUFSIZE];

    std::cout << "Welcome to remote threads demo" << std::endl;
    std::cout << "Enter target process PID: ";
    std::cin >> targetPid;
    std::cin.ignore();
    std::cout << "Enter desired DLL name: ";
    std::cin.getline(dllName, BUFSIZE);
    std::cout << "Enter desired function name: ";
    std::cin.getline(functionName, BUFSIZE);

    HANDLE hTargetProcess = NULL;
    LPVOID pRemoteMem = NULL;
    HANDLE hRemoteThread = NULL;

    DWORD result = 0;

    __try
    {
        hTargetProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, FALSE, targetPid);
        if (hTargetProcess == NULL) __leave;

        pRemoteMem = VirtualAllocEx(hTargetProcess, NULL, BUFSIZE, MEM_COMMIT, PAGE_READWRITE);
        if (pRemoteMem == NULL) __leave;
        if (!WriteProcessMemory(hTargetProcess, pRemoteMem, dllName, BUFSIZE, NULL)) __leave;

        PTHREAD_START_ROUTINE pThreadRtn = (PTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("kernel32.dll"), "GetModuleHandleA");
        hRemoteThread = CreateRemoteThread(hTargetProcess, NULL, 0, pThreadRtn, pRemoteMem, 0, NULL);
        if (hRemoteThread == NULL) __leave;
        WaitForSingleObject(hRemoteThread, INFINITE);

        GetExitCodeThread(hRemoteThread, &result);
        std::cout << "GetLastError: " << GetLastError() << std::endl;
    }
    __finally
    {
        if (hRemoteThread != NULL)
            CloseHandle(hRemoteThread);

        if (pRemoteMem != NULL)
            VirtualFreeEx(hTargetProcess, pRemoteMem, 0, MEM_RELEASE);

        if (hTargetProcess != NULL)
            CloseHandle(hTargetProcess);
    }

    if (result != 0)
    {
        std::cout.setf(std::ios::hex, std::ios::basefield);
        std::cout << "Dll base address inside target process: 0x" << result << std::endl;

        HMODULE hModule = LoadLibraryA(dllName);

        if (hModule != NULL)
        {
            std::cout << "Dll was loaded into this process at address: 0x" << hModule << std::endl;

            FARPROC functionAddr = GetProcAddress(hModule, functionName);

            if (functionAddr != NULL)
            {
                DWORD functionOffs = (DWORD)functionAddr - (DWORD)hModule;
                DWORD remoteFunctionAddr = functionOffs + result;

                std::cout << "Function offset from the DLL base address: 0x" << functionOffs << std::endl;
                std::cout << "Function address inside target process: 0x" << remoteFunctionAddr << std::endl;
            }

            FreeLibrary(hModule);
        }
    }
    else
    {
        std::cout << "Unable to retreive data";
    }

    std::cin.get();

    return 0;
}
*/
#include <Windows.h>
#include <stdio.h>

int main(int argc, char *args[]) {
    const char* buffer = "C:\\Users\\jenny_liu\\Desktop\\Hook_dll.dll";

    /*
     * Get process handle passing in the process ID.
     */
    int procID = atoi(args[1]);
    HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
    if (process == NULL) {
        printf("Error: the specified process couldn't be found.\n");
    }

    /*
     * Get address of the LoadLibrary function.
     */
    LPVOID addr = (LPVOID)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
    if (addr == NULL) {
        printf("Error: the LoadLibraryA function was not found inside kernel32.dll library.\n");
    }

    /*
     * Allocate new memory region inside the process's address space.
     */
    LPVOID arg = (LPVOID)VirtualAllocEx(process, NULL, strlen(buffer), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (arg == NULL) {
        printf("Error: the memory could not be allocated inside the chosen process.\n");
    }

    /*
     * Write the argument to LoadLibraryA to the process's newly allocated memory region.
     */
    int n = WriteProcessMemory(process, arg, buffer, strlen(buffer), NULL);
    if (n == 0) {
        printf("Error: there was no bytes written to the process's address space.\n");
    }

    /*
     * Inject our DLL into the process's address space.
     */
    HANDLE threadID = CreateRemoteThread(process, NULL, 0, (LPTHREAD_START_ROUTINE)addr, arg, NULL, NULL);
    if (threadID == NULL) {
        printf("Error: the remote thread could not be created.\n");
    }
    else {
        printf("Success: the remote thread was successfully created.\n");
    }

    /*
     * Close the handle to the process, becuase we've already injected the DLL.
     */
    CloseHandle(process);
    getchar();

    return 0;
}
