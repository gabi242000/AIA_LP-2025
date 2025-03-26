#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* cifru(char text[], int p) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) { 
            char baza = isupper(text[i]) ? 'A' : 'a'; 
            text[i] = (text[i] - baza + p) % 26 + baza; 
        }
    }
    return text;
}

int main() {
    char text[1000];
    int p;
    printf("Introduceți textul: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = 0; 
    printf("Introduceți valoarea p: ");
    scanf("%d", &p);
    printf("Textul criptat: %s\n", cifru(text, p));
    return 0;
}
