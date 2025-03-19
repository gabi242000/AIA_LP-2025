#include <stdio.h>

//EXERCITIUL 1
// int main(){
    
//     int a[5][5], n, m, suma = 0;
//     int vector[1000] = {0};
//     int suma_max = 0, rand_max = 0;

//     printf("scrie dimensiunea matricei");
    
//     scanf("%d %d", n, m);

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             scanf("%d",a[i][j]);
//         }
//     }

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             // std::cout<< a[i][j] << " "; 
//             printf("%d ", a[i][j]) ;       
//         }
//         // std::cout<< "\n";
//         printf("\n");
//     }

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             vector[i] += a[i][j];
//         }
//         // std::cout<< "suma randului "<< i + 1 <<": "<< vector[i] << '\n';
//         printf("suma randului %d ", i ,": %d", vector[i], "\n");
        
//     }

//     for(int i = 0; i < n; i++) {
//         // std::cout << vector[i] <<" \n";
//         printf("%d ", vector[i], " \n");

//         if(vector[i] > suma_max){
//             suma_max = vector[i];
//             rand_max = i + 1;
//         }
//     }
//     // std::cout<< "suma maxima este: " << suma_max << '\n';
//     printf("suma maxima este: %d", suma_max, "\n");
//     // std::cout<< "randul maxim este: " << rand_max << '\n';
//     printf("randul maxim este: ", rand_max, "\n");

//     return 0;
// }


// int main() {
//     int n, temp = 0;
//     int v[100];

//     printf("Introdu dimensiunea vectorului: ");
//     scanf("%d", &n);
//     printf("Scrie termenii: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &v[i]);
//     }

//     for (int i = 0; i < n; i++) {
//         printf("%d \n", v[i]);
//     }

//     for (int i = 0; i < n - 1; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (v[j] < v[i]) {
//                 temp = v[i];
//                 v[i] = v[j];
//                 v[j] = temp;
//             }
//         }
//     }

//     int m = 0;
//     for (int i = 0; i < n; i++) {
//         if (i == 0 || v[i] != v[i - 1]) {
//             v[m] = v[i];
//             m++;
//         }
//     }

//     printf("Vectorul crescator este: ");
//     for (int i = 0; i < m; i++) {
//         printf("%d ", v[i]);
//     }

//     return 0;
// }


// ex 3
// #include <stdio.h>

// int main() {
//     int a[100][100];
//     int n;

//     printf("Introdu dimensiunea matricei: ");
//     scanf("%d", &n);

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             a[i][j] = i + j + 1;
//             a[j][i] = a[i][j];
//         }
//     }

//     printf("\n");
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             printf("%d ", a[i][j]);
//         }
//         printf("\n");
//     }
//     printf("\n");

//     return 0;
// }


// ex 4

// int main()
// {
//     int N;
//     printf("introduceti un numar: ");
//     scanf("%d", &N);
//     int a[N+2][N+2];

//     for(int i = 1; i <= N; i++)
//         for(int j = 1; j <= N; j++)
//             scanf("%d", &a[i][j]);

//     for(int i = 0; i <= N + 1; i++) {
//         a[i][0] = 0;
//         a[i][N+1] = 0;
//     }

//     for(int j = 0; j <= N + 1; j++) {
//         a[0][j] = 0;
//         a[N+1][j] = 0;
//     }

//     for(int i = 1; i <= N; i++)
//         for(int j = 1; j <= N; j++)
//             if(a[i][j] > a[i-1][j] && a[i][j] > a[i+1][j] && a[i][j] > a[i][j-1] && a[i][j] > a[i][j+1]) {
//                 printf("%d ", a[i][j]);
//             }

//     return 0;
// }
