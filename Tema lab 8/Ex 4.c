#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Introduceti numarul de elemente: ");
    scanf("%d", &N);

    int* v = (int*)malloc(N * sizeof(int));
    if (v == NULL) {
        printf("Alocare esuata.\n");
        return 1;
    }

    printf("Introduceti elementele:\n");
    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    double suma = 0;
    for (int i = 0; i < N; ++i) {
        suma += v[i];
    }
    double media = suma / N;

    int* rezultat = (int*)malloc(N * sizeof(int)); // max posibil
    int k = 0;
    for (int i = 0; i < N; ++i) {
        if (v[i] >= media) {
            rezultat[k++] = v[i];
        }
    }

    printf("Elemente >= media (%.2f):\n", media);
    for (int i = 0; i < k; ++i) {
        printf("%d ", rezultat[i]);
    }

    free(v);
    free(rezultat);
    return 0;
}
