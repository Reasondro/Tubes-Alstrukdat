#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
/* State Mesin Kata */
boolean EndWord;
Word currentWord;

void IgnoreBlanks()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK || currentChar == ENTER)
    {
        ADV();
    }
}

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD()
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */
{
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
        IgnoreBlanks();
    }
}

void CopyWord()
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
{
    int i = 1;
    currentWord.Length = 0;
    while ((currentChar != BLANK) && (currentChar != ENTER))
    {
        IgnoreBlanks();
        currentWord.TabWord[i] = currentChar;
        i++;
        ADV();
    }
    currentWord.Length = i - 1;
}

void printWord(Word word)
{
    for (int i = 1; i <= word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
    }
    printf("\n");
}

void STARTCOMMAND()
{
    STARTINPUT();
    IgnoreBlanks();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord();
    }
}

void readCommand()
{
    printf("Masukkan command: ");
    STARTCOMMAND();
}

boolean IsSameWord(Word w1, char *w2)
{
    boolean IsSame = true;
    for (int i = 0; i < w1.Length; i++)
    {
        if (w2[i] != w1.TabWord[i + 1])
            IsSame = false;
    }
    return IsSame;
}