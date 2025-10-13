#include <stdio.h>

int m[100][100];

int main(){
    int n;
    printf("Introdu dimensiunea matricei (nxn):");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i <= j) m[i][j] = i + j + 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i > j) m[i][j] = m[j][i];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}