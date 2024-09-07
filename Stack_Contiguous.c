#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 3

typedef int stackEntry;

typedef struct
{
    int top;
    stackEntry entry[MAXSTACK];
}Stack;

void createStack(Stack *s)
{
    s->top = -1;
    printf("\nStack Implemented!");
}

typedef enum { FALSE, TRUE} Boolean;

Boolean isStackEmpty(const Stack *s)
{
    return s->top == -1;
}

Boolean isStackFull(const Stack *s)
{
    return s->top == MAXSTACK -1;
}

void push(stackEntry item, Stack *s)
{
    if(!isStackFull(s)){
        s->entry[++s->top] = item;
    }else{
        printf("---Stack is Full---");
    }
}

void pop(stackEntry *item, Stack *s)
{
    if(!isStackEmpty(s)){
        *item = s->entry[s->top--];
        printf("\nPopped item: %d", *item);
    }else{
        printf("---Stack is Empty---");
    }
}

void show(Stack *s)
{
    if(!isStackEmpty(s)){
        printf("\n---Current Stack---\n");
        for(int i = s->top; i >= 0; --i){
            printf("%d\n", s->entry[i]);
        }
    }else{
        printf("---Stack is Empty---");
    }
}

int main()
{
    Stack entry;

    int choice;

    int item;

    createStack(&entry);

    while(1){

        printf("\n\nPerfrom operations on Stack\n");
        printf("\n1.Push the element\n2.Pop the the element\n3.Show the Stack\n4.End\n");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice)
        {
        case 1:
            printf("\nEnter the value: ");
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
            exit(0);
        default:
            printf("\nInvalid choice!");
            break;
        }

    }
}
