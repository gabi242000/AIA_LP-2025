#include<iostream>
using namespace std;
int main()
{
    int n, i, j, aux, v[100];
    cout<<"Introduceti dimensiunea vectorului : ";
    cin>>n;
    for (i = 0; i < n; i++)
        cin>>v[i];
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    }
    for( i = 0; i < n - 1; i++)
    {
        if(v[i] == v[i+1])
        {
            for( j = i+1; j < n;j++)
                v[j] = v[j+1];
            n--;
            i--; 
        }
    }

    for (i = 0; i < n; i++)
        cout<<v[i]<<" ";
    return 0;
}