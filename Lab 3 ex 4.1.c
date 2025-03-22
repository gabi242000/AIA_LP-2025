#include <stdio.h>
int main()
{
    int n, start = 0;
    printf("Introdu un numar: ");
    scanf("%d", &n);
    while (start <= n)
    {
        printf("%d \n", start);
        start += 2;
    }
    return 0;
}
