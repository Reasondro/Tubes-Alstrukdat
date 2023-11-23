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
addressPlaylist Alokasi(Word penyanyi, Word album, Word judul)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    addressPlaylist P = (addressPlaylist)malloc(1 * sizeof(SongPlay));
    while (P == Nil) {
        addressPlaylist P = (addressPlaylist)malloc(1 * sizeof(SongPlay));
    } if (P != Nil){
        CopasWord(&Info(P).album, album);
        CopasWord(&Info(P).judul_lagu, judul);
        CopasWord(&Info(P).penyanyi, penyanyi);
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
    if (!IsEmptyList(L)){
        P = First(L);
        while (!bFound && P != Nil){
            if (IsDuplicateWord(X.judul_lagu, Info(P).judul_lagu)&&
                IsDuplicateWord(X.album, Info(P).album)&&
                IsDuplicateWord(X.penyanyi, Info(P).penyanyi)) {
                bFound = true;
            }
            else P = Next(P);
        }
    } return bFound;
}

void InsVLast(Playlist *L, QueueSongTypeRevisi X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen Playlist di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressPlaylist P = Alokasi(X.penyanyi,X.album,X.judul_lagu);
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
    if (IsEmptyList(*L)) InsertFirst(L, P);
    else
    {
        Last = First(*L);
        while (Next(Last) != Nil)
        {
            Last = Next(Last);
        }
        printf("sampe\n");
        InsertAfter(L, P, Last);
        printf("sampe1\n");
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
        if (IsDuplicateWord(X.judul_lagu, Info(P).judul_lagu)&&
            IsDuplicateWord(X.album, Info(P).album)&&
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
                if (IsDuplicateWord(X.judul_lagu, Info(P).judul_lagu)&&
                    IsDuplicateWord(X.album, Info(P).album)&&
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
    addressPlaylist P = First(L);
    int i = 1;
    while (P != Nil)
    {
        printf("%d", i);
        printWord(Info(P).penyanyi);
        printf(", ");
        printWord(Info(P).album);
        printf(", ");
        printWord(Info(P).judul_lagu);
        printf("\n");
        P = Next(P);
        i++;
    } 
    printf("batas\n");
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
    if (IsEmptyList(L)) return Nil;
    for (int i=0; i<idx; i++){
        P = Next(P);
    }
    return P;
}

void swap_tengah(Playlist L, int idx1, int idx2) 
{
    addressPlaylist lagu1, lagu2, prev1, prev2, next1, next2;
    lagu1 = AddressAtIndex(L, idx1);
    lagu2 = AddressAtIndex(L, idx2);
    prev1 = AddressAtIndex(L, idx1-1);
    prev2 = AddressAtIndex(L, idx2-1);
    next1 = Next(lagu1); next2 = Next(lagu2);
    if (idx2-idx1 == 1) 
    {
        Next(prev1) = lagu2;
        Next(lagu2) = lagu1;
        Next(lagu1) = next2;
    }
    else if (idx1-idx2 == 1) 
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
    if (idx2-idx1 != 1)
    {
        if (idx1==0 && idx2==NbElmt(*L)-1)
        {
            addressPlaylist lagu1, lagu2;
            DelFirst(L, &lagu1);
            DelLast(L, &lagu2);
            InsertFirst(L, lagu2);
            InsertLast(L, lagu1);
        }
        else if (idx1==0) /* idx2==tengah */
        {
            addressPlaylist lagu1, lagu2, prev2, next1, next2;
            lagu1 = First(*L);
            lagu2 = AddressAtIndex(*L, idx2);
            prev2 = AddressAtIndex(*L, idx2-1);
            next2 = Next(lagu2); next1 = Next(lagu1);
            Next(prev2) = lagu1;
            Next(lagu1) = next2;
            Next(lagu2) = next1;
            (*L).First = lagu2;
        }
        else if (idx2==NbElmt(*L)-1) /* idx1==tengah */
        {
            addressPlaylist lagu1, lagu2, prev1, prev2, next1;
            lagu1 = AddressAtIndex(*L, idx1);
            prev1 = AddressAtIndex(*L, idx1-1);
            prev2 = AddressAtIndex(*L, idx2-1);
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
        if (idx1==0) /* idx2==1 */
        {
            addressPlaylist lagu1, lagu2, prev2, next2;
            lagu1 = First(*L);
            lagu2 = Next(lagu1);
            next2 = Next(lagu2);
            (*L).First = lagu2;
            Next(lagu2) = lagu1;
            Next(lagu1) = next2;
        }
        else if (idx2==NbElmt(*L)-1) /* idx1==akhir-1 */
        {
            addressPlaylist lagu1, lagu2;
            DelLast(L, &lagu2);
            DelLast(L, &lagu1);
            InsertLast(L, lagu2);
            InsertLast(L, lagu1);
        }
    }
    // printf("sampe2");
    // PrintInfo(L);
}

boolean IsSameWord(Word w1, char w2[])
{
    boolean IsSame = true;
    if (w1.Length != stringLength(w2))
    {
        IsSame = false;
        return IsSame;
    }
    for (int i = 0; i < stringLength(w2); i++)
    {
        if (w2[i] != w1.TabWord[i])
        {
            IsSame = false;
            return IsSame;
        }
    }
    return IsSame;
}

void stringCopy(char *string1, char *string2)
{
    int panjang1 = stringLength(string1);
    int i = 0;
    while (string2[i] != '\0')
    {
        string1[i] = string2[i];
        i++;
    }
    int j;
    for (j = i; j < panjang1; j++)
    {
        string1[j] = '\0';
    }
}

boolean IsSameString(char w1[], char w2[])
{
    boolean IsSame = true;
    if (stringLength(w1) != stringLength(w2))
    {
        IsSame = false;
        return IsSame;
    }
    for (int i = 0; i < stringLength(w2); i++)
    {
        if (w2[i] != w1[i])
        {
            IsSame = false;
            return IsSame;
        }
    }
    return IsSame;
}

int stringLength(char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}

void swaptest(Playlist *L, int idxl1, int idxl2)
{
    if (!(idxl1 <= NbElmt(*L) && idxl1 > 0))
        {
            // printf("Tidak ada lagu dengan urutan %d di playlist ""%s""", idxl1, DP.pl[idxplay].nama);
            printf("Tidak ada lagu dengan urutan %d di playlist \"", idxl1);
            printWord((*L).nama);
            printf("\",\n");
            return;
        }
        else
        {
            idxl1--;
            if (!(idxl2 <= NbElmt(*L) && idxl2 > 0))
            {
                // printf("Tidak ada lagu dengan urutan %d di playlist ""%s""", idxl2, DP.pl[idxplay].nama);
                printf("Tidak ada lagu dengan urutan %d di playlist \"", idxl2);
                printWord((*L).nama);
                printf("\",\n");
                return;
            }
            else
            {
                idxl2--;
                if (idxl1 == 0 || idxl1 == NbElmt((*L)) - 1 || idxl2 == 0 || idxl2 == NbElmt((*L)) - 1)
                {
                    if (idxl1 < idxl2)
                    {
                        swap_pinggir(L, idxl1, idxl2);
                        addressPlaylist lagu1 = AddressAtIndex((*L), idxl1);
                        addressPlaylist lagu2 = AddressAtIndex((*L), idxl2);
                        // printf("Berhasil menukar lagu dengan nama ""%s"" dengan ""%s"" di playlist ""%s""", lagu1->info.judul_lagu.judul, lagu2->info.judul_lagu.judul, DP.pl[idxplay].nama);
                        printf("Berhasil menukar lagu dengan nama \"");
                        printWord(lagu1->info.judul_lagu);
                        printf("\" dengan \"");
                        printWord(lagu2->info.judul_lagu);
                        printf("\" di playlist \"");
                        printWord((*L).nama);
                        printf("\".\n");
                    }
                    else
                    {
                        swap_pinggir(L, idxl2, idxl1);
                        addressPlaylist lagu1 = AddressAtIndex(*L, idxl1);
                        addressPlaylist lagu2 = AddressAtIndex(*L, idxl2);
                        // printf("Berhasil menukar lagu dengan nama ""%s"" dengan ""%s"" di playlist ""%s""", lagu1->info.judul_lagu.judul, lagu2->info.judul_lagu.judul, DP.pl[idxplay].nama);
                        printf("Berhasil menukar lagu dengan nama \"");
                        printWord(lagu1->info.judul_lagu);
                        printf("\" dengan \"");
                        printWord(lagu2->info.judul_lagu);
                        printf("\" di playlist \"");
                        printWord((*L).nama);
                        printf("\".\n");
                    }
                }
                else
                {
                    swap_tengah((*L), idxl1, idxl2);
                    addressPlaylist lagu1 = AddressAtIndex((*L), idxl1);
                    addressPlaylist lagu2 = AddressAtIndex((*L), idxl2);
                    // printf("Berhasil menukar lagu dengan nama ""%s"" dengan ""%s"" di playlist ""%s""", lagu1->info.judul_lagu.judul, lagu2->info.judul_lagu.judul, DP.pl[idxplay].nama);
                    printf("Berhasil menukar lagu dengan nama \"");
                    printWord(lagu1->info.judul_lagu);
                    printf("\" dengan \"");
                    printWord(lagu2->info.judul_lagu);
                    printf("\" di playlist \"");
                    printWord((*L).nama);
                    printf("\".\n");
                }
            }
        }
}

void playlist_removesong(Playlist *L, int idxl)
{
    if (!(idxl <= NbElmt(*L) && idxl > 0))
    {
        printf("Tidak ada lagu dengan urutan %d di playlist \"", idxl);
        printWord((*L).nama);
        printf("\".\n");
        return;
    }
    else
    {
        idxl--;
        addressPlaylist lagu = AddressAtIndex(*L, idxl);
        addressPlaylist X;
        X = Alokasi(lagu->info.penyanyi,lagu->info.album,lagu->info.judul_lagu);
        DelP(L, Info(X));
        // printf("%s,%s,%s\n",X->info.penyanyi,X->info.album,X->info.judul_lagu.judul);
        printf("Lagu \"");
        printWord(X->info.judul_lagu);
        printf("\" oleh \"");
        printWord(X->info.penyanyi);
        printf("\" telah dihapus dari playlist \"");
        printWord((*L).nama);
        printf("\"!\n");
    }
}

void stringToWord(char *string1, Word *word1)
{
    int i = 0;
    word1->Length = 0;
    while (string1[i] != '\0')
    {
        word1->TabWord[i] = string1[i];
        i++;
        word1->Length++;
    }
    word1->TabWord[word1->Length] = '\0';
}

void printWord(Word word)
{
    int len = word.Length;
    for (int i = 0; i < len; i++)
    {
        printf("%c", word.TabWord[i]);
    }
    word.TabWord[word.Length] = '\0';
}

boolean IsDuplicateWord(Word w1, Word w2)
{
    boolean IsSame = true;
    if (w1.Length != w2.Length)
    {
        IsSame = false;
        return IsSame;
    }
    int len = w2.Length;

    for (int i = 0; i < len; i++)
    {
        if (w2.TabWord[i] != w1.TabWord[i])
        {
            IsSame = false;
            return IsSame;
        }
    }
    return IsSame;
}

void CopasWord(Word *Dest, Word Src)
{
    // int len = LengthWord(Src);
    int len = Src.Length;
    int i;
    Dest->Length = 0;
    for (i = 0; i < len; i++)
    {
        Dest->TabWord[i] = Src.TabWord[i];
        Dest->Length++;
    }
    Dest->TabWord[Dest->Length] = '\0';
}

int main(){
    Playlist L;
    CreateEmpty(&L);
    addressPlaylist a,s,d,f,g,h,k,l;
    Word w1,w2,w3,w4,w5,w6,w7,w8,w9,w10,w11,w12;
    stringToWord("1Billy",&w1);
    stringToWord("album1",&w2);
    stringToWord("lagu1",&w3);
    stringToWord("2Bully",&w4);
    stringToWord("album2",&w5);
    stringToWord("lagu2",&w6);
    stringToWord("3Udin",&w7);
    stringToWord("album3",&w8);
    stringToWord("lagu3",&w9);
    stringToWord("4ucok",&w10);
    stringToWord("album4",&w11);
    stringToWord("lagu4",&w12);
    a=Alokasi(w1,w2,w3);
    s=Alokasi(w4,w5,w6);
    d=Alokasi(w7,w8,w9);
    f=Alokasi(w10,w11,w12);
    printWord(a->info.penyanyi);
    printWord(a->info.album);
    printf("\n");
    printWord(s->info.penyanyi);
    printf("\n");
    printWord(d->info.penyanyi);
    printf("\n");
    printWord(f->info.penyanyi);
    printf("\n");
    printf("sampe1.5\n");
    InsertLast(&L, a);
    InsertLast(&L, s);
    InsertLast(&L, d);
    InsertLast(&L, f);
    printf("sampe2\n");
    PrintInfo(L);
    printf("di sini mulai remove\n");
    int i,j;
    scanf("%d", &i);
    playlist_removesong(&L,i);
    printf("\n");
    PrintInfo(L);
}