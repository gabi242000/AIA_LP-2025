#include <stdio.h>
#include <stdlib.h>

int **a;
int n;

int main() {
    printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &n);

    a = (int**)malloc(n * sizeof(int*));
    if(a == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }
    for(int i = 0; i < n; i++) {
        a[i] = (int*)calloc(n, sizeof(int));
    }

    for(int i = 0; i < n; i++) 
        for(int j = 0 ; j < n; j++) {
            if(i == j)
               a[i][j] = 1;
        }

    printf("Matricea identitate este:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < n; j++) 
            printf("%d ", a[i][j]);
        printf("\n");
    }

    free(a);
    return 0;

}