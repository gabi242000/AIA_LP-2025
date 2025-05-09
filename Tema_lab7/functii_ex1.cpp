#include <iostream>
using namespace std;

void sortareVector(int v[], int n) {
    int st = 0, dr = n - 1;
    
    while (st < dr) {
        int pivot = v[dr];
        int i = st - 1;
        
        for (int j = st; j < dr; j++) {
            if (v[j] < pivot) {
                i++;
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
        int temp = v[i + 1];
        v[i + 1] = v[dr];
        v[dr] = temp;
        int pivot_pos = i + 1;
        
        if (pivot_pos - st > dr - pivot_pos) {
            if (pivot_pos + 1 < dr) {
                int temp_st = pivot_pos + 1;
                int temp_dr = dr;
                dr= pivot_pos - 1;
                st = st;
                
                pivot_pos = temp_st;
                dr = temp_dr;
            } else {
                dr = pivot_pos - 1;
            }
        } else {
            if (st < pivot_pos - 1) {
                int temp_st = st;
                int temp_dr = pivot_pos - 1;
                st = pivot_pos + 1;
                dr = dr;
            
                st = temp_st;
                dr = temp_dr;
            } else {
                st = pivot_pos + 1;
            }
        }
    }
}

int cautareBinara(int v[], int n, int x) {
    int st = 0, dr = n - 1;
    
    while (st <= dr) {
        int mij = st + (dr - st) / 2;
        
        if (v[mij] == x) {
            return mij;
        }
        if (v[mij] < x) {
            st = mij + 1;
        } else {
            dr = mij - 1;
        }
    }
    
    return -1;
}

int main() {
    int n, x;
    
    cout << "Introdu numarul de elemente: ";
    cin >> n;
    
    int v[n];
    cout << "Introdu elementele:\n";
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    
    sortareVector(v, n);
    
    cout << "Vector sortat: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    cout << "Element de cautat: ";
    cin >> x;
    
    int poz = cautareBinara(v, n, x);
    if (poz != -1) {
        cout << "Elementul cautat se afla la pozitia: " << poz << endl;
    } else {
        cout << "Elementul nu a fost gasit" << endl;
    }
    
    return 0;
}