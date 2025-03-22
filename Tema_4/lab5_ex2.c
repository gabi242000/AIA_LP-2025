#include <stdio.h>
#include <string.h>
int main()
{
    char s[101],aux;
    int x,y;
    printf("Introdu un sir de caractere: \n");
    fgets(s,101,stdin);
    printf("Introdu 2 pozitii ale sirului pentru a le interschimba: \n");
    scanf("%d %d",&x,&y);
    if((x>=0 && x<strlen(s)) && (y>=0 && y<strlen(s)))
    {
        aux=s[x];
        s[x]=s[y];
        s[y]=aux;
        printf("Cuvantul dupa interschimmbare este: %s\n",s);
    }
    else 
    printf("Ai introdus 2 pozitii invalide\n");
    return 0;
}