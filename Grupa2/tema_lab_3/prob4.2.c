#include <stdio.h>
int main()
{
    int n, i,x=0,y=1,s=0;
    printf("Introdu un numar: \n");
    scanf("%d", &n);
    printf("Primele %d numere ale sirului lui Fibonacci sunt: \n",n);
    printf("%d %d ", x, y);
    for(i=0;i<n;i++)
    {
        s=x+y;
        printf("%d ",s);
        x=y;
        y=s;
    }
    return 0;
}