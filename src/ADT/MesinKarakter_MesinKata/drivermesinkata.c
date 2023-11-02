#include "mesinkarakter.c"
#include "mesinkata.c"
#include <string.h>
#include <stdio.h>

int main()
{
    char APA[] = "APA";
    readCommand();
    if (IsSameWord(currentWord, APA))
    {
        printf("berarti bisa");
    }
}