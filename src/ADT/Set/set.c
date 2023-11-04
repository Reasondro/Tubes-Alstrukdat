#include <stdio.h>
#include "set.h"

void CreateEmpty(Set *S){
    (*S).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Set S kosong berkapasitas MaxEl */
/* Ciri Set kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmpty(Set S){
    return (S.Count == Nil);
}
/* Mengirim true jika Set S kosong*/
/* Ciri Set kosong : count bernilai Nil */

boolean IsFull(Set S){
    return (S.Count == MaxEl);
}
/* Mengirim true jika Set S penuh */
/* Ciri Set penuh : count bernilai MaxEl */

/* ********** Operator Dasar Set ********* */
void Insert(Set *S, SongType Elmt){
    if (IsEmpty(*S)){
        (*S).Elements[0] = Elmt;
        (*S).Count = 1;
    }else{
        if (!(IsMember(*S, Elmt))){
            (*S).Elements[(*S).Count] = Elmt;
            (*S).Count++;
        }
    }

}
/* Menambahkan Elmt sebagai elemen Set S. */
/* I.S. S mungkin kosong, S tidak penuh
        S mungkin sudah beranggotakan Elmt */
/* F.S. Elmt menjadi anggota dari S. Jika Elmt sudah merupakan anggota, operasi tidak dilakukan */

void Delete(Set *S, SongType Elmt){
    int i = 0, j;
    boolean found = false; 
    while ( !(found) && i < (*S).Count){
        if ((*S).Elements[i] != Elmt){
            found = true;
        }else{
            i++;
        }
    }
    if (found){
        for (j = (*S).Count-1; j > i; j--){
            (*S).Elements[j] = (*S).Elements[j+1];
        }
        (*S).Count--;
    }
}

/* Menghapus Elmt dari Set S. */
/* I.S. S tidak kosong
        Elmt mungkin anggota / bukan anggota dari S */
/* F.S. Elmt bukan anggota dari S */

boolean IsMember(Set S, SongType Elmt){
    int i;
    for (i = 0; i < S.Count; i++){
        if (Elmt == S.Elements[i]){
            return true;
        }
    }
    return false;
}

/* Mengembalikan true jika Elmt adalah member dari S */