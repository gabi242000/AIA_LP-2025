#include<iostream>
using namespace std;
int main()
{
    int n, i, j, smax, s, rand, a[100][100];
    cout<<"Introduceti dimensiunea matircei : ";
    cin>>n;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            cin>>a[i][j];
    smax = -999;
    for (i = 1; i <= n; i++)
    {
        s = 0;
        for (j = 1; j <= n; j++)
            s = s + a[i][j];

        if (s > smax)
        {
            smax = s;
            rand = i;
        }
    }
    cout<<"Suma maxima este : "<<smax<<"  de pe randul "<< rand;
    return 0;
}