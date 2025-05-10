#include <iostream>
using namespace std;

int main() {
    int N;
    int *vector, *vector_invers;
    
    cout << "Introduceti numarul de elemente (N): ";
    cin >> N;
    
    // Alocare memorie pentru vector
    vector = new int[N];
    if (vector == nullptr) {
        cerr << "Eroare la alocarea memoriei pentru vector!" << endl;
        return 1;
    }
    
    cout << "Introduceti cele " << N << " numere intregi:" << endl;
    for (int i = 0; i < N; i++) {
        cin >> vector[i];
    }
    
    // Alocare memorie pentru vectorul invers
    vector_invers = new int[N];
    if (vector_invers == nullptr) {
        cerr << "Eroare la alocarea memoriei pentru vectorul invers!" << endl;
        delete[] vector; // Eliberăm memoria alocată anterior
        return 1;
    }
    
    // Inversare vector
    for (int i = 0; i < N; i++) {
        vector_invers[i] = vector[N - 1 - i];
    }
    
    // Afișare rezultate
    cout << "\nVectorul initial:" << endl;
    for (int i = 0; i < N; i++) {
        cout << vector[i] << " ";
    }
    
    cout << "\n\nVectorul inversat:" << endl;
    for (int i = 0; i < N; i++) {
        cout << vector_invers[i] << " ";
    }
    cout << endl;
    
    // Eliberare memorie
    delete[] vector;
    delete[] vector_invers;
    
    return 0;
}