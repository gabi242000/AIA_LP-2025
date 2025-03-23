#include <stdio.h>
int main()
{
    int n,elem;
    printf("Numarul de randuri si coloane ale matricei:\n");
    scanf("%d", &n);
    int a[n][n], i, j;
    printf("Completeaza elementele matricei.\n");
    for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
    {
        scanf("%d", &a[i][j]);
    }
    
    for(i=2;i<=n-1;i++)
    for(j=2;j<=n-1;j++)
    if(a[i][j]>a[i-1][j] && a[i][j]>a[i][j+1] && a[i][j]>a[i+1][j] && a[i][j]>a[i][j-1])
    {
        elem=a[i][j];
    }
    printf("%d", elem);
    return 0;
}