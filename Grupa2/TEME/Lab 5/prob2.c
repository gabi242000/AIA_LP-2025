#include <stdio.h>
#include<string.h>
#include<ctype.h>

int main()
{
    int x,y;
    char s[51], i;
    printf("Introdu un cuvant\n");
    fgets(s, 51, stdin);
    printf("Scrie prima pozitie:\n");
    scanf("%d", &x);
    printf("Scrie a doua pozitie:\n");
    scanf("%d", &y);
    
    if(x<strlen(s) && x>=0 && y<strlen(s) && y>=0)
    {
        i=s[y];
        s[y]=s[x];
        s[x]=i;
        printf("Noul cuvant este: %s\n", s);
    }
    else
    {
        printf("Pozitiile nu exista\n ");
    } 
    return 0;

}