#include <stdio.h>

void ex6()
{
    int pret , cod;
    printf("Pretul produsului : ");
    scanf("%d", &pret);
    printf("Codul produsului : ");
    scanf("%d", &cod);
    switch (cod)
    {
        case 1:
            printf("Pretul produsului este %.2f", pret - pret * 0.1);
            break;
        case 2:
            printf("Pretul produsului este %.2f", pret - pret * 0.2);
            break;
        case 3:
            printf("Pretul produsului este %.2f", pret - pret * 0.3);
            break;
        default:
            printf("Codul introdus nu exista");
    }
}

void ex7()
{
    int salariu, contr;
    printf("Salariul : ");
    scanf("%d", &salariu);
    printf("Tipul contractului : ");
    scanf("%d", &contr);
    switch (contr)
    {
        case 1:
            printf("Salariu pentru angajat full time este %.2f", salariu - salariu * 0.25);
            break;
        case 2:
            printf("Salariu pentru contract de colaborare este %.2f", salariu - salariu * 0.1);
            break;
        case 3:
            printf("Salariul pt PFA este %.2f", salariu - salariu * 0.05);
            break;
        default:
            printf("Codul introdus nu exista");
    }
}
int main()
{
    int x;
    printf("\n");
    printf("Alege ex din tema (6 / 7) : ");
    scanf("%d", &x);
    if(x == 6)
        ex6();
    else if(x == 7)
        ex7();
    else
        printf("Ex nu exista");
    return 0;
}