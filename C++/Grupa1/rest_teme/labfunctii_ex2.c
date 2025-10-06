#include <stdio.h>
#include <math.h>

#define N 10  // Dimensiune maximă pentru matrice

// Funcție pentru calculul determinantului folosind eliminarea Gauss
double determinant(double m[N][N], int n) {
    double temp[N][N]; // Copiem matricea pentru a nu o modifica
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[i][j] = m[i][j];

    double det = 1.0;

    for (int i = 0; i < n; i++) {
        // Dacă pivotul este zero, caută o linie de jos pentru interschimbare
        if (fabs(temp[i][i]) < 1e-9) {
            int ok = 0;
            for (int j = i + 1; j < n; j++) {
                if (fabs(temp[j][i]) > 1e-9) {
                    for (int k = 0; k < n; k++) {
                        double aux = temp[i][k];
                        temp[i][k] = temp[j][k];
                        temp[j][k] = aux;
                    }
                    det *= -1; // Schimbare de semn la determinant
                    ok = 1;
                    break;
                }
            }
            if (!ok) return 0; // Toți pivotii sunt zero => determinatul e zero
        }

        det *= temp[i][i];

        // Eliminare Gauss
        for (int j = i + 1; j < n; j++) {
            double factor = temp[j][i] / temp[i][i];
            for (int k = i; k < n; k++) {
                temp[j][k] -= factor * temp[i][k];
            }
        }
    }

    return det;
}

// Funcție pentru verificarea inversabilității
int esteInversabila(double m[N][N], int n) {
    double det = determinant(m, n);
    return fabs(det) > 1e-9;
}

int main() {
    int n;
    double m[N][N];

    printf("Introdu dimensiunea matricei patratice (n x n): ");
    scanf("%d", &n);

    printf("Introdu elementele matricei:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("m[%d][%d] = ", i, j);
            scanf("%lf", &m[i][j]);
        }
    }

    double det = determinant(m, n);
    printf("\nDeterminantul matricei este: %.2lf\n", det);

    if (esteInversabila(m, n))
        printf("Matricea este inversabila.\n");
    else
        printf("Matricea NU este inversabila.\n");

    return 0;
}
