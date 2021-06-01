#include <iostream>
#include <windows.h>
// #include <stdio.h>
#include "my_dll.h"

using namespace std;


int main()
{
    MyExportFunct(L"dll linked statically");
    return 0;
}
