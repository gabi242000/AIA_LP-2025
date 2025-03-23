#include <stdio.h>
int main()
{
    float pret;
    int cod;
    printf("Care este pretul produsului?");
    scanf("%f",&pret);
    printf("Ce cod de reducere doriti sa aplicati?\n");
    printf("Cod 1: 10%% reducere\n");
    printf("Cod 2: 20%% reducere\n");
    printf("Cod 3: 30%% reducere\n");
    scanf("%d",&cod);
    switch(cod)
    {
        case 1:
        pret-=pret*10/100;
        break;
        case 2:
        pret-=pret*20/100;
        break;
        case 3:
        pret-=pret*30/100;
        break;
        default:
        printf("Codul introdus nu este valid.");
    }
    printf("Noul pret este: %d",pret);
    return 0;
}