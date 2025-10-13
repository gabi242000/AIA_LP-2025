#include <stdio.h>

int main(){
    int n, s = 0, smax = -1e6, randMax = 0;
    printf("Introdu dimensiunea matricei (nxn):");
    scanf("%d", &n);
    int m[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("Elementul m[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            s = s + m[i][j];
        }
        if (s > smax){
            smax = s;
            randMax = i + 1;
        }
        s = 0;
    }
    printf("Randul cu suma elementelor cea mai mare este randul %d cu suma %d", randMax, smax);
    return 0;
}