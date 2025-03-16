#include <stdio.h>

int main ()
{
    int N,i,j;
    bool gasit=0;
    printf("Introdu dimensiunea matricei patratice: ");
    scanf("%d",&N)
    int a[N][N];
    printf("Introdu elementele matricei patratice: ");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        scanf("%d",&a[i][j]);
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if( (a[i][j]>a[i][j-1]) && (a[i][j]>a[i][j+1]) && (a[i][j]>a[i-1][j]) &&(a[i][j]>a[i+1][j]))
            {
                printf("Elementul varf este: %d\n",a[i][j]);
                gasit=1;
            }
        }
    }
    if(gasit==0) printtf("Matricea nu contine niciun element varf.");
    return 0;
}