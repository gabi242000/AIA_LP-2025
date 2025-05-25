#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v, *v_filtrat;
    int n, i, contor= 0;
    float media= 0;

    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);

    v=(int *)malloc(n * sizeof(int));
    if(v == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }

    printf("Introduceti cele %d valori:\n", n);
    for(i= 0; i< n;i++) {
        scanf("%d", &v[i]);
        media+= v[i];
    }

    media/= n;

    // Alocam pentru filtrat (in cel mai rau caz, toate sunt >= media)
    v_filtrat= (int *)malloc(n * sizeof(int));
    if(v_filtrat == NULL) {
        printf("Eroare la alocarea memoriei pentru vectorul filtrat!\n");
        free(v);
        return 1;
    }

    for(i= 0;i< n;i++) {
        if(v[i]>= media) {
            v_filtrat[contor++]= v[i];
        }
    }

    printf("Elementele >= media (%.2f) sunt: ", media);
    for (i= 0;i < contor;i++) {
        printf("%d ", v_filtrat[i]);
    }
    printf("\n");

    free(v);
    free(v_filtrat);
    return 0;
}
