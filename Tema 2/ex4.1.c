#include <stdio.h>

int main()
{
    int n, i;
    printf("Introduceti un numar : ");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
        if (i % 2 == 0)

            printf("%d ", i);

    return 0;
}