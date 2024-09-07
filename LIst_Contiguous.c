#include <stdio.h>
#include <stdlib.h>

#define MAXLIST 10

#define TRUE 1
#define FALSE 0

typedef char ListData;

typedef int Position;

typedef struct
{
    int count;
    ListData entry[MAXLIST];
}List;

void CreateList(List *l)
{
    l->count = 0;
    printf("\nList implemented!!!");
}

int isListEmpty(const List *l)
{
    return (l->count == 0);
}

int isListFull(const List *l)
{
    return (l->count == MAXLIST);
}

int ListSize(const List *l)
{
    return(l->count);
}

void InsertLast(ListData x, List *l)
{
    if(isListFull(l)){
        printf("\nAttempt to insert at the end of a full list");
        exit(1);
    }

    l->entry[l->count++] = x;
    printf("\nInsert item: %c into index: %d", x, l->count);
}

void InsertList(Position p, ListData x, List *l)
{
    int i;
    if(isListFull(l)){
        printf("\nAttempt to insert an entry into a full list");
        exit(1);
    }else if(p<0 || p>ListSize(l)){
        printf("\nAttempt to insert a position not in the list");
        exit(1);
    }else{
        for(i= ListSize(l)-1; i >= p; i--){
            l->entry[i+1] = l->entry[i];
        }

        l->entry[p] = x;
        l->count++;
    }
}

void DeleteList(Position p, ListData *x, List *l)
{
    if(isListEmpty(l)){
        printf("\nAttempt to delete an entry from an empty list\n");
    }else if(p<0 || p>= ListSize(l)){
        printf("\nAttempt to delete a position not in the list\n");
    }else{
        *x=l->entry[p];
        for(int i=p; i<ListSize(l); i++){
            l->entry[i] = l->entry[i+1];
        }
        l->count--;
    }
}

void RetrieveList(Position p, ListData *x, const List *l)
{
    if(isListEmpty(l)){
        printf("\nAttempt to retrieve an entry from an empty list\n");
    }else if(p<0 || p >= ListSize(l)){
        printf("\nAttempt to retrieve an entry at a position not in the list\n");
    }else{
        *x = l->entry[p];
        printf("\n%c at Position %d", *x, p);
    }
}

void ReplaceList(Position p, ListData x, List *l)
{
    if(isListEmpty(l)){
        printf("\nAttempt to replace an entry of an empty list");
    }else if(p<0 || p>= ListSize(l)){
        printf("\nAttempt to replace an entry at a position not in the list");
    }else {
        l->entry[p] = x;
    }
}

void TraverseList(const List *l)
{
    printf("\n\nList Traverse\n");
    for(int i=0; i<= (l->count-1); i++){
        printf("\n%c", l->entry[i]);
    }
}

void PrintElement(ListData x)
{
    printf("\nPrint Very First Element -> %c", x);
}

int main()
{
    List entry;

    ListData item;

    CreateList(&entry);

    InsertLast('A', &entry);
    InsertLast('B', &entry);
    InsertLast('C', &entry);

    //PRINT CURRET LIST
    printf("\n---Current List---\n");
    for(int i=0; i< ListSize(&entry); i++){
        printf("%c\t|", entry.entry[i]);
    }

    //InsertList(Position p, ListData x, List *l)
    InsertList(2, 'X', &entry);

    //PRINT CURRET LIST
    printf("\n---Updated List---\n");
    for(int i=0; i< ListSize(&entry); i++){
        printf("%c\t|", entry.entry[i]);
    }

    //DeleteList(Position p, ListData *x, List *l)
    DeleteList(1, &item, &entry);

    //PRINT CURRET LIST
    printf("\n---Updated List---\n");
    for(int i=0; i< ListSize(&entry); i++){
        printf("%c\t|", entry.entry[i]);
    }

    //RetrieveList(Position p, ListData *x, const List *l)
    RetrieveList(0, &item, &entry);

    //ReplaceList(Position p, ListData x, List *l)
    ReplaceList(0, 'Z', &entry);

    //PRINT CURRET LIST
    printf("\n---Updated List---\n");
    for(int i=0; i< ListSize(&entry); i++){
        printf("%c\t|", entry.entry[i]);
    }

    //TraverseList(const List *l)
    TraverseList(&entry);

    //PrintElement(ListData x)
    PrintElement(item);


}
