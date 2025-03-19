#include <iostream>
using namespace std;

int N, v[100], aux;

int main() {
    cout << "Introduceti dimensiunea vectorului: ";
    cin >> N;
    cout << "Introduceti elementele vectorului: \n";

    for(int i = 0; i < N; i++)
      cin >> v[i];

    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if(v[i] > v[j]) {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
              }
        }
    }

    for(int i = 0; i < N - 1; i++) {
        if(v[i] == v[i + 1]) {
            for(int k = i; k < N - 1; k++)
               v[k] = v[k + 1];
            N --;
            i --;
        }
       
    }

    cout << "Vectorul ordonat crescator si din care s-au eliminat dublurile arata astfel: \n";
    for(int i = 0; i < N; i++)
      cout << v[i] << " ";
      
    return 0;
}