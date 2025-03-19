#include <stdio.h>
int main(){
    int a[101][101],n,i,j;
    printf ("n: ");
    scanf ("%d",&n);
    for (i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if (j>=i)
                a[i][j]=i+j+1;
            else
                a[i][j]=a[j][i];


    for (i=1;i<=n;i++){
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}