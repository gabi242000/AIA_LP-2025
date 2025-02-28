#include <stdio.h>

int main() {
    int pret = 0;
    int optiune = 0;
    printf("Introduceti pretul produsului: ");
    scanf("%d", &pret);
    printf("Alegeti reducerea pe care sa o aplicati\n");
    printf("1-10 la suta\n");
    printf("2-20 la suta\n");
    printf("3-30 la suta\n");
    scanf("%d", &optiune);

    switch (optiune){
        case 1:
            printf("Pretul produsului cu reducerea de 10 la suta este: %.2f", pret - pret * 0.1);
            break;

        case 2:
            printf("Pretul produsului cu reducerea de 20 la suta este: %.2f", pret - pret * 0.2);
            break;

        case 3:
            printf("Pretul produsului cu reducerea de 30 la suta este: %.2f", pret - pret * 0.3);
            break;

        default:
            printf("Optiunea aleasa este invalida");
            break;

    }
    return 0;
}