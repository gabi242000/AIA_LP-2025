#include <stdio.h>
int main()
{
    int n,i;
    printf("Introdu numarul n: ");
    scanf("%d",&n);
    for (i=0;i<=n;i=i+2)
        printf("%d ",i);
}