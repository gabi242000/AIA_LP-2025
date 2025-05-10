#include <stdio.h>
#include <stdlib.h>
int main() {
    int N;
    printf("Introdu dimensiunea matricii identitate (N): ");
    scanf("%d", &N);
    int **matrice = (int **)malloc(N * sizeof(int *));
    if (matrice == NULL) {
        printf("Eroare la alocarea memoriei pentru liniile matricii.\n");
        return 1;
    }
    for (int i = 0; i < N; i++) {
        matrice[i] = (int *)malloc(N * sizeof(int));
        if (matrice[i] == NULL) {
            printf("Eroare la alocarea memoriei pentru coloanele matricii.\n");
            for (int j = 0; j < i; j++) {
                free(matrice[j]);
            }
            free(matrice);
            return 1;
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrice[i][j] = (i == j) ? 1 : 0;
        }
    }
    printf("Matricea identitate de dimensiune %d x %d:\n", N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < N; i++) {
        free(matrice[i]);
    }
    free(matrice);
    return 0;
}
