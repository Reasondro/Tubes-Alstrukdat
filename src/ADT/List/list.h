// list.h

#ifndef LIST_H
#define LIST_H

#include "../struct.h"

/* Kamus Umum */
#define MaxEl 100
#define Mark -9999	  /* Nilai tak terdefinisi */
#define InvalidIdx -1 /* Indeks tak terdefinisi */

void CreateEmptyListPenyanyi(ListPenyanyiRevisi *L);

void InsertPenyanyi(ListPenyanyiRevisi *L, PenyanyiTypeRevisi2 P);

void DisplayListPenyanyi(ListPenyanyiRevisi L);

#endif
