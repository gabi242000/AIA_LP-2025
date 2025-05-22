#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    printf("Numar elemente: ");
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));
    int *inv = malloc(n * sizeof(int));

    printf("Introduceti elementele:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    
    for (i = 0; i < n; i++) {
        inv[i] = v[n - 1 - i];
    }

    printf("Vector original: ");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    printf("\nVector inversat: ");
    for (i = 0; i < n; i++) {
        printf("%d ", inv[i]);
    }

    free(v);
    free(inv);
    return 0;
}
