#include <stdio.h>
int main()
{
    int pret, cod;

    printf("Introduceti pretul: ");
    scanf("%d",&pret);
    printf("Introduceti codul: ");
    scanf("%d",&cod);

    switch (cod)
    {
    case 1:
        printf("10%% reducere : %.2f", pret - 10.0 * pret / 100);
        break;
    case 2:
        printf("20%% reducere : %.2f", pret - 20.0 * pret / 100);
        break;
    case 3:
        printf("30%% reducere : %.2f", pret - 30.0 * pret / 100);
        break;
    default:
        printf("cod gresit!");
        break;
    }

    return 0;
}