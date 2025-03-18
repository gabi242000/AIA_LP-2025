#include <stdio.h>

int main() {
    int optiune = 0;
    float num1, num2, rezultat;
    
    while (optiune != 5) {
        printf("\n====================================\n");
        printf("          CALCULATOR SIMPLU         \n");
        printf("====================================\n");
        printf("\nCalculator simplu:\n");
        printf("1. Adunare\n");
        printf("2. Scadere\n");
        printf("3. Inmultire\n");
        printf("4. Impartire\n");
        printf("5. Iesire\n");
        printf("====================================\n");
        printf("Alegeti o optiune: ");
        
        scanf("%d", &optiune);
        
        switch(optiune) {
            case 1:
                printf("Introduceti valorile: ");
                scanf("%f %f", &num1, &num2);
                rezultat = num1 + num2;
                printf("Rezultatul: %.2f\n", rezultat);
                break;
            case 2:
                printf("Introduceti cele doua valori: ");
                scanf("%f %f", &num1, &num2);
                rezultat = num1 - num2;
                printf("Rezultatul: %.2f\n", rezultat);
                break;
            case 3:
                printf("Introduceti doua valori: ");
                scanf("%f %f", &num1, &num2);
                rezultat = num1 * num2;
                printf("Rezultatul: %.2f\n", rezultat);
                break;
            case 4:
                printf("Introduceti doua valori: ");
                scanf("%f %f", &num1, &num2);
                if (num2 == 0) {
                    printf("Eroare: Impartire la zero!\n");
                } else {
                    rezultat = num1 / num2;
                    printf("Rezultatul: %.2f\n", rezultat);
                }
                break;
            case 5:
                printf("Incheierea programului nostru\n");
                break;
        }
    }
    
    return 0;
}
