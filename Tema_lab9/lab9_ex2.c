#include <stdio.h>

int cmmdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return cmmdc(b, a % b);
}

int main() {
    int a, b;
    
    printf("Introduceți primul număr (a): ");
    scanf("%d", &a);
    
    printf("Introduceți al doilea număr (b): ");
    scanf("%d", &b);
    
    int rezultat = cmmdc(a, b);
    
    printf("Cel mai mare divizor comun al lui %d și %d este: %d\n", a, b, rezultat);
    
    return 0;
}