#include<stdio.h>

int main()
{
    int dim,sMax = 0,sAct = 0,iMax = 0,matr[10][10];
    printf("Introduceti dim matricei: ");
    scanf("%d",&dim);
    for(int i = 0; i < dim; i++)
    {
        sAct = 0;
        for(int j = 0; j < dim; j++)
        {
            scanf("%d",&matr[i][j]);
            sAct = sAct + matr[i][j];
        }
        if(sAct > sMax)
        {
            sMax = sAct;
            iMax = i;
        }
    }
    iMax = iMax+1;
    printf("Randul %d are suma maxima: %d ",iMax,sMax);



}