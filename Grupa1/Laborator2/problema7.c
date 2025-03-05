#include <stdio.h>
int main()
{
    int cod;
    int brut, net;
    scanf("%d", &brut);
    scanf("%d", &cod);
    switch (cod)
    {
        case 1:
            net=brut-(brut*15/100);
            printf("%d", net);
            break;
        case 2:
            net=brut-(brut*10/100);
            printf("%d", net);
            break;
        case 3:
           net=brut-(brut*5/100);
            printf("%d", net);
            break;
        default:
            printf("eroare");
            break;
    }
    return 0;
}
