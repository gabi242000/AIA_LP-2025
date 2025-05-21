#include <stdio.h>
#include <stdlib.h>

int main() {
    int **a;
    int n;
    scanf("%d", &n);
    a = (int**) malloc(n * sizeof (int*));
    for (int i = 0; i < n; i++) {
        a[i] = (int*) malloc(n * sizeof (int));

    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i == j)
                a[i][j] = 1;
            else
                a[i][j] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);

    return 0;
}
