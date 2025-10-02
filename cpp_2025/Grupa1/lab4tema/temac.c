#include <stdio.h>

void ex1()
{
    int N, sum_max[2] = {0, 0};
    scanf("%d", &N);
    int matrix[N][N];
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &matrix[i][j]);
            sum += matrix[i][j];
        }
        if (sum > sum_max[0])
        {
            sum_max[0] = sum;
            sum_max[1] = i;
        }
    }
    printf("Linia cu suma maxima este: %d si suma este: %d\n", sum_max[1] + 1, sum_max[0]);
    for (int i = 0; i < N; i++)
    {
        printf("%d ", matrix[sum_max[1]][i]);
    }
}

void ex2()
{
    int n, fr[1000] = {0};
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
        fr[v[i]]++;
    }
    for (int i = 0; i < 1000; i++)
    {
        if (fr[i] >= 1)
        {
            printf("%d ", i);
        }
    }
}

void ex3()
{
    int n;
    scanf("%d", &n);
    int matrix[n][n];    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            matrix[i][j] = i + j + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            matrix[i][j] = matrix[j][i];
        }
    }
    printf("Matricea folosind modelul deasupra diagonalei principale este: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void ex4()
{
    int n;
    scanf("%d", &n);
    int t = 0;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (matrix[i][j] > matrix[i - 1][j] && matrix[i][j] > matrix[i + 1][j] && matrix[i][j] > matrix[i][j - 1] && matrix[i][j] > matrix[i][j + 1])
            {
                printf("%d ", matrix[i][j]);
                t = 1;
            }
        }
    }
    if (t == 0)
    {
        printf("Nu exista elemente care sa fie strict mai mari decat vecinii lor");
    }
}

int main()
{
    int x;
    while (1)
    {
        printf("\n");
        printf("Introduceti nr exercitiului: ");
        scanf("%d", &x);
        switch (x)
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
            case 4:
                ex4();
                break;
            default:
                printf("Invalid input");
        }
    }
    return 0;
}

