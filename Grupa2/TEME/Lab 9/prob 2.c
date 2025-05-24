#include <stdio.h>

int cmmdc(int a, int b)
{
    if(a == 0)
    {
        return b;
    }
    else if(b == 0)
    {
        return a;
    }
    else
    {
        return cmmdc(b, a%b);
    }
}

int main()
{
    int a, b;
    printf("a=");
    scanf("%d", &a);
    printf("b=");
    scanf("%d", &b);
    printf("Cel mai mare divizor comun al celor doua numere este %d.", cmmdc(a, b));
    return 0;
}