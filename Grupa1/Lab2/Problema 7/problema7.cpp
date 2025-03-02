#include <iostream>

using namespace std;

int main(){
    int salariuBrut, cod;
    cout << "Introdu-ti salariu burt:"; cin >> salariuBrut;
    cout << "Introdu tipul contractului(1,2 sau 3):"; cin >> cod;
    switch (cod){
        case 1:
            cout << "Salariul tau net este: " << salariuBrut - (salariuBrut * 25/100.);
            break;
        case 2:
            cout << "Salariul tau net este: " << salariuBrut - (salariuBrut * 10/100.);
            break;
        case 3:
            cout << "Salariul tau net este: " << salariuBrut - (salariuBrut * 5/100.);
            break;
        default:
            cout << "Contract invalid!";
    }
}