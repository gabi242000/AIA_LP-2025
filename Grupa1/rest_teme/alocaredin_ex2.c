#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    int *v = (int *)malloc(n * sizeof(int));
    int *inv = (int *)malloc(n * sizeof(int));

    if (v == NULL || inv == NULL) {
        printf("Eroare la alocare memorie.\n");
        return 1;
    }

    printf("Introdu %d valori:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    // Inversare
    for (int i = 0; i < n; i++) {
        inv[i] = v[n - 1 - i];
    }

    printf("Vector original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    printf("\nVector inversat: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", inv[i]);
    }
    printf("\n");

    free(v);
    free(inv);
    return 0;
}
