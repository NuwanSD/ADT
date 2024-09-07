#include <stdio.h>
#include <stdlib.h>

typedef enum {TRUE, FALSE} Boolean;

typedef int stackEntry;

typedef struct node
{
    stackEntry element;
    struct node *next;
}Node;

typedef struct
{
    Node *top;
    int count;
    Boolean full;
}Stack;

void createStack(Stack *s)
{
    s->count = 0;
    s->top = NULL;
    s->full = FALSE;
    printf("\nStack has been created\n");
}

Boolean isStackEmpty(Stack *s)
{
    return s->top == NULL;
}

Boolean isStackFull(Stack *s)
{
    return s->full;
}

void push(stackEntry item, Stack *s)
{
    Node *np;

    np = (Node *)malloc(sizeof(Node));

    if(np == NULL){
        printf("\nStack is Full\n");
        s->full = TRUE;
    }else{
        np->element = item;
        np->next = s->top;
        s->top = np;
        s->count++;

        printf("\nPush item: %d", item);
    }
}

void pop(stackEntry *item, Stack *s)
{
    Node *np;

    if(isStackEmpty(s)){
        printf("\nStack is underflow");
    }else{
        *item = s->top->element;
        printf("\nPop item : %d", *item);
        np = s->top;
        s->top = s->top->next;
        s->count--;
        free(np);
    }
}


int main()
{
    stackEntry item;

    Stack entry;

    createStack(&entry);

    push(5, &entry);
    push(10, &entry);
    printf("\nCount : %d", entry.count);

    pop(&item, &entry);
    pop(&item, &entry);

    printf("\nCount : %d", entry.count);
}

