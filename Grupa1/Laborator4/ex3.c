#include <stdio.h>
int main() {
    int n;
    printf("introdu dimensiunea matricei: ");
    scanf("%d", &n);
    int matrice[n][n];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(i<=j){
                matrice[i][j]=i + j + 1;
            } else {
                matrice[i][j]=matrice[j][i];
            }
        }
    }
    printf("matricea generata este:\n");
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    return 0;
}