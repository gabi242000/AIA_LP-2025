# include <stdio.h>

int main(){
    int n,j,i;
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
    printf("Elementele de varf sunt:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int is_peak = 1; 

            if (i > 0 && m[i][j] <= m[i - 1][j]) is_peak = 0; 
            if (i < n - 1 && m[i][j] <= m[i + 1][j]) is_peak = 0;
            if (j > 0 && m[i][j] <= m[i][j - 1]) is_peak = 0;
            if (j < n - 1 && m[i][j] <= m[i][j + 1]) is_peak = 0;

            if (is_peak==1) {
                printf("m[%d][%d] = %d\n", i, j, m[i][j]);
            }
        }
    }
    return 0;
}