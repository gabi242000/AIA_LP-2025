#include <iostream>
using namespace std;
int main(){
    
    int i,j,N,temp;

    cout<<"Introduceti dimensiunea vectorului: ";
    cin>>N;
    int v[N];
    cout<<"Introduceti elementele vectorului: ";
    for(i=0;i<N;i++){
        cin>>v[i];
    }
    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(v[j]>v[j+1]){
                temp=v[j];
                v[j]=v[j+1];
                v[j+1]=temp;
            }
        }
    }
    cout<<"Vectorul rezultat este: ";
    for(i=0;i<N;i++){
        if(i==0 || v[i]!=v[i-1]){
            cout<<v[i]<<" ";
        }
    }
    cout<<"\n";
    return 0;
}
