#include "../boolean.h"

#ifndef struct_H
#define struct_H

#define NMax 100
#define NMaxLoad 1000
#define penyanyimax 20
#define albummax 20
#define MaxEl 100
typedef char keytype[50];

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
  char judul[100];
} SongType;

typedef SongType valuetype;

typedef struct
{
  char penyanyi[50];
  char album[50];
  Word judul_lagu;
} QueueSongType;

typedef struct
{
  Word penyanyi;
  Word album;
  Word judul_lagu;
} QueueSongTypeRevisi;

// revisi ak mulai dari sini

typedef struct
{
  SongType Songs[15]; // misal max 15 lagu per album
  int JumlahLagu;     // buat nentuin jumlah lagu misal butuh
} SetSong;

typedef struct
{
  keytype NamaAlbum;  // nama album si penyanyinya sebagai key
  SetSong DaftarLagu; // kumpulan lagu dalam 1 album sebagai isi dari map
} IsiAlbum;
typedef struct
{
  IsiAlbum AlbumKe[albummax]; // nah ini harusny udah map yang benar
  int JumlahAlbum;
} AlbumTypeRevisi;

typedef struct
{
  Word nama;
  AlbumTypeRevisi album; // sebagai map
} PenyanyiTypeRevisi;

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
  PenyanyiTypeRevisi Penyanyi[penyanyimax];
  int JumlahPenyanyi;
} ListPenyanyi;

typedef struct
{
  QueueSongTypeRevisi T[MaxEl]; /* tabel penyimpan elemen */
  int TOP;               /* alamat TOP: elemen puncak */
} StackRevisi;

// ges pusing ges tolong

#endif