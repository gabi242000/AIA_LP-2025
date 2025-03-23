#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char c[101];
    int i;
    printf("Introdu sirul de caractere: \n");
    fgets(c,101,stdin);
    for (i=0;i<strlen(c);i++)
    {
        c[i]=toupper(c[i]);
    }
    printf("Sirul modificat este: %s\n",c);
    return 0;
}
