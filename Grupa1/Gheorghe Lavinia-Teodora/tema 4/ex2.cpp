#include <iostream>
#include <cstring>
using namespace std;

char s[256], aux;
int x, y;

int main() {
    cout << "Introduceti un cuvant: ";
    cin >> s;
    cout << "Introduceti doua pozitii pe care le doriti interschimbate: ";
    cin >> x >> y;

    if((x < 0 || x > strlen(s)) || (y < 0 || y > strlen(s))) {
        cout << "Pozitia introdusa este invalida!";
        return 1;
    }

    aux = s[x];
    s[x] = s[y];
    s[y] = aux;

    cout << "Cuvantul in forma finala este: " << s;

    return 0;
}