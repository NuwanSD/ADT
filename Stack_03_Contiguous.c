#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 10

typedef enum {FALSE, TRUE} Boolean;

typedef int stackEntry;

typedef struct
{
    stackEntry items[MAXSTACK];
    int top;
}Stack;

void createStack(Stack *s)
{
    s->top = -1;

    printf("\nStack has been implemented!!");
}

Boolean isStackEmpty(Stack *s)
{
    return s->top == -1;
}

Boolean isStackFull(Stack *s)
{
    return s->top == MAXSTACK-1;
}

void push(stackEntry item, Stack *s)
{
    if(isStackFull(s)){
        printf("\nStack is full\n");
    }else{
         s->items[++s->top] = item;
    }
}

void pop(stackEntry *item, Stack *s)
{
    if(isStackEmpty(s)){
        printf("\nStack is empty");
    }else{
        *item = s->items[s->top--];
        printf("\nPop item: %d", *item);
    }
}


int main()
{

    Stack entry;

    stackEntry item;

    createStack(&entry);

    push(5, &entry);
    push(10, &entry);
    push(15, &entry);
    push(25, &entry);


    printf("\nInitial Stack\n");

    for(int i=0; i <= entry.top; i++){
        int value = entry.items[i];

        printf(" %d | ", value);
    }

    pop(&item, &entry);

    printf("\nAfter pop Stack\n");

    for(int i=0; i <= entry.top; i++){
        int value = entry.items[i];

        printf(" %d | ", value);
    }


}
