#include <stdio.h>
int main()
{
    int n, i, j, a[100][100];
    printf("Introduceti dimensiunea matricei : ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (j >= i)
                a[i][j] = i + j + 1;
            else
                a[i][j] = a[j][i];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}