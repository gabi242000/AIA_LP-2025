#include <stdio.h>
#include <stdlib.h>

int main(){
    int **A,n;

    scanf("%d",&n);

    A = (int**)malloc(n*sizeof(int*));

    for(int i=1;i<=n;i++)
        A[i] = (int*)malloc(n*sizeof(int));

    if(A==NULL){
        printf("Eroare la alocarea memoriei pentru matricea A");
        return 1;
    }

    

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j) A[i][j]=1;
            else A[i][j]=0;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",A[i][j]);
        printf("\n");
    }

    free(A);
}