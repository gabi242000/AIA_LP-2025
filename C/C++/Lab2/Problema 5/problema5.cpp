#include <iostream>

using namespace std;

int main(){
    int nota;
    cout << "Introdu nota:"; cin >> nota;
    switch(nota){
        case 1:
            cout << "Ingrozitor";
            break;
        case 2:
            cout << "Oribil";
            break;
        case 3:
            cout << "Foarte Rau";
            break;
        case 4:
            cout << "Insuficient";
            break;
        case 5:
            cout << "Suficient";
            break;
        case 6:
            cout << "Decent";
            break;
        case 7:
            cout << "Bine";
            break;
        case 8:
            cout << "Foarte bine";
            break;
        case 9:
            cout << "Grozav";
            break;
        case 10:
            cout << "Excelent";
            break;
        default:
            cout << "Introdu un numar de la 1-10!";
    }
    return 0;
}