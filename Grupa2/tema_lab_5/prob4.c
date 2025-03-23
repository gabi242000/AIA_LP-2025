#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[101];
    int i, p;
    printf("Introdu textul pe care doresti sa il criptezi: \n");
    fgets(s,101,stdin);
    printf("Introdu valoarea cu care vrei sa il criptezi: \n");
    scanf("%d", &p);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]!=' ')
            s[i]=s[i]+p;
    }
    printf("Sirul modificat este: %s\n",s);
    return 0;
}
