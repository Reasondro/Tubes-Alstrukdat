/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H

#include "../../boolean.h"
#include "../struct.h"
#include "../MesinKarakter_MesinKata/mesinkata.h"

#define NilS -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef int addr; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
  QueueSongType T[MaxEl]; /* tabel penyimpan elemen */
  addr TOP;               /* alamat TOP: elemen puncak */
} Stack;

typedef struct
{
  QueueSongType T[MaxEl]; /* tabel penyimpan elemen */
  addr TOP;               /* alamat TOP: elemen puncak */
} StackRevisi;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

#define Top(S) (S).TOP
#define Album(S) (S).T[(S).TOP].album
#define Penyanyi(S) (S).T[(S).TOP].penyanyi
#define Judul_Lagu(S) (S).T[(S).TOP].judul_lagu

// /* ************ Prototype ************ */
// /* *** Konstruktor/Kreator *** */
// void CreateEmptyStack(Stack *S);
// /* I.S. sembarang; */
// /* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
// /* jadi indeksnya antara 0..MaxEl-1 (inklusif) */
// /* Ciri stack kosong : TOP bernilai Nil */

// /* ************ Predikat Untuk test keadaan KOLEKSI ************ */
// boolean IsEmptyStack(Stack S);
// /* Mengirim true jika Stack kosong: lihat definisi di atas */
// boolean IsFullStack(Stack S);
// /* Mengirim true jika tabel penampung nilai elemen stack penuh */

// /* ************ Menambahkan sebuah elemen ke Stack ************ */
// void Push(Stack *S, QueueSongTypeRevisi X);
// /* Menambahkan X sebagai elemen Stack S. */
// /* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
// /* F.S. TOP bertambah 1, X menjadi TOP yang baru, */

// /* ************ Menghapus sebuah elemen Stack ************ */
// void Pop(Stack *S, QueueSongTypeRevisi *X);
// /* Menghapus X dari Stack S. */
// /* I.S. S  tidak mungkin kosong */
// /* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

// int lengthStack(Stack S);

// void displayStack(Stack S);
// /* Menampilkan isi stack */
// /* I.S. S mungkin kosong */
// /* F.S. Isi stack ditampilkan ke layar */

// void CopyStack(Stack Sin, Stack *Sout);

#endif