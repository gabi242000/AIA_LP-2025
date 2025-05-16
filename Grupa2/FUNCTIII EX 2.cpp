#include <stdio.h>
#define N 10
float determinant(float m[][N], int n) {
    float det = 1;
    for (int i = 0; i < n; i++) {
        if (m[i][i] == 0) {
            int sw = 0;
            for (int k = i + 1; k < n; k++) {
                if (m[k][i] != 0) {
                    for (int j = 0; j < n; j++)
                        m[i][j] += m[k][j];  
                    sw = 1;
                    break;
                }
            }
            if (!sw) return 0;
        }

        for (int k = i + 1; k < n; k++) {
            float f = m[k][i] / m[i][i];
            for (int j = i; j < n; j++)
                m[k][j] -= f * m[i][j];
        }
        det *= m[i][i];
    }
    return det;
}

int esteInversabila(float m[][N], int n) {
    float copie[N][N];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            copie[i][j] = m[i][j];

    return determinant(copie, n) != 0;
}

int main() {
    float m[N][N];
    int n;
    printf("Dimensiunea matricei patratice: ");
    scanf("%d", &n);

    printf("Elementele matricei:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%f", &m[i][j]);

    float d = determinant(m, n);
    printf("Determinantul este: %.2f\n", d);
    if (d != 0)
        printf("Matricea este inversabilă.\n");
    else
        printf("Matricea NU este inversabilă.\n");

    return 0;
}
