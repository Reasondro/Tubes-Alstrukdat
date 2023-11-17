#include "console.h"

Queue QueueOriginal;
Stack StackOriginal;

void song_next (Queue *q, Stack *s){
    QueueSongType next_song;
    dequeue (q, &next_song);
    Push (s, next_song);
    printf ("Memutar lagu selanjutnya\n");
    printf ("\"%s oleh \"%s\"", next_song.judul_lagu, next_song.penyanyi);
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
    printf ("Memutar lagu selanjutnya\n");
    printf ("\"%s\" oleh \"%s\"", prevSong.judul_lagu, prevSong.penyanyi);
}

void play_song(Queue *q, Stack *s){
    char *chosen_penyanyi;
    char *chosen_album;
    int id_chosen_lagu;
    printf("Daftar Penyanyi :\n");
    // for (int i = 0; i < length_penyanyi; i++){
    //     printf("%s. %s\n", i+1, Penyanyi[i])
    // }
    printf ("Masukkan Nama Penaynyi yang dipilih : ");
    scanf ("%s\n", &chosen_penyanyi);
    if (SearchList()){
        printf ("Daftar Album oleh %s :\n", chosen_penyanyi);
        // for (int i = 0; i < length_album; i++){
        //     printf("%s. %s\n", i+1, Penyanyi[i])
        // }
        printf ("Masukkan Nama Album yang dipilih : ");
        scanf ("%s\n", &chosen_album);
        if (IsMemberMap()){
            printf ("Daftar Lagu Album %s oleh %s : \n", chosen_penyanyi, chosen_album);
            // for (int i = 0; i < length_lagu; i++){
            //     printf("%s. %s\n", i+1, judul_lagu[i])
            // }
            printf ("Masukkan ID Lagu yang dipilih : ");
            scanf ("%d\n", &id_chosen_lagu);
            if (id_chosen_lagu < set.count){
                char chosen_lagu = lagu[id_chosen_lagu - 1];
                QueueSongType added_song, otherSong;
                for (int i = 0; i < lengthQueue; i++){
                    dequeue (q, &otherSong);
                }
                while (!(IsEmptyStack)){
                    Pop (s, &otherSong);
                }
                added_song.penyanyi[0] = chosen_penyanyi[0];
                added_song.album[0] = chosen_album[0];
                added_song.judul_lagu[0] = chosen_lagu[0];
                Push (s, added_song);
                printf("Memutar lagu \"%s\" oleh \"%s\"", chosen_lagu, chosen_penyanyi);
            }
        }
    }
}

void play_playlist (Queue *q, Stack *s){
    playlist id_PlayList;
    scanf("Mauskkan Id Playlist: %d\n", &id_PlayList);
    if (id_PlayList < NbEmlt(playlist)){
        QueueSongType otherSong;
        for (int i = 0; i < lengthQueue; i++){
            dequeue (q, &otherSong);
        }
        while (!(IsEmptyStack)){
            Pop (s, &otherSong);
        }
        for (int i = 0; i < length_playlist; i++){
            Push()
        }
    }   
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
    songtype SongQueue;
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
    songtype SongStack;
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
