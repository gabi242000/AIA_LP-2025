#include <stdio.h>

void ex1(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            printf("%d ", i);
    }
    printf("\n");
}

void ex2(void)
{
    int n;
    scanf("%d", &n);
    printf("Primele %d numere fibbonaci sunt: ", n);
    
    if (n == 1)
    {
        printf("0");
        return;
    }
    if (n == 2)
    {
        printf("0 1");
        return;
    }
    
    int cif = 1, ultima_cif = 1;
    printf("0 1 ");
    for (int i = 1; i < n - 1; i++)
    {
        printf("%d ", cif);
        int aux = cif;
        cif += ultima_cif;
        ultima_cif = aux;
    }
    printf("\n");
}

void ex3(void)
{
    int n;
    scanf("%d", &n);
    int width = 2 * n - 1;
    
    for (int i = 1; i <= n; i++)
    {
        int stars = 2 * i - 1;
        int spaces = (width - stars) / 2;        
        for (int j = 0; j < spaces; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < stars; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

int main(void)
{
    int x;
    scanf("%d", &x);
    switch(x)
    {
        case 1:
            ex1();
            break;
        case 2:
            ex2();
            break;
        case 3:
            ex3();
            break;
        default:
            printf("Invalid input");
    }
    return 0;
}
