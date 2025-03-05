#include <stdio.h>
int main()
{
    int cod;
    float pret;
    scanf("%f", &pret);
    scanf("%d", &cod);
    switch (cod)
    {
        case 1:
            pret=0.9*pret;
            printf("%f", pret);
            break;
        case 2:
            pret=0.8*pret;
            printf("%f", pret);
            break;
        case 3:
            pret=0.7*pret;
            printf("%f", pret);
            break;
        default:
            printf("eroare");
            break;
    }
    return 0;
}
