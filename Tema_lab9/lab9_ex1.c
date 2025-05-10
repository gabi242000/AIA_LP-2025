#include <stdio.h>

int invers(int n, int nr) {
    if (n == 0) {
        return nr;
    }
    return invers(n / 10, nr * 10 + n % 10);
}

int main() {
    int numar;
    
    printf("Introduceți un număr natural: ");
    scanf("%d", &numar);
    
    int numar_inversat = invers(numar, 0);
    
    printf("Numărul inversat este: %d\n", numar_inversat);
    
    return 0;
}