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

    printf("\n---QueueNode implemented!!!---\n");
}

Boolean isQueueEmpty(const Queue *q)
{
    return (q->front == NULL && q->rear == NULL);
}

Boolean isQueueFull(const Queue *q)
{
    return(q->full);
}

void append(queueElement x, Queue *q)
{
    QueueNode *np;
    np = (QueueNode *)malloc(sizeof(QueueNode));
    if(np == NULL){
        printf("\nNot enough memory");
        q->full=TRUE;
    }else{
        np->entry = x;
        np->next = NULL;

        if(isQueueEmpty(q)){
            q->front = q->rear = np;
        }else{
            q->rear->next = np;
            q->rear = np;
        }
    }

    q->count++;
}

void show(Queue *q)
{
    QueueNode *np;
    if(isQueueEmpty(q)){
        printf("\nQueue is empty");
        exit(1);
    }else{
        np = q->front;
        printf("\n---Current QueueNode---");
        while( np != NULL){
            printf("\n\t%d", np->entry);
            np = np->next;
        }
    }
}

void serve(queueElement *x, Queue *q)
{
    QueueNode *np;
    if(isQueueEmpty(q)){
        printf("\nQueue is underflow!");
        exit(1);
    }else{
        *x = q->front->entry;

        printf("\nServing...: %d", *x);

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

    queueElement element;

    createQueue(&entry);

    append(3, &entry);
    append(4, &entry);
    append(5, &entry);

    show(&entry);

    printf("\n\n--Serving items--\n");
    serve(&element, &entry);
    serve(&element, &entry);
    serve(&element, &entry);

}
