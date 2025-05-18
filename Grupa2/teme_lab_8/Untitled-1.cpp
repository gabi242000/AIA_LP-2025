#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Introdu numarul de elemente: ";
    cin >> N;

    int *v = new int[N];
    int *inversat = new int[N];

    cout << "Introdu elementele: ";
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        inversat[N - i - 1] = v[i];
    }

    cout << "Vector original: ";
    for (int i = 0; i < N; ++i) cout << v[i] << " ";

    cout << "\nVector inversat: ";
    for (int i = 0; i < N; ++i) cout << inversat[i] << " ";

    delete[] v;
    delete[] inversat;

    return 0;
}
