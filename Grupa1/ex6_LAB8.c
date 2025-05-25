#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s1, *s2, *concat;
    int len1, len2;

    s1 =(char *)malloc(100 * sizeof(char));
    s2 =(char *)malloc(100 * sizeof(char));

    if(s1==NULL || s2==NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }

    printf("Introduceti primul sir: ");
    scanf("%s", s1);

    printf("Introduceti al doilea sir: ");
    scanf("%s", s2);

    len1= strlen(s1);
    len2= strlen(s2);

    concat=(char *)malloc((len1+len2+1) * sizeof(char));
    if(concat==NULL) {
        printf("Eroare la alocarea memoriei pentru concatenare!\n");
        free(s1);
        free(s2);
        return 1;
    }

    strcpy(concat, s1);
    strcat(concat, s2);

    printf("Sirul concatenat: %s\n", concat);

    free(s1);
    free(s2);
    free(concat);
    return 0;
}
