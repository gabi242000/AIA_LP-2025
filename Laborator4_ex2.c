# include <stdio.h>
 
int main(){
    int n ,i ,aux ,j, duplicat=0;
    printf("Introduceti dimensiunea vectorului: ");
    scanf("%d",&n);
    int v[n];

    for(i=0;i<n;i++){
        printf("Elementul %d: ",i);
        scanf("%d",&v[i]);
    }

    printf("Vectorul este: ");
    for(i=0;i<n;i++) printf("%d ",v[i]);
    printf("\n");

    for(i=0;i<n-1;i++) 
    for(j=i+1;j<n;j++)
      if(v[i]>v[j]){
        aux=v[i];
        v[i]=v[j];
        v[j]=aux;
       }
    printf("Vectorul sortat este: ");
    for(i=0;i<n;i++) printf("%d ",v[i]);
    printf("\n");
    
    for(i=0;i<n;i++) if(v[i]==v[i+1]) duplicat=1;
    switch (duplicat){
        case 1: { printf("Vectorul fara elemente duplicate este: ");
                  for(i=0;i<n;i++) 
                  if(v[i]!=v[i+1]) printf("%d ", v[i]);
                  break;}
        case 0: {printf("Nu exista valori duplicate in vector");
                 break;}
    }
    

    return 0;
}