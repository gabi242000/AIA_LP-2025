#include <stdio.h>
void schimb(int &a, int &b);
int partitie(int v[], int mi, int ma);
void quicksort(int v[], int mi, int ma);
void sortare(int v[], int n);
int cautare(int v[], int n, int x);

int main()
{
    int n,i;
    int v[101];
    printf("introduceti dimensiunea vectorului:");
    scanf("%d", &n);
    printf("introduceti elementele vectorului:\n");
    for(i=0;i<n;i++)
        scanf("%d", &v[i]);
    printf("vectorul sortat:\n");
    sortare(v,n);
    for(i=0;i<n;i++)
        printf("%d ", v[i]);
    printf("\nintroduceti un nr:");
    int nr;
    scanf("%d", &nr);
    int rez=cautare(v,n,nr);
    if(rez>=0)
        printf("numarul se afla pe pozitia: %d", nr);
    else
        printf("numarul nu se afla in vector");
    return 0;
}

void schimb(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}
int partitie(int v[], int mi, int ma) {
    int piv=v[ma];
    int i = mi-1;
    for (int j =mi; j < ma; j++) {
        if (v[j] < piv) {
            i++;
            schimb(v[i], v[j]);
        }
    }
    schimb(v[i + 1], v[ma]);
    return i + 1;
}
void quicksort(int v[], int mi, int ma) {
    if (mi<ma) {
        int piv = partitie(v, mi, ma);
        quicksort(v, mi, piv - 1);
        quicksort(v, piv + 1, ma);
    }
}
void sortare(int v[], int n) {
    quicksort(v, 0, n - 1);
}
int cautare(int v[], int n, int x) {
    int st = 0, dr = n - 1;
    while (st <= dr) {
        int mij = st + (dr - st) / 2;
        if (v[mij] == x)
            return mij;
        else if (v[mij] < x)
            st = mij + 1;
        else
            dr = mij - 1;
    }
    return -1;
}
