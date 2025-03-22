#include <stdio.h>
#include <string.h>

void ex1()
{
    char s[100];
    printf("Introdu sirul de caractere: ");
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = 0;
    int n = strlen(s);
    for(int i = 0; i < n; i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
            s[i] = s[i] - 32;
    }
    printf("Sirul de caractere in majuscule: %s\n", s);
}

void ex2()
{
    char v[100];
    printf("Introdu sirul de caractere: ");
    fgets(v, 100, stdin);
    v[strcspn(v, "\n")] = 0;
    int x, y;
    printf("Introdu x si y: ");
    scanf("%d %d", &x, &y);
    getchar();
    v[x] += v[y];
    v[y] = v[x] - v[y];
    v[x] = v[x] - v[y];
    printf("Sirul de caractere dupa interschimbare: %s\n", v);
}

void ex3()
{
    int ok = 1;
    char s[100];
    printf("Introdu cuvantul: ");
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = 0;
    int n = strlen(s);
    if(n % 2 == 0 && s[0] == 'z')
    {
        for(int i = 0; i < n; i++)
        {
            if(i % 2 == 1)
            {
                if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
                {
                    ok = 0;
                    break;
                }
            }
            else
            {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                {
                    ok = 0;
                    break;
                }
            }
        }
    }
    else
        ok = 0;
    if(ok)
        printf("Cuvantul este frumos\n");
    else
        printf("Cuvantul nu este frumos\n");
}

void ex4()
{
    int n;
    char s[100];
    printf("Introduceti nr cu care encriptezi mesajul: ");
    scanf("%d", &n);
    getchar();
    printf("Introduceti mesajul: ");
    fgets(s, 100, stdin);
    s[strcspn(s, "\n")] = 0;
    for(int i = 0; i < strlen(s); i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] + n;
            if(s[i] > 'z')
                s[i] = s[i] - 26;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] + n;
            if(s[i] > 'Z')
                s[i] = s[i] - 26;
        }
    }
    printf("Mesajul encriptat: %s\n", s);
}

int main()
{
    while(1)
    {
        printf("\n");
        int x;
        printf("Introdu numarul de exercitiului: ");
        scanf("%d", &x);
        getchar();
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
            return 0;
        }
    }
    return 0;
}