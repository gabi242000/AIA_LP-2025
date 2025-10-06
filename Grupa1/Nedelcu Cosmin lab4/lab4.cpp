#include <iostream>

//EXERCITIUL 1
// int main(){
    
//     int a[5][5], n, m, suma = 0;
//     int vector[1000] = {0};
//     int suma_max = 0, rand_max = 0;

//     std::cout<< "scrie dimensiunea matricei";
//     std::cin>> n >> m;

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             std::cin>> a[i][j];
//         }
//     }

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             std::cout<< a[i][j] << " ";        
//         }
//         std::cout<< "\n";
//     }

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < m; j++){
//             vector[i] += a[i][j];
//         }
//         std::cout<< "suma randului "<< i + 1 <<": "<< vector[i] << '\n';
        
//     }

//     for(int i = 0; i < n; i++) {
//         std::cout << vector[i] <<" \n";

//         if(vector[i] > suma_max){
//             suma_max = vector[i];
//             rand_max = i + 1;
//         }
//     }
//     std::cout<< "suma maxima este: " << suma_max << '\n';
//     std::cout<< "randul maxim este: " << rand_max << '\n';

//     return 0;
// }

//EXERCITIUL 2
// int main(){

//     int n, temp = 0;
//     int v[100];

//     std::cout<< "Indrodu dimensiunea vectorului: ";
//     std::cin >> n;
//     std::cout << "Scrie termenii: ";
//     for(int i = 0; i < n; i++){
//         std::cin>> v[i];
//     }

//     for(int i = 0; i < n; i++){
//         std::cout<< v[i] << " \n";
//     }  
    
//     for(int i = 0; i < n - 1; i++){
//         for(int j = i + 1; j < n; j++){
//             if(v[j] < v[i]){
//                 temp = v[i];
//                 v[i] = v[j];
//                 v[j] = temp;
//             }
            
//         }
//     }

//     int m = 0; 
//     for (int i = 0; i < n; i++) {
//         if (i == 0 || v[i] != v[i - 1]){ 
//             v[m] = v[i];
//             m++;
//         }
//     }

//     std::cout<< "Vectorul crescator este: ";
//     for(int i = 0; i < m; i++){
//         std::cout<< v[i] << " ";
//     }

//     return 0;
// }

// EXERCITIUL 3
//  int main(){

//     int a[100][100];
//     int n;
//     std::cout<<"introdu dimensiunea matricei: ";
//     std::cin>> n;

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j< n; j++){
//             a[i][j] = i + j + 1;
//             a[j][i] = a[i][j];            
//         }
//     }

//     std::cout<< "\n";
//     for(int i = 0; i< n; i++){
//         for(int j = 0; j< n; j++){
//             std::cout<< a[i][j] << " ";
//         }
//         std::cout<< "\n";
//     }
//     std::cout<< "\n";
//     return 0;
//  }


// EXERCITIUL 4

// int main(){

//     int a[100][100];
//     int n;

//     std::cout<< "indrodu dimensiunea matricei: ";
//     std::cin>> n;

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             std::cin>> a[i][j];
//         }
//     }

//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < n; j++){
//             std::cout<< a[i][j] << " ";
//         }
//         std::cout<< '\n';
//     }

//     return 0;
// }