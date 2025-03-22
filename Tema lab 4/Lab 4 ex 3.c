#include <stdio.h>
int main()
{
    int n, i, j, a[100][100];
    printf("Introduceti dimensiunea matricei patratice: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            // Partea superioara a matricei adica deasupra diagonalei principale (sper ca e bine)
            if (i <= j)
                a[i][j] = i + j + 1;
            else
                a[i][j] = a[i][j];
        }
    printf("Matricea patratica este:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}