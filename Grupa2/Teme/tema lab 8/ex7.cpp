#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Introdu dimensiunea matricei (N x N): ";
    cin >> N;

    int **matrice = new int*[N];
    for (int i = 0; i < N; ++i) {
        matrice[i] = new int[N];
        for (int j = 0; j < N; ++j) {
            if (i == j)
                matrice[i][j] = 1;
            else
                matrice[i][j] = 0;
        }
    }

    cout << "Matrice identitate de dimensiune " << N << " x " << N << ":\n";
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrice[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N; ++i) delete[] matrice[i];
    delete[] matrice;

    return 0;
}
