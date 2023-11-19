#include <stdio.h>
#include "ADT\Queue\queue.h"
#include "ADT\Stack\stack.h"
#include "ADT\LinkedList\listlinier.h"
#include "ADT\MesinKarakter_MesinKata\mesinkata.h"

void song_next (Queue *q,Stack *s);

void song_previous(Queue *q, Stack *s);

void play_song(Queue *q, Stack *s);

void play_playlist(Queue *q, Stack *s);

void Save();

void playlist_create();

void playlist_add_song();

void playlist_add_album();

void AddtoPlayList(Playlist *pl, QueueSongType song);