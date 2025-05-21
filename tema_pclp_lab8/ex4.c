#include <stdio.h>
#include <stdlib.h>
int main() {
    int n,s = 0, cnt = 0;
    int *vector, *c;
    printf("Va rog introduceti numarul de elemente: ");
    scanf("%d", &n);
    vector = (int *) malloc(n * sizeof(int));
    if(vector == NULL) {
        printf("Eroare de alocare a memoriei");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &vector[i]);
        s += vector[i];
    }
    c = (int *) malloc(n * sizeof(int));
    if(c == NULL) {
        printf("Eroare de alocare a memoriei");
        return 1;
    }
    s = s / n;
    for (int i = 0; i < n; i++)
        if(vector[i] >= s) {
            c[cnt] = vector[i];
            cnt++;
        }
    for (int i = 0; i < cnt; i++)
        printf("%d ", c[i]);

    free(c);
    free(vector);
    return 0;
}
