#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXLIST 15

typedef float ListData;

typedef int Position;

typedef struct{
    int count;
    ListData Items[MAXLIST];
}List;

void CreateList(List *L)
{
    L->count = 0;

    printf("\nList has been implemented!!");
}

bool isListEmpty(List *L)
{
    return(L->count == 0);
}

bool isListFull(List *L)
{
    return(L->count == MAXLIST);
}

void Insert(ListData item, List *L)
{
    if(isListFull(L)){
        printf("\nYour List is full");
        exit(1);
    }else{
        L->Items[L->count++] = item;

        printf("\nInserting item : %.1f", item);
    }
}

int main()
{
    List entry;

    ListData element;

    CreateList(&entry);

    printf("\n");

    //void Insert(ListData item, List *L
    Insert(4.3, &entry);
    Insert(2.2, &entry);
    Insert(100.7, &entry);
    Insert(0.4, &entry);
    Insert(24.1, &entry);
    Insert(7.9, &entry);
    Insert(1600.6, &entry);
    Insert(5.3, &entry);
    Insert(1.4, &entry);
    Insert(30.7, &entry);

    printf("\n\n------Current List-----\n\n");
    for(int i=0; i<entry.count; i++){
        printf(" %.1f | ", entry.Items[i]);
    }

    //Bubble sort
    for(int i=0; i<= entry.count-2; i++){
        for(int j=0; j <= entry.count-2-i; j++){
            if(entry.Items[j+1] < entry.Items[j]){
                int k = entry.Items[j];
                entry.Items[j] = entry.Items[j+1];
                entry.Items[j+1] = k;
            }
        }
    }

    printf("\n\n------Bubble Sorted List-----\n\n");
    for(int i=0; i<entry.count; i++){
        printf(" %.1f | ", entry.Items[i]);
    }

    printf("\n\n------Bubble Sorted List By Reverse Order-----\n\n");
    for(int i= entry.count-1 ; i >= 0; i--){
        printf(" %.1f | ", entry.Items[i]);
    }

    printf("\n");

    //Find the largest three numbers
    float sum = 0;
    printf("\nLargest three numbers : ");
    for(int i= entry.count-1 ; i >= 7; i--){
        sum = sum + entry.Items[i];
        printf(" %.1f | ", entry.Items[i]);
    }

    printf("\n\nAverage value : %.2f ", sum/3);


    printf("\n\nNumber of Items : %d", entry.count);
}
