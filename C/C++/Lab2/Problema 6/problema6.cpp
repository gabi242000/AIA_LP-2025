#include <iostream>

using namespace std;

int main(){
    int pret, cod;
    cout << "Introdu pretul:"; cin >> pret;
    cout << "Introdu codul de reducere(1,2 sau 3):"; cin >> cod;
    switch(cod){
        case 1:
            cout << "10% Reducere => " << pret - (10 / 100.) * pret;
            break;
        case 2:
            cout << "20% Reducere => " << pret - (20 / 100.) * pret;
            break;
        case 3:
            cout << "30% Reducere => " << pret - (30 / 100.) * pret;
            break;
        default:
            cout << "Cod de reducere invalid!";
    }
    return 0;
}