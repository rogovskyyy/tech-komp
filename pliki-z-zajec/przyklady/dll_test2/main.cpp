#include <iostream>
#include <windows.h>
// #include <stdio.h>



using namespace std;

// void DLL_EXPORT MyExportFunct(const LPCSTR sometext);
typedef void (WINAPI *ptr2funct)(const LPCWSTR atext);
ptr2funct my_dll_funct = NULL;


int main()
{
   MessageBoxW(0, L"Komunikat wywolany z programu\nprzed zaladowaniem dll", L"Program korzystajacy z dll przed", MB_OK | MB_ICONINFORMATION);

   HINSTANCE h = LoadLibrary("dll_example1.dll");
   // printf("h = %d\n", h);

   if (h)
   {
      my_dll_funct = (ptr2funct) GetProcAddress(h, "MyExportFunct");
      // printf("pFM = %d", pFM);
      if (my_dll_funct != NULL)
      {
         my_dll_funct(L"Komunikat wyswietlony w dll.");
      }
      FreeLibrary(h);
      MessageBoxW(0, L"Komunikat wywolany z programu\npo powrocie z dll", L"Program korzystajacy z dll po", MB_OK | MB_ICONINFORMATION);
   }
   else
   {
      MessageBoxW(0, L"Blad przy wczytywaniu biblioteki dll", L"Program korzystajacy z dll", MB_OK | MB_ICONERROR);
   }
   return 0;
}
