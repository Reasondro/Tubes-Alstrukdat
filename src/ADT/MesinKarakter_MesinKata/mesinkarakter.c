#include "mesinkarakter.h"

char currentChar;
char currentCharNB;

char currentCharLoad;

boolean EOP;
boolean EOL;

static FILE *pita;
static int retval;

static FILE *pitaNB;
static int retvalNB;

static FILE *pitaLoad;
static int retvalLoad;

int stringLength(char *string)
{
    int length = 0;
    while (string[length] != '\0')
    {
        length++;
    }
    return length;
}
void stringCopy(char *string1, char *string2)
{
    int panjang1 = stringLength(string1);
    int i = 0;
    while (string2[i] != '\0')
    {
        string1[i] = string2[i];
        i++;
    }
    int j;
    for (j = i; j < panjang1; j++)
    {
        string1[j] = '\0';
    }
}

void stringConcat(char *string1, char *string2)
{
    int i = 0;
    int j = 0;
    while (string1[i] != '\0')
    {
        i++;
    }
    while (string2[j] != '\0')
    {
        string1[i] = string2[j];
        i++;
        j++;
    }
    string1[i] = '\0';
}

boolean IsSameChar(char c1, char c2)
{
    boolean IsSame = true;

    if (c1 != c2)
    {
        IsSame = false;
        return IsSame;
    }

    return IsSame;
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

void START()
{

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

void STARTINPUTNB()
{
    pitaNB = stdin;
    ADVINPUTNB();
}

void ADVINPUTNB()
{
    retvalNB = fscanf(pitaNB, "%c", &currentCharNB);
}

boolean IsEOP()
{
    /* Mengirimkan true jika currentChar = MARK */
    return (currentChar == MARK);
}

void stringToWord(char *string1, Word *word1)
{
    int i = 0;
    word1->Length = 0;
    while (string1[i] != '\0')
    {
        word1->TabWord[i] = string1[i];
        i++;
        word1->Length++;
    }
}

void wordConcat(Word *dest, Word src)
{
    int lengthSrc = src.Length;
    int lengthDest = dest->Length;

    for (int i = 0; i < lengthSrc; i++)
    {
        dest->TabWord[lengthDest + i] = src.TabWord[i];
        dest->Length++;
    }
}

void CopasWord(Word *Dest, Word Src)
{
    // int len = LengthWord(Src);
    int len = Src.Length;
    int i;
    Dest->Length = 0;
    for (i = 0; i < len; i++)
    {
        Dest->TabWord[i] = Src.TabWord[i];
        Dest->Length++;
    }
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
void STARTLOAD(char *filename)
{
    // pita = stdin;
    char dir[50] = "../save/";
    char filepath[50];
    Word dirW;
    Word filepathW;
    Word filenameW;

    stringToWord(dir, &(dirW));
    CopasWord(&filepathW, dirW);

    stringToWord(filename, &(filenameW));
    wordConcat(&(filepathW), filenameW);
    WordToString(filepathW, filepath);
    // * buat nge test
    // printf("NAMA FILE YANG DITERIMA %s\n", filepath);
    // printf("NAMA FILE YANG DITERIMA %s\n", filename);
    // printf("NAMA FILE YANG DITERIMA %s\n", dir);

    // stringCopy(filepath, dir);
    // printf("NAMA FILE YANG DITERIMA %s\n", filepath);
    // stringConcat(filepath, filename);

    pitaLoad = fopen(filepath, "r");
    if (pitaLoad == NULL)
    {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }
    else
    {
        printf("Save file %s berhasil dibaca. WayangWave berhasil dijalankan.\n", filename);
    }
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