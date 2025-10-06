#include <stdio.h>



int main(){
    int n;
    printf("Scrieti un numar: ");
    scanf("%d",&n);
    int nrstelutefinal=n*2-1/2;
        for (int i=1;i<=n;i++){
            for (int j=1;j<=nrstelutefinal;j++){
                printf(" ");
            }
            for (int j=1;j<=i*2-1;j++){
                printf("*");
            }
            for (int j=1;j<=nrstelutefinal;j++){
                printf(" ");
            }
            nrstelutefinal--;
            printf("\n");
        }
        
    
    
    return 0;
}