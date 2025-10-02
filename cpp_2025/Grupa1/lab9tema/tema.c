#include <stdio.h>

int invers(int n, int aux)
{
    if(n == 0)
    {
        return aux;
    }
    return invers(n/10, aux * 10 + n % 10);
}

int cmmdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }    
    return cmmdc(b, a % b);
}
int main()
{
    int n;
    printf("Introdu numarul: ");
    scanf("%d", &n);
    n = invers(n, 0);
    printf("Inversul numarului este: %d", n);
    int a, b;
    printf("Introdu primul numar: ");
    scanf("%d", &a);
    printf("Introdu al doilea numar: ");
    scanf("%d", &b);
    
    int rezultat = cmmdc(a, b);
    printf("Cel mai mare divizor comun este: %d", rezultat);

    
    return 0;
}