#include <stdio.h>
#include <ctype.h>
int main()
{
    char s[101],i;
    printf("Introdu un sir de caractere format din litere mici,litere mari si spatii:\n");
    fgets(s,101,stdin);
    for(i=0;s[i]!='\0';i++)
    {
        s[i]=toupper(s[i]);
    }
    printf("Sirul modificat este: %s",s);
    return 0;
}