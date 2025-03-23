#include <stdio.h>
int main()
{
    int n, i, a=0, b=1, c;
    printf("Introdu numarul:\n");
    scanf("%d", &n);
    if (n==1)
    printf("%d", a);
    if (n==2)
    printf("%d %d", a, b);
    else
    {
        printf("%d %d ", a, b);
        for(i=2; i<=(n-2); i++)
        {
            c=a+b;
            a=b;
            b=c;
            printf("%d ",c);
        }
    }
    return 0;
}