#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char* sir1, * sir2, * sir_concat;
    int len1, len2;

    char buffer1[1001], buffer2[1001];
    printf("Introdu primul sir: ");
    fgets(buffer1, sizeof(buffer1), stdin);
    printf("Introdu al doilea sir: ");
    fgets(buffer2, sizeof(buffer2), stdin);

    buffer1[strcspn(buffer1, "\n")] = '\0';
    buffer2[strcspn(buffer2, "\n")] = '\0';

    len1 = strlen(buffer1);
    len2 = strlen(buffer2);

    sir1 = (char*)malloc((len1 + 1) * sizeof(char));
    sir2 = (char*)malloc((len2 + 1) * sizeof(char));
    if (sir1 == NULL || sir2 == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }

    strcpy(sir1, buffer1);
    strcpy(sir2, buffer2);

    sir_concat = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    if (sir_concat == NULL) {
        printf("Eroare la alocarea memoriei pentru concatenare!\n");
        free(sir1);
        free(sir2);
        return 1;
    }

    strcpy(sir_concat, sir1);
    strcat(sir_concat, sir2);

    printf("Sirul concatenat este: %s\n", sir_concat);

    free(sir1);
    free(sir2);
    free(sir_concat);

    return 0;
}
