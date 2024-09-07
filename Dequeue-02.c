#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXQUEUE 10

typedef int QueueElement;

typedef struct{
    QueueElement items[MAXQUEUE];
    int front;
    int rear;
    int count;
}Dequeue;

void createQueue(Dequeue *q)
{
    q->count=0;
    q->front=0;
    q->rear = -1;

    printf("\nDequeue has been implemented!!!");
}

bool isQueueEmpty(Dequeue *q)
{
    return (q->rear < q->front);
}

bool isQueueFull(Dequeue *q)
{
    return (q->count == MAXQUEUE);
}

void AppendRear(QueueElement x, Dequeue *q)
{
    if(isQueueFull(q)){
        printf("\nQueue is full");
    }else{
        q->items[++q->rear] = x;
        q->count++;

        printf("\nAppendRear : %d", x);
    }
}

void AppendFront(QueueElement x, Dequeue *q)
{
    if(isQueueFull(q)){
        printf("\nQueue is full");
    }else{
        if(isQueueEmpty(q)){
            q->items[q->front] = x;
            q->rear++;

            printf("\nAppendFront: %d", x);
        }else{
            if(q->front == 0){
                for(int i = q->rear; i >= q->front; i--){
                    q->items[i+1] = q->items[i];
                }

                q->rear++;
                q->items[q->front] = x;
                printf("\nAppendFront: %d", x);
            }else{
                q->items[--q->front] = x;
                printf("\nAppendFront: %d", x);

            }
        }

        q->count++;
    }
}

void ServeRear(QueueElement *x, Dequeue *q)
{
    if(isQueueEmpty(q)){
        printf("\nQueue is empty");
        exit(1);
    }else{
        *x = q->items[q->rear--];
        q->count--;

        printf("\nServeRear : %d", *x);
    }
}

void ServeFront(QueueElement *x, Dequeue *q)
{
    if(isQueueEmpty(q)){
        printf("\nQueue is empty");
        exit(1);
    }else{
        *x = q->items[q->front++];
        q->count--;

        printf("\nServeFront : %d", *x);
    }
}

int main()
{
    Dequeue myQueue;

    QueueElement entry;

    createQueue(&myQueue);

    AppendFront(7, &myQueue);

    AppendRear(10, &myQueue);
    AppendRear(20, &myQueue);
    AppendRear(30, &myQueue);

    printf("\nCount : %d", myQueue.count);

    ServeFront(&entry, &myQueue);
    ServeRear(&entry, &myQueue);

    printf("\nCount : %d", myQueue.count);
}
