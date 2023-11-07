#include "mesinkarakter.c"
#include "mesinkata.c"
#include <string.h>
#include <stdio.h>

void stringCopy(char *string1, char *string2)
{
    int i = 0;
    while (string2[i] != '\0')
    {
        string1[i] = string2[i];
        i++;
    }
    string1[i] = '\0';
}

int main()
{

    char fungsi1[] = "fungsi1"; // contoh nulis command ke variable buat dicek nanti
    char fungsi2[] = "fungsi2";
    char fungsi3[] = "ini fungsi3";
    char exit[] = "exit";

    // char original[] = "Alessandro    del    Piero\nchristiano ronaldo";
    // char copy[50];

    // stringCopy(copy, original); // contoh copy string ke variable lain
    // printf("Original: %s\n", original);
    // printf("Copy: %s\n", copy);

    boolean exitRule = false;

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