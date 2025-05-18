#include <stdio.h>

// Funcție recursivă pentru CMMDC
int cmmdc(int a, int b) {
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main() {
    int a, b;
    printf("Introduceti doua numere: ");
    scanf("%d %d", &a, &b);

    int rezultat = cmmdc(a, b);
    printf("CMMDC este: %d\n", rezultat);
    return 0;
}
