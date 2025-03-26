#include <stdio.h>

int main(){
    printf("Problema 5\n");
    int nota;

    //introducerea notei de catre utilizator
    printf("Introduceti o nota intre 1 si 10: ");
    scanf("%d", &nota);

    //afisarea mesajului pentru nota
    switch(nota){
        case 1:
        printf("Ingrijorator!\n");
        break;
        case 2:
        printf("Foarte slab!\n");
        break;
        case 3:
        printf("Slab!\n");
        break;
        case 4:
        printf("Slabut!\n");
        break;
        case 5:
        printf("Suficient!\n");
        break;
        case 6:
        printf("Acceptabil!\n");
        break;
        case 7:
        printf("Destul de bine!\n");
        break;
        case 8:
        printf("Bine!\n");
        break;
        case 9:
        printf("Foarte bine!\n");
        break;
        case 10:
        printf("Excelent!\n");
        break;
        default:
        printf("Nu ati respectat conditia de a introduce o nota intre 1-10.\n");
    
    }

    printf("Problema 6\n");
    float pret, pret_final;
    int cod;

    //introducerea pretului de catre utilizator
    printf("Introduceti pretul produdului: ");
    scanf("%f", &pret);

    //introducerea codului de reducere de catre utilizator
    printf("Introduceti codul de reducere 1, 2 sau 3: ");
    scanf("%d", &cod);

    //aplicarea reducerii corecte
    switch(cod){
        case 1:
        pret_final=pret*0.90;
        printf("Pret final dupa reducere: %.2f\n", pret_final);
        break;
        case 2:
        pret_final=pret*0.80;
        printf("Pret final dupa reducere: %.2f\n", pret_final);
        break;
        case 3:
        pret_final=pret*0.70;
        printf("Pret final dupa reducere: %.2f\n", pret_final);
        break;
        default:
        printf("Cod de reducere incorect! Introduceti 1, 2 sau 3.\n");
    }

    print("Problema 7\n");
    int cod2;
    float salariu_brut, salariu_net;

    //introducerea salariului brut
    printf("Introduceti salariul brut: ");
    scanf("%f", &salariu_brut);

    //introducerea codolui pt tipul de contract
    printf("Introduceti codul tipului de contract (1, 2 sau 3): ");
    scanf("%d", &cod2);

    //aplicarea impozitului corespunzator
    switch(cod2){
        case 1:
        salariu_net=salariu_brut*0.75;
        printf("Salariu net pentru angajat full-time: %.2f\n", salariu_net);
        break;
        case 2:
        salariu_net=salariu_brut*0.90;
        printf("Salariu net pentru contract de colaborare: %.2f\n", salariu_net);
        break;
        case 3:
        salariu_net=salariu_brut*0.95;
        printf("Salariu net pentru PFA: %.2f\n", salariu_net);
        break;
        default:
        printf("Cod de contract incorect! Introduceti 1, 2 sau 3.\n");
    }

    return 0;
}