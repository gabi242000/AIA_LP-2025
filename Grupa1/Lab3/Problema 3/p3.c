#include <stdio.h>

int main(){
    int n;
    printf("Indtrodu numarul:");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i > j)
                printf("*");
        }
        printf("\n");
    }
    return 0;
}