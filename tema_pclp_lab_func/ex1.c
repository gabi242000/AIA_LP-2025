#include <stdio.h>
void sortareVector(int v[], int st, int dr)
{
    if(st < dr)
    {
        int m = (st + dr) / 2;
        int aux = v[st];
        v[st] = v[m];
        v[m] = aux;
        int i = st , j = dr, d = 0;
        while(i < j)
        {
            if(v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                d = 1 - d;
            }
            i += d;
            j -= 1 - d;
        }
        sortareVector(v, st , i - 1);
        sortareVector(v, i + 1 , dr);
    }
}
int cautareBinara(int v[], int st, int dr, int x)
{
    while(st <= dr)
    {
        int m = (st + dr) / 2;
        if(v[m] == x)
            return m;
        else if(v[m] < x)
            st = m + 1;
        else
            dr = m - 1;
    }
    return -1;
}
int main()
{
    int n, v[200], x;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    scanf("%d", &x);
    sortareVector(v, 0, n-1);
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
    int p = cautareBinara(v, 0, n - 1, x);
    if (p != -1)
        printf("%d", p);
    else
        printf("Numarul nu a fost gasit");
    return 0;
}
