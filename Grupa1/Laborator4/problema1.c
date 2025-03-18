#include <stdio.h>
int main()
{
    int a[101][101];
    int n,i,j,s,mx=-1,rm;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        {
            s=0;
            for(j=1;j<=n;j++)
            {
                scanf("%d", &a[i][j]);
                s+=a[i][j];
            }
            if(s>mx)
            {
                mx=s;
                rm=i;
            }
        }
    printf("suma maxima: %d\n", mx);
    printf("randul maxim:");
    for(j=1;j<=n;j++)
        printf(" %d", a[rm][j]);
    return 0;
}
