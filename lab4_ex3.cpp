#include <iostream>
using namespace std;
int main()
{
    int N,i,j;
    cout<<"Introdu dimensiunea matricei patratice: ";
    cin>>N;
    int a[N][N];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        if(i<=j)
             a[i][j]=i+j+1;
        else if(i>j)
            a[i][j]=a[j][i];
    }
    cout<<"Matricea generata este: "<<endl;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
        cout<<a[i][j]<<" ";
        
        }cout<<endl;
    }
    return 0;
}