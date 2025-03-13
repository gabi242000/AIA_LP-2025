#include <stdio.h>

int Nr_par(int n) {
    if (n % 2 == 0) {
        return 1;
    }
    else return 0;
}
int main() {

    int n, numar;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    printf("Numerele pare pana la %d sunt:\n ", n);
    for(numar = 0; numar <= n; numar++) {
        if (Nr_par(numar) == 1) {
            printf("%d ", numar);
        }
    }
    return 0;
}