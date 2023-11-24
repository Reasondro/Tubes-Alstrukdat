#include "mesinkata.h"
#include "mesinkarakter.h"
#include <stdio.h>

/* State Mesin Kata */
boolean EndWord;
Word currentWord;

boolean EndWordNB;
Word currentWordNB;

boolean EndLine;
Line currentLine;

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

int LengthWord(Word w1)
{
    int i = 0;
    int count = 0;
    while (w1.TabWord[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
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
    // printf("Masukkan command: ");
    STARTCOMMAND();
}

Word SentenceToWord(Word w, int wordKe)
{
    int count;

    int i = 0;
    int x = 0;
    int index;
    int j;
    count = wordKe;
    Word hasil;
    hasil.Length = 0;
    if (count == 0)
    {
        for (x = 0; x < w.Length; x++)
        {
            if (w.TabWord[x] == BLANK)
            {
                break;
            }
            hasil.TabWord[x] = w.TabWord[x];
            hasil.Length++;
        }
    }
    else
    {
        for (j = 0; j < w.Length; j++)
        {
            if (count == 0)
            {
                // printf("%c\n", w.TabWord[j]);
                break;
            }
            if (w.TabWord[j] == BLANK)
            {
                count -= 1;
            }
        }
        index = j;

        for (index = j; index < w.Length; index++)
        {

            if (w.TabWord[index] == BLANK)
            {
                break;
            }
            hasil.TabWord[x] = w.TabWord[index];
            x++;
            hasil.Length++;
        }
    }
    return hasil;
}

// ------------------- COMMAND NO BLANKS ---------------------------------------------
void IgnoreBlanksInputNB()

{
    while (currentCharNB == BLANK || currentCharNB == ENTER)
    {
        ADVINPUTNB();
    }
}
void CopyCommandNB()
{
    int i = 0;
    currentWordNB.Length = 0;
    while ((currentCharNB != MARK) && (currentCharNB != BLANK))
    {
        currentWordNB.TabWord[i] = currentCharNB;
        i++;
        ADVINPUTNB();
    }
    currentWordNB.Length = i;
}
void ADVCOMMANDNB()
{
    IgnoreBlanksInputNB();
    if (currentCharNB == MARK)
    {
        EndWordNB = true;
    }
    else
    {
        CopyCommandNB();
    }
}

void STARTCOMMANDNB()
{
    STARTINPUTNB();
    IgnoreBlanksInputNB();
    if (currentCharNB == MARK)
    {
        EndWordNB = true;
    }
    else
    {
        EndWordNB = false;
        CopyCommandNB();
    }
}

void readCommandNB()
{
    STARTCOMMANDNB();
}
// ------------------- COMMAND NO BLANKS ---------------------------------------------

int stringLengthNoBlanks(char *string)
{
    int length = 0;
    int lenBlank = 0;
    while (string[length] != '\0')
    {
        if (string[length] == BLANK)
            lenBlank++;
        length++;
    }
    return length - lenBlank;
}

int WordLengthNoBlanks(Word kata)
{
    int length = kata.Length;
    int lenBlank = 0, i = 0;
    for (i = 0; i < length; i++)
    {
        if (kata.TabWord[i] == BLANK)
            lenBlank++;
    }
    return length - lenBlank;
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

boolean IsDuplicateWord(Word w1, Word w2)
{
    boolean IsSame = true;
    if (w1.Length != w2.Length)
    {
        IsSame = false;
        return IsSame;
    }
    int len = w2.Length;

    for (int i = 0; i < len; i++)
    {
        if (w2.TabWord[i] != w1.TabWord[i])
        {
            IsSame = false;
            return IsSame;
        }
    }
    return IsSame;
}

void printWord(Word word)
{
    int len = word.Length;
    for (int i = 0; i < len; i++)
    {
        printf("%c", word.TabWord[i]);
    }
}

void ignoreBlanksLine()
{
    {
        while (currentCharLoad == BLANK || currentCharLoad == ENTER || currentCharLoad == MARKLINUX) // ini ada marklinux
        {
            ADVLOAD();
        }
    }
}

void CopyLine()
{

    int i = 0;
    currentLine.LengthLine = 0;
    while ((currentCharLoad != MARKLOAD && (currentCharLoad != ENTER) && (currentCharLoad != MARKLINUX))) // ini ada marklinux
    {
        currentLine.TabLine[i] = currentCharLoad;
        i++;
        ADVLOAD();
    }
    currentLine.LengthLine = i;
}
void ADVLINE()
{
    ignoreBlanksLine();
    if (currentCharLoad == MARKLOAD)
    {
        EndLine = true;
        CopyLine();
    }
    else
    {
        CopyLine();
    }
}

void STARTLINE(char *filename)
{
    STARTLOAD(filename);
    // printf("NAMA FILE YANG DITERIMA %s\n", filename);
    ignoreBlanksLine();
    if (currentCharLoad == MARKLOAD)
    {
        EndLine = true;
    }
    else
    {
        EndLine = false;
        CopyLine();
        // CopyLine;
    }
}

void displayLine(Line line) // somehow naming the function printLine will result in an error
{
    for (int i = 0; i < line.LengthLine; i++)
    {
        printf("%c", line.TabLine[i]);
    }

    printf("\n");
}

void LineToString(Line line, char *string)
{
    int i = 0;
    while (i < line.LengthLine)
    {
        string[i] = line.TabLine[i];
        i++;
    }
    string[i] = '\0';
}

void FPRINTWORD(FILE *fptr, Word W)
{
    for (int i = 0; i < W.Length; i++)
    {
        fprintf(fptr, "%c", W.TabWord[i]);
    }
}