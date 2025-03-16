#include <stdio.h>

int main()
{
    int salariu_brut,salariu_net,cod,ok=3,impozit,imp_procent;
    printf("Bine ati venit la serviciul de salarii brute. Tot programul este construit in aria facultatii UTCB A.I.A. I. Versiunea actuala a programului: 1.2.11");
    printf("\n\nVa rugam sa introduceti salariul brut: ");
    scanf("%d",&salariu_brut);
    printf("\nSalariile variaza in timp, dar trebuie cunoscute de asemenea si impozitele.");
    printf("\nPentru ce impozit ati dori sa va interesati?");
    printf("\n1. Salariu pentru angajat full-time");
    printf("\n2. Salariu pentru contract de colaborare");
    printf("\n3. Salariu pentru PFA");
    printf("\n\nVa rugam sa introduceti o cifra de mai sus: ");
    scanf("%d",&cod);
    while((cod<1 || cod>3) && ok)
    {
        printf("\nCodul este inexistent. Poate mai incercati inca o data? (incercari disponibile: %d)",ok);
        scanf("%d",&cod);
        ok-=1;
    }
    if(ok==0)
        printf("\nNe pare rau. Securitatea va suspecteaza ca pe intruns in sistemul nostru. Va rugam reveniti mai tarziu. :(");
    else
    {
        switch(cod)
        {
            case 1:
                imp_procent=25;
                impozit=salariu_brut/100*25;
                break;
            case 2:
                imp_procent=10;
                impozit=salariu_brut/100*10;
                break;
            case 3:
            imp_procent=5;
                impozit=salariu_brut/100*5;
                break;
        }
        salariu_net=salariu_brut-impozit;
        printf("\n\nPentru salariul brut de %d lei:",salariu_brut);
        printf("\nImpozitul de %d la suta pe salariu: %d lei",imp_procent,impozit);
        printf("\nSalariul net al dumneavoastra: %d lei",salariu_net);
        printf("\n\nVa multumim pentru serviciile apelate de la UTCB A.I.A. I :DDD");
    }
}