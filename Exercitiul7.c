#include <stdio.h>

int main() {
    float salariu_brut, salariu_net;
    int cod;

    printf("Introduceti salariul brut: ");
    scanf("%f", &salariu_brut);

    printf("Introduceti codul tipului de contract (1:Full-time, 2:colaborare, 3:PFA): ");
    scanf("%d", &cod);

    switch (cod) {
        case 1:
            salariu_net = salariu_brut * 0.25; 
            break;
        case 2:
            salariu_net = salariu_brut * 0.10; 
            break;
        case 3:
            salariu_net = salariu_brut * 0.05;
            break;
        default:
            printf("Cod invalid!\n");
            return 1;
    }

    printf("Salariul net este: %f\n", salariu_net);

    return 0;
}