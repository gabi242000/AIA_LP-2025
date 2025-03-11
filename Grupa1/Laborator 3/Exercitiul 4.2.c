#include <stdio.h>

int main(){
    int n,i,a=0,b=0,c;
    printf("Introdu un numar:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        if(a==0 && b==0) printf("%d ",++a);
        else if(a==1 && b==0) printf("%d ",++b);
        else {
            c=a+b;
            printf("%d ",c);
            a=b, b=c;
        }

        

}