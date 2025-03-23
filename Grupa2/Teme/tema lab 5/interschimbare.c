#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char s[100];
    int i,aux,x,y;
    printf("introdu sirul: ");
    fgets (s,100,stdin);
    scanf("%d %d",&x ,&y);
    aux=s[x];
    s[x]=s[y];
    s[y]=aux;
    printf("%s",s);
    return 0;
}