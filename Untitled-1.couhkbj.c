#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i, count = 0;
    double suma = 0, media;

    printf("Numar elemente: ");
    scanf("%d", &n);

    int *v = malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        suma += v[i];
    }

    media = suma / n;

    
    for (i = 0; i < n; i++)
        if (v[i] >= media)
            count++;

    int *nou = malloc(count * sizeof(int));
    int j = 0;
    for (i = 0; i < n; i++)
        if (v[i] >= media)
            nou[j++] = v[i];

    printf("Media: %.2f\n", media);
    printf("Elemente >= media:\n");
    for (i = 0; i < count; i++)
        printf("%d ", nou[i]);

    free(v);
    free(nou);
    return 0;
}



