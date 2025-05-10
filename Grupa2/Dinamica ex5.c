#include <stdio.h>
#include <stdlib.h>
int main() {
    int N;
    printf("Introdu numarul de elemente: ");
    scanf("%d", &N);
    int *v = (int *)malloc(N * sizeof(int));
    if (v == NULL) {
        printf("Eroare la alocarea memoriei pentru vectorul original.\n");
        return 1;
    }
    printf("Introdu cele %d numere intregi:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }
    int *inv = (int *)malloc(N * sizeof(int));
    if (inv == NULL) {
        printf("Eroare la alocarea memoriei pentru vectorul inversat.\n");
        free(v);
        return 1;
    }
    for (int i = 0; i < N; i++) {
        inv[i] = v[N - 1 - i];
    }
    printf("Vectorul original:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
    printf("Vectorul inversat:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", inv[i]);
    }
    printf("\n");
    free(v);
    free(inv);

    return 0;
}
