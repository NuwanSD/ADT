#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAXQUEUE 10

typedef char queueElement;

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

    printf("\nQueue Implemented\n");
}

int isQueueFull(Queue *q)
{
     if(q->rear == MAXQUEUE-1){
        return TRUE;
     }else{
        return FALSE;
     }

     //return(q->rear == MAXQUEUE -1 ? TRUE : FALSE);
}

int isQueueEmpty(Queue *q)
{
    if((q->rear) < (q->front)){
        return TRUE;
    }else{
        return FALSE;
    }
}

void append(queueElement x, Queue *q)
{
    if(isQueueFull(q)){
        printf("\nQueue full\n");
        exit(1);
    }else{
        q->items[++(q->rear)] = x;
        q->count++;
        printf("\nAppending --> %c at index: %d", x, q->rear);
    }
}

void serve(queueElement *x, Queue *q)
{
    if(isQueueEmpty(q)){
        printf("\nQueue is empty");
        exit(1);
    }else{
        *x = q->items[q->front++];
        printf("\nServe item: %c\n", *x);
        q->count--;
    }
}


int main()
{
    Queue entry;

    queueElement element;

    //createQueue(Queue *q)
    createQueue(&entry);

    //append(queueElement x, Queue *q)
    append('A', &entry);
    append('B', &entry);
    append('C', &entry);
    append('X', &entry);

    printf("\nAfter append item --> Count: %d\n", entry.count);

    printf("\n\n");

    //serve(queueElement *x, Queue *q)
    serve(&element, &entry);
    serve(&element, &entry);
    serve(&element, &entry);
    serve(&element, &entry);

    printf("\nAfter serve item --> Count: %d\n", entry.count);


}
