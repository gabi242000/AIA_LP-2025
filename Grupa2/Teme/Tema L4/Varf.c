#include <stdio.h>
int main(){
    int a[101][101],n,i,j,varf=0,varfi,varfj;
    printf ("n: ");
    scanf ("%d",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for (i=2;i<=n-1;i++)
        for(j=2;j<=n-1;j++)
            if (a[i][j]>a[i-1][j] && a[i][j]>a[i+1][j] && a[i][j]>a[i][j-1] && a[i][j]>a[i][j+1]){
                varf=a[i][j];
                varfi=i;
                varfj=j;
            }
    printf("Varf: %d\n",varf);
    printf("Coordonatele varfului sunt: linia %d si coloana %d", varfi, varfj);
}
