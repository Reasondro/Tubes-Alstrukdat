#include "../boolean.h"

#ifndef struct_H
#define struct_H

typedef char keytype;

typedef struct
{
  char penyanyi[50];
  char album[50];
  SongType judul_lagu[100];
} QueueSongType;

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
  char penyanyi[100];
  AlbumType album;
} PenyanyiType;

// revisi ak mulai dari sini

typedef struct
{
  SongType Songs[10]; // misal max 10 lagu per album
  int JumlahLagu;     // buat nentuin jumlah lagu misal butuh
} SetSong;

typedef struct
{
  keytype NamaAlbum[50]; // nama album si penyanyinya sebagai key
  SetSong DaftarLagu;    // kumpulan lagu dalam 1 album sebagai isi dari map
} IsiAlbum;
typedef struct
{
  IsiAlbum AlbumKe[3]; // nah ini harusny udah map yang benar
  int JumlahAlbum;
} AlbumTypeRevisi;

typedef struct
{
  char nama[100];
  AlbumTypeRevisi album; // sebagai map
} PenyanyiTypeRevisi;

typedef struct
{
  PenyanyiType Penyanyi[3]; // ini prototipe

} ListPenyanyi;

typedef struct {
    char nama[100];
    address First;
} List; //ini playlist

typedef struct {
    int id;
    List playlist;
    address next;
} DaftarPlaylist;

#endif
