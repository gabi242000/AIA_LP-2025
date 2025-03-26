#include <stdio.h>

int main() {
    int N;
    printf("Introduceți dimensiunea matricei : ");
    scanf("%d", &N);
    int matrice[N][N];
    printf("Introduceți elementele matricei:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    int suma_max = 0, rand_max = 0;
    for (int i = 0; i < N; i++) {
        int suma = 0;
        for (int j = 0; j < N; j++) {
            suma += matrice[i][j];
        }

        if (suma > suma_max) {
            suma_max = suma;
            rand_max = i;
        }
    }
    printf("Rândul cu suma maximă: %d\n", rand_max + 1);  
    printf("Suma maximă: %d\n", suma_max);

    return 0;
}
