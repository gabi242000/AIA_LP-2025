#include <iostream>
using namespace std;

int invers(int n, int nr) {
    if (n == 0) {
        return nr;
    }
    return invers(n / 10, nr * 10 + n % 10);
}

int main() {
    int numar;
    
    cout << "Introduceți un număr natural: ";
    cin >> numar;
    
    int numar_inversat = invers(numar, 0);
    
    cout << "Numărul inversat este: " << numar_inversat << endl;
    
    return 0;
}