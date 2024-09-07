#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLIST 10

typedef int ListData;

typedef int Position;

typedef struct{
    int count;
    ListData items[MAXLIST];
}List;

void CreateList(List *L)
{
    L->count = 0;

    printf("\nList created");
}

bool isListEmpty(List *L)
{
    return L->count == 0;
}

bool isListFull(List *L)
{
    return L->count == MAXLIST;
}

void InsertLast(ListData item, List *L)
{
    if(isListFull(L)){
        printf("\nList full");
    }else{
        L->items[L->count++] = item;

        printf("\nInsetLast : %d ", item);
    }
}

void InsetList(Position p, ListData x, List *L)
{
     if(isListFull(L)){
        printf("\nList full");
     }else if( p < 0 || p > MAXLIST){
        printf("Error");
     }else{
        for(int i= MAXLIST-1; i>= p; i--){
            L->items[i+1] = L->items[i];
        }

        L->items[p] = x;
        L->count++;
     }
}

int main()
{
    List entry;

    ListData item;

    CreateList(&entry);

    InsertLast(100, &entry);
    InsertLast(200, &entry);

    //void InsetList(Position p, ListData x, List *L)
}
