#include <stdio.h>
#include "stack.h"
#include "../struct.h"

int main(){
    Stack S, S2;
    QueueSongTypeRevisi data1, data2, data3, data4;
    QueueSongTypeRevisi ngepop;
    CreateEmptyStack(&S);
    CreateEmptyStack (&S2);
    char lagu[] = "lagu1";
    char album[] = "album1";
    char penyanyi[] = "penyanyi1";

    stringToWord(&lagu, &data1.judul_lagu);
    stringToWord(&album, &data1.album);
    stringToWord(&penyanyi, &data1.penyanyi);

    char lagu2[] = "lagu2";
    char album2[] = "album2";
    char penyanyi2[] = "penyanyi2";

    stringToWord(&lagu2, &data2.judul_lagu);
    stringToWord(&album2, &data2.album);
    stringToWord(&penyanyi2, &data2.penyanyi);

    char lagu3[] = "lagu3";
    char album3[] = "album3";
    char penyanyi3[] = "penyanyi3";

    stringToWord(&lagu3, &data3.judul_lagu);
    stringToWord(&album3, &data3.album);
    stringToWord(&penyanyi3, &data3.penyanyi);

    char lagu4[] = "lagu4";
    char album4[] = "album4";
    char penyanyi4[] = "penyanyi4";

    stringToWord(&lagu4, &data4.judul_lagu);
    stringToWord(&album4, &data4.album);
    stringToWord(&penyanyi4, &data4.penyanyi);

    if (IsEmptyStack(S)){
        printf("\n");
        Push (&S, data1);
        Pop (&S, &ngepop);
        Push (&S, data2);
        Push (&S, data3);
        CopyStack(S, &S2);
        printf("Isi dari S2 (salinan S): \n");
        displayStack(S2);
        printf("\n");
        Pop (&S, &ngepop);
        printf("Isi Top dari S: \n");
        printf ("%s %s %s\n\n", ngepop.judul_lagu, ngepop.album, ngepop.penyanyi);
        printf("Panjang Stack setelah nge pop 1x (harusnya 2): \n");
        printf("%d\n\n", lengthStack(S));
    }else{
        printf("0\n");
    }
    return 0;
}