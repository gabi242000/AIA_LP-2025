#include <iostream>
using namespace std;
int main()
{
    int n,i,j,a[100][100], is_peak;
    cout<<"Introduceti dimensiunea matricei: ";
    cin>>n;
    cout<<"Introduceti elementele matricei:"<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>a[i][j];
    cout<<"Varfurile sunt:"<<endl;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            is_peak=1;
            //verific sus
            if(i>0 && a[i][j]<=a[i-1][j])
                is_peak=0;
            //verific jos
            if(i<n-1 && a[i][j]<=a[i+1][j])
                is_peak=0;
            //verific dreapta
            if(j<n-1 && a[i][j]<=a[i][j+1])
                is_peak=0;
            //verific stanga
            if(i>0 && a[i][j]<=a[i][j-1])
                is_peak=0;
            if(is_peak)
            cout<<a[i][j]<<" ";
        }
        return 0;
    }