#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[100];
    int i;
    printf("introdu sirul: ");
    fgets (s,100,stdin);
    for (i=0;i<strlen(s);i++)
        s[i]=toupper(s[i]);
    printf("%s",s);
    printf("%d",strlen(s));
    return 0;
}