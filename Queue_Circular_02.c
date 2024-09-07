#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 10

#define TURE 1
#define FALSE 0


typedef int queueElement;

typedef struct
{
    queueElement items[MAXQUEUE];
    int front;
    int rear;
    int count;
}Queue;

void createQueue(Queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = -1;

    printf("Queue implemented!!");
}

int isQueueEmpty(Queue *q)
{
    return (q->count == 0);
}

int isQueueFull(Queue *q)
{
    return(q->count == MAXQUEUE);
}

void append(queueElement x, Queue *q)
{
    if(isQueueFull(q)){
        printf("\nQueue full");
        exit(1);
    }else{
        q->rear = (q->rear+1) % MAXQUEUE;
        q->items[(q->rear)] = x;
        q->count++;

        printf("\nAppend: %d", x);
    }
}

void serve(queueElement *x, Queue *q)
{
    if(isQueueEmpty(q)){
        printf("\nQueue is empty");
        exit(1);
    }else{
        *x = q->items[q->front];
        q->front=(q->front+1) % MAXQUEUE;
        q->count--;

        printf("\nServed: %d", *x);
    }
}

int main()
{
    Queue circularQueue;

    queueElement item;

    createQueue(&circularQueue);

    //append(queueElement x, Queue *q)
    append(100, &circularQueue);
    append(200, &circularQueue);

    //serve(queueElement *x, Queue *q)
    serve(&item, &circularQueue);
    serve(&item, &circularQueue);

}
