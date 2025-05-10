#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *sir1, *sir2, *rezultat;
    int lungime1, lungime2;

    printf("Introduceti primul sir: ");
    sir1 = (char*)malloc(100 * sizeof(char)); 
    if (sir1 == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }
    fgets(sir1, 100, stdin);
    lungime1 = strlen(sir1);
    if (sir1[lungime1 - 1] == '\n') {
        sir1[lungime1 - 1] = '\0'; 
        lungime1--;
    }

    sir1 = (char*)realloc(sir1, (lungime1 + 1) * sizeof(char));
    if (sir1 == NULL) {
        printf("Eroare la realocarea memoriei!\n");
        return 1;
    }
    printf("Introduceti al doilea sir: ");
    sir2 = (char*)malloc(100 * sizeof(char)); 
    if (sir2 == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        free(sir1);
        return 1;
    }
    fgets(sir2, 100, stdin);
    lungime2 = strlen(sir2);
    if (sir2[lungime2 - 1] == '\n') {
        sir2[lungime2 - 1] = '\0'; 
        lungime2--;
    }

    sir2 = (char*)realloc(sir2, (lungime2 + 1) * sizeof(char));
    if (sir2 == NULL) {
        printf("Eroare la realocarea memoriei!\n");
        free(sir1);
        return 1;
    }
    rezultat = (char*)malloc((lungime1 + lungime2 + 1) * sizeof(char));
    if (rezultat == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        free(sir1);
        free(sir2);
        return 1;
    }
    strcpy(rezultat, sir1);
    strcat(rezultat, sir2);

    printf("Rezultatul concatenarii: %s\n", rezultat);

    free(sir1);
    free(sir2);
    free(rezultat);

    return 0;
}