#include <stdio.h>
int main()
#ex_4.1
{
    int N,i;
    printf("Introdu un numar: ");
    scanf("%d",&N);
    printf("Numerele pare pana la %d sunt:\n",N);
    for(i=0;i<=N;i++)
    {
        if(i%2==0) printf("%d\n",i);
    }

#ex_4.2
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
#ex_4.3

    int N,i,j;
    printf("Introdu un numar: ");
    scanf("%d",&N);
    for (i=0; i<N;i++) 
    {
        for (j=0;j<N-i;j++) 
        {
            printf(" ");
        }
        for (j=0; j<2*i-1;j++)
    {
            printf("*");
    }
    printf("\n");
    }
    
}