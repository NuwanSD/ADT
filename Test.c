

int main(){

    for(int i=0; i<= MAXLIST-2; i++){
        for(int j=0; j<= MAXLIST-2-i; j++){
            if(L[j+1] < L[j]){
                int k = L[j];
                L[j] = L[j+1];
                L[j+1] = k;
            }
        }
    }

}
