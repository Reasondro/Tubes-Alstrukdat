#include "mesinkarakter.c"
#include "mesinkata.c"
#include <string.h>
#include <stdio.h>

typedef char keytype;
typedef struct
{
    char judul[100];
} SongType;

typedef SongType valuetype;

typedef struct
{
    keytype key[50];
    valuetype song;
} AlbumType;

typedef struct
{
    char penyanyi[50];
    char album[50];
    SongType judul_lagu[100];
} QueueSongType;

typedef struct
{
    char penyanyi[100];
    AlbumType album;
} PenyanyiType;

int main()
{

    char fungsi1[] = "fungsi1"; // contoh nulis command ke variable buat dicek nanti
    char fungsi2[] = "fungsi2";
    char fungsi3[] = "ini fungsi3";
    char exit[] = "exit";
    char printLine[] = "displayline";
    char majuLine[] = "majuline";
    char Yes[] = "yes";
    char No[] = "no";

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

    // ini langkah-langkah untuk nerima command tanpa pake scanf
    // char penyanyi[50];                    // ini misal string yang kalian mo isi
    // printf("Masukkan nama penyanyi: ");   // misal gini
    // STARTCOMMAND();                       // ini buat nerima command
    // printf("ini currentWord sekarang: "); // ini buat ngeprint command yang udah diambil, pembuktian aja ini, nanti di main ga usah
    // printWord(currentWord);               // ini buat ngeprint command yang udah diambil ,pembuktian aja ini, nanti di main ga usah
    // WordToString(currentWord, penyanyi);  // ini buat convert word ke string
    // printf("ini penyanyi sekarang: ");    // ini buat ngeprint string yang udah diambil, nah ini pembuktian juga
    // printf("%s", penyanyi);               // ini buat ngeprint string yang udah diambil, nah ini pembuktian juga

    STARTLINE();
    // displayLine(currentLine);
    // printf("Panjang karakter: %d\n", currentLine.LengthLine);

    boolean exitFile = false;

    while (exitFile == false)
    {
        readCommand();
        if (IsSameWord(currentWord, exit))
        {
            exitFile = true;
            printf("do you really wanto exit?\n");
            readCommand();
            if (IsSameWord(currentWord, No))
            {
                exitFile = false;
            }
        }
        else if (IsSameWord(currentWord, printLine))
        {
            displayLine(currentLine);
            printf("%d\n", currentLine.LengthLine);
        }
        else if (IsSameWord(currentWord, majuLine))
        {
            ADVLINE();
        }
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
        else if ((IsSameWord(currentWord, printLine)))
        {

            printf("%c\n", currentLine.TabLine[0]);
            // printf("testing");
        }
        else
        {
            printf("Command tidak diketahui!\n");
            printWord(currentWord);
        }
    }

    return 0;
}

// while (!EndLine)
// {
//     for (int i = 0; i < currentLine.LengthLine; i++)
//     {
//         printf("%c", currentLine.TabLine[i]);
//     }
//     printf("\n");
//     ADVLINE();
// }