#include <iostream>
using namespace std;

int main(){
    int n,mat[20][20];

    cout<<"n=";
    cin>>n;


    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i<=j) mat[i][j]= i+j+1;
            else if(i>j) mat[i][j]= mat[j][i];

    cout<<"Matricea rezultata este: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<mat[i][j]<<" ";

    cout<<endl;
    }
}