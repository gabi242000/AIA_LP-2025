#include <stdio.h>
int main()
{
    int n, i, j;
    printf("Introdu numarul de nivele al piramidei:\n");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<=n+i; j++)
        if(j < n-i)
        printf(" ");
        else
        printf("*");
        printf("\n");
    }
    return 0;
}