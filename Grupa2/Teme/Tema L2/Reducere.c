#include <stdio.h>

int main()
{
    float pret; 
    char cod_red;
    printf("Introduceti pretul produsului:");
    scanf("%f",&pret);
    printf("Introduceti codul de reducere:\n");
    printf("1 - 10%%\n");
    printf("2 - 20%%\n");
    printf("3 - 30%%\n");
    scanf(" %c",&cod_red);
    switch (cod_red)
    {
    case '1':
        pret=pret-pret/10;
        printf("Pretul redus: %f",pret);
        break;
    case '2':
        pret=pret-pret/5;
        printf("Pretul redus: %f",pret);
        break;
    case '3':
        pret=pret-30.0/100*pret;
        printf("Pretul redus: %f",pret);
        break;
    
    default:
        printf("Eroare!");
        break;
    }
    return 0;
}
