#include <iostream>
using namespace std;

int main() {
    int nota;
    cout << "Introduceti o nota de la 1 la 10: ";
    cin >> nota;
    switch(nota) {
        case 1:
        cout << "Extrem de nesatisfacator!";
        break;

        case 2:
        cout << "Foarte nesatisfacator!";
        break;

        case 3:
        cout << "Nesatisfacator!";
        break;

        case 4:
        cout << "Insuficient!";
        break;

        case 5:
        cout << "Satisfacator!";
        break;

        case 6:
        cout << "Foarte satisfacator!";
        break;

        case 7:
        cout << "Bine!";
        break;

        case 8:
        cout << "Foarte bine!";
        break;

        case 9:
        cout << "Excelent!";
        break;

        case 10:
        cout << "Perfect!";
        break;

        default:
        cout << "Notele posibile sunt doar de la 1 la 10!";
        break;
    } 

    return 0;
}