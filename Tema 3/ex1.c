#include <stdio.h>
int main()
{
    int n, i, j, smax, s, rand, a[100][100];
    printf("Introduceti dimensiunea matircei : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    smax = -999;
    for (i = 1; i <= n; i++)
    {
        s = 0;
        for (j = 1; j <= n; j++)
            s = s + a[i][j];

        if (s > smax)
        {
            smax = s;
            rand = i;
        }
    }
    printf("Suma maxima este : %d de pe randul %d", smax, rand);
    return 0;
}