#include <stdio.h>
int main()
{
    int n;
    printf("Introdu un numar: ");
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0;j <= n+i; j++)
            if (j < n-i)
                printf(" ");
            else
                printf("*");
        printf("\n");
    }
}