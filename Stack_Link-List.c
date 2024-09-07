#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} Boolean;

typedef int stackEntry;

typedef struct node
{
    stackEntry entry;
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
    s->top = NULL;
    s->count = 0;
    s->full = FALSE;
    printf("Stack is implemented!!");
}

Boolean isStackEmpty(const Stack *s)
{
    return (s->top == NULL);
}

Boolean isStackFull(const Stack *s)
{
    return (s->full);
}

void push(stackEntry item, Stack *s)
{
    Node *np;
    np = (Node *)malloc(sizeof(Node));
    if(np == NULL){
        printf("\nNot enough memory");
    }else{
        np->entry = item;
        np->next = s->top;
        s->top = np;
        s->count++;
    }

}

void pop(stackEntry *item, Stack *s)
{
    Node *np;
    if(!isStackEmpty(s)){
        *item = s->top->entry;
        printf("Pop item: %d", *item);
        np = s->top;
        s->top = s->top->next;
        s->count--;
        free(np);
    }else{
        printf("--Stack is empty--");
    }
}

void show(Stack *s)
{
    Node *np = s->top;
    if(!isStackEmpty(s)){
        printf("\n---Current Stack---\n");
        while(np != NULL){
            printf("%d\n", np->entry);
            np = np->next;
        }
    }else{
        printf("--Stack is empty--");
    }
}

void destroyStack(Stack *s)
{
    printf("\n--Stack destroy---\n");
    free(s);
}


int main()
{
    Stack entry;

    int item;

    int choice;

    createStack(&entry);

    while(1)
    {
        printf("\n\nPerfrom operations on Stack\n");
        printf("\n1.Push the element\n2.Pop the the element\n3.Show the Stack\n4.Destory the Stack\n");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice)
        {
        case 1:
            printf("\nEnter the item: ");
            scanf("%d", &item);
            push(item, &entry);
            break;
        case 2:
            pop(&item, &entry);
            break;
        case 3:
            show(&entry);
            break;
        case 4:
            destroyStack(&entry);
            exit(0);
        default:
            printf("\nInvalid choice");
            break;
        }

    }
}
