#include <stdio.h>
int main()
{
    float salariu_brut, salariu_net, impozit;
    int cod;
    printf("Introdu valoarea salariului brut:");
    scanf("%f",&salariu_brut);
    printf("Ce tip de contract preferati?\n");
    printf("Cod 1: full-time (25%% impozit)\n");
    printf("Cod 2: colaborare (10%% impozit)\n");
    printf("Cod 3: PFA (5%% impozit)\n");
    scanf("%d",&cod);
    switch(cod)
    {
        case 1:
        impozit=0.25;
        break;
        case 2:
        impozit=0.10;
        break;
        case 3:
        impozit=0.05;
        break;
        default:
        printf("Codul introdus nu este valid.");
    }
    salariu_net=salariu_brut-(salariu_brut*impozit);
    printf("Valoarea salariului net este: %d",salariu_net);
    return 0;
}