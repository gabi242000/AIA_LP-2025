#include <stdio.h>



int main(){
    int n;
    printf("Scrieti un numar: ");
    scanf("%d",&n);
    for (int i=0;i<=n;i+=2){
        printf("%d",i);
        printf(" ");
    }
    return 0;
}