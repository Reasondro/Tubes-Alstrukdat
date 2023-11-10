#include "../boolean.h"

#ifndef struct_H
#define struct_H

typedef char keytype;

typedef struct{
  char penyanyi[50];
  char album[50];
  SongType judul_lagu[100];
} QueueSongType;

typedef struct{
  char judul[100];
} SongType;

typedef SongType valuetype;

typedef struct{
  keytype key[50];
  valuetype song;
} AlbumType;

typedef struct{
  char penyanyi[100];
  AlbumType album;
} PenyanyiType;

#endif
