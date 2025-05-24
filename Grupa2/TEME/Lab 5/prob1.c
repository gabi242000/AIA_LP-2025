#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int i;
    char s[51];
    printf("Introdu un sir.\n");
    fgets(s, 51, stdin);
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            s[i]=toupper(s[i]);
        }
    }
    printf("Sirul in litere mari este: %s\n", s);
    return 0;
}