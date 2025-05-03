#include <stdio.h>
#include <stdlib.h>

int n, suma, numar, medie_aritmetica, contor;
int *v, *v_nou;

int main() {
    printf("Introduceti numarul de elemente: ");
    scanf("%d", &n);

    v = (int*)malloc(n * sizeof(int));

    if(v == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }

    printf("Introduceti cele %d valori:\n", n);
    for(int i = 0; i < n; i++) {
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
        suma += v[i];
        numar ++;
    }

    medie_aritmetica = suma / numar;
    printf("Media aritmetica a numerelor introduse este: %d\n", medie_aritmetica);

    v_nou = (int*)malloc(n * sizeof(int));

    if(v_nou == NULL) {
        printf("Eroare la alocarea memoriei pentru vectorul nou!\n");
        free(v_nou);
        return 1;
    }

    for(int i = 0; i < n; i++) {
        if(v[i] >= medie_aritmetica) {
            v_nou[contor++] = v[i];
        }
    }

    printf("Elementele mai mari sau egale cu media aritmetica sunt:\n");
    for(int i = 0; i < contor; i++) {
        printf("%d ", v_nou[i]);
    }

    free(v);
    free(v_nou);
    return 0;
}