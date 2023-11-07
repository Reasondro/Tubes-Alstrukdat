#include "../boolean.h"

#ifndef struct_H
#define struct_H

typedef char keytype;
typedef SongType valuetype;

typedef struct{
  char penyanyi[50];
  char album[50];
  char judul_lagu[100];
} QueueSongType;

typedef struct{
  char judul[100];
} SongType;

typedef struct{
  keytype key[50];
  valuetype song;
} AlbumType;

typedef struct{
  char penyanyi[100];
  AlbumType album;
} PenyanyiType;

#endif