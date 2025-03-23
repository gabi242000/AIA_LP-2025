#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char c[25];
    int i,ok=1;
    printf("Introdu cuvantul: \n");
    scanf("%s",c);
    if(c[0]!='z')
        ok=0;
    if (ok==1)
        for(i=0;i<strlen(c);i++)
        {
            if(i%2==0)
                {
                    if(strchr("aeiou",c[i])!=0)
                    ok=0;
                    break;
                }
            else 
                {
                    if(strchr("aeiou",c[i])==0)
                    ok=0;
                    break;
                }
        }
    if(ok==1)
        printf("Cuvantul introdus este un cuvant frumos. \n");
    else printf("Cuvantul introdus nu este un cuvant frumos. \n");
}
