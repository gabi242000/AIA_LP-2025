#include <stdio.h>
#include <stdlib.h> 

int main() {
    int N;
    int *vector, *vector_invers;
    
    printf("Introduceti numarul de elemente (N): ");
    scanf("%d", &N);
    
    
    vector = (int*)malloc(N * sizeof(int));
    if (vector == NULL) {
        printf("Eroare la alocarea memoriei pentru vector!\n");
        return 1;
    }
    
    printf("Introduceti cele %d numere intregi:\n", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &vector[i]);
    }
    
    
    vector_invers = (int*)malloc(N * sizeof(int));
    if (vector_invers == NULL) {
        printf("Eroare la alocarea memoriei pentru vectorul invers!\n");
        free(vector); 
        return 1;
    }
    
    
    for (int i = 0; i < N; i++) {
        vector_invers[i] = vector[N - 1 - i];
    }
    
    
    printf("\nVectorul initial:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vector[i]);
    }
    
    
    printf("\n\nVectorul inversat:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", vector_invers[i]);
    }
    printf("\n");
    
    
    free(vector);
    free(vector_invers);
    
    return 0;
}