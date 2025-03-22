#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[101];
    int p,i;
    printf("Introdu un sir de caractere:\n ");
    fgets(s,101,stdin);
    s[strcspn(s,"\n")]=0;
    printf("Introdu un numar natural: \n");
    scanf("%d",&p);
    for(i=0;s[i]!='\0';i++)
    {
        s[i]=s[i]+p;
        printf("%c",s[i]);
    }
    return 0;
}