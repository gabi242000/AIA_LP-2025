#include <stdio.h>

int main() {
    int N, suma_rand, suma_max = 0, nr_rand_max = 0;
    printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &N);
    int a[N][N];

    printf("Introduceti elementele matricei:\n");
    for(int i = 0; i < N; i++)
       for(int j = 0; j < N; j++)
          scanf("%d", &a[i][j]);

    for(int i = 0; i < N; i++) {
        suma_rand = 0;
        for(int j = 0; j < N; j++)
           suma_rand += a[i][j];
        
        if(suma_rand > suma_max) {
            suma_max = suma_rand;
            nr_rand_max = i + 1;
        }
    }

    printf("Suma maxima %d se afla pe randul %d al matricei.", suma_max, nr_rand_max);

    return 0;
}