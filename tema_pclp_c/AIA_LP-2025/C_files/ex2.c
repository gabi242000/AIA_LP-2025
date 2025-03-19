#include <stdio.h>
#include <string.h>
int main()
{
    float pret;
    char cod[10];
    printf("Va rog introduceti pretul produsului: \n");
    scanf("%f", &pret);
    getchar();
    printf("Va rog introduceti un cod(respectati sintaxa de: Cod nr.), acesta corespunde reducerii alese (1 - 10 la suta, 2 - 20 la suta, 3 - 30 la suta): \n");
    fgets(cod, sizeof(cod), stdin);
    cod[strcspn(cod, "\n")] = '\0';
    int ok = 1;
    if (strcmp(cod,"Cod 1") == 0)
        pret = pret * 9 / 10;
    else if(strcmp(cod,"Cod 2") == 0)
        pret = pret * 8 / 10;

    else if(strcmp(cod,"Cod 3") == 0)
        pret = pret * 7 / 10;
    else 
    {
        printf("Codul nu este valid");
        return 0;
    }
    printf("%.2f", pret);
    return 0;
}