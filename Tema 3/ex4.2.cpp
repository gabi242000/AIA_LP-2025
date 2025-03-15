#include<iostream>
using namespace std;
int main()
{
    int n, i, j, a[100][100], l, c, aux, ct;
    cout<<"Introduceti dimensiunea matricei : ";
    cin>>n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin>>a[i][j];

    for (i = 0; i <= n + 1; i++)
    {
        a[0][i] = -9999;
        a[i][0] = -999;
    }
    for (j = 0; j <= n + 1; j++)
    {
        a[j][n + 1] = -999;
        a[n + 1][j] = -999;
    }
    ct = 0;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            if (a[i][j] > a[i - 1][j] && a[i][j] > a[i + 1][j] && a[i][j] > a[i][j + 1] && a[i][j] > a[i][j - 1])
            {
                ct++;
                aux = a[i][j];
                l = i;
                c = j;
            }
        if (ct != 0)
            break;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            cout<<a[i][j]<<" ";
       cout<<endl;
    }
    cout<<"Primul element de varf este : "<<aux <<" de pe linia "<<l <<" coloana "<<c;
    return 0;
}