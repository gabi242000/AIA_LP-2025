#include <stdio.h>


int main() {
    float pret, reducere, pret_final;
    int cod_reducere;

    printf("Introduceti pretul produsului: ");
    scanf("%f", &pret);

    printf("Introduceti codul de reducere (1, 2 sau 3): ");
    scanf("%d", &cod_reducere);

    switch (cod_reducere) {
        case 1:
            reducere = 0.10;
            break;
        case 2:
            reducere = 0.20;
            break;
        case 3:
            reducere = 0.30;
            break;
        default:
            printf("Cod invalid!\n");
            return 1;  
    }

    pret_final = pret - (pret * reducere);
    printf("Pretul final dupa aplicarea reducerii: %.2f\n", pret_final);

    return 0;
}
