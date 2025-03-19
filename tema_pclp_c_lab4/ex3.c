#include <stdio.h>
int main()
{
    int N;
    printf("Va rog introduceti un numar: ");
    scanf("%d", &N);
    int a[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (j >= i)
                a[i][j] = i + j + 1;
            else
                a[i][j] = a[j][i];
        }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }

    return 0;
}
