#include "../MesinKarakter_MesinKata/mesinkata.h"
#include "../struct.h"
#include <stdio.h>

// #include "mesinkarakter.c" // non comment hanya klao mo test
// #include "mesinkata.c"

// ----------------- REVISI REVISI REVISI ---------------------
// typedef struct
// {
//     Word Songs[10]; // misal max 10 lagu per album
//     int JumlahLagu; // buat nentuin jumlah lagu misal butuh
// } SetSongRevisi;

// typedef struct
// {
//     Word NamaAlbum;           // nama album si penyanyinya sebagai key
//     SetSongRevisi DaftarLagu; // kumpulan lagu dalam 1 album sebagai isi dari map
// } IsiAlbumRevisi;
// typedef struct
// {
//     IsiAlbumRevisi AlbumKe[4]; // nah ini harusny udah map yang benar
//     int JumlahAlbum;
// } AlbumTypeRevisi2;

// typedef struct
// {
//     Word nama;
//     AlbumTypeRevisi2 album; // sebagai map
// } PenyanyiTypeRevisi2;

// typedef struct
// {
//     PenyanyiTypeRevisi2 Penyanyi[5]; // ini prototipe
//     int JumlahPenyanyi;
// } ListPenyanyiRevisi;
//-------------------------------------------------
// ! jan lupa
void CreateEmptySet(SetSongRevisi *S)
{
    S->JumlahLagu = 0;
}

boolean IsEmptySetSong(SetSongRevisi S)
{
    return S.JumlahLagu == 0;
}

boolean IsMemberSet(SetSongRevisi S, Word Song)
{
    boolean found = false;
    int idx = 0;
    while (!found && idx < S.JumlahLagu)
    {
        if (IsDuplicateWord(S.Songs[idx], Song))
        {
            found = true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}

void InsertSet(Word Song, AlbumTypeRevisi2 *Album, Word NamaAlbumDicari)
{
    int i = 0;
    boolean found = false;

    while (i < Album->JumlahAlbum && !found)
    {
        if (IsDuplicateWord(Album->AlbumKe[i].NamaAlbum, NamaAlbumDicari))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }

    if (IsMemberSet((Album->AlbumKe[i].DaftarLagu), Song))
    {
        return;
    }

    CopasWord(&(Album->AlbumKe[i].DaftarLagu.Songs[Album->AlbumKe[i].DaftarLagu.JumlahLagu]), Song);
    Album->AlbumKe[i].DaftarLagu.JumlahLagu++;
}

void DisplaySet(AlbumTypeRevisi2 Album, Word NamaAlbumDicari)
{
    int i = 0;
    boolean found = false;

    while (i < Album.JumlahAlbum && !found)
    {
        if (IsDuplicateWord(Album.AlbumKe[i].NamaAlbum, NamaAlbumDicari))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    if (found)
    {
        printf("Daftar Lagu Album ");
        printWord(Album.AlbumKe[i].NamaAlbum);
        printf(":");
        printf("\n");
        int j;
        for (j = 0; j < Album.AlbumKe[i].DaftarLagu.JumlahLagu; j++)
        {
            printf("    %d. ", j + 1);
            printWord(Album.AlbumKe[i].DaftarLagu.Songs[j]);
            printf("\n");
        }
    }
    else
    {
        printf("Tidak ada album bernama %s\n", NamaAlbumDicari.TabWord);
    }
}

// -------------------------------------------------------------------

void CreateEmptyMap(AlbumTypeRevisi2 *Album)
{
    Album->JumlahAlbum = 0;
}

int SearchPenyanyi(ListPenyanyiRevisi LP, Word penyanyi_dicari)
{
    int i;
    boolean isfound = false;
    for (i = 0; i < LP.JumlahPenyanyi; i++)
    {
        if (IsDuplicateWord(LP.Penyanyi[i].nama, penyanyi_dicari))
        {
            isfound = true;
            break;
        }
    }
    if (isfound)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

int SearchAlbum(PenyanyiTypeRevisi2 P, Word album_dicari)
{
    int i;
    boolean isfound = false;
    for (i = 0; i < P.album.JumlahAlbum; i++)
    {
        if (IsDuplicateWord(P.album.AlbumKe[i].NamaAlbum, album_dicari))
        {
            isfound = true;
            break;
        }
    }
    if (isfound)
    {
        return i;
    }
    else
    {
        return -1;
    }
}

boolean IsEmptyMap(AlbumTypeRevisi2 Album)
{
    return Album.JumlahAlbum == 0;
}

void InsertMap(AlbumTypeRevisi2 *Album, Word NamaAlbumDicari)
{
    int i = 0;
    boolean found = false;
    while (i < Album->JumlahAlbum && !found)
    {
        if (IsDuplicateWord(Album->AlbumKe[i].NamaAlbum, NamaAlbumDicari))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    if (!found)
    {
        CopasWord(&(Album->AlbumKe[Album->JumlahAlbum].NamaAlbum), NamaAlbumDicari);
        Album->JumlahAlbum++;
        CreateEmptySet(&(Album->AlbumKe[Album->JumlahAlbum].DaftarLagu));
    }
}

void DisplayMap(ListPenyanyiRevisi L, Word PenyanyiDicari)
{
    int i = 0;
    boolean found = false;

    while (i < L.JumlahPenyanyi && !found)
    {
        if (IsDuplicateWord(L.Penyanyi[i].nama, PenyanyiDicari))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    if (found)
    {
        printf("Daftar Album oleh  ");
        printWord(L.Penyanyi[i].nama);
        printf(":\n");
        int j = 0;
        for (j = 0; j < L.Penyanyi[i].album.JumlahAlbum; j++)
        {
            printf("    %d. ", j + 1);
            printWord(L.Penyanyi[i].album.AlbumKe[j].NamaAlbum);
            printf("\n");
        }
    }
    else
    {
        printf("Tidak ada Penyanyi dengan nama tersebut\n");
    }
}

boolean IsMemberMap(AlbumTypeRevisi2 Album, Word NamaAlbumDicari)
{
    int i = 0;
    boolean found = false;

    while (i < Album.JumlahAlbum && !found)
    {
        if (IsDuplicateWord(Album.AlbumKe[i].NamaAlbum, NamaAlbumDicari))
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    return found;
}

// ! AKHIR DISINI
// ------------------------------------------------------------
// void CreatEmptySet(SetSong *S)
// {
//     S->JumlahLagu = 0;
// }

// boolean IsEmptySetSong(SetSong S)
// {
//     return S.JumlahLagu == 0;
// }

// boolean IsMemberSet(SetSong S, SongType Song)
// {
//     boolean found = false;
//     int idx = 0;
//     while (!found && idx < S.JumlahLagu)
//     {
//         if (IsSameString(S.Songs[idx].judul, Song.judul))
//         {
//             found - true;
//         }
//         else
//         {
//             idx++;
//         }
//     }
//     return found;
// }

// void InsertSet(SongType Song, AlbumTypeRevisi *Album, char *NamaAlbumDicari)
// {
//     int i = 0;
//     boolean found = false;

//     while (i < Album->JumlahAlbum && !found)
//     {
//         if (IsSameString(Album->AlbumKe[i].NamaAlbum, NamaAlbumDicari))
//         {
//             found = true;
//         }
//         else
//         {
//             i++;
//         }
//     }

//     if (IsMemberSet((Album->AlbumKe[i].DaftarLagu), Song))
//     {
//         return;
//     }

//     stringCopy(Album->AlbumKe[i].DaftarLagu.Songs[Album->AlbumKe[i].DaftarLagu.JumlahLagu].judul, Song.judul);
//     Album->AlbumKe[i].DaftarLagu.JumlahLagu++;
// }

// void DisplaySet(AlbumTypeRevisi Album, char *NamaAlbumDicari)
// {
//     int i = 0;
//     boolean found = false;

//     while (i < Album.JumlahAlbum && !found)
//     {
//         if (IsSameString(Album.AlbumKe[i].NamaAlbum, NamaAlbumDicari))
//         {
//             found = true;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     if (found)
//     {
//         printf("Daftar Lagu Album %s :\n", Album.AlbumKe[i].NamaAlbum);
//         int j;
//         for (j = 0; j < Album.AlbumKe[i].DaftarLagu.JumlahLagu; j++)
//         {
//             printf("    %d. %s\n", j + 1, Album.AlbumKe[i].DaftarLagu.Songs[j].judul);
//         }
//     }
//     else
//     {
//         printf("Tidak ada album bernama %s\n", NamaAlbumDicari);
//     }
// }

// -------------------------------------------------------------------

// void CreateEmptyMap(AlbumTypeRevisi *Album)
// {
//     Album->JumlahAlbum = 0;
// }

// int SearchPenyanyi(ListPenyanyi LP, char *penyanyi_dicari)
// {
//     int i;
//     boolean isfound = false;
//     for (i = 0; i < LP.JumlahPenyanyi; i++)
//     {
//         if (IsSameString(LP.Penyanyi[i].nama, penyanyi_dicari))
//         {
//             isfound = true;
//             break;
//         }
//     }
//     if (isfound)
//     {
//         return i;
//     }
//     else
//     {
//         return -1;
//     }
// }

// int SearchAlbum(PenyanyiTypeRevisi P, char *album_dicari)
// {
//     int i;
//     boolean isfound = false;
//     for (i = 0; i < P.album.JumlahAlbum; i++)
//     {
//         if (IsSameString(P.album.AlbumKe[i].NamaAlbum, album_dicari))
//         {
//             isfound = true;
//             break;
//         }
//     }
//     if (isfound)
//     {
//         return i;
//     }
//     else
//     {
//         return -1;
//     }
// }

// boolean IsEmptyMap(AlbumTypeRevisi Album)
// {
//     return Album.JumlahAlbum == 0;
// }

// void InsertMap(AlbumTypeRevisi *Album, char *NamaAlbumDicari)
// {
//     int i = 0;
//     boolean found = false;
//     while (i < Album->JumlahAlbum && !found)
//     {
//         if (IsSameString(Album->AlbumKe[i].NamaAlbum, NamaAlbumDicari))
//         {
//             found = true;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     if (!found)
//     {
//         stringCopy(Album->AlbumKe[Album->JumlahAlbum].NamaAlbum, NamaAlbumDicari);
//         Album->JumlahAlbum++;
//         CreatEmptySet(&(Album->AlbumKe[Album->JumlahAlbum].DaftarLagu));
//     }
// }

// void DisplayMap(ListPenyanyi L, char *PenyanyiDicari)
// {
//     int i = 0;
//     boolean found = false;

//     while (i < L.JumlahPenyanyi && !found)
//     {
//         if (IsSameString(L.Penyanyi[i].nama, PenyanyiDicari))
//         {
//             found = true;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     if (found)
//     {
//         printf("Daftar Album oleh %s :\n", L.Penyanyi[i].nama);
//         int j = 0;
//         for (j = 0; j < L.Penyanyi[i].album.JumlahAlbum; j++)
//         {
//             printf("    %d. %s\n", j + 1, L.Penyanyi[i].album.AlbumKe[j].NamaAlbum);
//         }
//     }
//     else
//     {
//         printf("Tidak ada Penyanyi dengan nama tersebut\n");
//     }
// }

// boolean IsMemberMap(AlbumTypeRevisi Album, keytype NamaAlbumDicari)
// {
//     int i = 0;
//     boolean found = false;

//     while (i < Album.JumlahAlbum && !found)
//     {
//         if (IsSameString(Album.AlbumKe[i].NamaAlbum, NamaAlbumDicari))
//         {
//             found = true;
//         }
//         else
//         {
//             i++;
//         }
//     }
//     return found;
// }