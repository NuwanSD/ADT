#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} Boolean;

typedef int stackEntry;

typedef struct
{
    stackEntry element;
    struct node *next;
}Node;

typedef struct
{
    int count;
    Boolean full;
    Node *top;
}Stack;

void createStack(Stack *s)
{
    s->count = 0;
    s->full = FALSE;
    s->top = NULL;

    printf("\nStack implemented\n");
}

Boolean isStackEmpty(const Stack *s)
{
    return(s->top == NULL);
}

Boolean isStackFull(const Stack *s)
{
    return(s->full);
}

void push(stackEntry item, Stack *s)
{
    Node *np;

    np=(Node *)malloc(sizeof(Node));
    if(np == NULL){
        printf("\nNot enough memory\n");
        s->full = TRUE;
    }else{
        np->element = item;
        np->next = s->top;
        s->top = np;
        s->count++;

        printf("\nPushing---> %d",np->element);
    }
}

void pop(stackEntry *item, Stack *s)
{
    Node *np;
    if(isStackEmpty(s)){
        printf("\nStack is empty");
    }else{
        *item = s->top->element;
        np = s->top;
        s->top = s->top->next;
        s->count--;
        free(np);

        printf("\nPop out: %d", *item);
    }
}

void destoryStack(Stack *s)
{
    free(s);
}

int main()
{
    Stack entry;

    stackEntry item;

    //createStack(Stack *s)
    createStack(&entry);

    //push(stackEntry item, Stack *s)
    push(20, &entry);
    push(30, &entry);

    //destoryStack(Stack *s)
    destoryStack(&entry);

    //pop(stackEntry *item, Stack *s)
    pop(&item, &entry);
    pop(&item, &entry);
    pop(&item, &entry);
}


