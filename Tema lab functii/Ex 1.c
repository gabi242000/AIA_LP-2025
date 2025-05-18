#include <stdio.h>

#define MAX 100

int esteSimetrica(int A[MAX][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (A[i][j] != A[j][i])
                return 0; // fals, nu este simetrică
        }
    }
    return 1; // adevărat
}

void transpuneMatrice(int A[MAX][MAX], int T[MAX][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            T[j][i] = A[i][j];
        }
    }
}

int estePartialMagica(int A[MAX][MAX], int n) {
    int suma_diag1 = 0, suma_diag2 = 0;
    for (int i = 0; i < n; ++i) {
        suma_diag1 += A[i][i];
        suma_diag2 += A[i][n - 1 - i];
    }
    return (suma_diag1 == suma_diag2);
}

void afiseazaMatrice(int M[MAX][MAX], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int A[MAX][MAX], T[MAX][MAX];

    printf("Introduceti dimensiunea matricei patratice (n): ");
    scanf("%d", &n);

    printf("Introduceti elementele matricei A (%d x %d):\n", n, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            scanf("%d", &A[i][j]);

    // 1. Verificare simetrie
    if (esteSimetrica(A, n))
        printf("Matrice simetrica\n");
    else
        printf("Matrice nesimetrica\n");

    // 2. Transpunere
    transpuneMatrice(A, T, n);
    printf("Matricea transpusa:\n");
    afiseazaMatrice(T, n);

    // 3. Verificare partial magica
    if (estePartialMagica(A, n))
        printf("Matrice partial magica\n");
    else
        printf("Matrice obisnuita\n");

    return 0;
}
