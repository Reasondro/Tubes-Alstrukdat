#include "console.h"

Queue QueueOriginal;
Stack StackOriginal;
void song_next(Queue *q, Stack *s)
{
    QueueSongType next_song;
    dequeue(q, &next_song);
    Push(s, next_song);
}

void song_previous(Queue *q, Stack *s){
    QueueSongType ccSong, prevSong, otherSong; 
    Pop(s, &ccSong);
    if (!(IsEmptyStack(*s))){ //Ada Riwayat lagu
        Pop(s, &prevSong);
        Push (s, prevSong); //ccSong langsung masuk stack atau kaga
        Push (s, ccSong);
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

void play_playlist (Queue *q, Stack *s ){
    QueueSongType otherSong;
    for (int i = 0; i < lengthQueue; i++){
        dequeue (q, &otherSong);
    }
    while (!(IsEmptyStack)){
        Pop (s, &otherSong);
    }
    
} //nunggu linked list

void playlist_create(List *L){
    STARTCOMMAND();
    printf("\n");
    if (currentWord.Length>=3) {
        CreateEmpty(L);
        WordToString(currentWord, Nama(*L));
        printf("Playlist %c berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", Nama(*L));
    } else {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    }
}

void playlist_add_song(List *L, QueueSongType song) {
    address P = Alokasi(song.judul_lagu);
    if (Search(*L, song.judul_lagu)==Nil) {
        InsertLast(L, P);
    } else Dealokasi(&P);
}

void playlist_add_album(List *L, AlbumType album) {
    
}

void Save()
{
    FILE *fptr; // inisisasi file
    char SaveFile[100];
    printf("Masukkan nama file: ");
    scanf("%s", SaveFile);
    fptr = fopen(SaveFile, "w");

    int i;

    Queue QueueTemp; // mulai prosedur save queue
    CreateQueue(&QueueTemp);
    CopyQueue(QueueOriginal, &QueueTemp);
    QueueSongType SongQueue;
    int jumlahQueue;

    if (!isEmptyQueue(QueueOriginal))
    {
        jumlahQueue = lengthQueue(QueueTemp);
        fprintf(fptr, "%d\n", jumlahQueue);
        for (i = 0; i < lengthQueue(QueueOriginal); i++)
        {
            dequeue(&QueueTemp, &SongQueue);
            fprintf(fptr, "%s;", SongQueue.penyanyi);
            fprintf(fptr, "%s;", SongQueue.album);
            fprintf(fptr, "%s\n", SongQueue.judul_lagu);
        }
    }

    Stack StackTemp; // mulai prosedur save stack
    CreateEmptyStack(&StackTemp);
    CopyStack(StackOriginal, &StackTemp);
    QueueSongType SongStack;
    int jumlahStack;

    if (!IsEmptyStack(StackOriginal))
    {
        jumlahStack = lengthStack(StackTemp);
        fprintf(fptr, "%d\n", jumlahStack);
        for (i = 0; i < lengthStack(StackOriginal); i++)
        {
            Pop(&StackTemp, &SongStack);
            fprintf(fptr, "%s;", SongStack.penyanyi);
            fprintf(fptr, "%s;", SongStack.album);
            fprintf(fptr, "%s\n", SongStack.judul_lagu);
        }
    }
    fclose(fptr);
}

int main() {
    List L;
    playlist_create(&L);
}