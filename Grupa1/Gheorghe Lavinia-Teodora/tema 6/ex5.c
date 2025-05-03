#include <stdio.h>
#include <stdlib.h>

int *v1, *v2;
int n;

int main() {
    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);

    v1 = (int*)malloc(n * sizeof(int));

    if(v1 == NULL) {
        printf("Eroare la alocarea memoriei vectorului 1!\n");
        return 1;
    }

    printf("Introduceti elementele vectorului:\n");
    for(int i = 0; i < n; i++) {
        printf("v1[%d] = ", i);
        scanf("%d", &v1[i]);
    }

    printf("Elementele primului vector sunt:\n");
    for(int i = 0; i < n; i++)
        printf("%d ", v1[i]);
    printf("\n");

    v2 = (int*)malloc(n * sizeof(int));

    if(v2 == NULL) {
        printf("Eroare la alocarea memoriei vectorului 2!\n");
        free(v2);
        return 1;
    }

    for(int i = 0; i < n; i++) {
        v2[i] = v1[n - i - 1];
    }

    printf("Elementele celui de-al doilea vector sunt:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", v2[i]);
    }
    
    free(v1);
    free(v2);
    
    return 0;
}