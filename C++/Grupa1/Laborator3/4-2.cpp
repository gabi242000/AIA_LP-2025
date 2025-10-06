#include <stdio.h>



int main(){
    int n;
    printf("Scrieti un numar: ");
    scanf("%d",&n);
    printf("0 ");
    if (n==1){
        printf("1");
    }
    else{
        printf("1 ");
        int a=0;
        int b=1;
        int c;
        for (int i=0;i<=n-2;i++){
            c=a+b;
            if(i%2==0){
                a=c;
            } else b=c;
            printf("%d",c);
            printf(" ");
        }
    }
    
    return 0;
}