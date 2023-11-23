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

void CreateEmptyDaftarPlaylist(DaftarPlaylist *D)
{
    D->Neff = 0;
}

/****************** Manajemen Memori ******************/
addressPlaylist Alokasi(Word penyanyi, Word album, Word judul)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressPlaylist P = (addressPlaylist)malloc(1 * sizeof(SongPlay));
    while (P == Nil)
    {
        addressPlaylist P = (addressPlaylist)malloc(1 * sizeof(SongPlay));
    }
    if (P != Nil)
    {
        CopasWord(&album, Info(P).album);
        CopasWord(&judul, Info(P).judul_lagu);
        CopasWord(&penyanyi, Info(P).penyanyi);
        Next(P) = Nil;
        return P;
    }
}

void Dealokasi(addressPlaylist *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

/****************** PENCARIAN SEBUAH ELEMEN Playlist ******************/
boolean Search(Playlist L, QueueSongTypeRevisi X)
/* Mencari apakah ada elemen Playlist dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    addressPlaylist P;
    boolean bFound = false;
    if (!IsEmptyList(L))
    {
        P = First(L);
        while (!bFound && P != Nil)
        {
            if (IsDuplicateWord(X.judul_lagu, Info(P).judul_lagu) &&
                IsDuplicateWord(X.album, Info(P).album) &&
                IsDuplicateWord(X.penyanyi, Info(P).penyanyi))
            {
                bFound = true;
            }
            else
                P = Next(P);
        }
    }
    return bFound;
}

void InsVLast(Playlist *L, QueueSongTypeRevisi X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen Playlist di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressPlaylist P = Alokasi(X.penyanyi, X.album, X.judul_lagu);
    if (P != Nil)
    {
        InsertLast(L, P);
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst(Playlist *L, QueueSongTypeRevisi *X)
/* I.S. Playlist L tidak kosong  */
/* F.S. Elemen pertama Playlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dtpealokasi */
{
    addressPlaylist P = First(*L);
    *X = Info(P);
    First(*L) = Next(P);
    Dealokasi(&P);
}

void DelVLast(Playlist *L, QueueSongTypeRevisi *X)
/* I.S. Playlist tidak kosong */
/* F.S. Elemen terakhir Playlist dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressPlaylist P = First(*L);
    addressPlaylist Prec = Nil;

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
void InsertFirst(Playlist *L, addressPlaylist P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressPlaylist P sebagai elemen pertama */
{
    Next(P) = First(*L);
    First(*L) = P;
}

void InsertAfter(Playlist *L, addressPlaylist P, addressPlaylist Prec)
/* I.S. Prec pastilah elemen Playlist dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

void InsertLast(Playlist *L, addressPlaylist P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    addressPlaylist Last;
    if (IsEmptyList(*L))
        InsertFirst(L, P);
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
void DelFirst(Playlist *L, addressPlaylist *P)
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen pertama Playlist sebelum penghapusan */
/*      Elemen Playlist berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(First(*L));
    Next(*P) = Nil;
}

void DelP(Playlist *L, QueueSongTypeRevisi X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen Playlist beraddressPlaylist P, dengan Info(P)=X  */
/* Maka P dihapus dari Playlist dan di-dealokasi */
/* Jika tidak ada elemen Playlist dengan Info(P)=X, maka Playlist tetap */
/* Playlist mungkin menjadi kosong karena penghapusan */
{
    addressPlaylist Prec;
    addressPlaylist P = First(*L);
    boolean bFound = false;

    if (!IsEmptyList(*L))
    {
        if (IsDuplicateWord(X.judul_lagu, Info(P).judul_lagu) &&
            IsDuplicateWord(X.album, Info(P).album) &&
            IsDuplicateWord(X.penyanyi, Info(P).penyanyi))
        {
            DelFirst(L, &P);
            Dealokasi(&P);
        }
        else
        {
            Prec = P;
            P = Next(P);
            while (!bFound && P != Nil)
            {
                if (IsDuplicateWord(X.judul_lagu, Info(P).judul_lagu) &&
                    IsDuplicateWord(X.album, Info(P).album) &&
                    IsDuplicateWord(X.penyanyi, Info(P).penyanyi))
                {
                    bFound = true;
                }
                else
                {
                    Prec = P;
                    P = Next(P);
                }
            }

            if (bFound)
            {
                DelAfter(L, &P, Prec);
                Dealokasi(&P);
            }
        }
    }
}

void DelLast(Playlist *L, addressPlaylist *P)
/* I.S. Playlist tidak kosong */
/* F.S. P adalah alamat elemen terakhir Playlist sebelum penghapusan  */
/*      Elemen Playlist berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    addressPlaylist Last = First(*L);
    addressPlaylist PrecLast = Nil;

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

void DelAfter(Playlist *L, addressPlaylist *Pdel, addressPlaylist Prec)
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
    addressPlaylist P;

    if (!IsEmptyList(L))
    {
        P = First(L);
        while (P != Nil)
        {
            printWord(Info(P).penyanyi);
            printf(", ");
            printWord(Info(P).album);
            printf(", ");
            printWord(Info(P).judul_lagu);
            printf("\n");
            P = Next(P);
        }
    }
    printf("\n");
}
int NbElmt(Playlist L)
/* Mengirimkan banyaknya elemen Playlist; mengirimkan 0 jika Playlist kosong */
{
    int cnt = 0;
    addressPlaylist P;

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

addressPlaylist AddressAtIndex(Playlist L, int idx)
{
    addressPlaylist P;
    P = First(L);
    if (IsEmptyList(L))
        return Nil;
    for (int i = 0; i < idx; i++)
    {
        P = Next(P);
    }
    return P;
}

void swap_tengah(Playlist L, int idx1, int idx2)
{
    addressPlaylist lagu1, lagu2, prev1, prev2, next1, next2;
    lagu1 = AddressAtIndex(L, idx1);
    lagu2 = AddressAtIndex(L, idx2);
    prev1 = AddressAtIndex(L, idx1 - 1);
    prev2 = AddressAtIndex(L, idx2 - 1);
    next1 = Next(lagu1);
    next2 = Next(lagu2);
    if (idx2 - idx1 == 1)
    {
        Next(prev1) = lagu2;
        Next(lagu2) = lagu1;
        Next(lagu1) = next2;
    }
    else if (idx1 - idx2 == 1)
    {
        Next(prev2) = lagu1;
        Next(lagu1) = lagu2;
        Next(lagu2) = next1;
    }
    else
    {
        Next(prev1) = lagu2;
        Next(lagu2) = next1;
        Next(prev2) = lagu1;
        Next(lagu1) = next2;
    }
}

void swap_pinggir(Playlist *L, int idx1, int idx2)
{
    if (idx2 - idx1 != 1)
    {
        if (idx1 == 0 && idx2 == NbElmt(*L) - 1)
        {
            addressPlaylist lagu1, lagu2;
            DelFirst(L, &lagu1);
            DelLast(L, &lagu2);
            InsertFirst(L, lagu2);
            InsertLast(L, lagu1);
        }
        else if (idx1 == 0) /* idx2==tengah */
        {
            addressPlaylist lagu1, lagu2, prev2, next1, next2;
            lagu1 = First(*L);
            lagu2 = AddressAtIndex(*L, idx2);
            prev2 = AddressAtIndex(*L, idx2 - 1);
            next2 = Next(lagu2);
            next1 = Next(lagu1);
            Next(prev2) = lagu1;
            Next(lagu1) = next2;
            Next(lagu2) = next1;
            First(*L) = lagu2;
        }
        else if (idx2 == NbElmt(*L) - 1) /* idx1==tengah */
        {
            addressPlaylist lagu1, lagu2, prev1, prev2, next1;
            lagu1 = AddressAtIndex(*L, idx1);
            prev1 = AddressAtIndex(*L, idx1 - 1);
            prev2 = AddressAtIndex(*L, idx2 - 1);
            next1 = Next(lagu1);
            DelLast(L, &lagu2);
            Next(prev2) = lagu1;
            Next(lagu1) = Nil;
            Next(prev1) = lagu2;
            Next(lagu2) = next1;
        }
    }
    else
    {
        if (idx1 == 0) /* idx2==1 */
        {
            addressPlaylist lagu1, lagu2, prev2, next2;
            lagu1 = First(*L);
            lagu2 = Next(lagu1);
            next2 = Next(lagu2);
            First(*L) = lagu2;
            Next(lagu2) = lagu1;
            Next(lagu1) = next2;
        }
        else if (idx2 == NbElmt(*L) - 1) /* idx1==akhir-1 */
        {
            addressPlaylist lagu1, lagu2;
            DelLast(L, &lagu2);
            DelLast(L, &lagu1);
            InsertLast(L, lagu2);
            InsertLast(L, lagu1);
        }
    }
}

// /****************** PROSES TERHADAP Playlist ******************/
// void InversList(Playlist *L)
// /* I.S. sembarang. */
// /* F.S. elemen Playlist dibalik : */
// /* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
// /* Membalik elemen Playlist, tanpa melakukan alokasi/dealokasi. */
// {
//     address P;
//     address Prec = Nil;
//     address Succ;

//     if (!IsEmptyList(*L))
//     {
//         P = First(*L);
//         while (P != Nil)
//         {
//             Succ = Next(P);
//             Next(P) = Prec;
//             Prec = P;
//             P = Succ;
//         }
//         First(*L) = Prec;
//     }
// }

// void Konkat1(Playlist *L1, Playlist *L2, Playlist *L3)
// /* I.S. L1 dan L2 sembarang */
// /* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
// /* Konkatenasi dua buah Playlist : L1 dan L2    */
// /* menghasilkan L3 yang baru (dengan elemen Playlist L1 dan L2) */
// /* dan L1 serta L2 menjadi Playlist kosong.*/
// /* Tidak ada alokasi/dealokasi pada prosedur ini */
// {
//     address Last1;

//     CreateEmpty(L3);
//     if (IsEmptyList(*L1))
//     {
//         First(*L3) = First(*L2);
//     }
//     else
//     {
//         First(*L3) = First(*L1);
//         Last1 = First(*L1);
//         while (Next(Last1) != Nil)
//         {
//             Last1 = Next(Last1);
//         }
//         Next(Last1) = First(*L2);
//     }

//     First(*L1) = Nil;
//     First(*L2) = Nil;
// }