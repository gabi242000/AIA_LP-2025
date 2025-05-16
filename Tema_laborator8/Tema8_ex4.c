#include<stdio.h>
#include<stdlib.h>

int main(){
    int **m;
    int i,j,n;
    printf("introdu dimensiunea matricei: ");
    scanf("%d",&n);
    m = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) m[i] = (int*)malloc(n * sizeof(int));
    if(m==NULL){
        printf("eroare la alocarea memorie");
        return 1;
    }
    for(i = 0; i < n; i++) {
         for(j = 0; j < n; j++) {
             if(i == j) m[i][j] = 1;
             else m[i][j] = 0;
    }
}
    printf("Matricea identitate este: \n");
    for(i = 0; i < n; i++) {
         for(j = 0; j < n; j++) printf("%d ",m[i][j]);
         printf("\n");
    }
    free(m);
    return 0;
}