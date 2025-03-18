#include <stdio.h>
int main()
{
    int a[101][101];
    int n,i,j;
    printf("dimensiunea matricei: ");
    scanf(" %d", &n);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d", &a[i][j]);
    printf("elemente varf:");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i][j]>a[i-1][j]&&a[i][j]>a[i+1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i][j+1])
                    printf(" %d", a[i][j]);
        }
    return 0;
}
