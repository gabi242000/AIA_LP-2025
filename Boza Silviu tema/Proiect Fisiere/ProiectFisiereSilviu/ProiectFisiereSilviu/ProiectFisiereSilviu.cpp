#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>   // pentru remove
using namespace std;

void citesteFisier(const string& numeFisier) {
    ifstream fisier(numeFisier);
    if (!fisier) {
        cout << "Eroare la deschiderea fisierului.\n";
        return;
    }

    string linie;
    while (getline(fisier, linie)) {
        cout << linie << endl;
    }
    fisier.close();
}

void modificaFisier(const string& numeFisier) {
    ofstream fisier(numeFisier);
    if (!fisier) {
        cout << "Eroare la deschiderea fisierului pentru scriere.\n";
        return;
    }

    cout << "Introdu textul care va fi scris in fisier (Enter pe o linie goala pentru a termina):\n";
    string linie;
    while (true) {
        getline(cin, linie);
        if (linie.empty()) break;
        fisier << linie << endl;
    }

    fisier.close();
    cout << "Fisierul a fost modificat cu succes.\n";
}

void stergeFisier(const string& numeFisier) {
    if (remove(numeFisier.c_str()) == 0) {
        cout << "Fisierul '" << numeFisier << "' a fost sters cu succes.\n";
    }
    else {
        cout << "Eroare la stergerea fisierului.\n";
    }
}

int main() {
    int optiune;
    string numeFisier;

    do {
        cout << "\n=== Sistem de Gestiune a Fisierelor (C++) ===\n";
        cout << "1. Citeste fisier\n";
        cout << "2. Modifica fisier\n";
        cout << "3. Sterge fisier\n";
        cout << "0. Iesire\n";
        cout << "Alege o optiune: ";
        cin >> optiune;
        cin.ignore(); // eliminam newline

        if (optiune >= 1 && optiune <= 3) {
            cout << "Introdu numele fisierului: ";
            getline(cin, numeFisier);
        }

        switch (optiune) {
        case 1:
            citesteFisier(numeFisier);
            break;
        case 2:
            modificaFisier(numeFisier);
            break;
        case 3:
            stergeFisier(numeFisier);
            break;
        case 0:
            cout << "La revedere!\n";
            break;
        default:
            cout << "Optiune invalida.\n";
        }

    } while (optiune != 0);

    return 0;
}
