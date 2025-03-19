#include <stdio.h>
int main(void)
{
    int N;
    printf("Va rog introduceti un numar: ");
    scanf("%d", &N);
    int a[N][N];
    int s = 0 , smax = -9999999;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
            s = s + a[i][j];
        }
        if(s > smax)
            smax = s;
        s = 0;
    }
    printf("%d", smax);


    return 0;
}
