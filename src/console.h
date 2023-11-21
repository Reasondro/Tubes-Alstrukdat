#include <stdio.h>
#include "ADT/Queue/queue.h"
#include "ADT/Setmap-TEMPORER/SETMAP.h"
#include "ADT/Stack/stack.h"
#include "ADT/LinkedList/listlinier.h"
#include "ADT/MesinKarakter_MesinKata/mesinkata.h"

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

void Queue_Remove(int id);

void Queue_Clear();

void playlist_create();

void playlist_add_song();

void playlist_add_album();

void Save();

void Status();

void AddtoPlayList(Playlist *pl, QueueSongType song);
