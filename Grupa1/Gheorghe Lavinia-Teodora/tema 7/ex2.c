#include <stdio.h>

int cmmdc(int a, int b) {
    if(b == 0) return a;
    return cmmdc(b, a % b);
}

int main() {
    int a, b;
    printf("Introduceti primul numar: ");
    scanf("%d", &a);
    printf("Introduceti al doilea numar: ");
    scanf("%d", &b);

    int CMMDC = cmmdc(a, b);
    printf("Cel mai mare divizor comun al celor doua numere este: %d", CMMDC);

    return 0;
}