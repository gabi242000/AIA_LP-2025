#include <stdio.h>
int main() {
    int n;
    printf("introdu dimensiunea matricei: ");
    scanf("%d", &n);
    int matrice[n][n];
    printf("Elementele matricei: ");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &matrice[i][j]);
        }
    }
    int max_suma = 0;
    int max_rand = n;
    for(int i=0; i<n; i++) {
        int suma=0;
        for(int j=0; j<n; j++) {
            suma +=matrice[i][j];
        }
        if(suma > max_suma) {
            max_suma = suma;
            max_rand = i;
        }
    }
    printf("randul cu suma maxima este: %d cu suma %d\n", max_rand, max_suma);
    return 0;
}