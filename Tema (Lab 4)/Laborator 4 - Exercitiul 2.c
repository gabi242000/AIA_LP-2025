#include <stdio.h>

int main()
{
    int n,V[100],aux;
    printf("Introdu numarul de elemente: ");
    scanf("%d",&n);
    printf("Introdu si elementele vectorului:\n");
    for(int i=0;i<n;i++)
    {
        printf("Elementul [%d]: ",i+1);
        scanf("%d",&V[i]);
    }
    for(int i=0;i<n;i++)
        for(int j=i;j<n-1;j++)
            if(V[i]>V[j])
            {
                aux=V[i];
                V[i]=V[j];
                V[j]=aux;
            }
    printf("Vectorul sortat: ");
    for(int i=0;i<n;i++)
        printf("%d; ",V[i]);
    for(int i=0;i<n;i++)
        if(V[i]==V[i+1])
        {    
            for(int j=i+1;j<n;j++)
            {
                V[i]=V[j];
            }
            n--;
        }
    printf("\nVectorul cu duplicarile eliminate (in caz ca erau): ");
    for(int i=0;i<n;i++)
        printf("%d; ",V[i]);
}