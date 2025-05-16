#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vector;
    int n,x;
    printf("Introdu nr de elemente: ");
    scanf("%d",&n);
    vector=(int*)malloc(n * sizeof(int));
    if(vector == NULL){
        printf("Eroare la alocarea memoriei\n");
        return 1;
    }
    printf("Introduceti elementele vectorului: \n");
    for(int i=0; i<n; i++){
        printf("Elementul[%d]= ",i);
        scanf("%d",&vector[i]);
    }
    printf("Introdu numarul x: ");
    scanf("%d",&x);
    printf("Valorile din intervalul [%d][%d] sunt: ", x-5,x+5);
    for(int i=0; i<n; i++){
        if(vector[i]>=x-5 && vector[i]<=x+5) printf("%d ", vector[i]);
    }
    free(vector);
    return 0;
}