#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, count = 0;
    float media = 0;

    printf("Introdu numarul de elemente: ");
    scanf_s("%d", &n);

    int* vector = (int*)malloc(n * sizeof(int));
    if (vector == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }

    printf("Introdu cele %d numere intregi:\n", n);
    for (i = 0; i < n; i++) {
        scanf_s("%d", &vector[i]);
        media += vector[i];
    }

    media /= n;

    for (i = 0; i < n; i++) {
        if (vector[i] >= media) {
            count++;
        }
    }

    int* vector_nou = (int*)malloc(count * sizeof(int));
    if (vector_nou == NULL) {
        printf("Eroare la alocarea memoriei pentru noul vector!\n");
        free(vector);
        return 1;
    }

    int j = 0;
    for (i = 0; i < n; i++) {
        if (vector[i] >= media) {
            vector_nou[j++] = vector[i];
        }
    }

    printf("Media aritmetica este: %.2f\n", media);
    printf("Elementele mai mari sau egale cu media sunt:\n");
    for (i = 0; i < count; i++) {
        printf("%d ", vector_nou[i]);
    }
    printf("\n");

    free(vector);
    free(vector_nou);

    return 0;
}
