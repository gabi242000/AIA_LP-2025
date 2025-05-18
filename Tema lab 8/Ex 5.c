#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Introduceti numarul de elemente: ");
    scanf("%d", &N);

    int* v = (int*)malloc(N * sizeof(int));
    if (v == NULL) return 1;

    printf("Introduceti elementele:\n");
    for (int i = 0; i < N; ++i) {
        scanf("%d", &v[i]);
    }

    int* invers = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        invers[i] = v[N - 1 - i];
    }

    printf("Vector original:\n");
    for (int i = 0; i < N; ++i) {
        printf("%d ", v[i]);
    }

    printf("\nVector inversat:\n");
    for (int i = 0; i < N; ++i) {
        printf("%d ", invers[i]);
    }

    free(v);
    free(invers);
    return 0;
}
