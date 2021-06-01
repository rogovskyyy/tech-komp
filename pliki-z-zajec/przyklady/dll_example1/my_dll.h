#ifndef __MY_DLL_H__
#define __MY_DLL_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

// void DLL_EXPORT MyExportFunct(const LPCSTR sometext);
void DLL_EXPORT MyExportFunct(const LPCWSTR sometext);

#ifdef __cplusplus
}
#endif

#endif // __MY_DLL_H__
