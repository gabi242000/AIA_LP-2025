#include <stdio.h>

int cmmdc(int a, int b) {
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main() {
    int a, b;

    printf("Introdu doua numere naturale: ");
    scanf_s("%d %d", &a, &b);

    if (a < 0 || b < 0) {
        printf("Numerele trebuie sa fie naturale.\n");
        return 1;
    }

    int rezultat = cmmdc(a, b);
    printf("Cel mai mare divizor comun al lui %d si %d este: %d\n", a, b, rezultat);

    return 0;
}
