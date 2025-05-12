#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;

    printf("Introdu numarul de elemente: ");
    scanf_s("%d", &n);

    if (n <= 0) {
        printf("numarul de elemente trebuie sa fie pozitiv.\n");
        return 1;
    }

    int* vector = (int*)malloc(n * sizeof(int));
    if (vector == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }

    printf("Introdu cele %d numere intregi:\n", n);
    for (i = 0; i < n; i++) {
        scanf_s("%d", &vector[i]);
    }

    int* invers = (int*)malloc(n * sizeof(int));
    if (invers == NULL) {
        printf("Eroare la alocarea memoriei pentru vectorul inversat!\n");
        free(vector);
        return 1;
    }

    for (i = 0; i < n; i++) {
        invers[i] = vector[n - 1 - i];
    }

    printf("Vectorul initial: ");
    for (i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    printf("Vectorul inversat: ");
    for (i = 0; i < n; i++) {
        printf("%d ", invers[i]);
    }
    printf("\n");

    free(vector);
    free(invers);

    return 0;
}
