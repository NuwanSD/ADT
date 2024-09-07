#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 10

typedef enum {FALSE, TRUE} Boolean;

typedef int stackEntry;

typedef struct
{
    int top;
    stackEntry entry[MAXSTACK];
}Stack;

void createStack(Stack *s)
{
    s->top = -1;
    printf("\n---Stack implemented!!---\n");
}

Boolean isStackEmpty(const Stack *s)
{
    return s->top == -1;
}

Boolean isStackFull(const Stack *s)
{
    return s->top == MAXSTACK - 1;
}

void push(stackEntry item, Stack *s)
{
    if(isStackFull(s)){
        printf("\nStack is full\n");
        exit(1);
    }else{
        s->entry[++s->top] = item;
    }
}

void pop(stackEntry *item, Stack *s)
{
    if(isStackEmpty(s)){
        printf("\nStack is underflow\n");
        exit(1);
    }else{
        *item = s->entry[s->top--];
        printf("\nPop item: %d", *item);
    }
}

int main()
{
    Stack element;

    int k;

    stackEntry item;

    //createStack(Stack *s)
    createStack(&element);

    //push(stackEntry item, Stack *s)
    push(10, &element);
    push(100, &element);
    push(20, &element);
    push(30, &element);
    push(92, &element);

    printf("\nCurrent stack\n");
    for(int i= element.top; i >= 0; i--){
        printf(" %d |", element.entry[i]);
    }

     for(int i = 0; i <= MAXSTACK-2; i++){
        for(int j = 0; j <= MAXSTACK-2-i; j++){
            if(element.entry[j+1] < element.entry[j]){
                k = element.entry[j];
                element.entry[j] = element.entry[j+1];
                element.entry[j+1] = k;
            }
        }
    }

    printf("\nBubble shorted List -->");
    for(int i=0; i < MAXSTACK; i++){
        printf(" %d | ", element.entry[i]);
    }




    //pop(stackEntry *item, Stack *s)
    /*pop(&item, &element);
    pop(&item, &element);*/

}

