#include <stdio.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 (inklusif) */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = Nil;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == Nil);
}
boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == MaxEl - 1);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */

void PushAll(Stack *S, songtype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */
{
    if (IsEmptyStack(*S))
    {
        Top(*S) = 0;
    }
    else
    {
        Top(*S)++;
    }

    // Penyanyi(*S) = X.penyanyi; // ini yang sebelumny ga dipake gara" sekarang kita make string bukan char
    strcpy(Penyanyi(*S), X.penyanyi); // jadi harus strcpy buat nerima input string

    // Album(*S) = X.album;    // sama kaya di atas
    strcpy(Album(*S), X.album); // fix sama kaya di atas

    // Judul_Lagu(*S) = X.judul_lagu; // sama kaya di atas
    strcpy(Judul_Lagu(*S), X.judul_lagu); // fix sama kaya di atas
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, songtype *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    // (*X).penyanyi = Penyanyi(*S); // ini yang sebelumny ga dipake gara" sekarang kita make string bukan char
    strcpy((*X).penyanyi, Penyanyi(*S)); // jadi harus strcpy buat nerima input string

    // (*X).album = Album(*S); // sama kaya di atas
    strcpy((*X).album, Album(*S)); // fix sama kaya di atas

    // (*X).judul_lagu = Judul_Lagu(*S); // sama kaya di atas
    strcpy((*X).judul_lagu, Judul_Lagu(*S)); // fix sama kaya di atas
    Top(*S)--;
}