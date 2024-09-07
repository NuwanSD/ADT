#include <stdio.h>
#include <stdlib.h>

#define MAXLIST 5

int main()
{
    int i, j, k, L[MAXLIST];

    L[0] = 100;
    L[1] = 23;
    L[2] = 80;
    L[3] = 20;
    L[4] = 90;

    printf("\nInitial List --> ");
    for(i=0; i<= MAXLIST-1; i++){
        printf(" %d |", L[i] );
    }

    for(i=1; i<=MAXLIST-1; i++){
        j = i-1;

        while(j>=0){
            if(L[j] > L[j+1]){
                k = L[j];
                L[j] = L[j+1];
                L[j+1] = k;
            }

            j= j -1;
        }
    }


    printf("\nInsertion Shorted --> ");
    for(i=0; i<= MAXLIST-1; i++){
        printf(" %d |", L[i] );
    }
}
