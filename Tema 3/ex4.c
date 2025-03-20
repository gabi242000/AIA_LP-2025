#include<stdio.h>
int main()
{
    int dim,matr[10][10],varf = 0;
    printf("Introduceti dim matricei: ");
    scanf("%d",&dim);
    for(int i = 0; i <= dim; i++)
    {
        matr[i][0] = 0;
        matr[0][i] = 0;
        matr[dim+1][i] = 0;
        matr[i][dim+1] = 0;
    }
    matr[dim+1][dim+1] = 0;
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            scanf("%d",&matr[i][j]);
        }
    }
    for(int i = 0; i <= dim+1; i++)
    {
        for(int j = 0; j <= dim+1; j++)
        {
            printf("%d ",matr[i][j]);
        }
    printf("\n");
    }
    for(int i = 1; i <= dim; i++)
    {
        for(int j = 1; j <= dim; j++)
        {
            if(matr[i][j] > matr[i-1][j] && matr[i][j] > matr[i+1][j] && matr[i][j] > matr[i][j - 1] && matr[i][j] > matr[i][j + 1])
            {
                varf = matr[i][j];
                break;
            }
        }
        if(varf!=0)
            break;
    }
    if(varf != 0)
        printf("%d",varf);
    else
        printf("Nu exista varf!");

}