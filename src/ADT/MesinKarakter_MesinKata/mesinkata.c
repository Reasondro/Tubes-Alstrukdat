#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"
#include <stdio.h>

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

void IgnoreBlanksInput()
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */
{
    while (currentChar == BLANK || currentChar == ENTER)
    {
        ADVINPUT();
    }
}

void STARTWORD()
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */
{
    START();
    // IgnoreBlanks();
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

void CopyCommand()
{
    int i = 0;
    currentWord.Length = 0;
    while ((currentChar != MARK))
    {
        currentWord.TabWord[i] = currentChar;
        i++;
        ADVINPUT();
    }
    currentWord.Length = i;
}
void ADVCOMMAND()
{
    IgnoreBlanksInput();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        CopyCommand();
    }
}

void STARTCOMMAND()
{
    STARTINPUT();
    IgnoreBlanksInput();
    if (currentChar == MARK)
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyCommand();
    }
}

void readCommand()
{
    printf("Masukkan command: ");
    STARTCOMMAND();
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

int stringLengthNoBlanks(char *string)
{
    int length = 0;
    int lenBlank = 0;
    while (string[length] != '\0')
    {
        if (string[length] == BLANK) lenBlank++;
        length++;
    }
    return length-lenBlank;
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

void printWord(Word word)
{
    for (int i = 0; i < word.Length; i++)
    {
        printf("%c", word.TabWord[i]);
    }

    printf("\n");
}

void stringCopy(char *string1, char *string2)
{
    int i = 0;
    while (string2[i] != '\0')
    {
        string1[i] = string2[i];
        i++;
    }
    string1[i] = '\0';
}

void WordToString(Word word, char *string)
{
    int i = 0;
    while (i < word.Length)
    {
        string[i] = word.TabWord[i];
        i++;
    }
    string[i] = '\0';
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