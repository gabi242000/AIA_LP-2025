#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char *sir1 = new char[100];
    char *sir2 = new char[100];

    cout << "Introdu primul sir: ";
    cin.getline(sir1, 100);
    cout << "Introdu al doilea sir: ";
    cin.getline(sir2, 100);

    int lungime1 = strlen(sir1);
    int lungime2 = strlen(sir2);

    char *concatenat = new char[lungime1 + lungime2 + 1];

    strcpy(concatenat, sir1);
    strcat(concatenat, sir2);

    cout << "Sir concatenat: " << concatenat << endl;

    delete[] sir1;
    delete[] sir2;
    delete[] concatenat;

    return 0;
}