#include <iostream>
using namespace std;
int main ()
{
    int N,i,j;
    bool gasit=0;
    cout<<"Introdu dimensiunea matricei patratice: ";
    cin>>N;
    int a[N][N];
    cout<<"Introdu elementele matricei patratice: ";
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        cin>>a[i][j];
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if( (a[i][j]>a[i][j-1]) && (a[i][j]>a[i][j+1]) && (a[i][j]>a[i-1][j]) &&(a[i][j]>a[i+1][j]))
            {
                cout<<"Elementul varf este:"<<a[i][j]<<endl;
                gasit=1;
            }
        }
    }
    if(gasit==0)  cout<<"Matricea nu contine niciun element varf.";
    return 0;
}