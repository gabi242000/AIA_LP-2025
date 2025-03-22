#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char s[100];
    int p;

    fgets(s,100,stdin);
    scanf("%d",&p);

    for(int i=0;i<=strlen(s)-1;i++)
        if(isalpha(s[i])) s[i] = s[i]+p;

    printf("Sirul criptat este: %s",s);
}