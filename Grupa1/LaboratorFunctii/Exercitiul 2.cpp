#include <iostream>

using namespace std;

void getcofactor(int a[100][100],int cofactor[100][100],int row, int col,int n){
    int r=1, c=1;
    for(int i=1;i<=n;i++){
        if(i==row) continue;
        for(int j=1;j<=n;j++){
            if(j==col) continue;

            cofactor[r][c]=a[i][j];
            ++c;
        }
        ++r;    
        c=1;
    }

}

int determinant(int a[100][100],int n){
    if(n==1) return a[1][1];

    int det =0;
    int cofactor[100][100];


    for(int i=1;i<=n;i++){
        getcofactor(a,cofactor,1,i,n);

        int cofactorDet = determinant(cofactor, n-1);

        det+=((i%2==0?1 :-1)*a[1][i]*cofactorDet);


    }
    return det;



}

void inversabil(int det){
    if(det!=0) cout<<"Matricea este inversabila";
    else cout<<"Matricea nu este inversabila";
}

int main(){
    int a[100][100],n;

    cin>>n;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>a[i][j];


    int det = determinant(a,n);

    cout<<"Determinantul matricei este: "<<det<<endl;

    inversabil(det);

    
}