#include <stdio.h>
#include <stdlib.h>
int main() {
    int *v,*v2;
    int n;
    printf("Va rog introduceti numarul de elemente: ");
    scanf("%d", &n);
    v = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    v2 = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        v2[i] = v[n-i-1];
    for(int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d ", v2[i]);
    free(v);
    free(v2);
    return 0;
}