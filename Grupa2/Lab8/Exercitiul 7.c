#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, j;

    printf("Introdu dimensiunea matricei n: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("Dimensiunea trebuie sa fie un numar pozitiv.\n");
        return 1;
    }

    int** matrice = (int**)malloc(n * sizeof(int*));
    if (matrice == NULL) {
        printf("Eroare la alocarea memoriei pentru liniile matricei!\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        matrice[i] = (int*)malloc(n * sizeof(int));
        if (matrice[i] == NULL) {
            printf("Eroare la alocarea memoriei pentru coloanele matricei!\n");
            for (j = 0; j < i; j++) {
                free(matrice[j]);
            }
            free(matrice);
            return 1;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j)  matrice[i][j] = 1;
            else matrice[i][j] = 0;
        }
    }

    printf("Matricea identitate de dimensiune %d x %d este:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        free(matrice[i]);
    }
    free(matrice);

    return 0;
}
