#include <iostream>
using namespace std;
int main()
{
    int N,i,aux,dimensiune_noua;
    bool sortat;
    cout<<"Introdu dimensiunea vectorului: ";
    cin>>N;
    int v[N];
    cout<<"Introdu elementele vectorului: ";
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        cin>>v[i];
    }
    do
    {
        sortat=true;
        for(i=0;i<N-1;i++)
        {
            if(v[i]>v[i+1])
            {
                aux=v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
                sortat=false;
            }
        }
    }
    while(!sortat);

    dimensiune_noua = 0; 
    for (i=0;i<N;i++)
     {
        if (i==0 || v[i]!=v[i-1]) 
        {
            v[dimensiune_noua]=v[i];
            dimensiune_noua++; 
        }
    }
    cout<<"Elementele vectorului fara duplicate sunt: ";
    for (i=0;i<dimensiune_noua;i++) 
    {
        cout<<v[i];
    }
    cout<<endl;
    
    return 0;
}