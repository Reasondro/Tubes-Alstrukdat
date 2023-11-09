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

    // stringCopy(copy, original); // contoh copy string ke variable lain
    // printf("Original: %s\n", original);
    // printf("Copy: %s\n", copy);

    // if (IsSameString(original, copy)) // contoh compare string
    // {
    //     printf("Sama\n");
    // }
    // else
    // {
    //     printf("Tidak sama\n");
    // }
    char penyanyi[50];                    // ini misal string yang kalian mo isi
    printf("Masukkan nama penyanyi: ");   // misal gini
    STARTCOMMAND();                       // ini buat nerima command
    printf("ini currentWord sekarang: "); // ini buat ngeprint command yang udah diambil
    printWord(currentWord);               // ini buat ngeprint command yang udah diambil
    WordToString(currentWord, penyanyi);  // ini buat convert word ke string
    printf("ini penyanyi sekarang: ");    // ini buat ngeprint string yang udah diambil
    printf("%s", penyanyi);               // ini buat ngeprint string yang udah diambil

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