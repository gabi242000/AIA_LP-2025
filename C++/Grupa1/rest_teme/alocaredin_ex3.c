#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

int main() {
    char buffer1[MAX_LEN], buffer2[MAX_LEN];
    char *sir1, *sir2, *sir3;

    // Citirea primului șir
    printf("Introdu primul sir: ");
    fgets(buffer1, MAX_LEN, stdin);
    buffer1[strcspn(buffer1, "\n")] = '\0'; // Elimină '\n'

    // Citirea celui de-al doilea șir
    printf("Introdu al doilea sir: ");
    fgets(buffer2, MAX_LEN, stdin);
    buffer2[strcspn(buffer2, "\n")] = '\0'; // Elimină '\n'

    // Alocare dinamică pentru primele două șiruri
    sir1 = (char *)malloc(strlen(buffer1) + 1);
    sir2 = (char *)malloc(strlen(buffer2) + 1);

    if (sir1 == NULL || sir2 == NULL) {
        printf("Eroare la alocarea memoriei.\n");
        return 1;
    }

    strcpy(sir1, buffer1);
    strcpy(sir2, buffer2);

    // Alocare pentru al treilea șir (concatenare)
    sir3 = (char *)malloc(strlen(sir1) + strlen(sir2) + 1);
    if (sir3 == NULL) {
        printf("Eroare la alocarea memoriei pentru concatenare.\n");
        free(sir1);
        free(sir2);
        return 1;
    }

    // Concatenarea
    strcpy(sir3, sir1);
    strcat(sir3, sir2);

    // Afișare rezultat
    printf("Concatenarea celor doua siruri este: %s\n", sir3);

    // Eliberare memorie
    free(sir1);
    free(sir2);
    free(sir3);

    return 0;
}