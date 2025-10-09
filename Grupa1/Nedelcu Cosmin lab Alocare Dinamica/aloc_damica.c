// #include <stdio.h>
// #include <stdlib.h>

//ex 4
// int main()
// {
//     int N, *v, *v_mare, x = 0, suma = 0, media = 0;
//     scanf("%d", &N);

//     v = (int*)malloc(N * sizeof(int*));

//     if(v == NULL){
//         printf("eroare la alocare memorie");
//         return 1;
//     }

//     for(int i = 0; i < N; i++){
//         scanf("%d ", &v[i]);
//         suma += v[i];
//     }
//     media = suma / N;
//     printf("%d este media. ", media);

//     v_mare = (int*)malloc(N * sizeof(int*));
//     if(v_mare == NULL){
//         printf("eroare la alocare memorie");
//         free(v);
//         return 1;
//     }

//     for(int i = 0; i < N; i++){
//         if(v[i] >= media){
//             v_mare[x] = v[i];
//             x++; 
//         }
//     }  

//     for(int i = 0; i < x; i++){
//         printf("%d, ", v_mare[i]);
//     }

//     free(v);
//     free(v_mare);

//     return 0;
// }

//ex5
// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     int n, *v1, *v2;

//     printf ("Introdu numarul de elemente ale vectorului: ");
//     scanf ("%d", &n);

//     v1 = (int*)malloc(n * sizeof(int));

//     for (int i = 0; i < n; i++){
//         printf("Elementul %d: ", i);
//         scanf("%d", &v1[i]);
//     }

//     v2 = (int*)malloc(n * sizeof(int));

//     for (int i = n - 1; i >= 0; i--){
//         v2[n - 1 - i] = v1[i];
//     }

//     for (int i = 0; i < n; i++){
//         printf("v1[%d]: %d\n",i ,v1[i]);
//     }
//     for (int i = 0; i < n; i++){
//         printf("v2[%d]: %d\n",i ,v2[i]);
//     }

//     free (v1);
//     free (v2);
//     return 0;

// }

//ex6
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(){
//     char *s1, *s2, *s3;
//     s1 = (char*)malloc(101 * sizeof(char));
//     s2 = (char*)malloc(101 * sizeof(char));
//     printf ("Introdu primul sir: ");
//     scanf("%s", s1);
//     printf ("Introdu al doilea sir: ");
//     scanf("%s", s2);

//     s3 = (char*)calloc(101, sizeof(char));

//     strcpy (s3, s1);
//     strcat (s3, s2);

//     printf("Sirurile concatenate: %s", s3);

//     free (s1);
//     free (s2);
//     free (s3);
//     return 0;    
// }

//ex7
// #include <stdio.h>
// #include <stdlib.h>

//     int main() {
//         int N, i, j;

//         printf("Introduceti dimensiunea matricei (N): ");
//         scanf("%d", &N);

//         int **matrice = (int **)malloc(N * sizeof(int *));

//         for (i = 0; i < N; i++) {
//             matrice[i] = (int *)malloc(N * sizeof(int));
//         }

//         for (i = 0; i < N; i++) {
//             for (j = 0; j < N; j++) {
//                 if (i == j) {
//                     matrice[i][j] = 1;
//                 } else {
//                     matrice[i][j] = 0;
//                 }
//             }
//         }

//         printf("Matricea %d x %d:\n", N, N);
//         for (i = 0; i < N; i++) {
//             for (j = 0; j < N; j++) {
//                 printf("%d ", matrice[i][j]);
//             }
//             printf("\n");
//         }

//         for (i = 0; i < N; i++) {
//             free(matrice[i]);
//         }
//         free(matrice);

//         return 0;
//     }