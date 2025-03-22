#include <iostream>
using namespace std;
int main()
{
    int n, i, j, v[100][100], summax = 0, linmax = 0, suma;
    cout << "Introduceti dimensiunea matricei: ";
    cin >> n;
    cout << "Introduceti elementele matricei: ";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> v[i][j];
    for (i = 0; i < n; i++)
    {
        suma = 0;
        for (j = 0; j < n; j++)
            suma += v[i][j];
        if (summax < suma)
        {
            summax = suma;
            linmax = i;
        }
    }
    cout << "Linia cu suma maxima este a " << linmax + 1 << "-a cu suma egala cu " << summax << endl;
    for (j = 0; j < n; j++)
        cout << v[linmax][j] << " ";
    return 0;
}