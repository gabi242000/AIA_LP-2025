#include <iostream>

using namespace std;

int main(){
    int nota;
    cout << "Scrie nota "; cin >> nota;
    if (nota==10) cout << "Perfect";
    if (nota==9) cout << "Aproape perfect";
    if (nota==8) cout << "Foarte bun";
    if (nota==7) cout << "Bun";
    if (nota==6) cout << "Peste medie";
    if (nota==5) cout << "Suficient";
    if (nota>=0 && nota<=4) cout << "Insuficient";
    if (nota<0 || nota >10) cout << " Nota trebuie sa fie intre 1 si 10";
    return 0;
}
