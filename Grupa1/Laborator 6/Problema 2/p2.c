#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define N 10

double determinant(int m[][N], int n) {
    double det = 1.0;
    int i, j, k;

    for (i = 0; i < n; i++) {
        if (m[i][i] == 0) {
            for (j = i + 1; j < n; j++) {
                if (m[j][i] != 0) {
                    for (k = 0; k < n; k++) {
                        int temp = m[i][k];
                        m[i][k] = m[j][k];
                        m[j][k] = temp;
                    }
                    det = -det;
                    break;
                }
            }
        }

        if (m[i][i] == 0) {
            return 0;
        }

        for (j = i + 1; j < n; j++) {
            double factor = (double)m[j][i] / m[i][i];
            for (k = i; k < n; k++) {
                m[j][k] -= factor * m[i][k];
            }
        }

        det *= m[i][i];
    }

    return det;
}

bool esteInversabila(int m[][N], int n) {
    double det = determinant(m, n);
    return fabs(det) > 1e-9; 
}

int main() {
    int n, i, j;
    int m[N][N];

    printf("Introduceti dimensiunea matricei (n x n): ");
    scanf("%d", &n);

    if (n > N) {
        printf("Dimensiunea maxima a matricei este %d.\n", N);
        return 1;
    }

    printf("Introduceti elementele matricei:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    double det = determinant(m, n);
    printf("Determinantul matricei este: %.2lf\n", det);

    if (esteInversabila(m, n)) {
        printf("Matricea este inversabila.\n");
    } else {
        printf("Matricea nu este inversabila.\n");
    }

    return 0;
}