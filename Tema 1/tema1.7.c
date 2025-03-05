#include <stdio.h>
int main()
{
    int salariu, cod;

    printf("Salariul brut: ");
    scanf("%d",&salariu);
    printf("Introduceti codul: ");
    scanf("%d",&cod);

    switch (cod)
    {
    case 1:
        printf("Salariu pentru angajat full-time cu 25%%impozit : %d", salariu - 25 * salariu / 100);
        break;
    case 2:
        printf("Salariu pentru contract de colaborare cu 10%% impozit : %d", salariu - 10 * salariu / 100);
        break;
    case 3:
        printf("Salariu pentru PFA cu 5%% impozit : %d", salariu - 5 * salariu / 100);
        break;
    
    }

    return 0;
}