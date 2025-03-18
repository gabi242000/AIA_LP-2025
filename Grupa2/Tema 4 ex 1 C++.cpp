#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cout << "Introduceți dimensiunea matricei (N): ";
    cin >> N;

    vector<vector<int>> matrice(N, vector<int>(N));
    cout << "Introduceți elementele matricei:\n";
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matrice[i][j];
        }
    }

    int max_suma = -1, rand_max = 0;
    
    for (int i = 0; i < N; i++) {
        int suma = 0;
        for (int j = 0; j < N; j++) {
            suma += matrice[i][j];
        }
        if (suma > max_suma) {
            max_suma = suma;
            rand_max = i;
        }
    }
    
    cout << "Rândul cu suma maximă este " << rand_max + 1 << " cu suma " << max_suma << ".\n";
    
    return 0;
}





