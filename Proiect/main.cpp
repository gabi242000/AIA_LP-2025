#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Sarcina {
    string titlu;
    string descriere;
    string data;
    bool completata;
};

vector<Sarcina> sarcini;

void salvareFisier() {
    ofstream fisier("sarcini.txt");
    for (const auto& sarcina : sarcini) {
        fisier << sarcina.titlu << "|" << sarcina.descriere << "|" 
               << sarcina.data << "|" << sarcina.completata << "\n";
    }
    fisier.close();
}

void incarcareFisier() {
    ifstream fisier("sarcini.txt");
    string linie;
    while (getline(fisier, linie)) {
        Sarcina sarcina;
        size_t poz = 0;
        string token;
        
        poz = linie.find("|");
        sarcina.titlu = linie.substr(0, poz);
        linie.erase(0, poz + 1);
        
        poz = linie.find("|");
        sarcina.descriere = linie.substr(0, poz);
        linie.erase(0, poz + 1);
        
        poz = linie.find("|");
        sarcina.data = linie.substr(0, poz);
        linie.erase(0, poz + 1);
        
        sarcina.completata = (linie == "1");
        sarcini.push_back(sarcina);
    }
    fisier.close();
}

void adaugaSarcina() {
    Sarcina sarcina;
    cout << "\nIntroduceti titlul sarcinii: ";
    getline(cin, sarcina.titlu);
    cout << "Introduceti descrierea: ";
    getline(cin, sarcina.descriere);
    cout << "Introduceti data (DD/MM/YYYY): ";
    getline(cin, sarcina.data);
    sarcina.completata = false;
    sarcini.push_back(sarcina);
    salvareFisier();
    cout << "Sarcina adaugata cu succes!\n";
}

void afiseazaSarcini() {
    if (sarcini.empty()) {
        cout << "\nNu exista sarcini!\n";
        return;
    }
    
    cout << "\nLista Sarcini:\n";
    for (size_t i = 0; i < sarcini.size(); i++) {
        cout << i + 1 << ". " << sarcini[i].titlu 
             << " (" << (sarcini[i].completata ? "Completata" : "In lucru") << ")\n";
        cout << "   Descriere: " << sarcini[i].descriere << "\n";
        cout << "   Data: " << sarcini[i].data << "\n\n";
    }
}

void marcheazaCompletata() {
    if (sarcini.empty()) {
        cout << "\nNu exista sarcini!\n";
        return;
    }
    
    afiseazaSarcini();
    int index;
    cout << "Introduceti numarul sarcinii de marcat ca completata: ";
    cin >> index;
    cin.ignore();
    
    if (index > 0 && index <= sarcini.size()) {
        sarcini[index-1].completata = true;
        salvareFisier();
        cout << "Sarcina marcata ca completata!\n";
    } else {
        cout << "Numar invalid!\n";
    }
}

int main() {
    incarcareFisier();
    int optiune;
    
    do {
        cout << "\n=== Sistem de Gestionare a Sarcinilor - Proiect PCLP ===\n";
        cout << "1. Adauga sarcina noua\n";
        cout << "2. Arata toate sarcinile\n";
        cout << "3. Seteaza sarcina completata\n";
        cout << "4. Iesi\n";
        cout << "Alege o optiune : ";
        cin >> optiune;
        cin.ignore();
        
        switch (optiune) {
            case 1:
                adaugaSarcina();
                break;
            case 2:
                afiseazaSarcini();
                break;
            case 3:
                marcheazaCompletata();
                break;
            case 4:
                cout << "La revedere!\n";
                break;
            default:
                cout << "Optiune invalida!\n";
        }
    } while (optiune != 4);
    
    return 0;
} 
