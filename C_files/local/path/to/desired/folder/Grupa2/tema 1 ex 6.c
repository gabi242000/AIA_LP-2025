#include <stdio.h>
int main() {
    int pret, cod;  
    printf("Introduceti pretul produsului: ");
    scanf("%d", &pret);
    printf("Introduceti codul de reducere (1, 2 sau 3): ");
    scanf("%d", &cod);
    if (cod == 1) pret -= pret * 10 / 100;
    else if (cod == 2) pret -= pret * 20 / 100;
    else if (cod == 3) pret -= pret * 30 / 100;  
    printf("Pretul final este: %d\n", pret);  
    return 0;
}