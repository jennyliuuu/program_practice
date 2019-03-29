#ifndef HOOK_DLL_H
#define HOOK_DLL_H

#ifdef HOOK_DLL_EXPORTS
#define HOOK_API __declspec(dllexport)
#else
#define HOOK_API __declspec(dllimport)
#endif


extern "C" HOOK_API bool SetHookTest();
#endif