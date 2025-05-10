#include <stdio.h>
#include <stdlib.h> 

int main() {
    int N;
    printf("Introduceti numarul de elemente (N): ");
    scanf("%d", &N);

    
    int *vector = (int*)malloc(N * sizeof(int));
    if (vector == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }

    
    printf("Introduceti cele %d numere intregi:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &vector[i]);
    }

    
    double suma = 0;
    for (int i = 0; i < N; i++) {
        suma += vector[i];
    }
    double media = suma / N;
    printf("Media aritmetica: %.2f\n", media);

    
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (vector[i] >= media) {
            count++;
        }
    }

    
    int *vector_filtrat = (int*)malloc(count * sizeof(int));
    if (vector_filtrat == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        free(vector);
        return 1;
    }

    
    int nr = 0;
    for (int i = 0; i < N; i++) {
        if (vector[i] >= media) {
            vector_filtrat[nr] = vector[i];
            nr++;
        }
    }

    printf("Elementele mai mari sau egale cu media (%.2f):\n", media);
    for (int i = 0; i < count; i++) {
        printf("%d ", vector_filtrat[i]);
    }
    printf("\n");
    
    free(vector);
    free(vector_filtrat);

    return 0;
}