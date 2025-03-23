#include <stdio.h>
int main()
{
    int n, num1=0, num2=1, pas=2,aux;
    printf("Introdu un numar n: ");
    scanf("%d",&n);
    printf("%d %d ",num1,num2);
    while(pas<n){
        printf("%d ", num1+num2);
        aux=num2;
        num2=num1+num2;
        num1=aux;
        pas++;
    }
}
