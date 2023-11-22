#include "../boolean.h"

#ifndef struct_H
#define struct_H

#define NMax 100
#define NMaxLoad 1000
#define penyanyimax 20
#define albummax 20
#define NilS -1
#define MaxEl 100

typedef struct
{
  char TabWord[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
  int Length;
} Word;

typedef struct
{
  char TabLine[NMaxLoad];
  int LengthLine;
  /* data */
} Line;

typedef struct
{
  Word penyanyi;
  Word album;
  Word judul_lagu;
} QueueSongTypeRevisi;

typedef struct
{
  Word Songs[10]; // misal max 10 lagu per album
  int JumlahLagu; // buat nentuin jumlah lagu misal butuh
} SetSongRevisi;

typedef struct
{
  Word NamaAlbum;           // nama album si penyanyinya sebagai key
  SetSongRevisi DaftarLagu; // kumpulan lagu dalam 1 album sebagai isi dari map
} IsiAlbumRevisi;
typedef struct
{
  IsiAlbumRevisi AlbumKe[4]; // nah ini harusny udah map yang benar
  int JumlahAlbum;
} AlbumTypeRevisi2;

typedef struct
{
  Word nama;
  AlbumTypeRevisi2 album; // sebagai map
} PenyanyiTypeRevisi2;

typedef struct
{
  PenyanyiTypeRevisi2 Penyanyi[5]; // ini prototipe
  int JumlahPenyanyi;
} ListPenyanyiRevisi;

typedef struct tSongPlay *addressPlaylist;
typedef struct tSongPlay
{
  QueueSongTypeRevisi info;
  addressPlaylist next;
} SongPlay;

typedef struct
{
  Word nama;
  addressPlaylist First;
} Playlist;

typedef struct
{
  int Capacity;
  Playlist *pl;
  int Neff;
} DaftarPlaylist;

typedef struct
{
  QueueSongTypeRevisi T[MaxEl]; /* tabel penyimpan elemen */
  int TOP;                      /* alamat TOP: elemen puncak */
} StackRevisi;

// ges pusing ges tolong

#endif

// typedef struct
// {
//   char penyanyi[50];
//   char album[50];
//   Word judul_lagu;
// } QueueSongType;

// typedef struct
// {
//   SongType Songs[15]; // misal max 15 lagu per album
//   int JumlahLagu;     // buat nentuin jumlah lagu misal butuh
// } SetSong;

// typedef struct
// {
//   keytype NamaAlbum;  // nama album si penyanyinya sebagai key
//   SetSong DaftarLagu; // kumpulan lagu dalam 1 album sebagai isi dari map
// } IsiAlbum;
// typedef struct
// {
//   IsiAlbum AlbumKe[albummax]; // nah ini harusny udah map yang benar
//   int JumlahAlbum;
// } AlbumTypeRevisi;

// typedef struct
// {
//   char nama[100];
//   AlbumTypeRevisi album; // sebagai map
// } PenyanyiTypeRevisi;

// typedef struct
// {
//   PenyanyiTypeRevisi Penyanyi[5];
//   int JumlahPenyanyi;
// } ListPenyanyi;