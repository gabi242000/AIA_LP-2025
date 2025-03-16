#include <stdio.h>

int main()
{
    int n;
    printf("Introdu un numar (oarecare): ");
    scanf("%d",&n);
    for(int i=2;i<=n;i+=2)
        printf("%d ",i);
    return 0;
}