#include <iostream>
using namespace std;

int N, a[100][100];

int main() {
    cout << "Introduceti dimensiunea matricei: ";
    cin >> N;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
        if(i <= j)
          a[i][j] = i + j + 1;
        else if(i > j)
               a[i][j] = a[j][i];  
       }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
           cout << a[i][j] << " ";
        cout << "\n";
    }

    return 0;
}