#include "console.h"

Queue QueueOriginal;
Stack StackOriginal;

void Song_Next (Queue *q, Stack *s){
    QueueSongType next_song;
    dequeue(q, &next_song);
    Push(s, next_song);
}

void Song_Previous(Queue *q, Stack *s){
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

void Play_Song(Queue *q, Stack *s, Playlist *pl){
    char *chosen_penyanyi;
    char *chosen_album;
    char *id_chosen_lagu_string;
    int id_chosen_lagu;
    printf("Daftar Penyanyi :\n");
    // for (int i = 0; i < length_penyanyi; i++){
    //     printf("%d. %s\n", i+1, Penyanyi[i])
    // }
    printf ("Masukkan Nama Penyanyi yang dipilih : ");
    readCommand();
    if (SearchList()){
        WordToString(currentWord, chosen_penyanyi);
        printf ("Daftar Album oleh %s :\n", chosen_penyanyi);
        // for (int i = 0; i < length_album; i++){
        //     printf("%d. %s\n", i+1, Penyanyi[i])
        // }
        printf ("Masukkan Nama Album yang dipilih : ");
        readCommand();
        if (IsMemberMap()){
            WordToString(currentWord, chosen_album);
            printf ("Daftar Lagu Album %s oleh %s : \n", chosen_penyanyi, chosen_album);
            // for (int i = 0; i < length_lagu; i++){
            //     printf("%d. %s\n", i+1, judul_lagu[i])
            // }
            printf ("Masukkan ID Lagu yang dipilih : ");
            readCommand();
            WordToString (currentWord, id_chosen_lagu_string);
            id_chosen_lagu = id_chosen_lagu_string - '0';
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

Play_Playlist (Queue *q, Stack *s, ){
    char id_Playlist_string;
    DaftarPlaylist dafplaylist;
    printf("Masukkan Id Playlist: ");
    readCommand();
    WordToString(currentWord,&id_Playlist_string);
    dafplaylist.id = id_Playlist_string - '0';
    if (dafplaylist.id < NbEmlt(dafplaylist.playlist)){
        QueueSongType otherSong;
        for (int i = 0; i < lengthQueue; i++){
            dequeue (q, &otherSong);
        }
        while (!(IsEmptyStack)){
            Pop (s, &otherSong);
        }
        for (int i = 0; i < length_playlist; i++){
            Push(s, queue_song_dari_playlist);
        }
    } 
}

void playlist_create(Playlist *L){
    CreateEmpty(&L);
    STARTCOMMAND();
    printf("\n");
    if (stringLengthNoBlanks(&currentWord)>=3) {
        WordtoString(currentWord, Nama(*L));
        printf("Playlist %c berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", Nama(*L));
    } else {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    }
}

void playlist_add_song(Playlist *L, QueueSongType song) {
    address P = Alokasi(song.judul_lagu);
    if (Search(*L, song.judul_lagu)==Nil) {
        InsertLast(L, P);
    } else Dealokasi(&P);
}

void playlist_add_album(Playlist *L, IsiAlbum album) {
    for (int i=0; i<album.DaftarLagu.JumlahLagu; i++) {
        address P = Alokasi(album.DaftarLagu.Songs[i]);
        if (Search(*L, album.DaftarLagu.Songs[i])==Nil) {
            InsertLast(L, P);
        } else Dealokasi(&P);
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


void Status(Queue *q, Stack *s){
    QueueSongType Now_Playing, Antrean_Lagu;
    int i;
    if (playlist != ""){ 
        printf("Current Playlist: %s\n\n", playlist);
    }     
    if (isEmptyStack(*s)){
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n\nQueue:\nYour queue is empty.");
    }else{
        Pop (s, &Now_Playing);
        printf("Now Playing:\n%s - %s - %s\n\n", Now_Playing.penyanyi, Now_Playing.album, Now_Playing.judul_lagu);
        if (isEmptyQueue (*q)){
            printf("Queue:\nYour queue is empty.");
        }else{
            for (i = 0; i < lengthQueue; i++){
                printf("%d. %s - %s - %s", i+1, Antrean_Lagu.penyanyi, Antrean_Lagu.album, Antrean_Lagu.judul_lagu);
            }
        }
    }
}

void Queue_Song(Queue *q, Stack *s){
    char *chosen_penyanyi;
    char *chosen_album;
    char *id_chosen_lagu_string;
    int id_chosen_lagu;
    printf("Daftar Penyanyi :\n");
    // for (int i = 0; i < length_penyanyi; i++){
    //     printf("%d. %s\n", i+1, Penyanyi[i])
    // }
    printf ("Masukkan Nama Penyanyi yang dipilih : ");
    readCommand();
    WordToString(currentWord, chosen_penyanyi);
    if (SearchList()){
        printf ("Daftar Album oleh %s :\n", chosen_penyanyi);
        // for (int i = 0; i < length_album; i++){
        //     printf("%d. %s\n", i+1, Penyanyi[i])
        // }
        printf ("Masukkan Nama Album yang dipilih : ");
        readCommand();
        WordToString(currentWord, chosen_album);
        if (IsMemberMap()){
            printf ("Daftar Lagu Album %s oleh %s : \n", chosen_penyanyi, chosen_album);
            // for (int i = 0; i < length_lagu; i++){
            //     printf("%d. %s\n", i+1, judul_lagu[i])
            // }
            printf ("Masukkan ID Lagu yang dipilih : ");
            readCommand();
            WordToString (currentWord, id_chosen_lagu_string);
            id_chosen_lagu = id_chosen_lagu_string - '0';            
            if (id_chosen_lagu < set.count){
                char chosen_lagu = lagu[id_chosen_lagu - 1];
                QueueSongType added_song;
                added_song.penyanyi[0] = chosen_penyanyi[0];
                added_song.album[0] = chosen_album[0];
                added_song.judul_lagu[0] = chosen_lagu[0];
                enqueue (s, added_song);
                printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.", chosen_lagu, chosen_penyanyi);
            }
        }
    }
}

void Queue_Playlist(){
    playlist id_playList;
    char *id_playlist_string
    readCommand();
    WordToString(currentWord, id_playlist_string);
    id_playlist = id_playlist_string - '0';
    if (id_PlayList < NbEmlt(playlist)){
        for (int i = 0; i < length_playlist; i++){
            enqueue(q, queue_song)
        }
        printf("Berhasil menambahkan playlist \"%s\" ke queue.", playlist);
    }   
}

void Queue_Swap(Queue *q, int x, int y){
    QueueSongType temp, song_x, song_y;
    if (x > lengthQueue(*q)){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", x);
    }else if ( y > lengthQueue(*q)){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!", y);
    }else{
        int NbElmt = lengthQueue(*q);
        for (int i = 1; i <= NbElmt; i++){
            if (i == x){
                dequeue (q, &song_x);
                enqueue (q, song_x);
            }else if (i == y){
                dequeue (q, &song_y);
                enqueue (q, song_y);
            }else{
                dequeue (q, &temp);
                enqueue (q, temp);
            } 
        }
        for (int i = 1; i <= NbElmt; i++){
            if (i == x){
                dequeue (q, &temp);
                enqueue (q, song_y);
            }else if (i == y){
                dequeue (q, &temp);
                enqueue (q, song_x);
            }else{
                dequeue (q, &temp);
                enqueue (q, temp);
            }
        }
        displayQueue (*q);
    }
}