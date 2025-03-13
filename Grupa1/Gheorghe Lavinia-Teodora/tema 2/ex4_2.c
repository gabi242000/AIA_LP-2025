#include <stdio.h>

int main() {
    int n, termen1, termen2, termen_curent;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    termen1 = 0, termen2 = 1;
    printf("Primele %d numere din sirul Fibonacci sunt:\n", n);
    printf("%d %d ", termen1, termen2);
    for(int i = 3; i <= n; i++) {

            termen_curent = termen2 + termen1;
            termen1 = termen2;
            termen2 = termen_curent;
            printf("%d ", termen_curent);

    }

    return 0;
}