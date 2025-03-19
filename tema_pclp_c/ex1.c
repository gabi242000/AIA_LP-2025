#include <stdio.h>
int main(void) {
    int N;
    printf("Va rog introduceti un numar: ");
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0)
            printf("%d ", i);
    }
    return 0;
}
