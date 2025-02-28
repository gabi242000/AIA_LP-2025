#include <stdio.h>

int main() {
    float salariu_brut, salariu_net, impozit;
    int tip_contract;

    
    printf("Introduceti salariul brut: ");
    scanf("%f", &salariu_brut);

    
    printf("Introduceti tipul de contract: \n");
    printf("1 - Angajat full-time\n");
    printf("2 - Colaborare\n");
    printf("3 - PFA\n");
    scanf("%d", &tip_contract);

    
    switch (tip_contract) {
        case 1:
            impozit = 0.25;
            break;
        case 2: 
            impozit = 0.10; 
            break;
        case 3: 
            impozit = 0.05; 
            break;
        default:
            printf("Tip de contract invalid.\n");
            return 1; 
    }

    
    salariu_net = salariu_brut - (salariu_brut * impozit);

    
    printf("Salariul net este: %.2f lei\n", salariu_net);

    return 0;
}
