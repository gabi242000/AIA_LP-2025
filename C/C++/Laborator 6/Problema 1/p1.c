#include <stdio.h>

int sortareVector (int v[100], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (v[i] > v[j]){
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    return v[100];
}

int cautareBinara(int v[100], int n, int x){
    int st = 0, dr = n - 1;
    while (st <= dr){
        int mij = (st + dr) / 2;
        if (v[mij] == x){
            return mij;
        } else if (v[mij] < x){
            st = mij + 1;
        } else {
            dr = mij - 1;
        }
    }
    return -1;
}

int main(){
    int v[100], n, x;
    printf("Introduceti numarul de elemente al vectorului: ");
    scanf("%d", &n);
    printf("Introduceti elementele vectorului: ");
    for (int i = 0; i < n; i++){
        printf("v[%d] = ", i);
        scanf("%d", &v[i]);
    }
    printf("Introduceti elementul pe care doriti sa-l cautati: ");
    scanf("%d", &x);
    printf("Vectorul sortat este: ");
    sortareVector(v, n);
    for (int i = 0; i < n; i++){
        printf("%d ", v[i]);
    }
    if (cautareBinara(v, n, x) == -1){
        printf("\nElementul cautat %d nu se afla in vectorul sortat.\n", x);
        return 0;
    }
    else printf("\nElementul cautat %d nu se aflacin vectorul sortat.\n", x);
    return 0;
}