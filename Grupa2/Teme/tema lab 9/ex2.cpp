#include <iostream>
using namespace std;

int cmmdc(int a, int b) {
    if (b == 0) return a;
    return cmmdc(b, a % b);
}

int main() {
    int a, b;
    cout << "Introdu doua numere: ";
    cin >> a >> b;

    int rezultat = cmmdc(a, b);
    cout << "CMMD intre " << a << " si " << b << " este: " << rezultat << endl;

    return 0;
}
