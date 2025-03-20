#include <iostream>

int main() {
    int N;
    std::cout<<"Introdu numarul de linii si coloane ale matricei: ";
    std::cin>>N;
    
    int a[N][N];
    std::cout<<"Introdu valorile matricei:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin>> a[i][j];
        }
    }
    
    int vf = -1, linie = -1, coloana = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i == 0 || a[i][j] > a[i-1][j]) && (i == N-1 || a[i][j] > a[i+1][j]) && (j == 0 || a[i][j] > a[i][j-1]) && (j == N-1 || a[i][j] > a[i][j+1])) 
            {
                vf = a[i][j];
                linie = i;
                coloana = j;
            }
        }
    }
    
    if (vf != -1)
        std::cout<<"Elementul de varf al matricei este " <<vf<< " (Linia: "<<linie+1<<", Coloana:" <<coloana+1<<")\n";
    else
        std::cout<<"Nu exista element de varf in matrice.\n";
    
    return 0;
}
