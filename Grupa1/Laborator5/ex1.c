#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s[101];
    int i;
    fgets(s, 100, stdin);
    for(i=0;i<=strlen(s);i++)
        s[i]=toupper(s[i]);
    printf("%s", s);
    return 0;
}
