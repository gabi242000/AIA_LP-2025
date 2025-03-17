#include <stdio.h>

int main(){
    int n,mat[20][20];

    printf("n=");
    scanf("%d",&n);


    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i<=j) mat[i][j]= i+j+1;
            else if(i>j) mat[i][j]= mat[j][i];

printf("Matricea rezultata este: \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",mat[i][j]);

    printf("\n");
    }
}