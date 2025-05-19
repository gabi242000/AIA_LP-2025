#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Funcția care aplică Cifrul Cezar asupra unui text
void caesar_cipher(char *text, int p) {
    for (int i = 0; text[i] != '\0'; i++) { // Parcurgem fiecare caracter până la terminatorul de șir
        if (isalpha(text[i])) { // Verificăm dacă este o literă
            char base = isupper(text[i]) ? 'A' : 'a'; // Determinăm baza: 'A' pentru litere mari, 'a' pentru litere mici
            text[i] = (text[i] - base + p) % 26 + base; // Aplicăm formula Cifrului Cezar
        }
    }
}

int main() {
    char text[1000]; // Declarăm un buffer pentru textul de intrare
    int p; // Valoarea p pentru cifru
    
    printf("Introduceti textul: ");
    fgets(text, sizeof(text), stdin); // Citim textul inclusiv spațiile folosind fgets
    text[strcspn(text, "\n")] = 0; // Eliminăm caracterul newline introdus de fgets
    
    printf("Introduceti p: ");
    scanf("%d", &p); // Citim valoarea p de la tastatură
    
    caesar_cipher(text, p); // Aplicăm cifrul Cezar asupra textului
    printf("Text criptat: %s\n", text); // Afișăm textul criptat
    
    return 0; // Terminăm programul
}
