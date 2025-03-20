#include <iostream>
using namespace std;

int main()

{
    int i,j,N;
    int s,smx=-1,rsmx=-1;

    cout<<"Introdu dimensiune matricei: ";
    cin>>N;
    int a[N][N];
    for (i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin>>a[i][j];
        }
    }
    for(i=0;i<N;i++)
    {
        s=0;
        for(j=0;j<N;j++){
            s+=a[i][j];
        }
            if(s>smx){
                smx=s;
                rsmx=i;
            }
    }
    cout<<"Linia cu suma maxima este: ";
    for(j=0;j<N;j++)
    {
        cout<<a[rsmx][j]<<" ";
    }
    cout<<"("<<rsmx+1<<")"<<endl;
    cout<<"Suma maxima de pe o linie din matrice este:"<<smx<<endl;
}
