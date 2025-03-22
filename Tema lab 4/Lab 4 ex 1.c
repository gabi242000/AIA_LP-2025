#include <stdio.h>
int main()
{
    int n, i, j, suma, maxim = 0, liniamax = 0, v[100][100];
    printf("Introduceti dimensiunea matricei: ");
    scanf("%d", &n);
    printf("Introduceti elementele matricei: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &v[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        suma = 0;
        for (j = 0; j < n; j++)
        {
            suma += v[i][j];
        }
        if (maxim < suma)
        {
            maxim = suma;
            liniamax = i;
        }
    }
    printf("Linia cu suma maxima este a %d-a cu suma egala cu %d \n", liniamax + 1, maxim);
    for (j = 0; j < n; j++)
        printf("%d ", v[liniamax][j]);
}