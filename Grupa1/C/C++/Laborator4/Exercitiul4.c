#include <stdio.h>

int main(){
    int n,mat[20][20],i,j,varf;

    printf("n= ");
    scanf("%d ",&n);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&mat[i][j]);

    //Bordare
    for(int i=-1;i<=n;i++)
        mat[i][-1]=mat[i][n]=-1;

    for(int j=0;j<n;j++)
        mat[-1][j]=mat[n][j]=-1;

    

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            printf("%d ",mat[i][j]);
        printf("\n");
    }

    

    //Gasire element varf
    int gasit=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(mat[i][j]>mat[i-1][j] && 
               mat[i][j]>mat[i+1][j] && 
               mat[i][j]>mat[i][j-1] && 
               mat[i][j]>mat[i][j+1]) {gasit =1; varf = mat[i][j]; break;}

    
    if(gasit) printf("Un element varf din matrice este: %d",varf);
    
            

    
}