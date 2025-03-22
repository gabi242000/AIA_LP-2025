#include <stdio.h>
#include <ctype.h>

char s[101];
int main() {
    printf("Introduceti un sir de caractere: ");
    fgets(s, 256, stdin);

    for(int i = 0; s[i] != '\0'; i++) {
        if(isalpha(s[i]))
        s[i] = toupper(s[i]);
    }

    printf("Sirul de caractere introdus a fost rescris doar cu majuscule: \n%s", s);

    return 0;
}
