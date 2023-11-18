// list.h

#ifndef LIST_H
#define LIST_H

#include "struct.h"

// Fungsi untuk menampilkan daftar penyanyi
void showSingerList(PenyanyiType penyanyiList, int jumlahPenyanyi);

// Fungsi untuk menampilkan daftar album dari penyanyi tertentu
void showAlbumList(PenyanyiType penyanyiList, int jumlahPenyanyi, char penyanyi[]);

// Fungsi untuk menampilkan daftar lagu dari album tertentu
void showSongList(AlbumType albumList, int jumlahAlbum, char album[]);

// Fungsi untuk menampilkan daftar playlist yang dimiliki pengguna
void showPlaylistList(PlaylistType playlistList, int jumlahPlaylist);

#endif
