#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vector;
    int *vectorpar;
    int n,i,p=0;
    printf("Introdu nr de elemente: ");
    scanf("%d",&n);
    vector=(int*)malloc(n * sizeof(int));
    if(vector == NULL){
        printf("Eroare la alocarea memoriei vectorului\n");
        return 1;
    }
    printf("Introduceti elementele vectorului: \n");
    for(int i=0; i<n; i++){
        printf("Elementul[%d]= ",i);
        scanf("%d",&vector[i]);
     }
    vectorpar=(int*)malloc(n * sizeof(int));
    if(vectorpar == NULL){
        printf("Eroare la alocarea memoriei vectorului par\n");
        return 1;
    }
    for(i=0; i<n;i++) if(vector[i]%2==0) {
        vectorpar[p]=vector[i];
        p++;
    }
    printf("Valorile pare sunt: ");
    for(i=0;i<p; i++) printf("%d ",vectorpar[i]);
    free(vector);
    free(vectorpar);
     return 0;
    }