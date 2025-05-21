#include <stdio.h>
#include <stdlib.h>

//ex 1
// int invers(int n, int nr) {
//     if (n == 0) {
//         return nr;
//     }
//     return invers(n / 10, nr * 10 + n % 10);
// }

// int main() {
//     int numar;
    
//     printf("Introdu un numar: ");
//     scanf("%d", &numar);
    
//     int numar_inv = invers(numar, 0);
    
//     printf("Nr inversat este: %d\n", numar_inv);
    
//     return 0;
// }

//ex 2
// int cmmdc(int a, int b) {
//     if (b == 0) {
//         return a;
//     }
//     return cmmdc(b, a % b);
// }

// int main() {
//     int a, b;
    
//     printf("a: ");
//     scanf("%d", &a);
    
//     printf("b: ");
//     scanf("%d", &b);
    
//     int rezultat = cmmdc(a, b);
    
//     printf("CMMDC dintre  %d si %d este: %d\n", a, b, rezultat);
    
//     return 0;
// }