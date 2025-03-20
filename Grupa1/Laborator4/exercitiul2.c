#include <stdio.h>

int main(){
    
    int i,j,N,temp;

    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d",&N);
    int v[N];
    printf("Introduceti elementele vectorului: ");
    for(i=0;i<N;i++){
        scanf("%d",&v[i]);
    }
    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(v[j]>v[j+1]){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
    printf("Vectorul rezultat este: ");
    for(i=0;i<N;i++){
        if(i==0 || v[i]!=v[i-1]){
            printf("%d ",v[i]);
        }
    }
    printf("\n");
    return 0;
}
