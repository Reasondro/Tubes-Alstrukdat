#include "boolean.h"
#include <stdio.h>
#include <string.h>
#include "mesinkata.h"

#ifndef struct_H
#define struct_H

typedef char keytype;

typedef struct
{
  char judul[100];
} SongType;

typedef SongType valuetype;

typedef struct
{
  char penyanyi[50];
  char album[50];
  SongType judul_lagu;
} QueueSongType;

typedef struct
{
  keytype key[50];
  valuetype song;
} AlbumType;

typedef struct
{
  char penyanyi[100];
  AlbumType album;
} PenyanyiType;

// revisi ak mulai dari sini

typedef struct
{
  SongType Songs[10]; // misal max 10 lagu per album
  int JumlahLagu;     // buat nentuin jumlah lagu misal butuh
} SetSong;

typedef struct
{
  keytype NamaAlbum[50]; // nama album si penyanyinya sebagai key
  SetSong DaftarLagu;    // kumpulan lagu dalam 1 album sebagai isi dari map
} IsiAlbum;
typedef struct
{
  IsiAlbum AlbumKe[3]; // nah ini harusny udah map yang benar
  int JumlahAlbum;
} AlbumTypeRevisi;

typedef struct
{
  char nama[100];
  AlbumTypeRevisi album; // sebagai map
} PenyanyiTypeRevisi;

typedef struct
{
  PenyanyiType Penyanyi[3]; // ini prototipe

} ListPenyanyi;

//

#endif

/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stackt_H
#define stackt_H


#define NilS -1
#define MaxEl 100
/* Nil adalah stack dengan elemen kosong . */

typedef int addr; /* indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct
{
  QueueSongType T[MaxEl]; /* tabel penyimpan elemen */
  addr TOP;            /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
/* S.T[(S.TOP)] untuk mengakses elemen TOP */
/* S.TOP adalah alamat elemen TOP */

#define        Top(S) (S).TOP
#define	     Album(S) (S).T[(S).TOP].album
#define   Penyanyi(S) (S).T[(S).TOP].penyanyi
#define	Judul_Lagu(S) (S).T[(S).TOP].judul_lagu

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 (inklusif) */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, QueueSongType X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. TOP bertambah 1, X menjadi TOP yang baru, */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, QueueSongType *X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

int lengthStack(Stack S);

void displayStack(Stack S);
/* Menampilkan isi stack */
/* I.S. S mungkin kosong */
/* F.S. Isi stack ditampilkan ke layar */

void CopyStack(Stack Sin, Stack *Sout);

#endif

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0..MaxEl-1 (inklusif) */
/* Ciri stack kosong : TOP bernilai Nil */
{
    Top(*S) = NilS;
}
/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return (Top(S) == NilS);
}
boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
    return (Top(S) == MaxEl - 1);
}
/* ************ Menambahkan sebuah elemen ke Stack ************ */

void Push(Stack *S, QueueSongType X)
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
    stringCopy(Penyanyi(*S), X.penyanyi); // jadi harus strcpy buat nerima input string

    // Album(*S) = X.album;    // sama kaya di atas
    stringCopy(Album(*S), X.album); // fix sama kaya di atas

    // Judul_Lagu(*S) = X.judul_lagu; // sama kaya di atas
    stringCopy((*S).T[(*S).TOP].judul_lagu.judul, X.judul_lagu.judul); // fix sama kaya di atas
}
/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, QueueSongType *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    // (*X).penyanyi = Penyanyi(*S); // ini yang sebelumny ga dipake gara" sekarang kita make string bukan char
    stringCopy((*X).penyanyi, Penyanyi(*S)); // jadi harus strcpy buat nerima input string

    // (*X).album = Album(*S); // sama kaya di atas
    stringCopy((*X).album, Album(*S)); // fix sama kaya di atas

    // (*X).judul_lagu = Judul_Lagu(*S); // sama kaya di atas
    stringCopy((*X).judul_lagu.judul, (*S).T[(*S).TOP].judul_lagu.judul); // fix sama kaya di atas
    Top(*S)--;
}

int lengthStack(Stack S)
{
    /* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika S kosong. */
    return (Top(S) + 1);
}

void CopyStack(Stack SIn, Stack *SOut)
{
    /* I.S. SIn terdefinisi, SOut sembarang */
    /* F.S. SOut berisi salinan dari SIn (identik) */
    /* Proses : Menyalin isi SIn ke SOut */

    CreateEmptyStack(SOut);

    Stack StackTemp;
    CreateEmptyStack(&StackTemp);

    QueueSongType temp;

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

void displayStack(Stack S)
{
    if (IsEmptyStack(S))
    {
        printf("[]\n");
    }
    else
    {
        QueueSongType temp;
        Stack StackTemp;
        CopyStack(S, &StackTemp);

        int length = lengthStack(S);

        for (int i = 0; i < length; i++)
        {
            Pop(&StackTemp, &temp);
            printf("%s;", temp.penyanyi);
            printf("%s;", temp.album);
            printf("%s\n", temp.judul_lagu.judul);
        }
    }
}

// int main(){
//     Stack S, S2;
//     QueueSongType ngepush, ngepush2, ngepush3;
//     QueueSongType ngepop;
//     CreateEmptyStack(&S);
//     CreateEmptyStack (&S2);
//     char lagu[] = "lagu1";
//     char album[] = "album1";
//     char penyanyi[] = "penyanyi1";
//     stringCopy (ngepush.judul_lagu.judul, lagu);
//     stringCopy (ngepush.album, album);
//     stringCopy (ngepush.penyanyi, penyanyi);

//     char lagu2[] = "lagu2";
//     char album2[] = "album2";
//     char penyanyi2[] = "penyanyi2";
//     stringCopy (ngepush2.judul_lagu.judul, lagu2);
//     stringCopy (ngepush2.album, album2);
//     stringCopy (ngepush2.penyanyi, penyanyi2);
    
//     char lagu3[] = "lagu3";
//     char album3[] = "album3";
//     char penyanyi3[] = "penyanyi3";
//     stringCopy (ngepush3.judul_lagu.judul, lagu3);
//     stringCopy (ngepush3.album, album3);
//     stringCopy (ngepush3.penyanyi, penyanyi3);
    
//     if (IsEmptyStack(S)){
//         printf("\n");
//         Push (&S, ngepush);
//         Pop (&S, &ngepop);
//         Push (&S, ngepush2);
//         Push (&S, ngepush3);
//         CopyStack(S, &S2);
//         printf("Isi dari S2 (salinan S): \n");
//         displayStack(S2);
//         printf("\n");
//         Pop (&S, &ngepop);
//         printf("Isi Top dari S: \n");
//         printf ("%s %s %s\n\n", ngepop.judul_lagu.judul, ngepop.album, ngepop.penyanyi);
//         printf("Panjang Stack setelah nge pop 1x (harusnya 2): \n");
//         printf("%d\n\n", lengthStack(S));
//     }else{
//         printf("0\n");
//     }
//     return 0;
// }