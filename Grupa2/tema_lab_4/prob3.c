#include <stdio.h>
int main()
{
    int n, i, j;
    printf("Introdu dimensiunea matricii: \n");
    scanf("%d",&n);
    int a[n][n];
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        if(i<=j)
        {
            a[i][j]=i+j+1;
        }
        else a[i][j]=a[j][i];
    }
    printf("Matricea rezultata este: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
    return 0;
}