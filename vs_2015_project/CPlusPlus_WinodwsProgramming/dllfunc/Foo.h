#ifndef FOO_H
#define FOO_H

#ifdef FOO_DLL_EXPORTS
#define FOO_API __declspec(dllexport)
#else
#define FOO_API __declspec(dllimport)
#endif

FOO_API int Add(int a, int b);
extern "C" FOO_API int Sub(int a, int b);
#endif
