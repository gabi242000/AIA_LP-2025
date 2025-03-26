#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main()
{
    char s[101];
    int i,p;
    printf("introduceti un sir de caractere:\n");
    fgets(s,100,stdin);
    printf("intorudecti un numar:\n");
    scanf("%d", &p);
    for(i=0;i<=strlen(s);i++)
    {
        if(isalpha(s[i]))
            s[i]=s[i]+p;
    }
    printf("%s", s);
    return 0;
}
