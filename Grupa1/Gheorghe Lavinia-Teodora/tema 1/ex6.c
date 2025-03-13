#include <stdio.h>

int main() {
    float pret_produs, calc_red, pret_final;
    int cod_reducere;
    printf("Acesta este un calculator de reduceri\n");
    printf("Introduceti pretul produsului: ");
    scanf("%f", &pret_produs);
    printf("Codurile pentru reduceri sunt urmatoarele:\n"
        "Cod 1: 10%% reducere\n"
        "Cod 2: 20%% reducere\n"
        "Cod 3: 30%% reducere\n"
        "Introduceti un cod de mai sus: ");
    scanf("%d", &cod_reducere);

    switch(cod_reducere) {
        case 1:
        calc_red = (10 * pret_produs) / 100;
        pret_final = pret_produs - calc_red;
        printf("Valore discount: %.2f", calc_red);
        printf("\nValoare pret final: %.2f", pret_final);
        break;

        case 2:
        calc_red = (20 * pret_produs) / 100;
        pret_final = pret_produs - calc_red;
        printf("Valore discount: %.2f", calc_red);
        printf("\nValoare pret final: %.2f", pret_final);
        break;

        case 3:
        calc_red = (30 * pret_produs) / 100;
        pret_final = pret_produs - calc_red;
        printf("Valore discount: %.2f", calc_red);
        printf("\nValoare pret final: %.2f", pret_final);
        break;

        default:
        printf("Codul introdus este invalid!");
        break;
    }

    return 0;
}