#include <stdio.h>
#include <stdlib.h>

typedef enum {FALSE, TRUE} Boolean;

typedef int ListData;

typedef int Position;

typedef struct
{
    ListData entry;
    struct listNode *next;
}ListNode;

typedef struct
{
    int count;
    Boolean full;
    ListNode *head;
}List;

void CreateList(List *l)
{
    l->count = 0;
    l->head = NULL;
    l->full = FALSE;

    printf("\nListNode Implemented");
}

Boolean isListEmpty(const List *l)
{
    return (l->head == NULL);
}

Boolean isListFull(const List *l)
{
    return(l->full);
}

int ListSize(const List *l)
{
    return(l->count);
}

ListNode *MakeListNode(ListData x)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));

    if(p){
        p->entry = x;
        p->next = NULL;
    }

    return (p);
}

void setPosition(Position p, List *l, ListNode **current)
{
    int count;          //used to travel through positions
    ListNode *n;        //used to travel list

    if( p< 0 || p> (l->count)){
        printf("\nAttempt to set a position not in the list");
    }else{
        //Count from head of list to position p
        n = l->head;
        for(count =1; count <= p; count++){
            n = n->entry;
        }

        *current = n;
    }
}

void InsertList(Position p, ListData x, List *l)
{
    ListNode *newNode = NULL;
    ListNode *current = NULL;


    if(p<0 || p>ListSize(l)){
        printf("\nAttempt to insert a position not in the list\n");
    }else{
        newNode = MakeListNode(x);
        if(newNode == NULL){
            l->full = TRUE;
            printf("\nNot enough memory for additional node\n");
        }else{
            if(p == 0){
                //Insert as the first element
                newNode->next = l->head;
                l->head = newNode;
            }else{
                setPosition(p-1, l, &current);
                newNode->next = current->next;
                current->next = newNode;
            }
            l->count++;

        }
    }
}

void PrintElement(const List *L)
{
    ListNode *current = L->head;\
    printf("\n");
    while(current != NULL) {
        printf("%d -> ", current->entry);
        current = current->next;
    }
    //printf("NULL\n");
    printf("%d\n", current);
}

int main()
{
    List myList;

    ListData item;

    //CreateList(List *l)
    CreateList(&myList);

    //InsertList(Position p, ListData x, List *l)
    InsertList(0, 10, &myList);
    InsertList(1, 20, &myList);

    //PrintElement(const List *L)
    PrintElement(&myList);


}
