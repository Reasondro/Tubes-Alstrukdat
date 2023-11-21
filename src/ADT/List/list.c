// // list.c

// #include <stdio.h>
// #include "list.h"

// void CreateEmptyListPenyanyi(ListPenyanyi *L)
// {
//     (*L).JumlahPenyanyi = 0;
// }

// void InsertPenyanyi(ListPenyanyi *L, PenyanyiTypeRevisi P)
// {
//     L->Penyanyi[L->JumlahPenyanyi] = P;
//     CreateEmptyMap(&(L->Penyanyi[L->JumlahPenyanyi].album));
//     L->JumlahPenyanyi++;
// }

// void DisplayListPenyanyi(ListPenyanyi L)
// {
//     printf("Daftar Penyanyi: \n");
//     for (int i = 0; i < L.JumlahPenyanyi; i++)
//     {
//         printf("    %d. %s\n", i + 1, L.Penyanyi[i].nama);
//     }
// }
// // /* ********** KONSTRUKTOR ********** */
// // /* Konstruktor: create list kosong */
// // List MakeList(){
// //     List L;
// //     int i;
// //     for (i = 0; i < MaxEl; i++){
// //         strcpy(L.A[i].penyanyi, -9999);
// //     }
// //     return L;
// // }
// // /* I.S. sembarang */
// // /* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

// // Implementasi fungsi untuk menampilkan daftar lagu dari album tertentu
// void showSongList(AlbumType albumList[], int jumlahAlbum, char album[]) {
//     for (int i = 0; i < jumlahAlbum; i++) {
//         if (strcmp(albumList[i].key, album) == 0) {
//             printf("Daftar Lagu di %s:\n", album);
//             for (int j = 0; j < jumlahLagu; j++) {
//                 printf("%s\n", albumList[i].song[j].judul);
//             }
//             break;
//         }
//     }
// }

// // Implementasi fungsi untuk menampilkan daftar playlist yang dimiliki pengguna
// void showPlaylistList(PlaylistType playlistList[], int jumlahPlaylist) {
//     if (jumlahPlaylist > 0) {
//         printf("Daftar playlist yang kamu miliki:\n");
//         for (int i = 0; i < jumlahPlaylist; i++) {
//             printf("%s\n", playlistList[i].namaPlaylist);
//         }
//     } else {
//         printf("Kamu tidak memiliki playlist.\n");
//     }
// }
