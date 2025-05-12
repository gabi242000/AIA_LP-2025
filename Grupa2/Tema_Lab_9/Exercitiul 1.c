#include <stdio.h>

int invers(int n, int acc) {
    if (n == 0)
        return acc;
    return invers(n / 10, acc * 10 + n % 10);
}

int main() {
    int n;

    printf("Introdu un numar natural: ");
    scanf_s("%d", &n);

    if (n < 0) {
        printf("Numarul trebuie sa fie natural (>= 0).\n");
        return 1;
    }

    int rezultat = invers(n, 0);
    printf("Numarul %d inversat este: %d\n", n, rezultat);

    return 0;
}
