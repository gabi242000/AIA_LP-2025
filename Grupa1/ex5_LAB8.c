#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v, *v_invers;
    int n, i;

    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);

    v= (int *)malloc(n * sizeof(int));
    if(v == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }

    printf("Introduceti cele %d valori:\n", n);
    for(i= 0;i< n;i++) {
        scanf("%d", &v[i]);
    }

    v_invers=(int *)malloc(n * sizeof(int));
    if(v_invers== NULL) {
        printf("Eroare la alocarea memoriei pentru vectorul inversat!\n");
        free(v);
        return 1;
    }

    for(i= 0;i < n;i++) {
        v_invers[i]= v[n-i-1];
    }

    printf("Vectorul original: ");
    for (i= 0;i< n;i++) {
        printf("%d ", v[i]);
    }

    printf("\nVectorul inversat: ");
    for (i= 0;i< n;i++) {
        printf("%d ", v_invers[i]);
    }

    printf("\n");

    free(v);
    free(v_invers);
    return 0;
}
