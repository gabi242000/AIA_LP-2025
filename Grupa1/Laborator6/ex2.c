#include <stdio.h>
void determinant(float a[11][11], int n, float &det);
int esteinversabila(float a[11][11], int n);
int main()
{
    float a[11][11];
    int n,i,j;
    printf("introduceti dimensiunea matricii: ");
    scanf("%d", &n);
    printf("introduceti matricea:\n");
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%f", &a[i][j]);
    if(esteinversabila(a,n)==1)
        printf("matricea e inversabila");
    else
        printf("matricea nu e inversabila");
    return 0;
}
void determinant(float a[11][11], int n, float &det)
{
    det=1;
    int i,j;
    float div;
    if(a[1][1]==0)
        det=0;
    else
    {
        for(int k=1;k<n;k++)
        {
            for(i=k+1;i<=n;i++)
            {
                if(a[k][k]!=0)
                    div=a[i][k]/a[k][k];
                else
                    div=0;
                for(j=1;j<=n;j++)
                    a[i][j]=a[i][j]-(a[k][j]*div);
            }
        }
        for(i=1;i<=n;i++)
            det*=a[i][i];
        printf("\ndeterminantul matricii e: %.2f\n", det);
    }
}
int esteinversabila(float a[11][11], int n)
{
    float det;
    determinant(a,n,det);
    if(det)
        return 1;
    else
        return 0;
}
