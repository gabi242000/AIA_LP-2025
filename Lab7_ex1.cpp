#include <iostream>

using namespace std;

void sortareVector(int v[],int n){
    if(n<=1) return;

    int pivot=v[n-1];
    int i=-1;
    for(int j=0; j<n-1; j++){
        if(v[j]<=pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[n-1]);

    sortareVector(v, i+1);
    sortareVector(v+i+2, n-i-2);

}

int cautareBinara(int v[], int n, int x){
    int start=0, end=n-1;
    while(start<=end){
        int mid= start+(end-start)/2;
        if(v[mid]==x) return mid;
        if(v[mid]<x) start=mid+1;
        else end=mid-1;
    }
    return -1;
}

int main(){
    int v[100],n;
    cout<<"Introdu dimensiunea vectorului: ";
    cin>>n;
    cout<<"Introdu elementele vectorului:"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Elementul "<<i+1<<": ";
        cin>>v[i];
    }
    
    cout<<"Vectorul este: ";
    for(int i=0; i<n; i++) cout<<v[i]<<" ";
    
    cout<<endl;
    cout<<"Vectorul sortat este: ";
    sortareVector(v,n);
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    int x;
    cout<<"Introdu elementul de cautat: ";
    cin>>x;
    int cautare= cautareBinara(v,n,x);
    if (cautare != -1) {
        cout << "Elementul " << x << " a fost găsit la indexul " << cautare << endl;
    } else {
        cout << "Elementul " <<x << " nu a fost găsit." << endl;
    }
    return 0;

}