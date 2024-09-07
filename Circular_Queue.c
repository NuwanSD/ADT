#include <stdio.h>
#include <stdlib.h>

#define TURE 1
#define FALSE 0

#define MAXQUEUE 20

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

int isQueueEmpty(const Queue *q)
{
    return(q->count == 0);
}

int isQueueFull(const Queue *q)
{
    return(q->count == MAXQUEUE);
}

void append(queueElement x, Queue *q)
{
    if(isQueueFull(q))
    {
        printf("Queue full\n");
        exit(1);
    }else{
        q->rear = (q->rear+1) % MAXQUEUE;
        q->items[(q->rear)] = x;
        q->count++;

        printf("\n\tAppending -> %d into Index -> %d", x, q->rear);
    }
}

void serve(queueElement *x, Queue *q)
{
    if(isQueueEmpty(q)){
        printf("\nQueue is empty\n");
        exit(1);
    }else{
        *x = q->items[q->front];
        q->front = (q->front+1) % MAXQUEUE;
        q->count--;

        printf("\nServing... %d", *x);
    }
}

int queueSize(const Queue *q)
{
    return(q->count);
}

int main()
{
    Queue entry;

    queueElement element;

    int size;

    createQueue(&entry);

    printf("\n");
    append(10, &entry);
    append(20, &entry);
    append(30, &entry);

    size = queueSize(&entry);
    printf("\n\nQueue size: %d\n", size);

    serve(&element, &entry);
    serve(&element, &entry);
    serve(&element, &entry);

    printf("\n\nAfter Serving Queue size: %d\n", queueSize(&entry));

}
