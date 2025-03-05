// 1. Program în C++ pentru evaluarea notelor:

#include <iostream>

using namespace std;

int main() {
    int nota;
    cout << "Introduceți nota (1-10): ";
    cin >> nota;

    switch (nota) {
        case 10: cout << "Excelent"; break;
        case 9: cout << "Foarte Bine"; break;
        case 8: cout << "Bine"; break;
        case 7: cout << "Satisfăcător"; break;
        case 6: cout << "Acceptabil"; break;
        case 5: cout << "Slab"; break;
        case 4: case 3: case 2: case 1: cout << "Insuficient"; break;
        default: cout << "Nota invalidă!";
    }

    return 0;
}

// 2. Calculator de reduceri în C:

#include <stdio.h>

int main() {
    float pret, pret_final;
    int cod;

    printf("Introduceți prețul produsului: ");
    scanf("%f", &pret);
    printf("Introduceți codul de reducere (1, 2, 3): ");
    scanf("%d", &cod);

    switch (cod) {
        case 1: pret_final = pret * 0.90; break;
        case 2: pret_final = pret * 0.80; break;
        case 3: pret_final = pret * 0.70; break;
        default: 
            printf("Cod invalid!\n");
            return 1;
    }

    printf("Prețul final după reducere: %.2f\n", pret_final);
    return 0;
}
// 3. Program în C pentru calculul salariului net:

#include <stdio.h>

int main() {
    float salariu_brut, salariu_net;
    int cod;

    printf("Introduceți salariul brut: ");
    scanf("%f", &salariu_brut);
    printf("Introduceți tipul contractului (1, 2, 3): ");
    scanf("%d", &cod);

    switch (cod) {
        case 1: salariu_net = salariu_brut * 0.75; break;
        case 2: salariu_net = salariu_brut * 0.90; break;
        case 3: salariu_net = salariu_brut * 0.95; break;
        default: 
            printf("Cod invalid!\n");
            return 1;
    }

    printf("Salariul net: %.2f\n", salariu_net);
    return 0;
}