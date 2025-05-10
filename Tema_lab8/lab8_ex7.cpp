#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int N, i, j;
    int **matrice;

    cout << "Introduceti dimensiunea N a matricei identitate: ";
    cin >> N;

    matrice = (int **)malloc(N * sizeof(int *));
    if (matrice == nullptr) {
        cout << "Eroare la alocarea memoriei!\n";
        return 1;
    }

    for (i = 0; i < N; i++) {
        matrice[i] = (int *)malloc(N * sizeof(int));
        if (matrice[i] == nullptr) {
            cout << "Eroare la alocarea memoriei!\n";
            
            for (j = 0; j < i; j++) {
                free(matrice[j]);
            }
            free(matrice);
            return 1;
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            matrice[i][j] = (i == j) ? 1 : 0;
        }
    }

    cout << "Matricea identitate " << N << "x" << N << ":\n";
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << matrice[i][j] << " ";
        }
        cout << "\n";
    }

    for (i = 0; i < N; i++) {
        free(matrice[i]);
    }
    free(matrice);

    return 0;
}