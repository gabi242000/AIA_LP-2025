#include <stdio.h>
int main()
{
    int n;
    printf("Introdu numarul de randuri:\n");
    scanf("%d", &n);
    int a[n][n], suma, i, j, suma_max=-99, rand_max;
    printf("Introdu elementele matricei.\n");
    for(i=1; i<=n; i++)
    for(j=1; j<=n; j++)
    {
        scanf("%d", &a[i][j]);
    }    
    for(i=1; i<=n; i++)
    {
        suma=0;
        for(j=1; j<=n; j++)
        suma=suma+a[i][j];
        if(suma>suma_max)
        {
            suma_max=suma;
            rand_max=i;
        } 
    }
    printf("Suma maxima este %d si se afla pe randul %d", suma_max, rand_max);
    return 0;
}