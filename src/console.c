#include "console.h"

void song_next (Queue *q, Stack *s){
    QueueSongType next_song;
    dequeue (q, &next_song);
    Push (s, next_song);
}

void song_previous(Queue *q, Stack *s){
    QueueSongType ccSong, prevSong, otherSong; 
    Pop(s, &ccSong);
    if (!(IsEmptyStack(*s))){ //Ada Riwayat lagu
        Pop(s, &prevSong);
        Push (s, prevSong); //ccSong langsung masuk stack atau kaga
        push (s, ccSong);
    }else{ // stacknya cuma ada ccSong -> playing cclagu dan cclagu taro ke stack
        Push (s, ccSong);
    }
    Push(s, ccSong);
    enqueue (q, ccSong);
    for (int i = 0; i < lengthQueue (*q); i++){
        dequeue (q, &otherSong);
        enqueue (q, otherSong);
    }
}

void play_song(Queue *q, Stack *s, QueueSongType song){
    QueueSongType otherSong;
    for (int i = 0; i < lengthQueue; i++){
        dequeue (q, &otherSong);
    }
    while (!(IsEmptyStack)){
        Pop (s, &otherSong);
    }
    Push (s, song);
}

void play_playlist (Queue *q, Stack *s, ){
    QueueSongType otherSong;
    for (int i = 0; i < lengthQueue; i++){
        dequeue (q, &otherSong);
    }
    while (!(IsEmptyStack)){
        Pop (s, &otherSong);
    }
    
} //nunggu linked list
