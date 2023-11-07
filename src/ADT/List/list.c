#include <stdio.h>
#include "list.h"


// /* ********** KONSTRUKTOR ********** */
// /* Konstruktor: create list kosong */
// List MakeList(){
//     List L;
//     int i;
//     for (i = 0; i < MaxEl; i++){
//         strcpy(L.A[i].penyanyi, -9999);
//     }
//     return L;
// }
// /* I.S. sembarang */
// /* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

// /* ********** TEST KOSONG/PENUH ********** */
// /* *** Test list kosong *** */
// boolean IsEmptyList(List L){
//     return(L.A[0].penyanyi == -9999);
// }
// /* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

// /* *** Menghasilkan sebuah elemen *** */
// PenyanyiType GetPenyanyi(List L, IdxType i){
//     return (L.A[i]);
// }
// /* Prekondisi : list tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
// /* Mengirimkan elemen list yang ke-i */

// /* *** Selektor SET : Mengubah nilai list dan elemen list *** */
// void Set(List *L, IdxType i, PenyanyiType v){
//     (*L).A[i].penyanyi = v;
// }
// /* I.S. T terdefinisi, sembarang */
// /* F.S. Elemen T yang ke-i bernilai v */

// /* ********** SELEKTOR ********** */
// /* *** Banyaknya elemen *** */
// int LengthList(List L){
//     IdxType i = 0;
//     while ((GetPenyanyi(L, i)).penyanyi != -9999){
//         i++;
//     }
//     return i;
// }
// /* Mengirimkan banyaknya elemen efektif list */
// /* Mengirimkan nol jika list kosong */

// /* *** Selektor INDEKS *** */
// IdxType FirstIdx(List L){
//     return 0;
// }
// /* Prekondisi : list L tidak kosong */
// /* Mengirimkan indeks elemen pertama */

// IdxType LastIdx(List L){
//     return (Length(L)-1);
// }
// /* Prekondisi : list L tidak kosong */
// /* Mengirimkan indeks elemen terakhir */

// /* ********** Test Indeks yang valid ********** */
// boolean IsIdxValid (List L, IdxType i){
//     return (i >= FirstIdx(L) && i <= 99);
// }
// /* Prekondisi : i sembarang */
// /* Mengirimkan true jika i adalah indeks yang valid utk ukuran list */
// /* yaitu antara indeks yang terdefinisi untuk container*/

// boolean IsIdxEff (List L, IdxType i){
//     return (i >= FirstIdx(L) && i < LastIdx(L));
// }
// /* Prekondisi : i sembarang*/
// /* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
// /* yaitu antara FirstIdx(L)..LastIdx(L) */

// /* ********** Operasi-operasi ********** */
// boolean Search(List L, PenyanyiType X){
//     int i = FirstIdx(L);
//     boolean sama = false;
//     while (i <= LastIdx(L)){
//         if (X.penyanyi == (GetPenyanyi(L, i)).penyanyi){
//             sama = true;
//         }
//     }
//     return sama;
// }
// /* Prekondisi : X sembarang */
// /* Mengirimkan true jika terdapat elemen X di dalam list */
// /* yaitu antara FirstIdx(L)..LastIdx(L) */

// void InsertFirst(List *L, PenyanyiType X){
//     if (IsEmpty(*L)){
//         (*L).A[0] = X;
//     }else{
//         IdxType i;
//         for (i = LastIdx(*L); i > FirstIdx(*L); i--){
//             (*L).A[i+1] = GetPenyanyi(*L, i);
//         }
//         (*L).A[0] = X;
//     }
// }
// /* I.S. L terdefinisi, mungkin kosong. */
// /* F.S. v menjadi elemen pertama L. */

// void InsertAt(List *L, PenyanyiType X, IdxType i){
//     if (IsEmpty(*L)){
//         (*L).A[0] = X;
//     }else{
//         IdxType j;
//         for (j = i; j > FirstIdx(*L); j--){
//             (*L).A[j+1].penyanyi = (GetPenyanyi(*L, j)).penyanyi;
//         }
//         (*L).A[0] = X;
//     }
// }
// /* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
// /* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

// void InsertLast(List *L, PenyanyiType X){
//     if (Length(*L) < 100){
//         (*L).A[LastIdx(*L)] = X;
//     }
// }
// /* I.S. L terdefinisi, mungkin kosong. */
// /* F.S. v menjadi elemen terakhir L. */

// void DeleteFirst(List *L){
//     IdxType i;
//     (*L).A[FirstIdx(*L)] = Mark;
//     for (i = FirstIdx(*L)+1; i <= LastIdx(*L); i++){
//         (*L).A[i].penyanyi = (*L).A[i+1];
//     }
// }
// /* I.S. L terdefinisi, tidak kosong. */
// /* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

// void DeleteAt(List *L, IdxType i){
//     IdxType j;
//     (*L).A[FirstIdx(*L)] = Mark;
//     for (j = FirstIdx(*L)+1; j <= i; j++){
//         (*L).A[j].penyanyi = (*L).A[j+1].penyanyi;
//     }
// }
// /* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
// /* F.S. Elemen L pada indeks ke-i dihapus dari L. */

// void DeleteLast(List *L){
//     (*L).A[LastIdx(*L)].penyanyi = Mark;
// }
// /* I.S. L terdefinisi, tidak kosong. */
// /* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

// List Concat(List L1, List L2){
//     List L;
//     IdxType i;
//     for (i = 0; i < MaxEl; i++){
//         L.A[i].penyanyi = -9999;
//     }

//     for (i = 0; i < Length(L1);i++){
//         L.A[i].penyanyi = (GetPenyanyi(L1, i)).penyanyi;
//     }
//     for (i = 0; i < Length(L2);i++){
//         L.A[i].penyanyi = (GetPenyanyi(L2, i)).penyanyi;
//     }
//     return L;
// }
// /* Prekondisi : L1 dan L2 tidak kosong */
// /* Mengirimkan sebuah List yang merupakan gabungan dari L1 dan L2 */
// /* Urutan elemen terisi dari L1, lalu L2 */
// /* Contoh : L1 : [1, 2]; L2 : [3, 4]; Mengembalikan [1, 2, 3, 4] */