#include <stdio.h>
#include <stdlib.h>

int main(){
    int *A,*B,n,cnt=0;

    scanf("%d",&n);

    A = (int*)malloc(n*sizeof(int));

    if(A==NULL){
        printf("Eroare la alocarea memoriei pentru vectorul A ");
        return 1;
    }
    

    for(int i=0;i<n;i++)
        scanf("%d",&A[i]);

    B = (int*)malloc(n*sizeof(int));

    if(B==NULL){
        printf("Eroare la alocarea memoriei pentru vectorul B");
        return 1;
    }

    for(int i=n-1;i>=0;i--){
        B[cnt] = A[i];
        cnt++;
    }

    for(int i=0;i<n;i++)
        printf("%d ",A[i]);

    printf("\n");

    for(int i=0;i<n;i++)
        printf("%d ",B[i]);

    free(A);
    free(B);
        
}