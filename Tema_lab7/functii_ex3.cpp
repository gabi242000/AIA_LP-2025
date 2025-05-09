#include <iostream>
#include <string>
#include <cctype> 

using namespace std;

void cripteaza(string &s, int key) {
    for (char &c : s) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = base + (c - base + key) % 26;
        }
    }
}

void decripteaza(string &s, int key) {
    for (char &c : s) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = base + (c - base - key + 26) % 26;
        }
    }
}

int main() {
    string s;
    int key;

    cout << "Introdu un sir de caractere: ";
    getline(cin, s);

    cout << "Introdu cheia de criptare (un numar intreg): ";
    cin >> key;


    string criptat = s;
    cripteaza(criptat, key);
    cout << "Sir criptat: " << criptat << endl;


    string decriptat = criptat;
    decripteaza(decriptat, key);
    cout << "Sir decriptat: " << decriptat << endl;

    
    if (s == decriptat) {
        cout << "Decriptarea a fost realizata cu succes!" << endl;
    } else {
        cout << "Eroare la decriptare!" << endl;
    }

    return 0;
}