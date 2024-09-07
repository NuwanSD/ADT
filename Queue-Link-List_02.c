#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} Boolean;

typedef int queueElement;

typedef struct
{
    queueElement entry;
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
    q->count = 0;
    q->full = FALSE;
    q->front = NULL;
    q->rear = NULL;

    printf("\nQueueNode has been implemented\n");
}

Boolean isQueueEmpty(Queue *q)
{
    return (q->front == NULL) && (q->rear == NULL);
}

Boolean isQueueFull(Queue *q)
{
    return (q->full);
}

void append(queueElement x, Queue *q)
{
    QueueNode *np;
    np = (QueueNode *)malloc(sizeof(QueueNode));
    if(np == NULL){
        printf("\nNot enough memory\n");
        q->full = TRUE;
    }else{
        np->entry = x;
        np->next = NULL;
        if(isQueueEmpty(q)){
            q->front = q->rear = np;
        }else{
            q->rear->next=np;
        }

        printf("\nAppend item: %d", np->entry);

        q->count++;
    }
}

void serve(queueElement *x, Queue *q)
{
    QueueNode *np;
    if(isQueueEmpty(q)){
        printf("\nQueueNode is underflow\n");
        exit(1);
    }else{
        *x = q->front->entry;

        printf("\nServed...: %d", *x);

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

    Queue myQueue;

    queueElement item;

    //createQueue
    createQueue(&myQueue);

    //append(queueElement x, Queue *q)
    append(10, &myQueue);
    append(20, &myQueue);

    //Count the number of elements
    printf("\nCount: %d", myQueue.count);

    //serve(queueElement *x, Queue *q)
    serve(&item, &myQueue);
    serve(&item, &myQueue);
    serve(&item, &myQueue);

}

