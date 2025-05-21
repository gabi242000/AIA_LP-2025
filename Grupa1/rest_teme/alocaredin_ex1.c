#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    int *v = (int *)malloc(n * sizeof(int));
    if (v == NULL) {
        printf("Eroare la alocare memorie.\n");
        return 1;
    }

    printf("Introdu %d numere intregi:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    double suma = 0;
    for (int i = 0; i < n; i++) {
        suma += v[i];
    }
    double media = suma / n;

    // Numărăm câte valori sunt ≥ media
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] >= media)
            k++;
    }

    int *rez = (int *)malloc(k * sizeof(int));
    if (rez == NULL) {
        printf("Eroare la alocarea vectorului rezultat.\n");
        free(v);
        return 1;
    }

    // Populăm noul vector
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] >= media)
            rez[idx++] = v[i];
    }

    printf("Elementele mai mari sau egale cu media (%.2lf):\n", media);
    for (int i = 0; i < k; i++) {
        printf("%d ", rez[i]);
    }
    printf("\n");

    free(v);
    free(rez);
    return 0;
}
