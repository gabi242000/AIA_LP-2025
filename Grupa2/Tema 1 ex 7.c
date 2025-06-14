#include <stdio.h>

int main() {
    float salariu_brut, salariu_net;
    int cod_contract;
    float impozit;
    printf("Introdu salariul brut: ");
    scanf("%f", &salariu_brut);
    printf("Introdu codul contractului (1 - Full-time, 2 - Colaborare, 3 - PFA): ");
    scanf("%d", &cod_contract);
    switch (cod_contract) {
        case 1:
            impozit = 0.25; 
            break;
        case 2:
            impozit = 0.10; 
        case 3:
            impozit = 0.05; 
            break;
        default:
            printf("Eroare: Cod contract invalid!\n");
            return 1;
    }
    salariu_net = salariu_brut - (salariu_brut * impozit);
    printf("Salariul net este: %.2f\n", salariu_net);
    return 0;
}