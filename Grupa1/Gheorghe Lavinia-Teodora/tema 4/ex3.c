#include <stdio.h>
#include <string.h>

int verif_cons_voc(char s[]) {
    if(s[0] == 'z') {
        for(int i = 0; s[i] != '\0'; i += 2) {
            if(strchr("aeiou", s[i]) != NULL)
              return 0;
        }
        for(int i = 1; s[i] != '\0'; i += 2)
           if(strchr("aeiou", s[i]) == NULL)
             return 0;
    }
    else return 0;

    return 1;
}

char s[101];

int main() {
    printf("Introduceti un cuvant: ");
    scanf("%s", &s);
    if(verif_cons_voc(s) == 1 && strlen(s) % 2 == 0)
      printf("Cuvantul este frumos!");
    else printf( "Cuvantul NU este frumos!");

    return 0;
}