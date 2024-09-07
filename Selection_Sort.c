#include <stdio.h>
#include <stdlib.h>

#define MAXLIST 5

int main()
{
    int k, min1, L[MAXLIST];

    L[0] = 100;
    L[1] = 23;
    L[2] = 80;
    L[3] = 20;
    L[4] = 90;

    printf("\nInitial list --> \t");
    for(int i=0; i < MAXLIST; i++){
        printf(" %d | ", L[i]);
    }

    //Bubble short
    for(int i = 0; i <= MAXLIST-2; i++){
        min1 = i;
        for(int j = i+1; j <= MAXLIST-1; j++){
            if(L[j] < L[min1]){
                min1 = j;
            }
        }

        //swap the elements
        if(min1 != i){
            k = L[i];
            L[i] = L[min1];
            L[min1] = k;
        }


    }

    printf("\nSelection shorted -->");
    for(int i=0; i < MAXLIST; i++){
        printf(" %d | ", L[i]);
    }
}


