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

void art_WayangWave()
{
    printf("\n");
    printf("              _       _                               _       _                   \n");
    printf("             ( )  _  ( )                             ( )  _  ( )                  \n");
    printf("             | | ( ) | |  _ _ _   _   _ _  ___    __ | | ( ) | |  _ _ _   _   __  \n");
    printf("             | | | | | |/ _  ) ) ( )/ _  )  _  \\/ _  \\ | | | | |/ _  ) ) ( )/ __ \\\n");
    printf("             | (_/ \\_) | (_| | (_) | (_| | ( ) | (_) | (_/ \\_) | (_| | \\_/ |  ___/\n");
    printf("              \\__/\\___/ \\__ _)\\__  |\\__ _)_) (_)\\__  |\\__/\\___/ \\__ _)\\___/ \\____)\n");
    printf("                             ( )_| |           ( )_) |                            \n");
    printf("                              \\___/             \\___/                             \n");
    printf("                                                                                                    \n");
    printf("                                           ..                                                       \n");
    printf("                          :~?Y555YJ!^  .^7??:                                                       \n");
    printf("                       .7P#&&&&&&###BP7J555?                                                        \n");
    printf("                      ^P##PJ777J5####PY555PY?^.                                                     \n");
    printf("                      P#P^       ^5GGPY555Y5GY   .:!!~:                                             \n");
    printf("                      YBP!        !BGYYPP555557!J555~..                                             \n");
    printf("            ^: .~?5PGPPGG5!.     .Y#BP55P5555J5Y55Y.                                                \n");
    printf("           :?Y75###B5B#PBPYJ7..^7PBPPGG#BG555YYYYY^                                                 \n");
    printf("          .!5YYYPPP5YY5P5Y5YGY5PP5Y5GG###G5P555Y5Y.                                                 \n");
    printf("           ^PP5YYY55PPPPPP55PY555PP5G###P5PYY55YYJ:                                                 \n");
    printf("           :5PGPPGGPBP5PPPY55JY55PG###BPP555Y5Y5YY~:^.                   :~~:..^~!7JY5PP!           \n");
    printf("           :5B######BBGPBBGPP5PBB###B5JY555P5JY55Y5Y!       ......:^^~!!?Y5P55GB#&&&&###B.          \n");
    printf("           ~GBB##B####BGB#BBBBB##GP55555P55Y555YJY55^.^~7?YPGBGGBB#######BPP5YJ?JJ!~~P###!          \n");
    printf("           !####B######BB#B5PBGBBGGPPPP5PPP555PPPGGBGB##&&&##BBGP5Y?YYPPPYY5J?77~    ^B##5          \n");
    printf("           :G###############GGGB###BBBBGPPGBPBB########BPY7~::.       :7?!!!~~^:      J##B.         \n");
    printf("          ^YBPGPYPB##GYYYYJ7^:!YG#######B5GB5PPB###BGJ^.                              :B##!         \n");
    printf("          ?Y~     ~5Y^  :7JYPGB5PBGB#####BG#BPPBBGPP5?                                 J##Y         \n");
    printf("                       :B##&&&BG##GGGGGGPB###BP555555?                                 .B#G.        \n");
    printf("                       ?###Y775G####BPPPGG###BP55PPPY~                                  7##~        \n");
    printf("                       P##P   !P########GP###GY5PPP57                                  :!G#J        \n");
    printf("                     :7###7   .?P#####BBPP#BGPPP5Y?:                                   :5Y55?~      \n");
    printf("                  :7YPG##P.     :75GP5YPPG###Y!!~. .                                   .YPYP5?      \n");
    printf("                  75JYB##7        .!?GBBPP###?  ^?Y557.                                 !JYBP?.     \n");
    printf("                 ^5Y75B5PJ~          ~B##PB##P  ?PPPPPY?~                            .   .?#P       \n");
    printf("                 757:PB5G7^          .P&5YB#BBY~:JPGPGGGGJ                         :JP5Y5G#G~       \n");
    printf("                 :J^^BGG7          .7YG5JYPGB55Y?Y55555555!.                     ~PBBPB#BG?.        \n");
    printf("                   :5#BB:        .?YGPYY555PGGGPPPPPPP55P??J?.                  ~BY^. .^.~.         \n");
    printf("                   :B##G         !55P555P5Y55PPGPBGGG555Y?Y5Y?7.                ?5       ~.         \n");
    printf("                   J###Y        .YYYY55P5P5Y555555PPBGPYY5PGP55J7.              .:       !          \n");
    printf("                   P##B^        ^Y555PPPPGGPPGGGGGP5PPBBPY5P5P555Y?^.                   .7          \n");
    printf("                  .G##P        .J5Y5PPP5PPPPP55PPGP55PGG#P5PPP5YP55PY?7^                :!          \n");
    printf("                  .B##?        ~Y5Y555P55PGP55PPPPPP555Y5BBPPP5YP55PPPPP?.              ^!          \n");
    printf("                  :B##^       .JY5YYY5Y55PGGPPGPPP555555Y5BB5YP555JY55YY5?.             ~!          \n");
    printf("                  ^##G        !555YYY5YY5YPYGGPPGPPY555YJY5GBGGP?YJYYJYYYJ!             !~          \n");
    printf("                  ~##J        ^YYYY5PJY5Y55.JP5555PY5P555PGGG#GP55JJJYJYJJY7            7^          \n");
    printf("                 .7##^        :Y55P5PYYJJGG!?5YY5JJJ55PP5JYGGGBBPPJJYJYYYYJJ?:          ?:          \n");
    printf("                 7Y#P          !PGP5PPPJJYYY5J?Y55YYJJ7!J!:~YPBBBG5YYJJY7 ~JYYJ^       .Y^          \n");
    printf("                :PYP5!.         YGYJPG7~5555?JYY55P5YYJ~ .:^^?PGBBPPYJJY7 ~JYY!        .5^          \n");
    printf("                JP5P5J          YGY5PGPJ5Y~   .75YY7!J5555Y7^. ?PPB###BYY5Y!  ~YYY?:   .P^          \n");
    printf("                ~JGBY!          YG5PGPJ5Y~   .75YY7!J5555Y7^. ?PPB###BYY5Y!  ~YYY?:    .P^          \n");
    printf("         :^?Y~^::Y#Y:           ?PPGPY?^.     :?5YJ^ ^7?Y5555J5GP5G##BG555Y?YYYYY5577. :P^          \n");
    printf("      .?PGGB#&#BBG?            !P5YY5J         :JYYJ.   .:^~!~~55YPG##BGYP5YJ7?7^~~^~. :P^          \n");
    printf("     ^P?^..:?Y5J^.           .7GP555PY^         :J55J.         .75J?JG#BBBGYY!         :P^          \n");
    printf("     !7       ~              YP55B#BGJ:           75P?~:.      ..^?JY##&#B###G:        :P^          \n");
    printf("             ~:             .5YJ5B#PPY~           :YPYYP5?~:^^~PBB#&&&#GPBBY!^         ^P:          \n");
    printf("            ^~               JYJYG#GGY^     ...:^!5P5PPGGGGGGBB####Y7!^  Y#B7          ~P.          \n");
    printf("           .7.               :?Y5PGPPP??JYY5PPGGBBBBBBBBBBBGGPP555!       J##J         !5           \n");
    printf("           !^            :5PPPGB#&#&&&&##BBBBBGGGP55YJ?7!~^::..            ~PG7:       ?J           \n");
    printf("          ^7             ?&&&#B#BP5YJYYY?77!~^::..                          ^PP5!      YJ           \n");
    printf("         .?.             :YG5~::.                                            JBPPJ     57 ..        \n");
    printf("         7~                .                                                 .5GPBP:  ^PYJ5P5^      \n");
    printf("        :!                                                                    ^YJ?YJ~!??JJJJ!..     \n");
    printf("\n");
}
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

void list_playlist(DaftarPlaylist depe)
{
    printf("Daftar playlist yang kamu miliki: \n");
    if (DP.Neff > 0)
    {
        for (int i = 0; i < depe.Neff; i++)
        {
            printf("    %d.", i + 1);
            printWord(depe.pl[i].nama);
            printf("\n");
        }
    }
    else
    {
        printf("Kamu tidak memiliki playlist.");
        printf("\n");
    }
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

    DisplayListPenyanyi(DaftarPenyanyi);
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
    list_playlist(DP);
    printf("Masukkan Id Playlist: ");
    readCommand();
    id_Playlist = (*(currentWord.TabWord) - '0') - 1;
    if (id_Playlist < DP.Neff && id_Playlist >= 0)
    {
        QueueSongTypeRevisi otherSong;
        CreateQueue(&QueueOriginal);
        // DisplayQueue(QueueOriginal);
        // printf("queue dibuang\n\n");
        // printf("\n");
        CreateEmptyStack(&StackOriginal);
        // displayStack(StackOriginal);
        // printf("stack dibuang\n\n");
        printf("\n");
        addressPlaylist p = DP.pl[id_Playlist].First;
        CopasWord(&currentPlaySong.penyanyi, p->info.penyanyi);
        CopasWord(&currentPlaySong.album, p->info.album);
        CopasWord(&currentPlaySong.judul_lagu, p->info.judul_lagu);
        // printf("Current song ditambah\n\n");
        while (Next(p) != Nil)
        {
            p = Next(p);
            enqueue(&QueueOriginal, p->info);
        }
        CopasWord(&CurrentPlaylist, DP.pl[id_Playlist].nama);
        CountPlaylist = NbElmt(DP.pl[id_Playlist]);
        printf("Memutar playlist \"");
        printWord(DP.pl[id_Playlist].nama);
        printf("\".\n\n");
    }
    else
    {
        printf("Tidak ada playlist dengan id %d.\n\n", id_Playlist + 1);
    }
}

void playlist_create()
{
    printf("\n");
    printf("Masukkan nama playlist yang ingin dibuat : ");
    readCommand();
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
        printf(" berhasil dibuat! Silakan masukkan lagu - lagu artis terkini kesayangan Anda!\n\n");
        First(DP.pl[DP.Neff]) = Nil;
        DP.Neff++;
    }
    else
    {
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.\n\n");
    }
}

void playlist_add_song(DaftarPlaylist *depe, ListPenyanyiRevisi *DaftarPenyanyi)
{
    Word penyanyi, album;
    boolean foundp = false, founda = false;
    DisplayListPenyanyi(*DaftarPenyanyi);
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    CopasWord(&penyanyi, currentWord);
    int idxp = 0, idxa = 0, idxl, idxplay;
    while (!foundp && idxp < penyanyimax)
    {
        if (IsDuplicateWord((*DaftarPenyanyi).Penyanyi[idxp].nama, penyanyi))
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
        DisplayMap(*DaftarPenyanyi, penyanyi);
        printf("Masukkan Judul Album yang dipilih : ");
        STARTCOMMAND();
        CopasWord(&album, currentWord);
        while (!founda && idxa < (*DaftarPenyanyi).Penyanyi[idxp].album.JumlahAlbum)
        {
            if (IsDuplicateWord((*DaftarPenyanyi).Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, album))
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
            DisplaySet((*DaftarPenyanyi).Penyanyi[idxp].album, album);
            printf("Masukkan ID Lagu yang dipilih : ");
            STARTCOMMAND();
            idxl = *(currentWord.TabWord) - '0';
            if (!(idxl <= (*DaftarPenyanyi).Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.JumlahLagu && idxl > 0))
            {
                printf("ID Lagu %d tidak valid. Silakan coba lagi", idxl);
                return;
            }
            else
            {
                idxl--;
                list_playlist(*depe);
                printf("Masukkan ID Playlist yang dipilih : ");
                STARTCOMMAND();
                idxplay = *(currentWord.TabWord) - '0';
                if (!(idxplay <= (*depe).Neff && idxplay > 0))
                {
                    printf("ID Playlist %d tidak valid. Silakan coba lagi", idxplay);
                    return;
                }
                else
                {
                    idxplay--;
                    playlistsong(depe, DaftarPenyanyi, idxp, idxa, idxl, idxplay);
                }
            }
        }
    }
}

void playlistsong(DaftarPlaylist *depe, ListPenyanyiRevisi *LP, int idxp, int idxa, int idxl, int idxplay)
{
    //(penyanyi, album, DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl])
    QueueSongTypeRevisi P;
    P.penyanyi = (*LP).Penyanyi[idxp].nama;
    P.album = (*LP).Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum;
    P.judul_lagu = (*LP).Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl];
    if (!cekLagu(depe, P.penyanyi, P.album, P.judul_lagu, idxplay))
    // !Search(DP.pl[idxplay], DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl])
    {
        // printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s sudah ada dalam playlist %s.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl], DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DaftarPenyanyi.Penyanyi[idxp].nama, DP.pl[idxplay].nama);
        printf("Lagu dengan judul \"");
        printWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl]);
        printf("\" pada album \"");
        printWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum);
        printf("\" oleh penyanyi \"");
        printWord(DaftarPenyanyi.Penyanyi[idxp].nama);
        printf("\" sudah ada dalam playlist \"");
        printWord((*depe).pl[idxplay].nama);
        printf("\".\n");
    }
    else
    {
        InsVLast(&((*depe).pl[idxplay]), P);
        // printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist %s.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl].judul, DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DaftarPenyanyi.Penyanyi[idxp].nama, DP.pl[idxplay].nama);
        printf("Lagu dengan judul ");
        printf("\"");
        printWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl]);
        printf("\" pada album \"");
        printWord(DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum);
        printf("\" oleh penyanyi \"");
        printWord(DaftarPenyanyi.Penyanyi[idxp].nama);
        printf("\" berhasil ditambahkan ke dalam playlist \"");
        printWord((*depe).pl[idxplay].nama);
        printf("\".\n");
    }
}

void playlist_add_album(DaftarPlaylist *depe, ListPenyanyiRevisi *DaftarPenyanyi)
{
    Word penyanyi, album;
    boolean foundp = false, founda = false;
    DisplayListPenyanyi(*DaftarPenyanyi);
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    STARTCOMMAND();
    CopasWord(&penyanyi, currentWord);
    int idxp = 0, idxa = 0, idxplay;
    while (!foundp && idxp < penyanyimax)
    {
        if (IsDuplicateWord((*DaftarPenyanyi).Penyanyi[idxp].nama, penyanyi))
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
        DisplayMap(*DaftarPenyanyi, penyanyi);
        printf("Masukkan Judul Album yang dipilih : ");
        STARTCOMMAND();
        CopasWord(&album, currentWord);
        while (!founda && idxa < (*DaftarPenyanyi).Penyanyi[idxp].album.JumlahAlbum)
        {
            if (IsDuplicateWord((*DaftarPenyanyi).Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, album))
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
            printf("\" tidak ada dalam daftar. Silahkan coba lagi.\n\n");
            return;
        }
        else
        {
            list_playlist(*depe);
            printf("\nMasukkan ID Playlist yang dipilih : ");
            STARTCOMMAND();
            idxplay = *(currentWord.TabWord) - '0';
            if (!(idxplay <= (*depe).Neff && idxplay > 0))
            {
                printf("ID Playlist %d tidak valid. Silakan coba lagi\n", idxplay);
                return;
            }
            else
            {
                idxplay--;
                playlistalbum(depe, DaftarPenyanyi, idxp, idxa, idxplay);
            }
        }
    }
}

void playlistalbum(DaftarPlaylist *depe, ListPenyanyiRevisi *LP, int idxp, int idxa, int idxplay)
{
    int count = 0, idxl = 0;
    QueueSongTypeRevisi P;
    for (idxl = 0; idxl < (*LP).Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.JumlahLagu; idxl++)
    {
        P.penyanyi = (*LP).Penyanyi[idxp].nama;
        P.album = (*LP).Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum;
        P.judul_lagu = (*LP).Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl];
        if (cekLagu(depe, P.penyanyi, P.album, P.judul_lagu, idxplay))
        // if (cekLagu(depe, (*LP).Penyanyi[idxp].nama, (*LP).Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, (*LP).Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl], idxplay))
        {
            InsVLast(&((*depe).pl[idxplay]), P);
            count++;
        }
    }
    if (count == 0)
    {
        // printf("Album dengan judul “%s” sudah ada pada playlist pengguna “%s”.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DP.pl[idxplay].nama);
        printf("Album dengan judul \"");
        printWord((*LP).Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum);
        printf("\" sudah ada pada playlist pengguna \"");
        printWord((*depe).pl[idxplay].nama);
        printf("\".\n");
    }
    else
    {
        // printf("Album dengan judul “%s” berhasil ditambahkan ke dalam pada playlist pengguna “%s”.\n", DaftarPenyanyi.Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, DP.pl[idxplay].nama);
        printf("Album dengan judul \"");
        printWord((*LP).Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum);
        printf("\" berhasil ditambahkan ke dalam playlist pengguna \"");
        printWord((*depe).pl[idxplay].nama);
        printf("\".\n");
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
    list_playlist(DP);
    int idxplay;
    printf("Masukkan ID Playlist yang dipilih : ");
    STARTCOMMAND();
    idxplay = *(currentWord.TabWord) - '0';
    if (!(idxplay <= DP.Neff && idxplay > 0))
    {
        printf("Tidak ada playlist dengan ID %d dalam daftar playlist pengguna. Silakan coba lagi.", idxplay);
        return;
    }
    else
    {
        idxplay--;
        for (int i = idxplay; i < DP.Neff - 1; i++)
        {
            DP.pl[i] = DP.pl[i + 1];
        }
        // printf("Playlist ID %d dengan judul %s berhasil dihapus.", idxplay, DP.pl[idxplay].nama);
        printf("Playlist ID %d dengan judul \"", idxplay + 1);
        printWord(DP.pl[idxplay].nama);
        printf("\" berhasil dihapus.\n");
    }
}

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
            int len = LengthQueue(QueueOriginal);
            printf("Queue:\n");
            for (i = 1; i <= len; i++)
            {
                QueueSongTypeRevisi tampil;
                dequeue(&QueueOriginal, &tampil);
                enqueue(&QueueOriginal, tampil);
                // printf("%d. %s - %s - %s", i + 1, Antrean_Lagu.penyanyi, Antrean_Lagu.album, Antrean_Lagu.judul_lagu.judul);
                printf("%d. ", i);
                printWord(tampil.penyanyi);
                printf(" - ");
                printWord(tampil.album);
                printf(" - ");
                printWord(tampil.judul_lagu);
                printf("\n");
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

    DisplayListPenyanyi(DaftarPenyanyi);
    printf("Masukkan Nama Penyanyi yang dipilih : ");
    readCommand();
    int id_penyanyi, id_album;
    CopasWord(&chosen_penyanyi, currentWord);
    id_penyanyi = SearchPenyanyi(DaftarPenyanyi, chosen_penyanyi);
    if (id_penyanyi != -1)
    {
        DisplayMap(DaftarPenyanyi, currentWord);
        printf("Masukkan Nama Album yang dipilih : ");
        readCommand();
        CopasWord(&chosen_album, currentWord);
        id_album = SearchAlbum(DaftarPenyanyi.Penyanyi[id_penyanyi], chosen_album);
        if (id_album != -1)
        {
            DisplaySet(DaftarPenyanyi.Penyanyi[id_penyanyi].album, chosen_album);
            printf("Masukkan ID Lagu yang dipilih : ");
            readCommand();
            id_chosen_lagu = *(currentWord.TabWord) - '0';
            if (id_chosen_lagu <= DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.JumlahLagu)
            {
                Word chosen_lagu;
                CopasWord(&chosen_lagu, DaftarPenyanyi.Penyanyi[id_penyanyi].album.AlbumKe[id_album].DaftarLagu.Songs[id_chosen_lagu - 1]);
                if (currentPlaySong.penyanyi.Length == 0)
                {
                    CopasWord(&currentPlaySong.penyanyi, chosen_penyanyi);
                    CopasWord(&currentPlaySong.album, chosen_album);
                    CopasWord(&currentPlaySong.judul_lagu, chosen_lagu);
                    printf("Tidak ada lagu yang diputar.\n");
                    printf("Memutar lagu yang ditambahkan ke queue, yaitu ");
                    printf("\"");
                    printWord(currentPlaySong.judul_lagu);
                    printf("\" oleh \"");
                    printWord(currentPlaySong.penyanyi);
                    printf("\".\n");
                }
                else
                {
                    QueueSongTypeRevisi Antre_Lagu;
                    // printWord(chosen_penyanyi);
                    // printWord(chosen_album);
                    // printWord(chosen_lagu);
                    // printf("%s - %s - %s", chosen_penyanyi, chosen_album, chosen_lagu);
                    CopasWord(&Antre_Lagu.penyanyi, chosen_penyanyi);
                    CopasWord(&Antre_Lagu.album, chosen_album);
                    CopasWord(&Antre_Lagu.judul_lagu, chosen_lagu);
                    enqueue(&QueueOriginal, Antre_Lagu);
                    // QueueSongTypeRevisi ngepop;
                    // dequeue(&QueueOriginal, &ngepop);
                    // printWord(ngepop.penyanyi);
                    // printWord(ngepop.album);
                    // printWord(ngepop.judul_lagu);

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
                    printf("\" kedalam antrean.\n");
                }
            }
            else
            {
                printf("Tidak ada lagu dengan ID %d\n", id_chosen_lagu);
            }
        }
        else
        {
            printf("Album tidak tersedia.\n");
        }
    }
    else
    {
        printf("Penyanyi tidak tersedia.\n");
    }
}

// masih bermasalah di linked listnya
void Queue_Playlist()
{
    int id_playlist, i;
    printf("Masukkan ID Playlist: ");
    readCommand();
    id_playlist = (*(currentWord.TabWord) - '0') - 1;
    if (id_playlist < DP.Neff)
    {
        // printf("%d", id_playlist);
        addressPlaylist p = (DP.pl[id_playlist].First);
        if (currentPlaySong.penyanyi.Length == 0)
        {
            CopasWord(&currentPlaySong.penyanyi, p->info.penyanyi);
            CopasWord(&currentPlaySong.album, p->info.album);
            CopasWord(&currentPlaySong.judul_lagu, p->info.judul_lagu);
            while (Next(p) != Nil)
            {
                p = Next(p);
                enqueue(&QueueOriginal, p->info);
            }
        }
        else
        {
            while (p != Nil)
            {
                enqueue(&QueueOriginal, p->info);
                p = Next(p);
            }
        }
        // printf("Berhasil menambahkan playlist \"%s\" ke queue.\n", DP.pl[id_playlist].nama);
        printf("Berhasil menambahkan playlist \"");
        printWord(DP.pl[id_playlist].nama);
        printf("\" ke queue.\n");
    }
    else
    {
        printf("Playlist tidak tersedia.\n");
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
    STARTCOMMAND();
    if (IsSameWord(currentWord, "Y"))
    {
        printf("Masukkan nama save file: ");
        STARTCOMMAND();
        Word filepath = currentWordNB;
        Save(DaftarPenyanyi, QueueOriginal, StackOriginal, DP, currentPlaySong, filepath);
    }
    else if (IsSameWord(currentWord, "N"))
    {
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

void Start()
{
    char StartFileName[40] = "../save/save.txt";
    STARTLINE(StartFileName);

    int jumlahPenyanyi, jumlahAlbum, jumlahLagu;
    jumlahPenyanyi = currentLine.TabLine[0] - '0'; // inisiasi jumlah penaynyi

    // CreateEmptyListPenyanyi(&DaftarPenyanyi); // ini buat inisiasi list penyanyi
    PenyanyiTypeRevisi2 currentPenyanyi; // variabel temp
    AlbumTypeRevisi2 currentAlbum;       // variabel temp
    Word currentSong;
    Word KOSONG;
    stringToWord("", &KOSONG);
    CreateQueue(&QueueOriginal);
    CreateEmptyStack(&StackOriginal);
    init_dafplay();

    int i, j, k, l, m, n;
    for (i = 0; i < jumlahPenyanyi; i++)
    {
        CopasWord(&(currentPenyanyi.nama), KOSONG);
        ADVLINE();
        jumlahAlbum = currentLine.TabLine[0] - '0';
        int x;
        x = 0;
        currentPenyanyi.nama.Length = 0;
        for (j = 2; j < currentLine.LengthLine; j++)
        {
            currentPenyanyi.nama.TabWord[j - 2] = currentLine.TabLine[j];
            currentPenyanyi.nama.Length++;
        }
        InsertPenyanyi(&DaftarPenyanyi, currentPenyanyi);

        for (m = 0; m < jumlahAlbum; m++)
        {
            ADVLINE(); // ini masuk album pertama kali untuk penyanyi ke i;
            jumlahLagu = currentLine.TabLine[0] - '0';
            currentAlbum.AlbumKe[0].NamaAlbum.Length = 0;

            for (k = 2; k < currentLine.LengthLine; k++)
            {
                currentAlbum.AlbumKe[0].NamaAlbum.TabWord[k - 2] = currentLine.TabLine[k];
                currentAlbum.AlbumKe[0].NamaAlbum.Length++;
            }
            InsertMap(&(DaftarPenyanyi.Penyanyi[i].album), currentAlbum.AlbumKe[0].NamaAlbum);

            for (l = 0; l < jumlahLagu; l++)
            {

                ADVLINE();
                currentSong.Length = 0;

                for (n = 0; n < currentLine.LengthLine; n++)
                {
                    currentSong.TabWord[n] = currentLine.TabLine[n];
                    currentSong.Length++;
                }
                InsertSet(currentSong, &(DaftarPenyanyi.Penyanyi[i].album), currentAlbum.AlbumKe[0].NamaAlbum);
            }
        }
    }
    printf("File konfigurasi aplikasi berhasil dibaca. WayangWave berhasil dijalankan.\n");

    sesi = true;
}

// ini buat load
void load_playlist_create(DaftarPlaylist *depe, Word nama)
{
    if (DP.Neff >= DP.Capacity)
        realloc_dafplay(DP);
    CopasWord(&((*depe).pl[DP.Neff].nama), nama);
    First(DP.pl[DP.Neff]) = Nil;
    DP.Neff++;
}

void load_playlistsong(DaftarPlaylist *depe, ListPenyanyiRevisi *LP, Word penyanyi, Word album, Word judul, int idxplay)
{
    int idxp = 0, idxa = 0, idxl = 0;
    boolean foundp = false, founda = false, foundl = false;
    while (!foundp && idxp < penyanyimax)
    {
        if (IsDuplicateWord((*LP).Penyanyi[idxp].nama, penyanyi))
        {
            foundp = true;
        }
        else
            idxp++;
    }
    while (!founda && idxa < (*LP).Penyanyi[idxp].album.JumlahAlbum)
    {
        if (IsDuplicateWord((*LP).Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum, album))
        {
            founda = true;
        }
        else
            idxa++;
    }
    while (!foundl && idxl < (*LP).Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.JumlahLagu)
    {
        if (IsDuplicateWord((*LP).Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl], judul))
        {
            foundl = true;
        }
        else
            idxl++;
    }
    QueueSongTypeRevisi P;
    P.penyanyi = (*LP).Penyanyi[idxp].nama;
    P.album = (*LP).Penyanyi[idxp].album.AlbumKe[idxa].NamaAlbum;
    P.judul_lagu = (*LP).Penyanyi[idxp].album.AlbumKe[idxa].DaftarLagu.Songs[idxl];
    InsVLast(&((*depe).pl[idxplay]), P);
}

// // ------------------------------------------------------------
void Load()
{
    char LoadFileName[40];
    printf("Masukkan nama file: ");
    readCommand();
    WordToString(currentWord, LoadFileName);
    STARTLINE(LoadFileName);

    boolean IsComplete = false;

    int jumlahPenyanyi, jumlahAlbum, jumlahLagu;
    jumlahPenyanyi = currentLine.TabLine[0] - '0'; // inisiasi jumlah penaynyi

    CreateEmptyListPenyanyi(&DaftarPenyanyi); // ini buat inisiasi list penyanyi
    init_dafplay();
    // CreateEmptyDaftarPlaylist(&DP);
    // init_dafplay();

    PenyanyiTypeRevisi2 currentPenyanyi; // variabel temp
    AlbumTypeRevisi2 currentAlbum;       // variabel temp
    Word currentSong;
    Word KOSONG;
    stringToWord("", &KOSONG);
    CreateQueue(&QueueOriginal);
    CreateEmptyStack(&StackOriginal);

    int i, j, k, l, m, n;
    for (i = 0; i < jumlahPenyanyi; i++)
    {
        CopasWord(&(currentPenyanyi.nama), KOSONG);
        ADVLINE();
        jumlahAlbum = currentLine.TabLine[0] - '0';
        int x;
        x = 0;
        currentPenyanyi.nama.Length = 0;
        for (j = 2; j < currentLine.LengthLine; j++)
        {
            currentPenyanyi.nama.TabWord[j - 2] = currentLine.TabLine[j];
            currentPenyanyi.nama.Length++;
        }
        InsertPenyanyi(&DaftarPenyanyi, currentPenyanyi);

        for (m = 0; m < jumlahAlbum; m++)
        {
            ADVLINE(); // ini masuk album pertama kali untuk penyanyi ke i;
            jumlahLagu = currentLine.TabLine[0] - '0';
            currentAlbum.AlbumKe[0].NamaAlbum.Length = 0;

            for (k = 2; k < currentLine.LengthLine; k++)
            {
                currentAlbum.AlbumKe[0].NamaAlbum.TabWord[k - 2] = currentLine.TabLine[k];
                currentAlbum.AlbumKe[0].NamaAlbum.Length++;
            }
            InsertMap(&(DaftarPenyanyi.Penyanyi[i].album), currentAlbum.AlbumKe[0].NamaAlbum);

            for (l = 0; l < jumlahLagu; l++)
            {

                ADVLINE();
                currentSong.Length = 0;

                for (n = 0; n < currentLine.LengthLine; n++)
                {
                    currentSong.TabWord[n] = currentLine.TabLine[n];
                    currentSong.Length++;
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
        currentPlaySong.penyanyi.Length = 0;

        while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
        {
            currentPlaySong.penyanyi.TabWord[idxHurufPenyanyi] = currentLine.TabLine[idxHuruf];
            currentPlaySong.penyanyi.Length++;
            idxHurufPenyanyi++;
            idxHuruf++;
        }
        idxHuruf++; // lanjut setelah semicolon

        currentPlaySong.album.Length = 0;
        while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
        {
            currentPlaySong.album.TabWord[idxHurufAlbum] = currentLine.TabLine[idxHuruf];
            currentPlaySong.album.Length++;
            idxHurufAlbum++;
            idxHuruf++;
        }
        idxHuruf++; // lanjut setelah semicolon

        currentPlaySong.judul_lagu.Length = 0;
        for (idxHurufLagu = 0; idxHuruf < currentLine.LengthLine; idxHurufLagu++)
        {
            currentPlaySong.judul_lagu.TabWord[idxHurufLagu] = currentLine.TabLine[idxHuruf];
            currentPlaySong.judul_lagu.Length++;
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
            tempQST.penyanyi.Length = 0;
            while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
            {
                tempQST.penyanyi.TabWord[idxHurufPenyanyi] = currentLine.TabLine[idxHuruf];
                tempQST.penyanyi.Length++;
                idxHurufPenyanyi++;
                idxHuruf++;
            }
            idxHuruf++; // lanjut setelah semicolon
            tempQST.album.Length = 0;
            while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
            {
                tempQST.album.TabWord[idxHurufAlbum] = currentLine.TabLine[idxHuruf];
                tempQST.album.Length++;
                idxHurufAlbum++;
                idxHuruf++;
            }
            idxHuruf++; // lanjut setelah semicolon
            tempQST.judul_lagu.Length = 0;
            for (idxHurufLagu = 0; idxHuruf < currentLine.LengthLine; idxHurufLagu++)
            {
                tempQST.judul_lagu.TabWord[idxHurufLagu] = currentLine.TabLine[idxHuruf];
                tempQST.judul_lagu.Length++;
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
            tempSST.penyanyi.Length = 0;
            while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
            {
                tempSST.penyanyi.TabWord[idxHurufPenyanyi] = currentLine.TabLine[idxHuruf];
                tempSST.penyanyi.Length++;
                idxHurufPenyanyi++;
                idxHuruf++;
            }
            idxHuruf++; // lanjut setelah semicolon
            tempSST.album.Length = 0;
            while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
            {
                tempSST.album.TabWord[idxHurufAlbum] = currentLine.TabLine[idxHuruf];
                tempSST.album.Length++;
                idxHurufAlbum++;
                idxHuruf++;
            }
            idxHuruf++; // lanjut setelah semicolon
            tempSST.judul_lagu.Length = 0;
            for (idxHurufLagu = 0; idxHuruf < currentLine.LengthLine; idxHurufLagu++)
            {
                tempSST.judul_lagu.TabWord[idxHurufLagu] = currentLine.TabLine[idxHuruf];
                tempSST.judul_lagu.Length++;
                idxHuruf++;
            }
            Push(&StackOriginal, tempSST);
            ADVLINE();
        }
        ReverseStack(&StackOriginal);
    }
    // akhir dari baris stack, lanjut ke baris playlist jika ada
    if (IsSameChar(currentLine.TabLine[0], '0'))
    {
        // ga ngapain" kosong
    }
    else
    {
        int jumlahPlaylist;
        jumlahPlaylist = currentLine.TabLine[0] - '0';
        int indexPlaylist;
        int jumlahLaguPlaylist;
        int indexLaguPL;
        infoType isipltemp;
        Word namaPL;
        Word namaPenyanyiPL;
        Word namaAlbumPL;
        Word namaLaguPL;

        for (indexPlaylist = 0; indexPlaylist < jumlahPlaylist; indexPlaylist++)
        {
            ADVLINE();
            jumlahLaguPlaylist = currentLine.TabLine[0] - '0';
            namaPL.Length = 0;
            for (int x = 2; x < currentLine.LengthLine; x++)
            {
                namaPL.TabWord[x - 2] = currentLine.TabLine[x];
                namaPL.Length++;
            }
            load_playlist_create(&DP, namaPL);
            for (indexLaguPL = 0; indexLaguPL < jumlahLaguPlaylist; indexLaguPL++)
            {
                ADVLINE();
                idxHuruf = 0;
                idxHurufPenyanyi = 0;
                idxHurufAlbum = 0;
                idxHurufLagu = 0;

                namaPenyanyiPL.Length = 0;
                namaAlbumPL.Length = 0;
                namaLaguPL.Length = 0;
                while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
                {
                    namaPenyanyiPL.TabWord[idxHurufPenyanyi] = currentLine.TabLine[idxHuruf];
                    namaPenyanyiPL.Length++;
                    idxHurufPenyanyi++;
                    idxHuruf++;
                }
                idxHuruf++; // lanjut setelah semicolon
                while (!IsSameChar(currentLine.TabLine[idxHuruf], ';'))
                {
                    namaAlbumPL.TabWord[idxHurufAlbum] = currentLine.TabLine[idxHuruf];
                    namaAlbumPL.Length++;
                    idxHurufAlbum++;
                    idxHuruf++;
                }
                idxHuruf++; // lanjut setelah semicolon
                for (idxHurufLagu = 0; idxHuruf < currentLine.LengthLine; idxHurufLagu++)
                {
                    namaLaguPL.TabWord[idxHurufLagu] = currentLine.TabLine[idxHuruf];
                    namaLaguPL.Length++;
                    idxHuruf++;
                }
                load_playlistsong(&DP, &DaftarPenyanyi, namaPenyanyiPL, namaAlbumPL, namaLaguPL, indexPlaylist);
            }
        }
        // ADVLINE();
    }

    sesi = true;
}

void ListDefault(ListPenyanyiRevisi L)
{

    DisplayListPenyanyi(L);
    printf("Ingin melihat album yang ada? (Y/N): ");
    readCommand();
    Word namaPenyanyi;
    Word namaAlbum;
    int idxPenyanyi;
    if (IsSameWord(currentWord, "Y"))
    {
        printf("Pilih penyanyi untuk melihat album mereka:\n");
        readCommand();
        CopasWord(&namaPenyanyi, currentWord);
        idxPenyanyi = SearchPenyanyi(L, namaPenyanyi);
        while (idxPenyanyi == -1)
        {
            printf("Tidak ada Penyanyi dengan nama tersebut\n");
            DisplayListPenyanyi(L);
            printf("Masukkan kembali nama penyanyi: ");
            readCommand();
            CopasWord(&namaPenyanyi, currentWord);
            idxPenyanyi = SearchPenyanyi(L, namaPenyanyi);
        }
        DisplayMap(L, namaPenyanyi);

        printf("Ingin melihat lagu yang ada? (Y/N): ");
        readCommand();
        if (IsSameWord(currentWord, "Y"))
        {
            printf("Pilih nama album dari penyanyi tersebut: ");
            readCommand();
            CopasWord(&namaAlbum, currentWord);
            int idxAlbum = SearchAlbum(L.Penyanyi[idxPenyanyi], namaAlbum);
            while (idxAlbum == -1)
            {
                printf("Tidak ada Album dengan nama tersebut\n");
                DisplayMap(L, namaPenyanyi);

                printf("Masukkan kembali nama album:");
                readCommand();
                CopasWord(&namaAlbum, currentWord);
                idxAlbum = SearchAlbum(L.Penyanyi[idxPenyanyi], namaAlbum);
            }
            DisplaySet(L.Penyanyi[idxPenyanyi].album, namaAlbum);
        }
        else
        {
            return;
        }
    }
    else if (IsSameWord(currentWord, "N"))
    {
        return;
    }
}

void Save(ListPenyanyiRevisi L, QueueRevisi Q, StackRevisi S, DaftarPlaylist D, QueueSongTypeRevisi CPS, Word filepath)
{
    FILE *fptr; // inisisasi file
    char dir[40] = "../save/";
    char saveFilePath[40];

    Word dirW;
    Word savefilepathW;
    // Word savefilenameW;

    stringToWord(dir, &(dirW));
    CopasWord(&savefilepathW, dirW);

    char saveFileName[30];
    // printf("Masukkan nama save file: ");
    // readCommand();
    // CopasWord(&(savefilenameW), currentWord);

    // wordConcat(&(savefilepathW), savefilenameW);
    wordConcat(&(savefilepathW), filepath);
    WordToString(savefilepathW, saveFilePath);

    // scanf("%s", saveFileName);
    fptr = fopen(saveFilePath, "w");

    QueueRevisi QueueTemp; // mulai prosedur save queue
    // CreateQueue(&QueueTemp);
    CopyQueue(Q, &QueueTemp);
    QueueSongTypeRevisi qstQTemp;
    int jumlahQueue;

    // nge save jumlah penyanyi;
    fprintf(fptr, "%d\n", L.JumlahPenyanyi);

    // nge save album per penyanyi;
    int i, j, k, l;
    int countPenyanyi;
    int countAlbum;
    int countLagu;
    countPenyanyi = L.JumlahPenyanyi;

    for (i = 0; i < countPenyanyi; i++)
    {
        fprintf(fptr, "%d ", L.Penyanyi[i].album.JumlahAlbum);
        FPRINTWORD(fptr, L.Penyanyi[i].nama);
        fprintf(fptr, "\n");
        countAlbum = L.Penyanyi[i].album.JumlahAlbum;
        for (j = 0; j < countAlbum; j++)
        {
            fprintf(fptr, "%d ", L.Penyanyi[i].album.AlbumKe[j].DaftarLagu.JumlahLagu);
            countLagu = L.Penyanyi[i].album.AlbumKe[j].DaftarLagu.JumlahLagu;
            FPRINTWORD(fptr, L.Penyanyi[i].album.AlbumKe[j].NamaAlbum);
            fprintf(fptr, "\n");
            for (k = 0; k < countLagu; k++)
            {
                FPRINTWORD(fptr, L.Penyanyi[i].album.AlbumKe[j].DaftarLagu.Songs[k]);
                fprintf(fptr, "\n");
            }
        }
    }

    // ini buat nge save currentPlaySongs
    if (currentPlaySong.penyanyi.Length != 0)
    {
        FPRINTWORD(fptr, CPS.penyanyi);
        fprintf(fptr, ";");
        FPRINTWORD(fptr, CPS.album);
        fprintf(fptr, ";");
        FPRINTWORD(fptr, CPS.judul_lagu);
        fprintf(fptr, "\n");
    }
    else
    {
        fprintf(fptr, "-\n");
    }

    if (!IsEmptyQueue(Q))
    {
        jumlahQueue = LengthQueue(QueueTemp);
        fprintf(fptr, "%d\n", jumlahQueue);
        for (i = 0; i < LengthQueue(Q); i++)
        {
            qstQTemp.penyanyi.Length = 0;
            qstQTemp.album.Length = 0;
            qstQTemp.judul_lagu.Length = 0;
            dequeue(&QueueTemp, &qstQTemp);

            for (int x = 0; x < qstQTemp.penyanyi.Length; x++)
            {
                if (x == qstQTemp.penyanyi.Length - 1)
                {
                    fprintf(fptr, "%c;", qstQTemp.penyanyi.TabWord[x]);
                    break;
                }
                fprintf(fptr, "%c", qstQTemp.penyanyi.TabWord[x]);
            }
            for (int y = 0; y < qstQTemp.album.Length; y++)
            {
                if (y == qstQTemp.album.Length - 1)
                {
                    fprintf(fptr, "%c;", qstQTemp.album.TabWord[y]);
                    break;
                }
                fprintf(fptr, "%c", qstQTemp.album.TabWord[y]);
            }
            for (int z = 0; z < qstQTemp.judul_lagu.Length; z++)
            {
                if (z == qstQTemp.judul_lagu.Length - 1)
                {
                    fprintf(fptr, "%c\n", qstQTemp.judul_lagu.TabWord[z]);
                    break;
                }
                fprintf(fptr, "%c", qstQTemp.judul_lagu.TabWord[z]);
            }
        }
    }
    else
    {
        fprintf(fptr, "0\n");
    }

    StackRevisi StackTemp; // mulai prosedur save stack
    CreateEmptyStack(&StackTemp);
    CopyStack(S, &StackTemp);
    QueueSongTypeRevisi qstSTemp;
    int jumlahStack;

    if (!IsEmptyStack(S))
    {
        jumlahStack = lengthStack(StackTemp);
        fprintf(fptr, "%d\n", jumlahStack);
        for (i = 0; i < lengthStack(S); i++)
        {
            qstSTemp.penyanyi.Length = 0;
            qstSTemp.album.Length = 0;
            qstSTemp.judul_lagu.Length = 0;
            Pop(&StackTemp, &qstSTemp);
            for (int a = 0; qstSTemp.penyanyi.Length; a++)
            {
                if (a == qstSTemp.penyanyi.Length - 1)
                {
                    fprintf(fptr, "%c;", qstSTemp.penyanyi.TabWord[a]);
                    break;
                }
                fprintf(fptr, "%c", qstSTemp.penyanyi.TabWord[a]);
            }
            for (int b = 0; qstSTemp.album.Length; b++)
            {
                if (b == qstSTemp.album.Length - 1)
                {
                    fprintf(fptr, "%c;", qstSTemp.album.TabWord[b]);
                    break;
                }
                fprintf(fptr, "%c", qstSTemp.album.TabWord[b]);
            }
            for (int c = 0; qstSTemp.judul_lagu.Length; c++)
            {
                if (c == qstSTemp.judul_lagu.Length - 1)
                {
                    fprintf(fptr, "%c\n", qstSTemp.judul_lagu.TabWord[c]);
                    break;
                }
                fprintf(fptr, "%c", qstSTemp.judul_lagu.TabWord[c]);
            }
        }
    }
    else
    {
        fprintf(fptr, "0\n");
    }
    if (D.Neff == 0)
    {
        fprintf(fptr, "%d\n", D.Neff);
    }
    else
    {
        fprintf(fptr, "%d\n", D.Neff);
        int countPlaylist = D.Neff;
        int idxPlaylist;
        int countPlaylistSong;
        addressPlaylist P1;
        addressPlaylist P2;
        for (idxPlaylist = 0; idxPlaylist < countPlaylist; idxPlaylist++)
        {
            countPlaylistSong = 0;
            P1 = D.pl[idxPlaylist].First;
            while (P1 != Nil)
            {
                countPlaylistSong++;
                P1 = P1->next;
            }
            fprintf(fptr, "%d ", countPlaylistSong);
            FPRINTWORD(fptr, D.pl[idxPlaylist].nama);
            fprintf(fptr, "\n");
            if (countPlaylistSong != 0)
            {
                P1 = D.pl[idxPlaylist].First;
                while (P1 != Nil)
                {
                    FPRINTWORD(fptr, P1->info.penyanyi);
                    fprintf(fptr, ";");
                    FPRINTWORD(fptr, P1->info.album);
                    fprintf(fptr, ";");
                    FPRINTWORD(fptr, P1->info.judul_lagu);
                    fprintf(fptr, "\n");
                    P1 = P1->next;
                }
            }
            else
            {
            }
        }
    }
    fclose(fptr);
}

void invalid_command()
{
    boolean error = false;
    boolean invalid = false;
    Word First_Word = SentenceToWord(currentWord, 0);

    if (!sesi)
    {
        if (IsSameWord(First_Word, "LIST"))
        {
            Word Second_Word = SentenceToWord(currentWord, 1);
            if (IsSameWord(Second_Word, "DEFAULT"))
            {
                error = true;
            }
            else if (IsSameWord(Second_Word, "PLAYLIST"))
            {
                error = true;
            }
        }
        else if (IsSameWord(First_Word, "PLAY"))
        {
            Word Second_Word = SentenceToWord(currentWord, 1);
            if (IsSameWord(Second_Word, "SONG"))
            {
                error = true;
            }
            else if (IsSameWord(Second_Word, "PLAYLIST"))
            {
                error = true;
            }
        }
        else if (IsSameWord(First_Word, "QUEUE"))
        {
            Word Second_Word = SentenceToWord(currentWord, 1);
            if (IsSameWord(Second_Word, "SONG"))
            {
                error = true;
            }
            else if (IsSameWord(Second_Word, "PLAYLIST"))
            {
                error = true;
            }
            else if (IsSameWord(Second_Word, "SWAP"))
            {
                error = true;
            }
            else if (IsSameWord(Second_Word, "REMOVE"))
            {
                error = true;
            }
            else if (IsSameWord(Second_Word, "CLEAR"))
            {
                error = true;
            }
        }
        else if (IsSameWord(First_Word, "SONG"))
        {
            Word Second_Word = SentenceToWord(currentWord, 1);
            if (IsSameWord(Second_Word, "NEXT"))
            {
                error = true;
            }
            else if (IsSameWord(Second_Word, "PREVIOUS"))
            {
                error = true;
            }
        }
        else if (IsSameWord(First_Word, "PLAYLIST"))
        {
            Word Second_Word = SentenceToWord(currentWord, 1);
            if (IsSameWord(Second_Word, "CREATE"))
            {
                error = true;
            }
            else if (IsSameWord(Second_Word, "ADD"))
            {
                Word Third_Word = SentenceToWord(currentWord, 2);
                if (IsSameWord(Third_Word, "SONG"))
                {
                    error = true;
                }
                else if (IsSameWord(Third_Word, "ALBUM"))
                {
                    error = true;
                }
            }
            else if (IsSameWord(Second_Word, "SWAP"))
            {
                error = true;
            }
            else if (IsSameWord(Second_Word, "REMOVE"))
            {
                error = true;
            }
            else if (IsSameWord(Second_Word, "DELETE"))
            {
                error = true;
            }
        }
        else if (IsSameWord(First_Word, "STATUS"))
        {
            error = true;
        }
        else if (IsSameWord(First_Word, "SAVE"))
        {
            error = true;
        }
        else if (IsSameWord(First_Word, "HELP"))
        {
            error = true;
        }
        else if (IsSameWord(First_Word, "QUIT"))
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
        if (IsSameWord(First_Word, "START"))
        {
            error = true;
        }
        else if (IsSameWord(First_Word, "LOAD"))
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
        printf("Command tidak diketahui!\n");
    }
    else if (error)
    {
        printf("Command tidak bisa dieksekusi!\n");
    }
}

void cmd_user()
{
    art_WayangWave();
    while (mulai)
    {
        printf(">> ");
        readCommand();
        Word First_Word = SentenceToWord(currentWord, 0);

        if (sesi)
        {
            if (IsSameWord(First_Word, "LIST"))
            {
                Word Second_Word = SentenceToWord(currentWord, 1);
                if (IsSameWord(Second_Word, "DEFAULT"))
                {
                    ListDefault(DaftarPenyanyi);
                }
                else if (IsSameWord(Second_Word, "PLAYLIST"))
                {
                    list_playlist(DP);
                }
            }
            else if (IsSameWord(First_Word, "PLAY"))
            {
                Word Second_Word = SentenceToWord(currentWord, 1);
                if (IsSameWord(Second_Word, "SONG"))
                {
                    Play_Song();
                }
                else if (IsSameWord(Second_Word, "PLAYLIST"))
                {
                    Play_Playlist();
                }
            }
            else if (IsSameWord(First_Word, "QUEUE"))
            {
                Word Second_Word = SentenceToWord(currentWord, 1);
                if (IsSameWord(Second_Word, "SONG"))
                {
                    Queue_Song();
                }
                else if (IsSameWord(Second_Word, "PLAYLIST"))
                {
                    Queue_Playlist();
                }
                else if (IsSameWord(Second_Word, "SWAP"))
                {
                    Word Third_Word = SentenceToWord(currentWord, 2);
                    int x = *(Third_Word.TabWord) - '0';
                    Word Fourth_Word = SentenceToWord(currentWord, 3);
                    int y = *(Fourth_Word.TabWord) - '0';
                    Queue_Swap(x, y);
                }
                else if (IsSameWord(Second_Word, "REMOVE"))
                {
                    Word Third_Word = SentenceToWord(currentWord, 2);
                    int x = *(Third_Word.TabWord) - '0';
                    Queue_Remove(x);
                }
                else if (IsSameWord(Second_Word, "CLEAR"))
                {
                    Queue_Clear();
                }
            }
            else if (IsSameWord(First_Word, "SONG"))
            {
                Word Second_Word = SentenceToWord(currentWord, 1);
                if (IsSameWord(Second_Word, "NEXT"))
                {
                    Song_Next();
                }
                else if (IsSameWord(Second_Word, "PREVIOUS"))
                {
                    Song_Previous();
                }
            }
            else if (IsSameWord(First_Word, "PLAYLIST"))
            {
                Word Second_Word = SentenceToWord(currentWord, 1);
                if (IsSameWord(Second_Word, "CREATE"))
                {
                    playlist_create();
                }
                else if (IsSameWord(Second_Word, "ADD"))
                {
                    Word Third_Word = SentenceToWord(currentWord, 2);
                    if (IsSameWord(Third_Word, "SONG"))
                    {
                        playlist_add_song(&DP, &DaftarPenyanyi);
                    }
                    else if (IsSameWord(Third_Word, "ALBUM"))
                    {
                        playlist_add_album(&DP, &DaftarPenyanyi);
                    }
                }
                else if (IsSameWord(Second_Word, "SWAP"))
                {
                    Word Third_Word = SentenceToWord(currentWord, 2);
                    int id = *(Third_Word.TabWord) - '0';
                    Word Fourth_Word = SentenceToWord(currentWord, 3);
                    int x = *(Fourth_Word.TabWord) - '0';
                    Word Fifth_Word = SentenceToWord(currentWord, 4);
                    int y = *(Fifth_Word.TabWord) - '0';
                    playlist_swap(id, x, y);
                }
                else if (IsSameWord(Second_Word, "REMOVE"))
                {
                    Word Third_Word = SentenceToWord(currentWord, 2);
                    int id = *(Third_Word.TabWord) - '0';
                    Word Fourth_Word = SentenceToWord(currentWord, 3);
                    int x = *(Fourth_Word.TabWord) - '0';
                    playlist_removesong(id, x);
                }
                else if (IsSameWord(Second_Word, "DELETE"))
                {
                    playlist_delete();
                }
            }
            else if (IsSameWord(First_Word, "STATUS"))
            {
                Status();
            }
            else if (IsSameWord(First_Word, "SAVE"))
            {
                Word Second_Word = SentenceToWord(currentWord, 1);
                Word filepath = Second_Word;
                Save(DaftarPenyanyi, QueueOriginal, StackOriginal, DP, currentPlaySong, filepath);
            }
            else if (IsSameWord(First_Word, "HELP"))
            {
                help();
            }
            else if (IsSameWord(First_Word, "QUIT"))
            {
                quit();
            }
            else
            {
                invalid_command();
            }
        }
        else
        {
            if (IsSameWord(First_Word, "QUIT"))
            {
                quit();
            }
            else if (IsSameWord(First_Word, "START"))
            {
                Start();
            }
            else if (IsSameWord(First_Word, "LOAD"))
            {
                Load();
            }
            else if (IsSameWord(First_Word, "HELP"))
            {
                help();
            }
            else if (IsSameWord(First_Word, "TESTING"))
            {
                printf("INI NGE TEST\n");
            }
            else
            {
                invalid_command();
            }
        }
    }
}