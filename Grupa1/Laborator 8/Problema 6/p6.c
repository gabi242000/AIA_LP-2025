/**
6. Scrie un program care citește două șiruri de caractere de la tastatură (alocate dinamic) și 
creează un al treilea șir, tot alocat dinamic, care conține concatenarea lor. Afișează rezultatul 
și eliberează toată memoria.
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *s1, *s2, *s3;
    s1 = (char*)malloc(101 * sizeof(char));
    s2 = (char*)malloc(101 * sizeof(char));
    printf ("Introdu primul sir: ");
    scanf("%s", s1);
    printf ("Introdu al doilea sir: ");
    scanf("%s", s2);

    s3 = (char*)calloc(101, sizeof(char));

    strcpy (s3, s1);
    strcat (s3, s2);

    printf("Sirurile concatenate: %s", s3);

    free (s1);
    free (s2);
    free (s3);
    return 0;    
}