#include "console.h"

QueueRevisi QueueOriginal;
QueueSongTypeRevisi currentPlaySong;
Stack StackOriginal;
int InitialSize = 10;
DaftarPlaylist DP;
char CurrentPlaylist[30];
int CountPlaylist = 0;
boolean mulai = true;
boolean sesi = false;
int ComeToPlaylist[5];
ListPenyanyi DaftarPenyanyi;

void init_dafplay()
{
    DP.pl = (Playlist *)malloc(InitialSize * sizeof(Playlist));
    DP.Neff = 0;
    DP.Capacity = InitialSize;
    if (DP.pl == Nil)
    {
        init_dafplay();
    }
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
    QueueSongTypeRevisi next_song;
    if (!(IsEmptyQueue(QueueOriginal))){        
        Push (&StackOriginal, currentPlaySong);
        dequeue (&QueueOriginal, &next_song);
        printf("%s", next_song.album);
        stringCopy (currentPlaySong.penyanyi, next_song.penyanyi);
        stringCopy (currentPlaySong.album, next_song.album);
        stringCopy (currentPlaySong.judul_lagu.judul, next_song.judul_lagu.judul);
        if (CountPlaylist != 0){
            CountPlaylist--;
            if (CountPlaylist == 0){
                stringCopy(CurrentPlaylist, "");
            }
        }
        printf ("Memutar lagu selanjutnya\n");
        printf ("\"%s oleh \"%s\"\n", next_song.judul_lagu.judul, next_song.penyanyi);
    }else{
        printf("Queue kosong, memutar kembali lagu \"%s\" oleh \"%s\".\n", currentPlaySong.judul_lagu.judul, currentPlaySong.penyanyi);
    }
}


void Song_Previous()
{
    QueueSongTypeRevisi ccSong, prevSong, otherSong;

    if (!(IsEmptyStack(StackOriginal)))
    {
        Pop(&StackOriginal, &prevSong);
        enqueue(&QueueOriginal, currentPlaySong);
        stringCopy(currentPlaySong.penyanyi, prevSong.penyanyi);
        stringCopy(currentPlaySong.album, prevSong.album);
        stringCopy(currentPlaySong.judul_lagu.judul, prevSong.judul_lagu.judul);
        for (int i = 0; i < LengthQueue(QueueOriginal)-1; i++)
        {
            dequeue(&QueueOriginal, &otherSong);
            enqueue(&QueueOriginal, otherSong);
        }
    }
    else
    {
        stringCopy(prevSong.penyanyi, currentPlaySong.penyanyi);
        stringCopy(prevSong.album, currentPlaySong.album);
        stringCopy(prevSong.judul_lagu.judul, currentPlaySong.judul_lagu.judul);
        Push(&StackOriginal, prevSong);
    }
    if (!(IsSameString(CurrentPlaylist, "")))
    {
        CountPlaylist++;
    }
    printf("Memutar lagu sebelumnya\n");
    printf("\"%s\" oleh \"%s\"\n", prevSong.judul_lagu.judul, prevSong.penyanyi);
}

void Play_Song()
{
    char *chosen_penyanyi;
    char *chosen_album;
    char *id_chosen_lagu_string;
    int id_chosen_lagu;

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    readCommand();
    int id_penyanyi, id_album;
    WordToString(currentWord, chosen_penyanyi);
    id_penyanyi = SearchPenyanyi(DaftarPenyanyi, chosen_penyanyi);
    if (id_penyanyi != -1)
    {
        DisplayMap(DaftarPenyanyi, chosen_penyanyi);
        printf("Masukkan Nama Album yang dipilih : ");
        readCommand();
        id_album = SearchAlbum(DaftarPenyanyi.Penyanyi[id_penyanyi], chosen_album);
        if (id_album != -1)
        {
            WordToString(currentWord, chosen_album);
            DisplaySet(DaftarPenyanyi.Penyanyi[id_penyanyi].album, chosen_album);
            printf("Masukkan ID Lagu yang dipilih : ");
            readCommand();
            WordToString(currentWord, id_chosen_lagu_string);
            id_chosen_lagu = *id_chosen_lagu_string - '0';
            if (id_chosen_lagu < DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.JumlahLagu)
            {
                char *chosen_lagu;
                stringCopy(chosen_lagu, DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.Songs[id_chosen_lagu - 1].judul);
                QueueSongTypeRevisi otherSong;
                for (int i = 0; i < LengthQueue(QueueOriginal); i++)
                {
                    dequeue(&QueueOriginal, &otherSong);
                }
                while (!(IsEmptyStack))
                {
                    Pop(&StackOriginal, &otherSong);
                }
                stringCopy(currentPlaySong.penyanyi, chosen_penyanyi);
                stringCopy(currentPlaySong.album, chosen_album);
                stringCopy(currentPlaySong.judul_lagu.judul, chosen_lagu);
                if (!(IsSameString(CurrentPlaylist, "")))
                {
                    stringCopy(CurrentPlaylist, "");
                    CountPlaylist = 0;
                }
                printf("Memutar lagu \"%s\" oleh \"%s\"", currentPlaySong.judul_lagu.judul, currentPlaySong.penyanyi);
            }
            else
            {
                printf("Tidak ada lagu dengan id %d", id_chosen_lagu);
            }
        }
        else
        {
            printf("Tidak ada Album \"%s\".", chosen_album);
        }
    }
    else
    {
        printf("Tidak ada Penyanyi \"%s\".", chosen_penyanyi);
    }
}

void Play_Playlist()
{
    char *id_Playlist_string;
    int id_Playlist;
    printf("Masukkan Id Playlist: ");
    readCommand();
    WordToString(currentWord, id_Playlist_string);
    id_Playlist = *id_Playlist_string - '0';
    if (id_Playlist < DP.Neff)
    {
        QueueSongTypeRevisi otherSong;
        for (int i = 0; i < LengthQueue(QueueOriginal); i++)
        {
            dequeue(&QueueOriginal, &otherSong);
        }
        while (!(IsEmptyStack))
        {
            Pop(&StackOriginal, &otherSong);
        }
        addressPlaylist p = DP.pl[id_Playlist].First;
        stringCopy(currentPlaySong.penyanyi, p->info.penyanyi);
        stringCopy(currentPlaySong.album, p->info.album);
        stringCopy(currentPlaySong.judul_lagu.judul, p->info.judul_lagu.judul);
        while (Next(p) != Nil)
        {
            p = Next(p);
            enqueue(&QueueOriginal, p->info);
        }
        stringCopy(CurrentPlaylist, DP.pl[id_Playlist].nama);
        CountPlaylist = NbElmt(DP.pl[id_Playlist]);
    }
    else
    {
        printf("Tidak ada Playlist dengan id %d", id_Playlist);
    }
}

void playlist_create()
{
    printf("\n");
    printf("Masukkan nama playlist yang ingin dibuat : ");
    STARTCOMMAND();
    printf("\n");
    Word temp;
    CopasWord(&temp, currentWord);
    if (WordLengthNoBlanks(temp) >= 3)
    {
        if (DP.Neff >= DP.Capacity)
            realloc_dafplay(DP);
        CopasWord(&(DP.pl[DP.Neff].nama), currentWord);
        printf("Playlist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", DP.pl[DP.Neff].nama);
        First(DP.pl[DP.Neff]) = Nil;
        DP.Neff++;
    }
    else
    {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    }
}

void playlist_add_song()
{
    char penyanyi, album;
    boolean foundp = false, founda = false;
    printf("ini daftar penyanyi harusnya\n");
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    WordToString(currentWord, &penyanyi);
    int idxp = 0, idxa = 0, idxl, idxplay;
    while (!foundp && idxp < penyanyimax)
    {
        if (IsSameString(DaftarPenyanyi.Penyanyi[idxp].nama, &penyanyi))
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
        WordToString(currentWord, &album);
        while (!founda && idxa < DaftarPenyanyi.Penyanyi[idxp].album.JumlahAlbum)
        {
            if (IsSameString(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, &album))
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
            if (!(idxl <= DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.JumlahLagu && idxl > 0))
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
                    addressPlaylist P = Alokasi(&penyanyi, &album, DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul);
                    if (Search(DP.pl[idxplay], Info(P)))
                    {
                        printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s sudah ada dalam playlist %s.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul, DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DaftarPenyanyi.Penyanyi[idxp].nama, DP.pl[idxplay].nama);
                    }
                    else
                    {
                        QueueSongTypeRevisi X;
                        stringCopy(X.album, &album);
                        stringCopy(X.judul_lagu.judul, DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul);
                        stringCopy(X.penyanyi, &penyanyi);
                        InsVLast(&DP.pl[idxplay], X);
                        printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul, DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DaftarPenyanyi.Penyanyi[idxp].nama, DP.pl[idxplay].nama);
                    }
                }
            }
        }
    }
}

void playlist_add_album()
{
    char penyanyi, album;
    boolean foundp = false, founda = false;
    printf("ini daftar penyanyi harusnya\n");
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    WordToString(currentWord, &penyanyi);
    int idxp = 0, idxa = 0, idxplay;
    while (!foundp && idxp < penyanyimax)
    {
        if (IsSameString(DaftarPenyanyi.Penyanyi[idxp].nama, &penyanyi))
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
        WordToString(currentWord, &album);
        while (!founda && idxa < DaftarPenyanyi.Penyanyi[idxp].album.JumlahAlbum)
        {
            if (IsSameString(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, &album))
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
                int count = 0, idxl = 0;
                addressPlaylist P;
                while (idxl < DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.JumlahLagu)
                {
                    P = Alokasi(&penyanyi, &album, DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul);
                    if (!Search(DP.pl[idxplay], Info(P)))
                    {
                        InsertLast(&DP.pl[idxplay], P);
                        count++;
                    }
                    idxl++;
                    Dealokasi(&P);
                }
                if (count == 0)
                {
                    printf("Album dengan judul “%s” sudah ada pada playlist pengguna “%s”.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DP.pl[idxplay].nama);
                }
                else
                {
                    printf("Album dengan judul “%s” berhasil ditambahkan ke dalam pada playlist pengguna “%s”.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DP.pl[idxplay].nama);
                }
            }
        }
    }
}

void playlist_swap(int idxplay, int idxl1, int idxl2)
{
    if (!(idxplay <= DP.Neff && idxplay > 0))
    {
        printf("Tidak ada playlist dengan playlist ID %d\n", idxplay);
        return;
    }
    else
    {
        idxplay--;
        if (!(idxl1 <= NbElmt(DP.pl[idxplay]) && idxl1 > 0))
        {
            printf("Tidak ada lagu dengan urutan %d di playlist ""%s""", idxl1, DP.pl[idxplay].nama);
            return;
        }
        else
        {
            idxl1--;
            if (!(idxl2 <= NbElmt(DP.pl[idxplay]) && idxl2 > 0))
            {
                printf("Tidak ada lagu dengan urutan %d di playlist ""%s""", idxl2, DP.pl[idxplay].nama);
                return;
            }
            else
            {
                idxl2--;
                if (idxl1 == 0 || idxl1 == NbElmt(DP.pl[idxplay])-1 || idxl2 == 0 || idxl2 == NbElmt(DP.pl[idxplay])-1)
                {
                    if (idxl1 < idxl2)
                    {
                        swap_pinggir(&DP.pl[idxplay], idxl1, idxl2);
                        addressPlaylist lagu1 = AddressAtIndex(DP.pl[idxplay], idxl1);
                        addressPlaylist lagu2 = AddressAtIndex(DP.pl[idxplay], idxl2);
                        printf("Berhasil menukar lagu dengan nama ""%s"" dengan ""%s"" di playlist ""%s""", lagu1->info.judul_lagu.judul, lagu2->info.judul_lagu.judul, DP.pl[idxplay].nama);
                    }
                    else
                    {
                        swap_pinggir(&DP.pl[idxplay], idxl2, idxl1);
                        addressPlaylist lagu1 = AddressAtIndex(DP.pl[idxplay], idxl1);
                        addressPlaylist lagu2 = AddressAtIndex(DP.pl[idxplay], idxl2);
                        printf("Berhasil menukar lagu dengan nama ""%s"" dengan ""%s"" di playlist ""%s""", lagu1->info.judul_lagu.judul, lagu2->info.judul_lagu.judul, DP.pl[idxplay].nama);
                    }
                }
                else
                {
                    swap_tengah(DP.pl[idxplay], idxl1, idxl2);
                    addressPlaylist lagu1 = AddressAtIndex(DP.pl[idxplay], idxl1);
                    addressPlaylist lagu2 = AddressAtIndex(DP.pl[idxplay], idxl2);
                    printf("Berhasil menukar lagu dengan nama ""%s"" dengan ""%s"" di playlist ""%s""", lagu1->info.judul_lagu.judul, lagu2->info.judul_lagu.judul, DP.pl[idxplay].nama);
                }
            }
        }
    }
}

void playlist_remove(Playlist *L, int idxl)
{
    if (!(idxl <= NbElmt(*L) && idxl > 0))
    {
        printf("Tidak ada lagu dengan urutan %d di playlist ""%s""", idxl, (*L).nama);
        return;
    }
    else
    {
        idxl--;
        addressPlaylist lagu = AddressAtIndex(*L, idxl);
        addressPlaylist X;
        X = Alokasi(lagu->info.penyanyi,lagu->info.album,lagu->info.judul_lagu.judul);;
        DelP(L, Info(X));
        printf("Lagu %s oleh %s telah dihapus dari playlist %s!", X->info.judul_lagu.judul, X->info.penyanyi, (*L).nama);
    }
}

void playlist_removesong(int idxplay, int idxl)
{
    if (!(idxplay <= DP.Neff && idxplay > 0))
    {
        printf("Tidak ada playlist dengan playlist ID %d\n", idxplay);
        return;
    }
    else
    {
        idxplay--;
        playlist_remove(&DP.pl[idxplay], idxl);
    }
}

void playlist_delete()
{
    printf("ini daftar playlist harusnya\n");
    int idxplay;
    printf("Masukkan ID Playlist yang dipilih : ");
    STARTCOMMAND();
    idxplay = WordToInt(currentWord);
    if (!(idxplay <= DP.Neff && idxplay > 0))
    {
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.", idxplay);
        return;
    }
    else
    {
        idxplay--;
        for (int i = idxplay-1; i < DP.Neff-1; i++)
        {
            DP.pl[i] = DP.pl[i+1];
        }
        printf("Playlist ID %d dengan judul %s berhasil dihapus.", idxplay, DP.pl[idxplay].nama);
    }
}

// save yang dulu ak comment dulu, lgi ak kerjani
// void Save()
// {
//     FILE *fptr; // inisisasi file
//     char SaveFile[100];
//     printf("Masukkan nama file: ");
//     scanf("%s", SaveFile);
//     fptr = fopen(SaveFile, "w");

//     int i;

//     Queue QueueTemp; // mulai prosedur save queue
//     CreateQueue(&QueueTemp);
//     CopyQueue(QueueOriginal, &QueueTemp);
//     SongType SongQueue;
//     int jumlahQueue;

//     if (!IsEmptyQueue(QueueOriginal))
//     {
//         jumlahQueue = LengthQueue(QueueTemp);
//         fprintf(fptr, "%d\n", jumlahQueue);
//         for (i = 0; i < LengthQueue(QueueOriginal); i++)
//         {
//             dequeue(&QueueTemp, &SongQueue);
//             fprintf(fptr, "%s;", SongQueue.penyanyi);
//             fprintf(fptr, "%s;", SongQueue.album);
//             fprintf(fptr, "%s\n", SongQueue.judul_lagu);
//         }
//     }

//     Stack StackTemp; // mulai prosedur save stack
//     CreateEmptyStack(&StackTemp);
//     CopyStack(StackOriginal, &StackTemp);
//     SongType SongStack;
//     int jumlahStack;

//     if (!IsEmptyStack(StackOriginal))
//     {
//         jumlahStack = lengthStack(StackTemp);
//         fprintf(fptr, "%d\n", jumlahStack);
//         for (i = 0; i < lengthStack(StackOriginal); i++)
//         {
//             Pop(&StackTemp, &SongStack);
//             fprintf(fptr, "%s;", SongStack.penyanyi);
//             fprintf(fptr, "%s;", SongStack.album);
//             fprintf(fptr, "%s\n", SongStack.judul_lagu);
//         }
//     }
//     fclose(fptr);
// }

// masih bermasalah (mungkin)
void Status()
{
    QueueSongTypeRevisi Now_Playing, Antrean_Lagu;
    int i;
    if (!(IsSameString(CurrentPlaylist, "")))
    {
        printf("Current Playlist: %s\n\n", CurrentPlaylist);
    }
    if (IsSameString(currentPlaySong.judul_lagu.judul, ""))
    {
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n\nQueue:\nYour queue is empty.\n");
    }
    else
    {
        printf("Now Playing:\n%s - %s - %s\n\n", currentPlaySong.penyanyi, currentPlaySong.album, currentPlaySong.judul_lagu.judul);
        if (IsEmptyQueue(QueueOriginal))
        {
            printf("Queue:\nYour queue is empty.\n");
        }
        else
        {
            for (i = 0; i < LengthQueue(QueueOriginal); i++)
            {
                printf("%d. %s - %s - %s", i + 1, Antrean_Lagu.penyanyi, Antrean_Lagu.album, Antrean_Lagu.judul_lagu.judul);
            }
        }
    }
}

void Queue_Song()
{
    char *chosen_penyanyi;
    char *chosen_album;
    char *id_chosen_lagu_string;
    int id_chosen_lagu;

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    readCommand();
    int id_penyanyi, id_album;
    WordToString(currentWord, chosen_penyanyi);
    id_penyanyi = SearchPenyanyi(DaftarPenyanyi, chosen_penyanyi);
    if (id_penyanyi != -1)
    {
        DisplayMap(DaftarPenyanyi, chosen_penyanyi);
        printf("Masukkan Nama Album yang dipilih : ");
        readCommand();
        id_album = SearchAlbum(DaftarPenyanyi.Penyanyi[id_penyanyi], chosen_album);
        if (id_album != -1)
        {
            WordToString(currentWord, chosen_album);
            DisplaySet(DaftarPenyanyi.Penyanyi[id_penyanyi].album, chosen_album);
            printf("Masukkan ID Lagu yang dipilih : ");
            readCommand();
            WordToString(currentWord, id_chosen_lagu_string);
            id_chosen_lagu = *id_chosen_lagu_string - '0';
            if (id_chosen_lagu < DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.JumlahLagu)
            {
                char *chosen_lagu;
                stringCopy(chosen_lagu, DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.Songs[id_chosen_lagu - 1].judul);
                stringCopy(currentPlaySong.penyanyi, chosen_penyanyi);
                stringCopy(currentPlaySong.album, chosen_album);
                stringCopy(currentPlaySong.judul_lagu.judul, chosen_lagu);
                if (!(IsSameString(CurrentPlaylist, "")))
                {
                    stringCopy(CurrentPlaylist, "");
                    CountPlaylist = 0;
                }
                printf("Berhasil menambahkan lagu \"%s\" oleh \"%s\" ke queue.", chosen_lagu, chosen_penyanyi);
            }
        }
    }
}

// masih bermasalah di linked listnya
void Queue_Playlist()
{
    int id_playlist, i;
    char *id_playlist_string;
    readCommand();
    WordToString(currentWord, id_playlist_string);
    id_playlist = *id_playlist_string - '0';
    if (id_playlist < NbElmt(DP.pl[id_playlist]))
    {
        addressPlaylist p = (DP.pl[id_playlist].First);
        while (p != Nil)
        {
            enqueue(&QueueOriginal, p->info);
            p = Next(p);
        }
        printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", DP.pl[id_playlist].nama);
    }
}

void Queue_Swap(int x, int y)
{
    QueueSongTypeRevisi temp, song_x, song_y;
    if (x > LengthQueue(QueueOriginal))
    {
        printf("Lagu dengan id ke %d tidak terdapat dalam queue!\n", x);
    }
    else if (y > LengthQueue(QueueOriginal))
    {
        printf("Lagu dengan id ke %d tidak terdapat dalam queue!\n", y);
    }else if (x == y)
    {
        printf("Tidak bisa menukar lagu yang sama");
    }
    else
    {
        int NbElmt = LengthQueue(QueueOriginal);
        for (int i = 1; i <= NbElmt; i++)
        {
            if (i == x)
            {
                dequeue(&QueueOriginal, &song_x);
                enqueue(&QueueOriginal, song_x);
            }
            else if (i == y)
            {
                dequeue(&QueueOriginal, &song_y);
                enqueue(&QueueOriginal, song_y);
            }
            else
            {
                dequeue(&QueueOriginal, &temp);
                enqueue(&QueueOriginal, temp);
            }
        }
        for (int i = 1; i <= NbElmt; i++)
        {
            if (i == x)
            {
                dequeue(&QueueOriginal, &temp);
                enqueue(&QueueOriginal, song_y);
            }
            else if (i == y)
            {
                dequeue(&QueueOriginal, &temp);
                enqueue(&QueueOriginal, song_x);
            }
            else
            {
                dequeue(&QueueOriginal, &temp);
                enqueue(&QueueOriginal, temp);
            }
        }
        printf("Lagu \"%s\" berhasil ditukar dengan \"%s\"", song_x.judul_lagu.judul, song_y.judul_lagu.judul);
    }
}

void Queue_Remove(int id)
{
    QueueSongTypeRevisi temp, hapus;
    int NbElmt = LengthQueue(QueueOriginal);
    if (id > NbElmt)
    {
        printf("Lagu dengan urutan %d tidak ada.\n", id);
    }
    else
    {
        for (int i = 1; i <= NbElmt; i++)
        {
            if (i == id)
            {
                dequeue(&QueueOriginal, &hapus);
            }
            else
            {
                dequeue(&QueueOriginal, &temp);
                enqueue(&QueueOriginal, temp);
            }
        }
        printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari queue!\n", hapus.judul_lagu.judul, hapus.penyanyi);
    }
}

void Queue_Clear()
{
    QueueSongTypeRevisi deleted;
    int NbElmt = LengthQueue(QueueOriginal);
    for (int i = 1; i <= NbElmt; i++)
    {
        dequeue(&QueueOriginal, &deleted);
    }
    printf("Queue berhasil dikosongkan.\n");
}

void help()
{
    if (sesi)
    {
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
    }
    else
    {
        printf("=====[ Menu Help WayangWave ]=====\n");
        printf("1. START -> Untuk masuk sesi baru\n");
        printf("2. LOAD -> Untuk memulai sesi berdasarkan file konfigurasi\n");
    }
}

void invalid_command(){
    boolean error = false;
    boolean invalid = false;
    if (!(sesi)){
        if (IsSameWord(currentWord, "LIST")){
            if(IsSameWord(currentWord, "DEFAULT")){
                error = true;
            }else if (IsSameWord(currentWord, "PLAYLIST")){
                error = true;
            }                
        }else if (IsSameWord (currentWord, "PLAY")){
            if (IsSameWord(currentWord, "SONG")){
                error = true;
            }else if (IsSameWord(currentWord, "PLAYLIST")){
                error = true;
            }
        }else if(IsSameWord(currentWord, "QUEUE")){
            if (IsSameWord(currentWord, "SONG")){
                error = true;
            }else if (IsSameWord(currentWord, "PLAYLIST")){
                error = true;
            }else if (IsSameWord(currentWord, "SWAP")){
                error = true;
            }else if (IsSameWord(currentWord, "REMOVE")){
                error = true;
            }else if(IsSameWord(currentWord, "CLEAR")){
                error = true;
            }
        }else if (IsSameWord(currentWord, "SONG")){
            if (IsSameWord(currentWord, "NEXT")){
                error = true;
            }else if (IsSameWord(currentWord, "PREVIOUS")){
                error = true;
            }
        }else if (IsSameWord(currentWord, "PLAYLIST")){
            if (IsSameWord(currentWord, "CREATE")){
                error = true;
            }else if(IsSameWord(currentWord, "ADD")){
                if (IsSameWord(currentWord, "SONG")){
                    error = true;
                }else if (IsSameWord(currentWord, "ALBUM")){
                    error = true;
                }
            }else if (IsSameWord(currentWord, "SWAP")){
                error = true;
            }else if(IsSameWord(currentWord, "REMOVE")){
                error = true;
            }else if(IsSameWord(currentWord, "DELETE")){
                error = true;
            }
        }else if(IsSameWord(currentWord, "STATUS")){
            error = true;
        }else if(IsSameWord(currentWord, "SAVE")){
            error = true;
        }else if (IsSameWord(currentWord, "HELP")){
            error = true;
        }else if (IsSameWord(currentWord, "QUIT")){
            error = true;
        }else{
            invalid = true;
        }
    }else{
        if (IsSameWord(currentWord, "START") || IsSameWord(currentWord, "LOAD")){
            error = true;
        }else{
            invalid = true;
        }
    }
    if (invalid){
        printf("COmmand tidak diketahui!");
    }else if (error){
        printf("Command tidak bisa dieksekusi!")
    }
}

void cmd_user(){
    while (mulai){
        printf(">>> ");
        readCommand();
        if (sesi){
            if (IsSameWord(currentWord, "LIST")){
                if(IsSameWord(currentWord, "DEFAULT")){
                    list_default();
                }else if (IsSameWord(currentWord, "PLAYLIST")){
                    list_playlist();
                }                
            }else if (IsSameWord (currentWord, "PLAY")){
                if (IsSameWord(currentWord, "SONG")){
                    Play_Song();
                }else if (IsSameWord(currentWord, "PLAYLIST")){
                    Play_Playlist();
                }
            }else if(IsSameWord(currentWord, "QUEUE")){
                if (IsSameWord(currentWord, "SONG")){
                    Queue_Song();
                }else if (IsSameWord(currentWord, "PLAYLIST")){
                    Queue_Playlist();
                }else if (IsSameWord(currentWord, "SWAP")){
                    Queue_Swap(1,2);
                }else if (IsSameWord(currentWord, "REMOVE")){
                    Queue_Remove(1);
                }else if(IsSameWord(currentWord, "CLEAR")){
                    Queue_Clear();
                }
            }else if (IsSameWord(currentWord, "SONG")){
                if (IsSameWord(currentWord, "NEXT")){
                    Song_Next();
                }else if (IsSameWord(currentWord, "PREVIOUS")){
                    Song_Previous();
                }
            }else if (IsSameWord(currentWord, "PLAYLIST")){
                if (IsSameWord(currentWord, "CREATE")){
                    playlist_create();
                }else if(IsSameWord(currentWord, "ADD")){
                    if (IsSameWord(currentWord, "SONG")){
                        playlist_add_song();
                    }else if (IsSameWord(currentWord, "ALBUM")){
                        playlist_add_album();
                    }
                }else if (IsSameWord(currentWord, "SWAP")){
                    playlist_swap(1, 1, 2);
                }else if(IsSameWord(currentWord, "REMOVE")){
                    playlist_removesong(1, 1);
                }else if(IsSameWord(currentWord, "DELETE")){
                    // playlist_delete();
                    printf("DELETE");
                }
            }else if(IsSameWord(currentWord, "STATUS")){
                Status();
            }else if(IsSameWord(currentWord, "SAVE")){
                Save(/*harusnya nama file*/);
            }else if (IsSameWord(currentWord, "HELP")){
                help();
            }else if (IsSameWord(currentWord, "QUIT")){
                // mulai = quit();
                printf("quit");
            }else{
                invalid_command();
            }
        }else{            
            if (IsSameWord(currentWord, "QUIT")){
                    // mulai = quit();
                    printf("quit");
            }else if (IsSameWord(currentWord, "START")){
                start();
            }else if (IsSameWord(currentWord, "LOAD")){
                Load();
            }else if(IsSameWord(currentWord, "HELP")){
                help();
            }else{
                invalid_command();
            }
        }
    }
}
void Start()
{
    char StartFileName[40] = "save.txt";
    // printf("Masukkan nama file: ");
    // readCommand();
    // WordToString(currentWord, StartFileName);
    STARTLINE(StartFileName);

    int jumlahPenyanyi, jumlahAlbum, jumlahLagu;
    jumlahPenyanyi = currentLine.TabLine[0] - '0'; // inisiasi jumlah penaynyi

    CreateEmptyListPenyanyi(&DaftarPenyanyi); // ini buat inisiasi list penyanyi
    PenyanyiTypeRevisi currentPenyanyi;       // variabel temp
    AlbumTypeRevisi currentAlbum;             // variabel temp
    SongType currentSong;

    CreateQueue(&QueueOriginal);
    CreateEmptyStack(&StackOriginal);
    stringCopy(currentPenyanyi.nama, "");
    stringCopy(currentAlbum.AlbumKe[0].NamaAlbum, "");
    stringCopy(currentSong.judul, "");

    int i, j, k, l, m, n;
    for (i = 0; i < jumlahPenyanyi; i++)
    {
        stringCopy(currentPenyanyi.nama, "");
        ADVLINE();
        jumlahAlbum = currentLine.TabLine[0] - '0';

        for (j = 2; j < currentLine.LengthLine; j++)
        {
            currentPenyanyi.nama[j - 2] = currentLine.TabLine[j];
        }
        // printf("testing -- %s\n", currentPenyanyi.nama);
        InsertPenyanyi(&DaftarPenyanyi, currentPenyanyi);

        for (m = 0; m < jumlahAlbum; m++)
        {
            ADVLINE(); // ini masuk album pertama kali untuk penyanyi ke i;
            jumlahLagu = currentLine.TabLine[0] - '0';
            stringCopy(currentAlbum.AlbumKe[0].NamaAlbum, "");
            // printf("isi album origin %s\n", currentAlbum.AlbumKe[0].NamaAlbum);
            for (k = 2; k < currentLine.LengthLine; k++)
            {
                currentAlbum.AlbumKe[0].NamaAlbum[k - 2] = currentLine.TabLine[k];
            }
            // printf("testing -- %s\n", currentAlbum.AlbumKe[0].NamaAlbum);
            InsertMap(&(DaftarPenyanyi.Penyanyi[i].album), currentAlbum.AlbumKe[0].NamaAlbum);

            for (l = 0; l < jumlahLagu; l++)
            {

                ADVLINE();
                stringCopy(currentSong.judul, "");
                for (n = 0; n < currentLine.LengthLine; n++)
                {
                    currentSong.judul[n] = currentLine.TabLine[n];
                }
                InsertSet(currentSong, &(DaftarPenyanyi.Penyanyi[i].album), currentAlbum.AlbumKe[0].NamaAlbum);
            }
        }
    }
    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");
}

// ------------------------------------------------------------
void Load()
{
    char LoadFileName[40];
    printf("Masukkan nama file: ");
    readCommand();
    WordToString(currentWord, LoadFileName);
    STARTLINE(LoadFileName);

    int jumlahPenyanyi, jumlahAlbum, jumlahLagu;
    jumlahPenyanyi = currentLine.TabLine[0] - '0'; // inisiasi jumlah penaynyi

    CreateEmptyListPenyanyi(&DaftarPenyanyi); // ini buat inisiasi list penyanyi

    PenyanyiTypeRevisi currentPenyanyi; // variabel temp
    AlbumTypeRevisi currentAlbum;       // variabel temp
    SongType currentSong;

    CreateQueue(&QueueOriginal);
    CreateEmptyStack(&StackOriginal);
    stringCopy(currentPenyanyi.nama, "");
    stringCopy(currentAlbum.AlbumKe[0].NamaAlbum, "");
    stringCopy(currentSong.judul, "");

    int i, j, k, l, m, n;
    for (i = 0; i < jumlahPenyanyi; i++)
    {
        stringCopy(currentPenyanyi.nama, "");
        ADVLINE();
        jumlahAlbum = currentLine.TabLine[0] - '0';

        for (j = 2; j < currentLine.LengthLine; j++)
        {
            currentPenyanyi.nama[j - 2] = currentLine.TabLine[j];
        }
        InsertPenyanyi(&DaftarPenyanyi, currentPenyanyi);

        for (m = 0; m < jumlahAlbum; m++)
        {
            ADVLINE(); // ini masuk album pertama kali untuk penyanyi ke i;
            jumlahLagu = currentLine.TabLine[0] - '0';
            stringCopy(currentAlbum.AlbumKe[0].NamaAlbum, "");
            for (k = 2; k < currentLine.LengthLine; k++)
            {
                currentAlbum.AlbumKe[0].NamaAlbum[k - 2] = currentLine.TabLine[k];
            }
            InsertMap(&(DaftarPenyanyi.Penyanyi[i].album), currentAlbum.AlbumKe[0].NamaAlbum);

            for (l = 0; l < jumlahLagu; l++)
            {

                ADVLINE();
                stringCopy(currentSong.judul, "");
                for (n = 0; n < currentLine.LengthLine; n++)
                {
                    currentSong.judul[n] = currentLine.TabLine[n];
                }
                InsertSet(currentSong, &(DaftarPenyanyi.Penyanyi[i].album), currentAlbum.AlbumKe[0].NamaAlbum);
            }
        }
    }

    ADVLINE();
    int idxHuruf;
    int idxHurufPenyanyi;
    int idxHurufAlbum;
    int idxHurufLagu;

    if (IsSameChar(currentLine.TabLine[0], '-')) // masukikn currentPlaySong
    {
        ADVLINE();
    }
    else
    {
        idxHuruf = 0;
        idxHurufPenyanyi = 0;
        idxHurufAlbum = 0;
        idxHurufLagu = 0;

        while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
        {
            currentPlaySong.penyanyi[idxHurufPenyanyi] = currentLine.TabLine[idxHuruf];
            idxHurufPenyanyi++;
            idxHuruf++;
        }
        idxHuruf++; // lanjut setelah semicolon

        while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
        {
            currentPlaySong.album[idxHurufAlbum] = currentLine.TabLine[idxHuruf];
            idxHurufAlbum++;
            idxHuruf++;
        }
        idxHuruf++; // lanjut setelah semicolon

        for (idxHurufLagu = 0; idxHuruf < currentLine.LengthLine; idxHurufLagu++)
        {
            currentPlaySong.judul_lagu.judul[idxHurufLagu] = currentLine.TabLine[idxHuruf];
            idxHuruf++;
        }
        ADVLINE();
    }
    if (IsSameChar(currentLine.TabLine[0], '0')) // masukin queue
    {
        ADVLINE();
    }
    else
    {
        int queueCount;
        queueCount = currentLine.TabLine[0] - '0';
        ADVLINE();

        QueueSongTypeRevisi tempQST;

        int o;
        for (o = 0; o < queueCount; o++)
        {
            idxHuruf = 0;
            idxHurufPenyanyi = 0;
            idxHurufAlbum = 0;
            idxHurufLagu = 0;
            stringCopy(tempQST.penyanyi, "");
            stringCopy(tempQST.album, "");
            stringCopy(tempQST.judul_lagu.judul, "");

            while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
            {
                tempQST.penyanyi[idxHurufPenyanyi] = currentLine.TabLine[idxHuruf];
                idxHurufPenyanyi++;
                idxHuruf++;
            }
            idxHuruf++; // lanjut setelah semicolon
            while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
            {
                tempQST.album[idxHurufAlbum] = currentLine.TabLine[idxHuruf];
                idxHurufAlbum++;
                idxHuruf++;
            }
            idxHuruf++; // lanjut setelah semicolon

            for (idxHurufLagu = 0; idxHuruf < currentLine.LengthLine; idxHurufLagu++)
            {
                tempQST.judul_lagu.judul[idxHurufLagu] = currentLine.TabLine[idxHuruf];
                idxHuruf++;
            }
            enqueue(&QueueOriginal, tempQST);
            ADVLINE();
        }
    }
    if (IsSameChar(currentLine.TabLine[0], '0')) // masukin stack
    {
        ADVLINE();
    }
    else
    {
        int stackCount;
        stackCount = currentLine.TabLine[0] - '0';
        ADVLINE();

        QueueSongTypeRevisi tempSST;

        int o;
        for (o = 0; o < stackCount; o++)
        {
            idxHuruf = 0;
            idxHurufPenyanyi = 0;
            idxHurufAlbum = 0;
            idxHurufLagu = 0;
            stringCopy(tempSST.penyanyi, "");
            stringCopy(tempSST.album, "");
            stringCopy(tempSST.judul_lagu.judul, "");

            while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
            {
                tempSST.penyanyi[idxHurufPenyanyi] = currentLine.TabLine[idxHuruf];
                idxHurufPenyanyi++;
                idxHuruf++;
            }
            idxHuruf++; // lanjut setelah semicolon
            while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
            {
                tempSST.album[idxHurufAlbum] = currentLine.TabLine[idxHuruf];
                idxHurufAlbum++;
                idxHuruf++;
            }
            idxHuruf++; // lanjut setelah semicolon

            for (idxHurufLagu = 0; idxHuruf < currentLine.LengthLine; idxHurufLagu++)
            {
                tempSST.judul_lagu.judul[idxHurufLagu] = currentLine.TabLine[idxHuruf];
                idxHuruf++;
            }
            Push(&StackOriginal, tempSST);
            ADVLINE();
        }
    }
    // akhir dari baris stack, lanjut ke baris playlist jika ada
    if (IsSameChar(currentLine.TabLine[0], '0'))
    {
        // printf("gaada playlist :(\n"); // isinya nanti
    }
    else
    {
        // printf("%c", currentLine.TabLine[0]); // isinya nanti habis ngerti playlist
    }
}

void ListDefault(ListPenyanyi L)
{

    DisplayListPenyanyi(L);
    printf("Ingin melihat album yang ada? (Y/N): ");
    readCommand();
    char namaPenyanyi[30];
    char namaAlbum[30];
    int idxPenyanyi;
    if (IsSameWord(currentWord, "Y"))
    {
        printf("Pilih penyanyi untuk melihat album mereka:\n");
        readCommand();
        WordToString(currentWord, namaPenyanyi);
        // printf("%s\n", namaPenyanyi);
        // printf("BLACKPINK");
        DisplayMap(L, namaPenyanyi);
        printf("Ingin melihat lagu yang ada? (Y/N): ");
        readCommand();
        idxPenyanyi = SearchPenyanyi(L, namaPenyanyi);
        if (IsSameWord(currentWord, "Y"))
        {
            printf("Pilih nama album dari penyanyi tersebut: ");
            readCommand();
            stringCopy(namaAlbum, "");
            WordToString(currentWord, namaAlbum);
            // printf("%s\n", DaftarPenyanyi.Penyanyi[1].album.AlbumKe[0].NamaAlbum);
            DisplaySet(L.Penyanyi[idxPenyanyi].album, namaAlbum);
        }
    }
    else if (IsSameWord(currentWord, "N")) // ini tinggal n keluar
    {
    }
}