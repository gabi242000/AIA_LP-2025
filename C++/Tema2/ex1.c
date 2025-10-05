#include<stdio.h>

int main()
{
    int x;
    printf("Introduceti un numar: ");
    scanf("%d", &x);
    for(int i = 0; i < x; i++)
    {
        if(i%2==0)
            printf("%d ",i);
    }

}