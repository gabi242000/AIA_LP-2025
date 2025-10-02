#include <iostream>
using namespace std;

int main(){

    int n, v[20];
//Citire
    cout<<"n=";
    cin>>n;
    cout<<"Adauga un vector: "<<endl;
    
    for(int i=0;i<n;i++)
        cin>>v[i];
//Sortare
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++)
           if(v[i]>v[j]){
            int aux = v[i];
            v[i]=v[j];
            v[j]=aux;
           }
    }
//Elimnare duplicate
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            if(v[i]==v[j]){
                for(int k=j;k<n;k++)
                    v[k]=v[k+1];
                n--;
            }
    }


//Afisare
    cout<<"Vectorul rezultat este: "<<endl;
    for(int i=0;i<n;i++) cout<<v[i]<<" ";

}