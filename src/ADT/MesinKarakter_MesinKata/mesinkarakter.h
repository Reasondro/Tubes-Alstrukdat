/* File: mesinkarakter.h */
/* Definisi Mesin Karakter */

#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../../boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../struct.h"

#define MARK ';'
#define MARKLOAD '\0'

/* State Mesin */
extern char currentChar;
extern char currentCharNB;

extern char currentCharLoad;
extern boolean EOP;
extern boolean EOL;

void START();
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   Pita baca diambil dari stdin.
   I.S. : sembarang
   F.S. : currentChar adalah karakter pertama pada pita
          Jika currentChar != MARK maka EOP akan padam (false)
          Jika currentChar = MARK maka EOP akan menyala (true) */

void ADV();
/* Pita dimajukan satu karakter.
   I.S. : Karakter pada jendela = currentChar, currentChar != MARK
   F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
          currentChar mungkin = MARK
          Jika  currentChar = MARK maka EOP akan menyala (true) */

void STARTINPUT();

void ADVINPUT();

void STARTINPUTNB();
void ADVINPUTNB();

void STARTLOAD(char *filename);

void ADVLOAD();

boolean IsEOP();

int stringLength(char *string);
void stringCopy(char *string1, char *string2);
void stringConcat(char *string1, char *string2);
boolean IsSameString(char w1[], char w2[]);
boolean IsSameChar(char c1, char c2);

void stringToWord(char *string1, Word *word1);
void wordConcat(Word *dest, Word src);
void CopasWord(Word *Dest, Word Src);
void WordToString(Word word, char *string);

// /* Mengirimkan true jika currentChar = MARK */

#endif