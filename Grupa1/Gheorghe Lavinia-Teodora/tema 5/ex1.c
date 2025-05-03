#include <stdio.h>

int partitie(int v[], int start, int end) {
    int pivot = v[end];
    int i = start - 1;

    for(int j = start; j <= end; j++) {
        if(v[j] < pivot) {
            i++;
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }
    i++;
    int aux = v[i];
    v[i] = v[end];
    v[end] = aux;

    return i;
}

// sortare Quick Sort
void sortareVector(int v[], int start, int end) {
    if(end <= start) return;
    int pivot = partitie(v, start, end);
    sortareVector(v, start, pivot - 1);
    sortareVector(v, pivot + 1, end);
}

// cautare binara
int cautareBinara(int v[], int n, int x) {
    int start = 0;
    int end = n - 1;

    while(start <= end) {
        int middle = start + (end - start) / 2;
        int val = v[middle];

        if(val < x) 
           start = middle + 1;
        else if(val > x)
                end = middle - 1;
        else return middle;
    }

    return -1;
}

int v[101], n, x;

int main() {
    printf("Introduceti dimensiunea unui vector: ");
    scanf("%d", &n);
    printf("Introduceti elementele vectorului: ");
    for(int i = 0; i < n; i++)
       scanf("%d", &v[i]);

    printf("Vectorul sortat arata astfel: ");
    sortareVector(v, 0, n - 1);
    for(int i = 0; i < n; i++)
      printf("%d ", v[i]);

    printf("\nIntroduceti elementul cautat: ");
    scanf("%d", &x);
    int pozitie_x = cautareBinara(v, n, x);
    printf("Elementul cautat se afla pe pozitia %d din vector. (prima pozitie este 0)", pozitie_x);

    return 0;

}