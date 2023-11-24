/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../../boolean.h"
#include "../struct.h"
#include "stdio.h"

#define BLANK ' '
#define ENTER '\n'
#define MARKLINUX '\r'

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;

extern boolean EndWordNB;
extern Word currentWordNB;

extern boolean EndLine;
extern Line currentLine;

void IgnoreBlanks();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void IgnoreBlanksInput();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD();
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD();
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
int LengthWord(Word w1);
void CopyWord();
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
// void CopasWord(Word *Dest, Word Src);
void STARTCOMMAND();

void ADVCOMMAND();

void CopyCommand();

void readCommand();

// --------NO BLANK -------------
void IgnoreBlanksInputNB();

void STARTCOMMANDNB();

void ADVCOMMANDNB();

void CopyCommandNB();

void readCommandNB();

// -------- NO BLANK ------------
int stringLength(char *string);

int stringLengthNoBlanks(char *string);

boolean IsSameWord(Word W1, char w2[]);

void printWord(Word word);

boolean IsSameString(char w1[], char w2[]);

boolean IsDuplicateWord(Word w1, Word w2);

int WordLengthNoBlanks(Word kata);

void STARTLINE(char *filename);

void ADVLINE();
void ignoreBlanksLine();

void CopyLine();
void displayLine(Line line); // somehow naming the function printLine will result in an error
void LineToString(Line line, char *string);
void FPRINTWORD(FILE *fptr, Word W);

#endif