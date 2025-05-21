#include <stdio.h>

// Funcția de interschimbare
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Funcție auxiliară pentru quicksort: partiționare
int partition(int v[], int low, int high) {
    int pivot = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (v[j] < pivot) {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]);
    return i + 1;
}

// Funcția de sortare quicksort
void quicksort(int v[], int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);
        quicksort(v, low, pi - 1);
        quicksort(v, pi + 1, high);
    }
}

// Wrapper pentru sortare
void sortareVector(int v[], int n) {
    quicksort(v, 0, n - 1);
}

// Funcția de căutare binară
int cautareBinara(int v[], int n, int x) {
    int st = 0, dr = n - 1;
    while (st <= dr) {
        int mij = (st + dr) / 2;
        if (v[mij] == x)
            return mij; // element găsit, returnează poziția
        else if (v[mij] < x)
            st = mij + 1;
        else
            dr = mij - 1;
    }
    return -1; // elementul nu a fost găsit
}

int main() {
    int n, x;

    printf("Introdu numarul de elemente ale vectorului: ");
    scanf("%d", &n);

    int v[n];
    printf("Introdu elementele vectorului:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    sortareVector(v, n);

    printf("Vectorul sortat: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    printf("Introdu elementul pe care doresti sa-l cauti: ");
    scanf("%d", &x);

    int pozitie = cautareBinara(v, n, x);
    if (pozitie != -1)
        printf("Elementul %d a fost gasit la pozitia %d.\n", x, pozitie);
    else
        printf("Elementul %d nu a fost gasit in vector.\n", x);

    return 0;
}
