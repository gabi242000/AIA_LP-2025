#include <stdio.h>

int m[100][100];

int main(){
    int n, imax, jmax, vmax, ok = 0;
    printf("Introdu dimensiunea matricii (nxn):");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            printf("Elementul m[%d][%d]", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (m[i][j] > m[i + 1][j] && m[i][j] > m[i][j + 1] && m[i][j] > m[i - 1][j] && m[i][j] > m[i][j - 1]){
                imax = i;
                jmax = j;
                vmax = m[i][j];
                ok = 1;
                break;
            }
        }
    }

    if (ok == 1)
        printf("Elementul de varf este m[%d][%d] cu valoarea %d.", imax - 1, jmax - 1, vmax);
    else printf("Nu am gasit un element de varf.");
    return 0;
}