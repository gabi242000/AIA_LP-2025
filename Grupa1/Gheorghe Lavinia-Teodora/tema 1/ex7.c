#include <stdio.h>

int main() {
    int salariu_brut, salariu_net, cod;
    printf("Calculator pentru salariul net\n");
    printf("Introduceti salariul brut: ");
    scanf("%d", &salariu_brut);
    printf("Alegeti unul dintre codurile de mai jos: \n"
        "Cod 1: Salariu pentru angajat full-time (25%% impozit)\n"
        "Cod 2: Salariu pentru contract de colaborare (10%% impozit)\n"
        "Cod 3: Salariu pentru PFA (5%% impozit)\n");
    scanf("%d", &cod);

    switch(cod) {
        case 1:
        salariu_net = salariu_brut - (salariu_brut * 0.25);
        printf("Salariul net este : %d", salariu_net);
        break;

        case 2:
        salariu_net = salariu_brut - (salariu_brut * 0.1);
        printf("Salariul net este : %d", salariu_net);
        break;

        case 3:
        salariu_net = salariu_brut - (salariu_brut * 0.05);
        printf("Salariul net este : %d", salariu_net);
        break;

        default:
        printf("Codul introdus este invalid!");
        break;
    }

    return 0;
}