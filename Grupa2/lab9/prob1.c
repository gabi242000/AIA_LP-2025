#include <stdio.h>
int invers (int n, int r)
{
    if (n==0) return r;
    return invers(n/10, r*10+n%10);
}
int main()
{
    int n, r=0;
    printf("Introdu numarul pe care vrei sa il inversezi:\n");
    scanf("%d", &n);
    printf("%d", invers(n,r));

}
