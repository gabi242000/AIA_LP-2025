#include <stdio.h>



int main() {
    int N;
    printf("Introdu numarul de linii si coloane ale matricei: ");
    scanf("%d", &N);
    
    int a[N][N];
    printf("Introdu valorile matricei:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    
    int vf = -1, linie = -1, coloana = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i == 0 || a[i][j] > a[i-1][j]) && (i == N-1 || a[i][j] > a[i+1][j]) && (j == 0 || a[i][j] > a[i][j-1]) && (j == N-1 || a[i][j] > a[i][j+1])) 
            {
                vf = a[i][j];
                linie = i;
                coloana = j;
            }
        }
    }
    
    if (vf != -1)
        printf("Elementul de varf al matricei este %d (Linia: %d, Coloana: %d)\n", vf, linie+1, coloana+1);
    else
        printf("Nu exista element de varf in matrice.\n");
    
    return 0;
}
