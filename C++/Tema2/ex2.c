#include<stdio.h>

int main()
{
    int n1,n2,n3,x;
    n1 = 1;
    n2 = 1;
    printf("Introduceti un numar: ");
    scanf("%d", &x);
    if(x >= 1)
        printf("%d ",n1);
    if(x >= 2)
        printf("%d ",n2);
    for(int i = 0; i < x - 2; i++)
    {
        n3 = n2 + n1;
        n1 = n2;
        n2 = n3;
        printf("%d ",n3);
        
    }
}