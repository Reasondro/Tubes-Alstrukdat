

#include "../../boolean.h"
#include "../struct.h"
#include "../MesinKarakter_MesinKata/mesinkata.h"
#include <stdio.h>


// typedef char Word[20];

void CreatEmptySet(SetSongRevisi *S);

boolean IsMemberSet(SetSongRevisi S, QueueSongTypeRevisi Song);

int SearchAlbum(PenyanyiTypeRevisi2 P, Word album_dicari);

int SearchPenyanyi(ListPenyanyiRevisi LP, Word penyanyi_dicari);

void InsertSet(QueueSongTypeRevisi Song, AlbumTypeRevisi2 *Album, Word NamaAlbumDicari);

void DisplaySet(AlbumTypeRevisi2 Album, Word NamaAlbumDicari);

void CreateEmptyMap(AlbumTypeRevisi2 *Album);

boolean IsEmptyMap(AlbumTypeRevisi2 Album);

void InsertMap(AlbumTypeRevisi2 *Album, Word NamaAlbumDicari);

void DisplayMap(ListPenyanyiRevisi L, Word PenyanyiDicari);

boolean IsMemberMap(AlbumTypeRevisi2 Album, Word NamaAlbumDicari);
