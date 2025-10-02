#include <stdio.h>

int main(){
    float salariu_brut,impozit,salariu_net;
    int contract;

    printf("Introdu salariul brut:");
    scanf("%f",&salariu_brut);
   

    printf("Alege tipul contractului:\n");
    printf("1.Salariu pentru angajat full-time\n");
    printf("2.Salariu pentru contract de colaborare\n");
    printf("3.Salariu pentru PFA\n");

    scanf("%i",&contract);

    switch(contract){
        case 1:
            impozit = 0.25*salariu_brut;
            salariu_net = salariu_brut-impozit;
            
            printf("Ai ales salariu pentru angajat full-time\n");
            printf("Pentru acest tip de contract salariul net este de: %0.2f",salariu_net);
                break;
        case 2:
            impozit = 0.10*salariu_brut;
            salariu_net = salariu_brut-impozit;

            printf("Ai ales salariu pentru contract de colaborare\n");
            printf("Pentru acest tip de contract salariul net este de: %0.2f",salariu_net);
                break;
        case 3:
            impozit = 0.05*salariu_brut;
            salariu_net = salariu_brut-impozit;
            printf("Ai ales salariu pentru PFA\n");
            printf("Pentru acest tip de contract salariul net este de: %0.2f",salariu_net);
                break;
        default:
            printf("Nu ai ales un tip de contract valid!");
                break;

    }


    

    

}