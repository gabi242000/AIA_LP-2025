#include <stdio.h>

int main(){
    int n,a=0,b=0,c,i=1;

    printf("Introduceti un numar:");
    scanf("%d",&n);

    for(i=1;i<=n;i++)
        if(a==0 && b==0) a=1, printf("%d ",a);
        else if(a==1 && b==0) b=1,printf("%d ",b);
        else c=a+b, a=b, b=c, printf("%d ",c);
}