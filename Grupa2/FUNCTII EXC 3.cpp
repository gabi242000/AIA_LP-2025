#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cripteaza(char s[], int key) {
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i])) {
            char baza = isupper(s[i]) ? 'A' : 'a';
            s[i] = (s[i] - baza + key) % 26 + baza;
        }
    }
}

void decripteaza(char s[], int key) {
    cripteaza(s, 26 - (key % 26));
}

int main() {
    char sir[100];
    int key;
    printf("Text de criptat: ");
    fgets(sir, sizeof(sir), stdin);
    sir[strcspn(sir, "\n")] = '\0'; 

    printf("Cheie: ");
    scanf("%d", &key);

    cripteaza(sir, key);
    printf("Text criptat: %s\n", sir);

    decripteaza(sir, key);
    printf("Text decriptat: %s\n", sir);

    return 0;
}
