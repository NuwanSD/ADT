#include <stdio.h>
#include <stdlib.h>

#define MAXLIST 5


int main()
{
    int k, L[MAXLIST];

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
        for(int j = 0; j <= MAXLIST-2-i; j++){
            if(L[j+1] < L[j]){
                k = L[j];
                L[j] = L[j+1];
                L[j+1] = k;
            }
        }
    }

    printf("\nBubble shorted List -->");
    for(int i=0; i < MAXLIST; i++){
        printf(" %d | ", L[i]);
    }
}


