#include <iostream>
using namespace std;

int N, a[100][100], element_varf_maxim;

int main() {
   cout << "Introduceti dimensiunea matricei: ";
   cin >> N;
   cout << "Introduceti elementele matricei:\n";
   for(int i = 0; i <= N + 1; i++) {
      for(int j = 0; j <= N + 1; j++) {
         // construim o rama cu elemente 0 in jurul matricei, pentru nu a avea erori la comparari
         if((i == 0) || (i == N + 1) || (j == 0) || (j == N + 1))
            a[i][j] = 0;
         else cin >> a[i][j];
      
      }
   }
      
   for(int i = 1; i <= N; i++)
       for(int j = 1; j <= N; j++) {
           if(a[i][j] > a[i - 1][j] && a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1]) {
              if(a[i][j] > element_varf_maxim)
                 element_varf_maxim = a[i][j];
        }
          
       }
    
   cout << "Elementul varf de valoare maxima din matrice este: " << element_varf_maxim;

   return 0;
    
}
