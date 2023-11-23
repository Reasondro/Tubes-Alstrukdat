#include "console.h"

QueueRevisi QueueOriginal;
QueueSongTypeRevisi currentPlaySong;
StackRevisi StackOriginal;
int InitialSize = 10;
DaftarPlaylist DP;
Word CurrentPlaylist;
int CountPlaylist = 0;
boolean mulai = true;
boolean sesi = false;
int ComeToPlaylist[5];
ListPenyanyiRevisi DaftarPenyanyi;

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

void Song_Next()
{
    QueueSongTypeRevisi next_song;
    if (!(IsEmptyQueue(QueueOriginal)))
    {
        Push(&StackOriginal, currentPlaySong);
        dequeue(&QueueOriginal, &next_song);
        CopasWord(&(currentPlaySong.penyanyi), next_song.penyanyi);
        CopasWord(&(currentPlaySong.album), next_song.album);
        CopasWord(&(currentPlaySong.judul_lagu), next_song.judul_lagu);
        if (CountPlaylist == 0)
        {
            CurrentPlaylist.Length = 0;
        }
        else
        {
            CountPlaylist--;
        }
        printf("Memutar lagu selanjutnya\n");
    }
    else
    {
        printf("Queue kosong, memutar kembali lagu\n");
    }
    printf("\"");
    printWord(currentPlaySong.judul_lagu);
    printf("\" oleh ");
    printf("\"");
    printWord(currentPlaySong.penyanyi);
    printf("\".\n");
}

void Song_Previous()
{
    QueueSongTypeRevisi ccSong, prevSong, otherSong;

    if (!(IsEmptyStack(StackOriginal)))
    {
        Pop(&StackOriginal, &prevSong);
        enqueue(&QueueOriginal, currentPlaySong);
        CopasWord(&currentPlaySong.penyanyi, prevSong.penyanyi);
        CopasWord(&currentPlaySong.album, prevSong.album);
        CopasWord(&currentPlaySong.judul_lagu, prevSong.judul_lagu);
        for (int i = 0; i < LengthQueue(QueueOriginal) - 1; i++)
        {
            dequeue(&QueueOriginal, &otherSong);
            enqueue(&QueueOriginal, otherSong);
        }
    }
    else
    {
        CopasWord(&prevSong.penyanyi, currentPlaySong.penyanyi);
        CopasWord(&prevSong.album, currentPlaySong.album);
        CopasWord(&prevSong.judul_lagu, currentPlaySong.judul_lagu);
        Push(&StackOriginal, prevSong);
    }

    if (CurrentPlaylist.Length != 0)
    {
        CurrentPlaylist.Length++;
    }

    printf("Memutar lagu sebelumnya\n");
    printf("\"");
    printWord(prevSong.judul_lagu);
    printf("\" oleh ");
    printf("\"");
    printWord(prevSong.penyanyi);
    printf("\".\n");
}

void Play_Song()
{
    Word chosen_penyanyi;
    Word chosen_album;
    Word id_chosen_lagu_string;
    int id_chosen_lagu;

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    readCommand();
    int id_penyanyi, id_album;
    id_penyanyi = SearchPenyanyi(DaftarPenyanyi, currentWord);
    if (id_penyanyi != -1)
    {
        DisplayMap(DaftarPenyanyi, chosen_penyanyi);
        printf("Masukkan Nama Album yang dipilih : ");
        readCommand();
        id_album = SearchAlbum(DaftarPenyanyi.Penyanyi[id_penyanyi], currentWord);
        if (id_album != -1)
        {
            DisplaySet(DaftarPenyanyi.Penyanyi[id_penyanyi].album, currentWord);
            printf("Masukkan ID Lagu yang dipilih : ");
            readCommand();
            id_chosen_lagu = *(id_chosen_lagu_string.TabWord) - '0';
            if (id_chosen_lagu < DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.JumlahLagu)
            {
                Word chosen_lagu;
                CopasWord(&chosen_lagu, DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.Songs[id_chosen_lagu - 1]);
                QueueSongTypeRevisi otherSong;
                for (int i = 0; i < LengthQueue(QueueOriginal); i++)
                {
                    dequeue(&QueueOriginal, &otherSong);
                }
                while (!(IsEmptyStack(StackOriginal)))
                {
                    Pop(&StackOriginal, &otherSong);
                }
                CopasWord(&currentPlaySong.penyanyi, chosen_penyanyi);
                CopasWord(&currentPlaySong.album, chosen_album);
                CopasWord(&currentPlaySong.judul_lagu, chosen_lagu);
                CountPlaylist++;
                printf("Memutar lagu ");
                printf("\"");
                printWord(currentPlaySong.judul_lagu);
                printf("\" oleh \"");
                printWord(currentPlaySong.penyanyi);
                printf("\".\n");
            }
            else
            {
                printf("Tidak ada lagu dengan id %d", id_chosen_lagu);
            }
        }
        else
        {
            // printf("Tidak ada Album \"%s\".", chosen_album);
            printf("Tidak ada Album \"");
            printWord(chosen_album);
            printf("\".\n");
        }
    }
    else
    {
        // printf("Tidak ada Penyanyi \"%s\".", chosen_penyanyi);
        printf("Tidak ada Penyanyi \"");
        printWord(chosen_album);
        printf("\".\n");
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
        while (!(IsEmptyStack(StackOriginal)))
        {
            Pop(&StackOriginal, &otherSong);
        }
        addressPlaylist p = DP.pl[id_Playlist].First;
        CopasWord(&currentPlaySong.penyanyi, p->info.penyanyi);
        CopasWord(&currentPlaySong.album, p->info.album);
        CopasWord(&currentPlaySong.judul_lagu, p->info.judul_lagu);
        while (Next(p) != Nil)
        {
            p = Next(p);
            enqueue(&QueueOriginal, p->info);
        }
        CopasWord(&CurrentPlaylist, DP.pl[id_Playlist].nama);
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
        // printf("Playlist %s berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n", DP.pl[DP.Neff].nama);
        printf("Playlist ");
        printWord(DP.pl[DP.Neff].nama);
        printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n");
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
    Word penyanyi, album;
    boolean foundp = false, founda = false;
    printf("ini daftar penyanyi harusnya\n");
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    CopasWord(&penyanyi, currentWord);
    int idxp = 0, idxa = 0, idxl, idxplay;
    while (!foundp && idxp < penyanyimax)
    {
        if (IsDuplicateWord(DaftarPenyanyi.Penyanyi[idxp].nama, penyanyi))
        {
            foundp = true;
        }
        else
            idxp++;
    }
    if (!foundp)
    {
        printf("Penyanyi ");
        printWord(penyanyi);
        printf(" tidak ada dalam daftar. Silakan coba lagi.");
        return;
    }
    else
    {
        printf("ini daftar album harusnya\n");
        printf("Masukkan Judul Album yang dipilih : ");
        STARTCOMMAND();
        CopasWord(&album, currentWord);
        while (!founda && idxa < DaftarPenyanyi.Penyanyi[idxp].album.JumlahAlbum)
        {
            if (IsDuplicateWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, album))
            {
                founda = true;
            }
            else
                idxa++;
        }
        if (!founda)
        {
            printf("Album ");
            printWord(album);
            printf(" tidak ada dalam daftar. Silakan coba lagi.");
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
                    addressPlaylist P = Alokasi(penyanyi, album, DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl]);
                    if (Search(DP.pl[idxplay], Info(P)))
                    {
                        // printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s sudah ada dalam playlist %s.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl], DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DaftarPenyanyi.Penyanyi[idxp].nama, DP.pl[idxplay].nama);
                        printf("Lagu dengan judul \"");
                        printWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl]);
                        printf("\" pada album \"");
                        printWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum);
                        printf("\" Oleh penyanyi \"");
                        printWord(DaftarPenyanyi.Penyanyi[idxp].nama);
                        printf("\" sudah ada dalam playlist \"");
                        printWord(DP.pl[idxplay].nama);
                        printf("\".\n");
                    }
                    else
                    {
                        InsertLast(&(DP.pl[idxplay]), P);
                        // printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul, DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DaftarPenyanyi.Penyanyi[idxp].nama, DP.pl[idxplay].nama);
                        printf("Lagu dengan judul ");
                        printf("\"");
                        printWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl]);
                        printf("\" pada album \"");
                        printWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum);
                        printf("\" oleh penyanyi \"");
                        printWord(DaftarPenyanyi.Penyanyi[idxp].nama);
                        printf("\" berhasil ditambahkan ke dalam playlist \"");
                        printWord(DP.pl[idxplay].nama);
                        printf("\".\n");
                    }
                }
            }
        }
    }
}

void playlist_add_album()
{
    Word penyanyi, album;
    boolean foundp = false, founda = false;
    printf("ini daftar penyanyi harusnya\n");
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    CopasWord(&penyanyi, currentWord);
    int idxp = 0, idxa = 0, idxplay;
    while (!foundp && idxp < penyanyimax)
    {
        if (IsDuplicateWord(DaftarPenyanyi.Penyanyi[idxp].nama, penyanyi))
        {
            foundp = true;
        }
        else
            idxp++;
    }
    if (!foundp)
    {
        // printf("Penyanyi %s tidak ada dalam daftar. Silakan coba lagi.", penyanyi);
        printf("Penyanyi ");
        printf("\"");
        printWord(penyanyi);
        printf("\" tidak ada dalam daftar. Silahkan coba lagi.\n");
        return;
    }
    else
    {
        printf("ini daftar album harusnya\n");
        printf("Masukkan Judul Album yang dipilih : ");
        STARTCOMMAND();
        CopasWord(&album, currentWord);
        while (!founda && idxa < DaftarPenyanyi.Penyanyi[idxp].album.JumlahAlbum)
        {
            if (IsDuplicateWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, album))
            {
                founda = true;
            }
            else
                idxa++;
        }
        if (!founda)
        {
            // printf("Album %s tidak ada dalam daftar. Silakan coba lagi.", album);
            printf("Album \"");
            printWord(album);
            printf("\" tidak ada dalam daftar. Silahkan coba lagi.\n");
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
                    P = Alokasi(penyanyi, album, DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl]);
                    if (!Search(DP.pl[idxplay], Info(P)))
                    {
                        InsertLast(&(DP.pl[idxplay]), P);
                        count++;
                    }
                    idxl++;
                    Dealokasi(&P);
                }
                if (count == 0)
                {
                    // printf("Album dengan judul “%s” sudah ada pada playlist pengguna “%s”.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DP.pl[idxplay].nama);
                    printf("\" Album dengan judul \"");
                    printWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum);
                    printf("\" sudah ada pada playlist pengguna \"");
                    printWord(DP.pl[idxplay].nama);
                    printf("\".\n");
                }
                else
                {
                    // printf("Album dengan judul “%s” berhasil ditambahkan ke dalam pada playlist pengguna “%s”.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DP.pl[idxplay].nama);
                    printf("\" Album dengan judul \"");
                    printWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum);
                    printf("\" berhasil ditambahkan ke dalam playlist pengguna \"");
                    printWord(DP.pl[idxplay].nama);
                    printf("\".\n");
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
            // printf("Tidak ada lagu dengan urutan %d di playlist ""%s""", idxl1, DP.pl[idxplay].nama);
            printf("Tidak ada lagu dengan urutan %d di playlist \"", idxl1);
            printWord(DP.pl[idxplay].nama);
            printf("\",\n");
            return;
        }
        else
        {
            idxl1--;
            if (!(idxl2 <= NbElmt(DP.pl[idxplay]) && idxl2 > 0))
            {
                // printf("Tidak ada lagu dengan urutan %d di playlist ""%s""", idxl2, DP.pl[idxplay].nama);
                printf("Tidak ada lagu dengan urutan %d di playlist \"", idxl2);
                printWord(DP.pl[idxplay].nama);
                printf("\",\n");
                return;
            }
            else
            {
                idxl2--;
                if (idxl1 == 0 || idxl1 == NbElmt(DP.pl[idxplay]) - 1 || idxl2 == 0 || idxl2 == NbElmt(DP.pl[idxplay]) - 1)
                {
                    if (idxl1 < idxl2)
                    {
                        swap_pinggir(&(DP.pl[idxplay]), idxl1, idxl2);
                        addressPlaylist lagu1 = AddressAtIndex(DP.pl[idxplay], idxl1);
                        addressPlaylist lagu2 = AddressAtIndex(DP.pl[idxplay], idxl2);
                        // printf("Berhasil menukar lagu dengan nama ""%s"" dengan ""%s"" di playlist ""%s""", lagu1->info.judul_lagu.judul, lagu2->info.judul_lagu.judul, DP.pl[idxplay].nama);
                        printf("Berhasil menukar lagu dengan nama \"");
                        printWord(lagu1->info.judul_lagu);
                        printf("\" dengan \"");
                        printWord(lagu2->info.judul_lagu);
                        printf("\" di playlist \"");
                        printWord(DP.pl[idxplay].nama);
                        printf("\".\n");
                    }
                    else
                    {
                        swap_pinggir(&(DP.pl[idxplay]), idxl2, idxl1);
                        addressPlaylist lagu1 = AddressAtIndex(DP.pl[idxplay], idxl1);
                        addressPlaylist lagu2 = AddressAtIndex(DP.pl[idxplay], idxl2);
                        // printf("Berhasil menukar lagu dengan nama ""%s"" dengan ""%s"" di playlist ""%s""", lagu1->info.judul_lagu.judul, lagu2->info.judul_lagu.judul, DP.pl[idxplay].nama);
                        printf("Berhasil menukar lagu dengan nama \"");
                        printWord(lagu1->info.judul_lagu);
                        printf("\" dengan \"");
                        printWord(lagu2->info.judul_lagu);
                        printf("\" di playlist \"");
                        printWord(DP.pl[idxplay].nama);
                        printf("\".\n");
                    }
                }
                else
                {
                    swap_tengah(DP.pl[idxplay], idxl1, idxl2);
                    addressPlaylist lagu1 = AddressAtIndex(DP.pl[idxplay], idxl1);
                    addressPlaylist lagu2 = AddressAtIndex(DP.pl[idxplay], idxl2);
                    // printf("Berhasil menukar lagu dengan nama ""%s"" dengan ""%s"" di playlist ""%s""", lagu1->info.judul_lagu.judul, lagu2->info.judul_lagu.judul, DP.pl[idxplay].nama);
                    printf("Berhasil menukar lagu dengan nama \"");
                    printWord(lagu1->info.judul_lagu);
                    printf("\" dengan \"");
                    printWord(lagu2->info.judul_lagu);
                    printf("\" di playlist \"");
                    printWord(DP.pl[idxplay].nama);
                    printf("\".\n");
                }
            }
        }
    }
}

void playlist_remove(Playlist *L, int idxl)
{
    if (!(idxl <= NbElmt(*L) && idxl > 0))
    {
        // printf("Tidak ada lagu dengan urutan %d di playlist \"%s\"", idxl, (*L).nama);
        printf("Tidak ada lagu dengan urutan %d di playlist \"", idxl);
        printWord((*L).nama);
        printf("\".\n");
        return;
    }
    else
    {
        idxl--;
        addressPlaylist lagu = AddressAtIndex(*L, idxl);
        addressPlaylist X;
        X = Alokasi(lagu->info.penyanyi, lagu->info.album, lagu->info.judul_lagu);
        ;
        DelP(L, Info(X));
        // printf("Lagu %s oleh %s telah dihapus dari playlist %s!", X->info.judul_lagu.judul, X->info.penyanyi, (*L).nama);
        printf("Lagu \"");
        printWord(X->info.judul_lagu);
        printf("\" oleh \"");
        printWord(X->info.penyanyi);
        printf("\" telah dihapus dari playlist \"");
        printWord((*L).nama);
        printf("\"!\n");
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
        playlist_remove(&(DP.pl[idxplay]), idxl);
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
        for (int i = idxplay - 1; i < DP.Neff - 1; i++)
        {
            DP.pl[i] = DP.pl[i + 1];
        }
        // printf("Playlist ID %d dengan judul %s berhasil dihapus.", idxplay, DP.pl[idxplay].nama);
        printf("Playlist ID %d dengan judul \"", idxplay);
        printWord(DP.pl[idxplay].nama);
        printf("\" berhasil dihapus.\n");
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
    if (CurrentPlaylist.Length != 0)
    {
        // printf("Current Playlist: %s\n\n", CurrentPlaylist);
        printf("Current Playlist: \"");
        printWord(CurrentPlaylist);
        printf("\".\n");
    }
    if (currentPlaySong.judul_lagu.Length == 0)
    {
        printf("Now Playing:\nNo songs have been played yet. Please search for a song to begin playback.\n\nQueue:\nYour queue is empty.\n");
    }
    else
    {
        // printf("Now Playing:\n%s - %s - %s\n\n", currentPlaySong.penyanyi, currentPlaySong.album, currentPlaySong.judul_lagu);
        printf("Now Playing: ");
        printWord(currentPlaySong.penyanyi);
        printf(" - ");
        printWord(currentPlaySong.album);
        printf(" - ");
        printWord(currentPlaySong.judul_lagu);
        printf("\n\n");

        if (IsEmptyQueue(QueueOriginal))
        {
            printf("Queue:\nYour queue is empty.\n");
        }
        else
        {
            for (i = 0; i < LengthQueue(QueueOriginal); i++)
            {
                // printf("%d. %s - %s - %s", i + 1, Antrean_Lagu.penyanyi, Antrean_Lagu.album, Antrean_Lagu.judul_lagu.judul);
                printf("%d. ", i);
                printWord(currentPlaySong.penyanyi);
                printf(" - ");
                printWord(currentPlaySong.album);
                printf(" - ");
                printWord(currentPlaySong.judul_lagu);
                printf("\n\n");
            }
        }
    }
}

void Queue_Song()
{
    Word chosen_penyanyi;
    Word chosen_album;
    Word id_chosen_lagu_string;
    int id_chosen_lagu;

    printf("Masukkan Nama Penyanyi yang dipilih : ");
    readCommand();
    int id_penyanyi, id_album;
    id_penyanyi = SearchPenyanyi(DaftarPenyanyi, currentWord);
    if (id_penyanyi != -1)
    {
        DisplayMap(DaftarPenyanyi, currentWord);
        printf("Masukkan Nama Album yang dipilih : ");
        readCommand();
        id_album = SearchAlbum(DaftarPenyanyi.Penyanyi[id_penyanyi], chosen_album);
        if (id_album != -1)
        {
            DisplaySet(DaftarPenyanyi.Penyanyi[id_penyanyi].album, chosen_album);
            printf("Masukkan ID Lagu yang dipilih : ");
            readCommand();
            id_chosen_lagu = *(id_chosen_lagu_string.TabWord) - '0';
            if (id_chosen_lagu < DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.JumlahLagu)
            {
                Word chosen_lagu;
                CopasWord(&chosen_lagu, DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.Songs[id_chosen_lagu - 1]);
                CopasWord(&currentPlaySong.penyanyi, chosen_penyanyi);
                CopasWord(&currentPlaySong.album, chosen_album);
                CopasWord(&currentPlaySong.judul_lagu, chosen_lagu);
                if (CurrentPlaylist.Length != 0)
                {
                    CurrentPlaylist.Length = 0;
                    CountPlaylist = 0;
                }
                printf("Berhasil menambahkan lagu ");
                printf("\"");
                printWord(chosen_lagu);
                printf("\" oleh \"");
                printWord(chosen_penyanyi);
                printf("\".\n");
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
        // printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", DP.pl[id_playlist].nama);
        printf("Berhasil menambahkan playlist \"");
        printWord(DP.pl[id_playlist].nama);
        printf(" ke queue.\n");
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
    }
    else if (x == y)
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
        printf("Lagu ");
        printf("\"");
        printWord(song_x.judul_lagu);
        printf("\" berhasil ditukar dengan \"");
        printWord(song_y.judul_lagu);
        printf("\".\n");
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
        printf("Lagu ");
        printf("\"");
        printWord(hapus.judul_lagu);
        printf("\" oleh \"");
        printWord(hapus.penyanyi);
        printf("telah diahpsu dari queue!\".\n");
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

void quit()
{
    printf("Apakah kamu ingin menyimpan data sesi sekarang? ");
    ADVWORD();
    if (IsSameWord(currentWord, "Y")){
        Save();
    }else if (IsSameWord(currentWord, "N")){
        printf("Kamu keluar dari WayangWave.\nDadah ^_^/\n");
    }
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

void invalid_command()
{
    boolean error = false;
    boolean invalid = false;
    if (!(sesi))
    {
        if (IsSameWord(currentWord, "LIST"))
        {
            if (IsSameWord(currentWord, "DEFAULT"))
            {
                error = true;
            }
            else if (IsSameWord(currentWord, "PLAYLIST"))
            {
                error = true;
            }
        }
        else if (IsSameWord(currentWord, "PLAY"))
        {
            if (IsSameWord(currentWord, "SONG"))
            {
                error = true;
            }
            else if (IsSameWord(currentWord, "PLAYLIST"))
            {
                error = true;
            }
        }
        else if (IsSameWord(currentWord, "QUEUE"))
        {
            if (IsSameWord(currentWord, "SONG"))
            {
                error = true;
            }
            else if (IsSameWord(currentWord, "PLAYLIST"))
            {
                error = true;
            }
            else if (IsSameWord(currentWord, "SWAP"))
            {
                error = true;
            }
            else if (IsSameWord(currentWord, "REMOVE"))
            {
                error = true;
            }
            else if (IsSameWord(currentWord, "CLEAR"))
            {
                error = true;
            }
        }
        else if (IsSameWord(currentWord, "SONG"))
        {
            if (IsSameWord(currentWord, "NEXT"))
            {
                error = true;
            }
            else if (IsSameWord(currentWord, "PREVIOUS"))
            {
                error = true;
            }
        }
        else if (IsSameWord(currentWord, "PLAYLIST"))
        {
            if (IsSameWord(currentWord, "CREATE"))
            {
                error = true;
            }
            else if (IsSameWord(currentWord, "ADD"))
            {
                if (IsSameWord(currentWord, "SONG"))
                {
                    error = true;
                }
                else if (IsSameWord(currentWord, "ALBUM"))
                {
                    error = true;
                }
            }
            else if (IsSameWord(currentWord, "SWAP"))
            {
                error = true;
            }
            else if (IsSameWord(currentWord, "REMOVE"))
            {
                error = true;
            }
            else if (IsSameWord(currentWord, "DELETE"))
            {
                error = true;
            }
        }
        else if (IsSameWord(currentWord, "STATUS"))
        {
            error = true;
        }
        else if (IsSameWord(currentWord, "SAVE"))
        {
            error = true;
        }
        else if (IsSameWord(currentWord, "HELP"))
        {
            error = true;
        }
        else if (IsSameWord(currentWord, "QUIT"))
        {
            error = true;
        }
        else
        {
            invalid = true;
        }
    }
    else
    {
        if (IsSameWord(currentWord, "START") || IsSameWord(currentWord, "LOAD"))
        {
            error = true;
        }
        else
        {
            invalid = true;
        }
    }
    if (invalid)
    {
        printf("COmmand tidak diketahui!");
    }
    else if (error)
    {
        printf("Command tidak bisa dieksekusi!");
    }
}

void cmd_user()
{
    while (mulai)
    {
        printf(">>> ");
        readCommand();
        if (sesi)
        {
            if (IsSameWord(currentWord, "LIST"))
            {
                if (IsSameWord(currentWord, "DEFAULT"))
                {
                    list_default();
                }
                else if (IsSameWord(currentWord, "PLAYLIST"))
                {
                    list_playlist();
                }
            }
            else if (IsSameWord(currentWord, "PLAY"))
            {
                if (IsSameWord(currentWord, "SONG"))
                {
                    Play_Song();
                }
                else if (IsSameWord(currentWord, "PLAYLIST"))
                {
                    Play_Playlist();
                }
            }
            else if (IsSameWord(currentWord, "QUEUE"))
            {
                if (IsSameWord(currentWord, "SONG"))
                {
                    Queue_Song();
                }
                else if (IsSameWord(currentWord, "PLAYLIST"))
                {
                    Queue_Playlist();
                }
                else if (IsSameWord(currentWord, "SWAP"))
                {
                    Queue_Swap(1, 2);
                }
                else if (IsSameWord(currentWord, "REMOVE"))
                {
                    Queue_Remove(1);
                }
                else if (IsSameWord(currentWord, "CLEAR"))
                {
                    Queue_Clear();
                }
            }
            else if (IsSameWord(currentWord, "SONG"))
            {
                if (IsSameWord(currentWord, "NEXT"))
                {
                    Song_Next();
                }
                else if (IsSameWord(currentWord, "PREVIOUS"))
                {
                    Song_Previous();
                }
            }
            else if (IsSameWord(currentWord, "PLAYLIST"))
            {
                if (IsSameWord(currentWord, "CREATE"))
                {
                    playlist_create();
                }
                else if (IsSameWord(currentWord, "ADD"))
                {
                    if (IsSameWord(currentWord, "SONG"))
                    {
                        playlist_add_song();
                    }
                    else if (IsSameWord(currentWord, "ALBUM"))
                    {
                        playlist_add_album();
                    }
                }
                else if (IsSameWord(currentWord, "SWAP"))
                {
                    playlist_swap(1, 1, 2);
                }
                else if (IsSameWord(currentWord, "REMOVE"))
                {
                    playlist_removesong(1, 1);
                }
                else if (IsSameWord(currentWord, "DELETE"))
                {
                    // playlist_delete();
                    printf("DELETE");
                }
            }
            else if (IsSameWord(currentWord, "STATUS"))
            {
                Status();
            }
            else if (IsSameWord(currentWord, "SAVE"))
            {
                Save(/*harusnya nama file*/);
            }
            else if (IsSameWord(currentWord, "HELP"))
            {
                help();
            }
            else if (IsSameWord(currentWord, "QUIT"))
            {
                // mulai = quit();
                printf("quit");
            }
            else
            {
                invalid_command();
            }
        }else{            
            if (IsSameWord(currentWord, "QUIT")){
                    // mulai = quit();
                    printf("quit");
            }else if (IsSameWord(currentWord, "START")){
                // start();
            }else if (IsSameWord(currentWord, "LOAD")){
                // Load();
            }else if(IsSameWord(currentWord, "HELP")){
                help();
            }
            else
            {
                invalid_command();
            }
        }
    }
}