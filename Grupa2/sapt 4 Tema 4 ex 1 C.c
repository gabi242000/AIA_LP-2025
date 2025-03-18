#include <stdio.h>

int main() {
    int N;
    printf("Introduceți dimensiunea matricei (N): ");
    scanf("%d", &N);

    int matrice[N][N];
    printf("Introduceți elementele matricei:\n");
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }

    int max_suma = -1, rand_max = 0;
    
    for (int i = 0; i < N; i++) {
        int suma = 0;
        for (int j = 0; j < N; j++) {
            suma += matrice[i][j];
        }
        if (suma > max_suma) {
            max_suma = suma;
            rand_max = i;
        }
    }
    
    printf("Rândul cu suma maximă este %d cu suma %d.\n", rand_max + 1, max_suma);
    
    return 0;
}


