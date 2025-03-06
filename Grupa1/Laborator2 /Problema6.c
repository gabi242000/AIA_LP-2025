#include <stdio.h>


int main()
{
    float pret;
    int cod;
    
    
    printf("Introdu pretul: ");
    scanf("%f", &pret);
    printf("Introdu un cod(1,2 sau 3): ");
    scanf("%d", &cod);
    switch(cod){
        case 1:{
            pret=pret-pret*0.1;
            printf("%f RON", pret); //10% reducere
            break;
        }
        case 2:{
            pret=pret-pret*0.2;
            printf("%f RON", pret);//20% reducere
            break;
        }
        case 3:
        {   
            pret=pret-pret*0.3;
            printf("%f RON", pret);//30% reducere
            break;
        }
        default:
        {
            printf("Eroare");
            break;
        }

    }
}
