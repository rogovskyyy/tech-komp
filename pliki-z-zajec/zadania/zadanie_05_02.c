/**
Zadanie 05.02
Proszê napisaæ program, który zlicza iloœæ s³ów w pliku tekstowym(ASCII).Np.
na œci¹gniêtej stronie z Internetu.
*/

#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)
#define _CRT_SECURE_NO_DEPRECATE


int zadanie_05_02() 
{ 
    int num;
    FILE* fptr;

    fptr = fopen("test.txt", "r");

    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    int numb_of_chars = 0;
    int numb_of_words = 0;
    char c;

    while ((c = fgetc(fptr)) != EOF) {

        if (numb_of_chars == 1) {
            numb_of_words++;
        }

        if (c == 0x20) {
            numb_of_words = numb_of_words + 1;
        }

        numb_of_chars++;
    }

    fclose(fptr);

    printf("Znaki %d \n", numb_of_chars);
    printf("Slowa %d \n", numb_of_words);

    return 0;
}