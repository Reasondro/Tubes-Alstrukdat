#include "console.h"

Queue QueueOriginal;
Stack StackOriginal;
int InitialSize=10;
DaftarPlaylist DP;
ListPenyanyi LPenyu;

void init_dafplay(){
    DP.pl = (Playlist*) malloc (InitialSize*sizeof(Playlist));
    DP.Neff = 0;
    DP.Capacity = InitialSize;
    if (DP.pl == Nil) init_playlist();
} //harus dipanggil waktu start, tapi kalau load jangan

void realloc_dafplay(DaftarPlaylist DP){
    while (DP.Neff>=DP.Capacity) {
        DP.pl = (Playlist*) realloc(DP.pl, DP.Capacity+5 * sizeof(Playlist));
    } DP.Capacity += 5;
}

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
                play_song(&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, PLAY_PLAYLIST)){
                play_playlist (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, QUEUE_SONG)){
                Queue_Song (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, QUEUE_PLAYLIST)){
                Queue_Playlist (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, QUEUE_SWAP)){
                Queue_Swap (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, QUEUE_REMOVE)){
                Queue_Remove (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, QUEUE_CLEAR)){
                Queue_Clear(&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, SONG_NEXT)){
                song_next (&QueueOriginal, &StackOriginal);
            }else if (IsSameWord(currentWord, SONG_PREVIOUS)){
                Song_Previous (&QueueOriginal, &StackOriginal);
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
                Status (&QueueOriginal, &StackOriginal);
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

void Song_Next (Queue *q, Stack *s){
    QueueSongType next_song;
    dequeue (q, &next_song);
    Push (s, next_song);
    printf ("Memutar lagu selanjutnya\n");
    printf ("\"%s oleh \"%s\"", next_song.judul_lagu, next_song.penyanyi);
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
    printf ("Memutar lagu selanjutnya\n");
    printf ("\"%s\" oleh \"%s\"", prevSong.judul_lagu, prevSong.penyanyi);
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
    printf("Masukkan Id Playlist: ");
    readCommand();
    WordToString(currentWord,&id_Playlist_string);
    DP.id = id_Playlist_string - '0';
    if (DP.id < NbEmlt(DP.playlist)){
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

void playlist_create(){
    printf("\n");
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTCOMMAND();
    printf("\n");
    if (stringLengthNoBlanks(&currentWord)>=3) {
        if (DP.Neff>=DP.Capacity) realloc_dafplay(DP);
        WordtoString(currentWord, &DP.pl[DP.Neff].nama);
        printf("Playlist %c berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", DP.pl[DP.Neff].nama);
        First(DP.pl[DP.Neff])=Nil;
        DP.Neff++;
    } else {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    }
}

// GES JADI GES INI GESSSSSSSSSSSSS
void playlist_add_song() {
    char penyanyi, album;
    boolean foundp = false, founda = false;
    printf("ini daftar penyanyi harusnya\n");
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    WordtoString(currentWord, &penyanyi);
    int idxp = 0, idxa = 0, idxl, idxplay;
    while (!foundp && idxp<penyanyimax) {
        if (IsSameString(LPenyu.Penyanyi[idxp].nama, penyanyi)) {
            foundp = true;
        } else idxp++;
    }
    if (!foundp) {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.", penyanyi);
        return;
    } else {
        printf("ini daftar album harusnya\n");
        printf("Masukkan Judul Album yang dipilih : ");
        STARTCOMMAND();
        WordtoString(currentWord, &album);
        while (!founda && idxa < LPenyu.Penyanyi[idxp].album.JumlahAlbum) {
            if (IsSameString(LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, album)) {
                founda = true;
            } else idxa++;
        }
        if (!founda) {
            printf("Album %s tidak ada dalam daftar. Silakan coba lagi.", album);
            return;
        } else {
            printf("ini daftar lagu harusnya\n");
            printf("Masukkan ID Lagu yang dipilih : ");
            STARTCOMMAND();
            idxl = WordToInt(currentWord);
            if (!(idxl <= LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.JumlahLagu && idxl > 0)) {
                printf("ID Lagu %d tidak valid. Silakan coba lagi", idxl);
                return;
            } else {
                idxl--;
                printf("ini daftar playlist harusnya\n");
                printf("Masukkan ID Playlist yang dipilih : ");
                STARTCOMMAND();
                idxplay = WordToInt(currentWord);
                if (!(idxplay <= DP.Neff && idxplay > 0)) {
                    printf("ID Playlist %d tidak valid. Silakan coba lagi", idxplay);
                    return;
                } else {
                    idxplay--;
                    address P = Alokasi(penyanyi, album, LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul);
                    if (Search(DP.pl[idxplay], Info(P))) {
                        printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s sudah ada dalam playlist %s.\n", LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul, LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, LPenyu.Penyanyi[idxp].nama, DP.pl[idxplay].nama);
                    } else {
                        AddtoPlayList(&DP.pl[idxplay], Info(P));
                        printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.\n", LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul, LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, LPenyu.Penyanyi[idxp].nama, DP.pl[idxplay].nama);
                    }
                }
            }
        }
    }
}

// void AddtoPlayList(Playlist *pl, QueueSongType song) {
//     int i;
//     for (i = 0; i < pl->Neff; i++) {
//         if (Compare(pl->Q[i], song)) break;
//         }
//         if (i == pl->Neff) {
//             InsertinQueue(pl, song, pl->Neff + 1);
//             pl->Neff++;
//         } else {
//             printf("\n%s sudah terdaftar di playlist ini.\n", song.name);
//         }
// }

void playlist_add_album() {
    char penyanyi, album;
    boolean foundp = false, founda = false;
    printf("ini daftar penyanyi harusnya\n");
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    WordtoString(currentWord, &penyanyi);
    int idxp = 0, idxa = 0, idxplay;
    while (!foundp && idxp<penyanyimax) {
        if (IsSameString(LPenyu.Penyanyi[idxp].nama, penyanyi)) {
            foundp = true;
        } else idxp++;
    }
    if (!foundp) {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.", penyanyi);
        return;
    } else {
        printf("ini daftar album harusnya\n");
        printf("Masukkan Judul Album yang dipilih : ");
        STARTCOMMAND();
        WordtoString(currentWord, &album);
        while (!founda && idxa < LPenyu.Penyanyi[idxp].album.JumlahAlbum) {
            if (IsSameString(LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, album)) {
                founda = true;
            } else idxa++;
        }
        if (!founda) {
            printf("Album %s tidak ada dalam daftar. Silakan coba lagi.", album);
            return;
        } else {
            printf("ini daftar playlist harusnya\n");
            printf("Masukkan ID Playlist yang dipilih : ");
            STARTCOMMAND();
            idxplay = WordToInt(currentWord);
            if (!(idxplay <= DP.Neff && idxplay > 0)) {
                printf("ID Playlist %d tidak valid. Silakan coba lagi", idxplay);
                return;
            } else {
                idxplay--;
                // alokasi dulu tiap lagu di album sblm nambahin, cek apa semua lagu di album udh ada di playlist
                // if (udah ada semua) {
                //     printf("Album dengan judul “%s” sudah ada pada playlist pengguna “%s”.\n", LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DP.pl[idxplay].nama);
                // } else {
                //     AddtoPlayList(&DP.pl[idxplay], P);
                //     printf("Album dengan judul “%s” berhasil ditambahkan ke dalam pada playlist pengguna “%s”.\n", LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DP.pl[idxplay].nama);
                // }
            }
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


void Status(Queue *q, Stack *s){
    QueueSongType Now_Playing, Antrean_Lagu;
    int i;
    if (playlist != ""){ 
        printf("Current Playlist: %s\n\n", playlist);
    }     
    if (isEmptyStack(*s)){
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n\nQueue:\nYour queue is empty.\n");
    }else{
        Pop (s, &Now_Playing);
        printf("Now Playing:\n%s - %s - %s\n\n", Now_Playing.penyanyi, Now_Playing.album, Now_Playing.judul_lagu);
        if (isEmptyQueue (*q)){
            printf("Queue:\nYour queue is empty.\n");
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
                printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.\n", chosen_lagu, chosen_penyanyi);
            }
        }
    }
}

void Queue_Playlist(){
    playlist id_playList;
    char *id_playlist_string;
    readCommand();
    WordToString(currentWord, id_playlist_string);
    id_playlist = id_playlist_string - '0';
    if (id_PlayList < NbEmlt(playlist)){
        for (int i = 0; i < length_playlist; i++){
            enqueue(q, queue_song)
        }
        printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", playlist);
    }   
}

void Queue_Swap(Queue *q, int x, int y){
    QueueSongType temp, song_x, song_y;
    if (x > lengthQueue(*q)){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", x);
    }else if ( y > lengthQueue(*q)){
        printf("Lagu dengan urutan ke %d tidak terdapat dalam queue!\n", y);
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

void Queue_Remove(Queue *q, int urutan){
    QueueSongType temp, hapus;
    int NbElmt = lengthQueue(*q);
    if (urutan > NbElmt){
        printf("Lagu dengan urutan %d tidak ada.\n", urutan);
    }else{
        for (int i = 1; i <= NbElmt; i++){
            if (i == urutan){
                dequeue (q, &hapus);
            }else{
                dequeue(q, &temp);
                enqueue (q, temp);
            }
        }
        printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", hapus.judul_lagu, hapus.penyanyi);
    }
}

void Queue_Clear(Queue *q){
    QueueSongType deleted;
    int NbElmt = lengthQueue(*q);
    for (int i = 1; i <= NbElmt; i++){
        dequeue(q, &deleted);
    }
    printf("Queue berhasil dikosongkan.\n");
}