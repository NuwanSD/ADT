#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} Boolean;

typedef int ListData;

typedef struct node
{
    ListData entry;
    struct node *next;
} ListNode;

typedef struct
{
    ListNode *head;
    ListNode *tail;
    int count;
    Boolean full;
} List;

void CreateList(List *l)
{
    l->count = 0;
    l->full = FALSE;
    l->head = NULL;
    l->tail = NULL;

    printf("\n---ListNode Implemented!!!---\n");
}

Boolean isListEmpty(const List *l)
{
    return (l->head == NULL && l->tail == NULL);
}

Boolean isListFull(const List *l)
{
    return(l->full);
}

void InsertList(ListData x, List *l)
{
    ListNode *newNode;
    newNode = (ListNode *)malloc(sizeof(ListNode));
    if(newNode == NULL){
        printf("\nNot enough memory");
        l->full = TRUE;
    } else {
        newNode->entry = x;
        newNode->next = NULL;

        if(isListEmpty(l)){
            l->head = l->tail = newNode;
        } else {
            l->tail->next = newNode;
            l->tail = newNode;
        }
        l->count++;
    }
}

void ShowList(const List *l)
{
    ListNode *currentNode;
    if(isListEmpty(l)){
        printf("\nList is empty");
    } else {
        currentNode = l->head;
        printf("\n---Current List---");
        while(currentNode != NULL){
            printf("\n\t%d", currentNode->entry);
            currentNode = currentNode->next;
        }
    }
}

int main()
{
    List myList;
    ListData element;

    CreateList(&myList);

    InsertList(10, &myList);
    InsertList(20, &myList);
    InsertList(30, &myList);

    ShowList(&myList);

    return 0;
}

