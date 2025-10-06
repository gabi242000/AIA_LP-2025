#include <stdio.h>

int main() {
    float pret;
    int nrcupon;
    printf("Introdu pretul produsului: ");
    scanf("%f", &pret);
    printf("Introdu cod de reducere: ");
    scanf("%d", &nrcupon);

    switch (nrcupon) {
        case 1:
            printf("%.2f", pret * 90 / 100);
            break;

        case 2:
            printf("%.2f", pret * 80 / 100);
            break;

        case 3:
            printf("%.2f", pret * 70 / 100);
            break;

        default:
            printf("trebuie sa introduci un nr intre 1-3\n");
            break;
    }
    return 0;
}

