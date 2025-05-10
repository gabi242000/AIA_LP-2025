#include <stdio.h>
int invers(int n, int acc) {
    if (n == 0)
        return acc;
    return invers(n / 10, acc * 10 + n % 10);
}
int main() {
    int n;
    printf("Introdu un numar: ");
    scanf("%d", &n);
    printf("Numarul inversat este: %d\n", invers(n, 0));
    return 0;
}
