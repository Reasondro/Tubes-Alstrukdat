#include <stdio.h>
#include <string.h>
#include "mesinkarakter.h"

char currentChar;
char currentCharLoad;

boolean EOP;
boolean EOL;

static FILE *pita;
static int retval;

static FILE *pitaLoad;
static int retvalLoad;

void START()
{
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
       Karakter pertama yang ada pada pita posisinya adalah pada jendela.
       Pita baca diambil dari stdin.
       I.S. : sembarang
       F.S. : currentChar adalah karakter pertama pada pita
              Jika currentChar != MARK maka EOP akan padam (false)
              Jika currentChar = MARK maka EOP akan menyala (true) */
    pita = stdin;
    ADV();
}

void ADV()
{
    /* Pita dimajukan satu karakter.
       I.S. : Karakter pada jendela = currentChar, currentChar != MARK
       F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
              currentChar mungkin = MARK
              Jika  currentChar = MARK maka EOP akan menyala (true) */

    currentChar = getc(pita);
    EOP = (currentChar == MARK);
    if (EOP)
    {
        fclose(pita);
    }
}

void STARTINPUT()
{
    pita = stdin;
    ADVINPUT();
}

void ADVINPUT()
{
    retval = fscanf(pita, "%c", &currentChar);
}

boolean IsEOP()
{
    /* Mengirimkan true jika currentChar = MARK */
    return (currentChar == MARK);
}

void STARTLOAD()
{
    // pita = stdin;
    pitaLoad = fopen("save.txt", "r");
    ADVLOAD();
}

void ADVLOAD()
{
    retvalLoad = fscanf(pitaLoad, "%c", &currentCharLoad);
    EOL = (currentCharLoad == MARKLOAD);
    // if (EOL)
    // {
    //     fclose(pitaLoad);
    // }
}