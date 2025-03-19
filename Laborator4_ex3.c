# include <stdio.h>

int main(){
    int n,j,i;
    printf("Introdu numarul de linii si de coloane ale matricei: ");
    scanf("%d",&n);
    int m[n][n];
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)  if(j>=i){ m[i][j]=i+j+1;
                                  printf("Elementul %d%d este: %d\n",i+1,j+1,m[i][j]);}
                        else if(j<i) { m[i][j]=m[j][i];
                                       printf("Elementul %d%d este: %d\n",i+1,j+1,m[i][j]);}
  printf("\n"); 
  printf("Matricea este: \n"); 
  for(i=0;i<n;i++){
    for(j=0;j<n;j++) printf("%d  ",m[i][j]);
    printf("\n");
    }
    return 0;
}