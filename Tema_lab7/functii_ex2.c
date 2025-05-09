#include <stdio.h>
#define N 10 // Dimensiunea maxima a matricii

int determinant(int m[][N], int n) {
    int det = 1, i, j, k;
    float factor;
    
    for (i = 0; i < n; i++) {
        if (m[i][i] == 0) {
            int ok = 0;
            for (j = i + 1; j < n; j++) {
                if (m[j][i] != 0) {
                    for (k = 0; k < n; k++) {
                        int temp = m[i][k];
                        m[i][k] = m[j][k];
                        m[j][k] = temp;
                    }
                    det = -det;
                    ok = 1;
                    break;
                }
            }
            if (!ok) return 0;
        }
        
        for (j = i + 1; j < n; j++) {
            factor = m[j][i] / (float)m[i][i];
            for (k = 0; k < n; k++) {
                m[j][k] -= factor * m[i][k];
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        det *= m[i][i];
    }
    
    return det;
}

int esteInversabila(int m[][N], int n) {
    return determinant(m, n) != 0;
}

int main() {
    int mat[N][N], n, i, j;
    
    printf("Introdu dimensiunea matricii (max %d): ", N);
    scanf("%d", &n);
    
    printf("Introdu elementele matricii:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    
    int det = determinant(mat, n);
    printf("Determinantul matricii este: %d\n", det);
    
    if (esteInversabila(mat, n)) {
        printf("Matricea este inversabila.\n");
    } else {
        printf("Matricea NU este inversabila.\n");
    }
    
    return 0;
}