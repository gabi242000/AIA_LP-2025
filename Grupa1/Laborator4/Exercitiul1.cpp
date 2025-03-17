#include <iostream>

using namespace std;

int main(){
    int n, mat[20][20],s, max=-9999, indice_max;

    cout<<"n= ";
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>mat[i][j];

    for(int i=0;i<n;i++){
        s=0;
        for(int j=0;j<n;j++)
            s+=mat[i][j];
        
        if(s>max) {
            max=s; 
            indice_max=i;
        }
}

    cout<<"Randul: "<<indice_max<<endl;
    cout<<"Suma maxima: "<<max;

}