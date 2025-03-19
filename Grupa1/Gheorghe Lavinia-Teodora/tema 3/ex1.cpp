#include <iostream>
using namespace std;

int N, a[1000][1000], suma_rand, suma_max, nr_rand_max;

int main() {

    cout << "Introduceti dimensiunea matricei: ";
    cin >> N;
    cout << "Introduceti elementele matricei:\n";
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
         cin >> a[i][j];
      }
    }

    for(int i = 0; i < N; i++) {
        suma_rand = 0;
        for(int j = 0; j < N; j++) {
            suma_rand += a[i][j];
        }

        if(suma_rand > suma_max) {
            suma_max = suma_rand;
            nr_rand_max = i + 1;
        }
    }

    cout << "Suma maxima " << suma_max << " se afla pe randul " << nr_rand_max << " al matricei.";

    return 0;
}