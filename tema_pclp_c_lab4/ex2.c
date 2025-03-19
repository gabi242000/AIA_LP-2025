#include <stdio.h>
int main()
{
    int N;
    printf("Va rog introduceti un numar: ");
    scanf("%d", &N);
    int v[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &v[i]);
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (v[i] > v[j]) {
                v[i] = v[i] ^ v[j];
                v[j] = v[i] ^ v[j];
                v[i] = v[j] ^ v[i];
            }
    for (int i = 0; i < N; i++)
        printf("%d ", v[i]);
}
