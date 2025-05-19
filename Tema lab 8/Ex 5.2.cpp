#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Introduceti numarul de elemente: ";
    cin >> N;

    // Alocare dinamica pentru vectorul original
    int* v = new int[N];

    cout << "Introduceti elementele:\n";
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    // Alocare pentru vectorul inversat
    int* invers = new int[N];
    for (int i = 0; i < N; ++i) {
        invers[i] = v[N - 1 - i];
    }

    // Afisare vector original
    cout << "Vector original:\n";
    for (int i = 0; i < N; ++i) {
        cout << v[i] << " ";
    }

    // Afisare vector inversat
    cout << "\nVector inversat:\n";
    for (int i = 0; i < N; ++i) {
        cout << invers[i] << " ";
    }

    // Eliberare memorie
    delete[] v;
    delete[] invers;

    return 0;
}
