#include<iostream>
using namespace std;

int main()
{
    int dim,matr[10][10];
    cout << "Introduceti dim matricei: ";
    cin >> dim;
    for(int i = 0; i < dim; i++)
    {
        for(int j = 0; j < dim; j++)
        {
            if(j >= i)
            {                
                matr[i][j] = i + j + 1;
            }
            else
            {
                matr[i][j] = matr[j][i];
            }
            cout << matr[i][j] << " ";
        }
        cout << endl;
    }
   



}