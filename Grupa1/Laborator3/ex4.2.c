#include <stdio.h>

int main()
{
    int N,nr1,nr2,temp;
    nr1=0;
    nr2=1;
    printf("Introdu un nr:");
    scanf("%d", &N);
    if(N>2){
        printf("0 1 ");
        for(int i=3;i<=N;i++){
            printf("%d ",nr1+nr2);
            temp=nr2;
            nr2=nr1+nr2;
            nr1=temp;
        }
    }
    else if(N==2)
        printf("0 1");
    else if(N==1)
        printf("0");
    else
        printf("program terminat");
    return 0;
}
