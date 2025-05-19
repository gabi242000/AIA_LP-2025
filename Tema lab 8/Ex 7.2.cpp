#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Introduceti dimensiunea matricei: ";
    cin >> N;

    // Alocare matrice dinamica
    int** mat = new int*[N];
    for (int i = 0; i < N; ++i) {
        mat[i] = new int[N];
    }

    // Inițializare matrice identitate cu if
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                mat[i][j] = 1;
            } else {
                mat[i][j] = 0;
            }
        }
    }

    // Afișare matrice
    cout << "Matricea identitate:\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    // Eliberare memorie
    for (int i = 0; i < N; ++i) {
        delete[] mat[i];
    }
    delete[] mat;

    return 0;
}
