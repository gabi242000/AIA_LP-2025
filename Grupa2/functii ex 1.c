#include <stdio.h>

void sortareVector(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j] < v[minIdx])
                minIdx = j;
        }

        if (minIdx != i) {
            int temp = v[i];
            v[i] = v[minIdx];
            v[minIdx] = temp;
        }
    }
}
int cautareBinara(int v[], int n, int x) {
    int st = 0, dr = n - 1;

    while (st <= dr) {
        int mij = (st + dr) / 2;

        if (v[mij] == x)
            return mij;
        else if (v[mij] < x)
            st = mij + 1;
        else
            dr = mij - 1;
    }

    return -1;
}

int main() {
    int v[100], n, x;

    printf("Introdu numarul de elemente: ");
    scanf("%d", &n);

    printf("Introdu elementele vectorului:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    sortareVector(v, n);

    printf("Vector sortat: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Introdu elementul de cautat: ");
    scanf("%d", &x);

    int poz = cautareBinara(v, n, x);

    if (poz != -1)
        printf("Elementul %d a fost gasit la pozitia %d (indexare de la 0).\n", x, poz);
    else
        printf("Elementul %d NU a fost gasit in vector.\n", x);

    return 0;
}
