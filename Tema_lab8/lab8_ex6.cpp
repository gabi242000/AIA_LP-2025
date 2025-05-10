#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

int main() {
    char *sir1, *sir2, *rezultat;
    int lungime1, lungime2;

    cout << "Introduceti primul sir: ";
    sir1 = (char*)malloc(100 * sizeof(char)); 
    if (sir1 == nullptr) {
        cout << "Eroare la alocarea memoriei!\n";
        return 1;
    }
    cin.getline(sir1, 100);
    lungime1 = strlen(sir1);
    if (sir1[lungime1 - 1] == '\n') {
        sir1[lungime1 - 1] = '\0'; 
        lungime1--;
    }

    sir1 = (char*)realloc(sir1, (lungime1 + 1) * sizeof(char));
    if (sir1 == nullptr) {
        cout << "Eroare la realocarea memoriei!\n";
        return 1;
    }
    cout << "Introduceti al doilea sir: ";
    sir2 = (char*)malloc(100 * sizeof(char)); 
    if (sir2 == nullptr) {
        cout << "Eroare la alocarea memoriei!\n";
        free(sir1);
        return 1;
    }
    cin.getline(sir2, 100);
    lungime2 = strlen(sir2);
    if (sir2[lungime2 - 1] == '\n') {
        sir2[lungime2 - 1] = '\0'; 
        lungime2--;
    }

    sir2 = (char*)realloc(sir2, (lungime2 + 1) * sizeof(char));
    if (sir2 == nullptr) {
        cout << "Eroare la realocarea memoriei!\n";
        free(sir1);
        return 1;
    }
    rezultat = (char*)malloc((lungime1 + lungime2 + 1) * sizeof(char));
    if (rezultat == nullptr) {
        cout << "Eroare la alocarea memoriei!\n";
        free(sir1);
        free(sir2);
        return 1;
    }
    strcpy(rezultat, sir1);
    strcat(rezultat, sir2);

    cout << "Rezultatul concatenarii: " << rezultat << "\n";

    free(sir1);
    free(sir2);
    free(rezultat);

    return 0;
}