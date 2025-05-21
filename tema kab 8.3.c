#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s1[100], s2[100];

    printf("Primul sir: ");
    fgets(s1, sizeof(s1), stdin);
    s1[strcspn(s1, "\n")] = 0;  

    printf("Al doilea sir: ");
    fgets(s2, sizeof(s2), stdin);
    s2[strcspn(s2, "\n")] = 0;

    
    char *rezultat = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(rezultat, s1);
    strcat(rezultat, s2);

    printf("Concatenare: %s\n", rezultat);

    free(rezultat);
    return 0;
}
