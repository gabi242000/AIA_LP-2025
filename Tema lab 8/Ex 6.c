#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char buffer[100];

    printf("Introduceti primul sir: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    char* s1 = (char*)malloc(strlen(buffer) + 1);
    strcpy(s1, buffer);

    printf("Introduceti al doilea sir: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    char* s2 = (char*)malloc(strlen(buffer) + 1);
    strcpy(s2, buffer);

    char* concatenat = (char*)malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(concatenat, s1);
    strcat(concatenat, s2);

    printf("Concatenarea: %s\n", concatenat);

    free(s1);
    free(s2);
    free(concatenat);
    return 0;
}
