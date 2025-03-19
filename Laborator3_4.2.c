#include <stdio.h>

int main(){
    int n,i,a,b,c;
    printf("Introduceti un numar: ");
    scanf("%d",&n);
    a=0;
    b=1;
    printf("Sirul fibonacci este: %d %d ",a,b);
    for(i=3;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
        printf("%d ",c);
    }

    return 0;
}