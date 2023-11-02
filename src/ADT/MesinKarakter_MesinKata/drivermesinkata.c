#include "mesinkarakter.c"
#include "mesinkata.c"
#include <string.h>
#include <stdio.h>

int main()
{
    printWord(currentWord);

    char fungsi1[] = "fungsi1;"; // contoh nulis command ke variable buat dicek nanti
    char fungsi2[] = "fungsi2;";

    readCommand();
    printWord(currentWord);

    printf("\n");
    if (IsSameWord(currentWord, fungsi1))
    {
        // panggil fungsi1 disini
        printf("fungsi1 kepanggil\n");
        printWord(currentWord);
    }
    else if (IsSameWord(currentWord, fungsi2))
    {
        // panggil fungsi2 disini
        printf("fungsi2 kepanggil\n");
        printWord(currentWord);
    }
}