#include <stdio.h>

int main()
{
    int N;
    printf("Introdu numarul de linii si coloane ale matricei: ");
    scanf("%d",&N);
    int a[N][N];
    int i,j;

    for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++){
                a[i][j]=i+j+1;
                a[j][i]=a[i][j];

            }
        }
    printf("Matricea rezultata este:\n ");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ",a[i][j]);
            
        }printf("\n");
    }
    
    return 0;
}
