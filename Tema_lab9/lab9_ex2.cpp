#include <iostream>
using namespace std;

int cmmdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return cmmdc(b, a % b);
}

int main() {
    int a, b;
    
    cout << "Introduceți primul număr (a): ";
    cin >> a;
    
    cout << "Introduceți al doilea număr (b): ";
    cin >> b;
    
    int rezultat = cmmdc(a, b);
    
    cout << "Cel mai mare divizor comun al lui " << a << " și " << b 
         << " este: " << rezultat << endl;
    
    return 0;
}