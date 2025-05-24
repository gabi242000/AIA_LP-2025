#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v, *v2, n, m=0, i, j, sum=0, ma;

printf("Introdu numarul de elemente ale vectorului:\n");
scanf("%d", &n);

v=(int*)malloc(n*sizeof(int));
if (v==NULL)
{
    printf("Eroare la alocarea memoriei primului vector.\n");
    return 1;
}

printf("Introdu elementele vectorului.\n");
for(i=0; i<n; i++)
{
    scanf("%d", &v[i]);
    sum=sum+v[i];
}

ma=sum/n;

v2=(int*)malloc(n*sizeof(int));
if (v2==NULL)
{
    printf("Eroare la alocarea memoriei celui de al doilea vector.\n");
    return 1;
}

for(i=0; i<n; i++)
{
    if( v[i]>=ma )
    {
        for(j=0; i<n; j++)
        {
            v2[j] = v[i];
            m++;
        }
    }
}

printf("Al doilea vector este:\n");
for(i=0; i<m; i++)
    printf("%d, ", v2[i]);
return 0;
}