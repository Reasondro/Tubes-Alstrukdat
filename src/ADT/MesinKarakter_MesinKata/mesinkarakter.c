#include "mesinkarakter.h"

char currentChar;
char currentCharLoad;

boolean EOP;
boolean EOL;

static FILE *pita;
static int retval;

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
    int i = 0;
    while (string2[i] != '\0')
    {
        string1[i] = string2[i];
        i++;
    }
    string1[i] = '\0';
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

// void STARTLOAD(char *filename)
// {
//     // pita = stdin;
//     char *dir = "saves/";
//     char file[20] = "save.txt";
//     stringCopy(file, dir);
//     pitaLoad = fopen(dir, "r");
//     ADVLOAD();
// }

void STARTLOAD(char *filename)
{
    // pita = stdin;
    char *dir = "saves/";
    char filepath[30];
    stringCopy(filepath, dir);
    stringConcat(filepath, filename);
    pitaLoad = fopen(filepath, "r");
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