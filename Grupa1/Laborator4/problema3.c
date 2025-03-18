#include <stdio.h>
int main()
{
    int a[101][101];
    int n,i,j;
    printf("dimensiunea matricei: ");
    scanf("%d", &n);
    printf("\nmatricea generata");
    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=1;j<=n;j++)
            {
                if(i>j)
                    a[i][j]=a[j][i];
                else
                    a[i][j]=i+j+1;
                printf(" %d", a[i][j]);
            }
    }
    return 0;
}
