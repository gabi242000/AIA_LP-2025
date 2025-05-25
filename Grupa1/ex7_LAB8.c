#include <stdio.h>
#include <stdlib.h>

int main() {
    int **mat, n, i, j;

    printf("Introduceti dimensiunea matricei identitate: ");
    scanf("%d", &n);

    mat=(int **)malloc(n * sizeof(int *));
    if(mat == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }

    for(i= 0;i< n;i++) {
        mat[i]=(int *)malloc(n * sizeof(int));
        if(mat[i]==NULL) {
            printf("Eroare la alocarea memoriei pe linia %d\n", i);
            // Elibereaza liniile alocate pana acum
            for(j= 0;j< i;j++)
                free(mat[j]);
            free(mat);
            return 1;
        }
    }

    // Completam matricea
    for(i= 0;i< n;i++) {
        for (j= 0;j< n;j++){
            if(i==j)
            mat[i][j]= 1;
            else
            mat[i][j]= 0;
        }
    }


    printf("Matricea identitate este:\n");
    for(i= 0;i< n;i++) {
        for(j= 0;j< n;j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (i= 0;i< n;i++)
        free(mat[i]);
    free(mat);

    return 0;
}
