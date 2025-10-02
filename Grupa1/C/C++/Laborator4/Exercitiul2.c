#include <stdio.h>

int main(){

    int n, v[20];
//Citire
    printf("n=");
    scanf("%d",&n);
    printf("Adauga un vector: \n");
    
    for(int i=0;i<n;i++)
        scanf("%d", & v[i]);
//Sortare
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
           if(v[i]>v[j]){
            int aux = v[i];
            v[i]=v[j];
            v[j]=aux;
           }
    }
//Elimnare duplicate
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            if(v[i]==v[j]){
                for(int k=j;k<n;k++)
                    v[k]=v[k+1];
                n--;
            }
    }


//Afisare
    printf("Vectorul rezultat este: ");
    for(int i=0;i<n;i++) printf("%d ", v[i]);

}