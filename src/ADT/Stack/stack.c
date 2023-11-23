#include <stdio.h>
#include <string.h>
#include "stack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(StackRevisi *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 (inklusif) */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = NilS;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(StackRevisi S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == NilS);
}
boolean IsFullStack(StackRevisi S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == MaxEl - 1);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */

void Push(StackRevisi *S, QueueSongTypeRevisi X)
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
    // printf("%s", (*S).T[(*S).TOP].penyanyi.TabWord);
    // printf("%s", X.penyanyi.TabWord);
    // Penyanyi(*S) = X.penyanyi; // ini yang sebelumny ga dipake gara" sekarang kita make string bukan char
    CopasWord(&(S->T[S->TOP].penyanyi), X.penyanyi); // jadi harus strcpy buat nerima input string
    // printf("%s", (*S).T[(*S).TOP].penyanyi);

    // Album(*S) = X.album;    // sama kaya di atas
    CopasWord(&(S->T[S->TOP].album), X.album); // fix sama kaya di atas

    // Judul_Lagu(*S) = X.judul_lagu; // sama kaya di atas
    CopasWord(&(S->T[S->TOP].judul_lagu), X.judul_lagu); // fix sama kaya di atas
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(StackRevisi *S, QueueSongTypeRevisi *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    // (*X).penyanyi = Penyanyi(*S); // ini yang sebelumny ga dipake gara" sekarang kita make string bukan char
    // printf("%s", (*S).T[(*S).TOP].penyanyi);
    CopasWord(&(X->penyanyi), S->T[S->TOP].penyanyi); // jadi harus strcpy buat nerima input string
    // printf("%s", X->penyanyi);
    // (*X).album = Album(*S); // sama kaya di atas
    CopasWord(&(X->album), S->T[S->TOP].album); // fix sama kaya di atas
    // printf("%s", X->album);
    // (*X).judul_lagu = Judul_Lagu(*S); // sama kaya di atas
    CopasWord(&(X->judul_lagu), (S->T[S->TOP].judul_lagu)); // fix sama kaya di atas
    // printf("%s", X->judul_lagu);
    Top(*S)--;
}

int lengthStack(StackRevisi S)
{
    /* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika S kosong. */
    return (Top(S) + 1);
}

void CopyStack(StackRevisi SIn, StackRevisi *SOut)
{
    /* I.S. SIn terdefinisi, SOut sembarang */
    /* F.S. SOut berisi salinan dari SIn (identik) */
    /* Proses : Menyalin isi SIn ke SOut */

    CreateEmptyStack(SOut);

    StackRevisi StackTemp;
    CreateEmptyStack(&StackTemp);

    QueueSongTypeRevisi temp;

    int length = lengthStack(SIn);

    for (int i = 0; i < length; i++)
    {

        Pop(&SIn, &temp);
        Push(&StackTemp, temp);
    }

    for (int i = 0; i < length; i++)
    {
        Pop(&StackTemp, &temp);
        Push(&SIn, temp);
        Push(SOut, temp);
    }
}

void displayStack(StackRevisi S)
{
    if (IsEmptyStack(S))
    {
        printf("[]\n");
    }
    else
    {
        QueueSongTypeRevisi temp;
        StackRevisi StackTemp;
        CopyStack(S, &StackTemp);

        int length = lengthStack(S);

        for (int i = 0; i < length; i++)
        {
            Pop(&StackTemp, &temp);
            printWord(temp.penyanyi);
            printf(";");
            printWord(temp.album);
            printf(";");
            printWord(temp.judul_lagu);
            printf("\n");
        }
    }
}

void ReverseStack(StackRevisi *Stack)
{
    int i;
    QueueSongTypeRevisi mindah;
    StackRevisi temp;
    CreateEmptyStack(&temp);
    int length = lengthStack(*Stack);
    for (i = 0; i < length; i++)
    {
        Pop(Stack, &mindah);
        Push(&temp, mindah);
    }
    CopyStack(temp, Stack);
}