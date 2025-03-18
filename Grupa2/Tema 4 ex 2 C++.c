#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Introduceți numărul de elemente: ";
    cin >> N;

    int vec[N];
    cout << "Introduceți elementele:\n";
    for (int i = 0; i < N; i++) {
        cin >> vec[i];
    }

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (vec[i] > vec[j]) {
                swap(vec[i], vec[j]);
            }
        }
    }
    
    cout << "Vectorul sortat fără duplicate: ";
    cout << vec[0] << " ";
    for (int i = 1; i < N; i++) {
        if (vec[i] != vec[i - 1]) {
            cout << vec[i] << " ";
        }
    }
    cout << endl;
    
    return 0;
}
