#include <stdio.h>
#include <stdlib.h>

typedef enum {TRUE, FALSE} Boolean;

typedef int queueElement;

typedef struct
{
    queueElement item;
    struct node *next;
}QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
    int count;
    Boolean full;
}Queue;

void createQueue(Queue *q)
{
    q->front = NULL;
    q->rear = NULL;
    q->count = 0;
    q->full = FALSE;

    printf("\nQueue has been implemented!!");
}

Boolean isQueueEmpty(Queue *q)
{
    return (q->front == NULL && q->rear == NULL);
}

Boolean isQueueFull(Queue *q)
{
    return q->full;
}

void append(queueElement item, Queue *q)
{
    QueueNode *np;
    np = (QueueNode *)malloc(sizeof(QueueNode));

    if(np == NULL){
        printf("\nQueue is full");
        q->full = TRUE;
    }else{
        np->item = item;
        np->next = NULL;

        if(isQueueEmpty(q)){
            q->front = q->rear = np;
        }else{
            q->rear->next = np;
            q->rear = np;
        }

        q->count++;
        printf("\nAppend : %d", item);
    }
}

void serve(queueElement *item, Queue *q)
{
    QueueNode *np;
    if(isQueueEmpty(q)){
        printf("\nQueue is empty");
        exit(1);
    }else{
        *item = q->front->item;

        printf("\nServe: %d", *item);

        np = q->front;
        q->front = q->front->next;
        q->count--;

        if(q->front == NULL){
            q->rear = NULL;
        }

        free(np);

    }
}

int main()
{
    Queue entry;

    queueElement item;

    createQueue(&entry);

    append(4, &entry);
    append(5, &entry);
    append(6, &entry);

    printf("\n\nCount : %d\n\n", entry.count);

    serve(&item, &entry);
    serve(&item, &entry);

    printf("\n\nCount : %d\n\n", entry.count);
}

