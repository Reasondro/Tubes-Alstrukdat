#include "mesinkarakter.c"
#include "mesinkata.c"
#include "queue.c"
#include "SETMAP.c"
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

void loadFile()
{
    char loadfileName[40];
    printf("Masukkan nama file: ");
    readCommand();
    WordToString(currentWord, loadfileName);
    printf("Nama file: %s\n", loadfileName);
    STARTLINE(loadfileName);
    int jumlahPenyanyi, jumlahAlbum, jumlahLagu;
    jumlahPenyanyi = currentLine.TabLine[0] - '0';
    PenyanyiTypeRevisi currentPenyayi;
    char pattern = 'A';
    for (int i = 0; i < jumlahPenyanyi; i++)
    {
        ADVLINE();
        jumlahAlbum = currentLine.TabLine[0] - '0';
    }
    displayLine(currentLine);
    char testing[100];
    char copied[100];
    LineToString(currentLine, testing);
    stringCopy(copied, testing); // belum selsai
}

AlbumTypeRevisi Album;

keytype NamaAlbum1;

keytype NamaAlbum2;
keytype NamaAlbum3;
SongType Song1;
SongType Song2;
SongType Song3;
SongType Song4;
PenyanyiTypeRevisi Penyanyi1; // DECLARE PENYANYI

int main()
{

    // char *str1 = malloc(10 * sizeof(char));
    // if (str1 == NULL)
    // {
    //     printf("Memory allocation failed\n");
    //     return 1;
    // }
    // free(str1);

    char str3[] = "Testing memory, ";
    char str2[] = "Please!";
    stringConcat(str3, str2);
    printf("%s\n", str3); // Outputs: Hello, World!

    CreateEmptyMap(&Album);

    char Album1[] = "2001 by Dre";
    stringCopy(NamaAlbum1, Album1);

    char Album2[] = "Beat it by MJ";
    stringCopy(NamaAlbum2, Album2);

    char Album3[] = "HALO PAPUA";
    stringCopy(NamaAlbum3, Album3);

    InsertMap(&Album, NamaAlbum1);
    InsertMap(&Album, NamaAlbum2);
    // InsertMap(&Album, NamaAlbum3);

    char lagu1[] = "The Watcher";
    stringCopy(Song1.judul, lagu1);

    char lagu2[] = "F*ck You";
    stringCopy(Song2.judul, lagu2);

    char lagu3[] = "Thriller";
    stringCopy(Song3.judul, lagu3);

    char lagu4[] = "Billie Jean";
    stringCopy(Song4.judul, lagu4);

    InsertSet(Song1, &Album, NamaAlbum1);
    InsertSet(Song2, &Album, NamaAlbum1);
    InsertSet(Song3, &Album, NamaAlbum2);
    InsertSet(Song4, &Album, NamaAlbum2);

    // DisplaySet(Album, NamaAlbum1);
    // DisplaySet(Album, NamaAlbum2);

    char fungsi1[] = "fungsi1"; // contoh nulis command ke variable buat dicek nanti
    char fungsi2[] = "fungsi2";
    char fungsi3[] = "ini fungsi3";
    char exit[] = "exit";
    char printLine[] = "displayline";
    char majuLine[] = "majuline";
    char Yes[] = "yes";
    char No[] = "no";

    // char original[] = "halo pak riza\nhehehe";
    // char copy[50];

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

    // STARTLINE();
    // displayLine(currentLine);
    // int result = currentLine.TabLine[0] - '0';
    // printf("%d\n", result * 88);
    // printf("Panjang line sekarang: %d\n", currentLine.LengthLine);
    // ADVLINE();
    // printf("Panjang line sekarang: %d\n", currentLine.LengthLine);

    // ? ini penting
    stringCopy(Penyanyi1.nama, "Michael Jakson");                                // Inisiasi nama penyanyi 1;
    Penyanyi1.album.JumlahAlbum = 2;                                             // ini abain aja, nanti keubah sama primitif insert map
    stringCopy(Penyanyi1.album.AlbumKe[0].NamaAlbum, "ALBUM KE-1");              // inisiasi nama album penyanyi1 ke 1
    stringCopy(Penyanyi1.album.AlbumKe[1].NamaAlbum, "ALBUM KE-2");              // inisiasi nama album penyanyi1 ke 1
    Penyanyi1.album.AlbumKe[0].DaftarLagu.JumlahLagu = 1;                        // ini abain aja nanti keubah sama primitif insert di set
    stringCopy(Penyanyi1.album.AlbumKe[0].DaftarLagu.Songs[0].judul, "Beat it"); // inisiasi nama lagu album ke 1

    // printf("%d", Penyanyi1.album.JumlahAlbum);
    // printf("%s\n", Penyanyi1.nama);
    // printf("%s\n", Penyanyi1.album.AlbumKe[0].NamaAlbum);
    // printf("%s", Penyanyi1.album.AlbumKe[0].DaftarLagu.Songs[0].judul);

    loadFile();

    boolean exitFile = true;

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
        }
        else
        {
            printf("Command tidak diketahui!\n");
            printWord(currentWord);
        }
    }

    return 0;
}
