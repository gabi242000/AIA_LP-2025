#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int x, y;
    char s[100], aux;
    printf("Introduceti sirul de caractere :");
    fgets(s, 100, stdin);
    printf("introduceti pozitiile : ");
    scanf("%d", &x);
    scanf("%d", &y);

    aux = s[x];
    s[x] = s[y];
    s[y] = aux;
    printf("Sirul modificat este : ");
    printf("%s", s);
    return 0;
}