#include <stdio.h>
int cmmdc(int a, int b) {
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}
int main() {
    int a, b;
    printf("Introdu primul numar: ");
    scanf("%d", &a);
    printf("Introdu al doilea numar: ");
    scanf("%d", &b); 
    printf("Cel mai mare divizor comun (CMMD) este: %d\n", cmmdc(a, b));
    return 0;
}
