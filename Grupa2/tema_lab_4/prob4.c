#include <stdio.h>
int main()
{
    int n,m, i,j,max=0,imax=0,jmax=0;
    printf("Introdu dimensiunea matricei: \n");
    scanf("%d",&n);
    int v[n][n];
    printf("Introdu elementele matricei: \n");
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    scanf("%d", &v[i][j]);
    for(i=1;i<n-1;i++)
    for(j=1;j<n-1;j++)
        if(v[i][j]>v[i][j+1]&&v[i][j]>v[i+1][j]&&v[i][j]>v[i][j-1]&&v[i][j]>v[i-1][j])
        {
            if(v[i][j]>max) 
            {
                max=v[i][j];
                imax=i;
                jmax=j;
            }
        }
    if(max!=0)
    printf("Cel mai mare element varf al matricei este: %d, de pe linia %d si coloana %d\n",max, imax, jmax);
    else printf("Nu exista un element varf.");
}