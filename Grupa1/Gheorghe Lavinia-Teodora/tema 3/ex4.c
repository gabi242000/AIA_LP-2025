#include <stdio.h>

int main() {
   int N;
   printf("Introduceti dimensiunea matricei: ");
   scanf("%d", &N);

   int a[N + 2][N + 2], element_varf_maxim = 0;
   printf("Introduceti elementele matricei:\n");
   for(int i = 0; i <= N + 1; i++) {
      for(int j = 0; j <= N + 1; j++) {
         if((i == 0) || (i == N + 1) || (j == 0) || (j == N + 1))
            a[i][j] = 0;
         else scanf("%d", &a[i][j]);
      
      }
   }
      
   for(int i = 1; i <= N; i++)
       for(int j = 1; j <= N; j++) {
           if(a[i][j] > a[i - 1][j] && a[i][j] > a[i][j + 1] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j - 1]) {
              if(a[i][j] > element_varf_maxim)
                 element_varf_maxim = a[i][j];
        }
          
       }
    
   printf("Elementul varf de valoare maxima din matrice este: %d", element_varf_maxim);

   return 0;
           
}