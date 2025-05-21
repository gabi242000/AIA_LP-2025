#include <stdio.h>


int invers(int n, int a) {
    if (n == 0)
        return a;
    return invers(n / 10, a * 10 + n % 10);
}

int main() {
    int n;

    printf("Introdu un numar: ");
    scanf("%d", &n);

    int rezultat = invers(n, 0);
    printf("Numarul inversat este: %d\n", rezultat);

    return 0;
}
