#include <stdio.h>
#include "song.h"

void song_next (Queue *q,Stack *s){
    songtype next_song;
    dequeue (q, &next_song);
    Push (s, next_song);
}

void song_previous(Queue *q, Stack *s){
    songtype ccSong, prevSong; 
    Pop(s, &ccSong);
    if (!(IsEmptyStack(*s))){ //Ada Riwayat lagu
        Pop(s, &prevSong);
        Push (s, prevSong); //ccSong langsung masuk stack atau kaga
    }else{ // stacknya cuma ada ccSong -> playing cclagu dan cclagu taro ke stack
        Push (s, ccSong);
    }
    Push(s, ccSong);

}
