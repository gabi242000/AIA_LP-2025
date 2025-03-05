#include <stdio.h>

int main()
{
    int cod, salariuBrut, impozit, salariuNet;
    printf("Intorduceti un numar intre 1 si 3 corespunzator tipul dumneavoastra de contract.\n");
    printf("1 - Salariu pentru angajat full-time (25%% impozit)\n");
    printf("2 - Salariu pentru contract de colaborare (10%% impozit)\n");
    printf("3 - Salariu pentru PFA (5%% impozit)\n");
    scanf("%i", &cod);
    printf("Intorduceti salariul dumneavoastra brut.\n");
    scanf("%i", &salariuBrut);
    switch (cod)
    {
    case 1:
        impozit = 25;
        break;
    case 2:
        impozit = 10;
        break;
    case 3:
        impozit = 5;
        break;
    default:
        break;
    }
    salariuNet = salariuBrut - (salariuBrut*(impozit/100.0));
    printf("Salariu dumneavoastra net este: %i",salariuNet);
}