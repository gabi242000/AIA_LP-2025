#include <iostream>
using namespace std;

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

void sortareVector(int v[], int start, int end) {
    if(end <= start) return;
    int pivot = partitie(v, start, end);
    sortareVector(v, start, pivot - 1);
    sortareVector(v, pivot + 1, end);
}

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
    cout << "Introduceti dimensiunea unui vector: ";
    cin >> n;
    cout << "Introduceti elementele vectorului: ";
    for(int i = 0; i < n; i++)
       cin >> v[i];

    cout << "Vectorul sortat arata astfel: ";
    sortareVector(v, 0, n - 1);
    for(int i = 0; i < n; i++)
      cout << v[i] << " ";

    cout << "\n" << "Introduceti elementul cautat: ";
    cin >> x;
    int pozitie_x = cautareBinara(v, n, x);
    cout << "Elementul cautat se afla pe pozitia" << pozitie_x << "din vector. (prima pozitie este 0)";

    return 0;

}