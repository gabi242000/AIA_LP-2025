#include<stdio.h>

int main()
{
    int dim,matr[10][10];
    printf("Introduceti dim matricei: ");
    scanf("%d",&dim);
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            if(j >= i)
            {                
                matr[i][j] = i + j + 1;
            }
            else
            {
                matr[i][j] = matr[j][i];
            }
            printf("%d ",matr[i][j]);
        }
        printf("\n");
    }
   



}