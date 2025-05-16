#include <stdio.h>

int cmmdc(int a, int b) {
    if(b == 0) {
        return a;
    }
    return cmmdc(b, a % b);
}

int main()
{   int a, b;
    printf("introdu primul numar: ");
    scanf("%d",&a);
    printf("introdu al doilea numar: ");
    scanf("%d",&b);
    printf("Cel mai mare divizor comun al numerelor %d si %d este: %d",a,b,cmmdc(a,b));
    return 0;
}
