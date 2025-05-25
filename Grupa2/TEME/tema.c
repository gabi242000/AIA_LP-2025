#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *f;
    int *v, i, n;

    f = fopen("vector.txt", "w");
    if (f == NULL)
    {
        printf("Eroare la crearea fisierului.\n");
        return 1;
    }
    n=5;
    for(i=0; i<n; i++)
    {
        fprintf(f, "%d ", i+2);
    }
    fclose(f);

    f = fopen("vector.txt", "r");
    if (f == NULL)
    {
        printf("Eroare la dechiderea fiserului.\n");
        return 1;
    }

    fprintf(f, "Introdu dimensiunea.\n");
    fscanf(f, "%d", &n);

    v = (int*)malloc(n * sizeof(int));
    if (v == NULL)
    {
        printf("Eroare la alocarea memoriei.\n");
        return 1;
    }

    for(i=0; i<n; i++)
    {
        fscanf(f, "%d", &v[i]);
    }

    fclose(f);
    printf("Vectorul citit din fisier este:\n");
    for(i=0; i<n; i++)
    {
        printf("%d", v[i]);
    }

    free(v);
    return 0;

}