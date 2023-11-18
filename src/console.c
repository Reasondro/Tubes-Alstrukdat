#include "console.h"

Queue QueueOriginal;
Stack StackOriginal;
DaftarPlaylist PlayListOriginal;

void cmd_user(){
    char START[] = "START";
    char LOAD[] = "LOAD";
    char LIST_DEFAULT[] = "LIST DEFAULT";
    char LIST_PLAYLIST[] = "LIST PLAYLIST";
    char PLAY_SONG[] = "PLAY SONG";
    char PLAY_PLAYLIST[] = "PLAY PLAYLIST";
    char QUEUE_SONG[] = "QUEUE SONG";
    char QUEUE_PLAYLIST[] = "QUEUE PLAYLIST";
    char QUEUE_SWAP[] = "QUEUE SWAP";
    char QUEUE_REMOVE[] = "QUEUE REMOVE";
    char QUEUE_CLEAR[] = "QUEUE CLEAR";
    char SONG_NEXT[] = "SONG NEXT";
    char SONG_PREVIOUS[] = "SONG PREVIOUS";
    char PLAYLIST_CREATE[] = "PLAYLIST CREATE";
    char PLAYLIST_ADD_SONG[] = "PLAYLIST ADD SONG";
    char PLAYLIST_ADD_ALBUM[] = "PLAYLIST ADD ALBUM";
    char PLAYLIST_SWAP[] = "PLAYLIST SWAP";
    char PLAYLIST_REMOVE[] = "PLAYLIST REMOVE";
    char PLAYLIST_DELETE[] = "PLAYLIST DELETE";
    char STATUS[] = "STATUS";
    char SAVE[] = "SAVE";
    char QUIT[] = "QUIT";
    char HELP[] = "HELP";

    readCommand();
    if (IsSameWord(currentWord, START) || IsSameWord(currentWord, LOAD)){        
        while (!(IsSameWord(currentWord, QUIT))){
            if (IsSameWord(currentWord, START) || IsSameWord(currentWord, LOAD)){
                printf("Command tidak bisa dieksekusi!\n");
            }else if (IsSameWord(currentWord, LIST_DEFAULT)){

            }else if (IsSameWord(currentWord, LIST_PLAYLIST)){

            }else if (IsSameWord(currentWord, PLAY_SONG)){
                play_song();
            }else if (IsSameWord(currentWord, PLAY_PLAYLIST)){
                play_playlist ();
            }else if (IsSameWord(currentWord, QUEUE_SONG)){
                Queue_Song ();
            }else if (IsSameWord(currentWord, QUEUE_PLAYLIST)){
                Queue_Playlist ();
            }else if (IsSameWord(currentWord, QUEUE_SWAP)){
                Queue_Swap ();
            }else if (IsSameWord(currentWord, QUEUE_REMOVE)){
                Queue_Remove ();
            }else if (IsSameWord(currentWord, QUEUE_CLEAR)){
                Queue_Clear();
            }else if (IsSameWord(currentWord, SONG_NEXT)){
                song_next ();
            }else if (IsSameWord(currentWord, SONG_PREVIOUS)){
                Song_Previous ();
            }else if (IsSameWord(currentWord, PLAYLIST_CREATE)){
                playlist_create (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, PLAYLIST_ADD_SONG)){
                playlist_add_song (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, PLAYLIST_ADD_ALBUM)){
                playlist_add_album (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, PLAYLIST_SWAP)){
                playlist_swap (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, PLAYLIST_REMOVE)){
                playlist_remove (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, PLAYLIST_DELETE)){
                playlist_delete (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, STATUS)){
                Status ();
            }else if (IsSameWord(currentWord, SAVE)){
                Save (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, HELP)){
                help (&QueueOriginal, &StackOriginal);
            }else{
                printf("Command tidak diketahui!\n");
            }
        }
    }else{
        printf("Command tidak bisa dieksekusi!\n");
    }
}

void Song_Next (){
    QueueSongType next_song;
    dequeue (&QueueOriginal, &next_song);
    Push (&StackOriginal, next_song);
    printf ("Memutar lagu selanjutnya\n");
    printf ("\"%s oleh \"%s\"", next_song.judul_lagu, next_song.penyanyi);
}

void Song_Previous(){
    QueueSongType ccSong, prevSong, otherSong; 
    Pop(&StackOriginal, &ccSong);
    if (!(IsEmptyStack(StackOriginal))){ //Ada Riwayat lagu
        Pop(&StackOriginal, &prevSong);
        Push (&StackOriginal, prevSong); //ccSong langsung masuk stack atau kaga
        Push (&StackOriginal, ccSong);
    }else{ // stacknya cuma ada ccSong -> playing cclagu dan cclagu taro ke stack
        Push (&StackOriginal, ccSong);
    }
    Push(&StackOriginal, ccSong);
    enqueue (&QueueOriginal, ccSong);
    for (int i = 0; i < lengthQueue (QueueOriginal); i++){
        dequeue (&QueueOriginal, &otherSong);
        enqueue (&QueueOriginal, otherSong);
    }
    printf ("Memutar lagu selanjutnya\n");
    printf ("\"%s\" oleh \"%s\"", prevSong.judul_lagu, prevSong.penyanyi);
}

void Play_Song(){
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
                    dequeue (&QueueOriginal, &otherSong);
                }
                while (!(IsEmptyStack)){
                    Pop (&StackOriginal, &otherSong);
                }
                added_song.penyanyi[0] = chosen_penyanyi[0];
                added_song.album[0] = chosen_album[0];
                added_song.judul_lagu[0] = chosen_lagu[0];
                Push (&StackOriginal, added_song);
                printf("Memutar lagu \"%s\" oleh \"%s\"", chosen_lagu, chosen_penyanyi);
            }
        }
    }
}

void Play_Playlist (){
    char id_Playlist_string;
    DaftarPlaylist dafplaylist;
    printf("Masukkan Id Playlist: ");
    readCommand();
    WordToString(currentWord,&id_Playlist_string);
    dafplaylist.id = id_Playlist_string - '0';
    if (dafplaylist.id < NbEmlt(dafplaylist.playlist)){
        QueueSongType otherSong;
        for (int i = 0; i < lengthQueue; i++){
            dequeue (&QueueOriginal, &otherSong);
        }
        while (!(IsEmptyStack)){
            Pop (&StackOriginal, &otherSong);
        }
        for (int i = 0; i < NbElmt(dafplaylist.playlist); i++){

            Push(&StackOriginal, queue_song_dari_playlist);
        }
    } 
}

void playlist_create(){
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

void playlist_add_song() {
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
    CopyStack(&StackOriginal, &StackTemp);
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


void Status(){
    QueueSongType Now_Playing, Antrean_Lagu;
    int i;
    if (playlist != ""){ 
        printf("Current Playlist: %s\n\n", playlist);
    }     
    if (isEmptyStack(*s)){
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n\nQueue:\nYour queue is empty.\n");
    }else{
        Pop (&StackOriginal, &Now_Playing);
        printf("Now Playing:\n%s - %s - %s\n\n", Now_Playing.penyanyi, Now_Playing.album, Now_Playing.judul_lagu);
        if (isEmptyQueue (QueueOriginal)){
            printf("Queue:\nYour queue is empty.\n");
        }else{
            for (i = 0; i < lengthQueue; i++){
                printf("%d. %s - %s - %s", i+1, Antrean_Lagu.penyanyi, Antrean_Lagu.album, Antrean_Lagu.judul_lagu);
            }
        }
    }
}

void Queue_Song(){
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
                enqueue (&StackOriginal, added_song);
                printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n", chosen_lagu, chosen_penyanyi);
            }
        }
    }
}

void Queue_Playlist(){
    int id_playlist;
    char *id_playlist_string;
    readCommand();
    WordToString(currentWord, id_playlist_string);
    id_playlist = id_playlist_string - '0';
    if (id_playlist < NbEmlt(playlist_original)){
        for (int i = 0; i < NbEmlt(playlist_original); i++){
            enqueue(&QueueOriginal, playlist_original.);
        }
        printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", playlist);
    }   
}

void Queue_Swap(int x, int y){
    QueueSongType temp, song_x, song_y;
    if (x > lengthQueue(QueueOriginal)){
        printf("Lagu dengan id ke %d tidak terdapat dalam queue!\n", x);
    }else if ( y > lengthQueue(QueueOriginal)){
        printf("Lagu dengan id ke %d tidak terdapat dalam queue!\n", y);
    }else{
        int NbElmt = lengthQueue(QueueOriginal);
        for (int i = 1; i <= NbElmt; i++){
            if (i == x){
                dequeue (&QueueOriginal, &song_x);
                enqueue (&QueueOriginal, song_x);
            }else if (i == y){
                dequeue (&QueueOriginal, &song_y);
                enqueue (&QueueOriginal, song_y);
            }else{
                dequeue (&QueueOriginal, &temp);
                enqueue (&QueueOriginal, temp);
            } 
        }
        for (int i = 1; i <= NbElmt; i++){
            if (i == x){
                dequeue (&QueueOriginal, &temp);
                enqueue (&QueueOriginal, song_y);
            }else if (i == y){
                dequeue (&QueueOriginal, &temp);
                enqueue (&QueueOriginal, song_x);
            }else{
                dequeue (&QueueOriginal, &temp);
                enqueue (&QueueOriginal, temp);
            }
        }
        displayQueue (QueueOriginal);
    }
}

void Queue_Remove(int id){
    QueueSongType temp, hapus;
    int NbElmt = lengthQueue(QueueOriginal);
    if (id > NbElmt){
        printf("Lagu dengan urutan %d tidak ada.\n", id);
    }else{
        for (int i = 1; i <= NbElmt; i++){
            if (i == id){
                dequeue (&QueueOriginal, &hapus);
            }else{
                dequeue(&QueueOriginal, &temp);
                enqueue (&QueueOriginal, temp);
            }
        }
        printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", hapus.judul_lagu, hapus.penyanyi);
    }
}

void Queue_Clear(){
    QueueSongType deleted;
    int NbElmt = lengthQueue(QueueOriginal);
    for (int i = 1; i <= NbElmt; i++){
        dequeue(&QueueOriginal, &deleted);
    }
    printf("Queue berhasil dikosongkan.\n");
}