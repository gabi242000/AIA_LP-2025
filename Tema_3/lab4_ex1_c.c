#include <stdio.h>
int main()
{
    int N,i,j,suma_maxima,rand_maxim,suma_rand;
    printf("Introdu dimensiunea matricei: ");
    scanf("%d",&N);
    int a[N][N];
    printf("Introdu elementele matricei: ");
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        scanf("%d",&a[i][j]);
    }
    suma_maxima=-1;
    rand_maxim=-1;
    for(i=0;i<N;i++)
    {
        suma_rand=0;
        for(j=0;j<N;j++)
        {
            suma_rand=suma_rand+a[i][j];
        }
        if(suma_rand>suma_maxima)
        {
            suma_maxima=suma_rand;
            rand_maxim=i;
        }
    }
    printf("Randul cu suma maxima este: %d\n",rand_maxim);
    printf("Suma maxima este %d\n",suma_maxima);
    return 0;
}
