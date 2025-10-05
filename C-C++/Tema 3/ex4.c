#include <stdio.h>
int main()
{
    int n, i, j, a[100][100], l, c, aux, ct;
    printf("Introduceti dimensiunea matricei : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);

    for (i = 0; i <= n + 1; i++)
    {
        a[0][i] = -9999;
        a[i][0] = -999;
    }
    for (j = 0; j <= n + 1; j++)
    {
        a[j][n + 1] = -999;
        a[n + 1][j] = -999;
    }
    ct = 0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1])
            {
                ct++;
                aux = a[i][j];
                l = i;
                c = j;
            }
        if (ct != 0)
            break;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("Primul element de varf este : %d de pe linia %d coloana %d", aux, l, c);
    return 0;
}