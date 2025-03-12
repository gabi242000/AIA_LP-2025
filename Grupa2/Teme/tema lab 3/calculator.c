#include <stdio.h>

void afiseazaMeniu() {
    printf("\nCalculator Simplu\n");
    printf("1. Adunare\n");
    printf("2. Scadere\n");
    printf("3. Inmultire\n");
    printf("4. Impartire\n");
    printf("5. Iesire\n");
    printf("Alege o optiune: ");
}

int main() {
    int optiune;
    double num1, num2, rezultat;
    
    do {
        afiseazaMeniu();
        scanf("%d", &optiune);
        
        switch (optiune) {
            case 1:
                printf("Introdu doua numere: ");
                scanf("%lf %lf", &num1, &num2);
                rezultat = num1 + num2;
                printf("Rezultatul: %.2lf\n", rezultat);
                break;
            case 2:
                printf("Introdu doua numere: ");
                scanf("%lf %lf", &num1, &num2);
                rezultat = num1 - num2;
                printf("Rezultatul: %.2lf\n", rezultat);
                break;
            case 3:
                printf("Introdu doua numere: ");
                scanf("%lf %lf", &num1, &num2);
                rezultat = num1 * num2;
                printf("Rezultatul: %.2lf\n", rezultat);
                break;
            case 4:
                printf("Introdu doua numere: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Eroare: Impartire la zero!\n");
                } else {
                    rezultat = num1 / num2;
                    printf("Rezultatul: %.2lf\n", rezultat);
                }
                break;
            case 5:
                printf("Iesire din program.\n");
                break;
            default:
                printf("Optiune invalida! Incearca din nou.\n");
        }
    } while (optiune != 5);
    
    return 0;
}
