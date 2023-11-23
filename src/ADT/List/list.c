#include "list.h"
#include <stdio.h>
#include "../MesinKarakter_MesinKata/mesinkata.h"
#include "../Setmap-TEMPORER/SETMAP.h"

void CreateEmptyListPenyanyi(ListPenyanyiRevisi *L)
{
    (*L).JumlahPenyanyi = 0;
}

void InsertPenyanyi(ListPenyanyiRevisi *L, PenyanyiTypeRevisi2 P)
{
    L->Penyanyi[L->JumlahPenyanyi] = P;
    CreateEmptyMap(&(L->Penyanyi[L->JumlahPenyanyi].album));
    L->JumlahPenyanyi++;
}

void DisplayListPenyanyi(ListPenyanyiRevisi L)
{
    printf("Daftar Penyanyi: \n");
    for (int i = 0; i < L.JumlahPenyanyi; i++)
    {
        printf("    %d.", i + 1);
        printWord(L.Penyanyi[i].nama);
        printf("\n");
    }
}