#include <stdio.h>

int main()
{
    int n, aux;
    printf("Introdu dimensiunea vectorului (n):");
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
    
    int n2 = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || v[i] != v[i - 1]) {
            v[n2++] = v[i];
        }
    }
    
    printf("Vectorul fara duplicate: \n");
    for (int i = 0; i < n2; i++)
        printf("%d ", v[i]);
    printf("\n");
    
    return 0;
}
