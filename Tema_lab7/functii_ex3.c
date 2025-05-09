#include <stdio.h>
#include <ctype.h> 

void cripteaza(char s[], int key) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            if (isupper(s[i])) {
                s[i] = 'A' + (s[i] - 'A' + key) % 26;
            } else {
                s[i] = 'a' + (s[i] - 'a' + key) % 26;
            }
        }
    }
}

void decripteaza(char s[], int key) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) {
            if (isupper(s[i])) {
                s[i] = 'A' + (s[i] - 'A' - key + 26) % 26;
            } else {
                s[i] = 'a' + (s[i] - 'a' - key + 26) % 26;
            }
        }
    }
}

int main() {
    char s[100];
    int key;

    printf("Introdu un sir de caractere: ");
    fgets(s, sizeof(s), stdin);

    printf("Introdu cheia de criptare (un numar intreg): ");
    scanf("%d", &key);

    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '\n') {
            s[i] = '\0';
            break;
        }
    }

    cripteaza(s, key);
    printf("Sir criptat: %s\n", s);

    decripteaza(s, key);
    printf("Sir decriptat: %s\n", s);

    return 0;
}