#include <stdio.h>
int main()
{
    int v[101];
    int n,i,j,a;
    scanf("%d", &n);
    for(i=1;i<=n;i++)
        scanf("%d", &v[i]);
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(v[i]>v[j])
            {
                a=v[i];
                v[i]=v[j];
                v[j]=a;
            }
    for(i=1;i<=n;i++)
        if(v[i-1]==v[i])
            {
                for(j=i;j<=n;j++)
                    v[j]=v[j+1];
                n--;
            }
    printf("vectorul sortat:");
    for(i=1;i<=n;i++)
            printf(" %d", v[i]);
    return 0;
}
