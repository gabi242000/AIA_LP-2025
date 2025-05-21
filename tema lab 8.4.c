#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i, j;

    printf("Dimensiunea matricei: ");
    scanf("%d", &N);

    
    int **matrice = malloc(N * sizeof(int *));
    for (i = 0; i < N; i++) {
        matrice[i] = malloc(N * sizeof(int));
    }

    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j)
                matrice[i][j] = 1;
            else
                matrice[i][j] = 0;
        }
    }

    
    printf("Matricea identitate %dx%d:\n", N, N);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    
    for (i = 0; i < N; i++) {
        free(matrice[i]);
    }
    free(matrice);

    return 0;
}
