#include <stdio.h>

int main(){
    int n, mat[20][20],s, max=-9999, indice_max;

    printf("n= ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d", &mat[i][j]);

    for(int i=0;i<n;i++){
        s=0;
        for(int j=0;j<n;j++)
            s+=mat[i][j];
        
        if(s>max) {
            max=s; 
            indice_max=i;
        }
}

    printf("Randul : %d\n", indice_max);
    printf("Suma maxima : %d\n", max);

}