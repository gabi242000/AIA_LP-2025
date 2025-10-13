#include <stdio.h>
#include <string.h>

void cripteaza(char s[], int key) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = ((s[i] - 'a' + key) % 26) + 'a';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = ((s[i] - 'A' + key) % 26) + 'A';
        }
    }
}

void decripteaza(char s[], int key) {
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] = ((s[i] - 'a' - key + 26) % 26) + 'a';
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = ((s[i] - 'A' - key + 26) % 26) + 'A';
        }
    }
}

int main() {
    char sir[100];
    int key;

    printf("Introduceti un sir de caractere: ");
    fgets(sir, sizeof(sir), stdin);
    sir[strcspn(sir, "\n")] = '\0'; 
    
    printf("Introduceti cheia de criptare: ");
    scanf("%d", &key);

    cripteaza(sir, key);
    printf("Sirul criptat: %s\n", sir);

    decripteaza(sir, key);
    printf("Sirul decriptat: %s\n", sir);

    return 0;
}