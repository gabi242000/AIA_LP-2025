#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v;
    int *v_pare;
    int N,i,ip=0;

    printf("Introduceti numarul de elemente:");
    scanf("%d",&N);

    v=(int*)malloc(N*sizeof(int));
    if(v==NULL)
    {
        printf("Eroare la alocarea memoriei:\n");
        return 1;
    }
    printf("Introduceti cele %d elemente:",N);
    for(i=0;i<N;i++)
    {
        printf("v[%d]=",i);
        scanf("%d",&v[i]);
    }

    v_pare=(int*)malloc(N*sizeof(int));
    if(v_pare==NULL)
    {
        printf("Eroare la alocarea memoriei:\n");
        return 1;
    }
    for(i=0;i<N;i++)
    {
        if(v[i]%2==0)
        {
            v_pare[ip]=v[i];
            ip++;
        }
    }
    printf("Valorile pare sunt:\n");
    for(i=0;i<ip;i++)
    {
        printf("%d",v_pare[i]);
    }
    printf("\n");
    free(v);
    free(v_pare);
    return 0;
}