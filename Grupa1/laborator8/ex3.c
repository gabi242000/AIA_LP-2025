#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s1, *s2, *s3;
    int len1, len2;

    printf("Introdu primul sir: ");
    s1 = (char*)malloc(100 * sizeof(char));
    if (s1 == NULL) {
        printf("Eroare la alocarea memoriei pentru s1!\n");
        return 1;
    }
    fgets(s1, 100, stdin);
    s1[strcspn(s1, "\n")] = '\0';  


    printf("Introdu al doilea sir: ");
    s2 = (char*)malloc(100 * sizeof(char));
    if (s2 == NULL) {
        printf("Eroare la alocarea memoriei pentru s2!\n");
        free(s1);
        return 1;
    }
    fgets(s2, 100, stdin);
    s2[strcspn(s2, "\n")] = '\0';

    len1 = strlen(s1);
    len2 = strlen(s2);


    s3 = (char*)malloc((len1 + len2 + 1) * sizeof(char));
    if (s3 == NULL) {
        printf("Eroare la alocarea memoriei pentru s3!\n");
        free(s1);
        free(s2);
        return 1;
    }

    strcpy(s3, s1);    
    strcat(s3, s2);    

    printf("Sirul concatenat este: %s\n", s3);

    free(s1);
    free(s2);
    free(s3);

    return 0;
}
