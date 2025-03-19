#include <stdio.h>

int main(){
    int n;
    printf("Scrieti un numar: ");
    scanf ("%d",&n);
    int a[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if(i<=j)
            a[i][j]=i+j+1;
            else 
            a[i][j]=a[j][i];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }



    return 0;
}