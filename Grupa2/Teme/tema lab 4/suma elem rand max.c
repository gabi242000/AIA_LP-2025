#include <stdio.h>
int main(){
    int n,i,j,a[101][101],suma,maxim=-1,rand;
    printf("n: ");
    scanf("%d",&n);
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for (i=1;i<=n;i++){
        suma=0;
        for (j=1;j<=n;j++)
            suma=suma+a[i][j];
        if (maxim<suma){
            maxim=suma;
            rand=i;
        }
    }
    
    printf("randul: %d\n",rand);
    printf("suma max: %d",maxim);
    return 0;
}