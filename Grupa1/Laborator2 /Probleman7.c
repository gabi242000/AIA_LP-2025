#include <stdio.h>

int main()
{   
    int cod;
    float salariu_brut;
    float salariu_net;

    printf("Introdu salariul angajatului: ");
    scanf("%f", &salariu_brut) ;
      
    printf("Introdu un cod(1,2 sau 3): ");
    scanf("%d", &cod) ;

    switch(cod){
        case 1:        
            salariu_net = salariu_brut - (salariu_brut * 0.25);
            printf("%f", salariu_net);
            break;
        case 2:
            salariu_net = salariu_brut - (salariu_brut * 0.1);
            printf("%f", salariu_net);
            break;
        case 3:
            salariu_net = salariu_brut - (salariu_brut * 0.05);
            printf("%f", salariu_net);
            break;
        default:
            printf("Eroare");
            break;
    }

    return 0;
}
