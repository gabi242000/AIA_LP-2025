#include <stdio.h>
int main(){
    int a[101][101],n,i,j,vf=0,vfi,vfj;
    printf ("n: ");
    scanf ("%d",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            scanf("%d",&a[i][j]);

    //am considerat doar cazul in care are toti 4 vecini (nu e la margine)
    for (i=2;i<=n-1;i++)
        for(j=2;j<=n-1;j++)
            if (a[i][j]>a[i-1][j] && a[i][j]>a[i+1][j] && a[i][j]>a[i][j-1] && a[i][j]>a[i][j+1]){
                vf=a[i][j];
                vfi=i;
                vfj=j;
            }
    printf("vf: %d\n",vf);
    printf("coordonatele vf sunt: linia %d si coloana %d", vfi, vfj);
}