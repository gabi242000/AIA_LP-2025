#include <stdio.h>
int main()
{

    int N,i,j;
    printf("Introdu dimensiunea matricei patratice: ");
    scanf("%d",&N);
    int a[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        if(i<=j)
             a[i][j]=i+j+1;
        else if(i>j)
            a[i][j]=a[j][i];
    }
    printf("Matricea generata este: \n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
        printf("%d",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}