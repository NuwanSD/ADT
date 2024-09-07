#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAXQUEUE 10

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
    q->front = 0;
    q->rear = -1;
    q->count = 0;

    printf("\nQueue has been implemented!");
}

int isQueueEmpty(Queue *q)
{
    if(q->rear < q->front){
        return TRUE;
    }else{
        return FALSE;
    }
}

int isQueueFull(Queue *q)
{
    if(q->rear == MAXQUEUE -1){
        return TRUE;
    }else{
        return FALSE;
    }
}

void append(queueElement item, Queue *q)
{
    if(isQueueFull(q)){
        printf("\nQueue is full");
    }else{
        q->rear = (q->rear + 1) % MAXQUEUE;
        q->items[q->rear] = item;
        q->count++;
    }
}

void serve(queueElement *item, Queue *q)
{
    if(isQueueEmpty(q)){
        printf("\nQueue is underflow");
    }else{
        *item = q->items[q->front];
        q->front = (q->front + 1) % MAXQUEUE;
        q->count--;
        printf("\n Serve: %d", *item);
    }
}

int main()
{

    Queue entry;
    queueElement item;

    createQueue(&entry);

    append(10, &entry);
    append(20, &entry);
    append(30, &entry);
    append(30, &entry);
    append(30, &entry);

    printf("\n");

    for(int i= entry.front; i <= entry.rear; i++){
        printf(" %d | ", entry.items[i]);
    }

    serve(&item, &entry);
    serve(&item, &entry);

    printf("\n");

    for(int i= entry.front; i <= entry.rear; i++){
        printf(" %d | ", entry.items[i]);
    }

}
