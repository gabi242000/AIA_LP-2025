# include <stdio.h>

int main(){
    int n,j,i,suma,k,v[n], max,max_index=0;
    suma=0;
    printf("introdu numarul de linii si de coloane ale matricei: ");
    scanf("%d",&n);
    int m[n][n];
    for(i=0;i<n;i++)
      for(j=0;j<n;j++) {
       printf("Elementul %d%d: ",i+1,j+1);
       scanf("%d",&m[i][j]);
       }
    printf("\n"); 
    printf("Matricea este: \n"); 
    for(i=0;i<n;i++){
       for(j=0;j<n;j++) printf("%d  ",m[i][j]);
                        printf("\n");
    }

    for(i=0; i<n; i++){
        suma=0;
        for(j=0; j<n; j++) 
        suma=suma+m[i][j];
        printf("Suma elementelor de pe randul %d este: %d \n", i+1, suma);
        v[i]=suma;
    }
    printf("vectorul care are ca elemente sumele de pe fiecare rand: ");
    for(k=0;k<n;k++) printf("%d ",v[k]);
    printf("\n");
    max=v[0];
    for(k=0; k<n; k++) 
        if(v[k]>max) {
        max=v[k];
        max_index=k;
        }
    printf("Suma maxima= %d\n",max);
    printf("Rândul cu suma maximă este: ");
    for(j = 0; j < n; j++) printf("%d  ", m[max_index][j]);
    return 0;
}