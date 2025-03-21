#include <stdio.h>
int main(){
    int v[101], n, i,j,aux;
    printf ("n: ");
    scanf ("%d",&n);
    for (i=1;i<=n;i++)
        scanf ("%d",&v[i]);
    for (i=1;i<=n;i++)
        for (j=i;j<=n;j++)
            if (v[i]>v[j]){
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }         
    for (i=1;i<=n;i++)
        if (v[i]==v[i-1]){
            for (j=i;j<=n;j++)
                v[j]=v[j+1];
            n--;}
    
    for (i=1;i<=n;i++)
        printf("%d ", v[i]);
}