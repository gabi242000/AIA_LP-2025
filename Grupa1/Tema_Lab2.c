#include <stdio.h>

void ex5()
{
    printf("\nIntrodu nota(1-10):\n");
    int nota;
    scanf("%d", &nota);
    if(nota==10)
        printf("Bravo coi\n");
    else if (nota>=5)
        printf("Satisfacator\n");
    else if (nota<5)
        printf("Restanta\n");
    else
        printf("executat public\n");
}
void ex6()
{
    int pretul, cod;
    printf("\nIntrodu pretul:\n");
    scanf("%d", &pretul);
    printf("Introdu codul reducere (1, 2 sau 3)\n");
    scanf("%d", &cod);
    if(cod == 1 || cod == 2 || cod == 3)
    {
        pretul = (pretul*10-pretul*cod)/10;
        printf("Pretul este: %d\n", pretul);
    }
    else 
    printf("Cod invalid");
}
void ex7()
{
    int salar_b, salar_n, cod;

    printf("Introdu salariul brut: ");
    scanf("%d", &salar_b);

    printf("Introdu codul(1 = Full-time, 2 = Colaborare, 3 = PFA): ");
    scanf("%d", &cod);

    if (cod == 1) {
        salar_n = salar_b - (salar_b * 0.25);
        printf("Salariul net full-time: %d\n", salar_n);
    } 
    else if (cod == 2) {
        salar_n = salar_b - (salar_b * 0.10);
        printf("Salariul net contract de colaborare: %d\n", salar_n);
    } 
    else if (cod == 3) {
        salar_n = salar_b - (salar_b * 0.05);
        printf("Salariul net PFA: %d\n", salar_n);
    } 
    else {
        printf("Cod invalid\n");
    }
}
int main()
{
    ex7();
    return 0;
}