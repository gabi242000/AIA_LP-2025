#include <stdio.h>

int main() {
    int N;
    printf("Introdu dimensiunea matricei N: ");
    scanf("%d", &N);
    int matrice[N][N];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j >= i) {
                matrice[i][j] = i + j + 1;  
            } else {
                matrice[i][j] = matrice[j][i];  
            }
        }
    }

    printf("Matricea generata:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    return 0;
}
