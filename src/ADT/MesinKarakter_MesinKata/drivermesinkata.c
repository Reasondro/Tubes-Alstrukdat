#include "mesinkarakter.c"
#include "mesinkata.c"
#include <string.h>
#include <stdio.h>

int main()
{

    char fungsi1[] = "fungsi1"; // contoh nulis command ke variable buat dicek nanti
    char fungsi2[] = "fungsi2";
    char fungsi3[] = "ini fungsi3";
    char exit[] = "exit";

    char original[] = "halo pak riza\nhehehe";
    char copy[50];

    stringCopy(copy, original); // contoh copy string ke variable lain
    printf("Original: %s\n", original);
    printf("Copy: %s\n", copy);

    if (IsSameString(original, copy)) // contoh compare string
    {
        printf("Sama\n");
    }
    else
    {
        printf("Tidak sama\n");
    }

    boolean exitRule = true;

    while (exitRule == false)
    {
        readCommand();

        if (IsSameWord(currentWord, fungsi1))
        {
            printf("fungsi1 kepanggil\n");
            printf("ini currentWord sekarang: ");
            printWord(currentWord);
        }
        else if (IsSameWord(currentWord, fungsi2))
        {
            printf("fungsi2 kepanggil\n");
            printf("ini currentWord sekarang: ");

            printWord(currentWord);
        }
        else if (IsSameWord(currentWord, fungsi3))
        {
            printf("fungsi3 kepanggil\n");
            printf("ini currentWord sekarang: ");
            printWord(currentWord);
        }
        else if ((IsSameWord(currentWord, exit)))
        {
            exitRule = true;
        }

        else
        {
            printf("Command tidak diketahui!\n");
            printWord(currentWord);
        }
    }

    return 0;
}