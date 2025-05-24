#include <stdio.h>
#include <math.h>

int invers(int n, int nrc)
{
    if(nrc == 0)
    {
        return n;
    }
    while(nrc)
    {
        nrc--;
        return n%10*pow(10,nrc)+invers(n/10, nrc);
    }
}

int main()
{
    int n, nrc=0, cn;
    printf("Introdu un numar.\n");
    scanf("%d", &n);
    cn=n;
    while(cn)
    {
        cn=cn/10;
        nrc++;
    }
    printf("Inversul numarului %d este:%d.", n, invers(n, nrc));
    return 0;
}