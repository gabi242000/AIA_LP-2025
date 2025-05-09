#include <iostream>
using namespace std;

const int N = 10;
int determinant(int matrice[N][N], int dimensiune) {
    int det = 1;
    
    for (int i = 0; i < dimensiune; i++) {
        
        if (matrice[i][i] == 0) {
            bool gasit = false;
            for (int j = i + 1; j < dimensiune; j++) {
                if (matrice[j][i] != 0) {
                    for (int k = 0; k < dimensiune; k++) {
                        int temp = matrice[i][k];
                        matrice[i][k] = matrice[j][k];
                        matrice[j][k] = temp;
                    }
                    det = -det;
                    gasit = true;
                    break;
                }
            }
            if (!gasit) return 0; 
        }

        for (int j = i + 1; j < dimensiune; j++) {
            float factor = (float)matrice[j][i] / matrice[i][i];
            for (int k = 0; k < dimensiune; k++) {
                matrice[j][k] -= factor * matrice[i][k];
            }
        }
    }

    
    for (int i = 0; i < dimensiune; i++) {
        det *= matrice[i][i];
    }

    return det;
}

bool esteInversabila(int matrice[N][N], int dimensiune) {
    return determinant(matrice, dimensiune) != 0;
}

int main() {
    int matrice[N][N], dimensiune;

    cout << "Introduceți dimensiunea matricei (maxim " << N << "): ";
    cin >> dimensiune;

    cout << "Introduceți elementele matricei (rând cu rând):\n";
    for (int i = 0; i < dimensiune; i++) {
        for (int j = 0; j < dimensiune; j++) {
            cin >> matrice[i][j];
        }
    }

    
    int copieMatrice[N][N];
    for (int i = 0; i < dimensiune; i++) {
        for (int j = 0; j < dimensiune; j++) {
            copieMatrice[i][j] = matrice[i][j];
        }
    }

    int det = determinant(copieMatrice, dimensiune);
    cout << "Determinantul matricei: " << det << endl;

    if (esteInversabila(matrice, dimensiune)) {
        cout << "Matricea este inversabilă." << endl;
    } else {
        cout << "Matricea NU este inversabilă." << endl;
    }

    return 0;
}