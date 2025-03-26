#include <stdio.h>

int main() {
    int N;
    printf("Introdu dimensiunea vectorului: ");
    scanf("%d", &N);
    int v[N];
    printf("Introdu elementele: ");

    for (int i = 0; i < N; i++) {
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int t = v[j];
                v[j] = v[j + 1];
                v[j + 1] = t;
            }
        }
    }

    int N_nou = 1;
    for (int i = 1; i < N; i++) {
        if (v[i] != v[i - 1]) {
            v[N_nou++] = v[i];
        }
    }

    printf("Vectorul rezultat: ");
    for (int i = 0; i < N_nou; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
