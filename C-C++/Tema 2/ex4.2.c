#include <stdio.h>
int main()
{
    int n, a = 1, b = 1, c, i;
    printf("Introduceti un numar : ");
    scanf("%d", &n);
    if (n == 1)
        printf("%d ", a);
    if (n >= 2)
        printf("%d %d ", a, b);
    for (i = 1; i <= n - 2; i++)
    {
        c = a + b;
        a = b;
        b = c;
        printf("%d ", c);
    }
    return 0;
}