#include <iostream>
#include <iomanip> // pentru setprecision

using namespace std;

int main() {
    int N;
    cout << "Introduceti numarul de elemente (N): ";
    cin >> N;

    // Alocare dinamica a vectorului
    int* vector = new int[N];
    if (vector == nullptr) {
        cerr << "Eroare la alocarea memoriei!\n";
        return 1;
    }

    // Citire elemente
    cout << "Introduceti cele " << N << " numere intregi:\n";
    for (int i = 0; i < N; i++) {
        cin >> vector[i];
    }

    // Calcul medie
    double suma = 0;
    for (int i = 0; i < N; i++) {
        suma += vector[i];
    }
    double media = suma / N;
    cout << fixed << setprecision(2);
    cout << "Media aritmetica: " << media << endl;

    // Numărare elemente >= media
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (vector[i] >= media) {
            count++;
        }
    }

    // Alocare vector filtrat
    int* vector_filtrat = new int[count];
    if (vector_filtrat == nullptr) {
        cerr << "Eroare la alocarea memoriei!\n";
        delete[] vector;
        return 1;
    }

    // Populare vector filtrat
    int nr = 0;
    for (int i = 0; i < N; i++) {
        if (vector[i] >= media) {
            vector_filtrat[nr] = vector[i];
            nr++;
        }
    }

    // Afișare rezultate
    cout << "Elementele mai mari sau egale cu media (" << media << "):\n";
    for (int i = 0; i < count; i++) {
        cout << vector_filtrat[i] << " ";
    }
    cout << endl;

    // Eliberare memorie
    delete[] vector;
    delete[] vector_filtrat;

    return 0;
}