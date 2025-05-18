#include <stdio.h>
int cmmdc(int a, int b)
{
    if (b==0) return a;
    if(a==0) return b;
    if(a>=b) return cmmdc(a-b,b);
    else return (cmmdc(a,b-a));
}
int main()
{
    int a, b;
    printf("Introdu doua numere:\n");
    scanf("%d %d", &a, &b);
    printf("Cmmdc al celor doua este: %d", cmmdc(a, b));
}