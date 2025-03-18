#include <iostream>

using namespace std;

int main() {
    int nota;
    cout << "Introduceti o nota (1-10): ";
    cin >> nota;
    
    if (nota == 10) cout << "Excelent";
    else if (nota == 9) cout << "Foarte bine";
    else if (nota == 8) cout << "Bine";
    else if (nota == 7) cout << "Destul de bine";
    else if (nota == 6) cout << "Acceptabil";
    else if (nota == 5) cout << "Satisfacator";
    else if (nota == 4) cout << "Slab";
    else if (nota == 3) cout << "Foarte slab";
    else if (nota == 2) cout << "Insuficient";
    else if (nota == 1) cout << "Foarte insuficient";
    else cout << "Nota invalida! Introduceti un numar intre 1 si 10.";
    
    cout << endl;
    return 0;
}