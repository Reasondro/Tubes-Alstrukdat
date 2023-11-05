#include <stdio.h>
#include "set.h"

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

boolean IsMember(Set S, SongType *Elmt){
    int i;
    for (i = 0; i < S.Count; i++){
        if ((*Elmt) == S.Elements[i]){
            return true;
        }
    }
    return false;
}

/* Mengembalikan true jika Elmt adalah member dari S */