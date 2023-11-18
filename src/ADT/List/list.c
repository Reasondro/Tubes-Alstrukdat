// list.c

#include <stdio.h>
#include "list.h"

// Implementasi fungsi untuk menampilkan daftar penyanyi
void showSingerList(ListPenyanyi penyanyiList, int jumlahPenyanyi) {
    printf("Daftar Penyanyi :\n");
    for (int i = 0; i < jumlahPenyanyi; i++) {
        printf("%s\n", penyanyiList.Penyanyi[i].nama);
    }
}

// Implementasi fungsi untuk menampilkan daftar album dari penyanyi tertentu
void showAlbumList(ListPenyanyi penyanyiList, int jumlahPenyanyi, char penyanyi[]) {
    for (int i = 0; i < jumlahPenyanyi; i++) {
        if (strcmp(penyanyiList.Penyanyi[i], penyanyi) == 0) {
            printf("Daftar Album oleh %s :\n", penyanyi);
            for (int j = 0; j < penyanyiList.Penyanyi[i].album.JumlahAlbum; j++) {
                printf("%s\n", penyanyiList.Penyanyi[i].album.AlbumKe[j].NamaAlbum);
            }
            break;
        }
    }
}

// Implementasi fungsi untuk menampilkan daftar lagu dari album tertentu
void showSongList(AlbumType albumList[], int jumlahAlbum, char album[]) {
    for (int i = 0; i < jumlahAlbum; i++) {
        if (strcmp(albumList[i].key, album) == 0) {
            printf("Daftar Lagu di %s:\n", album);
            for (int j = 0; j < jumlahLagu; j++) {
                printf("%s\n", albumList[i].song[j].judul);
            }
            break;
        }
    }
}

// Implementasi fungsi untuk menampilkan daftar playlist yang dimiliki pengguna
void showPlaylistList(PlaylistType playlistList[], int jumlahPlaylist) {
    if (jumlahPlaylist > 0) {
        printf("Daftar playlist yang kamu miliki:\n");
        for (int i = 0; i < jumlahPlaylist; i++) {
            printf("%s\n", playlistList[i].namaPlaylist);
        }
    } else {
        printf("Kamu tidak memiliki playlist.\n");
    }
}
