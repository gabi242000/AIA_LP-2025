#include<stdio.h>
#include<stdlib.h>

int main(){
    int *v, *vinvers;
    int n,i,j;
    printf("Introdu dimensiunea vectorului: ");
    scanf("%d",&n);
    //v=(int*)malloc(n * sizeof(int));
    v=(int*)malloc(n * sizeof(int));
    if(v==NULL){
        printf("Eroare la alocarea memoriei");
        return 1;
    }
    printf("Introdu elementele vectorului:\n");
    for(i=0; i<n; i++) {
        printf("v[%d]= ",i);
        scanf("%d",&v[i]);
        }
    vinvers=(int*)malloc(n * sizeof(int));
    if(vinvers==NULL){
        printf("Eroare la alocarea memoriei pentru vectorul inversat");
        return 1;
    }
    for(i=0;i<n;i++) vinvers[i]=v[n-1-i];
    printf("Vectorul initial: ");
    for(i=0; i<n; i++) printf("%d ",v[i]);
    printf("\n");
    printf("Vectorul inversat: ");
    for(i=0; i<n; i++) printf("%d ",vinvers[i]);
    return 0;

}