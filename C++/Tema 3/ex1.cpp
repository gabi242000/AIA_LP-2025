#include<iostream>
using namespace std;
int main()
{
    int dim,sMax = 0,sAct = 0,iMax = 0,matr[10][10];
    cout << "Introduceti dim matricei: ";
    cin >> dim;
    for(int i = 0; i < dim; i++)
    {
        sAct = 0;
        for(int j = 0; j < dim; j++)
        {
            cin >> matr[i][j];
            sAct = sAct + matr[i][j];
        }
        if(sAct > sMax)
        {
            sMax = sAct;
            iMax = i;
        }
    }
    iMax = iMax+1;
    cout << "Randul " <<iMax<<" are suma maxima: "<< sMax;



}