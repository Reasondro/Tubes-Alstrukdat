#include <stdio.h>
#include "ADT\Queue\queue.h"
#include "ADT\Stack\stack.h"
#include "ADT\LinkedList\listlinier.h"

void song_next (Queue *q,Stack *s);

void song_previous(Queue *q, Stack *s);

void play_song(Queue *q, Stack *s, QueueSongType song);

void play_playlist(Queue *q, Stack *s);//nunggu linked list;

void playlist_create(List *L);

void playlist_add_song(List *L);