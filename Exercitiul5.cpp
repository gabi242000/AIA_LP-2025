#include <iostream>
using namespace std;

int main() {
    int value;
    cout << "Acordati o nota de la 1 la 10: ";
    cin >> value;
    
    if (value < 5) {
        cout << "Nesatisfacator";
    } else if (value >= 5 && value <= 7) {
        cout << "Satisfacator";
    } else if (value >= 8) {
        cout << "Excelent";
    }
    
    return 0;
}
