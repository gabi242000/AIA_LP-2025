#include <stdio.h>


int invers(int n, int acc) {
    if (n == 0)
        return acc;
    return invers(n / 10, acc * 10 + n % 10);
}

int main() {
    int n;

    printf("Introdu un numar natural: ");
    scanf("%d", &n);

    int rezultat = invers(n, 0);

    printf("Numarul inversat este: %d", rezultat);

    return 0;
}
