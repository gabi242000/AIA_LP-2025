#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, **a;

    printf("Introdu numarul de linii si de coloane ale matricii patratice.\n");
    scanf("%d", &n);

    a = (int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(i==j)
            {
                a[i][j] = 1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
    

    printf("Matricea identitate cu %d linii si %d coloane este:\n", n, n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}