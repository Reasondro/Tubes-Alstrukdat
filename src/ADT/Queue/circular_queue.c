#include "circular_queue.h"
#include "boolean.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *Q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD(*Q) = IDX_UNDEF;
    IDX_TAIL(*Q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean IsEmpty(Queue Q)
/* Mengirim true jika q kosong: lihat definisi di atas */
{
    return ( IDX_HEAD(Q) == IDX_UNDEF && IDX_TAIL(Q) == IDX_UNDEF );
}
boolean IsFull(Queue Q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam Tab melingkar*/
{
    if (IDX_HEAD(Q) == 0) {
        return (IDX_TAIL(Q) == 99);
    } else {
        return (IDX_TAIL(Q) == IDX_HEAD(Q)-1);
    }
}

int Length(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (IsEmpty(Q)){
        return 0;
    }else{
        if (IDX_HEAD (Q) <= IDX_TAIL (Q)){
            return (IDX_TAIL(Q) - IDX_HEAD(Q)+1);
        }else{
            return (IDX_MAX - IDX_HEAD(Q) + IDX_TAIL(Q) + 2);
        }
    }
    
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *Q, songtype X)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam Tab melingkar. */
{
    if (IsEmpty(*Q)){
        IDX_HEAD(*Q) = 0;
        IDX_TAIL(*Q) = 0;
    }else{
        IDX_TAIL (*Q) = (IDX_TAIL(*Q) + 1) % (IDX_MAX + 1);
    }
    Penyanyi_Tail(*Q) = X.penyanyi;
    Album_Tail(*Q) = X.album;
    Judul_Lagu_Tail(*Q) = X.judul_lagu;

}

songtype dequeue(Queue *Q)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */
{
    songtype val;
    val.penyanyi = Penyanyi_Head(*Q);
    val.album = Album_Head (*Q);
    val.judul_lagu = Judul_Lagu_Head(*Q);
    if (IDX_HEAD(*Q) == IDX_TAIL(*Q)){
        IDX_HEAD(*Q) = IDX_UNDEF;
        IDX_TAIL(*Q) = IDX_UNDEF;
    }else{
        IDX_HEAD (*Q) = (IDX_HEAD(*Q) + 1) % (IDX_MAX + 1);
    }
    return val;
}

// Display queue belom dibenerin

/* *** Display Queue *** */
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */
{
    int i = IDX_HEAD(q);

    if (IsEmpty(q)){
        printf("[]\n");
    } else {
        printf("[");
        for (i = IDX_HEAD(q); i < (IDX_HEAD(q)+Length(q))-1; i++){
            printf("%d,", q.Tab[i%(IDX_MAX+1)]);
        }
        printf("%d]\n", q.Tab[(i)%(IDX_MAX+1)]);
    }
    
}