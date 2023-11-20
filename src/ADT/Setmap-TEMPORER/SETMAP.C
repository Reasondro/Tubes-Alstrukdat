

#include "boolean.h"
// #include "mesinkarakter.c" // non comment hanya klao mo test
// #include "mesinkata.c"

typedef char keytype[20];

// typedef struct
// {
//     char judul[100];
// } SongType;

typedef struct
{
    SongType Songs[10]; // misal max 10 lagu per album
    int JumlahLagu;     // buat nentuin jumlah lagu misal butuh
} SetSong;

typedef struct
{
    keytype NamaAlbum;  // nama album si penyanyinya sebagai key
    SetSong DaftarLagu; // kumpulan lagu dalam 1 album sebagai isi dari map
} IsiAlbum;
typedef struct
{
    IsiAlbum AlbumKe[3]; // nah ini harusny udah map yang benar
    int JumlahAlbum;
} AlbumTypeRevisi;

//------------------------------

void CreatEmptySet(SetSong *S)
{
    S->JumlahLagu = 0;
}

boolean IsEmptySetSong(SetSong S)
{
    return S.JumlahLagu == 0;
}

boolean IsMemberSet(SetSong S, SongType Song)
{
    boolean found = false;
    int idx = 0;
    while (!found && idx < S.JumlahLagu)
    {
        if (IsSameString(S.Songs[idx].judul, Song.judul))
        {
            found - true;
        }
        else
        {
            idx++;
        }
    }
    return found;
}

void InsertSet(SongType Song, AlbumTypeRevisi *Album, char *NamaAlbumDicari)
{
    int i = 0;
    boolean found = false;

    while (i < Album->JumlahAlbum && !found)
    {
        if (IsSameString(Album->AlbumKe[i].NamaAlbum, NamaAlbumDicari))
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

    stringCopy(Album->AlbumKe[i].DaftarLagu.Songs[Album->AlbumKe[i].DaftarLagu.JumlahLagu].judul, Song.judul);
    Album->AlbumKe[i].DaftarLagu.JumlahLagu++;
}

void DisplaySet(AlbumTypeRevisi Album, char *NamaAlbumDicari)
{
    int i = 0;
    boolean found = false;

    while (i < Album.JumlahAlbum && !found)
    {
        if (IsSameString(Album.AlbumKe[i].NamaAlbum, NamaAlbumDicari))
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
        printf("Daftar Lagu Album %s :\n", Album.AlbumKe[i].NamaAlbum);
        int j;
        for (j = 0; j < Album.AlbumKe[i].DaftarLagu.JumlahLagu; j++)
        {
            printf("    %d. %s\n", j + 1, Album.AlbumKe[i].DaftarLagu.Songs[j].judul);
        }
    }
    else
    {
        printf("Tidak ada album bernama %s\n", NamaAlbumDicari);
    }
}

// -------------------------------------------------------------------

void CreateEmptyMap(AlbumTypeRevisi *Album)
{
    Album->JumlahAlbum = 0;
}

boolean IsEmptyMap(AlbumTypeRevisi Album)
{
    return Album.JumlahAlbum == 0;
}

void InsertMap(AlbumTypeRevisi *Album, char *NamaAlbumDicari)
{
    int i = 0;
    boolean found = false;
    while (i < Album->JumlahAlbum && !found)
    {
        if (IsSameString(Album->AlbumKe[i].NamaAlbum, NamaAlbumDicari))
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
        stringCopy(Album->AlbumKe[Album->JumlahAlbum].NamaAlbum, NamaAlbumDicari);
        Album->JumlahAlbum++;
        CreatEmptySet(&(Album->AlbumKe[Album->JumlahAlbum].DaftarLagu));
    }
}

// void DisplayMap(AlbumTypeRevisi Album)
// {
//     int i;
//     for (i = 0; i < Album.JumlahAlbum; i++)
//     {
//         printf("Album %d : %s\n", i + 1, Album.AlbumKe[i].NamaAlbum);
//     }
// }

typedef struct
{
    char nama[50];
    AlbumTypeRevisi album; // sebagai map
} PenyanyiTypeRevisi;

typedef struct
{
    PenyanyiTypeRevisi Penyanyi[5]; // ini prototipe
    int JumlahPenyanyi;
} ListPenyanyi;

void DisplayMap(ListPenyanyi L, char *PenyanyiDicari)
{
    int i = 0;
    boolean found = false;

    while (i < L.JumlahPenyanyi && !found)
    {
        if (IsSameString(L.Penyanyi[i].nama, PenyanyiDicari))
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
        printf("Daftar Album oleh %s :\n", L.Penyanyi[i].nama);
        int j = 0;
        for (j = 0; j < L.Penyanyi[i].album.JumlahAlbum; j++)
        {
            printf("    %d. %s\n", j + 1, L.Penyanyi[i].album.AlbumKe[j].NamaAlbum);
        }
    }
    else
    {
        printf("Tidak ada Penyanyi dengan nama tersebut\n");
    }
}

boolean IsMemberMap(AlbumTypeRevisi Album, keytype NamaAlbumDicari)
{
    int i = 0;
    boolean found = false;

    while (i < Album.JumlahAlbum && !found)
    {
        if (IsSameString(Album.AlbumKe[i].NamaAlbum, NamaAlbumDicari))
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

// ------------------------------------------------------------
