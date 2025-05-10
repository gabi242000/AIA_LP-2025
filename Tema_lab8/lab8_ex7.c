#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, i, j;
    int **matrice;

    printf("Introduceti dimensiunea N a matricei identitate: ");
    scanf("%d", &N);

    matrice = (int **)malloc(N * sizeof(int *));
    if (matrice == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }

    for (i = 0; i < N; i++) {
        matrice[i] = (int *)malloc(N * sizeof(int));
        if (matrice[i] == NULL) {
            printf("Eroare la alocarea memoriei!\n");
            
            for (j = 0; j < i; j++) {
                free(matrice[j]);
            }
            free(matrice);
            return 1;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (i == j) {
                matrice[i][j] = 1;  
            } else {
                matrice[i][j] = 0;  
            }
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