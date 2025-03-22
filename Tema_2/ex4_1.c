#include <stdio.h>
int main()
{
    //ex4_1
    int N,i;
    printf("Introdu un numar: \n");
    scanf("%d",&N);
    printf("Numerele pare pana la %d sunt:",N);
    for(i=0;i<N;i++)
    {
        if(i%2==0)
        printf("%d ",i);
    }
    
    return 0;
}
