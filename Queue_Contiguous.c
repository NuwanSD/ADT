#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
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
    printf("\nQueue Implemented!!!");
}

int isQueueEmpty(Queue *q)
{
    if((q->rear) < (q->front)){
        return TRUE;
    }else{
        return FALSE;
    }
}

int isQueueFull(Queue *q)
{
    if( (q->rear) == MAXQUEUE - 1){
        return TRUE;
    }else{
        return FALSE;
    }
}

void append(Queue *q, queueElement x)
{
    if(isQueueFull(q)){
        printf("\nQueue Full\n");
    }else{
        q->items[++(q->rear)] = x;
        q->count++;
    }
}

void serve(Queue *q, queueElement *x)
{
    if(isQueueEmpty(q)){
        printf("\nQueue is empty,underflow\n");
    }else{
        *x = q->items[(q->front)++];
        printf("\nServe item: %d", *x);
        q->count--;
    }
}

/*
void show(Queue *q)
{
    if(isQueueEmpty(q)){
        printf("\nQueue is empty\n");
    }else{
        printf("\n--Current Queue--\n");
        for(int i= q->front; i<= q->rear; i++)
        {
            i = (q->front)++;
            printf("\n%d", q->items[i]);
        }
    }
}
*/

int main()
{
    Queue entry;

    int item;
    int choice;

    createQueue(&entry);

    while(1)
    {
        printf("\n\nPerfrom operations on the stack:\n");
        printf("\n1.Insert the element\n2.Serve the the element\n3.Show current Queue\n4.End");
        printf("\n\nEnter the choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("\nEnter the value: ");
            scanf("%d", &item);
            append(&entry, item);
            break;
        case 2:
            serve(&entry, &item);
            break;
        case 3:
            //show(&entry);
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice!");
            break;
        }
    }
}
