#include <stdio.h>
int invers(int n, int inv)
{
    if(n<=9)
        {
            return inv*10+n;
        }
    else
        {
            inv=inv*10+n%10;
            return invers(n/10,inv);
        }
}
int main()
{
    int n;
    printf("introduceti un nr: ");
    scanf("%d", &n);
    printf("rasturnatul numarului %d este: %d",n,invers(n,0));
    return 0;
}
