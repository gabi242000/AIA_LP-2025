#include<iostream>
using namespace std;
int main()
{
    int v[10],v2[10],dim;
    bool sortat = false;
    cout << "Introduceti dimensiunea vectorului: ";
    cin >> dim;
    for(int i = 0; i < dim; i++)
    {
        cin >> v[i];
    }
    do
    {
        sortat = true;
        for(int i = 0 ; i < dim - 1 ; i++)
            if(v[i] > v[i+1])
            {
                int aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                sortat = false;
            }
        }
    while(!sortat);
    v2[0] = v[0];
    int j = 1;
    for(int i = 1; i < dim; i++)
    {
        if(v[i]!= v[i-1])
        {
            v2[j]=v[i];
            j++;
        }
        
    }
    for(int i = 0; i < j; i++)
    {
        cout << v2[i] << " ";
    }
    }