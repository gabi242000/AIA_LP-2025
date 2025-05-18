#include <iostream>
using namespace std;

int invers(int n, int x = 0) {
    if (n == 0) return x;
    return invers(n / 10, x * 10 + n % 10);
}

int main() {
    int numar;
    cout << "Introdu un numar: ";
    cin >> numar;

    int inversat = invers(numar);
    cout << "Numarul inversat este: " << inversat << endl;

    return 0;
}
