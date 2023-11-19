#include "queue.h"

void CreateQueue(Queue *Q)
{
    Q->idxHead = IDX_UNDEF;
    Q->idxTail = IDX_UNDEF;
}

boolean IsEmptyQueue(Queue Q)
{
    return (Q.idxHead == IDX_UNDEF && Q.idxTail == IDX_UNDEF);
}

boolean IsFullQueue(Queue Q)
{
    if (Q.idxTail == CAPACITY - 1)
    {
        return (Q.idxHead == 0);
    }
    else
    {
        return (Q.idxHead - 1 == Q.idxTail);
    }
}

void enqueue(Queue *Q, QueueSongType val)
{

    if (IsEmptyQueue(*Q))
    {
        Q->idxHead = 0;
        Q->idxTail = 0;
    }
    else
    {
        if (Q->idxTail == CAPACITY - 1)
        {
            Q->idxTail = 0;
        }
        else
        {
            Q->idxTail++;
        }
    }
    stringCopy(Q->buffer[Q->idxTail].penyanyi, val.penyanyi);                 // jadi harus strcpy buat nerima input string
    stringCopy(Q->buffer[Q->idxTail].album, val.album);                       // fix sama kaya di atas
    stringCopy(Q->buffer[Q->idxTail].judul_lagu.judul, val.judul_lagu.judul); // fix sama kaya di atas
}

int LengthQueue(Queue Q)
{
    if (IsEmptyQueue(Q))
    {
        return 0;
    }

    else
    {
        if (Q.idxHead <= Q.idxTail)
        {
            int panjang = Q.idxTail - Q.idxHead + 1;
            return panjang;
        }

        else
        {
            int panjang = CAPACITY - Q.idxHead + Q.idxTail + 1;

            return panjang;
        }
    }
}

void dequeue(Queue *Q, QueueSongType *val)
{

    stringCopy(val->penyanyi, Q->buffer[Q->idxHead].penyanyi);                 // jadi harus strcpy buat nerima input string
    stringCopy(val->album, Q->buffer[Q->idxHead].album);                       // fix sama kaya di atas
    stringCopy(val->judul_lagu.judul, Q->buffer[Q->idxHead].judul_lagu.judul); // fix sama kaya di atas

    if (Q->idxHead == Q->idxTail)
    {
        Q->idxHead = IDX_UNDEF;
        Q->idxTail = IDX_UNDEF;
    }
    else
    {
        if (Q->idxHead == CAPACITY - 1)
        {
            Q->idxHead = 0;
        }
        else
        {
            Q->idxHead++;
        }
    }
}

void CopyQueue(Queue qIn, Queue *qOut)
{
    CreateQueue(qOut);
    QueueSongType temp;

    int length = LengthQueue(qIn);
    for (int i = 0; i < LengthQueue(qIn); i++)
    {
        dequeue(&qIn, &temp);
        enqueue(qOut, temp);
        enqueue(&qIn, temp);
    }
}

void DisplayQueue(Queue Q)
{

    if (IsEmptyQueue(Q))
    {
        printf("[]\n");
    }
    else
    {
        int i;

        QueueSongType tempVal;
        Queue tempQ;
        CopyQueue(Q, &tempQ);

        for (i = 0; i < LengthQueue(Q); i++)
        {
            dequeue(&tempQ, &tempVal);

            printf("%s;", tempVal.penyanyi);
            printf("%s;", tempVal.album);
            printf("%s\n", tempVal.judul_lagu.judul);
        }
    }
}