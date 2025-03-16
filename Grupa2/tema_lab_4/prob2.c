#include <stdio.h>
int main()
{
    int n,m, i,j, aux;
    printf("Introdu dimensiunea vectorului: \n");
    scanf("%d",&n);
    int v[n];
    printf("Introdu elementele vectorului: \n");
    for(i=0;i<n;i++)
    scanf("%d", &v[i]);
    for(i=0;i<n-1;i++)
    for(j=i+1;j<n;j++)
        if(v[i]>v[j])
        {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
        }
    printf("Vectorul ordonat crescator este: \n");
    for(i=0;i<n;i++)
    printf("%d ",v[i]);
    printf("\n");
    for(i=1;i<n-1;i++)
    {
        if(v[i-1]==v[i])
        {
            v[i]=v[i+1];
            n--;
        }
    }
    printf("Vectorul sortat este: \n");
    for(i=0;i<n;i++)
    printf("%d ",v[i]);
    return 0;
}