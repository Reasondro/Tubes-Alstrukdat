#include <stdio.h>
#include "queue.h"
#include "../../boolean.h"
#include "../struct.h"
#include <string.h>

/* *** Kreator *** */
void CreateQueue(Queue *q)
{
    /* I.S. sembarang */
    /* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
    /* - Index head bernilai IDX_UNDEF */
    /* - Index tail bernilai IDX_UNDEF */
    /* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmptyQueue(Queue q)
{
    /* Mengirim true jika q kosong: lihat definisi di atas */
    return (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF);
}
boolean isFullQueue(Queue q)
{
    /* Mengirim true jika tabel penampung elemen q sudah penuh */
    /* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
    if (IDX_TAIL(q) == CAPACITY - 1)
    {
        return (IDX_HEAD(q) == 0);
    }
    else
    {
        return (IDX_HEAD(q) - 1 == IDX_TAIL(q));
    }
}
int lengthQueue(Queue q)
{
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    if (IDX_HEAD(q) <= IDX_TAIL(q))
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
    }
    else
    {
        if (isEmptyQueue(q))
        {
            return 0;
        }
        else
        {
            return (CAPACITY - IDX_HEAD(q) + IDX_TAIL(q) + 1);
        }
    }
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, QueueSongType val)
{
    /* Proses: Menambahkan val pada q dengan aturan FIFO */
    /* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
    /* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
    if (isEmptyQueue(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        if (IDX_TAIL(*q) == CAPACITY - 1)
        {
            IDX_TAIL(*q) = 0;
        }
        else
        {
            IDX_TAIL(*q)
            ++;
        }
    }
    // Penyanyi_Head(*q) = val.penyanyi;  // ini yang sebelumny ga dipake gara" sekarang kita make string bukan char
    stringCopy(Penyanyi_Tail(*q), val.penyanyi); // jadi harus strcpy buat nerima input string
    // Album_Tail(*q) = val.album; // sama kaya di atas
    stringCopy(Album_Tail(*q), val.album); // fix sama kaya di atas
    // Judul_Lagu_Tail(*q) = val.judul_lagu; //
    stringCopy(Judul_Lagu_Tail(*q), val.judul_lagu); // fix sama kaya di atas
}
void dequeue(Queue *q, QueueSongType *val)
{
    /* Proses: Menghapus val pada q dengan aturan FIFO */
    /* I.S. q tidak mungkin kosong */
    /* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
            q mungkin kosong */

    // (*val).penyanyi = Penyanyi_Head(*q); // ini yang sebelumny ga dipake gara" sekarang kita make string bukan char
    stringCopy((*val).penyanyi, Penyanyi_Head(*q)); // jadi harus strcpy buat nerima input string
    // (*val).album = Album_Head(*q);
    stringCopy((*val).album, Album_Head(*q)); // fix sama kaya di atas
    // (*val).judul_lagu = Judul_Lagu_Head(*q);
    stringCopy((*val).judul_lagu, Judul_Lagu_Head(*q)); // fix sama kaya di atas

    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        if (IDX_HEAD(*q) == CAPACITY - 1)
        {
            IDX_HEAD(*q) = 0;
        }
        else
        {
            IDX_HEAD(*q)
            ++;
        }
    }
}

// Display queue belom diganti

/* *** Display Queue *** */
void displayQueue(Queue q)
{
    /* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
       siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
       karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. q boleh kosong */
    /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika Queue kosong : menulis [] */
    if (isEmptyQueue(q))
    {
        printf("[]");
    }
    else
    {
        int i = IDX_HEAD(q);
        // printf("[");
        for (i = IDX_HEAD(q); i < (IDX_HEAD(q) + lengthQueue(q) - 1); i++)
        {
            printf("%s;", q.buffer[i % CAPACITY].penyanyi);
            printf("%s;", q.buffer[i % CAPACITY].album);
            printf("%s\n", q.buffer[i % CAPACITY].judul_lagu);
        }
        printf("%s;", q.buffer[i % CAPACITY].penyanyi);
        printf("%s;", q.buffer[i % CAPACITY].album);
        printf("%s\n", q.buffer[i % CAPACITY].judul_lagu);
    }
}

void CopyQueue(Queue qIn, Queue *qOut)
{
    /* I.S. qIn terdefinisi, qOut sembarang */
    /* F.S. qOut berisi salinan dari qIn (identik) */
    /* Proses : Menyalin isi qIn ke qOut */

    CreateQueue(qOut);

    QueueSongType temp;
    int length = lengthQueue(qIn);

    for (int i = 0; i < length; i++)
    {

        dequeue(&qIn, &temp);
        enqueue(qOut, temp);
        enqueue(&qIn, temp);
    }
}