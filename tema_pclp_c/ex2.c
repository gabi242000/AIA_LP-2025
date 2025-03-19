#include <stdio.h>
int main()
{
    int N,f0 = 0,fi = 0,f1 = 1;
    printf("Va rog introduceti un numar:  ");
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        fi = f1 + f0;
        printf("%d ", fi);
        f0 = f1;
        f1 = fi;
    }


    return 0;
}