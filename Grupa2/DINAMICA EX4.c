#include <stdio.h>
#include <stdlib.h>
int main() {
    int N;
    printf("Introdu numarul de elemente: ");
    scanf("%d", &N);
    int *v = (int *)malloc(N * sizeof(int));
    if (v == NULL) {
        printf("Eroare la alocarea memoriei.\n");
        return 1;
    }
    printf("Introdu cele %d numere intregi:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    double suma = 0;
    for (int i = 0; i < N; i++) {
        suma += v[i];
    }
    double media = suma / N;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] >= media) {
            count++;
        }
    }
    int *rezultat = (int *)malloc(count * sizeof(int));
    if (rezultat == NULL) {
        printf("Eroare la alocarea memoriei pentru vectorul rezultat.\n");
        free(v);
        return 1;
    }
    int j = 0;
    for (int i = 0; i < N; i++) {
        if (v[i] >= media) {
            rezultat[j++] = v[i];
        }
    }
    printf("Valorile mai mari sau egale cu media (%.2f):\n", media);
    for (int i = 0; i < count; i++) {
        printf("%d ", rezultat[i]);
    }
    printf("\n");

    free(v);
    free(rezultat);

    return 0;
}
