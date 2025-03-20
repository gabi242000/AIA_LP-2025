#include <stdio.h>

int main()

{
    int i,j,N;
    int s,smx=-1,rsmx=-1;

    printf("Introdu dimensiune matricei: ");
    scanf("%d",&N);
    int a[N][N];
    for (i=0;i<N;i++){
        for(j=0;j<N;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<N;i++)
    {
        s=0;
        for(j=0;j<N;j++){
            s+=a[i][j];
        }
            if(s>smx){
                smx=s;
                rsmx=i;
            }
        
    }
    printf("Linia cu suma maxima este: ");
    for(j=0;j<N;j++)
    {
        printf("%d ",a[rsmx][j]);
    }

    printf("(%d)",rsmx+1);

    printf("\n");
    printf("Suma maxima de pe o linie din matrice este: %d",smx);
}
