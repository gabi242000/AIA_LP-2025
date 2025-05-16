#include <stdio.h>

int inverseaza(int n, int inv) {
    if (n == 0)
        return inv;
    return inverseaza(n/10, inv*10 + n%10);
}

int main() {
    int n;
    printf("Introdu un număr: ");
    scanf("%d", &n);
    int invers = inverseaza(n, 0);
    printf("Numărul inversat este: %d\n", invers);
    return 0;
}
