#include <stdio.h>

int main(){
    int n;
    printf("Scrieti un numar: ");
    scanf ("%d",&n);
    int vector[n];

    for (int i=0;i<n;i++){
        scanf("%d",&vector[i]);
    }
    int aux;
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            if(vector[i]>vector[j]){
                aux=vector[i];
                vector[i]=vector[j];
                vector[j]=aux;
            }
            
        }
    }
    

    for (int i=0;i<n;i++){
    if(vector[i]==vector[i+1]){
        int a=i;
        while (a<n){
            vector[a]=vector[a+1];
            a++;
        }  
        n--;
        i--;
        }
    }



    for (int i=0;i<n;i++){
            printf("%d ", vector[i]);
    }
    return 0;
}
    
