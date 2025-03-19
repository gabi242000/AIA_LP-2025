//ex7
#include <stdio.h>
int main()
{
    float sal_brut,sal_net;
    int cod;
    printf("Introduceti salariul brut:");
    scanf("%f",&sal_brut);
    printf("Introduceti tipul contractului(corespunzatoare fiecarui tip de cod: 1,2 sau 3)\n");
    scanf("%d",&cod);
    switch(cod)
    {
        case 1:
            sal_net=sal_brut-(sal_brut*0.25);
            printf("Salariul pentru un angajat full-time este: %2f.\n",sal_net);
            break;
        case 2:
            sal_net=sal_brut-(sal_brut*0.10);
            printf("Salariul pentru un angajat full-time este: %2f.\n",sal_net);
            break;
        case 3:
            sal_net=sal_brut-(sal_brut*0.05);
            printf("Salariul pentru un angajat full-time este: %2f.\n",sal_net);
            break;
    default:
        printf("Cod de contract invalid. Vă rugăm să introduceți un cod valid (1, 2 sau 3).\n");
        break;
    }
    return 0;
}