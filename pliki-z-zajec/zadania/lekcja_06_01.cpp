#include <algorithm>
#include <iostream>
#include <list>
#include <string>

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_DEPRECATE

void print(std::list<std::string> const& list)
{
    for (auto const& i : list) {
        std::cout << i << std::endl;
    }
}

int main() {
    int num;
    FILE* fptr;
    std::list<std::string> lista;

    fptr = fopen("test.txt", "r");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    int numb_of_words = 0;
    char c;
    char buffer[128];
    int iter = 0;
    memset(buffer, 0, 127);

    while ((c = fgetc(fptr)) != EOF) {

        if (c == 0x20 || c == '\0') {
            std::string str;
            str.append(buffer);
            lista.push_back(str);
            memset(buffer, 0, 127);
            iter = 0;
        }

        buffer[iter] = c;
        iter++;

    }

    fclose(fptr);

    print(lista);

    return 0;
}