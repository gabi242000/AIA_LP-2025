#include <stdio.h>
#include <stdbool.h>
int main()
{
    int N,i,aux,dimensiune_noua;
    bool sortat;
    printf("Introdu dimensiunea vectorului: ");
    scanf("%d",&N);
    int v[N];
    printf("Introdu elementele vectorului: ");
    for(i=0;i<N;i++)
    {
        scanf("%d",&v[i]);
    }
    //Sortarea vectorului prin metoda BubbbleSort
    do
    {
        sortat=true;
        for(i=0;i<N-1;i++)
        {
            if(v[i]>v[i+1])
            {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                sortat=false;
            }
        }
    }
    while(!sortat);
    printf("Elementele vectorului dupa sortare sunt: ");
    for(i=0;i<N;i++)
    {
        printf("%d",v[i]);
    }
    printf("\n");
    dimensiune_noua = 0; 
    for (i = 0; i < N; i++)
     {
        if (i == 0 || v[i] != v[i - 1]) 
        {
            v[dimensiune_noua] = v[i];
            dimensiune_noua++; 
        }
    }
    printf("Elementele vectorului fara duplicate sunt: ");
    for (i = 0; i < dimensiune_noua; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}