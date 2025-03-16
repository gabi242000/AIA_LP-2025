#include <stdio.h>

int main()
{
    int n,X[10][10],s=0,max_S=0,lin=0;
    printf("Introdu numarul de linii si coloane ale matricei: ");
    scanf("%d",&n);
    printf("Introdu si elementele matricei de asemenea: ");
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            printf("Elementul [%d][%d]: ",i,j);
            scanf("%d",&X[i][j]);
        }
    for(int i=1;i<=n;i++)
    {
        s=0; 
        for(int j=1;j<=n;j++)
            s+=X[i][j];
        if(max_S<s){
            max_S=s;
            lin=i;
        }
    }
    printf("\nSuma maxima: %d (linia %d)",s,lin);
    printf("\nElementele de pe linie: ");
    for(int j=1;j<=n;j++)
        printf("%d; ",X[lin][j]);
    return 0;
}