#include <stdio.h>
int main()
{
    int n, i, j, space;
    printf("Introdu numarul de randuri: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (space = 1; space <= n - i; space++) {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++) {
            printf("*");
        }
        printf("\n");
    } 
    return 0;
}