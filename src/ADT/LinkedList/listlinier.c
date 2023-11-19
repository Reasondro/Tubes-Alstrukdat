/* File : listlinier.C */
/* contoh ADT Playlist berkait dengan representasi fisik pointer  */
/* Representasi address dengan pointer */
/* infotype adalah integer */

#include "listlinier.h"

/* PROTOTYPE */
/****************** TEST Playlist KOSONG ******************/
boolean IsEmptyList(Playlist L)
/* Mengirim true jika Playlist kosong */
{
    return First(L) == Nil;
}

/****************** PEMBUATAN Playlist KOSONG ******************/
void CreateEmpty(Playlist *L)
/* I.S. sembarang             */
/* F.S. Terbentuk Playlist kosong */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi(char penyanyi[], char album[], char judul[])
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address)malloc(1 * sizeof(SongPlay));
    if (P != Nil){
        stringCopy(&Info(P).album, &album);
        stringCopy(&Info(P).judul_lagu.judul, &judul);
        stringCopy(&Info(P).penyanyi, &penyanyi);
        Next(P) = Nil;
        return P;
    }
    else return Nil;
}

void Dealokasi(address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN Playlist ******************/
address Search(Playlist L, QueueSongType X)
/* Mencari apakah ada elemen Playlist dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P;
    boolean bFound = false;
    if (!IsEmptyList(L)){
        P = First(L);
        while (!bFound && P != Nil){
            if (IsSameString(&X.judul_lagu.judul, &Info(P).judul_lagu.judul)&&
                IsSameString(&X.album, &Info(P).album)&&
                IsSameString(&X.penyanyi, &Info(P).penyanyi)) {
                bFound = true;
            }
            else P = Next(P);
        }
    } return bFound;
}

void InsVLast(Playlist *L, QueueSongType X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen Playlist di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X.penyanyi,X.album,X.judul_lagu.judul);
    if (P != Nil)
    {
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(Playlist *L, QueueSongType *X)
/* I.S. Playlist L tidak kosong  */
/* F.S. Elemen pertama Playlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dtpealokasi */
{
    address P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast(Playlist *L, QueueSongType *X)
/* I.S. Playlist tidak kosong */
/* F.S. Elemen terakhir Playlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P = First(*L);
    address Prec = Nil;

    while (Next(P) != Nil)
    {
        Prec = P;
        P = Next(P);
    }

    *X = Info(P);
    if (Prec != Nil)
    {
        Next(Prec) = Nil;
    }
    else
    {
        First(*L) = Nil;
    }
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst(Playlist *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(Playlist *L, address P, address Prec)
/* I.S. Prec pastilah elemen Playlist dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(Playlist *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    address Last;
    if (IsEmptyList(*L)) InsertFirst(L, P);
    else
    {
        Last = First(*L);
        while (Next(Last) != Nil)
        {
            Last = Next(Last);
        }
        InsertAfter(L, P, Last);
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst(Playlist *L, address *P)
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen pertama Playlist sebelum penghapusan */
/*      Elemen Playlist berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}

// void DelP(Playlist *L, QueueSongType X)
// /* I.S. Sembarang */
// /* F.S. Jika ada elemen Playlist beraddress P, dengan Info(P)=X  */
// /* Maka P dihapus dari Playlist dan di-dealokasi */
// /* Jika tidak ada elemen Playlist dengan Info(P)=X, maka Playlist tetap */
// /* Playlist mungkin menjadi kosong karena penghapusan */
// {
//     address Prec;
//     address P;
//     boolean bFound = false;

//     if (!IsEmptyList(*L))
//     {
//         if (IsSameString(X.judul, Info(P).judul))
//         {
//             DelFirst(L, &P);
//             Dealokasi(&P);
//         }
//         else
//         {
//             P = First(*L);
//             while (!bFound && P != Nil)
//             {
//                 if (IsSameString(X.judul, Info(P).judul))
//                 {
//                     bFound = true;
//                 }
//                 else
//                 {
//                     Prec = P;
//                     P = Next(P);
//                 }
//             }

//             if (bFound)
//             {
//                 DelAfter(L, &P, Prec);
//                 Dealokasi(&P);
//             }
//         }
//     }
// }

void DelLast(Playlist *L, address *P)
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen terakhir Playlist sebelum penghapusan  */
/*      Elemen Playlist berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    address Last = First(*L);
    address PrecLast = Nil;

    while (Next(Last) != Nil)
    {
        PrecLast = Last;
        Last = Next(Last);
    }

    *P = Last;
    if (PrecLast == Nil)
    {
        First(*L) = Nil;
    }
    else
    {
        Next(PrecLast) = Nil;
    }
}

void DelAfter(Playlist *L, address *Pdel, address Prec)
/* I.S. Playlist tidak kosong. Prec adalah anggota Playlist  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen Playlist yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
    Next(*Pdel) = Nil;
}

/****************** PROSES SEMUA ELEMEN Playlist ******************/
void PrintInfo(Playlist L)
/* I.S. Playlist mungkin kosong */
/* F.S. Jika Playlist tidak kosong, iai Playlist dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Playlist kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P;
    boolean isFirst = true;

    printf("[");
    if (!IsEmptyList(L))
    {
        P = First(L);
        while (P != Nil)
        {
            if (!isFirst)
            {
                printf(",");
            }
            printf("%d", Info(P));
            isFirst = false;

            P = Next(P);
        }
    }
    printf("]");
}
int NbElmt(Playlist L)
/* Mengirimkan banyaknya elemen Playlist; mengirimkan 0 jika Playlist kosong */
{
    int cnt = 0;
    address P;

    if (!IsEmptyList(L))
    {
        P = First(L);
        while (P != Nil)
        {
            cnt++;
            P = Next(P);
        }
    }

    return cnt;
}

/****************** PROSES TERHADAP Playlist ******************/
void InversList(Playlist *L)
/* I.S. sembarang. */
/* F.S. elemen Playlist dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen Playlist, tanpa melakukan alokasi/dealokasi. */
{
    address P;
    address Prec = Nil;
    address Succ;

    if (!IsEmptyList(*L))
    {
        P = First(*L);
        while (P != Nil)
        {
            Succ = Next(P);
            Next(P) = Prec;
            Prec = P;
            P = Succ;
        }
        First(*L) = Prec;
    }
}

void Konkat1(Playlist *L1, Playlist *L2, Playlist *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah Playlist : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen Playlist L1 dan L2) */
/* dan L1 serta L2 menjadi Playlist kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    address Last1;

    CreateEmpty(L3);
    if (IsEmptyList(*L1))
    {
        First(*L3) = First(*L2);
    }
    else
    {
        First(*L3) = First(*L1);
        Last1 = First(*L1);
        while (Next(Last1) != Nil)
        {
            Last1 = Next(Last1);
        }
        Next(Last1) = First(*L2);
    }

    First(*L1) = Nil;
    First(*L2) = Nil;
}
