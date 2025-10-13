#include <stdio.h>

int main(){
    int n, v[100];
    v[0] = 0;
    v[1] = 1;
    printf("Indtrodu numarul:");
    scanf("%d", &n);
    for (int i = 2; i <= n; i++){
        v[i] = v[i-1] + v[i-2];
    }
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    return 0;
}