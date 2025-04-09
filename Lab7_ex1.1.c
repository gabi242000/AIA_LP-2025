#include <stdio.h>

void sortareVector(int v[],int n){
    if(n<=1) return;

    int pivot=v[n-1];
    int i=-1;
    for(int j=0; j<n-1; j++){
        if(v[j]<=pivot){
            i++;
            if(v[i]>v[j]){
            int aux=v[i];
            v[i]=v[j];
            v[j]=aux;
            }
        }
    }
    if(v[i+1]>v[n-1]){
        int aux=v[i+1];
        v[i+1]=v[n-1];
        v[n-1]=aux;
    }


    sortareVector(v, i+1);
    sortareVector(v+i+2, n-i-2);

}

int cautareBinara(int v[], int n, int x){
    int start=0, end=n-1;
    while(start<=end){
        int mid= start+(end-start)/2;
        if(v[mid]==x) return mid;
        if(v[mid]<x) start=mid+1;
        else end=mid-1;
    }
    return -1;
}

int main(){
    int v[100],n;
    printf("Introdu dimensiunea vectorului: ");
    scanf("%d",&n);
    printf("Introdu elementele vectorului:\n");
    for(int i=0; i<n; i++){
        printf("Elementul %d: ",i+1);
        scanf("%d",&v[i]);
    }
    
    printf("Vectorul este: ");
    for(int i=0; i<n; i++) printf("%d ",v[i]);
    
    printf("\n");
    printf("Vectorul sortat este: ");
    sortareVector(v,n);
    for (int i = 0; i < n; i++) {
        printf("%d ",v[i]);
    }
    printf("\n");
    int x;
    printf("Introdu elementul de cautat: ");
    scanf("%d",&x);
    int cautare= cautareBinara(v,n,x);
    if (cautare != -1) {
        printf( "Elementul %d a fost găsit la indexul %d\n",x,cautare);
    } else {
        printf ("Elementul %d nu a fost găsit.",x);
    }
    return 0;

}