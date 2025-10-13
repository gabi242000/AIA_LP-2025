#include <stdio.h>

int main(){
    int n;
    printf("Introdu numarul:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("%d ", i);
    }
    printf("%d", n);
    return 0;
}