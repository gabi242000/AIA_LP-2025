#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Introduceti N: ";
    cin >> N;
    
    if (N <= 0) {
        cout << "Dimensiunea trebuie să fie pozitivă!" << endl;
        return 1;
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (j >= i ? i + j + 1 : j + i + 1) << " ";
        }
        cout << endl;
    }
    
    return 0;
}


