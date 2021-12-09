#ifndef DLL_H_
#define DLL_H_

#if DLLProvider
#define DLL_EXPORT_IMPORT __declspec(dllexport)
#else
#define DLL_EXPORT_IMPORT __declspec(dllimport)
#endif

#endif // !DLL_H_

