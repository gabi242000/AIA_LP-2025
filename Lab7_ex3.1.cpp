#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

void cripteaza(string &sir, int key){
    for (int i = 0; sir[i] != '\0'; i++) {
        if (sir[i] >= 'a' && sir[i] <= 'z') {
            sir[i] = (sir[i] - 'a' + key) % 26 + 'a';
        }
        else if (sir[i] >= 'A' && sir[i] <= 'Z') {
            sir[i] = (sir[i] - 'A' + key) % 26 + 'A';
        }
    }   
}

void decripteaza(string &sir, int key){
    for (int i = 0; sir[i] != '\0'; i++) {
        if (sir[i] >= 'a' && sir[i] <= 'z') {
            sir[i] = (sir[i] - 'a' - key+26) % 26 + 'a';
        }
        else if (sir[i] >= 'A' && sir[i] <= 'Z') {
            sir[i] = (sir[i] - 'A' - key+26) % 26 + 'A';
        }
    }  
}

int main() {
    string sir, t;
    int key;
    cout << "Introdu un sir: ";
    getline(cin, sir);
    t = sir;
    //cout << "Sirul introdus este: " << t << endl;
    cout << "Introdu pozitia: ";
    cin >> key;

    cripteaza(sir, key);
    cout << "Sirul criptat: " << sir << endl;

    decripteaza(sir, key);
    cout << "Sirul decriptat: " << sir << endl;
    
    if (sir == t)
        cout << "Sirul a fost decriptat corect" << endl;
    else
        cout << "Sirul nu a fost decriptat corect" << endl;

    return 0;
}