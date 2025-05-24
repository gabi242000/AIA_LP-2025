#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v1, *v2, n, i;

    printf("Introdu numarul de elemente ale vectorului.\n");
    scanf("%d", &n);
    v1=(int*)malloc(n * sizeof(int));
    if(v1 == NULL)
    {
        printf("Eroare la alocarea memoriei vectorului.\n");
        return 1;
    }
    printf("Introdu elementele vectorului\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &v1[i]);
    }
    v2=(int*)malloc(n * sizeof(int));
    if(v2 == NULL)
    {
        printf("Eroare la alocarea memoriei vectorului.\n");
        return 1;
    }
    for(i=0; i<n; i++)
    {
        v2[n-i-1] = v1[i];
    }

    printf("Primul vector este:\n v1={");
    for(i=0; i<n; i++)
    {
        printf("%d ",v1[i]);
    }
    printf("}.\n");

    printf("Al doilea vector este:\n v2={");
    for(i=0; i<n; i++)
    {
        printf("%d ", v2[i]);
    }
    printf("}.");
}