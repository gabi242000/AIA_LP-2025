#include <stdio.h>
int main()
{
    int n;
    printf("Numarul de randuri si coloane:\n");
    scanf("%d", &n);
    int a[n][n], i, j;
    for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
    {
        if(i<=j)
        a[i][j]=i+j+1;
        else
        a[i][j]=a[j][i];
    }
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        printf("%d", a[i][j]);
        printf("\n");
    }
    return 0;
}