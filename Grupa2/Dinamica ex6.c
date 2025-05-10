#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000 
int main() {
    char buffer1[MAX_LEN], buffer2[MAX_LEN];
    char *sir1, *sir2, *sir_concat;
    printf("Introdu primul sir: ");
    fgets(buffer1, MAX_LEN, stdin);
    buffer1[strcspn(buffer1, "\n")] = '\0';
    printf("Introdu al doilea sir: ");
    fgets(buffer2, MAX_LEN, stdin);
    buffer2[strcspn(buffer2, "\n")] = '\0'; 
    sir1 = (char *)malloc((strlen(buffer1) + 1) * sizeof(char));
    sir2 = (char *)malloc((strlen(buffer2) + 1) * sizeof(char));

    if (sir1 == NULL || sir2 == NULL) {
        printf("Eroare la alocarea memoriei pentru siruri.\n");
        return 1;
    }
    strcpy(sir1, buffer1);
    strcpy(sir2, buffer2);
    sir_concat = (char *)malloc((strlen(sir1) + strlen(sir2) + 1) * sizeof(char));
    if (sir_concat == NULL) {
        printf("Eroare la alocarea memoriei pentru concatenare.\n");
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
