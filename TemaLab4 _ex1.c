#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a[n][n], i, j, s=0, max=-9999, rand=0;
    for(i=0;i<n;i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0; j<n; j++)
        {
            s=s+a[i][j];
        }
        if(s>=max)
        {
            max = s;
            rand = i+1;
        }
        s=0;
    }
    printf("Randul:%d \nMaximul:%d",rand,max);
    return 0;
}
