#include <stdio.h>

int invers(int n, int acc) {
    if (n == 0)
        return acc;
    return invers(n / 10, acc * 10 + n % 10);
}

int main() {
    int numar;
    printf("Introduceti un numar: ");
    scanf("%d", &numar);

    int rezultat = invers(numar, 0);
    printf("Numarul inversat este: %d\n", rezultat);
    return 0;
}
