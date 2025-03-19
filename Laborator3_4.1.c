# include <stdio.h>

int main(){
    int N,i;
    printf("Introduceti un numar: ");
    scanf("%d",&N);
    for(i=1;i<=N;i++) 
    if(i%2==0) printf("%d ",i);
    return 0;
}