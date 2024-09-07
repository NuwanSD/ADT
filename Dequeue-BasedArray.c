#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAXQUEUE 20

typedef int DqueueElement;

typedef struct
{
    DqueueElement items[MAXQUEUE];
    int front;
    int rear;
    int count;
}Dqueue;

void createQueue(Dqueue *Dq)
{
    Dq->count = 0;
    Dq->front = 0;
    Dq->rear = -1;

    printf("\nDequeue implemented");
}

int isQueueEmpty(Dqueue *q)
{
    return(q->count == 0);
}

int isQueueFull(Dqueue *q)
{
    return(q->count == MAXQUEUE);
}

void AppendRear(DqueueElement x, Dqueue *q)
{
    if(isQueueFull(q)){
        printf("Dequeue Full\n");
        exit(1);
    }else{
        q->items[++(q->rear)] = x;
        q->count++;

        printf("\nAppnedRear: %d", x);
    }
}

void AppendFront(DqueueElement x, Dqueue *q)
{
    if(isQueueFull(q)){
        printf("\nQueue Full\n");
        exit(1);
    }else{
        if(isQueueEmpty(q)){
            q->items[q->front] = x;
            printf("\nAppendFront: %d", x);
            q->rear++;
        }else{
            if(q->front == 0){
                for(int i = q->rear; i >= q->front; i--){
                    q->items[i+1] = q->items[i];
                }

                q->rear++;
                q->items[q->front] = x;
                printf("\nAppendFront: %d", x);
            }else{
                q->items[--(q->front)] = x;
                printf("\nAppendFront: %d", x);
            }
        }

        q->count++;
    }
}

void ServeFront(DqueueElement *x, Dqueue *q)
{
    if(isQueueEmpty(q)){
        printf("\nQueue is empty, underflow\n");
        exit(1);
    }else{
        *x = q->items[(q->front)++];
        printf("\nServeFront: %d", *x);
        q->count--;
    }
}

void ServeRear(DqueueElement *x, Dqueue *q)
{
    if(isQueueEmpty(q)){
        printf("Dequeue is empty\n");
        exit(1);
    }else{
        *x = q->items[(q->rear)--];
        printf("\nServeRear: %d", *x);
        q->count--;
    }
}



int main()
{

    Dqueue myQueue;

    DqueueElement element;

    createQueue(&myQueue);

    //AppnedRear(DqueueElement x, Dqueue *q)
    AppendRear(10, &myQueue);
    //AppendFront(DqueueElement x, Dqueue *q
    AppendFront(20, &myQueue);


    printf("\n");
    //PRINT THE CURRENT DEQUEUE
    for(int i= myQueue.front; i <= (myQueue.rear); i++){
        printf("\t%d |", myQueue.items[i]);
    }

    //ServeFront(DqueueElement *x, Dqueue *q).
    ServeFront(&element, &myQueue);
    //ServeRear(DqueueElement *x, Dqueue *q)
    ServeRear(&element, &myQueue);
}
