#include <stdio.h.>
#include <string.h>
#include <ctype.h>
int main()
{
    int i;
    char s[100];
    printf("Introduceti sirul de caractere : ");
    fgets(s, 100, stdin);
    for (i = 0; i <= strlen(s)-1; i++)
        s[i] = toupper(s[i]);

    printf("Sirul modificat este : %s", s);
    return 0;
}