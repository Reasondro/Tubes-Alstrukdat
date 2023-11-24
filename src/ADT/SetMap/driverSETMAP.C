#include "SETMAP.c"
#include <stdio.h>
#include "boolean.h"
// #include "mesinkarakter.c" // non comment hanya klao mo test
// #include "mesinkata.c"
int main() // non commaand klao mo test aja
{

    AlbumTypeRevisi Album;
    CreateEmptyMap(&Album);

    keytype NamaAlbum1;
    char Album1[25] = "2001 by Dre";
    stringCopy(NamaAlbum1, Album1);

    keytype NamaAlbum2;
    char Album2[25] = "Beat it by MJ";
    stringCopy(NamaAlbum2, Album2);

    keytype NamaAlbum3;
    char Album3[25] = "HALO PAPUA";
    stringCopy(NamaAlbum3, Album3);

    InsertMap(&Album, NamaAlbum1);
    InsertMap(&Album, NamaAlbum2);
    // InsertMap(&Album, NamaAlbum3);

    SongType Song1;
    char lagu1[15] = "The Watcher";
    stringCopy(Song1.judul, lagu1);

    SongType Song2;
    char lagu2[15] = "F*ck You";
    stringCopy(Song2.judul, lagu2);

    SongType Song3;
    char lagu3[15] = "Thriller";
    stringCopy(Song3.judul, lagu3);

    SongType Song4;
    char lagu4[15] = "Billie Jean";
    stringCopy(Song4.judul, lagu4);

    InsertSet(Song1, &Album, NamaAlbum1);
    InsertSet(Song2, &Album, NamaAlbum1);
    InsertSet(Song3, &Album, NamaAlbum2);
    InsertSet(Song4, &Album, NamaAlbum2);

    DisplayMap(Album);
    DisplaySet(Album, NamaAlbum1);
    DisplaySet(Album, NamaAlbum2);

    return 0;
}
