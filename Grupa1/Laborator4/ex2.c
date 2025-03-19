#include <stdio.h>

int main() {
    int n;
    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    int vector[n];
    printf("Introdu %d elemente: ", n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vector[j] > vector[j + 1]) {
                int temp = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = temp;
            }
        }
    }

    int nou_n = 0;
    int vector_fara_duplicate[n];

    for (int i = 0; i < n; i++) {
        if (i == 0 || vector[i] != vector[i - 1]) {
            vector_fara_duplicate[nou_n] = vector[i];
            nou_n++;
        }
    }

    printf("Vectorul sortat fara duplicate: ");
    for (int i = 0; i < nou_n; i++) {
        printf("%d ", vector_fara_duplicate[i]);
    }
    printf("\n");

    return 0;
}