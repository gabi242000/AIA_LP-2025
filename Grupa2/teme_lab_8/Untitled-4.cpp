#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Introdu numarul de elemente: ";
    cin >> N;

    int *v = new int[N];
    cout << "Introdu elementele: ";
    int suma = 0;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        suma += v[i];
    }

    float media = suma / N;
    int *rezultat = new int[N];
    int contor = 0;

    for (int i = 0; i < N; ++i) {
        if (v[i] >= media) {
            rezultat[contor++] = v[i];
        }
    }

    cout << "Vector nou cu valori >= media: ";
    for (int i = 0; i < contor; ++i) {
        cout << rezultat[i] << " ";
    }

    delete[] v;
    delete[] rezultat;

    return 0;
}