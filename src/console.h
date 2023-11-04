#include <stdio.h>
#include "queue.h"
#include "stack.h"

void song_next (Queue *q,Stack *s);

void song_previous(Queue *q, Stack *s);

void play_song(Queue *q, Stack *s, QueueSongType song);

void play_playlist(Queue *q, Stack *s);//nunggu linked list;