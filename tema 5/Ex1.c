#include <stdio.h>

void interschimbare(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int sortare(int v[], int st, int dr)
{
    int pivot = v[dr];
    int i = st - 1;

    for (int j = st; j < dr; j++)
    {
        if (v[j] <= pivot)
        {
            i++;
            interschimbare(&v[i], &v[j]);
        }
    }
    interschimbare(&v[i + 1], &v[dr]);
    return i + 1;
}

void sortareVector(int v[], int st, int dr)
{
    if (st < dr)
    {
        int poz = sortare(v, st, dr);
        sortareVector(v, st, poz - 1);
        sortareVector(v, poz + 1, dr);
    }
}

int cautareBinara(int v[], int dim, int nr)
{
    int st = 0, dr = dim - 1;

    while (st <= dr)
    {
        int m = (st + dr) / 2;

        if (v[m] == nr)
            return m;
        else if (v[m] < nr)
            st = m + 1;
        else
            dr = m - 1;
    }

    return -1;
}

int main()
{
    int n, v[1000], nr, poz;
    printf("Introdu dimensiunea vectorului: ");
    scanf("%d", &n);
    
    printf("Introduceti numerele: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    sortareVector(v, 0, n - 1);

    printf("Vectorul sortat este: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Introdu numarul de cautat: ");
    scanf("%d", &nr);

    poz = cautareBinara(v, n, nr);

    if (poz != -1)
        printf("Numarul se afla pe pozitia: %d\n", poz + 1);
    else
        printf("Numarul nu se regaseste in vector\n");

    return 0;
}
