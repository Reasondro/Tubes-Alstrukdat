/* File : listlinier.h */
/* contoh ADT list berkait dengan representasi fisik pointer  */
/* Representasi addressPlaylist dengan pointer */
/* infotype adalah integer */

#ifndef listlinier_H
#define listlinier_H

#include "../struct.h"
#include <stdio.h>
#include "stdlib.h"
#include "../MesinKarakter_MesinKata/mesinkata.h"
#include "../MesinKarakter_MesinKata/mesinkarakter.h"

#define Nil NULL

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan addressPlaylist P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressPlaylistnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Nama(L) ((L).nama)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmptyList(Playlist L);
/* Mengirim true jika Playlist kosong */

/****************** PEMBUATAN Playlist KOSONG ******************/
void CreateEmpty(Playlist *L);
/* I.S. sembarang             */
/* F.S. Terbentuk Playlist kosong */

/****************** Manajemen Memori ******************/
addressPlaylist Alokasi(char penyanyi[], char album[], char judul[]);
/* Mengirimkan addressPlaylist hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressPlaylist tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi(addressPlaylist *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressPlaylist P */

/****************** PENCARIAN SEBUAH ELEMEN Playlist ******************/
boolean Search(Playlist L, QueueSongType X);
/* Mencari apakah ada elemen Playlist dengan info(P)= X */
/* Jika ada, mengirimkan addressPlaylist elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVLast(Playlist *L, QueueSongType X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen Playlist di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(Playlist *L, QueueSongType *X);
/* I.S. Playlist L tidak kosong  */
/* F.S. Elemen pertama Playlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast(Playlist *L, QueueSongType *X);
/* I.S. Playlist tidak kosong */
/* F.S. Elemen terakhir Playlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(Playlist *L, addressPlaylist P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressPlaylist P sebagai elemen pertama */
void InsertAfter(Playlist *L, addressPlaylist P, addressPlaylist Prec);
/* I.S. Prec pastilah elemen Playlist dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast(Playlist *L, addressPlaylist P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(Playlist *L, addressPlaylist *P);
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen pertama Playlist sebelum penghapusan */
/*      Elemen Playlist berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP(Playlist *L, SongType X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen Playlist beraddressPlaylist P, dengan info(P)=X  */
/* Maka P dihapus dari Playlist dan di-dealokasi */
/* Jika tidak ada elemen Playlist dengan info(P)=X, maka Playlist tetap */
/* Playlist mungkin menjadi kosong karena penghapusan */
void DelLast(Playlist *L, addressPlaylist *P);
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen terakhir Playlist sebelum penghapusan  */
/*      Elemen Playlist berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter(Playlist *L, addressPlaylist *Pdel, addressPlaylist Prec);
/* I.S. Playlist tidak kosong. Prec adalah anggota Playlist  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen Playlist yang dihapus  */

/****************** PROSES SEMUA ELEMEN Playlist ******************/
void PrintInfo(Playlist L);
/* I.S. Playlist mungkin kosong */
/* F.S. Jika Playlist tidak kosong, iai Playlist dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Playlist kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt(Playlist L);
/* Mengirimkan banyaknya elemen Playlist; mengirimkan 0 jika Playlist kosong */

/****************** PROSES TERHADAP Playlist ******************/

void InversList(Playlist *L);
/* I.S. sembarang. */
/* F.S. elemen Playlist dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen Playlist, tanpa melakukan alokasi/dealokasi. */

void Konkat1(Playlist *L1, Playlist *L2, Playlist *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah Playlist : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen Playlist L1 dan L2) */
/* dan L1 serta L2 menjadi Playlist kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

addressPlaylist AddressAtIndex(Playlist L, int idx);

void swap_tengah(Playlist L, int idx1, int idx2);

void swap_pinggir(Playlist L, int idx1, int idx2);

#endif
