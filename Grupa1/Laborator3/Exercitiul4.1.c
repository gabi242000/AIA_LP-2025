#include <stdio.h>

int main(){
    int n,i;
    printf("Introduceti un numar:\n");
    scanf("%d",&n);

    for(i=2;i<=n;i+=2)
        printf("%d ",i);
}