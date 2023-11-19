

#include "boolean.h"
// #include "mesinkarakter.c" // non comment hanya klao mo test
// #include "mesinkata.c"

typedef char keytype[50];

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

void InsertSet(SongType Song, AlbumTypeRevisi *Album, keytype NamaAlbumDicari)
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

void DisplaySet(AlbumTypeRevisi Album, keytype NamaAlbumDicari)
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

    int j;
    for (j = 0; j < Album.AlbumKe[i].DaftarLagu.JumlahLagu; j++)
    {
        printf("Lagu %d dari Album %s : %s\n", j + 1, Album.AlbumKe[i].NamaAlbum, Album.AlbumKe[i].DaftarLagu.Songs[j].judul);
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

void InsertMap(AlbumTypeRevisi *Album, keytype NamaAlbumDicari)
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

void DisplayMap(AlbumTypeRevisi Album)
{
    int i;
    for (i = 0; i < Album.JumlahAlbum; i++)
    {
        printf("Album %d : %s\n", i + 1, Album.AlbumKe[i].NamaAlbum);
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

typedef struct
{
    char nama[100];
    AlbumTypeRevisi album; // sebagai map
} PenyanyiTypeRevisi;

typedef struct
{
    PenyanyiTypeRevisi Penyanyi[3]; // ini prototipe

} ListPenyanyi;
