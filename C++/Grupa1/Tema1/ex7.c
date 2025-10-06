#include <stdio.h>

int main() {
    float salariu_brut;
    int nrcod;
    printf("Introdu salariul brut: ");
    scanf("%f", &salariu_brut);
    printf("Introdu tipul contractului \n"
            "\"1\": Salariu pentru angajat full-time (25%% impozit) \n"
            "\"2\": Salariu pentru contract de colaborare (10%% impozit)\n"
            "\"3\" : Salariu pentru PFA (5%% impozit)\n ");

    scanf("%d", &nrcod);

    switch (nrcod) {
        case 1:
            printf("%.2f", salariu_brut * 75 / 100);
            break;

        case 2:
            printf("%.2f", salariu_brut * 90 / 100);
            break;

        case 3:
            printf("%.2f", salariu_brut * 95 / 100);
            break;

        default:
            printf("trebuie sa introduci un nr intre 1-3\n");
            break;
    }
    return 0;
}

