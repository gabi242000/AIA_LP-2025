#include <iostream>
using namespace std;
int main()
{
    int n, i, j, aux, v[100];
    cout << "Introduceti dimensiunea vectorului: ";
    cin >> n;
    cout << "Introduceti elementele vectorului: ";
    for (i = 0; i < n; i++)
        cin >> v[i];
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (v[j] > v[j + 1])
            {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
    int vector_fara_duplicate[100], k = 0;
    for (i = 0; i < n; i++)
    {
        if (i == 0 || v[i] != v[i - 1])
        {
            vector_fara_duplicate[k] = v[i];
            k++;
        }
    }
    printf("Vectorul sortat fara duplicate este: ");
    for (i = 0; i < k; i++)
        printf("%d ", vector_fara_duplicate[i]);
    printf("\n");

    return 0;
}