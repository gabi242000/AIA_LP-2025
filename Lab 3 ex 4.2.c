#include <stdio.h>
int main()
{
    int n;
    printf("Introdu un numar: ");
    scanf("%d", &n);
    int fib1 = 0, fib2 = 1, fib_next;

    if (n >= 1)
        printf("%d ", fib1);
    if (n >= 2)
        printf("%d ", fib2);

    for (int i = 3; i <= n; i++)
    {
        fib_next = fib1 + fib2;
        printf("%d ", fib_next);
        fib1 = fib2;
        fib2 = fib_next;
    }

    printf("\n");
    return 0;
}