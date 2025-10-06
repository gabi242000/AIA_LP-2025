#include <stdio.h>


int cmmdc(int a, int b) {
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main() {
    int a, b;

    printf("Introdu doua numere naturale: ");
    scanf("%d %d", &a, &b);

    int rezultat = cmmdc(a, b);

    printf("Cel mai mare divizor comun al lui %d si %d este: %d\n", a, b, rezultat);

    return 0;
}
