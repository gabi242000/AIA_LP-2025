#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Introdu dimensiunea matricei identitate: ");
    scanf("%d", &n);

    
    int **mat = (int **)malloc(n * sizeof(int *));

    if (mat == NULL) {
        printf("Eroare la alocare memorie (linii).\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        mat[i] = (int *)malloc(n * sizeof(int));
        if (mat[i] == NULL) {
            printf("Eroare la alocare memorie (coloane).\n");
            for (int j = 0; j < i; j++) free(mat[j]);
            free(mat);
            return 1;
        }
    }

    // Construim matricea identitate
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = (i == j) ? 1 : 0;

    // Afișare
    printf("Matricea identitate %d x %d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // Eliberare memorie
    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);

    return 0;
}
