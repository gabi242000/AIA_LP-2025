/**
7. Scrie un program care, folosind alocare dinamică, generează o matrice identitate de 
dimensiune N x N, unde N este citit de la tastatură. Afișează matricea.
**/

    #include <stdio.h>
    #include <stdlib.h>

    int main() {
        int N, i, j;

        printf("Introduceti dimensiunea matricei (N): ");
        scanf("%d", &N);

        int **matrice = (int **)malloc(N * sizeof(int *));

        for (i = 0; i < N; i++) {
            matrice[i] = (int *)malloc(N * sizeof(int));
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

        printf("Matricea %d x %d:\n", N, N);
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