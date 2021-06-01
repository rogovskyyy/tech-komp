#include "my_dll.h"

// a sample exported function
// void DLL_EXPORT MyExportFunct(const LPCSTR sometext)
void DLL_EXPORT MyExportFunct(const LPCWSTR sometext)
{
    // MessageBoxA(0, sometext, "DLL Message", MB_OK | MB_ICONINFORMATION);
    MessageBoxW(0, sometext, L"DLL Message", MB_OK | MB_ICONINFORMATION);
    // MessageBox(0, (LPCWSTR) sometext, (LPCWSTR)L"DLL Message", MB_OK | MB_ICONINFORMATION);
}

extern "C" DLL_EXPORT BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }
    return TRUE; // succesful
}
