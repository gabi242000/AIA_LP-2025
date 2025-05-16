#include <stdio.h>
#include <stdlib.h>

int main(){
  int **A, **B, **C;
  int i, j, k;
  int liniiA, coloaneA, liniiB, coloaneB;
  printf("Introduceți dimensiunile matricei A (linii coloane): ");
  scanf("%d %d", &liniiA, &coloaneA);
  printf("Introduceți dimensiunile matricei B (linii coloane): ");
  scanf("%d %d", &liniiB, &coloaneB);
  if (coloaneA != liniiB) {
      printf("Matricele nu pot fi înmulțite!\n");
      return 1;
}

 A = (int**)malloc(liniiA * sizeof(int*));
 for (i = 0; i < liniiA; i++) {
     A[i] = (int*)malloc(coloaneA * sizeof(int));
    }
 B = (int**)malloc(liniiB * sizeof(int*));
 for (i = 0; i < liniiB; i++) {
      B[i] = (int*)malloc(coloaneB * sizeof(int));
     }
 C = (int**)malloc(liniiA * sizeof(int*));
for (i = 0; i < liniiA; i++) {
      C[i] = (int*)malloc(coloaneB * sizeof(int));
     }    
printf("Introduceți elementele matricei A:\n");
for (i = 0; i < liniiA; i++) {
      for (j = 0; j < coloaneA; j++) {
         printf("A[%d][%d] = ", i, j);
         scanf("%d", &A[i][j]);
        }
}
printf("Introduceți elementele matricei B:\n");
for (i = 0; i < liniiB; i++) {
      for (j = 0; j < coloaneB; j++) {
         printf("B[%d][%d] = ", i, j);
         scanf("%d", &B[i][j]);
        }
}
for (i = 0; i < liniiA; i++) {
      for (j = 0; j < coloaneB; j++) {
         C[i][j] = 0;
         for (k = 0; k < coloaneA; k++) {
            C[i][j] += A[i][k] * B[k][j];
             } 
        }
}
printf("Rezultatul înmulțirii A * B este:\n");
for (i = 0; i < liniiA; i++) {
      for (j = 0; j < coloaneB; j++) {
         printf("%d  ", C[i][j]);
    }
      printf("\n");
}

for (i = 0; i < liniiA; i++) free(A[i]);
free(A);
for (i = 0; i < liniiB; i++) free(B[i]);
free(B);
for (i = 0; i < liniiA; i++) free(C[i]);
free(C);

return 0;
}