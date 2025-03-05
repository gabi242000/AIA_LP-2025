#include <stdio.h>
#include <string.h>
int main()
{
    float salariul_brut,salariul_final = 0;
    float impozit;
    char cod[10];
    printf("Cod 1: Salariu pentru angajat full-time\n");
    printf("Cod 2: Salariu pentru contract de colaborare\n");
    printf("Cod 3: Salariu pentru PFA\n");
    printf("Va rog introduceti salariul brut: \n");
    scanf("%f", &salariul_brut);
    getchar();
    printf("Va rog introduceti un cod(respectati sintaxa de: Cod nr.): \n");
    fgets(cod, sizeof(cod), stdin);
    cod[strcspn(cod, "\n")] = '\0';
    if(strcmp(cod,"Cod 1") == 0) 
    {
        salariul_final = salariul_brut - (salariul_brut * 0.25);
        printf("Salariul pentru angajat full-time: %.2f", salariul_final);
    }
    else if(strcmp(cod,"Cod 2") == 0) 
    {
        salariul_final = salariul_brut - (salariul_brut * 0.1);
        printf("Salariul pentru contract de colaborare: %.2f", salariul_final);
    }
    else if(strcmp(cod,"Cod 3") == 0)
    { 
        salariul_final = salariul_brut - (salariul_brut * 0.05);
        printf("Salariul pentru PFA: %.2f", salariul_final);
    }
    else 
    {
        printf("Codul nu este valid");
    }
    return 0;
}