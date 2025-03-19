#include <iostream>
using namespace std;
int main()
{
    int N,i,j,suma_maxima,rand_maxim,suma_rand;
    cout<<"Introdu dimensiunea matricei patratice: ";
    cin>>N;
    int a[N][N];
    cout<<"Introdu elementele matricei: ";
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        cin>>a[i][j];
    }
    suma_maxima=-1;
    rand_maxim=-1;
    for(i=0;i<N;i++)
    {
        suma_rand=0;
        for(j=0;j<N;j++)
        {
        suma_rand=suma_rand+a[i][j];
        }
        if(suma_rand>suma_maxima)
        {
            suma_maxima=suma_rand;
            rand_maxim=i;
        }
    }
    cout<<"Randul cu suma maxima este: "<<rand_maxim<<endl;
    cout<<"Suma maxima este: "<<suma_maxima<<endl;;

    return 0;
}