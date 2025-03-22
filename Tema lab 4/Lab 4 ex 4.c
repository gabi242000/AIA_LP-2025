#include <stdio.h>
int main()
{
    int n, i, j, a[100][100], is_peak;
    printf("Introduceti dimensiunea matricei patratice: ");
    scanf("%d", &n);
    printf("Introduceti elementele matricei patratice:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("Elemente varf:\n");
    //Banuiesc ca pot fi mai multe ca nu e specificat doar unul in cerinta
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            is_peak = 1; 

            // Verific vecinul de sus
            if (i > 0 && a[i][j] <= a[i - 1][j])
            {
                is_peak = 0; 
            }
            // Verific vecinul de jos
            if (i < n - 1 && a[i][j] <= a[i + 1][j])
            {
                is_peak = 0; 
            }
            // Verific vecinul din stanga
            if (j > 0 && a[i][j] <= a[i][j - 1])
            {
                is_peak = 0; 
            }
            // Verificam vecinul din dreapta
            if (j < n - 1 && a[i][j] <= a[i][j + 1])
            {
                is_peak = 0; 
            }
            if (is_peak)
            {
                printf("%d ", a[i][j]);
            }
        }
    }
    //Toata lumea foloseste functie isPeak ce cancer :(
    printf("\n");
    return 0;
}