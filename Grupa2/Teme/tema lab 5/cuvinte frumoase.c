#include <stdio.h>
#include <string.h>


int main()
{
    char s[100];
    int i,ok=1;
    printf("introdu cuvantul: ");
    gets(s);
    if (s[0]!='z' || strlen(s)%2!=0)
        ok=0;
    else
        for (i=0;i<strlen(s)-1;i++)
            if(strchr("aeiou",s[i]) == strchr("aeiou",s[i+1]))
                ok=0;

    if (ok==1)
        printf("cuvant frumos");
    else
        printf("cuvant urat");
    return 0;
}