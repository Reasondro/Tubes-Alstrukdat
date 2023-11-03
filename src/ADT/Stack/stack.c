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
    return(Top(S) == Nil);
}
boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == MaxEl-1);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */

void PushAll(Stack * S, songtype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */
{
    if (IsEmptyStack(*S)){
        Top(*S) = 0;
    }else{
        Top(*S) ++;
    }
    Penyanyi(*S) = X.penyanyi;
    Album(*S) = X.album;
    Judul_Lagu(*S) = X.judul_lagu;
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, songtype* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X).penyanyi = Penyanyi(*S);
    (*X).album = Album(*S);
    (*X).judul_lagu = Judul_Lagu(*S);
    Top(*S)--;
}