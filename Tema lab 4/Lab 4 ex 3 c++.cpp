#include <iostream>
using namespace std;
int main()
{
    int n, i, j, a[100][100];
    cout << "Introduceti dimensiunea matricei patratice: ";
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (i <= j)
                a[i][j] = i + j + 1;
            else
                a[i][j] = a[i][j];
        }
    cout << "Matricea patratica este:" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}