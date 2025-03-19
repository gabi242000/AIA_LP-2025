#include <stdio.h>
int main()
{
    //ex_4.2
    int N,i,f1,f2,f3;
    printf("Introdu un numar pozitiv: ");
    scanf("%d",&N);
    f1=0;
    f2=1;
    printf("Primele numere din sirul lui Fibonacci sunt: ");
    printf("%d %d\n",f1,f2);
    for(i=3;i<=N;i++)
    {
        f3=f1+f2;
        f1=f2;
        f2=f3;
        printf("%d\n",f3);
    }
return 0;
}