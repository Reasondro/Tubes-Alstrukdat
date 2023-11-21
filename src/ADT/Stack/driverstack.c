#include <stdio.h>
#include "stack.h"
#include "../struct.h"

int main(){
    Stack S, S2;
    QueueSongType ngepush, ngepush2, ngepush3;
    QueueSongType ngepop;
    CreateEmptyStack(&S);
    CreateEmptyStack (&S2);
    char lagu[] = "lagu1";
    char album[] = "album1";
    char penyanyi[] = "penyanyi1";
    stringCopy (ngepush.judul_lagu.judul, lagu);
    stringCopy (ngepush.album, album);
    stringCopy (ngepush.penyanyi, penyanyi);

    char lagu2[] = "lagu2";
    char album2[] = "album2";
    char penyanyi2[] = "penyanyi2";
    stringCopy (ngepush2.judul_lagu.judul, lagu2);
    stringCopy (ngepush2.album, album2);
    stringCopy (ngepush2.penyanyi, penyanyi2);

    char lagu3[] = "lagu3";
    char album3[] = "album3";
    char penyanyi3[] = "penyanyi3";
    stringCopy (ngepush3.judul_lagu.judul, lagu3);
    stringCopy (ngepush3.album, album3);
    stringCopy (ngepush3.penyanyi, penyanyi3);

    if (IsEmptyStack(S)){
        printf("\n");
        Push (&S, ngepush);
        Pop (&S, &ngepop);
        Push (&S, ngepush2);
        Push (&S, ngepush3);
        CopyStack(S, &S2);
        printf("Isi dari S2 (salinan S): \n");
        displayStack(S2);
        printf("\n");
        Pop (&S, &ngepop);
        printf("Isi Top dari S: \n");
        printf ("%s %s %s\n\n", ngepop.judul_lagu.judul, ngepop.album, ngepop.penyanyi);
        printf("Panjang Stack setelah nge pop 1x (harusnya 2): \n");
        printf("%d\n\n", lengthStack(S));
    }else{
        printf("0\n");
    }
    return 0;
}