#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    int i, ok;
    char s[100];
    printf("Introduceti cuvantul : ");
    fgets(s, 100, stdin);
    ok = 0;
    s[strcspn(s, "\n")] = 0;
    for (i = 0; i < strlen(s) - 1; i = i + 2)
        if ((strchr("aeiou", s[i]) == 0 && strchr("aeiou", s[i + 1]) == 0) || (strchr("aeiou", s[i]) != 0 && strchr("aeiou", s[i + 1]) != 0))

            ok++;

    if (s[0] == 'z' && strlen(s) % 2 == 0 && ok == 0)
        printf("Cuvant frumos");
    else
        printf("Cuvant gresit");
    return 0;
}