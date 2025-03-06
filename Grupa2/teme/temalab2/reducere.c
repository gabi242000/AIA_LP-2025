#include <stdio.h>

int main()
{
    float pret; 
    char cod_red;
    printf("introduceti pretul produsului:");
    scanf("%f",&pret);
    printf("introduceti codul de reducere:\n");
    printf("1 - 10%%\n");
    printf("2 - 20%%\n");
    printf("3 - 30%%\n");
    scanf(" %c",&cod_red);
    switch (cod_red)
    {
    case '1':
        pret=pret-pret/10;
        printf("pretul redus: %f",pret);
        break;
    case '2':
        pret=pret-pret/5;
        printf("pretul redus: %f",pret);
        break;
    case '3':
        pret=pret-30.0/100*pret;
        printf("pretul redus: %f",pret);
        break;
    
    default:
        printf("eroare: cod gresit");
        break;
    }
    return 0;
}