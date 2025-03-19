#include <stdio.h>

int main() {
    int N;
    printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &N);

    int a[N][N];
    
    for(int i = 0; i < N; i++)
       for(int j = 0; j < N; j++) {
        if(i <= j)
          a[i][j] = i + j + 1;
        else if(i > j)
               a[i][j] = a[j][i];
       }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
           printf("%d ", a[i][j]);
        printf(" ");
    }

    return 0;
}