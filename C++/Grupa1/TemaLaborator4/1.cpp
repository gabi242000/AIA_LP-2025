#include <stdio.h>

int main(){
    int n;
    printf("Scrieti un numar: ");
    scanf ("%d",&n);
    int maxsuma=-9999;
    int suma[n]={};
    int a[n][n];
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            scanf("%d",&a[i][j]);

            suma[i]+=a[i][j];
        }
        if(suma[i]>maxsuma){
            maxsuma=suma[i];
        }
    }
    for (int i=0;i<n;i++){
        if(suma[i]==maxsuma){
            printf("Cea mai mare suma este pe randul %d",i+1);
            printf("\nsuma este %d",maxsuma);
            break;
        }
    }
    





    return 0;
}
    
