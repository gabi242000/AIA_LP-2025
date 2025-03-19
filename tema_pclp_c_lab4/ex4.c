#include <stdio.h>
int main()
{
    int N;
    printf("Va rog introduceti un numar: ");
    scanf("%d", &N);
    int a[N+2][N+2];
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            scanf("%d", &a[i][j]);
    for(int i = 0; i <= N + 1; i++) {
        a[i][0] = 0;
        a[i][N+1] = 0;
    }
    for(int j = 0; j <= N + 1; j++) {
        a[0][j] = 0;
        a[N+1][j] = 0;
    }
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= N; j++)
            if(a[i][j] > a[i-1][j] && a[i][j] > a[i+1][j] && a[i][j] > a[i][j-1] && a[i][j] > a[i][j+1]) {
                printf("%d ", a[i][j]);
            }
    return 0;
}
