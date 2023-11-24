#include <stdio.h>
#include "ADT/Stack/stack.h"
#include "ADT/List/list.h"
#include "ADT/Setmap-TEMPORER/SETMAP.h"
#include "ADT/Queue/queue.h"
#include "ADT/LinkedList/listlinier.h"
#include "ADT/MesinKarakter_MesinKata/mesinkata.h"
#include "ADT/struct.h"

void cmd_user();

void list_default();

void list_playlist();

void Song_Next ();

void Song_Previous();

void Play_Song();

void Play_Playlist();

void Queue_Song();

void Queue_Playlist();

void Queue_Swap(int x, int y);

void playlistalbum(DaftarPlaylist *depe, ListPenyanyiRevisi *LP, int idxp, int idxa, int idxplay);

void Queue_Remove(int id);

void Queue_Clear();

void playlist_create();

void playlist_add_song(DaftarPlaylist *depe, ListPenyanyiRevisi *DaftarPenyanyi);

void playlistsong(DaftarPlaylist *depe, ListPenyanyiRevisi *LP, int idxp, int idxa, int idxl, int idxplay);

void playlist_add_album(DaftarPlaylist *depe, ListPenyanyiRevisi *DaftarPenyanyi);

void playlistalbum(DaftarPlaylist *depe, ListPenyanyiRevisi *LP, int idxp, int idxa, int idxplay);

void playlist_swap(int idxplay, int idxl1, int idxl2);

void Save();

void Status();

