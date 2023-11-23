#include <stdio.h>
#include "stack.h"
#include "../struct.h"

int main(){
    StackRevisi S, S2;
    QueueSongTypeRevisi data1, data2, data3, data4;
    QueueSongTypeRevisi ngepop;
    CreateEmptyStack(&S);
    CreateEmptyStack (&S2);
    char lagu[] = "lagu1";
    char album[] = "album1";
    char penyanyi[] = "penyanyi1";

    stringToWord(lagu, &data1.judul_lagu);
    stringToWord(album, &data1.album);
    stringToWord(penyanyi, &data1.penyanyi);

    char lagu2[] = "lagu2";
    char album2[] = "album2";
    char penyanyi2[] = "penyanyi2";

    stringToWord(lagu2, &data2.judul_lagu);
    stringToWord(album2, &data2.album);
    stringToWord(penyanyi2, &data2.penyanyi);

    char lagu3[] = "lagu3";
    char album3[] = "album3";
    char penyanyi3[] = "penyanyi3";

    stringToWord(lagu3, &data3.judul_lagu);
    stringToWord(album3, &data3.album);
    stringToWord(penyanyi3, &data3.penyanyi);

    char lagu4[] = "lagu4";
    char album4[] = "album4";
    char penyanyi4[] = "penyanyi4";

    stringToWord(lagu4, &data4.judul_lagu);
    stringToWord(album4, &data4.album);
    stringToWord(penyanyi4, &data4.penyanyi);

    if (IsEmptyStack(S)){
        printf("\n");
        Push (&S, data1);
        Push (&S, data2);
        Push (&S, data3);
        CopyStack(S, &S2);
        displayStack(S2);
        Pop (&S, &ngepop);
        Pop (&S, &ngepop);
        printWord(ngepop.penyanyi);
        printWord(ngepop.album);
        printWord(ngepop.judul_lagu);
    }else{
        printf("0\n");
    }
    return 0;
}