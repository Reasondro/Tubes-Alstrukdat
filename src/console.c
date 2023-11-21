#include "console.h"

Queue QueueOriginal;
QueueSongType currentPlaySong;
Stack StackOriginal;
int InitialSize = 10;
DaftarPlaylist DP;
char CurrentPlaylist[30];
int CountPlaylist = 0;
boolean sesi = false;
int ComeToPlaylist[5];
ListPenyanyi DaftarPenyanyi;
QueueSongType currentSong;

void init_dafplay()
{
    DP.pl = (Playlist *)malloc(InitialSize * sizeof(Playlist));
    DP.Neff = 0;
    DP.Capacity = InitialSize;
    if (DP.pl == Nil)
        init_playlist();
} // harus dipanggil waktu start, tapi kalau load jangan

void realloc_dafplay(DaftarPlaylist DP)
{
    while (DP.Neff >= DP.Capacity)
    {
        DP.pl = (Playlist *)realloc(DP.pl, DP.Capacity + 5 * sizeof(Playlist));
    }
    DP.Capacity += 5;
}

void Song_Next (){
    QueueSongType next_song;
    if (!(IsEmptyQueue(QueueOriginal))){        
        dequeue (&QueueOriginal, &next_song);
        Push (&StackOriginal, next_song);
        if (CountPlaylist != 0){
            CountPlaylist--;
            if (CountPlaylist == 0){
                stringCopy(CurrentPlaylist, "");
            }
        }
        printf ("Memutar lagu selanjutnya\n");
        printf ("\"%s oleh \"%s\"", next_song.judul_lagu, next_song.penyanyi);
    }else{
        printf("Antrean kosong.");
    }
}

void Song_Previous(){
    QueueSongType ccSong, prevSong, otherSong;
    Pop(&StackOriginal, &ccSong);
    
    //Ada Riwayat lagu
    if (!(IsEmptyStack(StackOriginal))){ 
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
    if (!(IsSameString (CurrentPlaylist, ""))){
        CountPlaylist++;
    }
    printf("Memutar lagu selanjutnya\n");
    printf("\"%s\" oleh \"%s\"", prevSong.judul_lagu, prevSong.penyanyi);
}

void Play_Song(){
    char *chosen_penyanyi;
    char *chosen_album;
    char *id_chosen_lagu_string;
    int id_chosen_lagu;

    printf ("Masukkan Nama Penyanyi yang dipilih : ");
    readCommand();
    int id_penyanyi, id_album;
    WordToString(currentWord, chosen_penyanyi);
    id_penyanyi = SearchPenyanyi(DaftarPenyanyi, chosen_penyanyi);
    if (SearchPenyanyi != -1){
        DisplayMap(DaftarPenyanyi, chosen_penyanyi);
        printf ("Masukkan Nama Album yang dipilih : ");
        readCommand();
        id_album = SearchAlbum(DaftarPenyanyi.Penyanyi[id_penyanyi], chosen_album);
        if (id_album != -1){
            WordToString(currentWord, chosen_album);
            DisplaySet(DaftarPenyanyi.Penyanyi[id_penyanyi].album, chosen_album);
            printf ("Masukkan ID Lagu yang dipilih : ");
            readCommand();
            WordToString(currentWord, id_chosen_lagu_string);
            id_chosen_lagu = id_chosen_lagu_string - '0';
            if (id_chosen_lagu < DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.JumlahLagu){
                char *chosen_lagu;
                stringCopy (chosen_lagu, DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.Songs[id_chosen_lagu-1].judul);
                QueueSongType added_song, otherSong;
                for (int i = 0; i < LengthQueue(QueueOriginal); i++){
                    dequeue (&QueueOriginal, &otherSong);
                }
                while (!(IsEmptyStack)){
                    Pop (&StackOriginal, &otherSong);
                }
                stringCopy (added_song.penyanyi, chosen_penyanyi);
                stringCopy (added_song.album, chosen_album);
                stringCopy (added_song.judul_lagu.judul, chosen_lagu);
                Push (&StackOriginal, added_song);
                if (!(IsSameString(CurrentPlaylist, ""))){
                    stringCopy(CurrentPlaylist, "");
                    CountPlaylist = 0;
                }
                printf("Memutar lagu \"%s\" oleh \"%s\"", chosen_lagu, chosen_penyanyi);
            }else{
                printf("Tidak ada lagu dengan id %d", id_chosen_lagu);
            }
        }else{
            printf("Tidak ada Album \"%s\".", chosen_album);
        }
    }else{
        printf("Tidak ada Penyanyi \"%s\".", chosen_penyanyi);
    }
}

void Play_Playlist (){
    char id_Playlist_string;
    int id_Playlist;
    printf("Masukkan Id Playlist: ");
    readCommand();
    WordToString(currentWord,&id_Playlist_string);
    id_Playlist = id_Playlist_string - '0';
    if (id_Playlist < DP.Neff){
        QueueSongType otherSong;
        for (int i = 0; i < LengthQueue(QueueOriginal); i++){
            dequeue (&QueueOriginal, &otherSong);
        }
        while (!(IsEmptyStack)){
            Pop (&StackOriginal, &otherSong);
        }
        address p = DP.pl[id_Playlist].First;
        Push(&StackOriginal, p->info);
        while (Next(p) != Nil){
            p = Next(p);
            enqueue(&QueueOriginal, p->info);
        }
        stringCopy(CurrentPlaylist, DP.pl[id_Playlist].nama);
        CountPlaylist = NbElmt(DP.pl[id_Playlist]);
    }else{
        printf("Tidak ada Playlist dengan id %d", id_Playlist);
    }
}

void playlist_create()
{
    printf("\n");
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTCOMMAND();
    printf("\n");
    if (stringLengthNoBlanks(&currentWord) >= 3)
    {
        if (DP.Neff >= DP.Capacity)
            realloc_dafplay(DP);
        WordtoString(currentWord, &DP.pl[DP.Neff].nama);
        printf("Playlist %c berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", DP.pl[DP.Neff].nama);
        First(DP.pl[DP.Neff]) = Nil;
        DP.Neff++;
    }
    else
    {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    }
}

// GES JADI GES INI GESSSSSSSSSSSSS
void playlist_add_song()
{
    char penyanyi, album;
    boolean foundp = false, founda = false;
    printf("ini daftar penyanyi harusnya\n");
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    WordtoString(currentWord, &penyanyi);
    int idxp = 0, idxa = 0, idxl, idxplay;
    while (!foundp && idxp < penyanyimax)
    {
        if (IsSameString(LPenyu.Penyanyi[idxp].nama, penyanyi))
        {
            foundp = true;
        }
        else
            idxp++;
    }
    if (!foundp)
    {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.", penyanyi);
        return;
    }
    else
    {
        printf("ini daftar album harusnya\n");
        printf("Masukkan Judul Album yang dipilih : ");
        STARTCOMMAND();
        WordtoString(currentWord, &album);
        while (!founda && idxa < LPenyu.Penyanyi[idxp].album.JumlahAlbum)
        {
            if (IsSameString(LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, album))
            {
                founda = true;
            }
            else
                idxa++;
        }
        if (!founda)
        {
            printf("Album %s tidak ada dalam daftar. Silakan coba lagi.", album);
            return;
        }
        else
        {
            printf("ini daftar lagu harusnya\n");
            printf("Masukkan ID Lagu yang dipilih : ");
            STARTCOMMAND();
            idxl = WordToInt(currentWord);
            if (!(idxl <= LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.JumlahLagu && idxl > 0))
            {
                printf("ID Lagu %d tidak valid. Silakan coba lagi", idxl);
                return;
            }
            else
            {
                idxl--;
                printf("ini daftar playlist harusnya\n");
                printf("Masukkan ID Playlist yang dipilih : ");
                STARTCOMMAND();
                idxplay = WordToInt(currentWord);
                if (!(idxplay <= DP.Neff && idxplay > 0))
                {
                    printf("ID Playlist %d tidak valid. Silakan coba lagi", idxplay);
                    return;
                }
                else
                {
                    idxplay--;
                    address P = Alokasi(penyanyi, album, LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul);
                    if (Search(DP.pl[idxplay], Info(P)))
                    {
                        printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s sudah ada dalam playlist %s.\n", LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul, LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, LPenyu.Penyanyi[idxp].nama, DP.pl[idxplay].nama);
                    }
                    else
                    {
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

void playlist_add_album()
{
    char penyanyi, album;
    boolean foundp = false, founda = false;
    printf("ini daftar penyanyi harusnya\n");
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    WordtoString(currentWord, &penyanyi);
    int idxp = 0, idxa = 0, idxplay;
    while (!foundp && idxp < penyanyimax)
    {
        if (IsSameString(LPenyu.Penyanyi[idxp].nama, penyanyi))
        {
            foundp = true;
        }
        else
            idxp++;
    }
    if (!foundp)
    {
        printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.", penyanyi);
        return;
    }
    else
    {
        printf("ini daftar album harusnya\n");
        printf("Masukkan Judul Album yang dipilih : ");
        STARTCOMMAND();
        WordtoString(currentWord, &album);
        while (!founda && idxa < LPenyu.Penyanyi[idxp].album.JumlahAlbum)
        {
            if (IsSameString(LPenyu.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, album))
            {
                founda = true;
            }
            else
                idxa++;
        }
        if (!founda)
        {
            printf("Album %s tidak ada dalam daftar. Silakan coba lagi.", album);
            return;
        }
        else
        {
            printf("ini daftar playlist harusnya\n");
            printf("Masukkan ID Playlist yang dipilih : ");
            STARTCOMMAND();
            idxplay = WordToInt(currentWord);
            if (!(idxplay <= DP.Neff && idxplay > 0))
            {
                printf("ID Playlist %d tidak valid. Silakan coba lagi", idxplay);
                return;
            }
            else
            {
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
    if (!(IsSameString(CurrentPlaylist, ""))){ 
        printf("Current Playlist: %s\n\n", CurrentPlaylist);
    }     
    if (isEmptyStack(StackOriginal)){
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n\nQueue:\nYour queue is empty.\n");
    }else{
        Pop (&StackOriginal, &Now_Playing);
        printf("Now Playing:\n%s - %s - %s\n\n", Now_Playing.penyanyi, Now_Playing.album, Now_Playing.judul_lagu);
        if (isEmptyQueue (QueueOriginal)){
            printf("Queue:\nYour queue is empty.\n");
        }else{
            for (i = 0; i < LengthQueue(QueueOriginal); i++){
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

    printf ("Masukkan Nama Penyanyi yang dipilih : ");
    readCommand();
    int id_penyanyi, id_album;
    WordToString(currentWord, chosen_penyanyi);
    id_penyanyi = SearchPenyanyi(DaftarPenyanyi, chosen_penyanyi);
    if (SearchPenyanyi != -1){
        DisplayMap(DaftarPenyanyi, chosen_penyanyi);
        printf ("Masukkan Nama Album yang dipilih : ");
        readCommand();
        id_album = SearchAlbum(DaftarPenyanyi.Penyanyi[id_penyanyi], chosen_album);
        if (id_album != -1){
            WordToString(currentWord, chosen_album);
            DisplaySet(DaftarPenyanyi.Penyanyi[id_penyanyi].album, chosen_album);
            printf ("Masukkan ID Lagu yang dipilih : ");
            readCommand();
            WordToString (currentWord, id_chosen_lagu_string);
            id_chosen_lagu = id_chosen_lagu_string - '0';
            if (id_chosen_lagu < DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.JumlahLagu){
                QueueSongType added_song, otherSong;
                char *chosen_lagu;
                stringCopy (chosen_lagu, DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.Songs[id_chosen_lagu-1].judul);
                stringCopy (added_song.penyanyi, chosen_penyanyi);
                stringCopy (added_song.album, chosen_album);
                stringCopy (added_song.judul_lagu.judul, chosen_lagu);
                Push (&StackOriginal, added_song);
                if (!(IsSameString(CurrentPlaylist, ""))){
                    stringCopy(CurrentPlaylist, "");
                    CountPlaylist = 0;
                }
                printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.", chosen_lagu, chosen_penyanyi);
            }
        }
    }
}

void Queue_Playlist(){
    int id_playlist, i;
    char *id_playlist_string;
    readCommand();
    WordToString(currentWord, id_playlist_string);
    id_playlist = id_playlist_string - '0';
    if (id_playlist < NbEmlt(DP)){
        address p = First(DP.pl[id_playlist]);
        while (p != Nil){
            enqueue(&QueueOriginal, p->info);
            p = Next(p);
        }
        printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", DP.pl[id_playlist].nama);
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
        printf("Lagu \"%s\" berhasil ditukar dengan \"%s\"", song_x, song_y);
        // displayQueue (QueueOriginal);
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

void help(){
    if (sesi){
        printf("=====[ Menu Help WayangWave ]=====\n");
        printf("1. START -> Untuk memulai Wayang Wave\n");
        printf("2. LOAD -> Untuk membaca file save dan memulai Wayang Wave\n");
        printf("3. LIST -> Untuk menampilkan daftar lagu atau playlist\n");
        printf("4. PLAY -> Untuk memulai suatu lagu atau playlist\n");
        printf("5. Queue -> Untuk menambah lagu atau playlist, menukar posisi antrean, menghapus lagu atau seluruh antrean\n");
        printf("6. SONG -> Untuk navigasi lagu di antrean (Next dan Previous)");
        printf("7. PLAYLIST -> untuk membuat, menambahkan lagu atau album, menukar lagu, menghapus lagu dalam playlist, serta menghapus playlist\n");
        printf("8. STATUS -> Untuk menampilkan lagu yang sedang dimainkan, antrean lagu, playlist yang dimainkan\n");
        printf("9. SAVE -> Untuk menyimpan state ke dalam file\n");
        printf("10. QUIT -> Untuk keluar dari sesi\n");
    }else{
        printf("=====[ Menu Help WayangWave ]=====\n");
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    }
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
    while (!(IsSameWord (currentWord, QUIT))){
        readCommand();
        if (IsSameWord(currentWord, START) || IsSameWord(currentWord, LOAD)){        
            if (IsSameWord(currentWord, START)){
                Start_Wayang_Wave();
            }else{
                loadFile();
            }
            sesi = true;
            readCommand();
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
                    Song_Next ();
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
                readCommand();
            }
        }else{
            sesi = false;
            if (IsSameWord(currentWord, HELP)){
                help();
            }else{
                printf("Command tidak bisa dieksekusi!\n");
            }
        }
    }
}