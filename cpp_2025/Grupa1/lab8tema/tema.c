#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ex1()
{
    int N , media_arit = 0 , j = 0;
    printf("Introduceti nr de elemente: ");
    scanf("%d", &N);
    int *v = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
    {
        printf("Introduceti elementul %d: ", i + 1);
        scanf("%d", &v[i]);
        media_arit += v[i];
    }
    media_arit /= N;
    int *v2 = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
    {
        if(v[i] > media_arit)
        {
            v2[j] = v[i];
            j++;
        }
    }
    printf("Media aritmetica este: %d\n", media_arit);
    printf("Elementele mai mari decat media aritmetica sunt: ");
    for(int i = 0; i < j; i++)
    {
        printf("%d ", v2[i]);
    }
    free(v);
    free(v2);
}

void ex2()
{
    int N,j;
    printf("Introduceti nr de elemente: ");
    scanf("%d", &N);
    j = N - 1;
    int *v = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
    {
        printf("Introduceti elementul %d: ", i + 1);
        scanf("%d", &v[i]);
    }
    int *v2 = (int *)malloc(N * sizeof(int));
    for(int i = 0; i < N; i++)
    {
        v2[i] = v[j];
        j--;
    }
    printf("Vectorul inversat este: ");
    for(int i = 0; i < N; i++)
    {
        printf("%d ", v2[i]);
    }
    free(v);
    free(v2);
}

int ex3()
{
    char *sir1, *sir2, *rezultat;
    int lungime1, lungime2;

    printf("Introduceti primul sir: ");
    sir1 = (char*)malloc(100 * sizeof(char)); 
    if (sir1 == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        return 1;
    }
    fgets(sir1, 100, stdin);
    lungime1 = strlen(sir1);
    if (sir1[lungime1 - 1] == '\n') {
        sir1[lungime1 - 1] = '\0'; 
        lungime1--;
    }

    sir1 = (char*)realloc(sir1, (lungime1 + 1) * sizeof(char));
    if (sir1 == NULL) {
        printf("Eroare la realocarea memoriei!\n");
        return 1;
    }
    printf("Introduceti al doilea sir: ");
    sir2 = (char*)malloc(100 * sizeof(char)); 
    if (sir2 == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        free(sir1);
        return 1;
    }
    fgets(sir2, 100, stdin);
    lungime2 = strlen(sir2);
    if (sir2[lungime2 - 1] == '\n') {
        sir2[lungime2 - 1] = '\0'; 
        lungime2--;
    }

    sir2 = (char*)realloc(sir2, (lungime2 + 1) * sizeof(char));
    if (sir2 == NULL) {
        printf("Eroare la realocarea memoriei!\n");
        free(sir1);
        return 1;
    }
    rezultat = (char*)malloc((lungime1 + lungime2 + 1) * sizeof(char));
    if (rezultat == NULL) {
        printf("Eroare la alocarea memoriei!\n");
        free(sir1);
        free(sir2);
        return 1;
    }
    strcpy(rezultat, sir1);
    strcat(rezultat, sir2);

    printf("Rezultatul concatenarii: %s\n", rezultat);

    free(sir1);
    free(sir2);
    free(rezultat);
}

void ex4()
{
    int N;
    printf("Introduceti nr de elemente: ");
    scanf("%d", &N);
    int *v = (int *)calloc(N ,  sizeof(int));
    for(int i = 0 ; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(i == j)
            {
                v[j] = 1;
                printf("%d ", v[i]);
                v[j] = 0;
            }
            else
            {
                printf("%d ", v[i]);
            }
        }
        printf("\n");
    }
}

int main()
{
    printf("\n");
    int n;
    while(1)
    {
        printf("Introdu numarul exercitiului: ");
        scanf("%d", &n);    
        switch(n)
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
                printf("Exercitiul nu exista!\n");
                break;
        }
    }
    return 0;
}
