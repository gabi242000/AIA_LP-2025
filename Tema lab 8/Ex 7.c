#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &N);

    int** mat = (int**)malloc(N * sizeof(int*));
    for (int i = 0; i < N; ++i) {
        mat[i] = (int*)malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j)
            {
                mat[i][j] = 1;
            }
            else
            {
                mat[i][j] = 0;
            }
        }
    }

    printf("Matricea identitate:\n");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < N; ++i) {
        free(mat[i]);
    }
    free(mat);
    return 0;
}
