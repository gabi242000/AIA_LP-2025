#include <stdio.h>
int main()
{
    float salariu_brut, salariu_net;
    int cod;
    printf("Introdu un salariu brut: \n");
    scanf("%f",&salariu_brut);
    printf("Introdu tipul contractului: \n");
    printf("Cod 1: Salariu pentru angajat full-time (25%% impozit)\n");
    printf("Cod 2: Salariu pentru contract de colaborare (10%% impozit)\n");
    printf("Cod 3: Salariu pentru PFA (5%% impozit)\n");
    scanf("%d",&cod);
    switch(cod)
    {
        case 1:
        salariu_net=salariu_brut-salariu_brut*(25.0/100);
            break;
        case 2:
        salariu_net=salariu_brut-salariu_brut*(10.0/100);
            break;
        case 3:
        salariu_net=salariu_brut-salariu_brut*(5.0/100);
            break;
        default:
            printf("Eroare!\n");
            break;
    }
    printf("Salariul brut pentru acest tip de contract este: %f\n", salariu_net);
}