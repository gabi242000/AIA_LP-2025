#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vector;
    int N,x;
    printf("Introduceti numarul de elemente (N):");
    scanf("%d",&N);

    vector=(int*)malloc(N*sizeof(int));

    if(vector==NULL)
        {
            printf("Eroare la alocarea memoriei!\n");
            return 1;
        }
    
    printf("Introduceti cele %d elemente:\n",N);
    for(int i=0;i<N;i++)
    {
        printf("vector[%d]= ",i);
        scanf("%d",&vector[i]);
    }
    printf("Introduceti numarul X: ");
    scanf("%d",&x);

    printf("Valorile din intervalul [%d,%d] sunt \n", x-5,x+5);
    for(int i=0;i<N;i++)
    {
        if(vector[i]>=x-5 && vector[i]<=x+5)
        {
            printf("%d",vector[i]);
        }
    }
    free(vector);
    return 0;
}